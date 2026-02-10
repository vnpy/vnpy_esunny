
// vnesunnytd.cpp : 定义 DLL 应用程序的导出函数。
//

#include "vnesunnytd.h"

///-------------------------------------------------------------------------------------
///C++的回调函数将数据保存到队列中
///-------------------------------------------------------------------------------------

void TdApi::OnConnect()
{
	Task task = Task();
	task.task_name = ONCONNECT;
	this->task_queue.push(task);
};

void TdApi::OnRspLogin(int errorCode, const TapAPITradeLoginRspInfo* loginRspInfo)
{
	Task task = Task();
	task.task_name = ONRSPLOGIN;
	task.task_int = errorCode;
	if (loginRspInfo)
	{
		TapAPITradeLoginRspInfo* task_data = new TapAPITradeLoginRspInfo();
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

void TdApi::OnRspQryAccount(unsigned int sessionID, unsigned int errorCode, char isLast, const TapAPIAccountInfo* info)
{
	Task task = Task();
	task.task_name = ONRSPQRYACCOUNT;
	task.task_id = sessionID;
	task.task_error = errorCode;
	task.task_last = isLast;
	if (info)
	{
		TapAPIAccountInfo* task_data = new TapAPIAccountInfo();
		*task_data = *info;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspQryFund(unsigned int sessionID, int errorCode, char isLast, const TapAPIFundData* info)
{
	Task task = Task();
	task.task_name = ONRSPQRYFUND;
	task.task_id = sessionID;
	task.task_int = errorCode;
	task.task_last = isLast;
	if (info)
	{
		TapAPIFundData* task_data = new TapAPIFundData();
		*task_data = *info;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRtnFund(const TapAPIFundData* info)
{
	Task task = Task();
	task.task_name = ONRTNFUND;
	if (info)
	{
		TapAPIFundData* task_data = new TapAPIFundData();
		*task_data = *info;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspQryExchange(unsigned int sessionID, int errorCode, char isLast, const TapAPIExchangeInfo* info)
{
	Task task = Task();
	task.task_name = ONRSPQRYEXCHANGE;
	task.task_id = sessionID;
	task.task_int = errorCode;
	task.task_last = isLast;
	if (info)
	{
		TapAPIExchangeInfo* task_data = new TapAPIExchangeInfo();
		*task_data = *info;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspQryCommodity(unsigned int sessionID, int errorCode, char isLast, const TapAPICommodityInfo* info)
{
	Task task = Task();
	task.task_name = ONRSPQRYCOMMODITY;
	task.task_id = sessionID;
	task.task_int = errorCode;
	task.task_last = isLast;
	if (info)
	{
		TapAPICommodityInfo* task_data = new TapAPICommodityInfo();
		*task_data = *info;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspQryContract(unsigned int sessionID, int errorCode, char isLast, const TapAPITradeContractInfo* info)
{
	Task task = Task();
	task.task_name = ONRSPQRYCONTRACT;
	task.task_id = sessionID;
	task.task_int = errorCode;
	task.task_last = isLast;
	if (info)
	{
		TapAPITradeContractInfo* task_data = new TapAPITradeContractInfo();
		*task_data = *info;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRtnContract(const TapAPITradeContractInfo* info)
{
	Task task = Task();
	task.task_name = ONRTNCONTRACT;
	if (info)
	{
		TapAPITradeContractInfo* task_data = new TapAPITradeContractInfo();
		*task_data = *info;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRtnOrder(const TapAPIOrderInfoNotice* info)
{
	Task task = Task();
	task.task_name = ONRTNORDER;
	if (info)
	{
		TapAPIOrderInfoNotice* task_data = new TapAPIOrderInfoNotice();
		*task_data = *info;
		if (info->OrderInfo)
		{
			task_data->OrderInfo = new TapAPIOrderInfo();
			*task_data->OrderInfo = *info->OrderInfo;
		}
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspOrderAction(unsigned int sessionID, unsigned int errorCode, const TapAPIOrderActionRsp* info)
{
	Task task = Task();
	task.task_name = ONRSPORDERACTION;
	task.task_id = sessionID;
	task.task_error = errorCode;
	if (info)
	{
		TapAPIOrderActionRsp* task_data = new TapAPIOrderActionRsp();
		*task_data = *info;
		if (info->OrderInfo)
		{
			task_data->OrderInfo = new TapAPIOrderInfo();
			*task_data->OrderInfo = *info->OrderInfo;
		}
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspQryOrder(unsigned int sessionID, int errorCode, char isLast, const TapAPIOrderInfo* info)
{
	Task task = Task();
	task.task_name = ONRSPQRYORDER;
	task.task_id = sessionID;
	task.task_int = errorCode;
	task.task_last = isLast;
	if (info)
	{
		TapAPIOrderInfo* task_data = new TapAPIOrderInfo();
		*task_data = *info;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspQryOrderProcess(unsigned int sessionID, int errorCode, char isLast, const TapAPIOrderInfo* info)
{
	Task task = Task();
	task.task_name = ONRSPQRYORDERPROCESS;
	task.task_id = sessionID;
	task.task_int = errorCode;
	task.task_last = isLast;
	if (info)
	{
		TapAPIOrderInfo* task_data = new TapAPIOrderInfo();
		*task_data = *info;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspQryFill(unsigned int sessionID, int errorCode, char isLast, const TapAPIFillInfo* info)
{
	Task task = Task();
	task.task_name = ONRSPQRYFILL;
	task.task_id = sessionID;
	task.task_int = errorCode;
	task.task_last = isLast;
	if (info)
	{
		TapAPIFillInfo* task_data = new TapAPIFillInfo();
		*task_data = *info;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRtnFill(const TapAPIFillInfo* info)
{
	Task task = Task();
	task.task_name = ONRTNFILL;
	if (info)
	{
		TapAPIFillInfo* task_data = new TapAPIFillInfo();
		*task_data = *info;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspQryPosition(unsigned int sessionID, int errorCode, char isLast, const TapAPIPositionInfo* info)
{
	Task task = Task();
	task.task_name = ONRSPQRYPOSITION;
	task.task_id = sessionID;
	task.task_int = errorCode;
	task.task_last = isLast;
	if (info)
	{
		TapAPIPositionInfo* task_data = new TapAPIPositionInfo();
		*task_data = *info;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRtnPosition(const TapAPIPositionInfo* info)
{
	Task task = Task();
	task.task_name = ONRTNPOSITION;
	if (info)
	{
		TapAPIPositionInfo* task_data = new TapAPIPositionInfo();
		*task_data = *info;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspQryClose(unsigned int sessionID, int errorCode, char isLast, const TapAPICloseInfo* info)
{
	Task task = Task();
	task.task_name = ONRSPQRYCLOSE;
	task.task_id = sessionID;
	task.task_int = errorCode;
	task.task_last = isLast;
	if (info)
	{
		TapAPICloseInfo* task_data = new TapAPICloseInfo();
		*task_data = *info;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRtnClose(const TapAPICloseInfo* info)
{
	Task task = Task();
	task.task_name = ONRTNCLOSE;
	if (info)
	{
		TapAPICloseInfo* task_data = new TapAPICloseInfo();
		*task_data = *info;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRtnPositionProfit(const TapAPIPositionProfitNotice* info)
{
	Task task = Task();
	task.task_name = ONRTNPOSITIONPROFIT;
	if (info)
	{
		TapAPIPositionProfitNotice* task_data = new TapAPIPositionProfitNotice();
		*task_data = *info;
		if (info->Data)
		{
			task_data->Data = new TapAPIPositionProfit();
			*task_data->Data = *info->Data;
		}
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspQryDeepQuote(unsigned int sessionID, int errorCode, char isLast, const TapAPIDeepQuoteQryRsp* info)
{
	Task task = Task();
	task.task_name = ONRSPQRYDEEPQUOTE;
	task.task_id = sessionID;
	task.task_int = errorCode;
	task.task_last = isLast;
	if (info)
	{
		TapAPIDeepQuoteQryRsp* task_data = new TapAPIDeepQuoteQryRsp();
		*task_data = *info;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspQryExchangeStateInfo(unsigned int sessionID, int errorCode, char isLast, const TapAPIExchangeStateInfo* info)
{
	Task task = Task();
	task.task_name = ONRSPQRYEXCHANGESTATEINFO;
	task.task_id = sessionID;
	task.task_int = errorCode;
	task.task_last = isLast;
	if (info)
	{
		TapAPIExchangeStateInfo* task_data = new TapAPIExchangeStateInfo();
		*task_data = *info;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRtnExchangeStateInfo(const TapAPIExchangeStateInfoNotice* info)
{
	Task task = Task();
	task.task_name = ONRTNEXCHANGESTATEINFO;
	if (info)
	{
		TapAPIExchangeStateInfoNotice* task_data = new TapAPIExchangeStateInfoNotice();
		*task_data = *info;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRtnReqQuoteNotice(const TapAPIReqQuoteNotice* info)
{
	Task task = Task();
	task.task_name = ONRTNREQQUOTENOTICE;
	if (info)
	{
		TapAPIReqQuoteNotice* task_data = new TapAPIReqQuoteNotice();
		*task_data = *info;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspUpperChannelInfo(unsigned int sessionID, int errorCode, char isLast, const TapAPIUpperChannelInfo* info)
{
	Task task = Task();
	task.task_name = ONRSPUPPERCHANNELINFO;
	task.task_id = sessionID;
	task.task_int = errorCode;
	task.task_last = isLast;
	if (info)
	{
		TapAPIUpperChannelInfo* task_data = new TapAPIUpperChannelInfo();
		*task_data = *info;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspAccountRentInfo(unsigned int sessionID, int errorCode, char isLast, const TapAPIAccountRentInfo* info)
{
	Task task = Task();
	task.task_name = ONRSPACCOUNTRENTINFO;
	task.task_id = sessionID;
	task.task_int = errorCode;
	task.task_last = isLast;
	if (info)
	{
		TapAPIAccountRentInfo* task_data = new TapAPIAccountRentInfo();
		*task_data = *info;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspSubmitUserLoginInfo(unsigned int sessionID, int errorCode, char isLast, const TapAPISubmitUserLoginRspInfo* info)
{
	Task task = Task();
	task.task_name = ONRSPSUBMITUSERLOGININFO;
	task.task_id = sessionID;
	task.task_int = errorCode;
	task.task_last = isLast;
	if (info)
	{
		TapAPISubmitUserLoginRspInfo* task_data = new TapAPISubmitUserLoginRspInfo();
		*task_data = *info;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspQryBill(unsigned int sessionID, int errorCode, char isLast, const TapAPIBillQryRsp* info)
{
	Task task = Task();
	task.task_name = ONRSPQRYBILL;
	task.task_id = sessionID;
	task.task_int = errorCode;
	task.task_last = isLast;
	if (info)
	{
		TapAPIBillQryRsp* task_data = new TapAPIBillQryRsp();
		*task_data = *info;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspQryAccountStorage(unsigned int sessionID, int errorCode, char isLast, const TapAPIAccountStorageInfo* info)
{
	Task task = Task();
	task.task_name = ONRSPQRYACCOUNTSTORAGE;
	task.task_id = sessionID;
	task.task_int = errorCode;
	task.task_last = isLast;
	if (info)
	{
		TapAPIAccountStorageInfo* task_data = new TapAPIAccountStorageInfo();
		*task_data = *info;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRtnAccountStorage(const TapAPIAccountStorageInfo* info)
{
	Task task = Task();
	task.task_name = ONRTNACCOUNTSTORAGE;
	if (info)
	{
		TapAPIAccountStorageInfo* task_data = new TapAPIAccountStorageInfo();
		*task_data = *info;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

///-------------------------------------------------------------------------------------
///工作线程从队列中取出数据，转化为python对象后，进行推送
///-------------------------------------------------------------------------------------

void TdApi::processTask()
{
	try
	{
		while (this->active)
		{
			Task task = this->task_queue.pop();

			switch (task.task_name)
			{
			case ONCONNECT:
			{
				this->processConnect(&task);
				break;
			}

			case ONRSPLOGIN:
			{
				this->processRspLogin(&task);
				break;
			}

			case ONAPIREADY:
			{
				this->processAPIReady(&task);
				break;
			}

			case ONDISCONNECT:
			{
				this->processDisconnect(&task);
				break;
			}

			case ONRSPCHANGEPASSWORD:
			{
				this->processRspChangePassword(&task);
				break;
			}

			case ONRSPSETRESERVEDINFO:
			{
				this->processRspSetReservedInfo(&task);
				break;
			}

			case ONRSPQRYACCOUNT:
			{
				this->processRspQryAccount(&task);
				break;
			}

			case ONRSPQRYFUND:
			{
				this->processRspQryFund(&task);
				break;
			}

			case ONRTNFUND:
			{
				this->processRtnFund(&task);
				break;
			}

			case ONRSPQRYEXCHANGE:
			{
				this->processRspQryExchange(&task);
				break;
			}

			case ONRSPQRYCOMMODITY:
			{
				this->processRspQryCommodity(&task);
				break;
			}

			case ONRSPQRYCONTRACT:
			{
				this->processRspQryContract(&task);
				break;
			}

			case ONRTNCONTRACT:
			{
				this->processRtnContract(&task);
				break;
			}

			case ONRTNORDER:
			{
				this->processRtnOrder(&task);
				break;
			}

			case ONRSPORDERACTION:
			{
				this->processRspOrderAction(&task);
				break;
			}

			case ONRSPQRYORDER:
			{
				this->processRspQryOrder(&task);
				break;
			}

			case ONRSPQRYORDERPROCESS:
			{
				this->processRspQryOrderProcess(&task);
				break;
			}

			case ONRSPQRYFILL:
			{
				this->processRspQryFill(&task);
				break;
			}

			case ONRTNFILL:
			{
				this->processRtnFill(&task);
				break;
			}

			case ONRSPQRYPOSITION:
			{
				this->processRspQryPosition(&task);
				break;
			}

			case ONRTNPOSITION:
			{
				this->processRtnPosition(&task);
				break;
			}

			case ONRSPQRYCLOSE:
			{
				this->processRspQryClose(&task);
				break;
			}

			case ONRTNCLOSE:
			{
				this->processRtnClose(&task);
				break;
			}

			case ONRTNPOSITIONPROFIT:
			{
				this->processRtnPositionProfit(&task);
				break;
			}

			case ONRSPQRYDEEPQUOTE:
			{
				this->processRspQryDeepQuote(&task);
				break;
			}

			case ONRSPQRYEXCHANGESTATEINFO:
			{
				this->processRspQryExchangeStateInfo(&task);
				break;
			}

			case ONRTNEXCHANGESTATEINFO:
			{
				this->processRtnExchangeStateInfo(&task);
				break;
			}

			case ONRTNREQQUOTENOTICE:
			{
				this->processRtnReqQuoteNotice(&task);
				break;
			}

			case ONRSPUPPERCHANNELINFO:
			{
				this->processRspUpperChannelInfo(&task);
				break;
			}

			case ONRSPACCOUNTRENTINFO:
			{
				this->processRspAccountRentInfo(&task);
				break;
			}

			case ONRSPSUBMITUSERLOGININFO:
			{
				this->processRspSubmitUserLoginInfo(&task);
				break;
			}

			case ONRSPQRYBILL:
			{
				this->processRspQryBill(&task);
				break;
			}

			case ONRSPQRYACCOUNTSTORAGE:
			{
				this->processRspQryAccountStorage(&task);
				break;
			}

			case ONRTNACCOUNTSTORAGE:
			{
				this->processRtnAccountStorage(&task);
				break;
			}
			};
		}
	}
	catch (const TerminatedError&)
	{
	}
};

void TdApi::processConnect(Task* task)
{
	this->onConnect();
};

void TdApi::processRspLogin(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		TapAPITradeLoginRspInfo* task_data = (TapAPITradeLoginRspInfo*)task->task_data;
		data["UserNo"] = toUtf(task_data->UserNo);
		data["UserType"] = task_data->UserType;
		data["UserName"] = toUtf(task_data->UserName);
		data["QuoteTempPassword"] = toUtf(task_data->QuoteTempPassword);
		data["ReservedInfo"] = toUtf(task_data->ReservedInfo);
		data["LastLoginIP"] = toUtf(task_data->LastLoginIP);
		data["LastLoginPort"] = task_data->LastLoginPort;
		data["LastLoginInfo"] = toUtf(task_data->LastLoginInfo);
		data["LastLoginTime"] = toUtf(task_data->LastLoginTime);
		data["LastLogoutTime"] = toUtf(task_data->LastLogoutTime);
		data["TradeDate"] = toUtf(task_data->TradeDate);
		data["LastSettleTime"] = toUtf(task_data->LastSettleTime);
		data["StartTime"] = toUtf(task_data->StartTime);
		data["InitTime"] = toUtf(task_data->InitTime);
		data["AuthType"] = task_data->AuthType;
		data["AuthDate"] = toUtf(task_data->AuthDate);
		data["UdpCertCode"] = task_data->UdpCertCode;
		delete task_data;
	}
	this->onRspLogin(task->task_int, data);
};

void TdApi::processAPIReady(Task* task)
{
	this->onAPIReady();
};

void TdApi::processDisconnect(Task* task)
{
	gil_scoped_acquire acquire;
	this->onDisconnect(task->task_int);
};

void TdApi::processRspChangePassword(Task* task)
{
	gil_scoped_acquire acquire;
	this->onRspChangePassword(task->task_id, task->task_int);
};

void TdApi::processRspSetReservedInfo(Task* task)
{
	gil_scoped_acquire acquire;
	this->onRspSetReservedInfo(task->task_id, task->task_int, task->task_string);
};

void TdApi::processRspQryAccount(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		TapAPIAccountInfo* task_data = (TapAPIAccountInfo*)task->task_data;
		data["AccountNo"] = toUtf(task_data->AccountNo);
		data["AccountType"] = task_data->AccountType;
		data["AccountState"] = task_data->AccountState;
		data["AccountShortName"] = toUtf(task_data->AccountShortName);
		data["AccountIsDocHolder"] = task_data->AccountIsDocHolder;
		data["IsMarketMaker"] = task_data->IsMarketMaker;
		data["AccountFamilyType"] = task_data->AccountFamilyType;
		delete task_data;
	}
	this->onRspQryAccount(task->task_id, task->task_error, task->task_last, data);
};

void TdApi::processRspQryFund(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		TapAPIFundData* task_data = (TapAPIFundData*)task->task_data;
		data["AccountNo"] = toUtf(task_data->AccountNo);
		data["ParentAccountNo"] = toUtf(task_data->ParentAccountNo);
		data["CurrencyGroupNo"] = toUtf(task_data->CurrencyGroupNo);
		data["CurrencyNo"] = toUtf(task_data->CurrencyNo);
		data["TradeRate"] = task_data->TradeRate;
		data["FutureAlg"] = task_data->FutureAlg;
		data["OptionAlg"] = task_data->OptionAlg;
		data["PreBalance"] = task_data->PreBalance;
		data["PreUnExpProfit"] = task_data->PreUnExpProfit;
		data["PreLMEPositionProfit"] = task_data->PreLMEPositionProfit;
		data["PreEquity"] = task_data->PreEquity;
		data["PreAvailable1"] = task_data->PreAvailable1;
		data["PreMarketEquity"] = task_data->PreMarketEquity;
		data["CashInValue"] = task_data->CashInValue;
		data["CashOutValue"] = task_data->CashOutValue;
		data["CashAdjustValue"] = task_data->CashAdjustValue;
		data["CashPledged"] = task_data->CashPledged;
		data["FrozenFee"] = task_data->FrozenFee;
		data["FrozenDeposit"] = task_data->FrozenDeposit;
		data["AccountFee"] = task_data->AccountFee;
		data["ExchangeFee"] = task_data->ExchangeFee;
		data["AccountDeliveryFee"] = task_data->AccountDeliveryFee;
		data["PremiumIncome"] = task_data->PremiumIncome;
		data["PremiumPay"] = task_data->PremiumPay;
		data["CloseProfit"] = task_data->CloseProfit;
		data["DeliveryProfit"] = task_data->DeliveryProfit;
		data["UnExpProfit"] = task_data->UnExpProfit;
		data["ExpProfit"] = task_data->ExpProfit;
		data["PositionProfit"] = task_data->PositionProfit;
		data["LmePositionProfit"] = task_data->LmePositionProfit;
		data["OptionMarketValue"] = task_data->OptionMarketValue;
		data["AccountIntialMargin"] = task_data->AccountIntialMargin;
		data["AccountMaintenanceMargin"] = task_data->AccountMaintenanceMargin;
		data["UpperInitalMargin"] = task_data->UpperInitalMargin;
		data["UpperMaintenanceMargin"] = task_data->UpperMaintenanceMargin;
		data["Discount"] = task_data->Discount;
		data["Balance"] = task_data->Balance;
		data["Equity"] = task_data->Equity;
		data["Available"] = task_data->Available;
		data["CanDraw"] = task_data->CanDraw;
		data["MarketEquity"] = task_data->MarketEquity;
		data["OriginalCashInOut"] = task_data->OriginalCashInOut;
		data["FloatingPL"] = task_data->FloatingPL;
		data["FrozenRiskFundValue"] = task_data->FrozenRiskFundValue;
		data["ClosePL"] = task_data->ClosePL;
		data["NoCurrencyPledgeValue"] = task_data->NoCurrencyPledgeValue;
		data["PrePledgeValue"] = task_data->PrePledgeValue;
		data["PledgeIn"] = task_data->PledgeIn;
		data["PledgeOut"] = task_data->PledgeOut;
		data["PledgeValue"] = task_data->PledgeValue;
		data["BorrowValue"] = task_data->BorrowValue;
		data["SpecialAccountFrozenMargin"] = task_data->SpecialAccountFrozenMargin;
		data["SpecialAccountMargin"] = task_data->SpecialAccountMargin;
		data["SpecialAccountFrozenFee"] = task_data->SpecialAccountFrozenFee;
		data["SpecialAccountFee"] = task_data->SpecialAccountFee;
		data["SpecialFloatProfit"] = task_data->SpecialFloatProfit;
		data["SpecialCloseProfit"] = task_data->SpecialCloseProfit;
		data["SpecialFloatPL"] = task_data->SpecialFloatPL;
		data["SpecialClosePL"] = task_data->SpecialClosePL;
		delete task_data;
	}
	this->onRspQryFund(task->task_id, task->task_int, task->task_last, data);
};

void TdApi::processRtnFund(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		TapAPIFundData* task_data = (TapAPIFundData*)task->task_data;
		data["AccountNo"] = toUtf(task_data->AccountNo);
		data["ParentAccountNo"] = toUtf(task_data->ParentAccountNo);
		data["CurrencyGroupNo"] = toUtf(task_data->CurrencyGroupNo);
		data["CurrencyNo"] = toUtf(task_data->CurrencyNo);
		data["TradeRate"] = task_data->TradeRate;
		data["FutureAlg"] = task_data->FutureAlg;
		data["OptionAlg"] = task_data->OptionAlg;
		data["PreBalance"] = task_data->PreBalance;
		data["PreUnExpProfit"] = task_data->PreUnExpProfit;
		data["PreLMEPositionProfit"] = task_data->PreLMEPositionProfit;
		data["PreEquity"] = task_data->PreEquity;
		data["PreAvailable1"] = task_data->PreAvailable1;
		data["PreMarketEquity"] = task_data->PreMarketEquity;
		data["CashInValue"] = task_data->CashInValue;
		data["CashOutValue"] = task_data->CashOutValue;
		data["CashAdjustValue"] = task_data->CashAdjustValue;
		data["CashPledged"] = task_data->CashPledged;
		data["FrozenFee"] = task_data->FrozenFee;
		data["FrozenDeposit"] = task_data->FrozenDeposit;
		data["AccountFee"] = task_data->AccountFee;
		data["ExchangeFee"] = task_data->ExchangeFee;
		data["AccountDeliveryFee"] = task_data->AccountDeliveryFee;
		data["PremiumIncome"] = task_data->PremiumIncome;
		data["PremiumPay"] = task_data->PremiumPay;
		data["CloseProfit"] = task_data->CloseProfit;
		data["DeliveryProfit"] = task_data->DeliveryProfit;
		data["UnExpProfit"] = task_data->UnExpProfit;
		data["ExpProfit"] = task_data->ExpProfit;
		data["PositionProfit"] = task_data->PositionProfit;
		data["LmePositionProfit"] = task_data->LmePositionProfit;
		data["OptionMarketValue"] = task_data->OptionMarketValue;
		data["AccountIntialMargin"] = task_data->AccountIntialMargin;
		data["AccountMaintenanceMargin"] = task_data->AccountMaintenanceMargin;
		data["UpperInitalMargin"] = task_data->UpperInitalMargin;
		data["UpperMaintenanceMargin"] = task_data->UpperMaintenanceMargin;
		data["Discount"] = task_data->Discount;
		data["Balance"] = task_data->Balance;
		data["Equity"] = task_data->Equity;
		data["Available"] = task_data->Available;
		data["CanDraw"] = task_data->CanDraw;
		data["MarketEquity"] = task_data->MarketEquity;
		data["OriginalCashInOut"] = task_data->OriginalCashInOut;
		data["FloatingPL"] = task_data->FloatingPL;
		data["FrozenRiskFundValue"] = task_data->FrozenRiskFundValue;
		data["ClosePL"] = task_data->ClosePL;
		data["NoCurrencyPledgeValue"] = task_data->NoCurrencyPledgeValue;
		data["PrePledgeValue"] = task_data->PrePledgeValue;
		data["PledgeIn"] = task_data->PledgeIn;
		data["PledgeOut"] = task_data->PledgeOut;
		data["PledgeValue"] = task_data->PledgeValue;
		data["BorrowValue"] = task_data->BorrowValue;
		data["SpecialAccountFrozenMargin"] = task_data->SpecialAccountFrozenMargin;
		data["SpecialAccountMargin"] = task_data->SpecialAccountMargin;
		data["SpecialAccountFrozenFee"] = task_data->SpecialAccountFrozenFee;
		data["SpecialAccountFee"] = task_data->SpecialAccountFee;
		data["SpecialFloatProfit"] = task_data->SpecialFloatProfit;
		data["SpecialCloseProfit"] = task_data->SpecialCloseProfit;
		data["SpecialFloatPL"] = task_data->SpecialFloatPL;
		data["SpecialClosePL"] = task_data->SpecialClosePL;
		delete task_data;
	}
	this->onRtnFund(data);
};

void TdApi::processRspQryExchange(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		TapAPIExchangeInfo* task_data = (TapAPIExchangeInfo*)task->task_data;
		data["ExchangeNo"] = toUtf(task_data->ExchangeNo);
		data["ExchangeName"] = toUtf(task_data->ExchangeName);
		delete task_data;
	}
	this->onRspQryExchange(task->task_id, task->task_int, task->task_last, data);
};

void TdApi::processRspQryCommodity(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		TapAPICommodityInfo* task_data = (TapAPICommodityInfo*)task->task_data;
		data["ExchangeNo"] = toUtf(task_data->ExchangeNo);
		data["CommodityType"] = task_data->CommodityType;
		data["CommodityNo"] = toUtf(task_data->CommodityNo);
		data["CommodityName"] = toUtf(task_data->CommodityName);
		data["CommodityEngName"] = toUtf(task_data->CommodityEngName);
		data["RelateExchangeNo"] = toUtf(task_data->RelateExchangeNo);
		data["RelateCommodityType"] = task_data->RelateCommodityType;
		data["RelateCommodityNo"] = toUtf(task_data->RelateCommodityNo);
		data["RelateExchangeNo2"] = toUtf(task_data->RelateExchangeNo2);
		data["RelateCommodityType2"] = task_data->RelateCommodityType2;
		data["RelateCommodityNo2"] = toUtf(task_data->RelateCommodityNo2);
		data["TradeCurrency"] = toUtf(task_data->TradeCurrency);
		data["SettleCurrency"] = toUtf(task_data->SettleCurrency);
		data["ContractSize"] = task_data->ContractSize;
		data["MarginCalculateMode"] = task_data->MarginCalculateMode;
		data["OptionMarginCalculateMode"] = task_data->OptionMarginCalculateMode;
		data["OpenCloseMode"] = task_data->OpenCloseMode;
		data["StrikePriceTimes"] = task_data->StrikePriceTimes;
		data["IsOnlyQuoteCommodity"] = task_data->IsOnlyQuoteCommodity;
		data["CommodityTickSize"] = task_data->CommodityTickSize;
		data["CommodityDenominator"] = task_data->CommodityDenominator;
		data["CmbDirect"] = task_data->CmbDirect;
		data["OnlyCanCloseDays"] = task_data->OnlyCanCloseDays;
		data["DeliveryMode"] = task_data->DeliveryMode;
		data["DeliveryDays"] = task_data->DeliveryDays;
		data["AddOneTime"] = toUtf(task_data->AddOneTime);
		data["CommodityTimeZone"] = task_data->CommodityTimeZone;
		delete task_data;
	}
	this->onRspQryCommodity(task->task_id, task->task_int, task->task_last, data);
};

void TdApi::processRspQryContract(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		TapAPITradeContractInfo* task_data = (TapAPITradeContractInfo*)task->task_data;
		data["ExchangeNo"] = toUtf(task_data->ExchangeNo);
		data["CommodityType"] = task_data->CommodityType;
		data["CommodityNo"] = toUtf(task_data->CommodityNo);
		data["ContractNo1"] = toUtf(task_data->ContractNo1);
		data["StrikePrice1"] = toUtf(task_data->StrikePrice1);
		data["CallOrPutFlag1"] = task_data->CallOrPutFlag1;
		data["ContractNo2"] = toUtf(task_data->ContractNo2);
		data["StrikePrice2"] = toUtf(task_data->StrikePrice2);
		data["CallOrPutFlag2"] = task_data->CallOrPutFlag2;
		data["ContractType"] = task_data->ContractType;
		data["QuoteUnderlyingContract"] = toUtf(task_data->QuoteUnderlyingContract);
		data["ContractName"] = toUtf(task_data->ContractName);
		data["ContractExpDate"] = toUtf(task_data->ContractExpDate);
		data["LastTradeDate"] = toUtf(task_data->LastTradeDate);
		data["FirstNoticeDate"] = toUtf(task_data->FirstNoticeDate);
		data["FutureContractNo"] = toUtf(task_data->FutureContractNo);
		delete task_data;
	}
	this->onRspQryContract(task->task_id, task->task_int, task->task_last, data);
};

void TdApi::processRtnContract(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		TapAPITradeContractInfo* task_data = (TapAPITradeContractInfo*)task->task_data;
		data["ExchangeNo"] = toUtf(task_data->ExchangeNo);
		data["CommodityType"] = task_data->CommodityType;
		data["CommodityNo"] = toUtf(task_data->CommodityNo);
		data["ContractNo1"] = toUtf(task_data->ContractNo1);
		data["StrikePrice1"] = toUtf(task_data->StrikePrice1);
		data["CallOrPutFlag1"] = task_data->CallOrPutFlag1;
		data["ContractNo2"] = toUtf(task_data->ContractNo2);
		data["StrikePrice2"] = toUtf(task_data->StrikePrice2);
		data["CallOrPutFlag2"] = task_data->CallOrPutFlag2;
		data["ContractType"] = task_data->ContractType;
		data["QuoteUnderlyingContract"] = toUtf(task_data->QuoteUnderlyingContract);
		data["ContractName"] = toUtf(task_data->ContractName);
		data["ContractExpDate"] = toUtf(task_data->ContractExpDate);
		data["LastTradeDate"] = toUtf(task_data->LastTradeDate);
		data["FirstNoticeDate"] = toUtf(task_data->FirstNoticeDate);
		data["FutureContractNo"] = toUtf(task_data->FutureContractNo);
		delete task_data;
	}
	this->onRtnContract(data);
};

void TdApi::processRtnOrder(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		TapAPIOrderInfoNotice* task_data = (TapAPIOrderInfoNotice*)task->task_data;
		data["SessionID"] = task_data->SessionID;
		data["ErrorCode"] = task_data->ErrorCode;
		data["AccountNo"] = toUtf(task_data->OrderInfo->AccountNo);
		data["ExchangeNo"] = toUtf(task_data->OrderInfo->ExchangeNo);
		data["CommodityType"] = task_data->OrderInfo->CommodityType;
		data["CommodityNo"] = toUtf(task_data->OrderInfo->CommodityNo);
		data["ContractNo"] = toUtf(task_data->OrderInfo->ContractNo);
		data["StrikePrice"] = toUtf(task_data->OrderInfo->StrikePrice);
		data["CallOrPutFlag"] = task_data->OrderInfo->CallOrPutFlag;
		data["ContractNo2"] = toUtf(task_data->OrderInfo->ContractNo2);
		data["StrikePrice2"] = toUtf(task_data->OrderInfo->StrikePrice2);
		data["CallOrPutFlag2"] = task_data->OrderInfo->CallOrPutFlag2;
		data["OrderType"] = task_data->OrderInfo->OrderType;
		data["OrderSource"] = task_data->OrderInfo->OrderSource;
		data["TimeInForce"] = task_data->OrderInfo->TimeInForce;
		data["ExpireTime"] = toUtf(task_data->OrderInfo->ExpireTime);
		data["IsRiskOrder"] = task_data->OrderInfo->IsRiskOrder;
		data["OrderSide"] = task_data->OrderInfo->OrderSide;
		data["PositionEffect"] = task_data->OrderInfo->PositionEffect;
		data["PositionEffect2"] = task_data->OrderInfo->PositionEffect2;
		data["InquiryNo"] = toUtf(task_data->OrderInfo->InquiryNo);
		data["HedgeFlag"] = task_data->OrderInfo->HedgeFlag;
		data["OrderPrice"] = task_data->OrderInfo->OrderPrice;
		data["OrderPrice2"] = task_data->OrderInfo->OrderPrice2;
		data["StopPrice"] = task_data->OrderInfo->StopPrice;
		data["OrderQty"] = task_data->OrderInfo->OrderQty;
		data["OrderMinQty"] = task_data->OrderInfo->OrderMinQty;
		data["OrderCanceledQty"] = task_data->OrderInfo->OrderCanceledQty;
		data["MinClipSize"] = task_data->OrderInfo->MinClipSize;
		data["MaxClipSize"] = task_data->OrderInfo->MaxClipSize;
		data["LicenseNo"] = toUtf(task_data->OrderInfo->LicenseNo);
		data["RefInt"] = task_data->OrderInfo->RefInt;
		data["RefString"] = toUtf(task_data->OrderInfo->RefString);
		data["ParentAccountNo"] = toUtf(task_data->OrderInfo->ParentAccountNo);
		data["ServerFlag"] = task_data->OrderInfo->ServerFlag;
		data["OrderNo"] = toUtf(task_data->OrderInfo->OrderNo);
		data["ClientOrderNo"] = toUtf(task_data->OrderInfo->ClientOrderNo);
		data["OrderLocalNo"] = toUtf(task_data->OrderInfo->OrderLocalNo);
		data["OrderSystemNo"] = toUtf(task_data->OrderInfo->OrderSystemNo);
		data["OrderExchangeSystemNo"] = toUtf(task_data->OrderInfo->OrderExchangeSystemNo);
		data["OrderParentNo"] = toUtf(task_data->OrderInfo->OrderParentNo);
		data["OrderParentSystemNo"] = toUtf(task_data->OrderInfo->OrderParentSystemNo);
		data["TradeNo"] = toUtf(task_data->OrderInfo->TradeNo);
		data["UpperNo"] = toUtf(task_data->OrderInfo->UpperNo);
		data["UpperChannelNo"] = toUtf(task_data->OrderInfo->UpperChannelNo);
		data["UpperSettleNo"] = toUtf(task_data->OrderInfo->UpperSettleNo);
		data["UpperUserNo"] = toUtf(task_data->OrderInfo->UpperUserNo);
		data["OrderInsertUserNo"] = toUtf(task_data->OrderInfo->OrderInsertUserNo);
		data["OrderInsertTime"] = toUtf(task_data->OrderInfo->OrderInsertTime);
		data["OrderCommandUserNo"] = toUtf(task_data->OrderInfo->OrderCommandUserNo);
		data["OrderUpdateUserNo"] = toUtf(task_data->OrderInfo->OrderUpdateUserNo);
		data["OrderUpdateTime"] = toUtf(task_data->OrderInfo->OrderUpdateTime);
		data["OrderState"] = task_data->OrderInfo->OrderState;
		data["OrderMatchPrice"] = task_data->OrderInfo->OrderMatchPrice;
		data["OrderMatchPrice2"] = task_data->OrderInfo->OrderMatchPrice2;
		data["OrderMatchQty"] = task_data->OrderInfo->OrderMatchQty;
		data["OrderMatchQty2"] = task_data->OrderInfo->OrderMatchQty2;
		data["ErrorCode"] = task_data->OrderInfo->ErrorCode;
		data["ErrorText"] = toUtf(task_data->OrderInfo->ErrorText);
		data["IsBackInput"] = task_data->OrderInfo->IsBackInput;
		data["IsDeleted"] = task_data->OrderInfo->IsDeleted;
		data["IsAddOne"] = task_data->OrderInfo->IsAddOne;
		data["OrderStreamID"] = task_data->OrderInfo->OrderStreamID;
		data["UpperStreamID"] = task_data->OrderInfo->UpperStreamID;
		data["ContractSize"] = task_data->OrderInfo->ContractSize;
		data["ContractSize2"] = task_data->OrderInfo->ContractSize2;
		data["CommodityCurrencyGroup"] = toUtf(task_data->OrderInfo->CommodityCurrencyGroup);
		data["CommodityCurrency"] = toUtf(task_data->OrderInfo->CommodityCurrency);
		data["FeeMode"] = task_data->OrderInfo->FeeMode;
		data["FeeParam"] = task_data->OrderInfo->FeeParam;
		data["FeeCurrencyGroup"] = toUtf(task_data->OrderInfo->FeeCurrencyGroup);
		data["FeeCurrency"] = toUtf(task_data->OrderInfo->FeeCurrency);
		data["FeeMode2"] = task_data->OrderInfo->FeeMode2;
		data["FeeParam2"] = task_data->OrderInfo->FeeParam2;
		data["FeeCurrencyGroup2"] = toUtf(task_data->OrderInfo->FeeCurrencyGroup2);
		data["FeeCurrency2"] = toUtf(task_data->OrderInfo->FeeCurrency2);
		data["MarginMode"] = task_data->OrderInfo->MarginMode;
		data["MarginParam"] = task_data->OrderInfo->MarginParam;
		data["MarginMode2"] = task_data->OrderInfo->MarginMode2;
		data["MarginParam2"] = task_data->OrderInfo->MarginParam2;
		data["PreSettlePrice"] = task_data->OrderInfo->PreSettlePrice;
		data["PreSettlePrice2"] = task_data->OrderInfo->PreSettlePrice2;
		data["OpenVol"] = task_data->OrderInfo->OpenVol;
		data["CoverVol"] = task_data->OrderInfo->CoverVol;
		data["OpenVol2"] = task_data->OrderInfo->OpenVol2;
		data["CoverVol2"] = task_data->OrderInfo->CoverVol2;
		data["FeeValue"] = task_data->OrderInfo->FeeValue;
		data["MarginValue"] = task_data->OrderInfo->MarginValue;
		data["TacticsType"] = task_data->OrderInfo->TacticsType;
		data["TriggerCondition"] = task_data->OrderInfo->TriggerCondition;
		data["TriggerPriceType"] = task_data->OrderInfo->TriggerPriceType;
		data["AddOneIsValid"] = task_data->OrderInfo->AddOneIsValid;
		data["OrderQty2"] = task_data->OrderInfo->OrderQty2;
		data["HedgeFlag2"] = task_data->OrderInfo->HedgeFlag2;
		data["MarketLevel"] = task_data->OrderInfo->MarketLevel;
		data["OrderDeleteByDisConnFlag"] = task_data->OrderInfo->OrderDeleteByDisConnFlag;
		if (task_data->OrderInfo) delete task_data->OrderInfo;
		delete task_data;
	}
	this->onRtnOrder(data);
};

void TdApi::processRspOrderAction(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		TapAPIOrderActionRsp* task_data = (TapAPIOrderActionRsp*)task->task_data;
		data["ActionType"] = task_data->ActionType;
		data["AccountNo"] = toUtf(task_data->OrderInfo->AccountNo);
		data["ExchangeNo"] = toUtf(task_data->OrderInfo->ExchangeNo);
		data["CommodityType"] = task_data->OrderInfo->CommodityType;
		data["CommodityNo"] = toUtf(task_data->OrderInfo->CommodityNo);
		data["ContractNo"] = toUtf(task_data->OrderInfo->ContractNo);
		data["StrikePrice"] = toUtf(task_data->OrderInfo->StrikePrice);
		data["CallOrPutFlag"] = task_data->OrderInfo->CallOrPutFlag;
		data["ContractNo2"] = toUtf(task_data->OrderInfo->ContractNo2);
		data["StrikePrice2"] = toUtf(task_data->OrderInfo->StrikePrice2);
		data["CallOrPutFlag2"] = task_data->OrderInfo->CallOrPutFlag2;
		data["OrderType"] = task_data->OrderInfo->OrderType;
		data["OrderSource"] = task_data->OrderInfo->OrderSource;
		data["TimeInForce"] = task_data->OrderInfo->TimeInForce;
		data["ExpireTime"] = toUtf(task_data->OrderInfo->ExpireTime);
		data["IsRiskOrder"] = task_data->OrderInfo->IsRiskOrder;
		data["OrderSide"] = task_data->OrderInfo->OrderSide;
		data["PositionEffect"] = task_data->OrderInfo->PositionEffect;
		data["PositionEffect2"] = task_data->OrderInfo->PositionEffect2;
		data["InquiryNo"] = toUtf(task_data->OrderInfo->InquiryNo);
		data["HedgeFlag"] = task_data->OrderInfo->HedgeFlag;
		data["OrderPrice"] = task_data->OrderInfo->OrderPrice;
		data["OrderPrice2"] = task_data->OrderInfo->OrderPrice2;
		data["StopPrice"] = task_data->OrderInfo->StopPrice;
		data["OrderQty"] = task_data->OrderInfo->OrderQty;
		data["OrderMinQty"] = task_data->OrderInfo->OrderMinQty;
		data["OrderCanceledQty"] = task_data->OrderInfo->OrderCanceledQty;
		data["MinClipSize"] = task_data->OrderInfo->MinClipSize;
		data["MaxClipSize"] = task_data->OrderInfo->MaxClipSize;
		data["LicenseNo"] = toUtf(task_data->OrderInfo->LicenseNo);
		data["RefInt"] = task_data->OrderInfo->RefInt;
		data["RefString"] = toUtf(task_data->OrderInfo->RefString);
		data["ParentAccountNo"] = toUtf(task_data->OrderInfo->ParentAccountNo);
		data["ServerFlag"] = task_data->OrderInfo->ServerFlag;
		data["OrderNo"] = toUtf(task_data->OrderInfo->OrderNo);
		data["ClientOrderNo"] = toUtf(task_data->OrderInfo->ClientOrderNo);
		data["OrderLocalNo"] = toUtf(task_data->OrderInfo->OrderLocalNo);
		data["OrderSystemNo"] = toUtf(task_data->OrderInfo->OrderSystemNo);
		data["OrderExchangeSystemNo"] = toUtf(task_data->OrderInfo->OrderExchangeSystemNo);
		data["OrderParentNo"] = toUtf(task_data->OrderInfo->OrderParentNo);
		data["OrderParentSystemNo"] = toUtf(task_data->OrderInfo->OrderParentSystemNo);
		data["TradeNo"] = toUtf(task_data->OrderInfo->TradeNo);
		data["UpperNo"] = toUtf(task_data->OrderInfo->UpperNo);
		data["UpperChannelNo"] = toUtf(task_data->OrderInfo->UpperChannelNo);
		data["UpperSettleNo"] = toUtf(task_data->OrderInfo->UpperSettleNo);
		data["UpperUserNo"] = toUtf(task_data->OrderInfo->UpperUserNo);
		data["OrderInsertUserNo"] = toUtf(task_data->OrderInfo->OrderInsertUserNo);
		data["OrderInsertTime"] = toUtf(task_data->OrderInfo->OrderInsertTime);
		data["OrderCommandUserNo"] = toUtf(task_data->OrderInfo->OrderCommandUserNo);
		data["OrderUpdateUserNo"] = toUtf(task_data->OrderInfo->OrderUpdateUserNo);
		data["OrderUpdateTime"] = toUtf(task_data->OrderInfo->OrderUpdateTime);
		data["OrderState"] = task_data->OrderInfo->OrderState;
		data["OrderMatchPrice"] = task_data->OrderInfo->OrderMatchPrice;
		data["OrderMatchPrice2"] = task_data->OrderInfo->OrderMatchPrice2;
		data["OrderMatchQty"] = task_data->OrderInfo->OrderMatchQty;
		data["OrderMatchQty2"] = task_data->OrderInfo->OrderMatchQty2;
		data["ErrorCode"] = task_data->OrderInfo->ErrorCode;
		data["ErrorText"] = toUtf(task_data->OrderInfo->ErrorText);
		data["IsBackInput"] = task_data->OrderInfo->IsBackInput;
		data["IsDeleted"] = task_data->OrderInfo->IsDeleted;
		data["IsAddOne"] = task_data->OrderInfo->IsAddOne;
		data["OrderStreamID"] = task_data->OrderInfo->OrderStreamID;
		data["UpperStreamID"] = task_data->OrderInfo->UpperStreamID;
		data["ContractSize"] = task_data->OrderInfo->ContractSize;
		data["ContractSize2"] = task_data->OrderInfo->ContractSize2;
		data["CommodityCurrencyGroup"] = toUtf(task_data->OrderInfo->CommodityCurrencyGroup);
		data["CommodityCurrency"] = toUtf(task_data->OrderInfo->CommodityCurrency);
		data["FeeMode"] = task_data->OrderInfo->FeeMode;
		data["FeeParam"] = task_data->OrderInfo->FeeParam;
		data["FeeCurrencyGroup"] = toUtf(task_data->OrderInfo->FeeCurrencyGroup);
		data["FeeCurrency"] = toUtf(task_data->OrderInfo->FeeCurrency);
		data["FeeMode2"] = task_data->OrderInfo->FeeMode2;
		data["FeeParam2"] = task_data->OrderInfo->FeeParam2;
		data["FeeCurrencyGroup2"] = toUtf(task_data->OrderInfo->FeeCurrencyGroup2);
		data["FeeCurrency2"] = toUtf(task_data->OrderInfo->FeeCurrency2);
		data["MarginMode"] = task_data->OrderInfo->MarginMode;
		data["MarginParam"] = task_data->OrderInfo->MarginParam;
		data["MarginMode2"] = task_data->OrderInfo->MarginMode2;
		data["MarginParam2"] = task_data->OrderInfo->MarginParam2;
		data["PreSettlePrice"] = task_data->OrderInfo->PreSettlePrice;
		data["PreSettlePrice2"] = task_data->OrderInfo->PreSettlePrice2;
		data["OpenVol"] = task_data->OrderInfo->OpenVol;
		data["CoverVol"] = task_data->OrderInfo->CoverVol;
		data["OpenVol2"] = task_data->OrderInfo->OpenVol2;
		data["CoverVol2"] = task_data->OrderInfo->CoverVol2;
		data["FeeValue"] = task_data->OrderInfo->FeeValue;
		data["MarginValue"] = task_data->OrderInfo->MarginValue;
		data["TacticsType"] = task_data->OrderInfo->TacticsType;
		data["TriggerCondition"] = task_data->OrderInfo->TriggerCondition;
		data["TriggerPriceType"] = task_data->OrderInfo->TriggerPriceType;
		data["AddOneIsValid"] = task_data->OrderInfo->AddOneIsValid;
		data["OrderQty2"] = task_data->OrderInfo->OrderQty2;
		data["HedgeFlag2"] = task_data->OrderInfo->HedgeFlag2;
		data["MarketLevel"] = task_data->OrderInfo->MarketLevel;
		data["OrderDeleteByDisConnFlag"] = task_data->OrderInfo->OrderDeleteByDisConnFlag;
		if (task_data->OrderInfo) delete task_data->OrderInfo;
		delete task_data;
	}
	this->onRspOrderAction(task->task_id, task->task_error, data);
};

void TdApi::processRspQryOrder(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		TapAPIOrderInfo* task_data = (TapAPIOrderInfo*)task->task_data;
		data["AccountNo"] = toUtf(task_data->AccountNo);
		data["ExchangeNo"] = toUtf(task_data->ExchangeNo);
		data["CommodityType"] = task_data->CommodityType;
		data["CommodityNo"] = toUtf(task_data->CommodityNo);
		data["ContractNo"] = toUtf(task_data->ContractNo);
		data["StrikePrice"] = toUtf(task_data->StrikePrice);
		data["CallOrPutFlag"] = task_data->CallOrPutFlag;
		data["ContractNo2"] = toUtf(task_data->ContractNo2);
		data["StrikePrice2"] = toUtf(task_data->StrikePrice2);
		data["CallOrPutFlag2"] = task_data->CallOrPutFlag2;
		data["OrderType"] = task_data->OrderType;
		data["OrderSource"] = task_data->OrderSource;
		data["TimeInForce"] = task_data->TimeInForce;
		data["ExpireTime"] = toUtf(task_data->ExpireTime);
		data["IsRiskOrder"] = task_data->IsRiskOrder;
		data["OrderSide"] = task_data->OrderSide;
		data["PositionEffect"] = task_data->PositionEffect;
		data["PositionEffect2"] = task_data->PositionEffect2;
		data["InquiryNo"] = toUtf(task_data->InquiryNo);
		data["HedgeFlag"] = task_data->HedgeFlag;
		data["OrderPrice"] = task_data->OrderPrice;
		data["OrderPrice2"] = task_data->OrderPrice2;
		data["StopPrice"] = task_data->StopPrice;
		data["OrderQty"] = task_data->OrderQty;
		data["OrderMinQty"] = task_data->OrderMinQty;
		data["OrderCanceledQty"] = task_data->OrderCanceledQty;
		data["MinClipSize"] = task_data->MinClipSize;
		data["MaxClipSize"] = task_data->MaxClipSize;
		data["LicenseNo"] = toUtf(task_data->LicenseNo);
		data["RefInt"] = task_data->RefInt;
		data["RefString"] = toUtf(task_data->RefString);
		data["ParentAccountNo"] = toUtf(task_data->ParentAccountNo);
		data["ServerFlag"] = task_data->ServerFlag;
		data["OrderNo"] = toUtf(task_data->OrderNo);
		data["ClientOrderNo"] = toUtf(task_data->ClientOrderNo);
		data["OrderLocalNo"] = toUtf(task_data->OrderLocalNo);
		data["OrderSystemNo"] = toUtf(task_data->OrderSystemNo);
		data["OrderExchangeSystemNo"] = toUtf(task_data->OrderExchangeSystemNo);
		data["OrderParentNo"] = toUtf(task_data->OrderParentNo);
		data["OrderParentSystemNo"] = toUtf(task_data->OrderParentSystemNo);
		data["TradeNo"] = toUtf(task_data->TradeNo);
		data["UpperNo"] = toUtf(task_data->UpperNo);
		data["UpperChannelNo"] = toUtf(task_data->UpperChannelNo);
		data["UpperSettleNo"] = toUtf(task_data->UpperSettleNo);
		data["UpperUserNo"] = toUtf(task_data->UpperUserNo);
		data["OrderInsertUserNo"] = toUtf(task_data->OrderInsertUserNo);
		data["OrderInsertTime"] = toUtf(task_data->OrderInsertTime);
		data["OrderCommandUserNo"] = toUtf(task_data->OrderCommandUserNo);
		data["OrderUpdateUserNo"] = toUtf(task_data->OrderUpdateUserNo);
		data["OrderUpdateTime"] = toUtf(task_data->OrderUpdateTime);
		data["OrderState"] = task_data->OrderState;
		data["OrderMatchPrice"] = task_data->OrderMatchPrice;
		data["OrderMatchPrice2"] = task_data->OrderMatchPrice2;
		data["OrderMatchQty"] = task_data->OrderMatchQty;
		data["OrderMatchQty2"] = task_data->OrderMatchQty2;
		data["ErrorCode"] = task_data->ErrorCode;
		data["ErrorText"] = toUtf(task_data->ErrorText);
		data["IsBackInput"] = task_data->IsBackInput;
		data["IsDeleted"] = task_data->IsDeleted;
		data["IsAddOne"] = task_data->IsAddOne;
		data["OrderStreamID"] = task_data->OrderStreamID;
		data["UpperStreamID"] = task_data->UpperStreamID;
		data["ContractSize"] = task_data->ContractSize;
		data["ContractSize2"] = task_data->ContractSize2;
		data["CommodityCurrencyGroup"] = toUtf(task_data->CommodityCurrencyGroup);
		data["CommodityCurrency"] = toUtf(task_data->CommodityCurrency);
		data["FeeMode"] = task_data->FeeMode;
		data["FeeParam"] = task_data->FeeParam;
		data["FeeCurrencyGroup"] = toUtf(task_data->FeeCurrencyGroup);
		data["FeeCurrency"] = toUtf(task_data->FeeCurrency);
		data["FeeMode2"] = task_data->FeeMode2;
		data["FeeParam2"] = task_data->FeeParam2;
		data["FeeCurrencyGroup2"] = toUtf(task_data->FeeCurrencyGroup2);
		data["FeeCurrency2"] = toUtf(task_data->FeeCurrency2);
		data["MarginMode"] = task_data->MarginMode;
		data["MarginParam"] = task_data->MarginParam;
		data["MarginMode2"] = task_data->MarginMode2;
		data["MarginParam2"] = task_data->MarginParam2;
		data["PreSettlePrice"] = task_data->PreSettlePrice;
		data["PreSettlePrice2"] = task_data->PreSettlePrice2;
		data["OpenVol"] = task_data->OpenVol;
		data["CoverVol"] = task_data->CoverVol;
		data["OpenVol2"] = task_data->OpenVol2;
		data["CoverVol2"] = task_data->CoverVol2;
		data["FeeValue"] = task_data->FeeValue;
		data["MarginValue"] = task_data->MarginValue;
		data["TacticsType"] = task_data->TacticsType;
		data["TriggerCondition"] = task_data->TriggerCondition;
		data["TriggerPriceType"] = task_data->TriggerPriceType;
		data["AddOneIsValid"] = task_data->AddOneIsValid;
		data["OrderQty2"] = task_data->OrderQty2;
		data["HedgeFlag2"] = task_data->HedgeFlag2;
		data["MarketLevel"] = task_data->MarketLevel;
		data["OrderDeleteByDisConnFlag"] = task_data->OrderDeleteByDisConnFlag;
		delete task_data;
	}
	this->onRspQryOrder(task->task_id, task->task_int, task->task_last, data);
};

void TdApi::processRspQryOrderProcess(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		TapAPIOrderInfo* task_data = (TapAPIOrderInfo*)task->task_data;
		data["AccountNo"] = toUtf(task_data->AccountNo);
		data["ExchangeNo"] = toUtf(task_data->ExchangeNo);
		data["CommodityType"] = task_data->CommodityType;
		data["CommodityNo"] = toUtf(task_data->CommodityNo);
		data["ContractNo"] = toUtf(task_data->ContractNo);
		data["StrikePrice"] = toUtf(task_data->StrikePrice);
		data["CallOrPutFlag"] = task_data->CallOrPutFlag;
		data["ContractNo2"] = toUtf(task_data->ContractNo2);
		data["StrikePrice2"] = toUtf(task_data->StrikePrice2);
		data["CallOrPutFlag2"] = task_data->CallOrPutFlag2;
		data["OrderType"] = task_data->OrderType;
		data["OrderSource"] = task_data->OrderSource;
		data["TimeInForce"] = task_data->TimeInForce;
		data["ExpireTime"] = toUtf(task_data->ExpireTime);
		data["IsRiskOrder"] = task_data->IsRiskOrder;
		data["OrderSide"] = task_data->OrderSide;
		data["PositionEffect"] = task_data->PositionEffect;
		data["PositionEffect2"] = task_data->PositionEffect2;
		data["InquiryNo"] = toUtf(task_data->InquiryNo);
		data["HedgeFlag"] = task_data->HedgeFlag;
		data["OrderPrice"] = task_data->OrderPrice;
		data["OrderPrice2"] = task_data->OrderPrice2;
		data["StopPrice"] = task_data->StopPrice;
		data["OrderQty"] = task_data->OrderQty;
		data["OrderMinQty"] = task_data->OrderMinQty;
		data["OrderCanceledQty"] = task_data->OrderCanceledQty;
		data["MinClipSize"] = task_data->MinClipSize;
		data["MaxClipSize"] = task_data->MaxClipSize;
		data["LicenseNo"] = toUtf(task_data->LicenseNo);
		data["RefInt"] = task_data->RefInt;
		data["RefString"] = toUtf(task_data->RefString);
		data["ParentAccountNo"] = toUtf(task_data->ParentAccountNo);
		data["ServerFlag"] = task_data->ServerFlag;
		data["OrderNo"] = toUtf(task_data->OrderNo);
		data["ClientOrderNo"] = toUtf(task_data->ClientOrderNo);
		data["OrderLocalNo"] = toUtf(task_data->OrderLocalNo);
		data["OrderSystemNo"] = toUtf(task_data->OrderSystemNo);
		data["OrderExchangeSystemNo"] = toUtf(task_data->OrderExchangeSystemNo);
		data["OrderParentNo"] = toUtf(task_data->OrderParentNo);
		data["OrderParentSystemNo"] = toUtf(task_data->OrderParentSystemNo);
		data["TradeNo"] = toUtf(task_data->TradeNo);
		data["UpperNo"] = toUtf(task_data->UpperNo);
		data["UpperChannelNo"] = toUtf(task_data->UpperChannelNo);
		data["UpperSettleNo"] = toUtf(task_data->UpperSettleNo);
		data["UpperUserNo"] = toUtf(task_data->UpperUserNo);
		data["OrderInsertUserNo"] = toUtf(task_data->OrderInsertUserNo);
		data["OrderInsertTime"] = toUtf(task_data->OrderInsertTime);
		data["OrderCommandUserNo"] = toUtf(task_data->OrderCommandUserNo);
		data["OrderUpdateUserNo"] = toUtf(task_data->OrderUpdateUserNo);
		data["OrderUpdateTime"] = toUtf(task_data->OrderUpdateTime);
		data["OrderState"] = task_data->OrderState;
		data["OrderMatchPrice"] = task_data->OrderMatchPrice;
		data["OrderMatchPrice2"] = task_data->OrderMatchPrice2;
		data["OrderMatchQty"] = task_data->OrderMatchQty;
		data["OrderMatchQty2"] = task_data->OrderMatchQty2;
		data["ErrorCode"] = task_data->ErrorCode;
		data["ErrorText"] = toUtf(task_data->ErrorText);
		data["IsBackInput"] = task_data->IsBackInput;
		data["IsDeleted"] = task_data->IsDeleted;
		data["IsAddOne"] = task_data->IsAddOne;
		data["OrderStreamID"] = task_data->OrderStreamID;
		data["UpperStreamID"] = task_data->UpperStreamID;
		data["ContractSize"] = task_data->ContractSize;
		data["ContractSize2"] = task_data->ContractSize2;
		data["CommodityCurrencyGroup"] = toUtf(task_data->CommodityCurrencyGroup);
		data["CommodityCurrency"] = toUtf(task_data->CommodityCurrency);
		data["FeeMode"] = task_data->FeeMode;
		data["FeeParam"] = task_data->FeeParam;
		data["FeeCurrencyGroup"] = toUtf(task_data->FeeCurrencyGroup);
		data["FeeCurrency"] = toUtf(task_data->FeeCurrency);
		data["FeeMode2"] = task_data->FeeMode2;
		data["FeeParam2"] = task_data->FeeParam2;
		data["FeeCurrencyGroup2"] = toUtf(task_data->FeeCurrencyGroup2);
		data["FeeCurrency2"] = toUtf(task_data->FeeCurrency2);
		data["MarginMode"] = task_data->MarginMode;
		data["MarginParam"] = task_data->MarginParam;
		data["MarginMode2"] = task_data->MarginMode2;
		data["MarginParam2"] = task_data->MarginParam2;
		data["PreSettlePrice"] = task_data->PreSettlePrice;
		data["PreSettlePrice2"] = task_data->PreSettlePrice2;
		data["OpenVol"] = task_data->OpenVol;
		data["CoverVol"] = task_data->CoverVol;
		data["OpenVol2"] = task_data->OpenVol2;
		data["CoverVol2"] = task_data->CoverVol2;
		data["FeeValue"] = task_data->FeeValue;
		data["MarginValue"] = task_data->MarginValue;
		data["TacticsType"] = task_data->TacticsType;
		data["TriggerCondition"] = task_data->TriggerCondition;
		data["TriggerPriceType"] = task_data->TriggerPriceType;
		data["AddOneIsValid"] = task_data->AddOneIsValid;
		data["OrderQty2"] = task_data->OrderQty2;
		data["HedgeFlag2"] = task_data->HedgeFlag2;
		data["MarketLevel"] = task_data->MarketLevel;
		data["OrderDeleteByDisConnFlag"] = task_data->OrderDeleteByDisConnFlag;
		delete task_data;
	}
	this->onRspQryOrderProcess(task->task_id, task->task_int, task->task_last, data);
};

void TdApi::processRspQryFill(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		TapAPIFillInfo* task_data = (TapAPIFillInfo*)task->task_data;
		data["AccountNo"] = toUtf(task_data->AccountNo);
		data["ParentAccountNo"] = toUtf(task_data->ParentAccountNo);
		data["ExchangeNo"] = toUtf(task_data->ExchangeNo);
		data["CommodityType"] = task_data->CommodityType;
		data["CommodityNo"] = toUtf(task_data->CommodityNo);
		data["ContractNo"] = toUtf(task_data->ContractNo);
		data["StrikePrice"] = toUtf(task_data->StrikePrice);
		data["CallOrPutFlag"] = task_data->CallOrPutFlag;
		data["ExchangeNoRef"] = toUtf(task_data->ExchangeNoRef);
		data["CommodityTypeRef"] = task_data->CommodityTypeRef;
		data["CommodityNoRef"] = toUtf(task_data->CommodityNoRef);
		data["ContractNoRef"] = toUtf(task_data->ContractNoRef);
		data["StrikePriceRef"] = toUtf(task_data->StrikePriceRef);
		data["CallOrPutFlagRef"] = task_data->CallOrPutFlagRef;
		data["OrderExchangeNo"] = toUtf(task_data->OrderExchangeNo);
		data["OrderCommodityType"] = task_data->OrderCommodityType;
		data["OrderCommodityNo"] = toUtf(task_data->OrderCommodityNo);
		data["OrderType"] = task_data->OrderType;
		data["MatchSource"] = task_data->MatchSource;
		data["TimeInForce"] = task_data->TimeInForce;
		data["ExpireTime"] = toUtf(task_data->ExpireTime);
		data["IsRiskOrder"] = task_data->IsRiskOrder;
		data["MatchSide"] = task_data->MatchSide;
		data["PositionEffect"] = task_data->PositionEffect;
		data["PositionEffectRef"] = task_data->PositionEffectRef;
		data["HedgeFlag"] = task_data->HedgeFlag;
		data["ServerFlag"] = task_data->ServerFlag;
		data["OrderNo"] = toUtf(task_data->OrderNo);
		data["OrderLocalNo"] = toUtf(task_data->OrderLocalNo);
		data["MatchNo"] = toUtf(task_data->MatchNo);
		data["ExchangeMatchNo"] = toUtf(task_data->ExchangeMatchNo);
		data["MatchDateTime"] = toUtf(task_data->MatchDateTime);
		data["UpperMatchDateTime"] = toUtf(task_data->UpperMatchDateTime);
		data["UpperNo"] = toUtf(task_data->UpperNo);
		data["UpperChannelNo"] = toUtf(task_data->UpperChannelNo);
		data["UpperSettleNo"] = toUtf(task_data->UpperSettleNo);
		data["UpperUserNo"] = toUtf(task_data->UpperUserNo);
		data["TradeNo"] = toUtf(task_data->TradeNo);
		data["MatchPrice"] = task_data->MatchPrice;
		data["MatchQty"] = task_data->MatchQty;
		data["IsBackInput"] = task_data->IsBackInput;
		data["IsDeleted"] = task_data->IsDeleted;
		data["IsAddOne"] = task_data->IsAddOne;
		data["MatchStreamID"] = task_data->MatchStreamID;
		data["UpperStreamID"] = task_data->UpperStreamID;
		data["OpenCloseMode"] = task_data->OpenCloseMode;
		data["ContractSize"] = task_data->ContractSize;
		data["CommodityCurrencyGroup"] = toUtf(task_data->CommodityCurrencyGroup);
		data["CommodityCurrency"] = toUtf(task_data->CommodityCurrency);
		data["FeeMode"] = task_data->FeeMode;
		data["FeeParam"] = task_data->FeeParam;
		data["FeeCurrencyGroup"] = toUtf(task_data->FeeCurrencyGroup);
		data["FeeCurrency"] = toUtf(task_data->FeeCurrency);
		data["PreSettlePrice"] = task_data->PreSettlePrice;
		data["FeeValue"] = task_data->FeeValue;
		data["IsManualFee"] = task_data->IsManualFee;
		data["Turnover"] = task_data->Turnover;
		data["PremiumIncome"] = task_data->PremiumIncome;
		data["PremiumPay"] = task_data->PremiumPay;
		data["OppoMatchNo"] = toUtf(task_data->OppoMatchNo);
		data["CloseProfit"] = task_data->CloseProfit;
		data["UnExpProfit"] = task_data->UnExpProfit;
		data["UpperMatchPrice"] = task_data->UpperMatchPrice;
		data["QuotePrice"] = task_data->QuotePrice;
		data["ClosePL"] = task_data->ClosePL;
		delete task_data;
	}
	this->onRspQryFill(task->task_id, task->task_int, task->task_last, data);
};

void TdApi::processRtnFill(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		TapAPIFillInfo* task_data = (TapAPIFillInfo*)task->task_data;
		data["AccountNo"] = toUtf(task_data->AccountNo);
		data["ParentAccountNo"] = toUtf(task_data->ParentAccountNo);
		data["ExchangeNo"] = toUtf(task_data->ExchangeNo);
		data["CommodityType"] = task_data->CommodityType;
		data["CommodityNo"] = toUtf(task_data->CommodityNo);
		data["ContractNo"] = toUtf(task_data->ContractNo);
		data["StrikePrice"] = toUtf(task_data->StrikePrice);
		data["CallOrPutFlag"] = task_data->CallOrPutFlag;
		data["ExchangeNoRef"] = toUtf(task_data->ExchangeNoRef);
		data["CommodityTypeRef"] = task_data->CommodityTypeRef;
		data["CommodityNoRef"] = toUtf(task_data->CommodityNoRef);
		data["ContractNoRef"] = toUtf(task_data->ContractNoRef);
		data["StrikePriceRef"] = toUtf(task_data->StrikePriceRef);
		data["CallOrPutFlagRef"] = task_data->CallOrPutFlagRef;
		data["OrderExchangeNo"] = toUtf(task_data->OrderExchangeNo);
		data["OrderCommodityType"] = task_data->OrderCommodityType;
		data["OrderCommodityNo"] = toUtf(task_data->OrderCommodityNo);
		data["OrderType"] = task_data->OrderType;
		data["MatchSource"] = task_data->MatchSource;
		data["TimeInForce"] = task_data->TimeInForce;
		data["ExpireTime"] = toUtf(task_data->ExpireTime);
		data["IsRiskOrder"] = task_data->IsRiskOrder;
		data["MatchSide"] = task_data->MatchSide;
		data["PositionEffect"] = task_data->PositionEffect;
		data["PositionEffectRef"] = task_data->PositionEffectRef;
		data["HedgeFlag"] = task_data->HedgeFlag;
		data["ServerFlag"] = task_data->ServerFlag;
		data["OrderNo"] = toUtf(task_data->OrderNo);
		data["OrderLocalNo"] = toUtf(task_data->OrderLocalNo);
		data["MatchNo"] = toUtf(task_data->MatchNo);
		data["ExchangeMatchNo"] = toUtf(task_data->ExchangeMatchNo);
		data["MatchDateTime"] = toUtf(task_data->MatchDateTime);
		data["UpperMatchDateTime"] = toUtf(task_data->UpperMatchDateTime);
		data["UpperNo"] = toUtf(task_data->UpperNo);
		data["UpperChannelNo"] = toUtf(task_data->UpperChannelNo);
		data["UpperSettleNo"] = toUtf(task_data->UpperSettleNo);
		data["UpperUserNo"] = toUtf(task_data->UpperUserNo);
		data["TradeNo"] = toUtf(task_data->TradeNo);
		data["MatchPrice"] = task_data->MatchPrice;
		data["MatchQty"] = task_data->MatchQty;
		data["IsBackInput"] = task_data->IsBackInput;
		data["IsDeleted"] = task_data->IsDeleted;
		data["IsAddOne"] = task_data->IsAddOne;
		data["MatchStreamID"] = task_data->MatchStreamID;
		data["UpperStreamID"] = task_data->UpperStreamID;
		data["OpenCloseMode"] = task_data->OpenCloseMode;
		data["ContractSize"] = task_data->ContractSize;
		data["CommodityCurrencyGroup"] = toUtf(task_data->CommodityCurrencyGroup);
		data["CommodityCurrency"] = toUtf(task_data->CommodityCurrency);
		data["FeeMode"] = task_data->FeeMode;
		data["FeeParam"] = task_data->FeeParam;
		data["FeeCurrencyGroup"] = toUtf(task_data->FeeCurrencyGroup);
		data["FeeCurrency"] = toUtf(task_data->FeeCurrency);
		data["PreSettlePrice"] = task_data->PreSettlePrice;
		data["FeeValue"] = task_data->FeeValue;
		data["IsManualFee"] = task_data->IsManualFee;
		data["Turnover"] = task_data->Turnover;
		data["PremiumIncome"] = task_data->PremiumIncome;
		data["PremiumPay"] = task_data->PremiumPay;
		data["OppoMatchNo"] = toUtf(task_data->OppoMatchNo);
		data["CloseProfit"] = task_data->CloseProfit;
		data["UnExpProfit"] = task_data->UnExpProfit;
		data["UpperMatchPrice"] = task_data->UpperMatchPrice;
		data["QuotePrice"] = task_data->QuotePrice;
		data["ClosePL"] = task_data->ClosePL;
		delete task_data;
	}
	this->onRtnFill(data);
};

void TdApi::processRspQryPosition(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		TapAPIPositionInfo* task_data = (TapAPIPositionInfo*)task->task_data;
		data["AccountNo"] = toUtf(task_data->AccountNo);
		data["ParentAccountNo"] = toUtf(task_data->ParentAccountNo);
		data["ExchangeNo"] = toUtf(task_data->ExchangeNo);
		data["CommodityType"] = task_data->CommodityType;
		data["CommodityNo"] = toUtf(task_data->CommodityNo);
		data["ContractNo"] = toUtf(task_data->ContractNo);
		data["StrikePrice"] = toUtf(task_data->StrikePrice);
		data["CallOrPutFlag"] = task_data->CallOrPutFlag;
		data["ExchangeNoRef"] = toUtf(task_data->ExchangeNoRef);
		data["CommodityTypeRef"] = task_data->CommodityTypeRef;
		data["CommodityNoRef"] = toUtf(task_data->CommodityNoRef);
		data["ContractNoRef"] = toUtf(task_data->ContractNoRef);
		data["StrikePriceRef"] = toUtf(task_data->StrikePriceRef);
		data["CallOrPutFlagRef"] = task_data->CallOrPutFlagRef;
		data["OrderExchangeNo"] = toUtf(task_data->OrderExchangeNo);
		data["OrderCommodityType"] = task_data->OrderCommodityType;
		data["OrderCommodityNo"] = toUtf(task_data->OrderCommodityNo);
		data["OrderType"] = task_data->OrderType;
		data["MatchSource"] = task_data->MatchSource;
		data["TimeInForce"] = task_data->TimeInForce;
		data["ExpireTime"] = toUtf(task_data->ExpireTime);
		data["MatchSide"] = task_data->MatchSide;
		data["HedgeFlag"] = task_data->HedgeFlag;
		data["PositionNo"] = toUtf(task_data->PositionNo);
		data["ServerFlag"] = task_data->ServerFlag;
		data["OrderNo"] = toUtf(task_data->OrderNo);
		data["MatchNo"] = toUtf(task_data->MatchNo);
		data["ExchangeMatchNo"] = toUtf(task_data->ExchangeMatchNo);
		data["MatchDate"] = toUtf(task_data->MatchDate);
		data["MatchTime"] = toUtf(task_data->MatchTime);
		data["UpperMatchTime"] = toUtf(task_data->UpperMatchTime);
		data["UpperNo"] = toUtf(task_data->UpperNo);
		data["UpperSettleNo"] = toUtf(task_data->UpperSettleNo);
		data["UpperUserNo"] = toUtf(task_data->UpperUserNo);
		data["TradeNo"] = toUtf(task_data->TradeNo);
		data["PositionPrice"] = task_data->PositionPrice;
		data["PositionQty"] = task_data->PositionQty;
		data["IsBackInput"] = task_data->IsBackInput;
		data["IsAddOne"] = task_data->IsAddOne;
		data["MatchStreamID"] = task_data->MatchStreamID;
		data["PositionStreamId"] = task_data->PositionStreamId;
		data["OpenCloseMode"] = task_data->OpenCloseMode;
		data["ContractSize"] = task_data->ContractSize;
		data["CommodityCurrencyGroup"] = toUtf(task_data->CommodityCurrencyGroup);
		data["CommodityCurrency"] = toUtf(task_data->CommodityCurrency);
		data["PreSettlePrice"] = task_data->PreSettlePrice;
		data["SettlePrice"] = task_data->SettlePrice;
		data["Turnover"] = task_data->Turnover;
		data["AccountMarginMode"] = task_data->AccountMarginMode;
		data["AccountMarginParam"] = task_data->AccountMarginParam;
		data["UpperMarginMode"] = task_data->UpperMarginMode;
		data["UpperMarginParam"] = task_data->UpperMarginParam;
		data["AccountInitialMargin"] = task_data->AccountInitialMargin;
		data["AccountMaintenanceMargin"] = task_data->AccountMaintenanceMargin;
		data["UpperInitialMargin"] = task_data->UpperInitialMargin;
		data["UpperMaintenanceMargin"] = task_data->UpperMaintenanceMargin;
		data["PositionProfit"] = task_data->PositionProfit;
		data["LMEPositionProfit"] = task_data->LMEPositionProfit;
		data["OptionMarketValue"] = task_data->OptionMarketValue;
		data["MatchCmbNo"] = toUtf(task_data->MatchCmbNo);
		data["IsHistory"] = task_data->IsHistory;
		data["FloatingPL"] = task_data->FloatingPL;
		delete task_data;
	}
	this->onRspQryPosition(task->task_id, task->task_int, task->task_last, data);
};

void TdApi::processRtnPosition(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		TapAPIPositionInfo* task_data = (TapAPIPositionInfo*)task->task_data;
		data["AccountNo"] = toUtf(task_data->AccountNo);
		data["ParentAccountNo"] = toUtf(task_data->ParentAccountNo);
		data["ExchangeNo"] = toUtf(task_data->ExchangeNo);
		data["CommodityType"] = task_data->CommodityType;
		data["CommodityNo"] = toUtf(task_data->CommodityNo);
		data["ContractNo"] = toUtf(task_data->ContractNo);
		data["StrikePrice"] = toUtf(task_data->StrikePrice);
		data["CallOrPutFlag"] = task_data->CallOrPutFlag;
		data["ExchangeNoRef"] = toUtf(task_data->ExchangeNoRef);
		data["CommodityTypeRef"] = task_data->CommodityTypeRef;
		data["CommodityNoRef"] = toUtf(task_data->CommodityNoRef);
		data["ContractNoRef"] = toUtf(task_data->ContractNoRef);
		data["StrikePriceRef"] = toUtf(task_data->StrikePriceRef);
		data["CallOrPutFlagRef"] = task_data->CallOrPutFlagRef;
		data["OrderExchangeNo"] = toUtf(task_data->OrderExchangeNo);
		data["OrderCommodityType"] = task_data->OrderCommodityType;
		data["OrderCommodityNo"] = toUtf(task_data->OrderCommodityNo);
		data["OrderType"] = task_data->OrderType;
		data["MatchSource"] = task_data->MatchSource;
		data["TimeInForce"] = task_data->TimeInForce;
		data["ExpireTime"] = toUtf(task_data->ExpireTime);
		data["MatchSide"] = task_data->MatchSide;
		data["HedgeFlag"] = task_data->HedgeFlag;
		data["PositionNo"] = toUtf(task_data->PositionNo);
		data["ServerFlag"] = task_data->ServerFlag;
		data["OrderNo"] = toUtf(task_data->OrderNo);
		data["MatchNo"] = toUtf(task_data->MatchNo);
		data["ExchangeMatchNo"] = toUtf(task_data->ExchangeMatchNo);
		data["MatchDate"] = toUtf(task_data->MatchDate);
		data["MatchTime"] = toUtf(task_data->MatchTime);
		data["UpperMatchTime"] = toUtf(task_data->UpperMatchTime);
		data["UpperNo"] = toUtf(task_data->UpperNo);
		data["UpperSettleNo"] = toUtf(task_data->UpperSettleNo);
		data["UpperUserNo"] = toUtf(task_data->UpperUserNo);
		data["TradeNo"] = toUtf(task_data->TradeNo);
		data["PositionPrice"] = task_data->PositionPrice;
		data["PositionQty"] = task_data->PositionQty;
		data["IsBackInput"] = task_data->IsBackInput;
		data["IsAddOne"] = task_data->IsAddOne;
		data["MatchStreamID"] = task_data->MatchStreamID;
		data["PositionStreamId"] = task_data->PositionStreamId;
		data["OpenCloseMode"] = task_data->OpenCloseMode;
		data["ContractSize"] = task_data->ContractSize;
		data["CommodityCurrencyGroup"] = toUtf(task_data->CommodityCurrencyGroup);
		data["CommodityCurrency"] = toUtf(task_data->CommodityCurrency);
		data["PreSettlePrice"] = task_data->PreSettlePrice;
		data["SettlePrice"] = task_data->SettlePrice;
		data["Turnover"] = task_data->Turnover;
		data["AccountMarginMode"] = task_data->AccountMarginMode;
		data["AccountMarginParam"] = task_data->AccountMarginParam;
		data["UpperMarginMode"] = task_data->UpperMarginMode;
		data["UpperMarginParam"] = task_data->UpperMarginParam;
		data["AccountInitialMargin"] = task_data->AccountInitialMargin;
		data["AccountMaintenanceMargin"] = task_data->AccountMaintenanceMargin;
		data["UpperInitialMargin"] = task_data->UpperInitialMargin;
		data["UpperMaintenanceMargin"] = task_data->UpperMaintenanceMargin;
		data["PositionProfit"] = task_data->PositionProfit;
		data["LMEPositionProfit"] = task_data->LMEPositionProfit;
		data["OptionMarketValue"] = task_data->OptionMarketValue;
		data["MatchCmbNo"] = toUtf(task_data->MatchCmbNo);
		data["IsHistory"] = task_data->IsHistory;
		data["FloatingPL"] = task_data->FloatingPL;
		delete task_data;
	}
	this->onRtnPosition(data);
};

void TdApi::processRspQryClose(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		TapAPICloseInfo* task_data = (TapAPICloseInfo*)task->task_data;
		data["AccountNo"] = toUtf(task_data->AccountNo);
		data["ParentAccountNo"] = toUtf(task_data->ParentAccountNo);
		data["ExchangeNo"] = toUtf(task_data->ExchangeNo);
		data["CommodityType"] = task_data->CommodityType;
		data["CommodityNo"] = toUtf(task_data->CommodityNo);
		data["ContractNo"] = toUtf(task_data->ContractNo);
		data["StrikePrice"] = toUtf(task_data->StrikePrice);
		data["CallOrPutFlag"] = task_data->CallOrPutFlag;
		data["OpenOrderExchangeNo"] = toUtf(task_data->OpenOrderExchangeNo);
		data["OpenOrderCommodityType"] = task_data->OpenOrderCommodityType;
		data["OpenOrderCommodityNo"] = toUtf(task_data->OpenOrderCommodityNo);
		data["CloseOrderExchangeNo"] = toUtf(task_data->CloseOrderExchangeNo);
		data["CloseOrderCommodityType"] = task_data->CloseOrderCommodityType;
		data["CloseOrderCommodityNo"] = toUtf(task_data->CloseOrderCommodityNo);
		data["OpenMatchSource"] = task_data->OpenMatchSource;
		data["CloseMatchSource"] = task_data->CloseMatchSource;
		data["CloseSide"] = task_data->CloseSide;
		data["CloseQty"] = task_data->CloseQty;
		data["OpenPrice"] = task_data->OpenPrice;
		data["ClosePrice"] = task_data->ClosePrice;
		data["OpenServerFlag"] = task_data->OpenServerFlag;
		data["OpenOrderNo"] = toUtf(task_data->OpenOrderNo);
		data["OpenMatchNo"] = toUtf(task_data->OpenMatchNo);
		data["OpenExchangeMatchNo"] = toUtf(task_data->OpenExchangeMatchNo);
		data["OpenMatchDateTime"] = toUtf(task_data->OpenMatchDateTime);
		data["CloseServerFlag"] = task_data->CloseServerFlag;
		data["CloseOrderNo"] = toUtf(task_data->CloseOrderNo);
		data["CloseMatchNo"] = toUtf(task_data->CloseMatchNo);
		data["CloseExchangeMatchNo"] = toUtf(task_data->CloseExchangeMatchNo);
		data["CloseMatchDateTime"] = toUtf(task_data->CloseMatchDateTime);
		data["CloseStreamId"] = task_data->CloseStreamId;
		data["OpenCloseMode"] = task_data->OpenCloseMode;
		data["ContractSize"] = task_data->ContractSize;
		data["CommodityCurrencyGroup"] = toUtf(task_data->CommodityCurrencyGroup);
		data["CommodityCurrency"] = toUtf(task_data->CommodityCurrency);
		data["PreSettlePrice"] = task_data->PreSettlePrice;
		data["PremiumIncome"] = task_data->PremiumIncome;
		data["PremiumPay"] = task_data->PremiumPay;
		data["CloseProfit"] = task_data->CloseProfit;
		data["UnExpProfit"] = task_data->UnExpProfit;
		data["ClosePL"] = task_data->ClosePL;
		delete task_data;
	}
	this->onRspQryClose(task->task_id, task->task_int, task->task_last, data);
};

void TdApi::processRtnClose(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		TapAPICloseInfo* task_data = (TapAPICloseInfo*)task->task_data;
		data["AccountNo"] = toUtf(task_data->AccountNo);
		data["ParentAccountNo"] = toUtf(task_data->ParentAccountNo);
		data["ExchangeNo"] = toUtf(task_data->ExchangeNo);
		data["CommodityType"] = task_data->CommodityType;
		data["CommodityNo"] = toUtf(task_data->CommodityNo);
		data["ContractNo"] = toUtf(task_data->ContractNo);
		data["StrikePrice"] = toUtf(task_data->StrikePrice);
		data["CallOrPutFlag"] = task_data->CallOrPutFlag;
		data["OpenOrderExchangeNo"] = toUtf(task_data->OpenOrderExchangeNo);
		data["OpenOrderCommodityType"] = task_data->OpenOrderCommodityType;
		data["OpenOrderCommodityNo"] = toUtf(task_data->OpenOrderCommodityNo);
		data["CloseOrderExchangeNo"] = toUtf(task_data->CloseOrderExchangeNo);
		data["CloseOrderCommodityType"] = task_data->CloseOrderCommodityType;
		data["CloseOrderCommodityNo"] = toUtf(task_data->CloseOrderCommodityNo);
		data["OpenMatchSource"] = task_data->OpenMatchSource;
		data["CloseMatchSource"] = task_data->CloseMatchSource;
		data["CloseSide"] = task_data->CloseSide;
		data["CloseQty"] = task_data->CloseQty;
		data["OpenPrice"] = task_data->OpenPrice;
		data["ClosePrice"] = task_data->ClosePrice;
		data["OpenServerFlag"] = task_data->OpenServerFlag;
		data["OpenOrderNo"] = toUtf(task_data->OpenOrderNo);
		data["OpenMatchNo"] = toUtf(task_data->OpenMatchNo);
		data["OpenExchangeMatchNo"] = toUtf(task_data->OpenExchangeMatchNo);
		data["OpenMatchDateTime"] = toUtf(task_data->OpenMatchDateTime);
		data["CloseServerFlag"] = task_data->CloseServerFlag;
		data["CloseOrderNo"] = toUtf(task_data->CloseOrderNo);
		data["CloseMatchNo"] = toUtf(task_data->CloseMatchNo);
		data["CloseExchangeMatchNo"] = toUtf(task_data->CloseExchangeMatchNo);
		data["CloseMatchDateTime"] = toUtf(task_data->CloseMatchDateTime);
		data["CloseStreamId"] = task_data->CloseStreamId;
		data["OpenCloseMode"] = task_data->OpenCloseMode;
		data["ContractSize"] = task_data->ContractSize;
		data["CommodityCurrencyGroup"] = toUtf(task_data->CommodityCurrencyGroup);
		data["CommodityCurrency"] = toUtf(task_data->CommodityCurrency);
		data["PreSettlePrice"] = task_data->PreSettlePrice;
		data["PremiumIncome"] = task_data->PremiumIncome;
		data["PremiumPay"] = task_data->PremiumPay;
		data["CloseProfit"] = task_data->CloseProfit;
		data["UnExpProfit"] = task_data->UnExpProfit;
		data["ClosePL"] = task_data->ClosePL;
		delete task_data;
	}
	this->onRtnClose(data);
};

void TdApi::processRtnPositionProfit(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		TapAPIPositionProfitNotice* task_data = (TapAPIPositionProfitNotice*)task->task_data;
		data["IsLast"] = task_data->IsLast;
		data["PositionNo"] = toUtf(task_data->Data->PositionNo);
		data["PositionStreamId"] = task_data->Data->PositionStreamId;
		data["PositionProfit"] = task_data->Data->PositionProfit;
		data["LMEPositionProfit"] = task_data->Data->LMEPositionProfit;
		data["OptionMarketValue"] = task_data->Data->OptionMarketValue;
		data["CalculatePrice"] = task_data->Data->CalculatePrice;
		data["FloatingPL"] = task_data->Data->FloatingPL;
		if (task_data->Data) delete task_data->Data;
		delete task_data;
	}
	this->onRtnPositionProfit(data);
};

void TdApi::processRspQryDeepQuote(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		TapAPIDeepQuoteQryRsp* task_data = (TapAPIDeepQuoteQryRsp*)task->task_data;
		data["ExchangeNo_Commodity"] = toUtf(task_data->Contract.Commodity.ExchangeNo);
		data["CommodityType_Commodity"] = task_data->Contract.Commodity.CommodityType;
		data["CommodityNo_Commodity"] = toUtf(task_data->Contract.Commodity.CommodityNo);
		data["ContractNo1"] = toUtf(task_data->Contract.ContractNo1);
		data["StrikePrice1"] = toUtf(task_data->Contract.StrikePrice1);
		data["CallOrPutFlag1"] = task_data->Contract.CallOrPutFlag1;
		data["ContractNo2"] = toUtf(task_data->Contract.ContractNo2);
		data["StrikePrice2"] = toUtf(task_data->Contract.StrikePrice2);
		data["CallOrPutFlag2"] = task_data->Contract.CallOrPutFlag2;
		data["Side"] = task_data->DeepQuote.Side;
		data["Price"] = task_data->DeepQuote.Price;
		data["Qty"] = task_data->DeepQuote.Qty;
		delete task_data;
	}
	this->onRspQryDeepQuote(task->task_id, task->task_int, task->task_last, data);
};

void TdApi::processRspQryExchangeStateInfo(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		TapAPIExchangeStateInfo* task_data = (TapAPIExchangeStateInfo*)task->task_data;
		data["UpperChannelNo"] = toUtf(task_data->UpperChannelNo);
		data["ExchangeNo"] = toUtf(task_data->ExchangeNo);
		data["CommodityType"] = task_data->CommodityType;
		data["CommodityNo"] = toUtf(task_data->CommodityNo);
		data["ExchangeTime"] = toUtf(task_data->ExchangeTime);
		data["TradingState"] = task_data->TradingState;
		delete task_data;
	}
	this->onRspQryExchangeStateInfo(task->task_id, task->task_int, task->task_last, data);
};

void TdApi::processRtnExchangeStateInfo(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		TapAPIExchangeStateInfoNotice* task_data = (TapAPIExchangeStateInfoNotice*)task->task_data;
		data["IsLast"] = task_data->IsLast;
		data["UpperChannelNo"] = toUtf(task_data->ExchangeStateInfo.UpperChannelNo);
		data["ExchangeNo"] = toUtf(task_data->ExchangeStateInfo.ExchangeNo);
		data["CommodityType"] = task_data->ExchangeStateInfo.CommodityType;
		data["CommodityNo"] = toUtf(task_data->ExchangeStateInfo.CommodityNo);
		data["ExchangeTime"] = toUtf(task_data->ExchangeStateInfo.ExchangeTime);
		data["TradingState"] = task_data->ExchangeStateInfo.TradingState;
		delete task_data;
	}
	this->onRtnExchangeStateInfo(data);
};

void TdApi::processRtnReqQuoteNotice(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		TapAPIReqQuoteNotice* task_data = (TapAPIReqQuoteNotice*)task->task_data;
		data["ExchangeNo"] = toUtf(task_data->ExchangeNo);
		data["CommodityType"] = task_data->CommodityType;
		data["CommodityNo"] = toUtf(task_data->CommodityNo);
		data["ContractNo"] = toUtf(task_data->ContractNo);
		data["StrikePrice"] = toUtf(task_data->StrikePrice);
		data["CallOrPutFlag"] = task_data->CallOrPutFlag;
		data["InquiryNo"] = toUtf(task_data->InquiryNo);
		data["UpdateTime"] = toUtf(task_data->UpdateTime);
		delete task_data;
	}
	this->onRtnReqQuoteNotice(data);
};

void TdApi::processRspUpperChannelInfo(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		TapAPIUpperChannelInfo* task_data = (TapAPIUpperChannelInfo*)task->task_data;
		data["UpperChannelNo"] = toUtf(task_data->UpperChannelNo);
		data["UpperChannelName"] = toUtf(task_data->UpperChannelName);
		data["UpperNo"] = toUtf(task_data->UpperNo);
		data["UpperUserNo"] = toUtf(task_data->UpperUserNo);
		delete task_data;
	}
	this->onRspUpperChannelInfo(task->task_id, task->task_int, task->task_last, data);
};

void TdApi::processRspAccountRentInfo(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		TapAPIAccountRentInfo* task_data = (TapAPIAccountRentInfo*)task->task_data;
		data["AccountNo"] = toUtf(task_data->AccountNo);
		data["ExchangeNo"] = toUtf(task_data->ExchangeNo);
		data["CommodityType"] = task_data->CommodityType;
		data["CommodityNo"] = toUtf(task_data->CommodityNo);
		data["ContractNo"] = toUtf(task_data->ContractNo);
		data["MatchSource"] = task_data->MatchSource;
		data["CurrencyNo"] = toUtf(task_data->CurrencyNo);
		data["FeeMode"] = task_data->FeeMode;
		data["OpenTurnover"] = task_data->OpenTurnover;
		data["ClosedTurnover"] = task_data->ClosedTurnover;
		data["CloseNewTurnover"] = task_data->CloseNewTurnover;
		data["OpenVolume"] = task_data->OpenVolume;
		data["ClosedVolume"] = task_data->ClosedVolume;
		data["CloseNewVolume"] = task_data->CloseNewVolume;
		data["MarginMode"] = task_data->MarginMode;
		data["BuyTInitMargin"] = task_data->BuyTInitMargin;
		data["SellTInitMargin"] = task_data->SellTInitMargin;
		data["BuyBInitMargin"] = task_data->BuyBInitMargin;
		data["SellBInitMargin"] = task_data->SellBInitMargin;
		data["BuyLInitMargin"] = task_data->BuyLInitMargin;
		data["SellLInitMargin"] = task_data->SellLInitMargin;
		data["BuyMInitMargin"] = task_data->BuyMInitMargin;
		data["SellMInitMargin"] = task_data->SellMInitMargin;
		data["BuyTMaintMargin"] = task_data->BuyTMaintMargin;
		data["SellTMaintMargin"] = task_data->SellTMaintMargin;
		data["BuyBMaintMargin"] = task_data->BuyBMaintMargin;
		data["SellBMaintMargin"] = task_data->SellBMaintMargin;
		data["BuyLMaintMargin"] = task_data->BuyLMaintMargin;
		data["SellLMaintMargin"] = task_data->SellLMaintMargin;
		data["BuyMMaintMargin"] = task_data->BuyMMaintMargin;
		data["SellMMaintMargin"] = task_data->SellMMaintMargin;
		delete task_data;
	}
	this->onRspAccountRentInfo(task->task_id, task->task_int, task->task_last, data);
};

void TdApi::processRspSubmitUserLoginInfo(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		TapAPISubmitUserLoginRspInfo* task_data = (TapAPISubmitUserLoginRspInfo*)task->task_data;
		data["UserNo"] = toUtf(task_data->UserNo);
		data["ErrorCode"] = task_data->ErrorCode;
		data["ErrorText"] = toUtf(task_data->ErrorText);
		delete task_data;
	}
	this->onRspSubmitUserLoginInfo(task->task_id, task->task_int, task->task_last, data);
};

void TdApi::processRspQryBill(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		TapAPIBillQryRsp* task_data = (TapAPIBillQryRsp*)task->task_data;
		data["Reqdata"] = task_data->Reqdata;
		data["BillLen"] = task_data->BillLen;
		data["BillText"] = toUtf(std::string(task_data->BillText, task_data->BillLen));
		delete task_data;
	}
	this->onRspQryBill(task->task_id, task->task_int, task->task_last, data);
};

void TdApi::processRspQryAccountStorage(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		TapAPIAccountStorageInfo* task_data = (TapAPIAccountStorageInfo*)task->task_data;
		data["AccountNo"] = toUtf(task_data->AccountNo);
		data["ExchangeNo"] = toUtf(task_data->ExchangeNo);
		data["CommodityType"] = task_data->CommodityType;
		data["CommodityNo"] = toUtf(task_data->CommodityNo);
		data["StorageQty"] = task_data->StorageQty;
		delete task_data;
	}
	this->onRspQryAccountStorage(task->task_id, task->task_int, task->task_last, data);
};

void TdApi::processRtnAccountStorage(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		TapAPIAccountStorageInfo* task_data = (TapAPIAccountStorageInfo*)task->task_data;
		data["AccountNo"] = toUtf(task_data->AccountNo);
		data["ExchangeNo"] = toUtf(task_data->ExchangeNo);
		data["CommodityType"] = task_data->CommodityType;
		data["CommodityNo"] = toUtf(task_data->CommodityNo);
		data["StorageQty"] = task_data->StorageQty;
		delete task_data;
	}
	this->onRtnAccountStorage(data);
};

///-------------------------------------------------------------------------------------
///主动函数
///-------------------------------------------------------------------------------------

void TdApi::createTapTradeAPI(const dict& req, int& iResult)
{
	TapAPIApplicationInfo myreq = TapAPIApplicationInfo();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "AuthCode", myreq.AuthCode);
	getString(req, "KeyOperationLogPath", myreq.KeyOperationLogPath);
	this->api = (ITapTradeAPI*)CreateTapTradeAPI(&myreq, iResult); // 创建API接口对象
	this->api->SetAPINotify(this);  //注册回调函数对象
};

void TdApi::release()
{
	FreeTapTradeAPI(this->api);
};

void TdApi::init()
{
	this->active = true;
	this->task_thread = thread(&TdApi::processTask, this);
};


int TdApi::exit()
{
	this->active = false;
	this->task_queue.terminate();
	this->task_thread.join();

	this->api->SetAPINotify(NULL);
	FreeTapTradeAPI(this->api);
	this->api = NULL;
	return 1;
};

int TdApi::login(const dict& req)
{
	TapAPITradeLoginAuth myreq = TapAPITradeLoginAuth();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "UserNo", myreq.UserNo);
	getString(req, "AuthCode", myreq.AuthCode);
	getString(req, "AppID", myreq.AppID);
	getChar(req, "ISModifyPassword", &myreq.ISModifyPassword);
	getString(req, "Password", myreq.Password);
	getString(req, "NewPassword", myreq.NewPassword);
	getChar(req, "ISDDA", &myreq.ISDDA);
	getString(req, "DDASerialNo", myreq.DDASerialNo);
	getUnsignedInt(req, "NoticeIgnoreFlag", &myreq.NoticeIgnoreFlag);
	int i = this->api->Login(&myreq);
	return i;
};

int TdApi::disconnect()
{
	int i = this->api->Disconnect();
	return i;
};

string TdApi::getTapTradeAPIVersion()
{
	string i = GetTapTradeAPIVersion();
	return i;
};

int TdApi::setTapTradeAPIDataPath(string path)
{
	int i = SetTapTradeAPIDataPath(path.c_str());
	return i;
};

int TdApi::setTapTradeAPILogLevel(string level)
{
	int i = SetTapTradeAPILogLevel(level.c_str()[0]);
	return i;
}

int TdApi::setHostAddress(string IP, int port)
{
	int i = this->api->SetHostAddress(IP.c_str(), (unsigned short)port);
	return i;
};

int TdApi::insertOrder(int sessionID, const dict& req)
{
	TapAPINewOrder myreq = TapAPINewOrder();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "AccountNo", myreq.AccountNo);
	getString(req, "ExchangeNo", myreq.ExchangeNo);
	getChar(req, "CommodityType", &myreq.CommodityType);
	getString(req, "CommodityNo", myreq.CommodityNo);
	getString(req, "ContractNo", myreq.ContractNo);
	getString(req, "StrikePrice", myreq.StrikePrice);
	getChar(req, "CallOrPutFlag", &myreq.CallOrPutFlag);
	getString(req, "ContractNo2", myreq.ContractNo2);
	getString(req, "StrikePrice2", myreq.StrikePrice2);
	getChar(req, "CallOrPutFlag2", &myreq.CallOrPutFlag2);
	getChar(req, "OrderType", &myreq.OrderType);
	getChar(req, "OrderSource", &myreq.OrderSource);
	getChar(req, "TimeInForce", &myreq.TimeInForce);
	getString(req, "ExpireTime", myreq.ExpireTime);
	getChar(req, "IsRiskOrder", &myreq.IsRiskOrder);
	getChar(req, "OrderSide", &myreq.OrderSide);
	getChar(req, "PositionEffect", &myreq.PositionEffect);
	getChar(req, "PositionEffect2", &myreq.PositionEffect2);
	getString(req, "InquiryNo", myreq.InquiryNo);
	getChar(req, "HedgeFlag", &myreq.HedgeFlag);
	getDouble(req, "OrderPrice", &myreq.OrderPrice);
	getDouble(req, "OrderPrice2", &myreq.OrderPrice2);
	getDouble(req, "StopPrice", &myreq.StopPrice);
	getUnsignedInt(req, "OrderQty", &myreq.OrderQty);
	getUnsignedInt(req, "OrderMinQty", &myreq.OrderMinQty);
	getUnsignedInt(req, "MinClipSize", &myreq.MinClipSize);
	getUnsignedInt(req, "MaxClipSize", &myreq.MaxClipSize);
	getInt(req, "RefInt", &myreq.RefInt);
	getString(req, "RefString", myreq.RefString);
	getChar(req, "TacticsType", &myreq.TacticsType);
	getChar(req, "TriggerCondition", &myreq.TriggerCondition);
	getChar(req, "TriggerPriceType", &myreq.TriggerPriceType);
	getChar(req, "AddOneIsValid", &myreq.AddOneIsValid);
	getUnsignedInt(req, "OrderQty2", &myreq.OrderQty2);
	getChar(req, "HedgeFlag2", &myreq.HedgeFlag2);
	getUnsignedChar(req, "MarketLevel", &myreq.MarketLevel);
	getChar(req, "FutureAutoCloseFlag", &myreq.FutureAutoCloseFlag);
	getString(req, "UpperChannelNo", myreq.UpperChannelNo);
	TAPIUINT32 session_id = static_cast<TAPIUINT32>(sessionID);
	int i = this->api->InsertOrder(&session_id, &myreq);
	return i;
};

int TdApi::cancelOrder(int sessionID, const dict& req)
{
	TapAPIOrderCancelReq myreq = TapAPIOrderCancelReq();
	memset(&myreq, 0, sizeof(myreq));
	getInt(req, "RefInt", &myreq.RefInt);
	getString(req, "RefString", myreq.RefString);
	getChar(req, "ServerFlag", &myreq.ServerFlag);
	getString(req, "OrderNo", myreq.OrderNo);
	TAPIUINT32 session_id = static_cast<TAPIUINT32>(sessionID);
	int i = this->api->CancelOrder(&session_id, &myreq);
	return i;
};

int TdApi::qryAccount(int sessionID, const dict& req)
{
	TapAPIAccQryReq myreq = TapAPIAccQryReq();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "AccountNo", myreq.AccountNo);
	TAPIUINT32 session_id = static_cast<TAPIUINT32>(sessionID);
	int i = this->api->QryAccount(&session_id, &myreq);
	return i;
};

int TdApi::qryFund(int sessionID, const dict& req)
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

int TdApi::qryContract(int sessionID, const dict& req)
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

int TdApi::qryOrder(int sessionID, const dict& req)
{
	TapAPIOrderQryReq myreq = TapAPIOrderQryReq();
	memset(&myreq, 0, sizeof(myreq));
	getChar(req, "OrderQryType", &myreq.OrderQryType);
	TAPIUINT32 session_id = static_cast<TAPIUINT32>(sessionID);
	int i = this->api->QryOrder(&session_id, &myreq);
	return i;
};

int TdApi::qryOrderProcess(int sessionID, const dict& req)
{
	TapAPIOrderProcessQryReq myreq = TapAPIOrderProcessQryReq();
	memset(&myreq, 0, sizeof(myreq));
	getChar(req, "ServerFlag", &myreq.ServerFlag);
	getString(req, "OrderNo", myreq.OrderNo);
	TAPIUINT32 session_id = static_cast<TAPIUINT32>(sessionID);
	int i = this->api->QryOrderProcess(&session_id, &myreq);
	return i;
};

int TdApi::qryFill(int sessionID, const dict& req)
{
	TapAPIFillQryReq myreq = TapAPIFillQryReq();
	memset(&myreq, 0, sizeof(myreq));
	getUnsignedInt(req, "StreamID", &myreq.StreamID);
	TAPIUINT32 session_id = static_cast<TAPIUINT32>(sessionID);
	int i = this->api->QryFill(&session_id, &myreq);
	return i;
};

int TdApi::qryPosition(int sessionID, const dict& req)
{
	TapAPIPositionQryReq myreq = TapAPIPositionQryReq();
	memset(&myreq, 0, sizeof(myreq));
	TAPIUINT32 session_id = static_cast<TAPIUINT32>(sessionID);
	int i = this->api->QryPosition(&session_id, &myreq);
	return i;
};

int TdApi::qryClose(int sessionID, const dict& req)
{
	TapAPICloseQryReq myreq = TapAPICloseQryReq();
	memset(&myreq, 0, sizeof(myreq));
	TAPIUINT32 session_id = static_cast<TAPIUINT32>(sessionID);
	int i = this->api->QryClose(&session_id, &myreq);
	return i;
};

int TdApi::qryDeepQuote(int sessionID, const dict& req)
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

int TdApi::qryExchangeStateInfo(int sessionID, const dict& req)
{
	TapAPIExchangeStateInfoQryReq myreq = TapAPIExchangeStateInfoQryReq();
	memset(&myreq, 0, sizeof(myreq));
	TAPIUINT32 session_id = static_cast<TAPIUINT32>(sessionID);
	int i = this->api->QryExchangeStateInfo(&session_id, &myreq);
	return i;
};

int TdApi::qryUpperChannel(int sessionID, const dict& req)
{
	TapAPIUpperChannelQryReq myreq = TapAPIUpperChannelQryReq();
	memset(&myreq, 0, sizeof(myreq));
	TAPIUINT32 session_id = static_cast<TAPIUINT32>(sessionID);
	int i = this->api->QryUpperChannel(&session_id, &myreq);
	return i;
};

int TdApi::qryAccountRent(int sessionID, const dict& req)
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

int TdApi::qryBill(int sessionID, const dict& req)
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

int TdApi::qryAccountStorage(int sessionID, const dict& req)
{
	TapAPIAccountStorageQryReq myreq = TapAPIAccountStorageQryReq();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "AccountNo", myreq.AccountNo);
	TAPIUINT32 session_id = static_cast<TAPIUINT32>(sessionID);
	int i = this->api->QryAccountStorage(&session_id, &myreq);
	return i;
};

///-------------------------------------------------------------------------------------
///Boost.Python封装
///-------------------------------------------------------------------------------------

class PyMdApi : public TdApi
{
public:
	using TdApi::TdApi;

	void onConnect() override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onConnect);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspLogin(int error, const dict& data) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspLogin, error, data);
		}
		catch (const error_already_set& e)
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
		catch (const error_already_set& e)
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
		catch (const error_already_set& e)
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
		catch (const error_already_set& e)
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
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspQryAccount(unsigned int sessionID, unsigned int errorCode, char last, const dict& data) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspQryAccount, sessionID, errorCode, last, data);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspQryFund(unsigned int sessionID, int error, char last, const dict& data) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspQryFund, sessionID, error, last, data);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRtnFund(const dict& data) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRtnFund, data);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspQryExchange(unsigned int sessionID, int error, char last, const dict& data) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspQryExchange, sessionID, error, last, data);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspQryCommodity(unsigned int sessionID, int error, char last, const dict& data) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspQryCommodity, sessionID, error, last, data);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspQryContract(unsigned int sessionID, int error, char last, const dict& data) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspQryContract, sessionID, error, last, data);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRtnContract(const dict& data) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRtnContract, data);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRtnOrder(const dict& data) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRtnOrder, data);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspOrderAction(unsigned int sessionID, unsigned int errorCode, const dict& data) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspOrderAction, sessionID, errorCode, data);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspQryOrder(unsigned int sessionID, int error, char last, const dict& data) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspQryOrder, sessionID, error, last, data);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspQryOrderProcess(unsigned int sessionID, int error, char last, const dict& data) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspQryOrderProcess, sessionID, error, last, data);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspQryFill(unsigned int sessionID, int error, char last, const dict& data) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspQryFill, sessionID, error, last, data);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRtnFill(const dict& data) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRtnFill, data);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspQryPosition(unsigned int sessionID, int error, char last, const dict& data) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspQryPosition, sessionID, error, last, data);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRtnPosition(const dict& data) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRtnPosition, data);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspQryClose(unsigned int sessionID, int error, char last, const dict& data) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspQryClose, sessionID, error, last, data);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRtnClose(const dict& data) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRtnClose, data);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRtnPositionProfit(const dict& data) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRtnPositionProfit, data);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspQryDeepQuote(unsigned int sessionID, int error, char last, const dict& data) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspQryDeepQuote, sessionID, error, last, data);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspQryExchangeStateInfo(unsigned int sessionID, int error, char last, const dict& data) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspQryExchangeStateInfo, sessionID, error, last, data);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRtnExchangeStateInfo(const dict& data) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRtnExchangeStateInfo, data);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRtnReqQuoteNotice(const dict& data) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRtnReqQuoteNotice, data);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspUpperChannelInfo(unsigned int sessionID, int error, char last, const dict& data) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspUpperChannelInfo, sessionID, error, last, data);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspAccountRentInfo(unsigned int sessionID, int error, char last, const dict& data) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspAccountRentInfo, sessionID, error, last, data);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspSubmitUserLoginInfo(unsigned int sessionID, int error, char last, const dict& data) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspSubmitUserLoginInfo, sessionID, error, last, data);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspQryBill(unsigned int sessionID, int error, char last, const dict& data) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspQryBill, sessionID, error, last, data);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspQryAccountStorage(unsigned int sessionID, int error, char last, const dict& data) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspQryAccountStorage, sessionID, error, last, data);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRtnAccountStorage(const dict& data) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRtnAccountStorage, data);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};
};

PYBIND11_MODULE(vnesunnytd, m)
{
	class_<TdApi, PyMdApi> tdapi(m, "TdApi", module_local());
	tdapi
		.def(init<>())
		.def("createTapTradeAPI", &TdApi::createTapTradeAPI)
		.def("release", &TdApi::release)
		.def("init", &TdApi::init)
		.def("exit", &TdApi::exit)
		.def("getTapTradeAPIVersion", &TdApi::getTapTradeAPIVersion)
		.def("setTapTradeAPIDataPath", &TdApi::setTapTradeAPIDataPath)
		.def("setTapTradeAPILogLevel", &TdApi::setTapTradeAPILogLevel)
		.def("setHostAddress", &TdApi::setHostAddress)
		.def("login", &TdApi::login)
		.def("disconnect", &TdApi::disconnect)
		.def("insertOrder", &TdApi::insertOrder)
		.def("cancelOrder", &TdApi::cancelOrder)

		.def("qryAccount", &TdApi::qryAccount)
		.def("qryFund", &TdApi::qryFund)
		.def("qryExchange", &TdApi::qryExchange)
		.def("qryCommodity", &TdApi::qryCommodity)
		.def("qryContract", &TdApi::qryContract)
		.def("qryOrder", &TdApi::qryOrder)
		.def("qryOrderProcess", &TdApi::qryOrderProcess)
		.def("qryFill", &TdApi::qryFill)
		.def("qryPosition", &TdApi::qryPosition)
		.def("qryClose", &TdApi::qryClose)
		.def("qryDeepQuote", &TdApi::qryDeepQuote)
		.def("qryExchangeStateInfo", &TdApi::qryExchangeStateInfo)
		.def("qryUpperChannel", &TdApi::qryUpperChannel)
		.def("qryAccountRent", &TdApi::qryAccountRent)
		.def("qryBill", &TdApi::qryBill)
		.def("qryAccountStorage", &TdApi::qryAccountStorage)

		.def("onConnect", &TdApi::onConnect)
		.def("onRspLogin", &TdApi::onRspLogin)
		.def("onAPIReady", &TdApi::onAPIReady)
		.def("onDisconnect", &TdApi::onDisconnect)
		.def("onRspChangePassword", &TdApi::onRspChangePassword)
		.def("onRspSetReservedInfo", &TdApi::onRspSetReservedInfo)
		.def("onRspQryAccount", &TdApi::onRspQryAccount)
		.def("onRspQryFund", &TdApi::onRspQryFund)
		.def("onRtnFund", &TdApi::onRtnFund)
		.def("onRspQryExchange", &TdApi::onRspQryExchange)
		.def("onRspQryCommodity", &TdApi::onRspQryCommodity)
		.def("onRspQryContract", &TdApi::onRspQryContract)
		.def("onRtnContract", &TdApi::onRtnContract)
		.def("onRtnOrder", &TdApi::onRtnOrder)
		.def("onRspOrderAction", &TdApi::onRspOrderAction)
		.def("onRspQryOrder", &TdApi::onRspQryOrder)
		.def("onRspQryOrderProcess", &TdApi::onRspQryOrderProcess)
		.def("onRspQryFill", &TdApi::onRspQryFill)
		.def("onRtnFill", &TdApi::onRtnFill)
		.def("onRspQryPosition", &TdApi::onRspQryPosition)
		.def("onRtnPosition", &TdApi::onRtnPosition)
		.def("onRspQryClose", &TdApi::onRspQryClose)
		.def("onRtnClose", &TdApi::onRtnClose)
		.def("onRtnPositionProfit", &TdApi::onRtnPositionProfit)
		.def("onRspQryDeepQuote", &TdApi::onRspQryDeepQuote)
		.def("onRspQryExchangeStateInfo", &TdApi::onRspQryExchangeStateInfo)
		.def("onRtnExchangeStateInfo", &TdApi::onRtnExchangeStateInfo)
		.def("onRtnReqQuoteNotice", &TdApi::onRtnReqQuoteNotice)
		.def("onRspUpperChannelInfo", &TdApi::onRspUpperChannelInfo)
		.def("onRspAccountRentInfo", &TdApi::onRspAccountRentInfo)
		.def("onRspSubmitUserLoginInfo", &TdApi::onRspSubmitUserLoginInfo)
		.def("onRspQryBill", &TdApi::onRspQryBill)
		.def("onRspQryAccountStorage", &TdApi::onRspQryAccountStorage)
		.def("onRtnAccountStorage", &TdApi::onRtnAccountStorage)
		;

}

