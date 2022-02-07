
// vnesunnytd.cpp : 定义 DLL 应用程序的导出函数。
//

#include "vnesunnytd.h"

///-------------------------------------------------------------------------------------
///C++的回调函数将数据保存到队列中
///-------------------------------------------------------------------------------------

void TdApi::OnConnect(const TAPISTR_20 UserNo)
{
	Task task = Task();
	task.task_name = ONCONNECT;
	task.task_string = UserNo;
	this->task_queue.push(task);
};

void TdApi::OnRspLogin(const TAPISTR_20 UserNo, TAPIINT32 nErrorCode, const TapAPITradeLoginRspInfo *pLoginRspInfo)
{
	Task task = Task();
	task.task_name = ONRSPLOGIN;
	task.task_string = UserNo;
	task.task_int = nErrorCode;
	if (pLoginRspInfo)
	{
		TapAPITradeLoginRspInfo *task_data = new TapAPITradeLoginRspInfo();
		*task_data = *pLoginRspInfo;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRtnContactInfo(const TAPISTR_20 UserNo, TAPIINT32 nErrorCode, TAPIYNFLAG isLast, const TapAPISecondInfo* pInfo)
{
	Task task = Task();
	task.task_name = ONRTNCONTACTINFO;
	task.task_string = UserNo;
	task.task_int = nErrorCode;
	task.task_last = isLast;
	if (pInfo)
	{
		TapAPISecondInfo *task_data = new TapAPISecondInfo();
		*task_data = *pInfo;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspRequestVertificateCode(const TAPISTR_20 UserNo, TAPIUINT32 nSessionID, TAPIINT32 nErrorCode, TAPIYNFLAG isLast, const TapAPIVertificateCode *pInfo)
{
	Task task = Task();
	task.task_name = ONRSPREQUESTVERTIFICATECODE;
	task.task_string = UserNo;
	task.task_id = nSessionID;
	task.task_int = nErrorCode;
	task.task_last = isLast;
	if (pInfo)
	{
		TapAPIVertificateCode *task_data = new TapAPIVertificateCode();
		*task_data = *pInfo;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

    void TdApi::OnRspRequestVerifyIdentity(const TAPISTR_20 UserNo, TAPIUINT32 nSessionID, TAPIINT32 nErrorCode, TAPIYNFLAG isLast, const TapAPIVerifyIdentity* pInfo)
{
	Task task = Task();
	task.task_name = ONRSPREQUESTVERIFYIDENTITY;
	task.task_string = UserNo;
	task.task_id = nSessionID;
	task.task_int = nErrorCode;
	task.task_last = isLast;
	if (pInfo)
	{
		TapAPIVerifyIdentity *task_data = new TapAPIVerifyIdentity();
		*task_data = *pInfo;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

    void TdApi::OnRspSetVertificateCode(const TAPISTR_20 UserNo, TAPIUINT32 nSessionID, TAPIINT32 nErrorCode, TAPIYNFLAG isLast, const TapAPISecondCertificationRsp *pInfo)
{
	Task task = Task();
	task.task_name = ONRSPSETVERTIFICATECODE;
	task.task_string = UserNo;
	task.task_id = nSessionID;
	task.task_int = nErrorCode;
	task.task_last = isLast;
	if (pInfo)
	{
		TapAPISecondCertificationRsp *task_data = new TapAPISecondCertificationRsp();
		*task_data = *pInfo;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRtnErrorMsg(const TAPISTR_20 UserNo, const TAPISTR_500 ErrorMsg)
{
	Task task = Task();
	task.task_name = ONRTNERRORMSG;
	task.task_string = UserNo;
	task.task_string = ErrorMsg;
	this->task_queue.push(task);
};

void TdApi::OnAPIReady(const TAPISTR_20 UserNo)
{
	Task task = Task();
	task.task_name = ONAPIREADY;
	task.task_string = UserNo;
	this->task_queue.push(task);
};

void TdApi::OnDisconnect(const TAPISTR_20 UserNo, TAPIINT32 nReasonCode)
{
	Task task = Task();
	task.task_name = ONDISCONNECT;
	task.task_string = UserNo;
	task.task_int = nReasonCode;
	this->task_queue.push(task);
};

void TdApi::OnRspSubmitUserLoginInfo(const TAPISTR_20 UserNo, TAPIUINT32 nSessionID, const TapAPISubmitUserLoginInfoRsp *pRspInfo)
{
	Task task = Task();
	task.task_name = ONRSPSUBMITUSERLOGININFO;
	task.task_string = UserNo;
	task.task_id = nSessionID;
	if (pRspInfo)
	{
		TapAPISubmitUserLoginInfoRsp *task_data = new TapAPISubmitUserLoginInfoRsp();
		*task_data = *pRspInfo;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspChangePassword(const TAPISTR_20 UserNo, TAPIUINT32 nSessionID, TAPIINT32 nErrorCode, const TapAPIChangePasswordRsp* pInfo)
{
	Task task = Task();
	task.task_name = ONRSPCHANGEPASSWORD;
	task.task_string = UserNo;
	task.task_id = nSessionID;
	task.task_int = nErrorCode;
	if (pInfo)
	{
		TapAPIChangePasswordRsp *task_data = new TapAPIChangePasswordRsp();
		*task_data = *pInfo;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspSetReservedInfo(const TAPISTR_20 UserNo, TAPIUINT32 nSessionID, TAPIINT32 nErrorCode, const TAPISTR_50 info)
{
	Task task = Task();
	task.task_name = ONRSPSETRESERVEDINFO;
	task.task_string = UserNo;
	task.task_id = nSessionID;
	task.task_int = nErrorCode;
	task.task_string = info;
	this->task_queue.push(task);
};

void TdApi::OnRtnContract(const TAPISTR_20 UserNo, const TapAPITradeContractInfo *pRtnInfo)
{
	Task task = Task();
	task.task_name = ONRTNCONTRACT;
	task.task_string = UserNo;
	if (pRtnInfo)
	{
		TapAPITradeContractInfo *task_data = new TapAPITradeContractInfo();
		*task_data = *pRtnInfo;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRtnFund(const TAPISTR_20 UserNo, const TapAPIFundData *pRtnInfo)
{
	Task task = Task();
	task.task_name = ONRTNFUND;
	task.task_string = UserNo;
	if (pRtnInfo)
	{
		TapAPIFundData *task_data = new TapAPIFundData();
		*task_data = *pRtnInfo;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRtnOrder(const TAPISTR_20 UserNo, TAPIUINT32 nRequestID, const TapAPIOrderInfo *pRtnInfo)
{
	Task task = Task();
	task.task_name = ONRTNORDER;
	task.task_string = UserNo;
	task.task_id = nRequestID;
	if (pRtnInfo)
	{
		TapAPIOrderInfo *task_data = new TapAPIOrderInfo();
		*task_data = *pRtnInfo;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

    void TdApi::OnRspOrderAction(const TAPISTR_20 UserNo, TAPIUINT32 nRequestID, TAPIINT32 nErrorCode, const TapAPIOrderActionRsp *pRtnInfo)
{
	Task task = Task();
	task.task_name = ONRSPORDERACTION;
	task.task_string = UserNo;
	task.task_id = nRequestID;
	task.task_int = nErrorCode;
	if (pRtnInfo)
	{
		TapAPIOrderActionRsp *task_data = new TapAPIOrderActionRsp();
		*task_data = *pRtnInfo;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspQryOrderProcess(const TAPISTR_20 UserNo, TAPIUINT32 nRequestID, TAPIINT32 nErrorCode, TAPIYNFLAG isLast, const TapAPIOrderInfo *pRspInfo)
{
	Task task = Task();
	task.task_name = ONRSPQRYORDERPROCESS;
	task.task_string = UserNo;
	task.task_id = nRequestID;
	task.task_int = nErrorCode;
	task.task_last = isLast;
	if (pRspInfo)
	{
		TapAPIOrderInfo *task_data = new TapAPIOrderInfo();
		*task_data = *pRspInfo;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRtnFill(const TAPISTR_20 UserNo, const TapAPIFillInfo *pRtnInfo)
{
	Task task = Task();
	task.task_name = ONRTNFILL;
	task.task_string = UserNo;
	if (pRtnInfo)
	{
		TapAPIFillInfo *task_data = new TapAPIFillInfo();
		*task_data = *pRtnInfo;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRtnPosition(const TAPISTR_20 UserNo, const TapAPIPositionInfo *pRtnInfo)
{
	Task task = Task();
	task.task_name = ONRTNPOSITION;
	task.task_string = UserNo;
	if (pRtnInfo)
	{
		TapAPIPositionInfo *task_data = new TapAPIPositionInfo();
		*task_data = *pRtnInfo;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRtnClose(const TAPISTR_20 UserNo, const TapAPICloseInfo *pRtnInfo)
{
	Task task = Task();
	task.task_name = ONRTNCLOSE;
	task.task_string = UserNo;
	if (pRtnInfo)
	{
		TapAPICloseInfo *task_data = new TapAPICloseInfo();
		*task_data = *pRtnInfo;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRtnPositionProfit(const TAPISTR_20 UserNo, const TapAPIPositionProfitNotice *pRtnInfo)
{
	Task task = Task();
	task.task_name = ONRTNPOSITIONPROFIT;
	task.task_string = UserNo;
	if (pRtnInfo)
	{
		TapAPIPositionProfitNotice *task_data = new TapAPIPositionProfitNotice();
		*task_data = *pRtnInfo;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspQryDeepQuote(const TAPISTR_20 UserNo, TAPIUINT32 nRequestID, TAPIINT32 nErrorCode, TAPIYNFLAG isLast, const TapAPIDeepQuoteQryRsp *pRspInfo)
{
	Task task = Task();
	task.task_name = ONRSPQRYDEEPQUOTE;
	task.task_string = UserNo;
	task.task_id = nRequestID;
	task.task_int = nErrorCode;
	task.task_last = isLast;
	if (pRspInfo)
	{
		TapAPIDeepQuoteQryRsp *task_data = new TapAPIDeepQuoteQryRsp();
		*task_data = *pRspInfo;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRtnExchangeStateInfo(const TAPISTR_20 UserNo, const TapAPIExchangeStateInfoNotice *pRtnInfo)
{
	Task task = Task();
	task.task_name = ONRTNEXCHANGESTATEINFO;
	task.task_string = UserNo;
	if (pRtnInfo)
	{
		TapAPIExchangeStateInfoNotice *task_data = new TapAPIExchangeStateInfoNotice();
		*task_data = *pRtnInfo;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRtnReqQuoteNotice(const TAPISTR_20 UserNo, const TapAPIReqQuoteNotice *pRtnInfo)
{
	Task task = Task();
	task.task_name = ONRTNREQQUOTENOTICE;
	task.task_string = UserNo;
	if (pRtnInfo)
	{
		TapAPIReqQuoteNotice *task_data = new TapAPIReqQuoteNotice();
		*task_data = *pRtnInfo;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspAccountRentInfo(const TAPISTR_20 UserNo, TAPIUINT32 nRequestID, TAPIINT32 nErrorCode, TAPIYNFLAG isLast, const TapAPIAccountRentInfo *pRspInfo)
{
	Task task = Task();
	task.task_name = ONRSPACCOUNTRENTINFO;
	task.task_string = UserNo;
	task.task_id = nRequestID;
	task.task_int = nErrorCode;
	task.task_last = isLast;
	if (pRspInfo)
	{
		TapAPIAccountRentInfo *task_data = new TapAPIAccountRentInfo();
		*task_data = *pRspInfo;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspTradeMessage(const TAPISTR_20 UserNo, TAPIUINT32 nRequestID, TAPIINT32 nErrorCode, TAPIYNFLAG isLast, const TapAPITradeMessage *pRspInfo)
{
	Task task = Task();
	task.task_name = ONRSPTRADEMESSAGE;
	task.task_string = UserNo;
	task.task_id = nRequestID;
	task.task_int = nErrorCode;
	task.task_last = isLast;
	if (pRspInfo)
	{
		TapAPITradeMessage *task_data = new TapAPITradeMessage();
		*task_data = *pRspInfo;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRtnTradeMessage(const TAPISTR_20 UserNo, const TapAPITradeMessage *pRtnInfo)
{
	Task task = Task();
	task.task_name = ONRTNTRADEMESSAGE;
	task.task_string = UserNo;
	if (pRtnInfo)
	{
		TapAPITradeMessage *task_data = new TapAPITradeMessage();
		*task_data = *pRtnInfo;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspQryHisOrder(const TAPISTR_20 UserNo, TAPIUINT32 nRequestID, TAPIINT32 nErrorCode, TAPIYNFLAG isLast, const TapAPIHisOrderQryRsp *pInfo)
{
	Task task = Task();
	task.task_name = ONRSPQRYHISORDER;
	task.task_string = UserNo;
	task.task_id = nRequestID;
	task.task_int = nErrorCode;
	task.task_last = isLast;
	if (pInfo)
	{
		TapAPIHisOrderQryRsp *task_data = new TapAPIHisOrderQryRsp();
		*task_data = *pInfo;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspQryHisOrderProcess(const TAPISTR_20 UserNo, TAPIUINT32 nRequestID, TAPIINT32 nErrorCode, TAPIYNFLAG isLast, const TapAPIHisOrderProcessQryRsp *pInfo)
{
	Task task = Task();
	task.task_name = ONRSPQRYHISORDERPROCESS;
	task.task_string = UserNo;
	task.task_id = nRequestID;
	task.task_int = nErrorCode;
	task.task_last = isLast;
	if (pInfo)
	{
		TapAPIHisOrderProcessQryRsp *task_data = new TapAPIHisOrderProcessQryRsp();
		*task_data = *pInfo;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspQryHisFill(const TAPISTR_20 UserNo, TAPIUINT32 nRequestID, TAPIINT32 nErrorCode, TAPIYNFLAG isLast, const TapAPIHisFillQryRsp *pInfo)
{
	Task task = Task();
	task.task_name = ONRSPQRYHISFILL;
	task.task_string = UserNo;
	task.task_id = nRequestID;
	task.task_int = nErrorCode;
	task.task_last = isLast;
	if (pInfo)
	{
		TapAPIHisFillQryRsp *task_data = new TapAPIHisFillQryRsp();
		*task_data = *pInfo;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspQryHisPosition(const TAPISTR_20 UserNo, TAPIUINT32 nRequestID, TAPIINT32 nErrorCode, TAPIYNFLAG isLast, const TapAPIHisPositionQryRsp *pInfo)
{
	Task task = Task();
	task.task_name = ONRSPQRYHISPOSITION;
	task.task_string = UserNo;
	task.task_id = nRequestID;
	task.task_int = nErrorCode;
	task.task_last = isLast;
	if (pInfo)
	{
		TapAPIHisPositionQryRsp *task_data = new TapAPIHisPositionQryRsp();
		*task_data = *pInfo;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspQryHisDelivery(const TAPISTR_20 UserNo, TAPIUINT32 nRequestID, TAPIINT32 nErrorCode, TAPIYNFLAG isLast, const TapAPIHisDeliveryQryRsp *pInfo)
{
	Task task = Task();
	task.task_name = ONRSPQRYHISDELIVERY;
	task.task_string = UserNo;
	task.task_id = nRequestID;
	task.task_int = nErrorCode;
	task.task_last = isLast;
	if (pInfo)
	{
		TapAPIHisDeliveryQryRsp *task_data = new TapAPIHisDeliveryQryRsp();
		*task_data = *pInfo;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspQryAccountCashAdjust(const TAPISTR_20 UserNo, TAPIUINT32 nRequestID, TAPIINT32 nErrorCode, TAPIYNFLAG isLast, const TapAPIAccountCashAdjustQryRsp *pInfo)
{
	Task task = Task();
	task.task_name = ONRSPQRYACCOUNTCASHADJUST;
	task.task_string = UserNo;
	task.task_id = nRequestID;
	task.task_int = nErrorCode;
	task.task_last = isLast;
	if (pInfo)
	{
		TapAPIAccountCashAdjustQryRsp *task_data = new TapAPIAccountCashAdjustQryRsp();
		*task_data = *pInfo;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspQryBill(const TAPISTR_20 UserNo, TAPIUINT32 nRequestID, TAPIINT32 nErrorCode, TAPIYNFLAG isLast, const TapAPIBillQryRsp *pInfo)
{
	Task task = Task();
	task.task_name = ONRSPQRYBILL;
	task.task_string = UserNo;
	task.task_id = nRequestID;
	task.task_int = nErrorCode;
	task.task_last = isLast;
	if (pInfo)
	{
		TapAPIBillQryRsp *task_data = new TapAPIBillQryRsp();
		*task_data = *pInfo;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspAccountFeeRent(const TAPISTR_20 UserNo, TAPIUINT32 nRequestID, TAPIINT32 nErrorCode, TAPIYNFLAG isLast, const TapAPIAccountFeeRentQryRsp *pInfo)
{
	Task task = Task();
	task.task_name = ONRSPACCOUNTFEERENT;
	task.task_string = UserNo;
	task.task_id = nRequestID;
	task.task_int = nErrorCode;
	task.task_last = isLast;
	if (pInfo)
	{
		TapAPIAccountFeeRentQryRsp *task_data = new TapAPIAccountFeeRentQryRsp();
		*task_data = *pInfo;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspAccountMarginRent(const TAPISTR_20 UserNo, TAPIUINT32 nRequestID, TAPIINT32 nErrorCode, TAPIYNFLAG isLast, const TapAPIAccountMarginRentQryRsp *pInfo)
{
	Task task = Task();
	task.task_name = ONRSPACCOUNTMARGINRENT;
	task.task_string = UserNo;
	task.task_id = nRequestID;
	task.task_int = nErrorCode;
	task.task_last = isLast;
	if (pInfo)
	{
		TapAPIAccountMarginRentQryRsp *task_data = new TapAPIAccountMarginRentQryRsp();
		*task_data = *pInfo;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspAddMobileDevice(const TAPISTR_20 UserNo, TAPIUINT32 nRequestID, TAPIINT32 nErrorCode, TAPIYNFLAG isLast, const TapAPIMobileDeviceAddRsp *pInfo)
{
	Task task = Task();
	task.task_name = ONRSPADDMOBILEDEVICE;
	task.task_string = UserNo;
	task.task_id = nRequestID;
	task.task_int = nErrorCode;
	task.task_last = isLast;
	if (pInfo)
	{
		TapAPIMobileDeviceAddRsp *task_data = new TapAPIMobileDeviceAddRsp();
		*task_data = *pInfo;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspQryManageInfoForEStar(const TAPISTR_20 UserNo, TAPIUINT32 nRequestID, TAPIINT32 nErrorCode, TAPIYNFLAG isLast, const TapAPIManageInfo *pInfo)
{
	Task task = Task();
	task.task_name = ONRSPQRYMANAGEINFOFORESTAR;
	task.task_string = UserNo;
	task.task_id = nRequestID;
	task.task_int = nErrorCode;
	task.task_last = isLast;
	if (pInfo)
	{
		TapAPIManageInfo *task_data = new TapAPIManageInfo();
		*task_data = *pInfo;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspQrySystemParameter(const TAPISTR_20 UserNo, TAPIUINT32 nRequestID, TAPIINT32 nErrorCode, TAPIYNFLAG isLast, const TapAPISystemParameterInfo *pInfo)
{
	Task task = Task();
	task.task_name = ONRSPQRYSYSTEMPARAMETER;
	task.task_string = UserNo;
	task.task_id = nRequestID;
	task.task_int = nErrorCode;
	task.task_last = isLast;
	if (pInfo)
	{
		TapAPISystemParameterInfo *task_data = new TapAPISystemParameterInfo();
		*task_data = *pInfo;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspQryTradeCenterFrontAddress(const TAPISTR_20 UserNo, TAPIUINT32 nRequestID, TAPIINT32 nErrorCode, TAPIYNFLAG isLast, const TapAPITradeCenterFrontAddressInfo *pInfo)
{
	Task task = Task();
	task.task_name = ONRSPQRYTRADECENTERFRONTADDRESS;
	task.task_string = UserNo;
	task.task_id = nRequestID;
	task.task_int = nErrorCode;
	task.task_last = isLast;
	if (pInfo)
	{
		TapAPITradeCenterFrontAddressInfo *task_data = new TapAPITradeCenterFrontAddressInfo();
		*task_data = *pInfo;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRtnCommodityInfo(const TAPISTR_20 UserNo, const TapAPICommodityInfo *pInfo)
{
	Task task = Task();
	task.task_name = ONRTNCOMMODITYINFO;
	task.task_string = UserNo;
	if (pInfo)
	{
		TapAPICommodityInfo *task_data = new TapAPICommodityInfo();
		*task_data = *pInfo;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRtnCurrencyInfo(const TAPISTR_20 UserNo, const TapAPICurrencyInfo *pInfo)
{
	Task task = Task();
	task.task_name = ONRTNCURRENCYINFO;
	task.task_string = UserNo;
	if (pInfo)
	{
		TapAPICurrencyInfo *task_data = new TapAPICurrencyInfo();
		*task_data = *pInfo;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

    void TdApi::OnRspQryAccountStorage(const TAPISTR_20 UserNo, TAPIUINT32 nRequestID, TAPIINT32 nErrorCode, TAPIYNFLAG isLast, const TapAPIAccountStorageInfo* pInfo)
{
	Task task = Task();
	task.task_name = ONRSPQRYACCOUNTSTORAGE;
	task.task_string = UserNo;
	task.task_id = nRequestID;
	task.task_int = nErrorCode;
	task.task_last = isLast;
	if (pInfo)
	{
		TapAPIAccountStorageInfo *task_data = new TapAPIAccountStorageInfo();
		*task_data = *pInfo;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

    void TdApi::OnRtnAccountStorage(const TAPISTR_20 UserNo, const TapAPIAccountStorageInfo* pInfo)
{
	Task task = Task();
	task.task_name = ONRTNACCOUNTSTORAGE;
	task.task_string = UserNo;
	if (pInfo)
	{
		TapAPIAccountStorageInfo *task_data = new TapAPIAccountStorageInfo();
		*task_data = *pInfo;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

    void TdApi::OnRspQrySpotLock(const TAPISTR_20 UserNo, TAPIUINT32 nRequestID, TAPIINT32 nErrorCode, TAPIYNFLAG isLast, const TapAPISpotLockInfo* pInfo)
{
	Task task = Task();
	task.task_name = ONRSPQRYSPOTLOCK;
	task.task_string = UserNo;
	task.task_id = nRequestID;
	task.task_int = nErrorCode;
	task.task_last = isLast;
	if (pInfo)
	{
		TapAPISpotLockInfo *task_data = new TapAPISpotLockInfo();
		*task_data = *pInfo;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

    void TdApi::OnRtnSpotLock(const TAPISTR_20 UserNo, const TapAPISpotLockInfo* pInfo)
{
	Task task = Task();
	task.task_name = ONRTNSPOTLOCK;
	task.task_string = UserNo;
	if (pInfo)
	{
		TapAPISpotLockInfo *task_data = new TapAPISpotLockInfo();
		*task_data = *pInfo;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

    void TdApi::OnRspSpecialOrderAction(const TAPISTR_20 UserNo, TAPIUINT32 nRequestID, TAPIINT32 nErrorCode, const TapAPISpecialOrderInfo *pRtnInfo)
{
	Task task = Task();
	task.task_name = ONRSPSPECIALORDERACTION;
	task.task_string = UserNo;
	task.task_id = nRequestID;
	task.task_int = nErrorCode;
	if (pRtnInfo)
	{
		TapAPISpecialOrderInfo *task_data = new TapAPISpecialOrderInfo();
		*task_data = *pRtnInfo;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

    void TdApi::OnRtnSpecialOrder(const TAPISTR_20 UserNo, TAPIUINT32 nRequestID, const TapAPISpecialOrderInfo* pInfo)
{
	Task task = Task();
	task.task_name = ONRTNSPECIALORDER;
	task.task_string = UserNo;
	task.task_id = nRequestID;
	if (pInfo)
	{
		TapAPISpecialOrderInfo *task_data = new TapAPISpecialOrderInfo();
		*task_data = *pInfo;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

    void TdApi::OnRtnCombinePosition(const TAPISTR_20 UserNo, const TapAPICombinePositionInfo* pInfo)
{
	Task task = Task();
	task.task_name = ONRTNCOMBINEPOSITION;
	task.task_string = UserNo;
	if (pInfo)
	{
		TapAPICombinePositionInfo *task_data = new TapAPICombinePositionInfo();
		*task_data = *pInfo;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

    void TdApi::OnRtnContractQuote(const TAPISTR_20 UserNo, const TapAPIContractQuoteInfo* pInfo)
{
	Task task = Task();
	task.task_name = ONRTNCONTRACTQUOTE;
	task.task_string = UserNo;
	if (pInfo)
	{
		TapAPIContractQuoteInfo *task_data = new TapAPIContractQuoteInfo();
		*task_data = *pInfo;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

    void TdApi::OnRspQryTrustDevice(const TAPISTR_20 UserNo, TAPIUINT32 nRequestID, TAPIINT32 nErrorCode, TAPIYNFLAG isLast, const TapAPITrustDeviceInfo* pInfo)
{
	Task task = Task();
	task.task_name = ONRSPQRYTRUSTDEVICE;
	task.task_string = UserNo;
	task.task_id = nRequestID;
	task.task_int = nErrorCode;
	task.task_last = isLast;
	if (pInfo)
	{
		TapAPITrustDeviceInfo *task_data = new TapAPITrustDeviceInfo();
		*task_data = *pInfo;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

    void TdApi::OnRspAddTrustDevice(const TAPISTR_20 UserNo, TAPIUINT32 nRequestID, TAPIINT32 nErrorCode, TAPIYNFLAG isLast, const TapAPITrustDeviceAddRsp* pInfo)
{
	Task task = Task();
	task.task_name = ONRSPADDTRUSTDEVICE;
	task.task_string = UserNo;
	task.task_id = nRequestID;
	task.task_int = nErrorCode;
	task.task_last = isLast;
	if (pInfo)
	{
		TapAPITrustDeviceAddRsp *task_data = new TapAPITrustDeviceAddRsp();
		*task_data = *pInfo;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

    void TdApi::OnRspDelTrustDevice(const TAPISTR_20 UserNo, TAPIUINT32 nRequestID, TAPIINT32 nErrorCode, TAPIYNFLAG isLast, const TapAPITrustDeviceDelRsp* pInfo)
{
	Task task = Task();
	task.task_name = ONRSPDELTRUSTDEVICE;
	task.task_string = UserNo;
	task.task_id = nRequestID;
	task.task_int = nErrorCode;
	task.task_last = isLast;
	if (pInfo)
	{
		TapAPITrustDeviceDelRsp *task_data = new TapAPITrustDeviceDelRsp();
		*task_data = *pInfo;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

    void TdApi::OnRtnAddUserRight(const TAPISTR_20 UserNo, const TapAPIUserRightInfo* pInfo)
{
	Task task = Task();
	task.task_name = ONRTNADDUSERRIGHT;
	task.task_string = UserNo;
	if (pInfo)
	{
		TapAPIUserRightInfo *task_data = new TapAPIUserRightInfo();
		*task_data = *pInfo;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

    void TdApi::OnRtnDelUserRight(const TAPISTR_20 UserNo, const TapAPIUserRightInfo* pInfo)
{
	Task task = Task();
	task.task_name = ONRTNDELUSERRIGHT;
	task.task_string = UserNo;
	if (pInfo)
	{
		TapAPIUserRightInfo *task_data = new TapAPIUserRightInfo();
		*task_data = *pInfo;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

    void TdApi::OnRspQryManagerConfigFile(const TAPISTR_20 UserNo, TAPIUINT32 nRequestID, TAPIINT32 nErrorCode, TAPIYNFLAG isLast, const TapAPIManagerConfigFileQryRsp* pInfo)
{
	Task task = Task();
	task.task_name = ONRSPQRYMANAGERCONFIGFILE;
	task.task_string = UserNo;
	task.task_id = nRequestID;
	task.task_int = nErrorCode;
	task.task_last = isLast;
	if (pInfo)
	{
		TapAPIManagerConfigFileQryRsp *task_data = new TapAPIManagerConfigFileQryRsp();
		*task_data = *pInfo;
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

			//cout << task.task_name << endl;

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
            
            case ONRTNCONTACTINFO:
            {
            	this->processRtnContactInfo(&task);
            	break;
            }
            
            case ONRSPREQUESTVERTIFICATECODE:
            {
            	this->processRspRequestVertificateCode(&task);
            	break;
            }
            
            case ONRSPREQUESTVERIFYIDENTITY:
            {
            	this->processRspRequestVerifyIdentity(&task);
            	break;
            }
            
            case ONRSPSETVERTIFICATECODE:
            {
            	this->processRspSetVertificateCode(&task);
            	break;
            }
            
            case ONRTNERRORMSG:
            {
            	this->processRtnErrorMsg(&task);
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
            
            case ONRSPSUBMITUSERLOGININFO:
            {
            	this->processRspSubmitUserLoginInfo(&task);
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
            
            case ONRTNCONTRACT:
            {
            	this->processRtnContract(&task);
            	break;
            }
            
            case ONRTNFUND:
            {
            	this->processRtnFund(&task);
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
            
            case ONRSPQRYORDERPROCESS:
            {
            	this->processRspQryOrderProcess(&task);
            	break;
            }
            
            case ONRTNFILL:
            {
            	this->processRtnFill(&task);
            	break;
            }
            
            case ONRTNPOSITION:
            {
            	this->processRtnPosition(&task);
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
            
            case ONRSPACCOUNTRENTINFO:
            {
            	this->processRspAccountRentInfo(&task);
            	break;
            }
            
            case ONRSPTRADEMESSAGE:
            {
            	this->processRspTradeMessage(&task);
            	break;
            }
            
            case ONRTNTRADEMESSAGE:
            {
            	this->processRtnTradeMessage(&task);
            	break;
            }
            
            case ONRSPQRYHISORDER:
            {
            	this->processRspQryHisOrder(&task);
            	break;
            }
            
            case ONRSPQRYHISORDERPROCESS:
            {
            	this->processRspQryHisOrderProcess(&task);
            	break;
            }
            
            case ONRSPQRYHISFILL:
            {
            	this->processRspQryHisFill(&task);
            	break;
            }
            
            case ONRSPQRYHISPOSITION:
            {
            	this->processRspQryHisPosition(&task);
            	break;
            }
            
            case ONRSPQRYHISDELIVERY:
            {
            	this->processRspQryHisDelivery(&task);
            	break;
            }
            
            case ONRSPQRYACCOUNTCASHADJUST:
            {
            	this->processRspQryAccountCashAdjust(&task);
            	break;
            }
            
            case ONRSPQRYBILL:
            {
            	this->processRspQryBill(&task);
            	break;
            }
            
            case ONRSPACCOUNTFEERENT:
            {
            	this->processRspAccountFeeRent(&task);
            	break;
            }
            
            case ONRSPACCOUNTMARGINRENT:
            {
            	this->processRspAccountMarginRent(&task);
            	break;
            }
            
            case ONRSPADDMOBILEDEVICE:
            {
            	this->processRspAddMobileDevice(&task);
            	break;
            }
            
            case ONRSPQRYMANAGEINFOFORESTAR:
            {
            	this->processRspQryManageInfoForEStar(&task);
            	break;
            }
            
            case ONRSPQRYSYSTEMPARAMETER:
            {
            	this->processRspQrySystemParameter(&task);
            	break;
            }
            
            case ONRSPQRYTRADECENTERFRONTADDRESS:
            {
            	this->processRspQryTradeCenterFrontAddress(&task);
            	break;
            }
            
            case ONRTNCOMMODITYINFO:
            {
            	this->processRtnCommodityInfo(&task);
            	break;
            }
            
            case ONRTNCURRENCYINFO:
            {
            	this->processRtnCurrencyInfo(&task);
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
            
            case ONRSPQRYSPOTLOCK:
            {
            	this->processRspQrySpotLock(&task);
            	break;
            }
            
            case ONRTNSPOTLOCK:
            {
            	this->processRtnSpotLock(&task);
            	break;
            }
            
            case ONRSPSPECIALORDERACTION:
            {
            	this->processRspSpecialOrderAction(&task);
            	break;
            }
            
            case ONRTNSPECIALORDER:
            {
            	this->processRtnSpecialOrder(&task);
            	break;
            }
            
            case ONRTNCOMBINEPOSITION:
            {
            	this->processRtnCombinePosition(&task);
            	break;
            }
            
            case ONRTNCONTRACTQUOTE:
            {
            	this->processRtnContractQuote(&task);
            	break;
            }
            
            case ONRSPQRYTRUSTDEVICE:
            {
            	this->processRspQryTrustDevice(&task);
            	break;
            }
            
            case ONRSPADDTRUSTDEVICE:
            {
            	this->processRspAddTrustDevice(&task);
            	break;
            }
            
            case ONRSPDELTRUSTDEVICE:
            {
            	this->processRspDelTrustDevice(&task);
            	break;
            }
            
            case ONRTNADDUSERRIGHT:
            {
            	this->processRtnAddUserRight(&task);
            	break;
            }
            
            case ONRTNDELUSERRIGHT:
            {
            	this->processRtnDelUserRight(&task);
            	break;
            }
            
            case ONRSPQRYMANAGERCONFIGFILE:
            {
            	this->processRspQryManagerConfigFile(&task);
            	break;
            }


			};
		}
	}
	catch (const TerminatedError&)
	{
	}
};

void TdApi::processConnect(Task *task)
{
	gil_scoped_acquire acquire;
	this->onConnect(task->task_string);
};

void TdApi::processRspLogin(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		TapAPITradeLoginRspInfo *task_data = (TapAPITradeLoginRspInfo*)task->task_data;
		data["UserNo"] = toUtf(task_data->UserNo);
		data["UserType"] = task_data->UserType;
		data["UserName"] = toUtf(task_data->UserName);
		data["QuoteTempPassword"] = toUtf(task_data->QuoteTempPassword);
		data["ReservedInfo"] = toUtf(task_data->ReservedInfo);
		data["LastLoginIP"] = toUtf(task_data->LastLoginIP);
		data["LastLoginPort"] = task_data->LastLoginPort;
		data["LastLoginTime"] = toUtf(task_data->LastLoginTime);
		data["LastLogoutTime"] = toUtf(task_data->LastLogoutTime);
		data["TradeDate"] = toUtf(task_data->TradeDate);
		data["LastSettleTime"] = toUtf(task_data->LastSettleTime);
		data["StartTime"] = toUtf(task_data->StartTime);
		data["InitTime"] = toUtf(task_data->InitTime);
		data["AuthType"] = task_data->AuthType;
		data["AuthDate"] = toUtf(task_data->AuthDate);
		data["UdpCertCode"] = task_data->UdpCertCode;
		data["CurrentLoginIP"] = toUtf(task_data->CurrentLoginIP);
		data["CurrentLoginPort"] = task_data->CurrentLoginPort;
		delete task_data;
	}
	this->onRspLogin(task->task_string, task->task_int, data);
};

void TdApi::processRtnContactInfo(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		TapAPISecondInfo *task_data = (TapAPISecondInfo*)task->task_data;
		data["SendType"] = task_data->SendType;
		data["SendAccount"] = toUtf(task_data->SendAccount);
		delete task_data;
	}
	this->onRtnContactInfo(task->task_string, task->task_int, task->task_last, data);
};

void TdApi::processRspRequestVertificateCode(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		TapAPIVertificateCode *task_data = (TapAPIVertificateCode*)task->task_data;
		data["SecondSerialID"] = toUtf(task_data->SecondSerialID);
		data["Effective"] = task_data->Effective;
		delete task_data;
	}
	this->onRspRequestVertificateCode(task->task_string, task->task_id, task->task_int, task->task_last, data);
};

void TdApi::processRspRequestVerifyIdentity(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		TapAPIVerifyIdentity *task_data = (TapAPIVerifyIdentity*)task->task_data;
		data["UserNo"] = toUtf(task_data->UserNo);
		data["CertificateType"] = task_data->CertificateType;
		data["CertificateNo"] = toUtf(task_data->CertificateNo);
		data["EMail"] = toUtf(task_data->EMail);
		data["PhoneNo"] = toUtf(task_data->PhoneNo);
		delete task_data;
	}
	this->onRspRequestVerifyIdentity(task->task_string, task->task_id, task->task_int, task->task_last, data);
};

void TdApi::processRspSetVertificateCode(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		TapAPISecondCertificationRsp *task_data = (TapAPISecondCertificationRsp*)task->task_data;
		data["PasswordType"] = task_data->PasswordType;
		data["VertificateCode"] = toUtf(task_data->VertificateCode);
		data["SecondDate"] = toUtf(task_data->SecondDate);
		delete task_data;
	}
	this->onRspSetVertificateCode(task->task_string, task->task_id, task->task_int, task->task_last, data);
};

void TdApi::processRtnErrorMsg(Task *task)
{
	gil_scoped_acquire acquire;
	this->onRtnErrorMsg(task->task_string, task->task_string);
};

void TdApi::processAPIReady(Task *task)
{
	gil_scoped_acquire acquire;
	this->onAPIReady(task->task_string);
};

void TdApi::processDisconnect(Task *task)
{
	gil_scoped_acquire acquire;
	this->onDisconnect(task->task_string, task->task_int);
};

void TdApi::processRspSubmitUserLoginInfo(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		TapAPISubmitUserLoginInfoRsp *task_data = (TapAPISubmitUserLoginInfoRsp*)task->task_data;
		data["UserNo"] = toUtf(task_data->UserNo);
		data["ErrorCode"] = task_data->ErrorCode;
		data["ErrorText"] = toUtf(task_data->ErrorText);
		delete task_data;
	}
	this->onRspSubmitUserLoginInfo(task->task_string, task->task_id, data);
};

void TdApi::processRspChangePassword(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		TapAPIChangePasswordRsp *task_data = (TapAPIChangePasswordRsp*)task->task_data;
		data["PasswordType"] = task_data->PasswordType;
		data["OldPassword"] = toUtf(task_data->OldPassword);
		data["NewPassword"] = toUtf(task_data->NewPassword);
		delete task_data;
	}
	this->onRspChangePassword(task->task_string, task->task_id, task->task_int, data);
};

void TdApi::processRspSetReservedInfo(Task *task)
{
	gil_scoped_acquire acquire;
	this->onRspSetReservedInfo(task->task_string, task->task_id, task->task_int, task->task_string);
};

void TdApi::processRtnContract(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		TapAPITradeContractInfo *task_data = (TapAPITradeContractInfo*)task->task_data;
		data["ExchangeNo"] = toUtf(task_data->ExchangeNo);
		data["CommodityType"] = task_data->CommodityType;
		data["CommodityNo"] = toUtf(task_data->CommodityNo);
		data["ContractNo1"] = toUtf(task_data->ContractNo1);
		data["StrikePrice1"] = toUtf(task_data->StrikePrice1);
		data["CallOrPutFlag1"] = task_data->CallOrPutFlag1;
		data["ContractNo2"] = toUtf(task_data->ContractNo2);
		data["StrikePrice2"] = toUtf(task_data->StrikePrice2);
		data["CallOrPutFlag2"] = task_data->CallOrPutFlag2;
		data["ContractExpDate"] = toUtf(task_data->ContractExpDate);
		data["LastTradeDate"] = toUtf(task_data->LastTradeDate);
		data["FirstNoticeDate"] = toUtf(task_data->FirstNoticeDate);
		delete task_data;
	}
	this->onRtnContract(task->task_string, data);
};

void TdApi::processRtnFund(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		TapAPIFundData *task_data = (TapAPIFundData*)task->task_data;
		data["AccountNo"] = toUtf(task_data->AccountNo);
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
		data["AccountInitialMargin"] = task_data->AccountInitialMargin;
		data["AccountMaintenanceMargin"] = task_data->AccountMaintenanceMargin;
		data["UpperInitialMargin"] = task_data->UpperInitialMargin;
		data["UpperMaintenanceMargin"] = task_data->UpperMaintenanceMargin;
		data["Discount"] = task_data->Discount;
		data["Balance"] = task_data->Balance;
		data["Equity"] = task_data->Equity;
		data["Available"] = task_data->Available;
		data["CanDraw"] = task_data->CanDraw;
		data["MarketEquity"] = task_data->MarketEquity;
		data["AuthMoney"] = task_data->AuthMoney;
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
		data["RiskRate"] = task_data->RiskRate;
		delete task_data;
	}
	this->onRtnFund(task->task_string, data);
};

void TdApi::processRtnOrder(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		TapAPIOrderInfo *task_data = (TapAPIOrderInfo*)task->task_data;
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
		data["HedgeFlag2"] = task_data->HedgeFlag2;
		data["OrderPrice"] = task_data->OrderPrice;
		data["OrderPrice2"] = task_data->OrderPrice2;
		data["StopPrice"] = task_data->StopPrice;
		data["OrderQty"] = task_data->OrderQty;
		data["OrderQty2"] = task_data->OrderQty2;
		data["OrderMinQty"] = task_data->OrderMinQty;
		data["MinClipSize"] = task_data->MinClipSize;
		data["MaxClipSize"] = task_data->MaxClipSize;
		data["RefInt"] = task_data->RefInt;
		data["RefDouble"] = task_data->RefDouble;
		data["RefString"] = toUtf(task_data->RefString);
		data["TacticsType"] = task_data->TacticsType;
		data["TriggerCondition"] = task_data->TriggerCondition;
		data["TriggerPriceType"] = task_data->TriggerPriceType;
		data["AddOneIsValid"] = task_data->AddOneIsValid;
		data["MarketLevel"] = task_data->MarketLevel;
		data["FutureAutoCloseFlag"] = task_data->FutureAutoCloseFlag;
		data["OrderCanceledQty"] = task_data->OrderCanceledQty;
		data["LicenseNo"] = toUtf(task_data->LicenseNo);
		data["ParentAccountNo"] = toUtf(task_data->ParentAccountNo);
		data["ServerFlag"] = task_data->ServerFlag;
		data["OrderNo"] = toUtf(task_data->OrderNo);
		data["ClientOrderNo"] = toUtf(task_data->ClientOrderNo);
		data["OrderLocalNo"] = toUtf(task_data->OrderLocalNo);
		data["OrderSystemNo"] = toUtf(task_data->OrderSystemNo);
		data["OrderExchangeSystemNo"] = toUtf(task_data->OrderExchangeSystemNo);
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
		data["ClientID"] = toUtf(task_data->ClientID);
		data["FeeValue"] = task_data->FeeValue;
		data["MarginValue"] = task_data->MarginValue;
		data["OrderParentSystemNo"] = toUtf(task_data->OrderParentSystemNo);
		delete task_data;
	}
	this->onRtnOrder(task->task_string, task->task_id, data);
};

void TdApi::processRspOrderAction(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		TapAPIOrderActionRsp *task_data = (TapAPIOrderActionRsp*)task->task_data;
		data["ActionType"] = task_data->ActionType;
		data["AccountNo"] = toUtf(task_data->OrderInfo.AccountNo);
		data["ExchangeNo"] = toUtf(task_data->OrderInfo.ExchangeNo);
		data["CommodityType"] = task_data->OrderInfo.CommodityType;
		data["CommodityNo"] = toUtf(task_data->OrderInfo.CommodityNo);
		data["ContractNo"] = toUtf(task_data->OrderInfo.ContractNo);
		data["StrikePrice"] = toUtf(task_data->OrderInfo.StrikePrice);
		data["CallOrPutFlag"] = task_data->OrderInfo.CallOrPutFlag;
		data["ContractNo2"] = toUtf(task_data->OrderInfo.ContractNo2);
		data["StrikePrice2"] = toUtf(task_data->OrderInfo.StrikePrice2);
		data["CallOrPutFlag2"] = task_data->OrderInfo.CallOrPutFlag2;
		data["OrderType"] = task_data->OrderInfo.OrderType;
		data["OrderSource"] = task_data->OrderInfo.OrderSource;
		data["TimeInForce"] = task_data->OrderInfo.TimeInForce;
		data["ExpireTime"] = toUtf(task_data->OrderInfo.ExpireTime);
		data["IsRiskOrder"] = task_data->OrderInfo.IsRiskOrder;
		data["OrderSide"] = task_data->OrderInfo.OrderSide;
		data["PositionEffect"] = task_data->OrderInfo.PositionEffect;
		data["PositionEffect2"] = task_data->OrderInfo.PositionEffect2;
		data["InquiryNo"] = toUtf(task_data->OrderInfo.InquiryNo);
		data["HedgeFlag"] = task_data->OrderInfo.HedgeFlag;
		data["HedgeFlag2"] = task_data->OrderInfo.HedgeFlag2;
		data["OrderPrice"] = task_data->OrderInfo.OrderPrice;
		data["OrderPrice2"] = task_data->OrderInfo.OrderPrice2;
		data["StopPrice"] = task_data->OrderInfo.StopPrice;
		data["OrderQty"] = task_data->OrderInfo.OrderQty;
		data["OrderQty2"] = task_data->OrderInfo.OrderQty2;
		data["OrderMinQty"] = task_data->OrderInfo.OrderMinQty;
		data["MinClipSize"] = task_data->OrderInfo.MinClipSize;
		data["MaxClipSize"] = task_data->OrderInfo.MaxClipSize;
		data["RefInt"] = task_data->OrderInfo.RefInt;
		data["RefDouble"] = task_data->OrderInfo.RefDouble;
		data["RefString"] = toUtf(task_data->OrderInfo.RefString);
		data["TacticsType"] = task_data->OrderInfo.TacticsType;
		data["TriggerCondition"] = task_data->OrderInfo.TriggerCondition;
		data["TriggerPriceType"] = task_data->OrderInfo.TriggerPriceType;
		data["AddOneIsValid"] = task_data->OrderInfo.AddOneIsValid;
		data["MarketLevel"] = task_data->OrderInfo.MarketLevel;
		data["FutureAutoCloseFlag"] = task_data->OrderInfo.FutureAutoCloseFlag;
		data["OrderCanceledQty"] = task_data->OrderInfo.OrderCanceledQty;
		data["LicenseNo"] = toUtf(task_data->OrderInfo.LicenseNo);
		data["ParentAccountNo"] = toUtf(task_data->OrderInfo.ParentAccountNo);
		data["ServerFlag"] = task_data->OrderInfo.ServerFlag;
		data["OrderNo"] = toUtf(task_data->OrderInfo.OrderNo);
		data["ClientOrderNo"] = toUtf(task_data->OrderInfo.ClientOrderNo);
		data["OrderLocalNo"] = toUtf(task_data->OrderInfo.OrderLocalNo);
		data["OrderSystemNo"] = toUtf(task_data->OrderInfo.OrderSystemNo);
		data["OrderExchangeSystemNo"] = toUtf(task_data->OrderInfo.OrderExchangeSystemNo);
		data["TradeNo"] = toUtf(task_data->OrderInfo.TradeNo);
		data["UpperNo"] = toUtf(task_data->OrderInfo.UpperNo);
		data["UpperChannelNo"] = toUtf(task_data->OrderInfo.UpperChannelNo);
		data["UpperSettleNo"] = toUtf(task_data->OrderInfo.UpperSettleNo);
		data["UpperUserNo"] = toUtf(task_data->OrderInfo.UpperUserNo);
		data["OrderInsertUserNo"] = toUtf(task_data->OrderInfo.OrderInsertUserNo);
		data["OrderInsertTime"] = toUtf(task_data->OrderInfo.OrderInsertTime);
		data["OrderCommandUserNo"] = toUtf(task_data->OrderInfo.OrderCommandUserNo);
		data["OrderUpdateUserNo"] = toUtf(task_data->OrderInfo.OrderUpdateUserNo);
		data["OrderUpdateTime"] = toUtf(task_data->OrderInfo.OrderUpdateTime);
		data["OrderState"] = task_data->OrderInfo.OrderState;
		data["OrderMatchPrice"] = task_data->OrderInfo.OrderMatchPrice;
		data["OrderMatchPrice2"] = task_data->OrderInfo.OrderMatchPrice2;
		data["OrderMatchQty"] = task_data->OrderInfo.OrderMatchQty;
		data["OrderMatchQty2"] = task_data->OrderInfo.OrderMatchQty2;
		data["ErrorCode"] = task_data->OrderInfo.ErrorCode;
		data["ErrorText"] = toUtf(task_data->OrderInfo.ErrorText);
		data["IsBackInput"] = task_data->OrderInfo.IsBackInput;
		data["IsDeleted"] = task_data->OrderInfo.IsDeleted;
		data["IsAddOne"] = task_data->OrderInfo.IsAddOne;
		data["OrderStreamID"] = task_data->OrderInfo.OrderStreamID;
		data["UpperStreamID"] = task_data->OrderInfo.UpperStreamID;
		data["ClientID"] = toUtf(task_data->OrderInfo.ClientID);
		data["FeeValue"] = task_data->OrderInfo.FeeValue;
		data["MarginValue"] = task_data->OrderInfo.MarginValue;
		data["OrderParentSystemNo"] = toUtf(task_data->OrderInfo.OrderParentSystemNo);
		delete task_data;
	}
	this->onRspOrderAction(task->task_string, task->task_id, task->task_int, data);
};

void TdApi::processRspQryOrderProcess(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		TapAPIOrderInfo *task_data = (TapAPIOrderInfo*)task->task_data;
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
		data["HedgeFlag2"] = task_data->HedgeFlag2;
		data["OrderPrice"] = task_data->OrderPrice;
		data["OrderPrice2"] = task_data->OrderPrice2;
		data["StopPrice"] = task_data->StopPrice;
		data["OrderQty"] = task_data->OrderQty;
		data["OrderQty2"] = task_data->OrderQty2;
		data["OrderMinQty"] = task_data->OrderMinQty;
		data["MinClipSize"] = task_data->MinClipSize;
		data["MaxClipSize"] = task_data->MaxClipSize;
		data["RefInt"] = task_data->RefInt;
		data["RefDouble"] = task_data->RefDouble;
		data["RefString"] = toUtf(task_data->RefString);
		data["TacticsType"] = task_data->TacticsType;
		data["TriggerCondition"] = task_data->TriggerCondition;
		data["TriggerPriceType"] = task_data->TriggerPriceType;
		data["AddOneIsValid"] = task_data->AddOneIsValid;
		data["MarketLevel"] = task_data->MarketLevel;
		data["FutureAutoCloseFlag"] = task_data->FutureAutoCloseFlag;
		data["OrderCanceledQty"] = task_data->OrderCanceledQty;
		data["LicenseNo"] = toUtf(task_data->LicenseNo);
		data["ParentAccountNo"] = toUtf(task_data->ParentAccountNo);
		data["ServerFlag"] = task_data->ServerFlag;
		data["OrderNo"] = toUtf(task_data->OrderNo);
		data["ClientOrderNo"] = toUtf(task_data->ClientOrderNo);
		data["OrderLocalNo"] = toUtf(task_data->OrderLocalNo);
		data["OrderSystemNo"] = toUtf(task_data->OrderSystemNo);
		data["OrderExchangeSystemNo"] = toUtf(task_data->OrderExchangeSystemNo);
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
		data["ClientID"] = toUtf(task_data->ClientID);
		data["FeeValue"] = task_data->FeeValue;
		data["MarginValue"] = task_data->MarginValue;
		data["OrderParentSystemNo"] = toUtf(task_data->OrderParentSystemNo);
		delete task_data;
	}
	this->onRspQryOrderProcess(task->task_string, task->task_id, task->task_int, task->task_last, data);
};

void TdApi::processRtnFill(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		TapAPIFillInfo *task_data = (TapAPIFillInfo*)task->task_data;
		data["AccountNo"] = toUtf(task_data->AccountNo);
		data["ExchangeNo"] = toUtf(task_data->ExchangeNo);
		data["CommodityType"] = task_data->CommodityType;
		data["CommodityNo"] = toUtf(task_data->CommodityNo);
		data["ContractNo"] = toUtf(task_data->ContractNo);
		data["StrikePrice"] = toUtf(task_data->StrikePrice);
		data["CallOrPutFlag"] = task_data->CallOrPutFlag;
		data["OrderType"] = task_data->OrderType;
		data["MatchSource"] = task_data->MatchSource;
		data["TimeInForce"] = task_data->TimeInForce;
		data["ExpireTime"] = toUtf(task_data->ExpireTime);
		data["IsRiskOrder"] = task_data->IsRiskOrder;
		data["MatchSide"] = task_data->MatchSide;
		data["PositionEffect"] = task_data->PositionEffect;
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
		data["FeeCurrencyGroup"] = toUtf(task_data->FeeCurrencyGroup);
		data["FeeCurrency"] = toUtf(task_data->FeeCurrency);
		data["FeeValue"] = task_data->FeeValue;
		data["IsManualFee"] = task_data->IsManualFee;
		data["PremiumIncome"] = task_data->PremiumIncome;
		data["PremiumPay"] = task_data->PremiumPay;
		data["CloseProfit"] = task_data->CloseProfit;
		data["OrderSystemNo"] = toUtf(task_data->OrderSystemNo);
		data["UpperMatchNo"] = toUtf(task_data->UpperMatchNo);
		data["ClosePositionPrice"] = task_data->ClosePositionPrice;
		delete task_data;
	}
	this->onRtnFill(task->task_string, data);
};

void TdApi::processRtnPosition(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		TapAPIPositionInfo *task_data = (TapAPIPositionInfo*)task->task_data;
		data["AccountNo"] = toUtf(task_data->AccountNo);
		data["ExchangeNo"] = toUtf(task_data->ExchangeNo);
		data["CommodityType"] = task_data->CommodityType;
		data["CommodityNo"] = toUtf(task_data->CommodityNo);
		data["ContractNo"] = toUtf(task_data->ContractNo);
		data["StrikePrice"] = toUtf(task_data->StrikePrice);
		data["CallOrPutFlag"] = task_data->CallOrPutFlag;
		data["MatchSide"] = task_data->MatchSide;
		data["HedgeFlag"] = task_data->HedgeFlag;
		data["PositionNo"] = toUtf(task_data->PositionNo);
		data["ServerFlag"] = task_data->ServerFlag;
		data["OrderNo"] = toUtf(task_data->OrderNo);
		data["MatchNo"] = toUtf(task_data->MatchNo);
		data["ExchangeMatchNo"] = toUtf(task_data->ExchangeMatchNo);
		data["MatchSource"] = task_data->MatchSource;
		data["MatchDate"] = toUtf(task_data->MatchDate);
		data["MatchTime"] = toUtf(task_data->MatchTime);
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
		data["ContractSize"] = task_data->ContractSize;
		data["CommodityCurrencyGroup"] = toUtf(task_data->CommodityCurrencyGroup);
		data["CommodityCurrency"] = toUtf(task_data->CommodityCurrency);
		data["PreSettlePrice"] = task_data->PreSettlePrice;
		data["SettlePrice"] = task_data->SettlePrice;
		data["Turnover"] = task_data->Turnover;
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
		data["CalculatePrice"] = task_data->CalculatePrice;
		delete task_data;
	}
	this->onRtnPosition(task->task_string, data);
};

void TdApi::processRtnClose(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		TapAPICloseInfo *task_data = (TapAPICloseInfo*)task->task_data;
		data["AccountNo"] = toUtf(task_data->AccountNo);
		data["ExchangeNo"] = toUtf(task_data->ExchangeNo);
		data["CommodityType"] = task_data->CommodityType;
		data["CommodityNo"] = toUtf(task_data->CommodityNo);
		data["ContractNo"] = toUtf(task_data->ContractNo);
		data["StrikePrice"] = toUtf(task_data->StrikePrice);
		data["CallOrPutFlag"] = task_data->CallOrPutFlag;
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
		data["ContractSize"] = task_data->ContractSize;
		data["PreSettlePrice"] = task_data->PreSettlePrice;
		data["CloseProfit"] = task_data->CloseProfit;
		data["UnExpProfit"] = task_data->UnExpProfit;
		data["ClosePL"] = task_data->ClosePL;
		delete task_data;
	}
	this->onRtnClose(task->task_string, data);
};

void TdApi::processRtnPositionProfit(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		TapAPIPositionProfitNotice *task_data = (TapAPIPositionProfitNotice*)task->task_data;
		data["IsLast"] = task_data->IsLast;
		//data["Data"] = task_data->Data;
		delete task_data;
	}
	this->onRtnPositionProfit(task->task_string, data);
};

void TdApi::processRspQryDeepQuote(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		TapAPIDeepQuoteQryRsp *task_data = (TapAPIDeepQuoteQryRsp*)task->task_data;
		//data["Contract"] = task_data->Contract;
		//data["DeepQuote"] = task_data->DeepQuote;
		delete task_data;
	}
	this->onRspQryDeepQuote(task->task_string, task->task_id, task->task_int, task->task_last, data);
};

void TdApi::processRtnExchangeStateInfo(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		TapAPIExchangeStateInfoNotice *task_data = (TapAPIExchangeStateInfoNotice*)task->task_data;
		data["IsLast"] = task_data->IsLast;
		data["UpperChannelNo"] = toUtf(task_data->ExchangeStateInfo.UpperChannelNo);
		data["ExchangeNo"] = toUtf(task_data->ExchangeStateInfo.ExchangeNo);
		data["CommodityType"] = task_data->ExchangeStateInfo.CommodityType;
		data["CommodityNo"] = toUtf(task_data->ExchangeStateInfo.CommodityNo);
		data["ExchangeTime"] = toUtf(task_data->ExchangeStateInfo.ExchangeTime);
		data["TradingState"] = task_data->ExchangeStateInfo.TradingState;
		delete task_data;
	}
	this->onRtnExchangeStateInfo(task->task_string, data);
};

void TdApi::processRtnReqQuoteNotice(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		TapAPIReqQuoteNotice *task_data = (TapAPIReqQuoteNotice*)task->task_data;
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
	this->onRtnReqQuoteNotice(task->task_string, data);
};

void TdApi::processRspAccountRentInfo(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		TapAPIAccountRentInfo *task_data = (TapAPIAccountRentInfo*)task->task_data;
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
	this->onRspAccountRentInfo(task->task_string, task->task_id, task->task_int, task->task_last, data);
};

void TdApi::processRspTradeMessage(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		TapAPITradeMessage *task_data = (TapAPITradeMessage*)task->task_data;
		data["SerialID"] = task_data->SerialID;
		data["AccountNo"] = toUtf(task_data->AccountNo);
		data["TMsgValidDateTime"] = toUtf(task_data->TMsgValidDateTime);
		data["TMsgTitle"] = toUtf(task_data->TMsgTitle);
		data["TMsgContent"] = toUtf(task_data->TMsgContent);
		data["TMsgType"] = task_data->TMsgType;
		data["TMsgLevel"] = task_data->TMsgLevel;
		data["IsSendBySMS"] = task_data->IsSendBySMS;
		data["IsSendByEMail"] = task_data->IsSendByEMail;
		data["Sender"] = toUtf(task_data->Sender);
		data["SendDateTime"] = toUtf(task_data->SendDateTime);
		delete task_data;
	}
	this->onRspTradeMessage(task->task_string, task->task_id, task->task_int, task->task_last, data);
};

void TdApi::processRtnTradeMessage(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		TapAPITradeMessage *task_data = (TapAPITradeMessage*)task->task_data;
		data["SerialID"] = task_data->SerialID;
		data["AccountNo"] = toUtf(task_data->AccountNo);
		data["TMsgValidDateTime"] = toUtf(task_data->TMsgValidDateTime);
		data["TMsgTitle"] = toUtf(task_data->TMsgTitle);
		data["TMsgContent"] = toUtf(task_data->TMsgContent);
		data["TMsgType"] = task_data->TMsgType;
		data["TMsgLevel"] = task_data->TMsgLevel;
		data["IsSendBySMS"] = task_data->IsSendBySMS;
		data["IsSendByEMail"] = task_data->IsSendByEMail;
		data["Sender"] = toUtf(task_data->Sender);
		data["SendDateTime"] = toUtf(task_data->SendDateTime);
		delete task_data;
	}
	this->onRtnTradeMessage(task->task_string, data);
};

void TdApi::processRspQryHisOrder(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		TapAPIHisOrderQryRsp *task_data = (TapAPIHisOrderQryRsp*)task->task_data;
		data["Date"] = toUtf(task_data->Date);
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
		data["RefInt"] = task_data->RefInt;
		data["RefDouble"] = task_data->RefDouble;
		data["RefString"] = toUtf(task_data->RefString);
		data["ServerFlag"] = task_data->ServerFlag;
		data["OrderNo"] = toUtf(task_data->OrderNo);
		data["OrderStreamID"] = task_data->OrderStreamID;
		data["UpperNo"] = toUtf(task_data->UpperNo);
		data["UpperChannelNo"] = toUtf(task_data->UpperChannelNo);
		data["OrderLocalNo"] = toUtf(task_data->OrderLocalNo);
		data["UpperStreamID"] = task_data->UpperStreamID;
		data["OrderSystemNo"] = toUtf(task_data->OrderSystemNo);
		data["OrderExchangeSystemNo"] = toUtf(task_data->OrderExchangeSystemNo);
		data["OrderParentSystemNo"] = toUtf(task_data->OrderParentSystemNo);
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
		data["AddOneIsValid"] = task_data->AddOneIsValid;
		data["MinClipSize"] = task_data->MinClipSize;
		data["MaxClipSize"] = task_data->MaxClipSize;
		data["LicenseNo"] = toUtf(task_data->LicenseNo);
		data["TacticsType"] = task_data->TacticsType;
		data["TriggerCondition"] = task_data->TriggerCondition;
		data["TriggerPriceType"] = task_data->TriggerPriceType;
		delete task_data;
	}
	this->onRspQryHisOrder(task->task_string, task->task_id, task->task_int, task->task_last, data);
};

void TdApi::processRspQryHisOrderProcess(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		TapAPIHisOrderProcessQryRsp *task_data = (TapAPIHisOrderProcessQryRsp*)task->task_data;
		data["Date"] = toUtf(task_data->Date);
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
		data["RefInt"] = task_data->RefInt;
		data["RefDouble"] = task_data->RefDouble;
		data["RefString"] = toUtf(task_data->RefString);
		data["ServerFlag"] = task_data->ServerFlag;
		data["OrderNo"] = toUtf(task_data->OrderNo);
		data["OrderStreamID"] = task_data->OrderStreamID;
		data["UpperNo"] = toUtf(task_data->UpperNo);
		data["UpperChannelNo"] = toUtf(task_data->UpperChannelNo);
		data["OrderLocalNo"] = toUtf(task_data->OrderLocalNo);
		data["UpperStreamID"] = task_data->UpperStreamID;
		data["OrderSystemNo"] = toUtf(task_data->OrderSystemNo);
		data["OrderExchangeSystemNo"] = toUtf(task_data->OrderExchangeSystemNo);
		data["OrderParentSystemNo"] = toUtf(task_data->OrderParentSystemNo);
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
		data["AddOneIsValid"] = task_data->AddOneIsValid;
		data["MinClipSize"] = task_data->MinClipSize;
		data["MaxClipSize"] = task_data->MaxClipSize;
		data["LicenseNo"] = toUtf(task_data->LicenseNo);
		data["TacticsType"] = task_data->TacticsType;
		data["TriggerCondition"] = task_data->TriggerCondition;
		data["TriggerPriceType"] = task_data->TriggerPriceType;
		delete task_data;
	}
	this->onRspQryHisOrderProcess(task->task_string, task->task_id, task->task_int, task->task_last, data);
};

void TdApi::processRspQryHisFill(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		TapAPIHisFillQryRsp *task_data = (TapAPIHisFillQryRsp*)task->task_data;
		data["SettleDate"] = toUtf(task_data->SettleDate);
		data["TradeDate"] = toUtf(task_data->TradeDate);
		data["AccountNo"] = toUtf(task_data->AccountNo);
		data["ExchangeNo"] = toUtf(task_data->ExchangeNo);
		data["CommodityType"] = task_data->CommodityType;
		data["CommodityNo"] = toUtf(task_data->CommodityNo);
		data["ContractNo"] = toUtf(task_data->ContractNo);
		data["StrikePrice"] = toUtf(task_data->StrikePrice);
		data["CallOrPutFlag"] = task_data->CallOrPutFlag;
		data["MatchSource"] = task_data->MatchSource;
		data["MatchSide"] = task_data->MatchSide;
		data["PositionEffect"] = task_data->PositionEffect;
		data["HedgeFlag"] = task_data->HedgeFlag;
		data["MatchPrice"] = task_data->MatchPrice;
		data["MatchQty"] = task_data->MatchQty;
		data["OrderNo"] = toUtf(task_data->OrderNo);
		data["MatchNo"] = toUtf(task_data->MatchNo);
		data["MatchStreamID"] = task_data->MatchStreamID;
		data["UpperNo"] = toUtf(task_data->UpperNo);
		data["MatchCmbNo"] = toUtf(task_data->MatchCmbNo);
		data["ExchangeMatchNo"] = toUtf(task_data->ExchangeMatchNo);
		data["MatchUpperStreamID"] = task_data->MatchUpperStreamID;
		data["CommodityCurrencyGroup"] = toUtf(task_data->CommodityCurrencyGroup);
		data["CommodityCurrency"] = toUtf(task_data->CommodityCurrency);
		data["Turnover"] = task_data->Turnover;
		data["PremiumIncome"] = task_data->PremiumIncome;
		data["PremiumPay"] = task_data->PremiumPay;
		data["AccountFee"] = task_data->AccountFee;
		data["AccountFeeCurrencyGroup"] = toUtf(task_data->AccountFeeCurrencyGroup);
		data["AccountFeeCurrency"] = toUtf(task_data->AccountFeeCurrency);
		data["IsManualFee"] = task_data->IsManualFee;
		data["AccountOtherFee"] = task_data->AccountOtherFee;
		data["UpperFee"] = task_data->UpperFee;
		data["UpperFeeCurrencyGroup"] = toUtf(task_data->UpperFeeCurrencyGroup);
		data["UpperFeeCurrency"] = toUtf(task_data->UpperFeeCurrency);
		data["IsUpperManualFee"] = task_data->IsUpperManualFee;
		data["UpperOtherFee"] = task_data->UpperOtherFee;
		data["MatchDateTime"] = toUtf(task_data->MatchDateTime);
		data["UpperMatchDateTime"] = toUtf(task_data->UpperMatchDateTime);
		data["CloseProfit"] = task_data->CloseProfit;
		data["ClosePrice"] = task_data->ClosePrice;
		data["CloseQty"] = task_data->CloseQty;
		data["SettleGroupNo"] = toUtf(task_data->SettleGroupNo);
		data["OperatorNo"] = toUtf(task_data->OperatorNo);
		data["OperateTime"] = toUtf(task_data->OperateTime);
		delete task_data;
	}
	this->onRspQryHisFill(task->task_string, task->task_id, task->task_int, task->task_last, data);
};

void TdApi::processRspQryHisPosition(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		TapAPIHisPositionQryRsp *task_data = (TapAPIHisPositionQryRsp*)task->task_data;
		data["SettleDate"] = toUtf(task_data->SettleDate);
		data["OpenDate"] = toUtf(task_data->OpenDate);
		data["AccountNo"] = toUtf(task_data->AccountNo);
		data["ExchangeNo"] = toUtf(task_data->ExchangeNo);
		data["CommodityType"] = task_data->CommodityType;
		data["CommodityNo"] = toUtf(task_data->CommodityNo);
		data["ContractNo"] = toUtf(task_data->ContractNo);
		data["StrikePrice"] = toUtf(task_data->StrikePrice);
		data["CallOrPutFlag"] = task_data->CallOrPutFlag;
		data["MatchSide"] = task_data->MatchSide;
		data["HedgeFlag"] = task_data->HedgeFlag;
		data["PositionPrice"] = task_data->PositionPrice;
		data["PositionQty"] = task_data->PositionQty;
		data["OrderNo"] = toUtf(task_data->OrderNo);
		data["PositionNo"] = toUtf(task_data->PositionNo);
		data["UpperNo"] = toUtf(task_data->UpperNo);
		data["CurrencyGroup"] = toUtf(task_data->CurrencyGroup);
		data["Currency"] = toUtf(task_data->Currency);
		data["PreSettlePrice"] = task_data->PreSettlePrice;
		data["SettlePrice"] = task_data->SettlePrice;
		data["PositionDProfit"] = task_data->PositionDProfit;
		data["LMEPositionProfit"] = task_data->LMEPositionProfit;
		data["OptionMarketValue"] = task_data->OptionMarketValue;
		data["AccountInitialMargin"] = task_data->AccountInitialMargin;
		data["AccountMaintenanceMargin"] = task_data->AccountMaintenanceMargin;
		data["UpperInitialMargin"] = task_data->UpperInitialMargin;
		data["UpperMaintenanceMargin"] = task_data->UpperMaintenanceMargin;
		data["SettleGroupNo"] = toUtf(task_data->SettleGroupNo);
		delete task_data;
	}
	this->onRspQryHisPosition(task->task_string, task->task_id, task->task_int, task->task_last, data);
};

void TdApi::processRspQryHisDelivery(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		TapAPIHisDeliveryQryRsp *task_data = (TapAPIHisDeliveryQryRsp*)task->task_data;
		data["DeliveryDate"] = toUtf(task_data->DeliveryDate);
		data["OpenDate"] = toUtf(task_data->OpenDate);
		data["AccountNo"] = toUtf(task_data->AccountNo);
		data["ExchangeNo"] = toUtf(task_data->ExchangeNo);
		data["CommodityType"] = task_data->CommodityType;
		data["CommodityNo"] = toUtf(task_data->CommodityNo);
		data["ContractNo"] = toUtf(task_data->ContractNo);
		data["StrikePrice"] = toUtf(task_data->StrikePrice);
		data["CallOrPutFlag"] = task_data->CallOrPutFlag;
		data["MatchSource"] = task_data->MatchSource;
		data["OpenSide"] = task_data->OpenSide;
		data["OpenPrice"] = task_data->OpenPrice;
		data["DeliveryPrice"] = task_data->DeliveryPrice;
		data["DeliveryQty"] = task_data->DeliveryQty;
		data["FrozenQty"] = task_data->FrozenQty;
		data["OpenNo"] = toUtf(task_data->OpenNo);
		data["UpperNo"] = toUtf(task_data->UpperNo);
		data["CommodityCurrencyGroupy"] = toUtf(task_data->CommodityCurrencyGroupy);
		data["CommodityCurrency"] = toUtf(task_data->CommodityCurrency);
		data["PreSettlePrice"] = task_data->PreSettlePrice;
		data["DeliveryProfit"] = task_data->DeliveryProfit;
		data["AccountFrozenInitialMargin"] = task_data->AccountFrozenInitialMargin;
		data["AccountFrozenMaintenanceMargin"] = task_data->AccountFrozenMaintenanceMargin;
		data["UpperFrozenInitialMargin"] = task_data->UpperFrozenInitialMargin;
		data["UpperFrozenMaintenanceMargin"] = task_data->UpperFrozenMaintenanceMargin;
		data["AccountFeeCurrencyGroup"] = toUtf(task_data->AccountFeeCurrencyGroup);
		data["AccountFeeCurrency"] = toUtf(task_data->AccountFeeCurrency);
		data["AccountDeliveryFee"] = task_data->AccountDeliveryFee;
		data["UpperFeeCurrencyGroup"] = toUtf(task_data->UpperFeeCurrencyGroup);
		data["UpperFeeCurrency"] = toUtf(task_data->UpperFeeCurrency);
		data["UpperDeliveryFee"] = task_data->UpperDeliveryFee;
		data["DeliveryMode"] = task_data->DeliveryMode;
		data["OperatorNo"] = toUtf(task_data->OperatorNo);
		data["OperateTime"] = toUtf(task_data->OperateTime);
		data["SettleGroupNo"] = toUtf(task_data->SettleGroupNo);
		delete task_data;
	}
	this->onRspQryHisDelivery(task->task_string, task->task_id, task->task_int, task->task_last, data);
};

void TdApi::processRspQryAccountCashAdjust(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		TapAPIAccountCashAdjustQryRsp *task_data = (TapAPIAccountCashAdjustQryRsp*)task->task_data;
		data["Date"] = toUtf(task_data->Date);
		data["AccountNo"] = toUtf(task_data->AccountNo);
		data["CashAdjustType"] = task_data->CashAdjustType;
		data["CurrencyGroupNo"] = toUtf(task_data->CurrencyGroupNo);
		data["CurrencyNo"] = toUtf(task_data->CurrencyNo);
		data["CashAdjustValue"] = task_data->CashAdjustValue;
		data["CashAdjustRemark"] = toUtf(task_data->CashAdjustRemark);
		data["OperateTime"] = toUtf(task_data->OperateTime);
		data["OperatorNo"] = toUtf(task_data->OperatorNo);
		data["AccountBank"] = toUtf(task_data->AccountBank);
		data["BankAccount"] = toUtf(task_data->BankAccount);
		data["AccountLWFlag"] = task_data->AccountLWFlag;
		data["CompanyBank"] = toUtf(task_data->CompanyBank);
		data["InternalBankAccount"] = toUtf(task_data->InternalBankAccount);
		data["CompanyLWFlag"] = task_data->CompanyLWFlag;
		delete task_data;
	}
	this->onRspQryAccountCashAdjust(task->task_string, task->task_id, task->task_int, task->task_last, data);
};

void TdApi::processRspQryBill(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		TapAPIBillQryRsp *task_data = (TapAPIBillQryRsp*)task->task_data;
		data["UserNo"] = toUtf(task_data->Reqdata.UserNo);
		data["BillType"] = task_data->Reqdata.BillType;
		data["BillDate"] = toUtf(task_data->Reqdata.BillDate);
		data["BillFileType"] = task_data->Reqdata.BillFileType;
		data["BillLen"] = task_data->BillLen;
		data["BillText"] = task_data->BillText;
		delete task_data;
	}
	this->onRspQryBill(task->task_string, task->task_id, task->task_int, task->task_last, data);
};

void TdApi::processRspAccountFeeRent(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		TapAPIAccountFeeRentQryRsp *task_data = (TapAPIAccountFeeRentQryRsp*)task->task_data;
		data["AccountNo"] = toUtf(task_data->AccountNo);
		data["ExchangeNo"] = toUtf(task_data->ExchangeNo);
		data["CommodityType"] = task_data->CommodityType;
		data["CommodityNo"] = toUtf(task_data->CommodityNo);
		data["MatchSource"] = task_data->MatchSource;
		data["CalculateMode"] = task_data->CalculateMode;
		data["CurrencyGroupNo"] = toUtf(task_data->CurrencyGroupNo);
		data["CurrencyNo"] = toUtf(task_data->CurrencyNo);
		data["OpenCloseFee"] = task_data->OpenCloseFee;
		data["CloseTodayFee"] = task_data->CloseTodayFee;
		data["ContractNo"] = toUtf(task_data->ContractNo);
		delete task_data;
	}
	this->onRspAccountFeeRent(task->task_string, task->task_id, task->task_int, task->task_last, data);
};

void TdApi::processRspAccountMarginRent(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		TapAPIAccountMarginRentQryRsp *task_data = (TapAPIAccountMarginRentQryRsp*)task->task_data;
		data["AccountNo"] = toUtf(task_data->AccountNo);
		data["ExchangeNo"] = toUtf(task_data->ExchangeNo);
		data["CommodityType"] = task_data->CommodityType;
		data["CommodityNo"] = toUtf(task_data->CommodityNo);
		data["ContractNo"] = toUtf(task_data->ContractNo);
		data["StrikePrice"] = toUtf(task_data->StrikePrice);
		data["CallOrPutFlag"] = task_data->CallOrPutFlag;
		data["CalculateMode"] = task_data->CalculateMode;
		data["CurrencyGroupNo"] = toUtf(task_data->CurrencyGroupNo);
		data["CurrencyNo"] = toUtf(task_data->CurrencyNo);
		data["InitialMargin"] = task_data->InitialMargin;
		data["MaintenanceMargin"] = task_data->MaintenanceMargin;
		data["SellInitialMargin"] = task_data->SellInitialMargin;
		data["SellMaintenanceMargin"] = task_data->SellMaintenanceMargin;
		data["LockMargin"] = task_data->LockMargin;
		delete task_data;
	}
	this->onRspAccountMarginRent(task->task_string, task->task_id, task->task_int, task->task_last, data);
};

void TdApi::processRspAddMobileDevice(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		TapAPIMobileDeviceAddRsp *task_data = (TapAPIMobileDeviceAddRsp*)task->task_data;
		data["UserNo"] = toUtf(task_data->UserNo);
		data["AppKey"] = toUtf(task_data->AppKey);
		data["AppID"] = toUtf(task_data->AppID);
		data["MasterSecret"] = toUtf(task_data->MasterSecret);
		data["Cid"] = toUtf(task_data->Cid);
		data["CompanyNo"] = toUtf(task_data->CompanyNo);
		data["CompanyAddressNo"] = toUtf(task_data->CompanyAddressNo);
		data["DeviceType"] = task_data->DeviceType;
		delete task_data;
	}
	this->onRspAddMobileDevice(task->task_string, task->task_id, task->task_int, task->task_last, data);
};

void TdApi::processRspQryManageInfoForEStar(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		TapAPIManageInfo *task_data = (TapAPIManageInfo*)task->task_data;
		data["MsgID"] = task_data->MsgID;
		data["SendFrom"] = toUtf(task_data->SendFrom);
		data["SendManageType"] = task_data->SendManageType;
		data["AccountNo"] = toUtf(task_data->AccountNo);
		data["SendAccount"] = toUtf(task_data->SendAccount);
		data["Title"] = toUtf(task_data->Title);
		data["Content"] = toUtf(task_data->Content);
		data["Attachment"] = toUtf(task_data->Attachment);
		data["SendStatus"] = task_data->SendStatus;
		data["Remark"] = toUtf(task_data->Remark);
		data["GUID"] = toUtf(task_data->GUID);
		data["OperatorNo"] = toUtf(task_data->OperatorNo);
		data["OperateTime"] = toUtf(task_data->OperateTime);
		delete task_data;
	}
	this->onRspQryManageInfoForEStar(task->task_string, task->task_id, task->task_int, task->task_last, data);
};

void TdApi::processRspQrySystemParameter(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		TapAPISystemParameterInfo *task_data = (TapAPISystemParameterInfo*)task->task_data;
		data["ItemNo"] = toUtf(task_data->ItemNo);
		data["ExchangeNo"] = toUtf(task_data->ExchangeNo);
		data["CommodityNo"] = toUtf(task_data->CommodityNo);
		data["CommodityType"] = task_data->CommodityType;
		data["ItemValue"] = task_data->ItemValue;
		data["ItemValueStr"] = toUtf(task_data->ItemValueStr);
		data["ItemValueDouble"] = task_data->ItemValueDouble;
		delete task_data;
	}
	this->onRspQrySystemParameter(task->task_string, task->task_id, task->task_int, task->task_last, data);
};

void TdApi::processRspQryTradeCenterFrontAddress(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		TapAPITradeCenterFrontAddressInfo *task_data = (TapAPITradeCenterFrontAddressInfo*)task->task_data;
		data["FrontName"] = toUtf(task_data->FrontName);
		data["FrontAddress"] = toUtf(task_data->FrontAddress);
		data["FrontPort"] = toUtf(task_data->FrontPort);
		data["TradeCenter"] = task_data->TradeCenter;
		data["IsEnable"] = task_data->IsEnable;
		data["IsSSL"] = task_data->IsSSL;
		delete task_data;
	}
	this->onRspQryTradeCenterFrontAddress(task->task_string, task->task_id, task->task_int, task->task_last, data);
};

void TdApi::processRtnCommodityInfo(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		TapAPICommodityInfo *task_data = (TapAPICommodityInfo*)task->task_data;
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
		data["ContractSize"] = task_data->ContractSize;
		data["OpenCloseMode"] = task_data->OpenCloseMode;
		data["StrikePriceTimes"] = task_data->StrikePriceTimes;
		data["CommodityTickSize"] = task_data->CommodityTickSize;
		data["CommodityDenominator"] = task_data->CommodityDenominator;
		data["CmbDirect"] = task_data->CmbDirect;
		data["OnlyCanCloseDays"] = task_data->OnlyCanCloseDays;
		data["DeliveryMode"] = task_data->DeliveryMode;
		data["DeliveryDays"] = task_data->DeliveryDays;
		data["AddOneTime"] = toUtf(task_data->AddOneTime);
		data["CommodityTimeZone"] = task_data->CommodityTimeZone;
		data["IsAddOne"] = task_data->IsAddOne;
		delete task_data;
	}
	this->onRtnCommodityInfo(task->task_string, data);
};

void TdApi::processRtnCurrencyInfo(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		TapAPICurrencyInfo *task_data = (TapAPICurrencyInfo*)task->task_data;
		data["CurrencyNo"] = toUtf(task_data->CurrencyNo);
		data["CurrencyGroupNo"] = toUtf(task_data->CurrencyGroupNo);
		data["TradeRate"] = task_data->TradeRate;
		data["TradeRate2"] = task_data->TradeRate2;
		data["FutureAlg"] = task_data->FutureAlg;
		data["OptionAlg"] = task_data->OptionAlg;
		delete task_data;
	}
	this->onRtnCurrencyInfo(task->task_string, data);
};

void TdApi::processRspQryAccountStorage(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		TapAPIAccountStorageInfo *task_data = (TapAPIAccountStorageInfo*)task->task_data;
		data["AccountNo"] = toUtf(task_data->AccountNo);
		data["ExchangeNo"] = toUtf(task_data->ExchangeNo);
		data["CommodityType"] = task_data->CommodityType;
		data["CommodityNo"] = toUtf(task_data->CommodityNo);
		data["StorageQty"] = task_data->StorageQty;
		delete task_data;
	}
	this->onRspQryAccountStorage(task->task_string, task->task_id, task->task_int, task->task_last, data);
};

void TdApi::processRtnAccountStorage(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		TapAPIAccountStorageInfo *task_data = (TapAPIAccountStorageInfo*)task->task_data;
		data["AccountNo"] = toUtf(task_data->AccountNo);
		data["ExchangeNo"] = toUtf(task_data->ExchangeNo);
		data["CommodityType"] = task_data->CommodityType;
		data["CommodityNo"] = toUtf(task_data->CommodityNo);
		data["StorageQty"] = task_data->StorageQty;
		delete task_data;
	}
	this->onRtnAccountStorage(task->task_string, data);
};

void TdApi::processRspQrySpotLock(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		TapAPISpotLockInfo *task_data = (TapAPISpotLockInfo*)task->task_data;
		data["AccountNo"] = toUtf(task_data->AccountNo);
		data["ExchangeNo"] = toUtf(task_data->ExchangeNo);
		data["CommodityType"] = task_data->CommodityType;
		data["CommodityNo"] = toUtf(task_data->CommodityNo);
		data["PositionQty"] = task_data->PositionQty;
		data["LockQty"] = task_data->LockQty;
		data["CoveredQty"] = task_data->CoveredQty;
		data["CanCoveredQty"] = task_data->CanCoveredQty;
		delete task_data;
	}
	this->onRspQrySpotLock(task->task_string, task->task_id, task->task_int, task->task_last, data);
};

void TdApi::processRtnSpotLock(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		TapAPISpotLockInfo *task_data = (TapAPISpotLockInfo*)task->task_data;
		data["AccountNo"] = toUtf(task_data->AccountNo);
		data["ExchangeNo"] = toUtf(task_data->ExchangeNo);
		data["CommodityType"] = task_data->CommodityType;
		data["CommodityNo"] = toUtf(task_data->CommodityNo);
		data["PositionQty"] = task_data->PositionQty;
		data["LockQty"] = task_data->LockQty;
		data["CoveredQty"] = task_data->CoveredQty;
		data["CanCoveredQty"] = task_data->CanCoveredQty;
		delete task_data;
	}
	this->onRtnSpotLock(task->task_string, data);
};

void TdApi::processRspSpecialOrderAction(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		TapAPISpecialOrderInfo *task_data = (TapAPISpecialOrderInfo*)task->task_data;
		data["AccountNo"] = toUtf(task_data->AccountNo);
		data["ServerFlag"] = task_data->ServerFlag;
		data["OrderNo"] = toUtf(task_data->OrderNo);
		data["RefString"] = toUtf(task_data->RefString);
		data["SpecialOrderType"] = task_data->SpecialOrderType;
		data["OrderSource"] = task_data->OrderSource;
		data["CombineStrategy"] = toUtf(task_data->CombineStrategy);
		data["CombineNo"] = toUtf(task_data->CombineNo);
		data["OrderQty"] = task_data->OrderQty;
		data["ExchangeNo"] = toUtf(task_data->ExchangeNo);
		data["CommodityType"] = task_data->CommodityType;
		data["CommodityNo"] = toUtf(task_data->CommodityNo);
		data["ContractNo"] = toUtf(task_data->ContractNo);
		data["StrikePrice"] = toUtf(task_data->StrikePrice);
		data["CallOrPutFlag"] = task_data->CallOrPutFlag;
		data["OrderSide1"] = task_data->OrderSide1;
		data["CombineQty1"] = task_data->CombineQty1;
		data["HedgeFlag1"] = task_data->HedgeFlag1;
		data["ContractNo2"] = toUtf(task_data->ContractNo2);
		data["StrikePrice2"] = toUtf(task_data->StrikePrice2);
		data["CallOrPutFlag2"] = task_data->CallOrPutFlag2;
		data["OrderSide2"] = task_data->OrderSide2;
		data["CombineQty2"] = task_data->CombineQty2;
		data["HedgeFlag2"] = task_data->HedgeFlag2;
		data["LicenseNo"] = toUtf(task_data->LicenseNo);
		data["OrderStreamID"] = task_data->OrderStreamID;
		data["UpperNo"] = toUtf(task_data->UpperNo);
		data["UpperChannelNo"] = toUtf(task_data->UpperChannelNo);
		data["OrderLocalNo"] = toUtf(task_data->OrderLocalNo);
		data["OrderSystemNo"] = toUtf(task_data->OrderSystemNo);
		data["OrderExchangeSystemNo"] = toUtf(task_data->OrderExchangeSystemNo);
		data["OrderInsertUserNo"] = toUtf(task_data->OrderInsertUserNo);
		data["OrderInsertTime"] = toUtf(task_data->OrderInsertTime);
		data["OrderState"] = task_data->OrderState;
		data["ErrorCode"] = task_data->ErrorCode;
		data["ErrorText"] = toUtf(task_data->ErrorText);
		delete task_data;
	}
	this->onRspSpecialOrderAction(task->task_string, task->task_id, task->task_int, data);
};

void TdApi::processRtnSpecialOrder(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		TapAPISpecialOrderInfo *task_data = (TapAPISpecialOrderInfo*)task->task_data;
		data["AccountNo"] = toUtf(task_data->AccountNo);
		data["ServerFlag"] = task_data->ServerFlag;
		data["OrderNo"] = toUtf(task_data->OrderNo);
		data["RefString"] = toUtf(task_data->RefString);
		data["SpecialOrderType"] = task_data->SpecialOrderType;
		data["OrderSource"] = task_data->OrderSource;
		data["CombineStrategy"] = toUtf(task_data->CombineStrategy);
		data["CombineNo"] = toUtf(task_data->CombineNo);
		data["OrderQty"] = task_data->OrderQty;
		data["ExchangeNo"] = toUtf(task_data->ExchangeNo);
		data["CommodityType"] = task_data->CommodityType;
		data["CommodityNo"] = toUtf(task_data->CommodityNo);
		data["ContractNo"] = toUtf(task_data->ContractNo);
		data["StrikePrice"] = toUtf(task_data->StrikePrice);
		data["CallOrPutFlag"] = task_data->CallOrPutFlag;
		data["OrderSide1"] = task_data->OrderSide1;
		data["CombineQty1"] = task_data->CombineQty1;
		data["HedgeFlag1"] = task_data->HedgeFlag1;
		data["ContractNo2"] = toUtf(task_data->ContractNo2);
		data["StrikePrice2"] = toUtf(task_data->StrikePrice2);
		data["CallOrPutFlag2"] = task_data->CallOrPutFlag2;
		data["OrderSide2"] = task_data->OrderSide2;
		data["CombineQty2"] = task_data->CombineQty2;
		data["HedgeFlag2"] = task_data->HedgeFlag2;
		data["LicenseNo"] = toUtf(task_data->LicenseNo);
		data["OrderStreamID"] = task_data->OrderStreamID;
		data["UpperNo"] = toUtf(task_data->UpperNo);
		data["UpperChannelNo"] = toUtf(task_data->UpperChannelNo);
		data["OrderLocalNo"] = toUtf(task_data->OrderLocalNo);
		data["OrderSystemNo"] = toUtf(task_data->OrderSystemNo);
		data["OrderExchangeSystemNo"] = toUtf(task_data->OrderExchangeSystemNo);
		data["OrderInsertUserNo"] = toUtf(task_data->OrderInsertUserNo);
		data["OrderInsertTime"] = toUtf(task_data->OrderInsertTime);
		data["OrderState"] = task_data->OrderState;
		data["ErrorCode"] = task_data->ErrorCode;
		data["ErrorText"] = toUtf(task_data->ErrorText);
		delete task_data;
	}
	this->onRtnSpecialOrder(task->task_string, task->task_id, data);
};

void TdApi::processRtnCombinePosition(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		TapAPICombinePositionInfo *task_data = (TapAPICombinePositionInfo*)task->task_data;
		data["AccountNo"] = toUtf(task_data->AccountNo);
		data["PositionStreamId"] = task_data->PositionStreamId;
		data["ServerFlag"] = task_data->ServerFlag;
		data["UpperNo"] = toUtf(task_data->UpperNo);
		data["CombineStrategy"] = toUtf(task_data->CombineStrategy);
		data["CombineNo"] = toUtf(task_data->CombineNo);
		data["PositionQty"] = task_data->PositionQty;
		data["ExchangeNo"] = toUtf(task_data->ExchangeNo);
		data["CommodityType"] = task_data->CommodityType;
		data["CommodityNo"] = toUtf(task_data->CommodityNo);
		data["ContractNo"] = toUtf(task_data->ContractNo);
		data["StrikePrice"] = toUtf(task_data->StrikePrice);
		data["CallOrPutFlag"] = task_data->CallOrPutFlag;
		data["OrderSide1"] = task_data->OrderSide1;
		data["CombineQty1"] = task_data->CombineQty1;
		data["HedgeFlag1"] = task_data->HedgeFlag1;
		data["ContractNo2"] = toUtf(task_data->ContractNo2);
		data["StrikePrice2"] = toUtf(task_data->StrikePrice2);
		data["CallOrPutFlag2"] = task_data->CallOrPutFlag2;
		data["OrderSide2"] = task_data->OrderSide2;
		data["CombineQty2"] = task_data->CombineQty2;
		data["HedgeFlag2"] = task_data->HedgeFlag2;
		data["CommodityCurrencyGroup"] = toUtf(task_data->CommodityCurrencyGroup);
		data["CommodityCurrency"] = toUtf(task_data->CommodityCurrency);
		data["AccountInitialMargin"] = task_data->AccountInitialMargin;
		data["AccountMaintenanceMargin"] = task_data->AccountMaintenanceMargin;
		data["UpperInitialMargin"] = task_data->UpperInitialMargin;
		data["UpperMaintenanceMargin"] = task_data->UpperMaintenanceMargin;
		delete task_data;
	}
	this->onRtnCombinePosition(task->task_string, data);
};

void TdApi::processRtnContractQuote(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		TapAPIContractQuoteInfo *task_data = (TapAPIContractQuoteInfo*)task->task_data;
		data["ExchangeNo"] = toUtf(task_data->ExchangeNo);
		data["CommodityType"] = task_data->CommodityType;
		data["CommodityNo"] = toUtf(task_data->CommodityNo);
		data["ContractNo"] = toUtf(task_data->ContractNo);
		data["StrikePrice"] = toUtf(task_data->StrikePrice);
		data["CallOrPutFlag"] = task_data->CallOrPutFlag;
		data["LastPrice"] = task_data->LastPrice;
		data["PreSettlePrice"] = task_data->PreSettlePrice;
		data["PreClosingPrice"] = task_data->PreClosingPrice;
		data["LimitUpPrice"] = task_data->LimitUpPrice;
		data["LimitDownPrice"] = task_data->LimitDownPrice;
		delete task_data;
	}
	this->onRtnContractQuote(task->task_string, data);
};

void TdApi::processRspQryTrustDevice(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		TapAPITrustDeviceInfo *task_data = (TapAPITrustDeviceInfo*)task->task_data;
		data["UserNo"] = toUtf(task_data->UserNo);
		data["LicenseNo"] = toUtf(task_data->LicenseNo);
		data["Mac"] = toUtf(task_data->Mac);
		data["DeviceName"] = toUtf(task_data->DeviceName);
		delete task_data;
	}
	this->onRspQryTrustDevice(task->task_string, task->task_id, task->task_int, task->task_last, data);
};

void TdApi::processRspAddTrustDevice(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		TapAPITrustDeviceAddRsp *task_data = (TapAPITrustDeviceAddRsp*)task->task_data;
		data["UserNo"] = toUtf(task_data->UserNo);
		data["LicenseNo"] = toUtf(task_data->LicenseNo);
		data["Mac"] = toUtf(task_data->Mac);
		data["DeviceName"] = toUtf(task_data->DeviceName);
		delete task_data;
	}
	this->onRspAddTrustDevice(task->task_string, task->task_id, task->task_int, task->task_last, data);
};

void TdApi::processRspDelTrustDevice(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		TapAPITrustDeviceDelRsp *task_data = (TapAPITrustDeviceDelRsp*)task->task_data;
		data["UserNo"] = toUtf(task_data->UserNo);
		data["LicenseNo"] = toUtf(task_data->LicenseNo);
		data["Mac"] = toUtf(task_data->Mac);
		delete task_data;
	}
	this->onRspDelTrustDevice(task->task_string, task->task_id, task->task_int, task->task_last, data);
};

void TdApi::processRtnAddUserRight(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		TapAPIUserRightInfo *task_data = (TapAPIUserRightInfo*)task->task_data;
		data["UserNo"] = toUtf(task_data->UserNo);
		data["RightID"] = task_data->RightID;
		delete task_data;
	}
	this->onRtnAddUserRight(task->task_string, data);
};

void TdApi::processRtnDelUserRight(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		TapAPIUserRightInfo *task_data = (TapAPIUserRightInfo*)task->task_data;
		data["UserNo"] = toUtf(task_data->UserNo);
		data["RightID"] = task_data->RightID;
		delete task_data;
	}
	this->onRtnDelUserRight(task->task_string, data);
};

void TdApi::processRspQryManagerConfigFile(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		TapAPIManagerConfigFileQryRsp *task_data = (TapAPIManagerConfigFileQryRsp*)task->task_data;
		data["FileName"] = toUtf(task_data->Reqdata.FileName);
        data["FileDirectory"] = toUtf(task_data->Reqdata.FileDirectory);
		data["ManagerConfigFileLen"] = task_data->ManagerConfigFileLen;
		data["ManagerConfigFileText"] = task_data->ManagerConfigFileText;
		delete task_data;
	}
	this->onRspQryManagerConfigFile(task->task_string, task->task_id, task->task_int, task->task_last, data);
};



///-------------------------------------------------------------------------------------
///主动函数
///-------------------------------------------------------------------------------------

void TdApi::createEsTradeAPI(int nResult)
{
	this->api = (IEsTradeAPI*)CreateEsTradeAPI(nResult); // 创建API接口对象
	this->api->SetAPINotify(this);  //注册回调函数对象
};

void TdApi::release()
{	
	FreeEsTradeAPI(this->api);
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
	FreeEsTradeAPI(this ->api);
	this->api = NULL;
	return 1;
};

int TdApi::esunny_getloginInfo(const dict&req)
{
	LoginInfo myreq = LoginInfo();
	memset(&myreq, 0, sizeof(myreq));
	getChar(req, "GatherInfo", myreq.GatherInfo);
	getInt(req, "KeyVersion", &myreq.KeyVersion);
	getChar(req, "ItemFalg", myreq.ItemFalg);
	getChar(req, "GatherLibVersion", myreq.GatherLibVersion);
	getChar(req, "IsTestKey", &myreq.IsTestKey);
	getChar(req, "OperatingSystmeType", &myreq.OperatingSystmeType);
	int i = esunny_getLoginInfo(&myreq);
	return i;
}

string TdApi::getEsTradeAPIVersion()
{
	char buf[9999];
	GetEsTradeAPIVersion(buf, 9999);
	return string(buf);
}

int TdApi::setEsTradeAPIDataPath(string pPath)
{
	int i = this->api->SetEsTradeAPIDataPath(pPath.c_str());
	return i;
};

int TdApi::setEsTradeAPILogLevel(string LogLevel)
{
	int i = this->api->SetEsTradeAPILogLevel(LogLevel.c_str()[0]);
	return i;
}

int TdApi::setUserInfo(const dict &req)
{
	TapAPITradeUserInfo myreq = TapAPITradeUserInfo();
	memset(&myreq, 0, sizeof(myreq));
    getUnsignedInt(req, "SystemType", &myreq.SystemType);
	getString(req, "UserNo", myreq.UserNo);
	getString(req, "LoginIP", myreq.LoginIP);
	getUnsignedInt(req, "LoginPort", &myreq.LoginPort);
	getUnsignedInt(req, "LoginType", &myreq.LoginType);
	int i = this->api->SetUserInfo(&myreq);
	return i;
}

int TdApi::setBackUpAddress(string UserNo, const dict &req)
{
	TapAPIBackUpAddress myreq = TapAPIBackUpAddress();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "LoginIP", myreq.LoginIP);
	getUnsignedInt(req, "LoginPort", &myreq.LoginPort);
	int i = this->api->SetBackUpAddress((char*)UserNo.c_str(), &myreq);
}

pybind11::tuple TdApi::requestVerifyIdentity(string UserNo, const dict &req, TAPIUINT32 nRequestID)
{
	TapAPIVerifyIdentity myreq = TapAPIVerifyIdentity();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "UserNo", myreq.UserNo);
	getChar(req, "CertificateType", &myreq.CertificateType);
	getString(req, "CertificateNo", myreq.CertificateNo);
	getString(req, "EMail", myreq.EMail);
	getString(req, "PhoneNo", myreq.PhoneNo);
	int i = this->api->RequestVerifyIdentity((char*)UserNo.c_str(), nRequestID, &myreq);

	pybind11::tuple result = pybind11::make_tuple(i, UserNo, nRequestID);
	return result;	
}

int TdApi::startUser(string UserNo, const dict &req)
{
	TapAPITradeLoginAuth myreq = TapAPITradeLoginAuth();

	getString(req, "UserNo", myreq.UserNo);
	getInt(req, "UserType", &myreq.UserType);
	getString(req, "AuthCode", myreq.AuthCode);
	getString(req, "AppID", myreq.AppID);
	getChar(req, "ISModifyPassword", &myreq.ISModifyPassword);
	getString(req, "Password", myreq.Password);
	getString(req, "NewPassword", myreq.NewPassword);
	getChar(req, "ISDDA", &myreq.ISDDA);
	getString(req, "DDASerialNo", myreq.DDASerialNo);
	//getUnsignedInt(req, "NoticeIgnoreFlag", &myreq.NoticeIgnoreFlag);
	myreq.NoticeIgnoreFlag = TAPI_NOTICE_IGNORE_POSITIONPROFIT;
	getString(req, "LoginIP", myreq.LoginIP);
	getString(req, "LoginMac", myreq.LoginMac);
	int i = this->api->StartUser((char*)UserNo.c_str(), &myreq);
	return i;
};

int TdApi::stopUser(string UserNo)
{
	int i = this->api->StopUser((char*)UserNo.c_str());
	return i;
};


pybind11::tuple TdApi::requestVertificateCode(string UserNo, const dict &req, TAPIUINT32 nRequestID)
{
	TapAPISecondInfo myreq = TapAPISecondInfo();
	memset(&myreq, 0, sizeof(myreq));
	getChar(req, "SendType", &myreq.SendType);
	getString(req, "SendAccount", myreq.SendAccount);
	int i = this->api->RequestVertificateCode((char*)UserNo.c_str(), nRequestID, &myreq);

	pybind11::tuple result = pybind11::make_tuple(i, UserNo, nRequestID);
	return result;	
}

pybind11::tuple TdApi::setVertificateCode(string UserNo, const dict &req, TAPIUINT32 nRequestID)
{
	TapAPISecondCertificationReq myreq = TapAPISecondCertificationReq();
	memset(&myreq, 0, sizeof(myreq));
    getChar(req, "PasswordType", &myreq.PasswordType);
	getString(req, "VertificateCode", myreq.VertificateCode);
	getChar(req, "LoginType", &myreq.LoginType);
	int i = this->api->SetVertificateCode((char*)UserNo.c_str(), nRequestID, &myreq);

	pybind11::tuple result = pybind11::make_tuple(i, UserNo, nRequestID);
	return result;	
}

pybind11::tuple TdApi::insertOrder(string UserNo, const dict &req, TAPIUINT32 nRequestID)
{
	TapAPINewOrder myreq = TapAPINewOrder();

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
	getChar(req, "HedgeFlag2", &myreq.HedgeFlag2);

	getDouble(req, "OrderPrice", &myreq.OrderPrice);
	getDouble(req, "OrderPrice2", &myreq.OrderPrice2);
	getUnsignedInt(req, "OrderQty", &myreq.OrderQty);
	getUnsignedInt(req, "OrderQty2", &myreq.OrderQty2); 
	getUnsignedInt(req, "OrderMinQty", &myreq.OrderMinQty);

	getUnsignedInt(req, "MinClipSize", &myreq.MinClipSize);
	getUnsignedInt(req, "MaxClipSize", &myreq.MaxClipSize);

	getInt(req, "RefInt", &myreq.RefInt);
	getDouble(req, "RefDouble", &myreq.RefDouble);
	getString(req, "RefString", myreq.RefString);
	getChar(req, "TacticsType", &myreq.TacticsType);
	getChar(req, "TriggerCondition", &myreq.TriggerCondition);
	getChar(req, "TriggerPriceType", &myreq.TriggerPriceType);

	getDouble(req, "StopPrice", &myreq.StopPrice);
	getChar(req, "AddOneIsValid", &myreq.AddOneIsValid);
	getUnsignedChar(req, "MarketLevel", &myreq.MarketLevel);
	getChar(req, "FutureAutoCloseFlag", &myreq.FutureAutoCloseFlag);
	getString(req, "UpperChannelNo", myreq.UpperChannelNo);
	getString(req, "ClientID", myreq.ClientID);

	int i = this->api->InsertOrder((char*)UserNo.c_str(), nRequestID, &myreq);

	pybind11::tuple result = pybind11::make_tuple(i, UserNo, nRequestID);
	return result;
}

pybind11::tuple TdApi::cancelOrder(string UserNo, const dict &req, TAPIUINT32 nRequestID)
{
	TapAPIOrderCancelReq myreq = TapAPIOrderCancelReq();
	memset(&myreq, 0, sizeof(myreq));
	getInt(req, "RefInt", &myreq.RefInt);
	getString(req, "RefString", myreq.RefString);
	getChar(req, "ServerFlag", &myreq.ServerFlag);
	getString(req, "OrderNo", myreq.OrderNo);

	int i = this->api->CancelOrder((char*)UserNo.c_str(), nRequestID, &myreq);

	pybind11::tuple result = pybind11::make_tuple(i, UserNo, nRequestID);
	return result;
}

//-----------------------------------------
pybind11::tuple TdApi::qryOrderProcess(string UserNo, const dict &req, TAPIUINT32 nRequestID)
{   
	TapAPIOrderProcessQryReq myreq = TapAPIOrderProcessQryReq();
	memset(&myreq, 0, sizeof(myreq));
	getChar(req, "ServerFlag", &myreq.ServerFlag);
	getString(req, "OrderNo", myreq.OrderNo);
	int i = this->api->QryOrderProcess((char*)UserNo.c_str(), nRequestID, &myreq);

	pybind11::tuple result = pybind11::make_tuple(i, UserNo, nRequestID);
	return result;
};

pybind11::tuple TdApi::qryDeepQuote(string UserNo, const dict &req, TAPIUINT32 nRequestID)
{ 
	TapAPIContract myreq = TapAPIContract();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "Commodity.ExchangeNo", myreq.Commodity.ExchangeNo);
	getChar(req, "Commodity.CommodityType", &myreq.Commodity.CommodityType);
	getString(req, "Commodity.CommodityNo", myreq.Commodity.CommodityNo);
	getString(req, "ContractNo1", myreq.ContractNo1);
	getString(req, "ContractNo1", myreq.ContractNo1);
	getString(req, "StrikePrice1", myreq.StrikePrice1);
	getChar(req, "CallOrPutFlag1", &myreq.CallOrPutFlag1);
	getString(req, "ContractNo2", myreq.ContractNo2);
	getString(req, "StrikePrice2", myreq.StrikePrice2);
	getChar(req, "CallOrPutFlag2", &myreq.CallOrPutFlag2);
	int i = this->api->QryDeepQuote((char*)UserNo.c_str(), nRequestID, &myreq);

	pybind11::tuple result = pybind11::make_tuple(i, UserNo, nRequestID);
	return result;
};

pybind11::tuple TdApi::qryAccountRent(string UserNo, const dict &req, TAPIUINT32 nRequestID)
{ 
	TapAPIAccountRentQryReq myreq = TapAPIAccountRentQryReq();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "AccountNo", myreq.AccountNo);
	getString(req, "ExchangeNo", myreq.ExchangeNo);
	getChar(req, "CommodityType", &myreq.CommodityType);
	getString(req, "CommodityNo", myreq.CommodityNo);
	getString(req, "ContractNo", myreq.ContractNo);
	int i = this->api->QryAccountRent((char*)UserNo.c_str(), nRequestID, &myreq);

	pybind11::tuple result = pybind11::make_tuple(i, UserNo, nRequestID);
	return result;
};

pybind11::tuple TdApi::qryAccountFeeRent(string UserNo, const dict &req, TAPIUINT32 nRequestID)
{ 
	TapAPIAccountFeeRentQryReq myreq = TapAPIAccountFeeRentQryReq();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "AccountNo", myreq.AccountNo);
	int i = this->api->QryAccountFeeRent((char*)UserNo.c_str(), nRequestID, &myreq);

	pybind11::tuple result = pybind11::make_tuple(i, UserNo, nRequestID);
	return result;
};

pybind11::tuple TdApi::qryAccountMarginRent(string UserNo, const dict &req, TAPIUINT32 nRequestID)
{ 
	TapAPIAccountMarginRentQryReq myreq = TapAPIAccountMarginRentQryReq();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "AccountNo", myreq.AccountNo);
	getString(req, "ExchangeNo", myreq.ExchangeNo);
	getChar(req, "CommodityType", &myreq.CommodityType);
	getString(req, "CommodityNo", myreq.CommodityNo);
	int i = this->api->QryAccountMarginRent((char*)UserNo.c_str(), nRequestID, &myreq);

	pybind11::tuple result = pybind11::make_tuple(i, UserNo, nRequestID);
	return result;
};

pybind11::tuple TdApi::qryAccountCashAdjust(string UserNo, const dict &req, TAPIUINT32 nRequestID)
{ 
	TapAPIAccountCashAdjustQryReq myreq = TapAPIAccountCashAdjustQryReq();
	memset(&myreq, 0, sizeof(myreq));
	getUnsignedInt(req, "SerialID", &myreq.SerialID);
	getString(req, "AccountNo", myreq.AccountNo);
	getString(req, "AccountAttributeNo", myreq.AccountAttributeNo);
	getString(req, "BeginDate", myreq.BeginDate);
	getString(req, "EndDate", myreq.EndDate);
	int i = this->api->QryAccountCashAdjust((char*)UserNo.c_str(), nRequestID, &myreq);

	pybind11::tuple result = pybind11::make_tuple(i, UserNo, nRequestID);
	return result;
};

pybind11::tuple TdApi::qryBill(string UserNo, const dict &req, TAPIUINT32 nRequestID)
{ 
	TapAPIBillQryReq myreq = TapAPIBillQryReq();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "UserNo", myreq.UserNo);
	getChar(req, "BillType", &myreq.BillType);
	getString(req, "BillDate", myreq.BillDate);
	getChar(req, "BillFileType", &myreq.BillFileType);
	int i = this->api->QryBill((char*)UserNo.c_str(), nRequestID, &myreq);

	pybind11::tuple result = pybind11::make_tuple(i, UserNo, nRequestID);
	return result;
};

pybind11::tuple TdApi::qryHisOrder(string UserNo, const dict &req, TAPIUINT32 nRequestID)
{ 
	TapAPIHisOrderQryReq myreq = TapAPIHisOrderQryReq();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "AccountNo", myreq.AccountNo);
	getString(req, "AccountAttributeNo", myreq.AccountAttributeNo);
	getString(req, "BeginDate", myreq.BeginDate);
	getString(req, "EndDate", myreq.EndDate);
	int i = this->api->QryHisOrder((char*)UserNo.c_str(), nRequestID, &myreq);

	pybind11::tuple result = pybind11::make_tuple(i, UserNo, nRequestID);
	return result;
};

pybind11::tuple TdApi::qryHisOrderProcess(string UserNo, const dict &req, TAPIUINT32 nRequestID)
{ 
	TapAPIHisOrderProcessQryReq myreq = TapAPIHisOrderProcessQryReq();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "Date", myreq.Date);
	getString(req, "OrderNo", myreq.OrderNo);
	int i = this->api->QryHisOrderProcess((char*)UserNo.c_str(), nRequestID, &myreq);

	pybind11::tuple result = pybind11::make_tuple(i, UserNo, nRequestID);
	return result;
};

pybind11::tuple TdApi::qryHisFill(string UserNo, const dict &req, TAPIUINT32 nRequestID)
{ 
	TapAPIHisFillQryReq myreq = TapAPIHisFillQryReq();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "AccountNo", myreq.AccountNo);
	getString(req, "AccountAttributeNo", myreq.AccountAttributeNo);
	getString(req, "BeginDate", myreq.BeginDate);
	getString(req, "EndDate", myreq.EndDate);
	getChar(req, "CountType", &myreq.CountType);
	int i = this->api->QryHisFill((char*)UserNo.c_str(), nRequestID, &myreq);

	pybind11::tuple result = pybind11::make_tuple(i, UserNo, nRequestID);
	return result;
};

pybind11::tuple TdApi::qryHisPosition(string UserNo, const dict &req, TAPIUINT32 nRequestID)
{ 
	TapAPIHisPositionQryReq myreq = TapAPIHisPositionQryReq();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "AccountNo", myreq.AccountNo);
	getString(req, "Date", myreq.Date);
	getChar(req, "SettleFlag", &myreq.SettleFlag);
	int i = this->api->QryHisPosition((char*)UserNo.c_str(), nRequestID, &myreq);

	pybind11::tuple result = pybind11::make_tuple(i, UserNo, nRequestID);
	return result;
};

pybind11::tuple TdApi::qryHisDelivery(string UserNo, const dict &req, TAPIUINT32 nRequestID)
{ 
	TapAPIHisDeliveryQryReq myreq = TapAPIHisDeliveryQryReq();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "AccountNo", myreq.AccountNo);
	getString(req, "AccountAttributeNo", myreq.AccountAttributeNo);
	getString(req, "BeginDate", myreq.BeginDate);
	getString(req, "EndDate", myreq.EndDate);
	getChar(req, "CountType", &myreq.CountType);
	int i = this->api->QryHisDelivery((char*)UserNo.c_str(), nRequestID, &myreq);

	pybind11::tuple result = pybind11::make_tuple(i, UserNo, nRequestID);
	return result;
};

pybind11::tuple TdApi::qryManageInfoForEStar(string UserNo, const dict &req, TAPIUINT32 nRequestID)
{ 
	TapAPIManageInfoQryReq myreq = TapAPIManageInfoQryReq();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "BeginDate", myreq.BeginDate);
	getString(req, "EndDate", myreq.EndDate);
	int i = this->api->QryManageInfoForEStar((char*)UserNo.c_str(), nRequestID, &myreq);

	pybind11::tuple result = pybind11::make_tuple(i, UserNo, nRequestID);
	return result;
};

pybind11::tuple TdApi::qrySystemParameter(string UserNo, const dict &req, TAPIUINT32 nRequestID)
{ 
	TapAPISystemParameterQryReq myreq = TapAPISystemParameterQryReq();
	memset(&myreq, 0, sizeof(myreq));
	int i = this->api->QrySystemParameter((char*)UserNo.c_str(), nRequestID, &myreq);

	pybind11::tuple result = pybind11::make_tuple(i, UserNo, nRequestID);
	return result;	
};

pybind11::tuple TdApi::qryTradeCenterFrontAddress(string UserNo, const dict &req, TAPIUINT32 nRequestID)
{ 
	TapAPITradeCenterFrontAddressQryReq myreq = TapAPITradeCenterFrontAddressQryReq();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "FrontAddress", myreq.FrontAddress);
	getString(req, "FrontPort", myreq.FrontPort);
	getChar(req, "TradeCenter", &myreq.TradeCenter);
	getChar(req, "IsSSL", &myreq.IsSSL);
	int i = this->api->QryTradeCenterFrontAddress((char*)UserNo.c_str(), nRequestID, &myreq);

	pybind11::tuple result = pybind11::make_tuple(i, UserNo, nRequestID);
	return result;	
};

pybind11::tuple TdApi::qryTradeMessage(string UserNo, const dict &req, TAPIUINT32 nRequestID)
{ 
	TapAPITradeMessageQryReq myreq = TapAPITradeMessageQryReq();
	memset(&myreq, 0, sizeof(myreq));
	getUnsignedInt(req, "SerialID", &myreq.SerialID);
	getChar(req, "TradeMsgQryType", &myreq.TradeMsgQryType);
	getString(req, "AccountNo", myreq.AccountNo);
	getString(req, "BeginSendDateTime", myreq.BeginSendDateTime);
	getString(req, "EndSendDateTime", myreq.EndSendDateTime);
	int i = this->api->QryTradeMessage((char*)UserNo.c_str(), nRequestID, &myreq);

	pybind11::tuple result = pybind11::make_tuple(i, UserNo, nRequestID);
	return result;	
};

pybind11::tuple TdApi::qryAccountStorage(string UserNo, const dict &req, TAPIUINT32 nRequestID)
{ 
	TapAPIAccountStorageQryReq myreq = TapAPIAccountStorageQryReq();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "AccountNo", myreq.AccountNo);
	int i = this->api->QryAccountStorage((char*)UserNo.c_str(), nRequestID, &myreq);

	pybind11::tuple result = pybind11::make_tuple(i, UserNo, nRequestID);
	return result;	
};

pybind11::tuple TdApi::qrySpotLock(string UserNo, const dict &req, TAPIUINT32 nRequestID)
{ 
	TapAPISpotLockQryReq myreq = TapAPISpotLockQryReq();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "StreamAccountNo", myreq.StreamAccountNo);
	getString(req, "AccountNo", myreq.AccountNo);
	int i = this->api->QrySpotLock((char*)UserNo.c_str(), nRequestID, &myreq);

	pybind11::tuple result = pybind11::make_tuple(i, UserNo, nRequestID);
	return result;	
};

pybind11::tuple TdApi::qryTrustDevice(string UserNo, const dict &req, TAPIUINT32 nRequestID)
{ 
	TapAPITrustDeviceQryReq myreq = TapAPITrustDeviceQryReq();
	memset(&myreq, 0, sizeof(myreq));
	int i = this->api->QryTrustDevice((char*)UserNo.c_str(), nRequestID, &myreq);

	pybind11::tuple result = pybind11::make_tuple(i, UserNo, nRequestID);
	return result;	
};

pybind11::tuple TdApi::qryManagerConfigFile(string UserNo, const dict &req, TAPIUINT32 nRequestID)
{ 
	TapAPIManagerConfigFileQryReq myreq = TapAPIManagerConfigFileQryReq();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "FileName", myreq.FileName);
	getString(req, "FileDirectory", myreq.FileDirectory);
	int i = this->api->QryManagerConfigFile((char*)UserNo.c_str(), nRequestID, &myreq);

	pybind11::tuple result = pybind11::make_tuple(i, UserNo, nRequestID);
	return result;	
};

///-------------------------------------------------------------------------------------
///Boost.Python封装
///-------------------------------------------------------------------------------------

class PyTdApi : public TdApi
{
public:
	using TdApi::TdApi;

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


};


PYBIND11_MODULE(vnesunnytd, m)
{
	class_<TdApi, PyTdApi> TdApi(m, "TdApi", module_local());
	TdApi
		.def(init<>())
		.def("createEsTradeAPI", &TdApi::createEsTradeAPI)
		.def("release", &TdApi::release)
		.def("init", &TdApi::init)
		.def("exit", &TdApi::exit)
		.def("esunny_getloginInfo", &TdApi::esunny_getloginInfo)
		.def("getEsTradeAPIVersion", &TdApi::getEsTradeAPIVersion)
		.def("setEsTradeAPIDataPath", &TdApi::setEsTradeAPIDataPath)
		.def("setEsTradeAPILogLevel", &TdApi::setEsTradeAPILogLevel)
		.def("setUserInfo", &TdApi::setUserInfo)
		.def("setBackUpAddress", &TdApi::setBackUpAddress)
		.def("requestVerifyIdentity", &TdApi::requestVerifyIdentity)
		.def("startUser", &TdApi::startUser)
		.def("stopUser", &TdApi::stopUser)
		.def("requestVertificateCode", &TdApi::requestVertificateCode)
		.def("setVertificateCode", &TdApi::setVertificateCode)
		.def("insertOrder", &TdApi:: insertOrder)
		.def("cancelOrder", &TdApi:: cancelOrder)


        .def("qryOrderProcess", &TdApi::qryOrderProcess)
        .def("qryDeepQuote", &TdApi::qryDeepQuote)
        .def("qryAccountRent", &TdApi::qryAccountRent)
        .def("qryAccountFeeRent", &TdApi::qryAccountFeeRent)
        .def("qryAccountMarginRent", &TdApi::qryAccountMarginRent)
        .def("qryAccountCashAdjust", &TdApi::qryAccountCashAdjust)
        .def("qryBill", &TdApi::qryBill)
        .def("qryHisOrder", &TdApi::qryHisOrder)
        .def("qryHisOrderProcess", &TdApi::qryHisOrderProcess)
        .def("qryHisFill", &TdApi::qryHisFill)
        .def("qryHisPosition", &TdApi::qryHisPosition)
        .def("qryHisDelivery", &TdApi::qryHisDelivery)
        .def("qryManageInfoForEStar", &TdApi::qryManageInfoForEStar)
        .def("qrySystemParameter", &TdApi::qrySystemParameter)
        .def("qryTradeCenterFrontAddress", &TdApi::qryTradeCenterFrontAddress)
        .def("qryTradeMessage", &TdApi::qryTradeMessage)
        .def("qryAccountStorage", &TdApi::qryAccountStorage)
        .def("qrySpotLock", &TdApi::qrySpotLock)
        .def("qryTrustDevice", &TdApi::qryTrustDevice)
        .def("qryManagerConfigFile", &TdApi::qryManagerConfigFile)
        
        .def("onConnect", &TdApi::onConnect)
        .def("onRspLogin", &TdApi::onRspLogin)
        .def("onRtnContactInfo", &TdApi::onRtnContactInfo)
        .def("onRspRequestVertificateCode", &TdApi::onRspRequestVertificateCode)
        .def("onRspRequestVerifyIdentity", &TdApi::onRspRequestVerifyIdentity)
        .def("onRspSetVertificateCode", &TdApi::onRspSetVertificateCode)
        .def("onRtnErrorMsg", &TdApi::onRtnErrorMsg)
        .def("onAPIReady", &TdApi::onAPIReady)
        .def("onDisconnect", &TdApi::onDisconnect)
        .def("onRspSubmitUserLoginInfo", &TdApi::onRspSubmitUserLoginInfo)
        .def("onRspChangePassword", &TdApi::onRspChangePassword)
        .def("onRspSetReservedInfo", &TdApi::onRspSetReservedInfo)
        .def("onRtnContract", &TdApi::onRtnContract)
        .def("onRtnFund", &TdApi::onRtnFund)
        .def("onRtnOrder", &TdApi::onRtnOrder)
        .def("onRspOrderAction", &TdApi::onRspOrderAction)
        .def("onRspQryOrderProcess", &TdApi::onRspQryOrderProcess)
        .def("onRtnFill", &TdApi::onRtnFill)
        .def("onRtnPosition", &TdApi::onRtnPosition)
        .def("onRtnClose", &TdApi::onRtnClose)
        .def("onRtnPositionProfit", &TdApi::onRtnPositionProfit)
        .def("onRspQryDeepQuote", &TdApi::onRspQryDeepQuote)
        .def("onRtnExchangeStateInfo", &TdApi::onRtnExchangeStateInfo)
        .def("onRtnReqQuoteNotice", &TdApi::onRtnReqQuoteNotice)
        .def("onRspAccountRentInfo", &TdApi::onRspAccountRentInfo)
        .def("onRspTradeMessage", &TdApi::onRspTradeMessage)
        .def("onRtnTradeMessage", &TdApi::onRtnTradeMessage)
        .def("onRspQryHisOrder", &TdApi::onRspQryHisOrder)
        .def("onRspQryHisOrderProcess", &TdApi::onRspQryHisOrderProcess)
        .def("onRspQryHisFill", &TdApi::onRspQryHisFill)
        .def("onRspQryHisPosition", &TdApi::onRspQryHisPosition)
        .def("onRspQryHisDelivery", &TdApi::onRspQryHisDelivery)
        .def("onRspQryAccountCashAdjust", &TdApi::onRspQryAccountCashAdjust)
        .def("onRspQryBill", &TdApi::onRspQryBill)
        .def("onRspAccountFeeRent", &TdApi::onRspAccountFeeRent)
        .def("onRspAccountMarginRent", &TdApi::onRspAccountMarginRent)
        .def("onRspAddMobileDevice", &TdApi::onRspAddMobileDevice)
        .def("onRspQryManageInfoForEStar", &TdApi::onRspQryManageInfoForEStar)
        .def("onRspQrySystemParameter", &TdApi::onRspQrySystemParameter)
        .def("onRspQryTradeCenterFrontAddress", &TdApi::onRspQryTradeCenterFrontAddress)
        .def("onRtnCommodityInfo", &TdApi::onRtnCommodityInfo)
        .def("onRtnCurrencyInfo", &TdApi::onRtnCurrencyInfo)
        .def("onRspQryAccountStorage", &TdApi::onRspQryAccountStorage)
        .def("onRtnAccountStorage", &TdApi::onRtnAccountStorage)
        .def("onRspQrySpotLock", &TdApi::onRspQrySpotLock)
        .def("onRtnSpotLock", &TdApi::onRtnSpotLock)
        .def("onRspSpecialOrderAction", &TdApi::onRspSpecialOrderAction)
        .def("onRtnSpecialOrder", &TdApi::onRtnSpecialOrder)
        .def("onRtnCombinePosition", &TdApi::onRtnCombinePosition)
        .def("onRtnContractQuote", &TdApi::onRtnContractQuote)
        .def("onRspQryTrustDevice", &TdApi::onRspQryTrustDevice)
        .def("onRspAddTrustDevice", &TdApi::onRspAddTrustDevice)
        .def("onRspDelTrustDevice", &TdApi::onRspDelTrustDevice)
        .def("onRtnAddUserRight", &TdApi::onRtnAddUserRight)
        .def("onRtnDelUserRight", &TdApi::onRtnDelUserRight)
        .def("onRspQryManagerConfigFile", &TdApi::onRspQryManagerConfigFile)
		;

}
