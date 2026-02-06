virtual void onRspLogin(int error, const dict &data) {};

virtual void onAPIReady() {};

virtual void onDisconnect(int reason) {};

virtual void onRspQryCommodity(unsigned int sessionID, int error, char last, const dict &data) {};

virtual void onRspQryContract(unsigned int sessionID, int error, char last, const dict &data) {};

virtual void onRspSubscribeQuote(unsigned int sessionID, int error, char last, const dict &data) {};

virtual void onRspUnSubscribeQuote(unsigned int sessionID, int error, char last, const dict &data) {};

virtual void onRtnQuote(const dict &data) {};

