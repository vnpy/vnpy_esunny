void TdApi::processConnect(Task *task)
{
	this->onConnect();
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

void TdApi::processAPIReady(Task *task)
{
	this->onAPIReady();
};

void TdApi::processDisconnect(Task *task)
{
	gil_scoped_acquire acquire;
	this->onDisconnect(task->task_int);
};

void TdApi::processRspChangePassword(Task *task)
{
	gil_scoped_acquire acquire;
	this->onRspChangePassword(task->task_id, task->task_int);
};

void TdApi::processRspSetReservedInfo(Task *task)
{
	gil_scoped_acquire acquire;
	this->onRspSetReservedInfo(task->task_id, task->task_int, task->task_string);
};

void TdApi::processRspQryAccount(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		TapAPIAccountInfo *task_data = (TapAPIAccountInfo*)task->task_data;
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

void TdApi::processRspQryFund(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		TapAPIFundData *task_data = (TapAPIFundData*)task->task_data;
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

void TdApi::processRtnFund(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		TapAPIFundData *task_data = (TapAPIFundData*)task->task_data;
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

void TdApi::processRspQryExchange(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		TapAPIExchangeInfo *task_data = (TapAPIExchangeInfo*)task->task_data;
		data["ExchangeNo"] = toUtf(task_data->ExchangeNo);
		data["ExchangeName"] = toUtf(task_data->ExchangeName);
		delete task_data;
	}
	this->onRspQryExchange(task->task_id, task->task_int, task->task_last, data);
};

void TdApi::processRspQryCommodity(Task *task)
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

void TdApi::processRspQryContract(Task *task)
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

void TdApi::processRtnOrder(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		TapAPIOrderInfoNotice *task_data = (TapAPIOrderInfoNotice*)task->task_data;
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
		delete task_data;
	}
	this->onRtnOrder(data);
};

void TdApi::processRspOrderAction(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		TapAPIOrderActionRsp *task_data = (TapAPIOrderActionRsp*)task->task_data;
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
		delete task_data;
	}
	this->onRspOrderAction(task->task_id, task->task_error, data);
};

void TdApi::processRspQryOrder(Task *task)
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

void TdApi::processRspQryFill(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		TapAPIFillInfo *task_data = (TapAPIFillInfo*)task->task_data;
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

void TdApi::processRtnFill(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		TapAPIFillInfo *task_data = (TapAPIFillInfo*)task->task_data;
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

void TdApi::processRspQryPosition(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		TapAPIPositionInfo *task_data = (TapAPIPositionInfo*)task->task_data;
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

void TdApi::processRtnPosition(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		TapAPIPositionInfo *task_data = (TapAPIPositionInfo*)task->task_data;
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

void TdApi::processRspQryClose(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		TapAPICloseInfo *task_data = (TapAPICloseInfo*)task->task_data;
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

void TdApi::processRtnClose(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		TapAPICloseInfo *task_data = (TapAPICloseInfo*)task->task_data;
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

void TdApi::processRtnPositionProfit(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		TapAPIPositionProfitNotice *task_data = (TapAPIPositionProfitNotice*)task->task_data;
		data["IsLast"] = task_data->IsLast;
		data["PositionNo"] = toUtf(task_data->Data->PositionNo);
		data["PositionStreamId"] = task_data->Data->PositionStreamId;
		data["PositionProfit"] = task_data->Data->PositionProfit;
		data["LMEPositionProfit"] = task_data->Data->LMEPositionProfit;
		data["OptionMarketValue"] = task_data->Data->OptionMarketValue;
		data["CalculatePrice"] = task_data->Data->CalculatePrice;
		data["FloatingPL"] = task_data->Data->FloatingPL;
		delete task_data;
	}
	this->onRtnPositionProfit(data);
};

void TdApi::processRspQryDeepQuote(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		TapAPIDeepQuoteQryRsp *task_data = (TapAPIDeepQuoteQryRsp*)task->task_data;
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

void TdApi::processRspQryExchangeStateInfo(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		TapAPIExchangeStateInfo *task_data = (TapAPIExchangeStateInfo*)task->task_data;
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
	this->onRtnExchangeStateInfo(data);
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
	this->onRtnReqQuoteNotice(data);
};

void TdApi::processRspUpperChannelInfo(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		TapAPIUpperChannelInfo *task_data = (TapAPIUpperChannelInfo*)task->task_data;
		data["UpperChannelNo"] = toUtf(task_data->UpperChannelNo);
		data["UpperChannelName"] = toUtf(task_data->UpperChannelName);
		data["UpperNo"] = toUtf(task_data->UpperNo);
		data["UpperUserNo"] = toUtf(task_data->UpperUserNo);
		delete task_data;
	}
	this->onRspUpperChannelInfo(task->task_id, task->task_int, task->task_last, data);
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
	this->onRspAccountRentInfo(task->task_id, task->task_int, task->task_last, data);
};

void TdApi::processRspSubmitUserLoginInfo(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		TapAPISubmitUserLoginRspInfo *task_data = (TapAPISubmitUserLoginRspInfo*)task->task_data;
		data["UserNo"] = toUtf(task_data->UserNo);
		data["ErrorCode"] = task_data->ErrorCode;
		data["ErrorText"] = toUtf(task_data->ErrorText);
		delete task_data;
	}
	this->onRspSubmitUserLoginInfo(task->task_id, task->task_int, task->task_last, data);
};

void TdApi::processRspQryBill(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		TapAPIBillQryRsp *task_data = (TapAPIBillQryRsp*)task->task_data;
		data["Reqdata"] = task_data->Reqdata;
		data["BillLen"] = task_data->BillLen;
		data["BillText"] = toUtf(std::string(task_data->BillText, task_data->BillLen));
		delete task_data;
	}
	this->onRspQryBill(task->task_id, task->task_int, task->task_last, data);
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
	this->onRspQryAccountStorage(task->task_id, task->task_int, task->task_last, data);
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
	this->onRtnAccountStorage(data);
};

