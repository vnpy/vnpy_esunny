void TdApi::OnConnect()
{
	Task task = Task();
	task.task_name = ONCONNECT;
	this->task_queue.push(task);
};

void TdApi::OnRspLogin(int errorCode, const TapAPITradeLoginRspInfo *loginRspInfo)
{
	Task task = Task();
	task.task_name = ONRSPLOGIN;
	task.task_int = errorCode;
	if (loginRspInfo)
	{
		TapAPITradeLoginRspInfo *task_data = new TapAPITradeLoginRspInfo();
		*task_data = *loginRspInfo;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnAPIReady()
{
	Task task = Task();
	task.task_name = ONAPIREADY;
	this->task_queue.push(task);
};

void TdApi::OnDisconnect(int reasonCode)
{
	Task task = Task();
	task.task_name = ONDISCONNECT;
	task.task_int = reasonCode;
	this->task_queue.push(task);
};

void TdApi::OnRspChangePassword(unsigned int sessionID, int errorCode)
{
	Task task = Task();
	task.task_name = ONRSPCHANGEPASSWORD;
	task.task_id = sessionID;
	task.task_int = errorCode;
	this->task_queue.push(task);
};

void TdApi::OnRspSetReservedInfo(unsigned int sessionID, int errorCode, const TAPISTR_50 info)
{
	Task task = Task();
	task.task_name = ONRSPSETRESERVEDINFO;
	task.task_id = sessionID;
	task.task_int = errorCode;
	task.task_string = info;
	this->task_queue.push(task);
};

void TdApi::OnRspQryAccount(unsigned int sessionID, unsigned int errorCode, char isLast, const TapAPIAccountInfo *info)
{
	Task task = Task();
	task.task_name = ONRSPQRYACCOUNT;
	task.task_id = sessionID;
	task.task_error = errorCode;
	task.task_last = isLast;
	if (info)
	{
		TapAPIAccountInfo *task_data = new TapAPIAccountInfo();
		*task_data = *info;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspQryFund(unsigned int sessionID, int errorCode, char isLast, const TapAPIFundData *info)
{
	Task task = Task();
	task.task_name = ONRSPQRYFUND;
	task.task_id = sessionID;
	task.task_int = errorCode;
	task.task_last = isLast;
	if (info)
	{
		TapAPIFundData *task_data = new TapAPIFundData();
		*task_data = *info;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRtnFund(const TapAPIFundData *info)
{
	Task task = Task();
	task.task_name = ONRTNFUND;
	if (info)
	{
		TapAPIFundData *task_data = new TapAPIFundData();
		*task_data = *info;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspQryExchange(unsigned int sessionID, int errorCode, char isLast, const TapAPIExchangeInfo *info)
{
	Task task = Task();
	task.task_name = ONRSPQRYEXCHANGE;
	task.task_id = sessionID;
	task.task_int = errorCode;
	task.task_last = isLast;
	if (info)
	{
		TapAPIExchangeInfo *task_data = new TapAPIExchangeInfo();
		*task_data = *info;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspQryCommodity(unsigned int sessionID, int errorCode, char isLast, const TapAPICommodityInfo *info)
{
	Task task = Task();
	task.task_name = ONRSPQRYCOMMODITY;
	task.task_id = sessionID;
	task.task_int = errorCode;
	task.task_last = isLast;
	if (info)
	{
		TapAPICommodityInfo *task_data = new TapAPICommodityInfo();
		*task_data = *info;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspQryContract(unsigned int sessionID, int errorCode, char isLast, const TapAPITradeContractInfo *info)
{
	Task task = Task();
	task.task_name = ONRSPQRYCONTRACT;
	task.task_id = sessionID;
	task.task_int = errorCode;
	task.task_last = isLast;
	if (info)
	{
		TapAPITradeContractInfo *task_data = new TapAPITradeContractInfo();
		*task_data = *info;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRtnContract(const TapAPITradeContractInfo *info)
{
	Task task = Task();
	task.task_name = ONRTNCONTRACT;
	if (info)
	{
		TapAPITradeContractInfo *task_data = new TapAPITradeContractInfo();
		*task_data = *info;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRtnOrder(const TapAPIOrderInfoNotice *info)
{
	Task task = Task();
	task.task_name = ONRTNORDER;
	if (info)
	{
		TapAPIOrderInfoNotice *task_data = new TapAPIOrderInfoNotice();
		*task_data = *info;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspOrderAction(unsigned int sessionID, unsigned int errorCode, const TapAPIOrderActionRsp *info)
{
	Task task = Task();
	task.task_name = ONRSPORDERACTION;
	task.task_id = sessionID;
	task.task_error = errorCode;
	if (info)
	{
		TapAPIOrderActionRsp *task_data = new TapAPIOrderActionRsp();
		*task_data = *info;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspQryOrder(unsigned int sessionID, int errorCode, char isLast, const TapAPIOrderInfo *info)
{
	Task task = Task();
	task.task_name = ONRSPQRYORDER;
	task.task_id = sessionID;
	task.task_int = errorCode;
	task.task_last = isLast;
	if (info)
	{
		TapAPIOrderInfo *task_data = new TapAPIOrderInfo();
		*task_data = *info;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspQryOrderProcess(unsigned int sessionID, int errorCode, char isLast, const TapAPIOrderInfo *info)
{
	Task task = Task();
	task.task_name = ONRSPQRYORDERPROCESS;
	task.task_id = sessionID;
	task.task_int = errorCode;
	task.task_last = isLast;
	if (info)
	{
		TapAPIOrderInfo *task_data = new TapAPIOrderInfo();
		*task_data = *info;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspQryFill(unsigned int sessionID, int errorCode, char isLast, const TapAPIFillInfo *info)
{
	Task task = Task();
	task.task_name = ONRSPQRYFILL;
	task.task_id = sessionID;
	task.task_int = errorCode;
	task.task_last = isLast;
	if (info)
	{
		TapAPIFillInfo *task_data = new TapAPIFillInfo();
		*task_data = *info;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRtnFill(const TapAPIFillInfo *info)
{
	Task task = Task();
	task.task_name = ONRTNFILL;
	if (info)
	{
		TapAPIFillInfo *task_data = new TapAPIFillInfo();
		*task_data = *info;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspQryPosition(unsigned int sessionID, int errorCode, char isLast, const TapAPIPositionInfo *info)
{
	Task task = Task();
	task.task_name = ONRSPQRYPOSITION;
	task.task_id = sessionID;
	task.task_int = errorCode;
	task.task_last = isLast;
	if (info)
	{
		TapAPIPositionInfo *task_data = new TapAPIPositionInfo();
		*task_data = *info;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRtnPosition(const TapAPIPositionInfo *info)
{
	Task task = Task();
	task.task_name = ONRTNPOSITION;
	if (info)
	{
		TapAPIPositionInfo *task_data = new TapAPIPositionInfo();
		*task_data = *info;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspQryClose(unsigned int sessionID, int errorCode, char isLast, const TapAPICloseInfo *info)
{
	Task task = Task();
	task.task_name = ONRSPQRYCLOSE;
	task.task_id = sessionID;
	task.task_int = errorCode;
	task.task_last = isLast;
	if (info)
	{
		TapAPICloseInfo *task_data = new TapAPICloseInfo();
		*task_data = *info;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRtnClose(const TapAPICloseInfo *info)
{
	Task task = Task();
	task.task_name = ONRTNCLOSE;
	if (info)
	{
		TapAPICloseInfo *task_data = new TapAPICloseInfo();
		*task_data = *info;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRtnPositionProfit(const TapAPIPositionProfitNotice *info)
{
	Task task = Task();
	task.task_name = ONRTNPOSITIONPROFIT;
	if (info)
	{
		TapAPIPositionProfitNotice *task_data = new TapAPIPositionProfitNotice();
		*task_data = *info;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspQryDeepQuote(unsigned int sessionID, int errorCode, char isLast, const TapAPIDeepQuoteQryRsp *info)
{
	Task task = Task();
	task.task_name = ONRSPQRYDEEPQUOTE;
	task.task_id = sessionID;
	task.task_int = errorCode;
	task.task_last = isLast;
	if (info)
	{
		TapAPIDeepQuoteQryRsp *task_data = new TapAPIDeepQuoteQryRsp();
		*task_data = *info;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspQryExchangeStateInfo(unsigned int sessionID, int errorCode, char isLast, const TapAPIExchangeStateInfo *info)
{
	Task task = Task();
	task.task_name = ONRSPQRYEXCHANGESTATEINFO;
	task.task_id = sessionID;
	task.task_int = errorCode;
	task.task_last = isLast;
	if (info)
	{
		TapAPIExchangeStateInfo *task_data = new TapAPIExchangeStateInfo();
		*task_data = *info;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRtnExchangeStateInfo(const TapAPIExchangeStateInfoNotice *info)
{
	Task task = Task();
	task.task_name = ONRTNEXCHANGESTATEINFO;
	if (info)
	{
		TapAPIExchangeStateInfoNotice *task_data = new TapAPIExchangeStateInfoNotice();
		*task_data = *info;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRtnReqQuoteNotice(const TapAPIReqQuoteNotice *info)
{
	Task task = Task();
	task.task_name = ONRTNREQQUOTENOTICE;
	if (info)
	{
		TapAPIReqQuoteNotice *task_data = new TapAPIReqQuoteNotice();
		*task_data = *info;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspUpperChannelInfo(unsigned int sessionID, int errorCode, char isLast, const TapAPIUpperChannelInfo *info)
{
	Task task = Task();
	task.task_name = ONRSPUPPERCHANNELINFO;
	task.task_id = sessionID;
	task.task_int = errorCode;
	task.task_last = isLast;
	if (info)
	{
		TapAPIUpperChannelInfo *task_data = new TapAPIUpperChannelInfo();
		*task_data = *info;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspAccountRentInfo(unsigned int sessionID, int errorCode, char isLast, const TapAPIAccountRentInfo *info)
{
	Task task = Task();
	task.task_name = ONRSPACCOUNTRENTINFO;
	task.task_id = sessionID;
	task.task_int = errorCode;
	task.task_last = isLast;
	if (info)
	{
		TapAPIAccountRentInfo *task_data = new TapAPIAccountRentInfo();
		*task_data = *info;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspSubmitUserLoginInfo(unsigned int sessionID, int errorCode, char isLast, const TapAPISubmitUserLoginRspInfo *info)
{
	Task task = Task();
	task.task_name = ONRSPSUBMITUSERLOGININFO;
	task.task_id = sessionID;
	task.task_int = errorCode;
	task.task_last = isLast;
	if (info)
	{
		TapAPISubmitUserLoginRspInfo *task_data = new TapAPISubmitUserLoginRspInfo();
		*task_data = *info;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspQryBill(unsigned int sessionID, int errorCode, char isLast, const TapAPIBillQryRsp *info)
{
	Task task = Task();
	task.task_name = ONRSPQRYBILL;
	task.task_id = sessionID;
	task.task_int = errorCode;
	task.task_last = isLast;
	if (info)
	{
		TapAPIBillQryRsp *task_data = new TapAPIBillQryRsp();
		*task_data = *info;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

    void TdApi::OnRspQryAccountStorage(unsigned int sessionID, int errorCode, char isLast, const TapAPIAccountStorageInfo *info)
{
	Task task = Task();
	task.task_name = ONRSPQRYACCOUNTSTORAGE;
	task.task_id = sessionID;
	task.task_int = errorCode;
	task.task_last = isLast;
	if (info)
	{
		TapAPIAccountStorageInfo *task_data = new TapAPIAccountStorageInfo();
		*task_data = *info;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

    void TdApi::OnRtnAccountStorage(const TapAPIAccountStorageInfo *info)
{
	Task task = Task();
	task.task_name = ONRTNACCOUNTSTORAGE;
	if (info)
	{
		TapAPIAccountStorageInfo *task_data = new TapAPIAccountStorageInfo();
		*task_data = *info;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

