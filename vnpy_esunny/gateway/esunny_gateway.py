from collections import defaultdict
from dataclasses import dataclass
from datetime import datetime
from pathlib import Path
from typing import Dict, Tuple, Any, List

from vnpy.event import EventEngine
from vnpy.trader.utility import get_folder_path, ZoneInfo
from vnpy.trader.constant import (
    Exchange,
    Product,
    Direction,
    Status,
    OrderType,
    Offset
)
from vnpy.trader.gateway import BaseGateway
from vnpy.trader.object import (
    CancelRequest,
    OrderRequest,
    SubscribeRequest,
    TickData,
    ContractData,
    OrderData,
    TradeData,
    PositionData,
    AccountData
)

from ..api import MdApi, TdApi


# 委托状态映射
STATUS_ES2VT: Dict[str, Status] = {
    "0": Status.SUBMITTING,
    "1": Status.SUBMITTING,
    "4": Status.NOTTRADED,
    "5": Status.PARTTRADED,
    "6": Status.ALLTRADED,
    "9": Status.CANCELLED,
    "A": Status.CANCELLED,
    "B": Status.REJECTED,
}

# 多空方向映射
DIRECTION_ES2VT: Dict[str, Direction] = {
    "N": Direction.NET,
    "B": Direction.LONG,
    "S": Direction.SHORT,
}
DIRECTION_VT2ES: Dict[Direction, str] = {v: k for k, v in DIRECTION_ES2VT.items()}

# 委托类型映射
ORDERTYPE_ES2VT: Dict[str, OrderType] = {
    "1": OrderType.MARKET,
    "2": OrderType.LIMIT
}
ORDERTYPE_VT2ES = {v: k for k, v in ORDERTYPE_ES2VT.items()}

# 委托有效类型映射
ORDERTIF_VT2ES: Dict[str, str] = {
    "TAPI_ORDER_TIMEINFORCE_GTC": "1",
    "TAPI_ORDER_TIMEINFORCE_FAK": "3",
    "TAPI_ORDER_TIMEINFORCE_FOK": "4"
}

# 开平方向映射
OFFSET_VT2ES: Dict[Offset, str] = {
    Offset.OPEN: "O",
    Offset.CLOSE: "C",
    Offset.CLOSEYESTERDAY: "C",
    Offset.CLOSETODAY: "T",
    Offset.NONE: "N"
}
OFFSET_ES2VT: Dict[str, Offset] = {
    "O": Offset.OPEN,
    "C": Offset.CLOSE,
    "T": Offset.CLOSETODAY,
    "N": Offset.NONE
}

# 交易所映射
EXCHANGE_ES2VT: Dict[str, Exchange] = {
    "CFFEX": Exchange.CFFEX,
    "ZCE": Exchange.CZCE,
    "DCE": Exchange.DCE,
    "SHFE": Exchange.SHFE,
    "INE": Exchange.INE,
    "SGE": Exchange.SGE,
    "CBOT": Exchange.CBOT,
    "CME": Exchange.CME,
    "COMEX": Exchange.COMEX,
    "EUREX": Exchange.EUREX,
    "HKEX": Exchange.HKFE,
    "KRX": Exchange.KRX,
    "LME": Exchange.LME,
    "NYMEX": Exchange.NYMEX,
    "SGX": Exchange.SGX
}
EXCHANGE_VT2ES: Dict[Exchange, str] = {v: k for k, v in EXCHANGE_ES2VT.items()}

# 产品类型映射
PRODUCT_TYPE_ES2VT: Dict[str, Product] = {
    "F": Product.FUTURES,
    "Y": Product.SPOT
}
PRODUCT_TYPE_VT2ES: Dict[Product, str] = {v: k for k, v in PRODUCT_TYPE_ES2VT.items()}

# 行情接口日志级别映射
MDLOGLEVEL_VT2ES: Dict[str, str] = {
    "APILOGLEVEL_NONE": "N",
    "APILOGLEVEL_ERROR": "E",
    "APILOGLEVEL_WARNING": "W",
    "APILOGLEVEL_DEBUG": "D"
}

# 交易接口日志级别映射
TDLOGLEVEL_VT2ES: Dict[str, str] = {
    "APILOGLEVEL_ERROR": "1",
    "APILOGLEVEL_NORMAL": "2",
    "APILOGLEVEL_DEBUG": "3"
}

# 标示类型映射
FLAG_VT2ES: Dict[str, str] = {
    "APIYNFLAG_YES": "Y",
    "APIYNFLAG_NO": "N",
    "TAPI_CALLPUT_FLAG_CALL": "C",
    "TAPI_CALLPUT_FLAG_PUT": "P",
    "TAPI_CALLPUT_FLAG_NONE": "N"
}

# 投机保值类型映射
HEDGETYPE_VT2ES: Dict[str, str] = {
    "TAPI_HEDGEFLAG_NONE": "N",
    "TAPI_HEDGEFLAG_T": "T",
    "TAPI_HEDGEFLAG_B": "B",
    "TAPI_HEDGEFLAG_L": "L",
    "TAPI_HEDGEFLAG_M": "M"
}

# 其他常量
CHINA_TZ = ZoneInfo("Asia/Shanghai")       # 中国时区

# 合约数据全局缓存字典
commodity_infos: Dict[str, "CommodityInfo"] = {}
contract_infos: Dict[Tuple[str, "Exchange"], "ContractInfo"] = {}


class EsunnyGateway(BaseGateway):
    """
    VeighNa用于对接易盛柜台的交易接口。
    """

    default_name: str = "ESUNNY"

    default_setting: Dict[str, Any] = {
        "行情账号": "",
        "行情密码": "",
        "行情服务器": "",
        "行情端口": 0,
        "行情授权编码": "",
        "交易账号": "",
        "交易密码": "",
        "交易服务器": "",
        "交易端口": 0,
        "交易产品名称": "",
        "交易授权编码": "",
        "交易系统": ["内盘", "外盘"]
    }

    exchanges: List[str] = list(EXCHANGE_VT2ES.keys())

    def __init__(self, event_engine: EventEngine, gateway_name: str) -> None:
        """构造函数"""
        super().__init__(event_engine, gateway_name)

        self.md_api: "QuoteApi" = QuoteApi(self)
        self.td_api: "EsTradeApi" = EsTradeApi(self)

    def connect(self, setting: dict) -> None:
        """连接交易接口"""
        quote_username: str = setting["行情账号"]
        quote_password: str = setting["行情密码"]
        quote_host: str = setting["行情服务器"]
        quote_port: int = setting["行情端口"]
        quote_authcode: str = setting["行情授权编码"]
        trade_username: str = setting["交易账号"]
        trade_password: str = setting["交易密码"]
        trade_host: str = setting["交易服务器"]
        trade_port: int = setting["交易端口"]
        trade_appid: str = setting["交易产品名称"]
        trade_authcode: str = setting["交易授权编码"]
        if setting["交易系统"] == "内盘":
            systype: int = 1
        else:
            systype: int = 2

        self.md_api.connect(
            quote_username,
            quote_password,
            quote_host,
            quote_port,
            quote_authcode
        )
        self.td_api.connect(
            trade_username,
            trade_password,
            trade_host,
            trade_port,
            trade_appid,
            trade_authcode,
            systype
        )

    def subscribe(self, req: SubscribeRequest) -> None:
        """订阅行情"""
        self.md_api.subscribe(req)

    def send_order(self, req: OrderRequest) -> str:
        """委托下单"""
        return self.td_api.send_order(req)

    def cancel_order(self, req: CancelRequest) -> None:
        """委托撤单"""
        self.td_api.cancel_order(req)

    def query_account(self) -> None:
        """查询资金"""
        pass

    def query_position(self) -> None:
        """查询持仓"""
        pass

    def close(self) -> None:
        """关闭接口"""
        self.td_api.close()
        self.md_api.close()


class QuoteApi(MdApi):
    """行情API"""

    def __init__(self, gateway: EsunnyGateway) -> None:
        """构造函数"""
        super().__init__()

        self.gateway: EsunnyGateway = gateway
        self.gateway_name: str = gateway.gateway_name

        self.connect_status: bool = False

    def onRspLogin(self, error: int, data: dict) -> None:
        """用户登录请求回报"""
        if error != 0:
            self.gateway.write_log(f"行情服务器登录失败：{error}")
        else:
            self.connect_status = True
            self.gateway.write_log("行情服务器登录成功")

    def onAPIReady(self) -> None:
        """API状态通知回报"""
        self.qryCommodity()

    def onDisconnect(self, reason: int) -> None:
        """服务器连接断开回报"""
        self.connect_status = False
        self.gateway.write_log(f"行情服务器连接断开，原因：{reason}")

    def onRspSubscribeQuote(
        self,
        session: int,
        error: int,
        last: str,
        data: dict
    ) -> None:
        """订阅行情回报"""
        if error != 0:
            self.gateway.write_log(f"订阅行情失败：{error}")
        else:
            self.update_tick(data)

    def onRtnQuote(self, data: dict) -> None:
        """行情数据推送"""
        self.update_tick(data)

    def onRspQryCommodity(
        self,
        session: int,
        error: int,
        last: str,
        data: dict,
    ) -> None:
        """交易品种查询回报"""
        if error != 0:
            self.gateway.write_log("查询交易品种信息失败")
            return

        # 对于金交所的现货，则直接推送合约信息
        if data["CommodityType"] == "Y":
            contract: ContractData = ContractData(
                symbol=data["CommodityNo"],
                exchange=Exchange.SGE,
                name=data["CommodityNo"],
                product=Product.SPOT,
                size=data["ContractSize"],
                pricetick=data["CommodityTickSize"],
                gateway_name=self.gateway.gateway_name
            )
            self.gateway.on_contract(contract)

        # 缓存交易品种的信息
        commodity_info: CommodityInfo = CommodityInfo(
            size=int(data["ContractSize"]),
            pricetick=data["CommodityTickSize"],
            commodity_type=data["CommodityType"],
            commodity_no=data["CommodityNo"],
            exchange_no=data["ExchangeNo"]
        )

        if commodity_info.commodity_no == "AU(T+D)":
            commodity_info.size = 1000
        elif commodity_info.commodity_no == "AG(T+D)":
            commodity_info.size = 1

        key: tuple = (data["ExchangeNo"], data["CommodityNo"], data["CommodityType"])
        commodity_infos[key] = commodity_info

        if last == "Y":
            self.gateway.write_log("查询交易品种信息成功")
            self.qryContract({})

    def onRspQryContract(
        self,
        session: int,
        error: int,
        last: str,
        data: dict
    ) -> None:
        """交易合约查询回报"""
        if error != 0:
            self.gateway.write_log("查询交易合约信息失败")
            return

        # 检查是否支持该合约
        exchange: Exchange = EXCHANGE_ES2VT.get(data["ExchangeNo"], None)
        key: tuple = (data["ExchangeNo"], data["CommodityNo"], data["CommodityType"])
        commodity_info: CommodityInfo = commodity_infos.get(key, None)

        if not data or not exchange or not commodity_info:
            return

        # 只处理期货和现货
        if data["CommodityType"] in PRODUCT_TYPE_ES2VT:
            symbol: str = data["CommodityNo"] + data["ContractNo1"]
            product: Product = PRODUCT_TYPE_ES2VT[data["CommodityType"]]

            contract: ContractData = ContractData(
                symbol=symbol,
                exchange=exchange,
                name=symbol,
                product=product,
                size=commodity_info.size,
                pricetick=commodity_info.pricetick,
                gateway_name=self.gateway.gateway_name
            )
            self.gateway.on_contract(contract)

            contract_info: ContractInfo = ContractInfo(
                name=contract.name,
                contract_no=data["ContractNo1"],
                commodity_type=data["CommodityType"],
                commodity_no=data["CommodityNo"],
                exchange_no=data["ExchangeNo"]
            )
            contract_infos[(contract.symbol, contract.exchange)] = contract_info

        if last == "Y":
            self.gateway.write_log("查询交易合约信息成功")

    def update_tick(self, data: dict) -> None:
        """切片数据类型转换"""
        # 过滤没有时间戳的异常行情数据
        if not data["DateTimeStamp"]:
            return

        if data["ContractNo1"]:
            symbol: str = data["CommodityNo"] + data["ContractNo1"]
        else:
            symbol: str = data["CommodityNo"]
        exchange: Exchange = EXCHANGE_ES2VT[data["ExchangeNo"]]

        tick: TickData = TickData(
            symbol=symbol,
            exchange=exchange,
            datetime=generate_datetime(data["DateTimeStamp"]),
            name=symbol,
            volume=data["QTotalQty"],
            last_price=data["QLastPrice"],
            last_volume=data["QLastQty"],
            limit_up=data["QLimitUpPrice"],
            limit_down=data["QLimitDownPrice"],
            open_price=data["QOpeningPrice"],
            high_price=data["QHighPrice"],
            low_price=data["QLowPrice"],
            pre_close=data["QPreClosingPrice"],
            bid_price_1=data["QBidPrice"][0],
            bid_price_2=data["QBidPrice"][1],
            bid_price_3=data["QBidPrice"][2],
            bid_price_4=data["QBidPrice"][3],
            bid_price_5=data["QBidPrice"][4],
            ask_price_1=data["QAskPrice"][0],
            ask_price_2=data["QAskPrice"][1],
            ask_price_3=data["QAskPrice"][2],
            ask_price_4=data["QAskPrice"][3],
            ask_price_5=data["QAskPrice"][4],
            bid_volume_1=data["QBidQty"][0],
            bid_volume_2=data["QBidQty"][1],
            bid_volume_3=data["QBidQty"][2],
            bid_volume_4=data["QBidQty"][3],
            bid_volume_5=data["QBidQty"][4],
            ask_volume_1=data["QAskQty"][0],
            ask_volume_2=data["QAskQty"][1],
            ask_volume_3=data["QAskQty"][2],
            ask_volume_4=data["QAskQty"][3],
            ask_volume_5=data["QAskQty"][4],
            gateway_name=self.gateway_name,
        )
        self.gateway.on_tick(tick)

    def connect(
        self,
        username: str,
        password: str,
        host: str,
        port: int,
        auth_code: str
    ) -> None:
        """连接服务器"""
        # 禁止重复发起连接，会导致异常崩溃
        if self.connect_status:
            return

        self.init()

        # API基本设置
        path: Path = get_folder_path(self.gateway_name.lower())
        self.setTapQuoteAPIDataPath(str(path).encode("GBK"))
        self.setTapQuoteAPILogLevel(MDLOGLEVEL_VT2ES["APILOGLEVEL_NONE"])

        # 创建API
        req: dict = {
            "AuthCode": auth_code,
            "KeyOperationLogPath": str(path).encode("GBK")
        }
        self.createTapQuoteAPI(req, 0)

        # 设置服务器地址
        self.setHostAddress(host, port)

        # 登录
        data: dict = {
            "UserNo": username,
            "Password": password,
            "ISModifyPassword": FLAG_VT2ES["APIYNFLAG_NO"],
            "ISDDA": FLAG_VT2ES["APIYNFLAG_NO"]
        }
        self.login(data)

    def subscribe(self, req: SubscribeRequest) -> None:
        """订阅行情"""
        contract_info = contract_infos.get((req.symbol, req.exchange), None)
        if not contract_info:
            if req.exchange == Exchange.SGE:
                key: tuple = ("SGE", req.symbol, "Y")
                commodity_info: CommodityInfo = commodity_infos[key]
            else:
                self.gateway.write_log(f"找不到匹配的合约：{req.symbol}和{req.exchange.value}")
                return

        tap_contract: dict = {
            "ExchangeNo": EXCHANGE_VT2ES[req.exchange],
            "CallOrPutFlag1": FLAG_VT2ES["TAPI_CALLPUT_FLAG_NONE"],
            "CallOrPutFlag2": FLAG_VT2ES["TAPI_CALLPUT_FLAG_NONE"]
        }

        if contract_info:
            tap_contract["ContractNo1"] = contract_info.contract_no
            tap_contract["CommodityType"] = contract_info.commodity_type
            tap_contract["CommodityNo"] = contract_info.commodity_no

        else:
            tap_contract["CommodityType"] = commodity_info.commodity_type
            tap_contract["CommodityNo"] = commodity_info.commodity_no

        self.subscribeQuote(tap_contract)

    def close(self) -> None:
        """关闭连接"""
        if self.connect_status:
            self.disconnect()
            self.exit()


class EsTradeApi(TdApi):
    """交易API"""

    def __init__(self, gateway: EsunnyGateway) -> None:
        """构造函数"""
        super().__init__()

        self.gateway: EsunnyGateway = gateway
        self.gateway_name: str = gateway.gateway_name

        self.connect_status: bool = False
        self.reqid: int = 0

        self.account_no: str = ""

        self.sys_local_map: Dict[str, str] = {}
        self.local_sys_map: Dict[str, str] = {}
        self.position_details: Dict[Tuple, Dict[str, Dict]] = defaultdict(dict)

    def onConnect(self, userno: str) -> None:
        """服务器连接成功回报"""
        self.connect_status = True
        self.gateway.write_log("交易服务器连接成功")

    def onRspLogin(self, userno: str, error: int, data: dict) -> None:
        """用户登录请求回报"""
        if error != 0:
            self.gateway.write_log(f"交易服务器登录失败，错误码：{error}")
        else:
            self.gateway.write_log("交易服务器登录成功")

    def onAPIReady(self, userno: str) -> None:
        """API状态通知回报"""
        self.gateway.write_log("交易服务器API准备就绪")

    def onDisconnect(self, userno: str, reason: int) -> None:
        """服务器连接断开回报"""
        self.gateway.write_log(f"交易服务器连接断开，原因：{reason}")

    def onRtnFund(self, userno: str, data: dict) -> None:
        """账户资金推送"""
        self.account_no = data["AccountNo"]

        account: AccountData = AccountData(
            accountid=data["AccountNo"],
            balance=data["Balance"],
            frozen=data["Balance"] - data["Available"],
            gateway_name=self.gateway_name
        )
        self.gateway.on_account(account)

    def onRtnPosition(self, userno: str, data: dict) -> None:
        """持仓更新推送"""
        # 生成合约代码
        if data["ExchangeNo"] == "SGE":
            symbol: str = data["CommodityNo"]
        else:
            symbol: str = data["CommodityNo"] + data["ContractNo"]

        # 缓存持仓明细
        key: tuple = (symbol, data["MatchSide"])
        details: dict = self.position_details[key]
        details[data["PositionNo"]] = data

        # 汇总持仓明细
        position: PositionData = PositionData(
            symbol=symbol,
            exchange=EXCHANGE_ES2VT[data["ExchangeNo"]],
            direction=DIRECTION_ES2VT[data["MatchSide"]],
            gateway_name=self.gateway_name
        )
        cost: float = 0

        for d in details.values():
            # 汇总持仓量
            position.volume += d["PositionQty"]

            # 汇总昨仓量
            if d["IsHistory"] == "Y":
                position.yd_volume += d["PositionQty"]

            # 累加成本
            cost += d["PositionPrice"] * d["PositionQty"]

        # 计算均价
        if position.volume:
            position.price = cost / position.volume

        self.gateway.on_position(position)

    def onRtnOrder(self, userno: str, requestid: int, data: dict) -> None:
        """委托更新推送"""
        type: OrderType = ORDERTYPE_ES2VT.get(data["OrderType"], None)
        if not type:
            self.gateway.write_log(f"收到不支持的委托类型{data['OrderType']}，委托号{data['OrderNo']}")
            return

        if data["ErrorCode"] != 0:
            self.gateway.write_log(f"委托下单失败，错误码: {data['ErrorCode']}, 错误信息: {data['ErrorText']}")

        # 过滤委托的临时状态推送
        if data["OrderState"] in {"7", "8"}:
            return

        # 绑定本地和系统委托号映射
        self.local_sys_map[data["RefString"]] = data["OrderNo"]
        self.sys_local_map[data["OrderNo"]] = data["RefString"]

        if data["ExchangeNo"] == "SGE":
            symbol: str = data["CommodityNo"]
        else:
            symbol: str = data["CommodityNo"] + data["ContractNo"]

        order: OrderData = OrderData(
            symbol=symbol,
            exchange=EXCHANGE_ES2VT.get(data["ExchangeNo"], None),
            orderid=data["RefString"],
            type=type,
            direction=DIRECTION_ES2VT[data["OrderSide"]],
            offset=OFFSET_ES2VT.get(data["PositionEffect"], Offset.NONE),
            price=data["OrderPrice"],
            volume=data["OrderQty"],
            traded=data["OrderMatchQty"],
            status=STATUS_ES2VT.get(data["OrderState"], Status.SUBMITTING),
            datetime=generate_datetime(data["OrderInsertTime"]),
            gateway_name=self.gateway_name
        )
        self.gateway.on_order(order)

    def onRtnFill(self, userno: str, data: dict) -> None:
        """成交数据推送"""
        orderid: str = self.sys_local_map[data["OrderNo"]]

        if data["ExchangeNo"] == "SGE":
            symbol: str = data["CommodityNo"]
        else:
            symbol: str = data["CommodityNo"] + data["ContractNo"]

        trade: TradeData = TradeData(
            symbol=symbol,
            exchange=EXCHANGE_ES2VT.get(data["ExchangeNo"], None),
            orderid=orderid,
            tradeid=data["MatchNo"],
            direction=DIRECTION_ES2VT[data["MatchSide"]],
            price=data["MatchPrice"],
            volume=data["MatchQty"],
            datetime=generate_datetime(data["MatchDateTime"]),
            gateway_name=self.gateway_name
        )
        self.gateway.on_trade(trade)

    def connect(
        self,
        username: str,
        password: str,
        host: str,
        port: int,
        appid: str,
        auth_code: str,
        systype: int
    ) -> None:
        """连接交易接口"""
        # 禁止重复发起连接，会导致异常崩溃
        if self.connect_status:
            return

        self.userno = username

        # 创建API
        self.createEsTradeAPI(0)

        # API基本设置
        path: Path = get_folder_path(self.gateway_name.lower())
        self.setEsTradeAPIDataPath(str(path).encode("GBK"))
        self.setEsTradeAPILogLevel(TDLOGLEVEL_VT2ES["APILOGLEVEL_ERROR"])

        self.init()

        # 设置用户信息
        user_data: dict = {
            "SystemType": systype,
            "UserNo": self.userno,
            "LoginIP": host,
            "LoginPort": port,
            "LoginType": 1              # 普通登录
        }
        self.setUserInfo(user_data)

        # 登录
        data: dict = {
            "UserNo": self.userno,
            "Password": password,
            "AuthCode": auth_code,
            "AppID": appid,
            "UserType": 10000,
            "ISModifyPassword": FLAG_VT2ES["APIYNFLAG_NO"],
            "ISDDA": FLAG_VT2ES["APIYNFLAG_NO"],
            "LoginIP": host
        }
        self.startUser(username, data)

    def send_order(self, req: OrderRequest) -> str:
        """委托下单"""
        # 验证是否能找到匹配的合约
        valid: bool = True

        if req.exchange == Exchange.SGE:
            key: tuple = ("SGE", req.symbol, "Y")
            commodity_info: CommodityInfo = commodity_infos.get(key, None)
            if not commodity_info:
                valid = False
        else:
            key: tuple = (req.symbol, req.exchange)
            contract_info: ContractInfo = contract_infos.get(key, None)
            if not contract_info:
                valid = False

        if not valid:
            self.gateway.write_log(f"找不到匹配的合约：{req.symbol}和{req.exchange.value}")
            return

        # 检查委托类型是否支持
        if req.type not in ORDERTYPE_VT2ES:
            self.gateway.write_log(f"不支持的委托类型: {req.type.value}")
            return ""

        # 生成委托号
        self.reqid += 1
        prefix: str = datetime.now().strftime("%Y%m%d_%H%M%S_")
        suffix: str = str(self.reqid).rjust(6, "0")
        orderid: str = f"{prefix}_{suffix}"

        order_req: dict = {
            "AccountNo": self.account_no,
            "OrderType": ORDERTYPE_VT2ES.get(req.type, ""),
            "TimeInForce": ORDERTIF_VT2ES["TAPI_ORDER_TIMEINFORCE_GTC"],
            "PositionEffect": OFFSET_VT2ES.get(req.offset, ""),
            "PositionEffect2": OFFSET_VT2ES[Offset.NONE],
            "OrderSide": DIRECTION_VT2ES.get(req.direction, ""),
            "OrderPrice": req.price,
            "OrderQty": int(req.volume),
            "RefInt": self.reqid,
            "RefString": orderid,
            "CallOrPutFlag": "N",
            "CallOrPutFlag2": "N",
            "IsRiskOrder": FLAG_VT2ES["APIYNFLAG_NO"],
            "AddOneIsValid": FLAG_VT2ES["APIYNFLAG_NO"],
            "FutureAutoCloseFlag": FLAG_VT2ES["APIYNFLAG_NO"]
        }

        if req.exchange == Exchange.SGE:
            order_req["ExchangeNo"] = commodity_info.exchange_no
            order_req["ContractNo"] = commodity_info.commodity_no
            order_req["CommodityType"] = commodity_info.commodity_type
            order_req["CommodityNo"] = commodity_info.commodity_no
            order_req["HedgeFlag"] = HEDGETYPE_VT2ES["TAPI_HEDGEFLAG_NONE"]
            order_req["HedgeFlag2"] = HEDGETYPE_VT2ES["TAPI_HEDGEFLAG_NONE"]
        else:
            order_req["ExchangeNo"] = contract_info.exchange_no
            order_req["ContractNo"] = contract_info.contract_no
            order_req["CommodityType"] = contract_info.commodity_type
            order_req["CommodityNo"] = contract_info.commodity_no
            order_req["HedgeFlag"] = HEDGETYPE_VT2ES["TAPI_HEDGEFLAG_T"]
            order_req["HedgeFlag2"] = HEDGETYPE_VT2ES["TAPI_HEDGEFLAG_T"]

        self.insertOrder(self.userno, order_req, self.reqid)

        order: OrderData = req.create_order_data(orderid, self.gateway_name)
        self.gateway.on_order(order)

        return order.vt_orderid

    def cancel_order(self, req: CancelRequest) -> None:
        """委托撤单"""
        order_no: str = self.local_sys_map.get(req.orderid, "")
        if not order_no:
            self.gateway.write_log(f"撤单失败，找不到{req.orderid}对应的系统委托号")
            return

        cancel_req: dict = {"OrderNo": order_no}

        self.reqid += 1
        self.cancelOrder(self.userno, cancel_req, self.reqid)

    def close(self) -> None:
        """关闭连接"""
        if self.connect_status:
            self.stopUser(self.userno)
            self.exit()


def generate_datetime(timestamp: str) -> datetime:
    """生成时间戳"""
    if "-" in timestamp:
        if "." in timestamp:
            dt: datetime = datetime.strptime(timestamp, "%Y-%m-%d %H:%M:%S.%f")
        else:
            dt: datetime = datetime.strptime(timestamp, "%Y-%m-%d %H:%M:%S")
    else:
        dt: datetime = datetime.strptime(timestamp, "%y%m%d%H%M%S.%f")

    dt: datetime = dt.replace(tzinfo=CHINA_TZ)
    return dt


@dataclass
class ContractInfo:
    """储存合约信息"""
    name: str
    contract_no: str
    exchange_no: str
    commodity_type: int
    commodity_no: str


@dataclass
class CommodityInfo:
    """储存品种信息"""
    size: int
    pricetick: float
    exchange_no: str
    commodity_type: int
    commodity_no: str
