void onConnect(string UserNo) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onConnect, UserNo);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspLogin(string UserNo, int nErrorCode, const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRspLogin, UserNo, nErrorCode, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRtnContactInfo(string UserNo, int nErrorCode, char last, const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRtnContactInfo, UserNo, nErrorCode, last, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspRequestVertificateCode(string UserNo, unsigned int session, int nErrorCode, char last, const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRspRequestVertificateCode, UserNo, session, nErrorCode, last, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspRequestVerifyIdentity(string UserNo, unsigned int session, int nErrorCode, char last, const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRspRequestVerifyIdentity, UserNo, session, nErrorCode, last, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspSetVertificateCode(string UserNo, unsigned int session, int nErrorCode, char last, const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRspSetVertificateCode, UserNo, session, nErrorCode, last, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRtnErrorMsg(string UserNo, string ErrorMsg) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRtnErrorMsg, UserNo, ErrorMsg);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onAPIReady(string UserNo) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onAPIReady, UserNo);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onDisconnect(string UserNo, int nReasonCode) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onDisconnect, UserNo, nReasonCode);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspSubmitUserLoginInfo(string UserNo, unsigned int session, const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRspSubmitUserLoginInfo, UserNo, session, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspChangePassword(string UserNo, unsigned int session, int nErrorCode, const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRspChangePassword, UserNo, session, nErrorCode, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspSetReservedInfo(string UserNo, unsigned int session, int nErrorCode, string info) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRspSetReservedInfo, UserNo, session, nErrorCode, info);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRtnContract(string UserNo, const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRtnContract, UserNo, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRtnFund(string UserNo, const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRtnFund, UserNo, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRtnOrder(string UserNo, unsigned int session, const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRtnOrder, UserNo, session, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspOrderAction(string UserNo, unsigned int session, int nErrorCode, const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRspOrderAction, UserNo, session, nErrorCode, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspQryOrderProcess(string UserNo, unsigned int session, int nErrorCode, char last, const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRspQryOrderProcess, UserNo, session, nErrorCode, last, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRtnFill(string UserNo, const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRtnFill, UserNo, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRtnPosition(string UserNo, const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRtnPosition, UserNo, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRtnClose(string UserNo, const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRtnClose, UserNo, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRtnPositionProfit(string UserNo, const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRtnPositionProfit, UserNo, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspQryDeepQuote(string UserNo, unsigned int session, int nErrorCode, char last, const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRspQryDeepQuote, UserNo, session, nErrorCode, last, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRtnExchangeStateInfo(string UserNo, const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRtnExchangeStateInfo, UserNo, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRtnReqQuoteNotice(string UserNo, const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRtnReqQuoteNotice, UserNo, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspAccountRentInfo(string UserNo, unsigned int session, int nErrorCode, char last, const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRspAccountRentInfo, UserNo, session, nErrorCode, last, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspTradeMessage(string UserNo, unsigned int session, int nErrorCode, char last, const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRspTradeMessage, UserNo, session, nErrorCode, last, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRtnTradeMessage(string UserNo, const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRtnTradeMessage, UserNo, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspQryHisOrder(string UserNo, unsigned int session, int nErrorCode, char last, const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRspQryHisOrder, UserNo, session, nErrorCode, last, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspQryHisOrderProcess(string UserNo, unsigned int session, int nErrorCode, char last, const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRspQryHisOrderProcess, UserNo, session, nErrorCode, last, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspQryHisFill(string UserNo, unsigned int session, int nErrorCode, char last, const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRspQryHisFill, UserNo, session, nErrorCode, last, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspQryHisPosition(string UserNo, unsigned int session, int nErrorCode, char last, const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRspQryHisPosition, UserNo, session, nErrorCode, last, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspQryHisDelivery(string UserNo, unsigned int session, int nErrorCode, char last, const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRspQryHisDelivery, UserNo, session, nErrorCode, last, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspQryAccountCashAdjust(string UserNo, unsigned int session, int nErrorCode, char last, const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRspQryAccountCashAdjust, UserNo, session, nErrorCode, last, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspQryBill(string UserNo, unsigned int session, int nErrorCode, char last, const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRspQryBill, UserNo, session, nErrorCode, last, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspAccountFeeRent(string UserNo, unsigned int session, int nErrorCode, char last, const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRspAccountFeeRent, UserNo, session, nErrorCode, last, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspAccountMarginRent(string UserNo, unsigned int session, int nErrorCode, char last, const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRspAccountMarginRent, UserNo, session, nErrorCode, last, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspAddMobileDevice(string UserNo, unsigned int session, int nErrorCode, char last, const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRspAddMobileDevice, UserNo, session, nErrorCode, last, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspQryManageInfoForEStar(string UserNo, unsigned int session, int nErrorCode, char last, const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRspQryManageInfoForEStar, UserNo, session, nErrorCode, last, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspQrySystemParameter(string UserNo, unsigned int session, int nErrorCode, char last, const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRspQrySystemParameter, UserNo, session, nErrorCode, last, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspQryTradeCenterFrontAddress(string UserNo, unsigned int session, int nErrorCode, char last, const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRspQryTradeCenterFrontAddress, UserNo, session, nErrorCode, last, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRtnCommodityInfo(string UserNo, const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRtnCommodityInfo, UserNo, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRtnCurrencyInfo(string UserNo, const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRtnCurrencyInfo, UserNo, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspQryAccountStorage(string UserNo, unsigned int session, int nErrorCode, char last, const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRspQryAccountStorage, UserNo, session, nErrorCode, last, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRtnAccountStorage(string UserNo, const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRtnAccountStorage, UserNo, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspQrySpotLock(string UserNo, unsigned int session, int nErrorCode, char last, const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRspQrySpotLock, UserNo, session, nErrorCode, last, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRtnSpotLock(string UserNo, const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRtnSpotLock, UserNo, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspSpecialOrderAction(string UserNo, unsigned int session, int nErrorCode, const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRspSpecialOrderAction, UserNo, session, nErrorCode, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRtnSpecialOrder(string UserNo, unsigned int session, const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRtnSpecialOrder, UserNo, session, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRtnCombinePosition(string UserNo, const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRtnCombinePosition, UserNo, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRtnContractQuote(string UserNo, const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRtnContractQuote, UserNo, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspQryTrustDevice(string UserNo, unsigned int session, int nErrorCode, char last, const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRspQryTrustDevice, UserNo, session, nErrorCode, last, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspAddTrustDevice(string UserNo, unsigned int session, int nErrorCode, char last, const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRspAddTrustDevice, UserNo, session, nErrorCode, last, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspDelTrustDevice(string UserNo, unsigned int session, int nErrorCode, char last, const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRspDelTrustDevice, UserNo, session, nErrorCode, last, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRtnAddUserRight(string UserNo, const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRtnAddUserRight, UserNo, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRtnDelUserRight(string UserNo, const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRtnDelUserRight, UserNo, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspQryManagerConfigFile(string UserNo, unsigned int session, int nErrorCode, char last, const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRspQryManagerConfigFile, UserNo, session, nErrorCode, last, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

