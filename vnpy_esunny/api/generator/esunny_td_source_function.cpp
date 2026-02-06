int TdApi::qryAccount(int sessionID, const dict &req)
{
	TapAPIAccQryReq myreq = TapAPIAccQryReq();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "AccountNo", myreq.AccountNo);
	TAPIUINT32 session_id = static_cast<TAPIUINT32>(sessionID);
	int i = this->api->QryAccount(&session_id, &myreq);
	return i;
};

int TdApi::qryFund(int sessionID, const dict &req)
{
	TapAPIFundReq myreq = TapAPIFundReq();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "AccountNo", myreq.AccountNo);
	TAPIUINT32 session_id = static_cast<TAPIUINT32>(sessionID);
	int i = this->api->QryFund(&session_id, &myreq);
	return i;
};

int TdApi::qryExchange(int sessionID)
{
	TAPIUINT32 session_id = static_cast<TAPIUINT32>(sessionID);
	int i = this->api->QryExchange(&session_id);
	return i;
};

int TdApi::qryCommodity(int sessionID)
{
	TAPIUINT32 session_id = static_cast<TAPIUINT32>(sessionID);
	int i = this->api->QryCommodity(&session_id);
	return i;
};

int TdApi::qryContract(int sessionID, const dict &req)
{
	TapAPICommodity myreq = TapAPICommodity();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "ExchangeNo", myreq.ExchangeNo);
	getChar(req, "CommodityType", &myreq.CommodityType);
	getString(req, "CommodityNo", myreq.CommodityNo);
	TAPIUINT32 session_id = static_cast<TAPIUINT32>(sessionID);
	int i = this->api->QryContract(&session_id, &myreq);
	return i;
};

int TdApi::qryOrder(int sessionID, const dict &req)
{
	TapAPIOrderQryReq myreq = TapAPIOrderQryReq();
	memset(&myreq, 0, sizeof(myreq));
	getChar(req, "OrderQryType", &myreq.OrderQryType);
	TAPIUINT32 session_id = static_cast<TAPIUINT32>(sessionID);
	int i = this->api->QryOrder(&session_id, &myreq);
	return i;
};

int TdApi::qryOrderProcess(int sessionID, const dict &req)
{
	TapAPIOrderProcessQryReq myreq = TapAPIOrderProcessQryReq();
	memset(&myreq, 0, sizeof(myreq));
	getChar(req, "ServerFlag", &myreq.ServerFlag);
	getString(req, "OrderNo", myreq.OrderNo);
	TAPIUINT32 session_id = static_cast<TAPIUINT32>(sessionID);
	int i = this->api->QryOrderProcess(&session_id, &myreq);
	return i;
};

int TdApi::qryFill(int sessionID, const dict &req)
{
	TapAPIFillQryReq myreq = TapAPIFillQryReq();
	memset(&myreq, 0, sizeof(myreq));
	getUnsignedInt(req, "StreamID", &myreq.StreamID);
	TAPIUINT32 session_id = static_cast<TAPIUINT32>(sessionID);
	int i = this->api->QryFill(&session_id, &myreq);
	return i;
};

int TdApi::qryPosition(int sessionID, const dict &req)
{
	TapAPIPositionQryReq myreq = TapAPIPositionQryReq();
	memset(&myreq, 0, sizeof(myreq));
	TAPIUINT32 session_id = static_cast<TAPIUINT32>(sessionID);
	int i = this->api->QryPosition(&session_id, &myreq);
	return i;
};

int TdApi::qryClose(int sessionID, const dict &req)
{
	TapAPICloseQryReq myreq = TapAPICloseQryReq();
	memset(&myreq, 0, sizeof(myreq));
	TAPIUINT32 session_id = static_cast<TAPIUINT32>(sessionID);
	int i = this->api->QryClose(&session_id, &myreq);
	return i;
};

int TdApi::qryDeepQuote(int sessionID, const dict &req)
{
	TapAPIContract myreq = TapAPIContract();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "Commodity.ExchangeNo", myreq.Commodity.ExchangeNo);
	getChar(req, "Commodity.CommodityType", &myreq.Commodity.CommodityType);
	getString(req, "Commodity.CommodityNo", myreq.Commodity.CommodityNo);
	getString(req, "ContractNo1", myreq.ContractNo1);
	getString(req, "StrikePrice1", myreq.StrikePrice1);
	getChar(req, "CallOrPutFlag1", &myreq.CallOrPutFlag1);
	getString(req, "ContractNo2", myreq.ContractNo2);
	getString(req, "StrikePrice2", myreq.StrikePrice2);
	getChar(req, "CallOrPutFlag2", &myreq.CallOrPutFlag2);
	TAPIUINT32 session_id = static_cast<TAPIUINT32>(sessionID);
	int i = this->api->QryDeepQuote(&session_id, &myreq);
	return i;
};

int TdApi::qryExchangeStateInfo(int sessionID, const dict &req)
{
	TapAPIExchangeStateInfoQryReq myreq = TapAPIExchangeStateInfoQryReq();
	memset(&myreq, 0, sizeof(myreq));
	TAPIUINT32 session_id = static_cast<TAPIUINT32>(sessionID);
	int i = this->api->QryExchangeStateInfo(&session_id, &myreq);
	return i;
};

int TdApi::qryUpperChannel(int sessionID, const dict &req)
{
	TapAPIUpperChannelQryReq myreq = TapAPIUpperChannelQryReq();
	memset(&myreq, 0, sizeof(myreq));
	TAPIUINT32 session_id = static_cast<TAPIUINT32>(sessionID);
	int i = this->api->QryUpperChannel(&session_id, &myreq);
	return i;
};

int TdApi::qryAccountRent(int sessionID, const dict &req)
{
	TapAPIAccountRentQryReq myreq = TapAPIAccountRentQryReq();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "AccountNo", myreq.AccountNo);
	getString(req, "ExchangeNo", myreq.ExchangeNo);
	getChar(req, "CommodityType", &myreq.CommodityType);
	getString(req, "CommodityNo", myreq.CommodityNo);
	getString(req, "ContractNo", myreq.ContractNo);
	TAPIUINT32 session_id = static_cast<TAPIUINT32>(sessionID);
	int i = this->api->QryAccountRent(&session_id, &myreq);
	return i;
};

int TdApi::qryBill(int sessionID, const dict &req)
{
	TapAPIBillQryReq myreq = TapAPIBillQryReq();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "UserNo", myreq.UserNo);
	getChar(req, "BillType", &myreq.BillType);
	getString(req, "BillDate", myreq.BillDate);
	getChar(req, "BillFileType", &myreq.BillFileType);
	TAPIUINT32 session_id = static_cast<TAPIUINT32>(sessionID);
	int i = this->api->QryBill(&session_id, &myreq);
	return i;
};

int TdApi::qryAccountStorage(int sessionID, const dict &req)
{
	TapAPIAccountStorageQryReq myreq = TapAPIAccountStorageQryReq();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "AccountNo", myreq.AccountNo);
	TAPIUINT32 session_id = static_cast<TAPIUINT32>(sessionID);
	int i = this->api->QryAccountStorage(&session_id, &myreq);
	return i;
};

