int MdApi::qryCommodity(int sessionID)
{
	TAPIUINT32 session_id = static_cast<TAPIUINT32>(sessionID);
	int i = this->api->QryCommodity(&session_id);
	return i;
};

int MdApi::qryContract(int sessionID, const dict &req)
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

