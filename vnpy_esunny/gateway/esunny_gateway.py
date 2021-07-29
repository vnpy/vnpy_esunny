from dataclasses import dataclass
from datetime import datetime
from pathlib import Path
from typing import Dict, Tuple
import pytz

from ..api import MdApi, TdApi
from vnpy.event import EventEngine
from vnpy.trader.utility import get_folder_path
from vnpy.trader.constant import (
    Exchange,
    Product,
    Direction,
    Status,
    OrderType
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

# 交易所映射
EXCHANGE_ES2VT: Dict[str, Exchange] = {
    "SGX": Exchange.SGX,
    "INE": Exchange.INE,
    "APEX": Exchange.APEX,
    "NYMEX": Exchange.NYMEX,
    "LME": Exchange.LME,
    "COMEX": Exchange.COMEX,
    "CBOT": Exchange.CBOT,
    "HKEX": Exchange.HKFE,
    "CME": Exchange.CME,
    "ZCE": Exchange.CZCE,
    "DCE": Exchange.DCE,
    "TOCOM": Exchange.TOCOM,
    "KRX": Exchange.KRX,
    "ICUS": Exchange.ICE,
    "ICEU": Exchange.ICE
}
EXCHANGE_VT2ES: Dict[Exchange, str] = {v: k for k, v in EXCHANGE_ES2VT.items()}

# 产品类型映射
PRODUCT_TYPE_ES2VT: Dict[str, Product] = {
    "P": Product.SPOT,
    "F": Product.FUTURES,
    "O": Product.OPTION,
    "Z": Product.INDEX,
    "T": Product.EQUITY,
}

# 报错信息映射
ERROR_VT2ES: Dict[str, int] = {
    "TAPIERROR_SUCCEED": 0
}

# 日志级别映射
LOGLEVEL_VT2ES: Dict[str, str] = {
    "APILOGLEVEL_NONE": "N",
    "APILOGLEVEL_ERROR": "E",
    "APILOGLEVEL_WARNING": "W",
    "APILOGLEVEL_DEBUG": "D"
}

# 标示类型映射
FLAG_VT2ES: Dict[str, str] = {
    "APIYNFLAG_YES": "Y",
    "APIYNFLAG_NO": "N",
    "TAPI_CALLPUT_FLAG_CALL": "C",
    "TAPI_CALLPUT_FLAG_PUT": "P",
    "TAPI_CALLPUT_FLAG_NONE": "N"
}

# 其他常量
CHINA_TZ = pytz.timezone("Asia/Shanghai")       # 中国时区

# 合约数据全局缓存字典
commodity_infos: Dict[str, "CommodityInfo"] = {}
contract_infos: Dict[Tuple[str, "Exchange"], "ContractInfo"] = {}


class EsunnyGateway(BaseGateway):
    """
    vn.py用于对接易盛内盘的交易接口。
    """

    default_setting = {
        "行情账号": "",
        "行情密码": "",
        "行情服务器": "",
        "行情端口": 0,
        "交易账号": "",
        "交易密码": "",
        "交易服务器": "",
        "交易端口": 0,
        "授权码": ""
    }

    exchanges = list(EXCHANGE_VT2ES.keys())

    def __init__(self, event_engine: EventEngine, gateway_name: str = "ESUNNY") -> None:
        """构造函数"""
        super().__init__(event_engine, gateway_name)

        self.md_api: "QuoteApi" = QuoteApi(self)
        self.td_api: "EsTradeApi" = EsTradeApi(self)

    def connect(self, setting: dict) -> None:
        """连接交易接口"""
        quote_username: str = setting["行情账号"]
        quote_password: str = setting["行情密码"]
        quote_host: str = setting["行情服务器"]
        quote_port: str = setting["行情端口"]
        trade_username: str = setting["交易账号"]
        trade_password: str = setting["交易密码"]
        trade_host: str = setting["交易服务器"]
        trade_port: str = setting["交易端口"]
        auth_code: str = setting["授权码"]

        self.md_api.connect(
            quote_username,
            quote_password,
            quote_host,
            quote_port,
            auth_code
        )
        self.td_api.connect(
            trade_username,
            trade_password,
            trade_host,
            trade_port,
            auth_code
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
        pass


class QuoteApi(MdApi):
    """"""

    def __init__(self, gateway: EsunnyGateway) -> None:
        """构造函数"""
        super().__init__()

        self.gateway: EsunnyGateway = gateway
        self.gateway_name: str = gateway.gateway_name

    def onRspLogin(self, error: int, data: dict) -> None:
        """用户登录请求回报"""
        if error != ERROR_VT2ES["TAPIERROR_SUCCEED"]:
            self.gateway.write_log(f"行情服务器登录失败：{error}")
        else:
            self.gateway.write_log("行情服务器登录成功")

    def onAPIReady(self) -> None:
        """API状态通知回报"""
        self.qryCommodity()

    def onDisconnect(self, reason: int) -> None:
        """服务器连接断开回报"""
        self.gateway.write_log(f"行情服务器连接断开，原因：{reason}")

    def onRspSubscribeQuote(
        self,
        session: int,
        error: int,
        last: str,
        data: dict
    ) -> None:
        """订阅行情回报"""
        if error != ERROR_VT2ES["TAPIERROR_SUCCEED"]:
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
        if error != ERROR_VT2ES["TAPIERROR_SUCCEED"]:
            self.gateway.write_log("查询交易品种信息失败")
            return

        commodity_info: CommodityInfo = CommodityInfo(
            name=data["CommodityEngName"],
            size=int(data["ContractSize"]),
            pricetick=data["CommodityTickSize"]
        )
        key: str = (data["ExchangeNo"], data["CommodityNo"], data["CommodityType"])
        commodity_infos[key] = commodity_info

        if last == "Y":
            self.gateway.write_log("查询交易品种信息成功")
            req: dict = {}
            self.qryContract(req)

    def onRspQryContract(
        self,
        session: int,
        error: int,
        last: str,
        data: dict
    ) -> None:
        """交易合约查询回报"""
        if error != ERROR_VT2ES["TAPIERROR_SUCCEED"]:
            self.gateway.write_log("查询交易合约信息失败")
            return

        exchange: Exchange = EXCHANGE_ES2VT.get(data["ExchangeNo"], None)
        key: str = (data["ExchangeNo"], data["CommodityNo"], data["CommodityType"])
        commodity_info: CommodityInfo = commodity_infos.get(key, None)

        if not data or not exchange or not commodity_info:
            return

        if data["CommodityType"] == "F":
            symbol: str = data["CommodityNo"] + data["ContractNo1"]

            if commodity_info.name:
                name: str = f"{commodity_info.name} {data['ContractNo1']}"
            else:
                name: str = symbol

            contract: ContractData = ContractData(
                symbol=symbol,
                exchange=exchange,
                name=name,
                product=Product.FUTURES,
                size=commodity_info.size,
                pricetick=commodity_info.pricetick,
                net_position=True,
                gateway_name=self.gateway.gateway_name
            )
            self.gateway.on_contract(contract)

            contract_info: ContractInfo = ContractInfo(
                name=contract.name,
                exchange_no=data["ExchangeNo"],
                contract_no=data["ContractNo1"],
                commodity_type=data["CommodityType"],
                commodity_no=data["CommodityNo"],
            )
            contract_infos[(contract.symbol, contract.exchange)] = contract_info

        if last == "Y":
            self.gateway.write_log("查询交易合约信息成功")

    def update_tick(self, data: dict) -> None:
        """切片数据类型转换"""
        symbol: str = data["CommodityNo"] + data["ContractNo1"]
        exchange: Exchange = EXCHANGE_ES2VT[data["ExchangeNo"]]

        contract_info: ContractInfo = contract_infos.get((symbol, exchange), None)
        if not contract_info:
            self.gateway.write_log(f"行情合约信息无法匹配：{symbol}和{exchange}")
            return

        tick: TickData = TickData(
            symbol=symbol,
            exchange=exchange,
            datetime=generate_datetime(data["DateTimeStamp"]),
            name=contract_info.name,
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
        self.init()
        # General API setting
        path: Path = get_folder_path(self.gateway_name.lower())
        self.setTapQuoteAPIDataPath(str(path))
        self.setTapQuoteAPILogLevel(LOGLEVEL_VT2ES["APILOGLEVEL_NONE"])

        # Create API object
        req: dict = {
            "AuthCode": auth_code,
            "KeyOperationLogPath": str(path)
        }
        self.createTapQuoteAPI(req, 0)

        # Set server address and port
        self.setHostAddress(host, port)

        # Start connection
        data: dict = {
            "UserNo": username,
            "Password": password,
            "ISModifyPassword": FLAG_VT2ES["APIYNFLAG_NO"],
            "ISDDA": FLAG_VT2ES["APIYNFLAG_NO"]
        }
        self.login(data)

    def subscribe(self, req: SubscribeRequest):
        """订阅行情"""
        contract_info: ContractInfo = contract_infos.get((req.symbol, req.exchange), None)
        if not contract_info:
            self.gateway.write_log(
                f"找不到匹配的合约：{req.symbol}和{req.exchange.value}")
            return

        tap_contract: dict = {
            "ExchangeNo": EXCHANGE_VT2ES[req.exchange],
            "CommodityType": contract_info.commodity_type,
            "CommodityNo": contract_info.commodity_no,
            "ContractNo1": contract_info.contract_no,
            "CallOrPutFlag1": FLAG_VT2ES["TAPI_CALLPUT_FLAG_NONE"],
            "CallOrPutFlag2": FLAG_VT2ES["TAPI_CALLPUT_FLAG_NONE"]
        }

        self.subscribeQuote(tap_contract)


class EsTradeApi(TdApi):
    """"""

    def __init__(self, gateway: EsunnyGateway) -> None:
        """构造函数"""
        super().__init__()

        self.gateway: EsunnyGateway = gateway
        self.gateway_name: str = gateway.gateway_name

        self.account_no = ""        # required when sending order request
        self.cancel_reqs = {}       # waiting cancel order requests before OrderNo received

        # for mapping relationship between ES OrderNo and ClientOrderNo
        self.sys_local_map = {}
        self.local_sys_map = {}
        self.sys_server_map = {}

    def onConnect(self) -> None:
        """
        Callback when connection is established with ES server.
        """
        self.gateway.write_log("交易服务器连接成功")

    def onRspLogin(self, error: int, data: dict) -> None:
        """
        Callback of login request.
        """
        if error != ERROR_VT2ES["TAPIERROR_SUCCEED"]:
            self.gateway.write_log(f"交易服务器登录失败，错误码：{error}")
        else:
            self.gateway.write_log("交易服务器登录成功")

    def onAPIReady(self, code: int) -> None:
        """
        Callback when API is ready for sending requests or queries.
        """
        self.query_account()

    def onRspQryCommodity(
        self,
        session: int,
        error: int,
        last: str,
        data: dict,
    ) -> None:
        """
        Callback of commodity query with size and pricetick data.
        """
        if error != ERROR_VT2ES["TAPIERROR_SUCCEED"]:
            self.gateway.write_log("查询交易品种信息失败")
            return

        commodity_info = CommodityInfo(
            name=data["CommodityEngName"],
            size=int(data["ContractSize"]),
            pricetick=data["CommodityTickSize"]
        )
        commodity_infos[data["CommodityNo"]] = commodity_info

        if last == "Y":
            self.gateway.write_log("查询交易品种信息成功")
            req = {}
            self.qryContract(req)

    def onRspQryContract(
        self,
        session: int,
        error: int,
        last: str,
        data: dict
    ) -> None:
        """
        Callback of contract query with detailed contract data.
        """
        if error != ERROR_VT2ES["TAPIERROR_SUCCEED"]:
            self.gateway.write_log("查询交易合约信息失败")
            return

        exchange = EXCHANGE_ES2VT.get(data["ExchangeNo"], None)
        commodity_info = commodity_infos.get(data["CommodityNo"], None)

        if not data or not exchange or not commodity_info:
            return

        if data["CommodityType"] == "F":
            symbol = data["CommodityNo"] + data["ContractNo1"]

            if commodity_info.name:
                name = f"{commodity_info.name} {data['ContractNo1']}"
            else:
                name = symbol

            contract = ContractData(
                symbol=symbol,
                exchange=exchange,
                name=name,
                product=Product.FUTURES,
                size=commodity_info.size,
                pricetick=commodity_info.pricetick,
                net_position=True,
                gateway_name=self.gateway.gateway_name
            )
            self.gateway.on_contract(contract)

            contract_info = ContractInfo(
                name=contract.name,
                exchange_no=data["ExchangeNo"],
                contract_no=data["ContractNo1"],
                commodity_type=data["CommodityType"],
                commodity_no=data["CommodityNo"],
            )
            contract_infos[(contract.symbol, contract.exchange)] = contract_info

        if last == "Y":
            self.gateway.write_log("查询交易合约信息成功")
            self.query_account()

    def onRtnPositionProfit(self, data: dict) -> None:
        """"""
        pass

    def onRspQryAccount(
        self,
        session: int,
        error: int,
        last: str,
        data: dict
    ) -> None:
        """
        Callback of account number query.
        """
        if error != ERROR_VT2ES["TAPIERROR_SUCCEED"]:
            self.gateway.write_log(f"查询账号信息失败")
            return

        req = {
            "AccountNo": data["AccountNo"]
        }
        self.qryFund(req)

    def onRspQryFund(
        self,
        session: int,
        error: int,
        last: str,
        data: dict
    ) -> None:
        """Callback of account fund query"""
        if error != ERROR_VT2ES["TAPIERROR_SUCCEED"]:
            self.gateway.write_log(f"查询资金信息失败")
            return

        self.update_account(data)

        if last == "Y":
            self.gateway.write_log("查询资金信息成功")
            self.query_position()

    def onRtnFund(self, data: dict) -> None:
        """
        Callback of account fund update.
        """
        self.update_account(data)

    def onRspQryPositionSummary(
        self,
        session: int,
        error: int,
        last: str,
        data: dict
    ) -> None:
        """
        Callback of position summary query.

        Position summary reflects the sum of positions on each contract.
        """
        if error != ERROR_VT2ES["TAPIERROR_SUCCEED"]:
            self.gateway.write_log(f"查询持仓信息失败")
            return

        if data:
            self.update_position(data)

        if last == "Y":
            self.gateway.write_log(f"查询持仓信息成功")
            self.query_order()

    def onRtnPositionSummary(self, data: dict) -> None:
        """
        Callback of position summary update.
        """
        self.update_position(data)

    def onRspQryOrder(
        self,
        session: int,
        error: int,
        last: str,
        data: dict
    ) -> None:
        """
        Callback of today's order query.
        """
        if error != ERROR_VT2ES["TAPIERROR_SUCCEED"]:
            self.gateway.write_log(f"查询委托信息失败")
            return

        if data:
            self.update_order(data)

        if last == "Y":
            self.gateway.write_log(f"查询委托信息成功")
            self.query_trade()

    def onRtnOrder(self, data: dict) -> None:
        """
        Callback of order update.
        """
        if data["ErrorCode"] != ERROR_VT2ES["TAPIERROR_SUCCEED"]:
            self.gateway.write_log(f"委托下单失败，错误码: {data['ErrorCode']}")
            return

        self.update_order(data)

    def onRspQryFill(
        self,
        session: int,
        error: int,
        last: str,
        data: dict
    ) -> None:
        """
        Callback of today's order fill (trade) query.
        """
        if error != ERROR_VT2ES["TAPIERROR_SUCCEED"]:
            self.gateway.write_log(f"查询成交信息失败")
            return

        if data:
            self.update_trade(data)

        if last == "Y":
            self.gateway.write_log(f"查询成交信息成功")

    def onRtnFill(self, data: dict) -> None:
        """
        Callback of trade update.
        """
        self.update_trade(data)

    def onRspOrderAction(
        self,
        session: int,
        error: int,
        data: dict
    ) -> None:
        """
        Callback of order action (cancel/amend) request.
        """
        if error != ERROR_VT2ES["TAPIERROR_SUCCEED"]:
            self.gateway.write_log(f"委托操作失败：{error}")
            return

    def update_account(self, data: dict) -> None:
        """
        Convert ES fund data structure into AccountData event and push it.
        """
        self.account_no = data["AccountNo"]

        account = AccountData(
            accountid=data["AccountNo"],
            balance=data["Balance"],
            frozen=data["Balance"] - data["Available"],
            gateway_name=self.gateway_name
        )
        self.gateway.on_account(account)

    def update_position(self, data: dict) -> None:
        """
        Convert ES position summary structure into PositionData event and push it.
        """
        position = PositionData(
            symbol=data["CommodityNo"] + data["ContractNo"],
            exchange=EXCHANGE_ES2VT.get(data["ExchangeNo"], None),
            direction=DIRECTION_ES2VT[data["MatchSide"]],
            volume=data["PositionQty"],
            price=data["PositionPrice"],
            gateway_name=self.gateway_name
        )
        self.gateway.on_position(position)

    def update_order(self, data: dict) -> None:
        """
        Convert ES order data structure into OrderData event and push it.
        """
        # Filter canceling and modifying order state update
        if data["OrderState"] in {"7", "8"}:
            return

        self.local_sys_map[data["ClientOrderNo"]] = data["OrderNo"]
        self.sys_local_map[data["OrderNo"]] = data["ClientOrderNo"]
        self.sys_server_map[data["OrderNo"]] = data["ServerFlag"]

        order = OrderData(
            symbol=data["CommodityNo"] + data["ContractNo"],
            exchange=EXCHANGE_ES2VT.get(data["ExchangeNo"], None),
            orderid=data["ClientOrderNo"],
            type=ORDERTYPE_ES2VT.get(data["OrderType"], data["OrderType"]),
            direction=DIRECTION_ES2VT[data["OrderSide"]],
            price=data["OrderPrice"],
            volume=data["OrderQty"],
            traded=data["OrderMatchQty"],
            status=STATUS_ES2VT.get(data["OrderState"], Status.SUBMITTING),
            datetime=generate_datetime(data["OrderInsertTime"]),
            gateway_name=self.gateway_name
        )
        self.gateway.on_order(order)

        # Send waiting cancel request to server
        if data["ClientOrderNo"] in self.cancel_reqs:
            req = self.cancel_reqs.pop(data["ClientOrderNo"])
            self.cancel_order(req)

    def update_trade(self, data: dict) -> None:
        """
        Convert ES fill data structure into TradeData event and push it.
        """
        orderid = self.sys_local_map[data["OrderNo"]]

        trade = TradeData(
            symbol=data["CommodityNo"] + data["ContractNo"],
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
        auth_code: str
    ) -> None:
        """
        Starting connection to ES server.
        """
        self.init()

        # General API setting
        path = get_folder_path(self.gateway_name.lower())
        self.setITapTradeAPIDataPath(str(path))
        self.setITapTradeAPILogLevel(LOGLEVEL_VT2ES["APILOGLEVEL_NONE"])

        # Create API object
        req = {
            "AuthCode": auth_code,
            "KeyOperationLogPath": str(path)
        }
        self.createITapTradeAPI(req, 0)

        # Set server address and port
        self.setHostAddress(host, port)

        # Start connection
        data = {
            "UserNo": username,
            "Password": password,
            "ISModifyPassword": FLAG_VT2ES["APIYNFLAG_NO"],
            "NoticeIgnoreFlag": "TAPI_NOTICE_IGNORE_POSITIONPROFIT"
        }
        self.login(data)

    def send_order(self, req: OrderRequest) -> str:
        """
        Send new order to ES server.
        """
        contract_info = contract_infos.get((req.symbol, req.exchange), None)
        if not contract_info:
            self.gateway.write_log(f"找不到匹配的合约：{req.symbol}和{req.exchange.value}")
            return ""

        if req.type not in ORDERTYPE_VT2ES:
            self.gateway.write_log(f"不支持的委托类型: {req.type.value}")
            return ""

        order_req = {
            "AccountNo": self.account_no,
            "ExchangeNo": contract_info.exchange_no,
            "CommodityType": contract_info.commodity_type,
            "CommodityNo": contract_info.commodity_no,
            "ContractNo": contract_info.contract_no,
            "OrderType": ORDERTYPE_VT2ES[req.type],
            "OrderSide": DIRECTION_VT2ES[req.direction],
            "OrderPrice": req.price,
            "OrderQty": int(req.volume),
        }

        error_id, sesion, order_id = self.insertOrder(order_req)
        order = req.create_order_data(
            order_id,
            self.gateway_name
        )

        if error_id:
            self.gateway.write_log(f"委托请求失败，错误号：{error_id}")
            order.status = Status.REJECTED

        self.gateway.on_order(order)

        return order.vt_orderid

    def cancel_order(self, req: CancelRequest) -> None:
        """
        Cancel an existing order.

        If LocalOrderNo/OrderNo map is not ready yet (from query or update callback),
        the cancel request will be put into cancel_reqs dict waiting.
        """
        order_no = self.local_sys_map.get(req.orderid, "")
        if not order_no:
            self.cancel_reqs[req.orderid] = req
            return

        server_flag = self.sys_server_map[order_no]

        cancel_req = {
            "OrderNo": order_no,
            "ServerFlag": server_flag,
        }

        self.cancelOrder(cancel_req)

    def query_account(self) -> None:
        """
        Query account number data (and account fund data will be auto queried in callback).
        """
        self.qryAccount({})

    def query_position(self) -> None:
        """
        Query position summary.
        """
        self.qryPositionSummary({})

    def query_order(self) -> None:
        """
        Query today order data.
        """
        self.qryOrder({})

    def query_trade(self) -> None:
        """
        Query today trade data.
        """
        self.qryFill({})


def generate_datetime(timestamp: str) -> datetime:
    """
    Convert timestamp string to datetime object.
    """
    if "-" in timestamp:
        if "." in timestamp:
            dt = datetime.strptime(timestamp, "%Y-%m-%d %H:%M:%S.%f")
        else:
            dt = datetime.strptime(timestamp, "%Y-%m-%d %H:%M:%S")
    else:
        dt = datetime.strptime(timestamp, "%y%m%d%H%M%S.%f")

    dt = CHINA_TZ.localize(dt)
    return dt


@dataclass
class ContractInfo:
    """
    For storing extra data of contract from ES trading server.
    """
    name: str
    exchange_no: str
    commodity_type: int
    commodity_no: str
    contract_no: str


@dataclass
class CommodityInfo:
    """
    For storing extra data of commodity from ES trading server.
    """
    name: str
    size: int
    pricetick: float
