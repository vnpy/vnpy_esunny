from collections.abc import Callable, Iterator
from datetime import datetime
from typing import Any

import pytest

pytest.importorskip("vnpy_esunny.api", reason="缺少 Esunny 原生扩展")

from vnpy.event import EventEngine  # noqa: E402
from vnpy.trader.constant import (  # noqa: E402
    Direction,
    Exchange,
    Offset,
    OrderType,
    Product,
    Status,
)
from vnpy.trader.object import (  # noqa: E402
    AccountData,
    CancelRequest,
    ContractData,
    OrderData,
    OrderRequest,
    PositionData,
    SubscribeRequest,
    TickData,
    TradeData,
)
from vnpy_esunny.gateway import esunny_gateway  # noqa: E402
from vnpy_esunny.gateway.esunny_gateway import (  # noqa: E402
    CHINA_TZ,
    COUNT_INTERVAL,
    EXCHANGE_ES2VT,
    EXCHANGE_VT2ES,
    FLAG_VT2ES,
    HEDGETYPE_VT2ES,
    CommodityInfo,
    ContractInfo,
    EsunnyGateway,
    QuoteApi,
    TradeApi,
    generate_datetime,
)


ORDER_ID: str = "20251010_093000__000001"


class Sink:
    def __init__(self) -> None:
        self.logs: list[str] = []
        self.ticks: list[TickData] = []
        self.contracts: list[ContractData] = []
        self.orders: list[OrderData] = []
        self.trades: list[TradeData] = []
        self.positions: list[PositionData] = []
        self.accounts: list[AccountData] = []

    def attach(self, gateway: EsunnyGateway) -> None:
        gateway.write_log = self.logs.append  # type: ignore[method-assign]
        gateway.on_tick = self.ticks.append  # type: ignore[method-assign]
        gateway.on_contract = self.contracts.append  # type: ignore[method-assign]
        gateway.on_order = self.orders.append  # type: ignore[method-assign]
        gateway.on_trade = self.trades.append  # type: ignore[method-assign]
        gateway.on_position = self.positions.append  # type: ignore[method-assign]
        gateway.on_account = self.accounts.append  # type: ignore[method-assign]


class CallRecorder:
    def __init__(self) -> None:
        self.calls: list[tuple[str, tuple[Any, ...]]] = []

    def patch(self, monkeypatch: pytest.MonkeyPatch, api: object, names: list[str]) -> None:
        for name in names:
            monkeypatch.setattr(api, name, self.make_stub(name))

    def make_stub(self, name: str) -> Callable[..., int]:
        def stub(*args: Any) -> int:
            self.calls.append((name, args))
            return 0
        return stub

    def names(self) -> list[str]:
        return [name for name, _ in self.calls]


QUOTE_METHODS: list[str] = [
    "qryCommodity",
    "qryContract",
    "subscribeQuote",
    "login",
    "disconnect",
    "exit",
]

TRADE_METHODS: list[str] = [
    "qryFund",
    "qryOrder",
    "qryFill",
    "qryPosition",
    "insertOrder",
    "cancelOrder",
    "login",
    "disconnect",
    "exit",
]


@pytest.fixture(autouse=True)
def clear_caches() -> Iterator[None]:
    esunny_gateway.commodity_infos.clear()
    esunny_gateway.contract_infos.clear()
    yield
    esunny_gateway.commodity_infos.clear()
    esunny_gateway.contract_infos.clear()


@pytest.fixture
def sink() -> Sink:
    return Sink()


@pytest.fixture
def recorder() -> CallRecorder:
    return CallRecorder()


@pytest.fixture
def gateway(sink: Sink, recorder: CallRecorder, monkeypatch: pytest.MonkeyPatch) -> EsunnyGateway:
    engine: EventEngine = EventEngine()
    gateway: EsunnyGateway = EsunnyGateway(engine, "ESUNNY")
    sink.attach(gateway)
    recorder.patch(monkeypatch, gateway.md_api, QUOTE_METHODS)
    recorder.patch(monkeypatch, gateway.td_api, TRADE_METHODS)
    return gateway


@pytest.fixture
def quote_api(gateway: EsunnyGateway) -> QuoteApi:
    return gateway.md_api


@pytest.fixture
def trade_api(gateway: EsunnyGateway) -> TradeApi:
    return gateway.td_api


def freeze_now(monkeypatch: pytest.MonkeyPatch) -> None:
    class FrozenDateTime(datetime):
        @classmethod
        def now(cls, tz: Any = None) -> datetime:
            return datetime(2025, 10, 10, 9, 30, 0)

    monkeypatch.setattr(esunny_gateway, "datetime", FrozenDateTime)


def add_futures_contract() -> None:
    esunny_gateway.contract_infos[("rb2510", Exchange.SHFE)] = ContractInfo(
        name="rb2510",
        contract_no="2510",
        exchange_no="SHFE",
        commodity_type="F",
        commodity_no="rb",
    )


def add_sge_commodity() -> None:
    esunny_gateway.commodity_infos[("SGE", "Au99.99", "Y")] = CommodityInfo(
        size=10,
        pricetick=0.01,
        exchange_no="SGE",
        commodity_type="Y",
        commodity_no="Au99.99",
    )


def order_request(
    symbol: str = "rb2510",
    exchange: Exchange = Exchange.SHFE,
    order_type: OrderType = OrderType.LIMIT,
    offset: Offset = Offset.CLOSETODAY,
) -> OrderRequest:
    return OrderRequest(
        symbol=symbol,
        exchange=exchange,
        direction=Direction.LONG,
        type=order_type,
        volume=2,
        price=3000,
        offset=offset,
    )


def order_data(**overrides: Any) -> dict[str, Any]:
    data: dict[str, Any] = {
        "OrderNo": "SYS1",
        "RefString": "1001",
        "CommodityNo": "rb",
        "ContractNo": "2510",
        "ExchangeNo": "SHFE",
        "OrderType": "2",
        "TimeInForce": "0",
        "OrderSide": "B",
        "PositionEffect": "O",
        "OrderPrice": 3000,
        "OrderQty": 2,
        "OrderMatchQty": 0,
        "OrderState": "4",
        "OrderInsertTime": "2025-10-10 09:30:00",
        "ErrorCode": 0,
        "ErrorText": "",
    }
    data.update(overrides)
    return data


def tick_data(**overrides: Any) -> dict[str, Any]:
    data: dict[str, Any] = {
        "CommodityNo": "rb",
        "ContractNo1": "2510",
        "ExchangeNo": "SHFE",
        "DateTimeStamp": "2025-10-10 09:30:00.500",
        "QTotalQty": 100,
        "QLastPrice": 3000,
        "QLastQty": 1,
        "QLimitUpPrice": 3300,
        "QLimitDownPrice": 2700,
        "QOpeningPrice": 2990,
        "QHighPrice": 3010,
        "QLowPrice": 2980,
        "QPreClosingPrice": 2985,
        "QBidPrice": [2999, 2998, 2997, 2996, 2995],
        "QAskPrice": [3001, 3002, 3003, 3004, 3005],
        "QBidQty": [5, 4, 3, 2, 1],
        "QAskQty": [1, 2, 3, 4, 5],
    }
    data.update(overrides)
    return data


def position_detail(**overrides: Any) -> dict[str, Any]:
    data: dict[str, Any] = {
        "ExchangeNo": "DCE",
        "CommodityNo": "m",
        "ContractNo": "2501",
        "MatchSide": "S",
        "PositionNo": "P1",
        "PositionQty": 2,
        "PositionPrice": 3000,
        "IsHistory": "N",
    }
    data.update(overrides)
    return data


@pytest.mark.parametrize(
    ("timestamp", "expected"),
    [
        ("2025-10-10 09:30:00.123", datetime(2025, 10, 10, 9, 30, 0, 123000)),
        ("2025-10-10 09:30:00", datetime(2025, 10, 10, 9, 30, 0)),
        ("251010093000.123", datetime(2025, 10, 10, 9, 30, 0, 123000)),
    ],
)
def test_generate_datetime_formats(timestamp: str, expected: datetime) -> None:
    assert generate_datetime(timestamp) == expected.replace(tzinfo=CHINA_TZ)


def test_czce_exchange_code_is_zce() -> None:
    assert EXCHANGE_VT2ES[Exchange.CZCE] == "ZCE"
    assert EXCHANGE_ES2VT["ZCE"] == Exchange.CZCE


def test_gateway_connect_forwards_host_and_port(
    gateway: EsunnyGateway,
    monkeypatch: pytest.MonkeyPatch,
) -> None:
    seen: dict[str, tuple[Any, ...]] = {}
    monkeypatch.setattr(gateway.md_api, "connect", lambda *args: seen.__setitem__("md", args))
    monkeypatch.setattr(gateway.td_api, "connect", lambda *args: seen.__setitem__("td", args))

    setting: dict[str, Any] = dict(EsunnyGateway.default_setting)
    setting["行情账号"] = "mq"
    setting["行情密码"] = "mp"
    setting["行情服务器"] = "127.0.0.1"
    setting["行情端口"] = 9001
    setting["行情授权编码"] = "ma"
    setting["交易账号"] = "tq"
    setting["交易密码"] = "tp"
    setting["交易服务器"] = "10.0.0.2"
    setting["交易端口"] = 9002
    setting["交易产品名称"] = "app"
    setting["交易授权编码"] = "ta"
    gateway.connect(setting)

    assert seen["md"] == ("mq", "mp", "127.0.0.1", 9001, "ma")
    assert seen["td"] == ("tq", "tp", "10.0.0.2", 9002, "app", "ta")


def test_quote_login_request(quote_api: QuoteApi, recorder: CallRecorder) -> None:
    quote_api.username = "mq"
    quote_api.password = "mp"
    quote_api.login_server()

    data: dict[str, Any] = recorder.calls[0][1][0]
    assert data["UserNo"] == "mq"
    assert data["Password"] == "mp"
    assert data["ISModifyPassword"] == FLAG_VT2ES["APIYNFLAG_NO"]
    assert data["ISDDA"] == FLAG_VT2ES["APIYNFLAG_NO"]
    assert "AuthCode" not in data


def test_trade_login_request(trade_api: TradeApi, recorder: CallRecorder) -> None:
    trade_api.username = "tq"
    trade_api.password = "tp"
    trade_api.auth_code = "ta"
    trade_api.appid = "app"
    trade_api.login_server()

    data: dict[str, Any] = recorder.calls[0][1][0]
    assert data["UserNo"] == "tq"
    assert data["AuthCode"] == "ta"
    assert data["AppID"] == "app"
    assert data["ISModifyPassword"] == "N"
    assert data["ISDDA"] == "N"


def test_quote_ready_queries_commodity(quote_api: QuoteApi, recorder: CallRecorder) -> None:
    quote_api.onAPIReady()

    assert recorder.names() == ["qryCommodity"]


def test_trade_ready_queries_fund(trade_api: TradeApi, sink: Sink, recorder: CallRecorder) -> None:
    trade_api.onAPIReady()

    assert recorder.names() == ["qryFund"]
    assert sink.logs == ["交易服务器API准备就绪"]


def test_commodity_error_stops_chain(quote_api: QuoteApi, sink: Sink, recorder: CallRecorder) -> None:
    quote_api.onRspQryCommodity(1, 1, "Y", {})

    assert recorder.calls == []
    assert sink.logs == ["查询交易品种信息失败"]


def test_commodity_futures_last_queries_contract(
    quote_api: QuoteApi,
    sink: Sink,
    recorder: CallRecorder,
) -> None:
    quote_api.onRspQryCommodity(1, 0, "Y", {
        "CommodityType": "F",
        "CommodityNo": "rb",
        "ContractSize": "10",
        "CommodityTickSize": 1.0,
        "ExchangeNo": "SHFE",
    })

    assert sink.contracts == []
    assert esunny_gateway.commodity_infos[("SHFE", "rb", "F")].size == 10
    assert recorder.names() == ["qryContract"]
    assert sink.logs == ["查询交易品种信息成功"]


@pytest.mark.parametrize(
    ("commodity_no", "size", "pricetick"),
    [
        ("AU(T+D)", 1000, 0.01),
        ("AG(T+D)", 1, 1),
    ],
)
def test_spot_commodity_override_does_not_change_pushed_contract(
    quote_api: QuoteApi,
    sink: Sink,
    commodity_no: str,
    size: int,
    pricetick: float,
) -> None:
    quote_api.onRspQryCommodity(1, 0, "N", {
        "CommodityType": "Y",
        "CommodityNo": commodity_no,
        "ContractSize": 10,
        "CommodityTickSize": 0.05,
        "ExchangeNo": "SGE",
    })

    contract: ContractData = sink.contracts[0]
    assert contract.symbol == commodity_no
    assert contract.exchange == Exchange.SGE
    assert contract.product == Product.SPOT
    assert contract.size == 10
    assert contract.pricetick == 0.05
    cached: CommodityInfo = esunny_gateway.commodity_infos[("SGE", commodity_no, "Y")]
    assert cached.size == size
    assert cached.pricetick == pricetick


def test_contract_empty_tail_logs_success(quote_api: QuoteApi, sink: Sink) -> None:
    quote_api.onRspQryContract(1, 0, "Y", {})

    assert sink.logs == ["查询交易合约信息成功"]
    assert sink.contracts == []


def test_contract_futures_pushed(quote_api: QuoteApi, sink: Sink) -> None:
    esunny_gateway.commodity_infos[("SHFE", "rb", "F")] = CommodityInfo(
        size=10,
        pricetick=1,
        exchange_no="SHFE",
        commodity_type="F",
        commodity_no="rb",
    )
    quote_api.onRspQryContract(1, 0, "Y", {
        "ExchangeNo": "SHFE",
        "CommodityNo": "rb",
        "CommodityType": "F",
        "ContractNo1": "2510",
    })

    contract: ContractData = sink.contracts[0]
    assert contract.symbol == "rb2510"
    assert contract.exchange == Exchange.SHFE
    assert contract.product == Product.FUTURES
    assert contract.size == 10
    assert esunny_gateway.contract_infos[("rb2510", Exchange.SHFE)].contract_no == "2510"
    assert "查询交易合约信息成功" in sink.logs


def test_contract_without_commodity_is_skipped(quote_api: QuoteApi, sink: Sink) -> None:
    quote_api.onRspQryContract(1, 0, "N", {
        "ExchangeNo": "SHFE",
        "CommodityNo": "rb",
        "CommodityType": "F",
        "ContractNo1": "2510",
    })

    assert sink.contracts == []
    assert esunny_gateway.contract_infos == {}


def test_contract_option_type_is_skipped(quote_api: QuoteApi, sink: Sink) -> None:
    esunny_gateway.commodity_infos[("SHFE", "rb", "O")] = CommodityInfo(
        size=10,
        pricetick=1,
        exchange_no="SHFE",
        commodity_type="O",
        commodity_no="rb",
    )
    quote_api.onRspQryContract(1, 0, "N", {
        "ExchangeNo": "SHFE",
        "CommodityNo": "rb",
        "CommodityType": "O",
        "ContractNo1": "2510",
    })

    assert sink.contracts == []


def test_fund_error_stops_chain(trade_api: TradeApi, sink: Sink, recorder: CallRecorder) -> None:
    trade_api.onRspQryFund(1, 1, "Y", {})

    assert recorder.calls == []
    assert sink.accounts == []
    assert sink.logs == ["查询资金信息失败"]


def test_fund_pushes_account_and_queries_order(trade_api: TradeApi, sink: Sink, recorder: CallRecorder) -> None:
    trade_api.onRspQryFund(1, 0, "Y", {"AccountNo": "A1", "Balance": 1000.0, "Available": 800.0})

    account: AccountData = sink.accounts[0]
    assert account.accountid == "A1"
    assert account.balance == 1000.0
    assert account.frozen == 200.0
    assert account.available == 800.0
    assert recorder.names() == ["qryOrder"]
    assert "查询资金信息成功" in sink.logs


def test_order_empty_tail_queries_trade(trade_api: TradeApi, sink: Sink, recorder: CallRecorder) -> None:
    trade_api.onRspQryOrder(1, 0, "Y", {})

    assert recorder.names() == ["qryFill"]
    assert sink.logs == ["查询委托信息成功"]
    assert sink.orders == []


def test_order_error_stops_chain(trade_api: TradeApi, sink: Sink, recorder: CallRecorder) -> None:
    trade_api.onRspQryOrder(1, 1, "Y", {})

    assert recorder.calls == []
    assert sink.logs == ["查询委托信息失败"]


def test_fill_empty_tail_logs_success(trade_api: TradeApi, sink: Sink) -> None:
    trade_api.onRspQryFill(1, 0, "Y", {})

    assert sink.logs == ["查询成交信息成功"]
    assert sink.trades == []


def test_position_aggregates_volume_and_history(trade_api: TradeApi, sink: Sink) -> None:
    trade_api.onRspQryPosition(1, 0, "N", position_detail())
    trade_api.onRspQryPosition(1, 0, "N", position_detail(
        PositionNo="P2",
        PositionQty=1,
        PositionPrice=3300,
        IsHistory="Y",
    ))
    assert sink.positions == []

    trade_api.onRspQryPosition(1, 0, "Y", {})

    position: PositionData = sink.positions[0]
    assert position.symbol == "m2501"
    assert position.exchange == Exchange.DCE
    assert position.direction == Direction.SHORT
    assert position.volume == 3
    assert position.yd_volume == 1
    assert position.price == 3100


def test_position_sge_symbol_drops_contract_no(trade_api: TradeApi, sink: Sink) -> None:
    trade_api.onRspQryPosition(1, 0, "Y", position_detail(
        ExchangeNo="SGE",
        CommodityNo="Au99.99",
        ContractNo="X",
        MatchSide="B",
        PositionQty=5,
        PositionPrice=500,
        IsHistory="Y",
    ))

    position: PositionData = sink.positions[0]
    assert position.symbol == "Au99.99"
    assert position.exchange == Exchange.SGE
    assert position.direction == Direction.LONG
    assert position.volume == 5
    assert position.yd_volume == 5


def test_position_error_stops(trade_api: TradeApi, sink: Sink) -> None:
    trade_api.onRspQryPosition(1, 1, "Y", {})

    assert sink.positions == []
    assert sink.logs == ["查询持仓信息失败"]


def test_query_position_zeros_then_empty_tail_pushes(
    trade_api: TradeApi,
    sink: Sink,
    recorder: CallRecorder,
) -> None:
    trade_api.onRspQryPosition(1, 0, "Y", position_detail())
    assert sink.positions[0].volume == 2

    trade_api.query_position()

    assert recorder.names() == ["qryPosition"]
    assert trade_api.positions[("m2501", "S")].volume == 0
    trade_api.onRspQryPosition(2, 0, "Y", {})
    assert sink.positions[-1].volume == 0
    assert sink.positions[-1].yd_volume == 0
    assert sink.positions[-1].price == 0


def test_send_order_unknown_contract_returns_empty(trade_api: TradeApi, sink: Sink, recorder: CallRecorder) -> None:
    assert trade_api.send_order(order_request()) == ""
    assert recorder.names() == []
    assert sink.logs


def test_send_order_unsupported_type_returns_empty(trade_api: TradeApi, sink: Sink) -> None:
    add_futures_contract()

    assert trade_api.send_order(order_request(order_type=OrderType.STOP)) == ""
    assert sink.orders == []


def test_send_order_returns_ref_string(
    trade_api: TradeApi,
    sink: Sink,
    recorder: CallRecorder,
    monkeypatch: pytest.MonkeyPatch,
) -> None:
    freeze_now(monkeypatch)
    add_futures_contract()
    trade_api.username = "tq"

    vt_orderid: str = trade_api.send_order(order_request())

    assert vt_orderid == f"ESUNNY.{ORDER_ID}"
    request: dict[str, Any] = recorder.calls[0][1][1]
    assert request["RefString"] == ORDER_ID
    assert request["RefInt"] == 1
    assert request["AccountNo"] == "tq"
    assert request["ExchangeNo"] == "SHFE"
    assert request["CommodityNo"] == "rb"
    assert request["ContractNo"] == "2510"
    assert request["OrderType"] == "2"
    assert request["TimeInForce"] == "0"
    assert request["OrderSide"] == "B"
    assert request["PositionEffect"] == "T"
    assert request["OrderQty"] == 2
    assert request["HedgeFlag"] == HEDGETYPE_VT2ES["TAPI_HEDGEFLAG_T"]
    assert sink.orders[0].status == Status.SUBMITTING
    assert sink.orders[0].orderid == ORDER_ID


def test_send_order_sge_uses_commodity(
    trade_api: TradeApi,
    recorder: CallRecorder,
    monkeypatch: pytest.MonkeyPatch,
) -> None:
    freeze_now(monkeypatch)
    add_sge_commodity()
    trade_api.send_order(order_request(symbol="Au99.99", exchange=Exchange.SGE, offset=Offset.OPEN))

    request: dict[str, Any] = recorder.calls[0][1][1]
    assert request["ExchangeNo"] == "SGE"
    assert request["CommodityNo"] == "Au99.99"
    assert request["ContractNo"] == "Au99.99"
    assert request["CommodityType"] == "Y"
    assert request["PositionEffect"] == "O"


def test_send_order_fak(trade_api: TradeApi, recorder: CallRecorder, monkeypatch: pytest.MonkeyPatch) -> None:
    freeze_now(monkeypatch)
    add_futures_contract()
    trade_api.send_order(order_request(order_type=OrderType.FAK))

    request: dict[str, Any] = recorder.calls[0][1][1]
    assert request["OrderType"] == "2"
    assert request["TimeInForce"] == "3"


def test_send_order_error_marks_rejected(
    trade_api: TradeApi,
    sink: Sink,
    monkeypatch: pytest.MonkeyPatch,
) -> None:
    freeze_now(monkeypatch)
    add_futures_contract()

    def insert_order(reqid: int, req: dict[str, Any]) -> int:
        return 8

    monkeypatch.setattr(trade_api, "insertOrder", insert_order)
    vt_orderid: str = trade_api.send_order(order_request())

    assert vt_orderid == f"ESUNNY.{ORDER_ID}"
    assert sink.orders[0].status == Status.REJECTED
    assert "委托请求失败" in sink.logs[0]


@pytest.mark.parametrize(
    ("state", "expected"),
    [
        ("0", Status.SUBMITTING),
        ("4", Status.NOTTRADED),
        ("5", Status.PARTTRADED),
        ("6", Status.ALLTRADED),
        ("9", Status.CANCELLED),
        ("B", Status.REJECTED),
    ],
)
def test_order_maps_ref_and_status(trade_api: TradeApi, sink: Sink, state: str, expected: Status) -> None:
    trade_api.onRtnOrder(order_data(OrderState=state, OrderMatchQty=1))

    order: OrderData = sink.orders[0]
    assert order.orderid == "1001"
    assert order.status == expected
    assert order.type == OrderType.LIMIT
    assert order.direction == Direction.LONG
    assert order.offset == Offset.OPEN
    assert order.traded == 1
    assert order.symbol == "rb2510"
    assert order.datetime == datetime(2025, 10, 10, 9, 30, tzinfo=CHINA_TZ)
    assert trade_api.local_sys_map["1001"] == "SYS1"
    assert trade_api.sys_local_map["SYS1"] == "1001"


def test_sge_order_symbol_drops_contract_no(trade_api: TradeApi, sink: Sink) -> None:
    trade_api.onRtnOrder(order_data(ExchangeNo="SGE", CommodityNo="Au99.99", ContractNo="X"))

    assert sink.orders[0].symbol == "Au99.99"
    assert sink.orders[0].exchange == Exchange.SGE


@pytest.mark.parametrize("state", ["7", "8"])
def test_pending_cancel_or_modify_state_is_skipped(trade_api: TradeApi, sink: Sink, state: str) -> None:
    trade_api.onRtnOrder(order_data(OrderState=state))

    assert sink.orders == []
    assert trade_api.local_sys_map == {}


def test_order_error_code_still_pushes(trade_api: TradeApi, sink: Sink) -> None:
    trade_api.onRtnOrder(order_data(ErrorCode=10, ErrorText="bad"))

    assert sink.orders[0].status == Status.NOTTRADED
    assert "委托下单失败" in sink.logs[0]
    assert trade_api.local_sys_map["1001"] == "SYS1"


def test_cancel_without_sysid_is_logged(trade_api: TradeApi, sink: Sink, recorder: CallRecorder) -> None:
    trade_api.cancel_order(CancelRequest(orderid="1001", symbol="rb2510", exchange=Exchange.SHFE))

    assert recorder.calls == []
    assert "撤单失败" in sink.logs[0]


def test_cancel_after_order_return_uses_order_no(trade_api: TradeApi, recorder: CallRecorder) -> None:
    trade_api.onRtnOrder(order_data())
    trade_api.cancel_order(CancelRequest(orderid="1001", symbol="rb2510", exchange=Exchange.SHFE))

    assert recorder.calls[-1] == ("cancelOrder", (1, {"OrderNo": "SYS1"}))


def test_trade_without_order_is_ignored(trade_api: TradeApi, sink: Sink) -> None:
    trade_api.onRtnFill({
        "OrderNo": "SYS1",
        "CommodityNo": "rb",
        "ContractNo": "2510",
        "ExchangeNo": "SHFE",
        "MatchNo": "M1",
        "MatchSide": "B",
        "PositionEffect": "O",
        "MatchPrice": 3001,
        "MatchQty": 1,
        "MatchDateTime": "2025-10-10 09:31:00",
    })

    assert sink.trades == []


def test_trade_uses_local_order_id(trade_api: TradeApi, sink: Sink) -> None:
    trade_api.onRtnOrder(order_data())
    trade_api.onRtnFill({
        "OrderNo": "SYS1",
        "CommodityNo": "rb",
        "ContractNo": "2510",
        "ExchangeNo": "SHFE",
        "MatchNo": "M1",
        "MatchSide": "B",
        "PositionEffect": "T",
        "MatchPrice": 3001,
        "MatchQty": 1,
        "MatchDateTime": "2025-10-10 09:31:00",
    })

    trade: TradeData = sink.trades[0]
    assert trade.orderid == "1001"
    assert trade.tradeid == "M1"
    assert trade.offset == Offset.CLOSETODAY
    assert trade.direction == Direction.LONG
    assert trade.datetime == datetime(2025, 10, 10, 9, 31, tzinfo=CHINA_TZ)


def test_tick_without_timestamp_is_ignored(quote_api: QuoteApi, sink: Sink) -> None:
    quote_api.onRtnQuote(tick_data(DateTimeStamp=""))

    assert sink.ticks == []


def test_tick_pushes_depth_and_time(quote_api: QuoteApi, sink: Sink) -> None:
    quote_api.onRtnQuote(tick_data())

    tick: TickData = sink.ticks[0]
    assert tick.symbol == "rb2510"
    assert tick.exchange == Exchange.SHFE
    assert tick.datetime == datetime(2025, 10, 10, 9, 30, 0, 500000, tzinfo=CHINA_TZ)
    assert tick.last_price == 3000
    assert tick.bid_price_1 == 2999
    assert tick.ask_price_5 == 3005
    assert tick.bid_volume_5 == 1
    assert tick.ask_volume_1 == 1


def test_tick_zce_maps_to_czce(quote_api: QuoteApi, sink: Sink) -> None:
    quote_api.onRtnQuote(tick_data(ExchangeNo="ZCE", CommodityNo="SR", ContractNo1="501"))

    assert sink.ticks[0].exchange == Exchange.CZCE
    assert sink.ticks[0].symbol == "SR501"


def test_subscribe_unknown_contract_is_skipped(quote_api: QuoteApi, sink: Sink, recorder: CallRecorder) -> None:
    quote_api.subscribe(SubscribeRequest(symbol="rb2510", exchange=Exchange.SHFE))

    assert recorder.calls == []
    assert sink.logs


def test_subscribe_futures(quote_api: QuoteApi, recorder: CallRecorder) -> None:
    add_futures_contract()
    quote_api.subscribe(SubscribeRequest(symbol="rb2510", exchange=Exchange.SHFE))

    request: dict[str, Any] = recorder.calls[0][1][1]
    assert request["ExchangeNo"] == "SHFE"
    assert request["CommodityType"] == "F"
    assert request["CommodityNo"] == "rb"
    assert request["ContractNo1"] == "2510"
    assert request["CallOrPutFlag1"] == "N"


def test_subscribe_sge_uses_commodity(quote_api: QuoteApi, recorder: CallRecorder) -> None:
    add_sge_commodity()
    quote_api.subscribe(SubscribeRequest(symbol="Au99.99", exchange=Exchange.SGE))

    request: dict[str, Any] = recorder.calls[0][1][1]
    assert request["ExchangeNo"] == "SGE"
    assert request["CommodityType"] == "Y"
    assert request["CommodityNo"] == "Au99.99"
    assert "ContractNo1" not in request


def test_reconnect_waits_for_interval(trade_api: TradeApi, recorder: CallRecorder) -> None:
    trade_api.need_reconnect = True
    trade_api.host = "127.0.0.1"
    trade_api.port = 1

    for _ in range(COUNT_INTERVAL - 1):
        trade_api.check_reconnect()

    assert trade_api.need_reconnect is True
    assert recorder.calls == []


def test_close_without_connection_does_not_exit(
    trade_api: TradeApi,
    quote_api: QuoteApi,
    recorder: CallRecorder,
) -> None:
    trade_api.close()
    quote_api.close()

    assert recorder.calls == []


def test_close_after_init_disconnects_and_exits(
    trade_api: TradeApi,
    quote_api: QuoteApi,
    recorder: CallRecorder,
) -> None:
    trade_api.inited = True
    quote_api.inited = True

    trade_api.close()
    quote_api.close()

    assert recorder.names() == ["disconnect", "exit", "disconnect", "exit"]
    assert trade_api.inited is False
    assert quote_api.inited is False
    assert trade_api.need_reconnect is False
    assert quote_api.need_reconnect is False
