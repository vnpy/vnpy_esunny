virtual void onConnect(string UserNo) {};

virtual void onRspLogin(string UserNo, int nErrorCode, const dict &data) {};

virtual void onRtnContactInfo(string UserNo, int nErrorCode, char last, const dict &data) {};

virtual void onRspRequestVertificateCode(string UserNo, unsigned int session, int nErrorCode, char last, const dict &data) {};

virtual void onRspRequestVerifyIdentity(string UserNo, unsigned int session, int nErrorCode, char last, const dict &data) {};

virtual void onRspSetVertificateCode(string UserNo, unsigned int session, int nErrorCode, char last, const dict &data) {};

virtual void onRtnErrorMsg(string UserNo, string ErrorMsg) {};

virtual void onAPIReady(string UserNo) {};

virtual void onDisconnect(string UserNo, int nReasonCode) {};

virtual void onRspSubmitUserLoginInfo(string UserNo, unsigned int session, const dict &data) {};

virtual void onRspChangePassword(string UserNo, unsigned int session, int nErrorCode, const dict &data) {};

virtual void onRspSetReservedInfo(string UserNo, unsigned int session, int nErrorCode, string info) {};

virtual void onRtnContract(string UserNo, const dict &data) {};

virtual void onRtnFund(string UserNo, const dict &data) {};

virtual void onRtnOrder(string UserNo, unsigned int session, const dict &data) {};

virtual void onRspOrderAction(string UserNo, unsigned int session, int nErrorCode, const dict &data) {};

virtual void onRspQryOrderProcess(string UserNo, unsigned int session, int nErrorCode, char last, const dict &data) {};

virtual void onRtnFill(string UserNo, const dict &data) {};

virtual void onRtnPosition(string UserNo, const dict &data) {};

virtual void onRtnClose(string UserNo, const dict &data) {};

virtual void onRtnPositionProfit(string UserNo, const dict &data) {};

virtual void onRspQryDeepQuote(string UserNo, unsigned int session, int nErrorCode, char last, const dict &data) {};

virtual void onRtnExchangeStateInfo(string UserNo, const dict &data) {};

virtual void onRtnReqQuoteNotice(string UserNo, const dict &data) {};

virtual void onRspAccountRentInfo(string UserNo, unsigned int session, int nErrorCode, char last, const dict &data) {};

virtual void onRspTradeMessage(string UserNo, unsigned int session, int nErrorCode, char last, const dict &data) {};

virtual void onRtnTradeMessage(string UserNo, const dict &data) {};

virtual void onRspQryHisOrder(string UserNo, unsigned int session, int nErrorCode, char last, const dict &data) {};

virtual void onRspQryHisOrderProcess(string UserNo, unsigned int session, int nErrorCode, char last, const dict &data) {};

virtual void onRspQryHisFill(string UserNo, unsigned int session, int nErrorCode, char last, const dict &data) {};

virtual void onRspQryHisPosition(string UserNo, unsigned int session, int nErrorCode, char last, const dict &data) {};

virtual void onRspQryHisDelivery(string UserNo, unsigned int session, int nErrorCode, char last, const dict &data) {};

virtual void onRspQryAccountCashAdjust(string UserNo, unsigned int session, int nErrorCode, char last, const dict &data) {};

virtual void onRspQryBill(string UserNo, unsigned int session, int nErrorCode, char last, const dict &data) {};

virtual void onRspAccountFeeRent(string UserNo, unsigned int session, int nErrorCode, char last, const dict &data) {};

virtual void onRspAccountMarginRent(string UserNo, unsigned int session, int nErrorCode, char last, const dict &data) {};

virtual void onRspAddMobileDevice(string UserNo, unsigned int session, int nErrorCode, char last, const dict &data) {};

virtual void onRspQryManageInfoForEStar(string UserNo, unsigned int session, int nErrorCode, char last, const dict &data) {};

virtual void onRspQrySystemParameter(string UserNo, unsigned int session, int nErrorCode, char last, const dict &data) {};

virtual void onRspQryTradeCenterFrontAddress(string UserNo, unsigned int session, int nErrorCode, char last, const dict &data) {};

virtual void onRtnCommodityInfo(string UserNo, const dict &data) {};

virtual void onRtnCurrencyInfo(string UserNo, const dict &data) {};

virtual void onRspQryAccountStorage(string UserNo, unsigned int session, int nErrorCode, char last, const dict &data) {};

virtual void onRtnAccountStorage(string UserNo, const dict &data) {};

virtual void onRspQrySpotLock(string UserNo, unsigned int session, int nErrorCode, char last, const dict &data) {};

virtual void onRtnSpotLock(string UserNo, const dict &data) {};

virtual void onRspSpecialOrderAction(string UserNo, unsigned int session, int nErrorCode, const dict &data) {};

virtual void onRtnSpecialOrder(string UserNo, unsigned int session, const dict &data) {};

virtual void onRtnCombinePosition(string UserNo, const dict &data) {};

virtual void onRtnContractQuote(string UserNo, const dict &data) {};

virtual void onRspQryTrustDevice(string UserNo, unsigned int session, int nErrorCode, char last, const dict &data) {};

virtual void onRspAddTrustDevice(string UserNo, unsigned int session, int nErrorCode, char last, const dict &data) {};

virtual void onRspDelTrustDevice(string UserNo, unsigned int session, int nErrorCode, char last, const dict &data) {};

virtual void onRtnAddUserRight(string UserNo, const dict &data) {};

virtual void onRtnDelUserRight(string UserNo, const dict &data) {};

virtual void onRspQryManagerConfigFile(string UserNo, unsigned int session, int nErrorCode, char last, const dict &data) {};

