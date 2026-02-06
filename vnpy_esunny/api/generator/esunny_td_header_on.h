virtual void onConnect() {};

virtual void onRspLogin(int error, const dict &data) {};

virtual void onAPIReady() {};

virtual void onDisconnect(int reason) {};

virtual void onRspChangePassword(unsigned int sessionID, int error) {};

virtual void onRspSetReservedInfo(unsigned int sessionID, int error, string info) {};

virtual void onRspQryAccount(unsigned int sessionID, unsigned int errorCode, char last, const dict &data) {};

virtual void onRspQryFund(unsigned int sessionID, int error, char last, const dict &data) {};

virtual void onRtnFund(const dict &data) {};

virtual void onRspQryExchange(unsigned int sessionID, int error, char last, const dict &data) {};

virtual void onRspQryCommodity(unsigned int sessionID, int error, char last, const dict &data) {};

virtual void onRspQryContract(unsigned int sessionID, int error, char last, const dict &data) {};

virtual void onRtnContract(const dict &data) {};

virtual void onRtnOrder(const dict &data) {};

virtual void onRspOrderAction(unsigned int sessionID, unsigned int errorCode, const dict &data) {};

virtual void onRspQryOrder(unsigned int sessionID, int error, char last, const dict &data) {};

virtual void onRspQryOrderProcess(unsigned int sessionID, int error, char last, const dict &data) {};

virtual void onRspQryFill(unsigned int sessionID, int error, char last, const dict &data) {};

virtual void onRtnFill(const dict &data) {};

virtual void onRspQryPosition(unsigned int sessionID, int error, char last, const dict &data) {};

virtual void onRtnPosition(const dict &data) {};

virtual void onRspQryClose(unsigned int sessionID, int error, char last, const dict &data) {};

virtual void onRtnClose(const dict &data) {};

virtual void onRtnPositionProfit(const dict &data) {};

virtual void onRspQryDeepQuote(unsigned int sessionID, int error, char last, const dict &data) {};

virtual void onRspQryExchangeStateInfo(unsigned int sessionID, int error, char last, const dict &data) {};

virtual void onRtnExchangeStateInfo(const dict &data) {};

virtual void onRtnReqQuoteNotice(const dict &data) {};

virtual void onRspUpperChannelInfo(unsigned int sessionID, int error, char last, const dict &data) {};

virtual void onRspAccountRentInfo(unsigned int sessionID, int error, char last, const dict &data) {};

virtual void onRspSubmitUserLoginInfo(unsigned int sessionID, int error, char last, const dict &data) {};

virtual void onRspQryBill(unsigned int sessionID, int error, char last, const dict &data) {};

virtual void onRspQryAccountStorage(unsigned int sessionID, int error, char last, const dict &data) {};

virtual void onRtnAccountStorage(const dict &data) {};

