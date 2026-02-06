void onConnect() override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onConnect);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspLogin(int error, const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRspLogin, error, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onAPIReady() override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onAPIReady);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onDisconnect(int reasonCode) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onDisconnect, reasonCode);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspChangePassword(unsigned int sessionID, int error) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRspChangePassword, sessionID, error);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspSetReservedInfo(unsigned int sessionID, int error, string info) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRspSetReservedInfo, sessionID, error, info);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspQryAccount(unsigned int sessionID, unsigned int errorCode, char last, const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRspQryAccount, sessionID, errorCode, last, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspQryFund(unsigned int sessionID, int error, char last, const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRspQryFund, sessionID, error, last, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRtnFund(const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRtnFund, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspQryExchange(unsigned int sessionID, int error, char last, const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRspQryExchange, sessionID, error, last, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspQryCommodity(unsigned int sessionID, int error, char last, const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRspQryCommodity, sessionID, error, last, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspQryContract(unsigned int sessionID, int error, char last, const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRspQryContract, sessionID, error, last, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRtnContract(const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRtnContract, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRtnOrder(const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRtnOrder, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspOrderAction(unsigned int sessionID, unsigned int errorCode, const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRspOrderAction, sessionID, errorCode, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspQryOrder(unsigned int sessionID, int error, char last, const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRspQryOrder, sessionID, error, last, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspQryOrderProcess(unsigned int sessionID, int error, char last, const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRspQryOrderProcess, sessionID, error, last, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspQryFill(unsigned int sessionID, int error, char last, const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRspQryFill, sessionID, error, last, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRtnFill(const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRtnFill, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspQryPosition(unsigned int sessionID, int error, char last, const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRspQryPosition, sessionID, error, last, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRtnPosition(const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRtnPosition, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspQryClose(unsigned int sessionID, int error, char last, const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRspQryClose, sessionID, error, last, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRtnClose(const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRtnClose, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRtnPositionProfit(const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRtnPositionProfit, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspQryDeepQuote(unsigned int sessionID, int error, char last, const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRspQryDeepQuote, sessionID, error, last, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspQryExchangeStateInfo(unsigned int sessionID, int error, char last, const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRspQryExchangeStateInfo, sessionID, error, last, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRtnExchangeStateInfo(const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRtnExchangeStateInfo, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRtnReqQuoteNotice(const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRtnReqQuoteNotice, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspUpperChannelInfo(unsigned int sessionID, int error, char last, const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRspUpperChannelInfo, sessionID, error, last, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspAccountRentInfo(unsigned int sessionID, int error, char last, const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRspAccountRentInfo, sessionID, error, last, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspSubmitUserLoginInfo(unsigned int sessionID, int error, char last, const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRspSubmitUserLoginInfo, sessionID, error, last, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspQryBill(unsigned int sessionID, int error, char last, const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRspQryBill, sessionID, error, last, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspQryAccountStorage(unsigned int sessionID, int error, char last, const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRspQryAccountStorage, sessionID, error, last, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRtnAccountStorage(const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRtnAccountStorage, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

