int TdApi::qryOrderProcess(unsigned int session, const dict &req)
{
	TapAPIOrderProcessQryReq myreq = TapAPIOrderProcessQryReq();
	memset(&myreq, 0, sizeof(myreq));
	getChar(req, "ServerFlag", &myreq.ServerFlag);
	getString(req, "OrderNo", myreq.OrderNo);
	int i = this->api->QryOrderProcess(session, &myreq);
	return i;
};

int TdApi::qryDeepQuote(unsigned int session, const dict &req)
{
	TapAPIContract myreq = TapAPIContract();
	memset(&myreq, 0, sizeof(myreq));
	getDict(req, "Commodity", &myreq.Commodity);
	getString(req, "ContractNo1", myreq.ContractNo1);
	getString(req, "StrikePrice1", myreq.StrikePrice1);
	getChar(req, "CallOrPutFlag1", &myreq.CallOrPutFlag1);
	getString(req, "ContractNo2", myreq.ContractNo2);
	getString(req, "StrikePrice2", myreq.StrikePrice2);
	getChar(req, "CallOrPutFlag2", &myreq.CallOrPutFlag2);
	int i = this->api->QryDeepQuote(session, &myreq);
	return i;
};

int TdApi::qryAccountRent(unsigned int session, const dict &req)
{
	TapAPIAccountRentQryReq myreq = TapAPIAccountRentQryReq();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "AccountNo", myreq.AccountNo);
	getString(req, "ExchangeNo", myreq.ExchangeNo);
	getChar(req, "CommodityType", &myreq.CommodityType);
	getString(req, "CommodityNo", myreq.CommodityNo);
	getString(req, "ContractNo", myreq.ContractNo);
	int i = this->api->QryAccountRent(session, &myreq);
	return i;
};

int TdApi::qryAccountFeeRent(unsigned int session, const dict &req)
{
	TapAPIAccountFeeRentQryReq myreq = TapAPIAccountFeeRentQryReq();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "AccountNo", myreq.AccountNo);
	int i = this->api->QryAccountFeeRent(session, &myreq);
	return i;
};

int TdApi::qryAccountMarginRent(unsigned int session, const dict &req)
{
	TapAPIAccountMarginRentQryReq myreq = TapAPIAccountMarginRentQryReq();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "AccountNo", myreq.AccountNo);
	getString(req, "ExchangeNo", myreq.ExchangeNo);
	getChar(req, "CommodityType", &myreq.CommodityType);
	getString(req, "CommodityNo", myreq.CommodityNo);
	getDict(req, "ContractNo", &myreq.ContractNo);
	int i = this->api->QryAccountMarginRent(session, &myreq);
	return i;
};

int TdApi::qryAccountCashAdjust(unsigned int session, const dict &req)
{
	TapAPIAccountCashAdjustQryReq myreq = TapAPIAccountCashAdjustQryReq();
	memset(&myreq, 0, sizeof(myreq));
	getUnsigned int(req, "SerialID", &myreq.SerialID);
	getString(req, "AccountNo", myreq.AccountNo);
	getString(req, "AccountAttributeNo", myreq.AccountAttributeNo);
	getString(req, "BeginDate", myreq.BeginDate);
	getString(req, "EndDate", myreq.EndDate);
	int i = this->api->QryAccountCashAdjust(session, &myreq);
	return i;
};

int TdApi::qryBill(unsigned int session, const dict &req)
{
	TapAPIBillQryReq myreq = TapAPIBillQryReq();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "UserNo", myreq.UserNo);
	getChar(req, "BillType", &myreq.BillType);
	getString(req, "BillDate", myreq.BillDate);
	getChar(req, "BillFileType", &myreq.BillFileType);
	int i = this->api->QryBill(session, &myreq);
	return i;
};

int TdApi::qryHisOrder(unsigned int session, const dict &req)
{
	TapAPIHisOrderQryReq myreq = TapAPIHisOrderQryReq();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "AccountNo", myreq.AccountNo);
	getString(req, "AccountAttributeNo", myreq.AccountAttributeNo);
	getString(req, "BeginDate", myreq.BeginDate);
	getString(req, "EndDate", myreq.EndDate);
	int i = this->api->QryHisOrder(session, &myreq);
	return i;
};

int TdApi::qryHisOrderProcess(unsigned int session, const dict &req)
{
	TapAPIHisOrderProcessQryReq myreq = TapAPIHisOrderProcessQryReq();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "Date", myreq.Date);
	getString(req, "OrderNo", myreq.OrderNo);
	int i = this->api->QryHisOrderProcess(session, &myreq);
	return i;
};

int TdApi::qryHisFill(unsigned int session, const dict &req)
{
	TapAPIHisFillQryReq myreq = TapAPIHisFillQryReq();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "AccountNo", myreq.AccountNo);
	getString(req, "AccountAttributeNo", myreq.AccountAttributeNo);
	getString(req, "BeginDate", myreq.BeginDate);
	getString(req, "EndDate", myreq.EndDate);
	getChar(req, "CountType", &myreq.CountType);
	int i = this->api->QryHisFill(session, &myreq);
	return i;
};

int TdApi::qryHisPosition(unsigned int session, const dict &req)
{
	TapAPIHisPositionQryReq myreq = TapAPIHisPositionQryReq();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "AccountNo", myreq.AccountNo);
	getString(req, "Date", myreq.Date);
	getChar(req, "SettleFlag", &myreq.SettleFlag);
	int i = this->api->QryHisPosition(session, &myreq);
	return i;
};

int TdApi::qryHisDelivery(unsigned int session, const dict &req)
{
	TapAPIHisDeliveryQryReq myreq = TapAPIHisDeliveryQryReq();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "AccountNo", myreq.AccountNo);
	getString(req, "AccountAttributeNo", myreq.AccountAttributeNo);
	getString(req, "BeginDate", myreq.BeginDate);
	getString(req, "EndDate", myreq.EndDate);
	getChar(req, "CountType", &myreq.CountType);
	int i = this->api->QryHisDelivery(session, &myreq);
	return i;
};

int TdApi::qryManageInfoForEStar(unsigned int session, const dict &req)
{
	TapAPIManageInfoQryReq myreq = TapAPIManageInfoQryReq();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "BeginDate", myreq.BeginDate);
	getString(req, "EndDate", myreq.EndDate);
	int i = this->api->QryManageInfoForEStar(session, &myreq);
	return i;
};

int TdApi::qrySystemParameter(unsigned int session, const dict &req)
{
	TapAPISystemParameterQryReq myreq = TapAPISystemParameterQryReq();
	memset(&myreq, 0, sizeof(myreq));
	int i = this->api->QrySystemParameter(session, &myreq);
	return i;
};

int TdApi::qryTradeCenterFrontAddress(unsigned int session, const dict &req)
{
	TapAPITradeCenterFrontAddressQryReq myreq = TapAPITradeCenterFrontAddressQryReq();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "FrontAddress", myreq.FrontAddress);
	getString(req, "FrontPort", myreq.FrontPort);
	getChar(req, "TradeCenter", &myreq.TradeCenter);
	getChar(req, "IsSSL", &myreq.IsSSL);
	int i = this->api->QryTradeCenterFrontAddress(session, &myreq);
	return i;
};

int TdApi::qryTradeMessage(unsigned int session, const dict &req)
{
	TapAPITradeMessageQryReq myreq = TapAPITradeMessageQryReq();
	memset(&myreq, 0, sizeof(myreq));
	getUnsigned int(req, "SerialID", &myreq.SerialID);
	getChar(req, "TradeMsgQryType", &myreq.TradeMsgQryType);
	getString(req, "AccountNo", myreq.AccountNo);
	getString(req, "BeginSendDateTime", myreq.BeginSendDateTime);
	getString(req, "EndSendDateTime", myreq.EndSendDateTime);
	int i = this->api->QryTradeMessage(session, &myreq);
	return i;
};

int TdApi::qryAccountStorage(unsigned int session, const dict &req)
{
	TapAPIAccountStorageQryReq myreq = TapAPIAccountStorageQryReq();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "AccountNo", myreq.AccountNo);
	int i = this->api->QryAccountStorage(session, &myreq);
	return i;
};

int TdApi::qrySpotLock(unsigned int session, const dict &req)
{
	TapAPISpotLockQryReq myreq = TapAPISpotLockQryReq();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "StreamAccountNo", myreq.StreamAccountNo);
	getString(req, "AccountNo", myreq.AccountNo);
	int i = this->api->QrySpotLock(session, &myreq);
	return i;
};

int TdApi::qryTrustDevice(unsigned int session, const dict &req)
{
	TapAPITrustDeviceQryReq myreq = TapAPITrustDeviceQryReq();
	memset(&myreq, 0, sizeof(myreq));
	int i = this->api->QryTrustDevice(session, &myreq);
	return i;
};

int TdApi::qryManagerConfigFile(unsigned int session, const dict &req)
{
	TapAPIManagerConfigFileQryReq myreq = TapAPIManagerConfigFileQryReq();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "FileName", myreq.FileName);
	getString(req, "FileDirectory", myreq.FileDirectory);
	int i = this->api->QryManagerConfigFile(session, &myreq);
	return i;
};

