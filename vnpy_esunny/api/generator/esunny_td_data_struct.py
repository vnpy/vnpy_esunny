TapAPITradeUserInfo = {
    "SystemType": "dict",
    "UserNo": "string",
    "LoginIP": "string",
    "LoginPort": "unsigned int",
    "LoginType": "dict",
}

TapAPITradeLoginAuth = {
    "UserNo": "string",
    "UserType": "dict",
    "AuthCode": "string",
    "AppID": "string",
    "ISModifyPassword": "char",
    "Password": "string",
    "NewPassword": "string",
    "ISDDA": "char",
    "DDASerialNo": "string",
    "NoticeIgnoreFlag": "dict",
    "LoginIP": "string",
    "LoginMac": "string",
}

TapAPITradeLoginRspInfo = {
    "UserNo": "string",
    "UserType": "dict",
    "UserName": "string",
    "QuoteTempPassword": "string",
    "ReservedInfo": "string",
    "LastLoginIP": "string",
    "LastLoginPort": "unsigned int",
    "LastLoginTime": "string",
    "LastLogoutTime": "string",
    "TradeDate": "string",
    "LastSettleTime": "string",
    "StartTime": "string",
    "InitTime": "string",
    "AuthType": "char",
    "AuthDate": "string",
    "UdpCertCode": "unsigned long long",
    "CurrentLoginIP": "string",
    "CurrentLoginPort": "unsigned int",
}

TapAPISubmitUserLoginInfo = {
    "UserNo": "string",
    "GatherInfo": "string",
    "ClientLoginIP": "string",
    "ClientLoginPort": "unsigned int",
    "ClientLoginDateTime": "string",
    "ClientAppID": "string",
    "AuthKeyVersion": "unsigned int",
    "ItemFalg": "string",
    "GatherLibVersion": "string",
    "IsTestKey": "char",
    "OperatingSystmeType": "char",
}

TapAPISubmitUserLoginInfoRsp = {
    "UserNo": "string",
    "ErrorCode": "unsigned int",
    "ErrorText": "string",
}

TapAPIExchangeInfo = {
    "ExchangeNo": "string",
    "ExchangeName": "string",
}

TapAPICommodity = {
    "ExchangeNo": "string",
    "CommodityType": "char",
    "CommodityNo": "string",
}

TapAPICommodityInfo = {
    "ExchangeNo": "string",
    "CommodityType": "char",
    "CommodityNo": "string",
    "CommodityName": "string",
    "CommodityEngName": "string",
    "RelateExchangeNo": "string",
    "RelateCommodityType": "char",
    "RelateCommodityNo": "string",
    "RelateExchangeNo2": "string",
    "RelateCommodityType2": "char",
    "RelateCommodityNo2": "string",
    "TradeCurrency": "string",
    "ContractSize": "double",
    "OpenCloseMode": "char",
    "StrikePriceTimes": "double",
    "CommodityTickSize": "double",
    "CommodityDenominator": "int",
    "CmbDirect": "char",
    "OnlyCanCloseDays": "int",
    "DeliveryMode": "char",
    "DeliveryDays": "int",
    "AddOneTime": "string",
    "CommodityTimeZone": "int",
    "IsAddOne": "char",
}

TapAPIContract = {
    "Commodity": "dict",
    "ContractNo1": "string",
    "StrikePrice1": "string",
    "CallOrPutFlag1": "char",
    "ContractNo2": "string",
    "StrikePrice2": "string",
    "CallOrPutFlag2": "char",
}

TapAPITradeContractInfo = {
    "ExchangeNo": "string",
    "CommodityType": "char",
    "CommodityNo": "string",
    "ContractNo1": "string",
    "StrikePrice1": "string",
    "CallOrPutFlag1": "char",
    "ContractNo2": "string",
    "StrikePrice2": "string",
    "CallOrPutFlag2": "char",
    "ContractName": "dict",
    "ContractExpDate": "string",
    "LastTradeDate": "string",
    "FirstNoticeDate": "string",
    "FutureContractNo": "dict",
}

TapAPIChangePasswordReq = {
    "PasswordType": "char",
    "OldPassword": "string",
    "NewPassword": "string",
}

TapAPIChangePasswordRsp = TapAPIChangePasswordReq
TapAPIUserRightInfo = {
    "UserNo": "string",
    "RightID": "dict",
}

TapAPIUserOrderFrequency = {
    "UserNo": "string",
    "UserOrderFrequency": "unsigned int",
}

TapAPIAccQryReq = {
    "AccountNo": "string",
}

TapAPIAccountInfo = {
    "AccountNo": "string",
    "AccountType": "char",
    "AccountState": "char",
    "AccountShortName": "string",
    "AccountIsDocHolder": "dict",
    "IsMarketMaker": "char",
    "AccountFamilyType": "dict",
}

TapAPINewOrder = {
    "AccountNo": "string",
    "ExchangeNo": "string",
    "CommodityType": "char",
    "CommodityNo": "string",
    "ContractNo": "string",
    "StrikePrice": "string",
    "CallOrPutFlag": "char",
    "ContractNo2": "string",
    "StrikePrice2": "string",
    "CallOrPutFlag2": "char",
    "OrderType": "char",
    "OrderSource": "char",
    "TimeInForce": "char",
    "ExpireTime": "string",
    "IsRiskOrder": "char",
    "OrderSide": "char",
    "PositionEffect": "char",
    "PositionEffect2": "char",
    "InquiryNo": "string",
    "HedgeFlag": "char",
    "HedgeFlag2": "char",
    "OrderPrice": "double",
    "OrderPrice2": "double",
    "OrderQty": "unsigned int",
    "OrderQty2": "unsigned int",
    "OrderMinQty": "unsigned int",
    "MinClipSize": "unsigned int",
    "MaxClipSize": "unsigned int",
    "RefInt": "int",
    "RefDouble": "double",
    "RefString": "string",
    "TacticsType": "char",
    "TriggerCondition": "char",
    "TriggerPriceType": "char",
    "StopPrice": "double",
    "AddOneIsValid": "char",
    "MarketLevel": "dict",
    "FutureAutoCloseFlag": "char",
    "UpperChannelNo": "string",
    "ClientID": "string",
}

TapAPIOrderInfo = {
    "AccountNo": "string",
    "ExchangeNo": "string",
    "CommodityType": "char",
    "CommodityNo": "string",
    "ContractNo": "string",
    "StrikePrice": "string",
    "CallOrPutFlag": "char",
    "ContractNo2": "string",
    "StrikePrice2": "string",
    "CallOrPutFlag2": "char",
    "OrderType": "char",
    "OrderSource": "char",
    "TimeInForce": "char",
    "ExpireTime": "string",
    "IsRiskOrder": "char",
    "OrderSide": "char",
    "PositionEffect": "char",
    "PositionEffect2": "char",
    "InquiryNo": "string",
    "HedgeFlag": "char",
    "HedgeFlag2": "char",
    "OrderPrice": "double",
    "OrderPrice2": "double",
    "StopPrice": "double",
    "OrderQty": "unsigned int",
    "OrderQty2": "unsigned int",
    "OrderMinQty": "unsigned int",
    "MinClipSize": "unsigned int",
    "MaxClipSize": "unsigned int",
    "RefInt": "int",
    "RefDouble": "double",
    "RefString": "string",
    "TacticsType": "char",
    "TriggerCondition": "char",
    "TriggerPriceType": "char",
    "AddOneIsValid": "char",
    "MarketLevel": "dict",
    "FutureAutoCloseFlag": "char",
    "OrderCanceledQty": "unsigned int",
    "LicenseNo": "string",
    "ParentAccountNo": "string",
    "ServerFlag": "char",
    "OrderNo": "string",
    "ClientOrderNo": "string",
    "OrderLocalNo": "string",
    "OrderSystemNo": "string",
    "OrderExchangeSystemNo": "string",
    "TradeNo": "string",
    "UpperNo": "string",
    "UpperChannelNo": "string",
    "UpperSettleNo": "string",
    "UpperUserNo": "string",
    "OrderInsertUserNo": "string",
    "OrderInsertTime": "string",
    "OrderCommandUserNo": "string",
    "OrderUpdateUserNo": "string",
    "OrderUpdateTime": "string",
    "OrderState": "char",
    "OrderMatchPrice": "double",
    "OrderMatchPrice2": "double",
    "OrderMatchQty": "unsigned int",
    "OrderMatchQty2": "unsigned int",
    "ErrorCode": "unsigned int",
    "ErrorText": "string",
    "IsBackInput": "char",
    "IsDeleted": "char",
    "IsAddOne": "char",
    "OrderStreamID": "unsigned int",
    "UpperStreamID": "unsigned int",
    "ClientID": "string",
    "FeeValue": "double",
    "MarginValue": "double",
    "OrderParentSystemNo": "string",
}

TapAPIOrderActionRsp = {
    "ActionType": "char",
    "OrderInfo": "dict",
}

TapAPIOrderModifyReq = {
    "ReqData": "dict",
    "ServerFlag": "char",
    "OrderNo": "string",
}

TapAPIOrderCancelReq = {
    "RefInt": "int",
    "RefString": "string",
    "ServerFlag": "char",
    "OrderNo": "string",
}

TapAPIOrderDeactivateReq = TapAPIOrderCancelReq
TapAPIOrderActivateReq = TapAPIOrderCancelReq
TapAPIOrderDeleteReq = TapAPIOrderCancelReq
TapAPIOrderQryReq = {
    "OrderQryType": "char",
    "AccountNo": "string",
    "DataSeqID": "unsigned int",
}

TapAPIOrderProcessQryReq = {
    "ServerFlag": "char",
    "OrderNo": "string",
}

TapAPIFillQryReq = {
    "AccountNo": "string",
    "DataSeqID": "unsigned int",
}

TapAPIFillInfo = {
    "AccountNo": "string",
    "ParentAccountNo": "dict",
    "ExchangeNo": "string",
    "CommodityType": "char",
    "CommodityNo": "string",
    "ContractNo": "string",
    "StrikePrice": "string",
    "CallOrPutFlag": "char",
    "OrderType": "char",
    "MatchSource": "char",
    "TimeInForce": "char",
    "ExpireTime": "string",
    "IsRiskOrder": "char",
    "MatchSide": "char",
    "PositionEffect": "char",
    "HedgeFlag": "char",
    "ServerFlag": "char",
    "OrderNo": "string",
    "OrderLocalNo": "string",
    "MatchNo": "string",
    "ExchangeMatchNo": "string",
    "MatchDateTime": "string",
    "UpperMatchDateTime": "string",
    "UpperNo": "string",
    "UpperChannelNo": "string",
    "UpperSettleNo": "string",
    "UpperUserNo": "string",
    "TradeNo": "string",
    "MatchPrice": "double",
    "MatchQty": "unsigned int",
    "IsBackInput": "char",
    "IsDeleted": "char",
    "IsAddOne": "char",
    "MatchStreamID": "unsigned int",
    "UpperStreamID": "unsigned int",
    "OpenCloseMode": "dict",
    "ContractSize": "dict",
    "CommodityCurrencyGroup": "dict",
    "CommodityCurrency": "dict",
    "FeeMode": "dict",
    "FeeParam": "dict",
    "FeeCurrencyGroup": "string",
    "FeeCurrency": "string",
    "PreSettlePrice": "dict",
    "FeeValue": "double",
    "IsManualFee": "char",
    "Turnover": "dict",
    "PremiumIncome": "double",
    "PremiumPay": "double",
    "OppoMatchNo": "dict",
    "CloseProfit": "double",
    "UnExpProfit": "dict",
    "UpperMatchPrice": "dict",
    "QuotePrice": "dict",
    "ClosePL": "dict",
    "OrderSystemNo": "string",
    "UpperMatchNo": "string",
    "ClosePositionPrice": "double",
}

TapAPIPositionQryReq = {
    "AccountNo": "string",
    "DataSeqID": "unsigned int",
}

TapAPIPositionInfo = {
    "AccountNo": "string",
    "ExchangeNo": "string",
    "CommodityType": "char",
    "CommodityNo": "string",
    "ContractNo": "string",
    "StrikePrice": "string",
    "CallOrPutFlag": "char",
    "MatchSide": "char",
    "HedgeFlag": "char",
    "PositionNo": "string",
    "ServerFlag": "char",
    "OrderNo": "string",
    "MatchNo": "string",
    "ExchangeMatchNo": "string",
    "MatchSource": "char",
    "MatchDate": "string",
    "MatchTime": "string",
    "UpperMatchTime": "dict",
    "UpperNo": "string",
    "UpperSettleNo": "string",
    "UpperUserNo": "string",
    "TradeNo": "string",
    "PositionPrice": "double",
    "PositionQty": "unsigned int",
    "IsBackInput": "char",
    "IsAddOne": "char",
    "MatchStreamID": "unsigned int",
    "PositionStreamId": "unsigned int",
    "OpenCloseMode": "dict",
    "ContractSize": "double",
    "CommodityCurrencyGroup": "string",
    "CommodityCurrency": "string",
    "PreSettlePrice": "double",
    "SettlePrice": "double",
    "Turnover": "double",
    "AccountMarginMode": "dict",
    "AccountMarginParam": "dict",
    "UpperMarginMode": "dict",
    "UpperMarginParam": "dict",
    "AccountInitialMargin": "double",
    "AccountMaintenanceMargin": "double",
    "UpperInitialMargin": "double",
    "UpperMaintenanceMargin": "double",
    "PositionProfit": "double",
    "LMEPositionProfit": "double",
    "OptionMarketValue": "double",
    "MatchCmbNo": "string",
    "IsHistory": "char",
    "FloatingPL": "double",
    "CalculatePrice": "double",
}

TapAPIPositionSumInfo = {
    "AccountNo": "string",
    "ExchangeNo": "string",
    "CommodityType": "char",
    "CommodityNo": "string",
    "ContractNo": "string",
    "StrikePrice": "string",
    "CallOrPutFlag": "char",
    "MatchSide": "char",
    "HedgeFlag": "char",
    "PositionPrice": "double",
    "PositionQty": "unsigned int",
    "HisPositionQty": "unsigned int",
}

TapAPIPositionProfit = {
    "PositionNo": "string",
    "PositionStreamId": "unsigned int",
    "PositionProfit": "double",
    "LMEPositionProfit": "double",
    "OptionMarketValue": "double",
    "CalculatePrice": "double",
    "FloatingPL": "double",
}

TapAPIPositionProfitNotice = {
    "IsLast": "char",
    "Data": "dict",
}

TapAPICloseQryReq = {
    "AccountNo": "string",
    "DataSeqID": "unsigned int",
}

TapAPICloseInfo = {
    "AccountNo": "string",
    "ParentAccountNo": "dict",
    "ExchangeNo": "string",
    "CommodityType": "char",
    "CommodityNo": "string",
    "ContractNo": "string",
    "StrikePrice": "string",
    "CallOrPutFlag": "char",
    "OpenOrderExchangeNo": "dict",
    "OpenOrderCommodityType": "dict",
    "OpenOrderCommodityNo": "dict",
    "CloseOrderExchangeNo": "dict",
    "CloseOrderCommodityType": "dict",
    "CloseOrderCommodityNo": "dict",
    "OpenMatchSource": "char",
    "CloseMatchSource": "char",
    "CloseSide": "char",
    "CloseQty": "unsigned int",
    "OpenPrice": "double",
    "ClosePrice": "double",
    "OpenServerFlag": "char",
    "OpenOrderNo": "string",
    "OpenMatchNo": "string",
    "OpenExchangeMatchNo": "string",
    "OpenMatchDateTime": "string",
    "CloseServerFlag": "char",
    "CloseOrderNo": "string",
    "CloseMatchNo": "string",
    "CloseExchangeMatchNo": "string",
    "CloseMatchDateTime": "string",
    "CloseStreamId": "unsigned int",
    "OpenCloseMode": "dict",
    "ContractSize": "double",
    "CommodityCurrencyGroup": "dict",
    "CommodityCurrency": "dict",
    "PreSettlePrice": "double",
    "PremiumIncome": "dict",
    "PremiumPay": "dict",
    "CloseProfit": "double",
    "UnExpProfit": "double",
    "ClosePL": "double",
}

TapAPIFundReq = {
    "AccountNo": "string",
    "DataSeqID": "unsigned int",
}

TapAPIFundData = {
    "AccountNo": "string",
    "ParentAccountNo": "dict",
    "CurrencyGroupNo": "string",
    "CurrencyNo": "string",
    "TradeRate": "double",
    "FutureAlg": "char",
    "OptionAlg": "char",
    "PreBalance": "double",
    "PreUnExpProfit": "double",
    "PreLMEPositionProfit": "double",
    "PreEquity": "double",
    "PreAvailable1": "double",
    "PreMarketEquity": "double",
    "CashInValue": "double",
    "CashOutValue": "double",
    "CashAdjustValue": "double",
    "CashPledged": "double",
    "FrozenFee": "double",
    "FrozenDeposit": "double",
    "AccountFee": "double",
    "ExchangeFee": "double",
    "AccountDeliveryFee": "double",
    "PremiumIncome": "double",
    "PremiumPay": "double",
    "CloseProfit": "double",
    "DeliveryProfit": "double",
    "UnExpProfit": "double",
    "ExpProfit": "double",
    "PositionProfit": "double",
    "LmePositionProfit": "double",
    "OptionMarketValue": "double",
    "AccountInitialMargin": "double",
    "AccountMaintenanceMargin": "double",
    "UpperInitialMargin": "double",
    "UpperMaintenanceMargin": "double",
    "Discount": "double",
    "Balance": "double",
    "Equity": "double",
    "Available": "double",
    "CanDraw": "double",
    "MarketEquity": "double",
    "AuthMoney": "double",
    "OriginalCashInOut": "double",
    "FloatingPL": "double",
    "FrozenRiskFundValue": "double",
    "ClosePL": "double",
    "NoCurrencyPledgeValue": "double",
    "PrePledgeValue": "double",
    "PledgeIn": "double",
    "PledgeOut": "double",
    "PledgeValue": "double",
    "BorrowValue": "double",
    "SpecialAccountFrozenMargin": "double",
    "SpecialAccountMargin": "double",
    "SpecialAccountFrozenFee": "double",
    "SpecialAccountFee": "double",
    "SpecialFloatProfit": "double",
    "SpecialCloseProfit": "double",
    "SpecialFloatPL": "double",
    "SpecialClosePL": "double",
    "RiskRate": "double",
}

TapAPIReqQuoteNotice = {
    "ExchangeNo": "string",
    "CommodityType": "char",
    "CommodityNo": "string",
    "ContractNo": "string",
    "StrikePrice": "string",
    "CallOrPutFlag": "char",
    "InquiryNo": "string",
    "UpdateTime": "string",
}

TapAPIDeepQuoteInfo = {
    "Side": "char",
    "Price": "double",
    "Qty": "unsigned int",
}

TapAPIDeepQuoteQryRsp = {
    "Contract": "dict",
    "DeepQuote": "dict",
}

TapAPIExchangeStateInfoQryReq = {
}

TapAPIExchangeStateInfo = {
    "UpperChannelNo": "string",
    "ExchangeNo": "string",
    "CommodityType": "char",
    "CommodityNo": "string",
    "ExchangeTime": "string",
    "TradingState": "char",
}

TapAPIExchangeStateInfoNotice = {
    "IsLast": "char",
    "ExchangeStateInfo": "dict",
}

TapAPIUpperChannelQryReq = {
}

TapAPIUpperChannelInfo = {
    "UpperChannelNo": "string",
    "UpperChannelName": "string",
    "UpperNo": "string",
    "UpperUserNo": "string",
}

TapAPIAccountRentQryReq = {
    "AccountNo": "string",
    "ExchangeNo": "string",
    "CommodityType": "char",
    "CommodityNo": "string",
    "ContractNo": "string",
}

TapAPIAccountRentInfo = {
    "AccountNo": "string",
    "ExchangeNo": "string",
    "CommodityType": "char",
    "CommodityNo": "string",
    "ContractNo": "string",
    "MatchSource": "char",
    "CurrencyNo": "string",
    "FeeMode": "char",
    "OpenTurnover": "double",
    "ClosedTurnover": "double",
    "CloseNewTurnover": "double",
    "OpenVolume": "double",
    "ClosedVolume": "double",
    "CloseNewVolume": "double",
    "MarginMode": "char",
    "BuyTInitMargin": "double",
    "SellTInitMargin": "double",
    "BuyBInitMargin": "double",
    "SellBInitMargin": "double",
    "BuyLInitMargin": "double",
    "SellLInitMargin": "double",
    "BuyMInitMargin": "double",
    "SellMInitMargin": "double",
    "BuyTMaintMargin": "double",
    "SellTMaintMargin": "double",
    "BuyBMaintMargin": "double",
    "SellBMaintMargin": "double",
    "BuyLMaintMargin": "double",
    "SellLMaintMargin": "double",
    "BuyMMaintMargin": "double",
    "SellMMaintMargin": "double",
}

TapAPICurrencyInfo = {
    "CurrencyNo": "string",
    "CurrencyGroupNo": "string",
    "TradeRate": "double",
    "TradeRate2": "double",
    "FutureAlg": "char",
    "OptionAlg": "char",
}

TapAPITradeMessageQryReq = {
    "SerialID": "unsigned int",
    "TradeMsgQryType": "char",
    "AccountNo": "string",
    "BeginSendDateTime": "string",
    "EndSendDateTime": "string",
}

TapAPITradeMessage = {
    "SerialID": "unsigned int",
    "AccountNo": "string",
    "TMsgValidDateTime": "string",
    "TMsgTitle": "string",
    "TMsgContent": "string",
    "TMsgType": "char",
    "TMsgLevel": "char",
    "IsSendBySMS": "char",
    "IsSendByEMail": "char",
    "Sender": "string",
    "SendDateTime": "string",
}

TapAPIAccountCashAdjustQryReq = {
    "SerialID": "unsigned int",
    "AccountNo": "string",
    "AccountAttributeNo": "string",
    "BeginDate": "string",
    "EndDate": "string",
}

TapAPIAccountCashAdjustQryRsp = {
    "Date": "string",
    "AccountNo": "string",
    "CashAdjustType": "char",
    "CurrencyGroupNo": "string",
    "CurrencyNo": "string",
    "CashAdjustValue": "double",
    "CashAdjustRemark": "string",
    "OperateTime": "string",
    "OperatorNo": "string",
    "AccountBank": "string",
    "BankAccount": "string",
    "AccountLWFlag": "char",
    "CompanyBank": "string",
    "InternalBankAccount": "string",
    "CompanyLWFlag": "char",
}

TapAPIBillQryReq = {
    "UserNo": "string",
    "BillType": "char",
    "BillDate": "string",
    "BillFileType": "char",
}

TapAPIBillQryRsp = {
    "Reqdata": "dict",
    "BillLen": "int",
    "BillText": "char",
}

TapAPIHisOrderQryReq = {
    "AccountNo": "string",
    "AccountAttributeNo": "string",
    "BeginDate": "string",
    "EndDate": "string",
}

TapAPIHisOrderQryRsp = {
    "Date": "string",
    "AccountNo": "string",
    "ExchangeNo": "string",
    "CommodityType": "char",
    "CommodityNo": "string",
    "ContractNo": "string",
    "StrikePrice": "string",
    "CallOrPutFlag": "char",
    "ContractNo2": "string",
    "StrikePrice2": "string",
    "CallOrPutFlag2": "char",
    "OrderType": "char",
    "OrderSource": "char",
    "TimeInForce": "char",
    "ExpireTime": "string",
    "IsRiskOrder": "char",
    "OrderSide": "char",
    "PositionEffect": "char",
    "PositionEffect2": "char",
    "InquiryNo": "string",
    "HedgeFlag": "char",
    "OrderPrice": "double",
    "OrderPrice2": "double",
    "StopPrice": "double",
    "OrderQty": "unsigned int",
    "OrderMinQty": "unsigned int",
    "OrderCanceledQty": "unsigned int",
    "RefInt": "int",
    "RefDouble": "double",
    "RefString": "string",
    "ServerFlag": "char",
    "OrderNo": "string",
    "OrderStreamID": "unsigned int",
    "UpperNo": "string",
    "UpperChannelNo": "string",
    "OrderLocalNo": "string",
    "UpperStreamID": "unsigned int",
    "OrderSystemNo": "string",
    "OrderExchangeSystemNo": "string",
    "OrderParentSystemNo": "string",
    "OrderInsertUserNo": "string",
    "OrderInsertTime": "string",
    "OrderCommandUserNo": "string",
    "OrderUpdateUserNo": "string",
    "OrderUpdateTime": "string",
    "OrderState": "char",
    "OrderMatchPrice": "double",
    "OrderMatchPrice2": "double",
    "OrderMatchQty": "unsigned int",
    "OrderMatchQty2": "unsigned int",
    "ErrorCode": "unsigned int",
    "ErrorText": "string",
    "IsBackInput": "char",
    "IsDeleted": "char",
    "IsAddOne": "char",
    "AddOneIsValid": "char",
    "MinClipSize": "unsigned int",
    "MaxClipSize": "unsigned int",
    "LicenseNo": "string",
    "TacticsType": "char",
    "TriggerCondition": "char",
    "TriggerPriceType": "char",
}

TapAPIHisFillQryReq = {
    "AccountNo": "string",
    "AccountAttributeNo": "string",
    "BeginDate": "string",
    "EndDate": "string",
    "CountType": "char",
}

TapAPIHisFillQryRsp = {
    "SettleDate": "string",
    "TradeDate": "string",
    "AccountNo": "string",
    "ExchangeNo": "string",
    "CommodityType": "char",
    "CommodityNo": "string",
    "ContractNo": "string",
    "StrikePrice": "string",
    "CallOrPutFlag": "char",
    "MatchSource": "char",
    "MatchSide": "char",
    "PositionEffect": "char",
    "HedgeFlag": "char",
    "MatchPrice": "double",
    "MatchQty": "unsigned int",
    "OrderNo": "string",
    "MatchNo": "string",
    "MatchStreamID": "unsigned int",
    "UpperNo": "string",
    "MatchCmbNo": "string",
    "ExchangeMatchNo": "string",
    "MatchUpperStreamID": "unsigned int",
    "CommodityCurrencyGroup": "string",
    "CommodityCurrency": "string",
    "Turnover": "double",
    "PremiumIncome": "double",
    "PremiumPay": "double",
    "AccountFee": "double",
    "AccountFeeCurrencyGroup": "string",
    "AccountFeeCurrency": "string",
    "IsManualFee": "char",
    "AccountOtherFee": "double",
    "UpperFee": "double",
    "UpperFeeCurrencyGroup": "string",
    "UpperFeeCurrency": "string",
    "IsUpperManualFee": "char",
    "UpperOtherFee": "double",
    "MatchDateTime": "string",
    "UpperMatchDateTime": "string",
    "CloseProfit": "double",
    "ClosePrice": "double",
    "CloseQty": "unsigned int",
    "SettleGroupNo": "string",
    "OperatorNo": "string",
    "OperateTime": "string",
}

TapAPIHisOrderProcessQryReq = {
    "Date": "string",
    "OrderNo": "string",
}

TapAPIHisOrderProcessQryRsp = TapAPIHisOrderQryRsp
TapAPIHisPositionQryReq = {
    "AccountNo": "string",
    "Date": "string",
    "SettleFlag": "char",
}

TapAPIHisPositionQryRsp = {
    "SettleDate": "string",
    "OpenDate": "string",
    "AccountNo": "string",
    "ExchangeNo": "string",
    "CommodityType": "char",
    "CommodityNo": "string",
    "ContractNo": "string",
    "StrikePrice": "string",
    "CallOrPutFlag": "char",
    "MatchSide": "char",
    "HedgeFlag": "char",
    "PositionPrice": "double",
    "PositionQty": "unsigned int",
    "OrderNo": "string",
    "PositionNo": "string",
    "UpperNo": "string",
    "CurrencyGroup": "string",
    "Currency": "string",
    "PreSettlePrice": "double",
    "SettlePrice": "double",
    "PositionDProfit": "double",
    "LMEPositionProfit": "double",
    "OptionMarketValue": "double",
    "AccountInitialMargin": "double",
    "AccountMaintenanceMargin": "double",
    "UpperInitialMargin": "double",
    "UpperMaintenanceMargin": "double",
    "SettleGroupNo": "string",
}

TapAPIHisDeliveryQryReq = {
    "AccountNo": "string",
    "AccountAttributeNo": "string",
    "BeginDate": "string",
    "EndDate": "string",
    "CountType": "char",
}

TapAPIHisDeliveryQryRsp = {
    "DeliveryDate": "string",
    "OpenDate": "string",
    "AccountNo": "string",
    "ExchangeNo": "string",
    "CommodityType": "char",
    "CommodityNo": "string",
    "ContractNo": "string",
    "StrikePrice": "string",
    "CallOrPutFlag": "char",
    "MatchSource": "char",
    "OpenSide": "char",
    "OpenPrice": "double",
    "DeliveryPrice": "double",
    "DeliveryQty": "unsigned int",
    "FrozenQty": "unsigned int",
    "OpenNo": "string",
    "UpperNo": "string",
    "CommodityCurrencyGroupy": "string",
    "CommodityCurrency": "string",
    "PreSettlePrice": "double",
    "DeliveryProfit": "double",
    "AccountFrozenInitialMargin": "double",
    "AccountFrozenMaintenanceMargin": "double",
    "UpperFrozenInitialMargin": "double",
    "UpperFrozenMaintenanceMargin": "double",
    "AccountFeeCurrencyGroup": "string",
    "AccountFeeCurrency": "string",
    "AccountDeliveryFee": "double",
    "UpperFeeCurrencyGroup": "string",
    "UpperFeeCurrency": "string",
    "UpperDeliveryFee": "double",
    "DeliveryMode": "char",
    "OperatorNo": "string",
    "OperateTime": "string",
    "SettleGroupNo": "string",
}

TapAPIAccountFeeRentQryReq = {
    "AccountNo": "string",
}

TapAPIAccountFeeRentQryRsp = {
    "AccountNo": "string",
    "ExchangeNo": "string",
    "CommodityType": "char",
    "CommodityNo": "string",
    "MatchSource": "char",
    "CalculateMode": "char",
    "CurrencyGroupNo": "string",
    "CurrencyNo": "string",
    "OpenCloseFee": "double",
    "CloseTodayFee": "double",
    "ContractNo": "string",
}

TapAPIAccountMarginRentQryReq = {
    "AccountNo": "string",
    "ExchangeNo": "string",
    "CommodityType": "char",
    "CommodityNo": "string",
    "ContractNo": "dict",
}

TapAPIAccountMarginRentQryRsp = {
    "AccountNo": "string",
    "ExchangeNo": "string",
    "CommodityType": "char",
    "CommodityNo": "string",
    "ContractNo": "string",
    "StrikePrice": "string",
    "CallOrPutFlag": "char",
    "CalculateMode": "char",
    "CurrencyGroupNo": "string",
    "CurrencyNo": "string",
    "InitialMargin": "double",
    "MaintenanceMargin": "double",
    "SellInitialMargin": "double",
    "SellMaintenanceMargin": "double",
    "LockMargin": "double",
}

TapAPISecondInfo = {
    "SendType": "char",
    "SendAccount": "string",
}

TapAPIVertificateCode = {
    "SecondSerialID": "string",
    "Effective": "int",
}

TapAPISecondCertificationReq = {
    "PasswordType": "char",
    "VertificateCode": "string",
    "LoginType": "char",
}

TapAPISecondCertificationRsp = {
    "PasswordType": "char",
    "VertificateCode": "string",
    "SecondDate": "string",
}

TapAPIMobileDeviceAddReq = {
    "UserNo": "string",
    "AppKey": "string",
    "AppID": "string",
    "MasterSecret": "string",
    "Cid": "string",
    "CompanyNo": "string",
    "CompanyAddressNo": "string",
    "DeviceType": "char",
}

TapAPIMobileDeviceAddRsp = TapAPIMobileDeviceAddReq
TapAPIManageInfoQryReq = {
    "BeginDate": "string",
    "EndDate": "string",
}

TapAPIManageInfo = {
    "MsgID": "unsigned int",
    "SendFrom": "string",
    "SendManageType": "char",
    "AccountNo": "string",
    "SendAccount": "string",
    "Title": "string",
    "Content": "string",
    "Attachment": "string",
    "SendStatus": "char",
    "Remark": "string",
    "GUID": "string",
    "OperatorNo": "string",
    "OperateTime": "string",
}

TapAPISystemParameterQryReq = {
}

TapAPISystemParameterInfo = {
    "ItemNo": "string",
    "ExchangeNo": "string",
    "CommodityNo": "string",
    "CommodityType": "char",
    "ItemValue": "int",
    "ItemValueStr": "string",
    "ItemValueDouble": "double",
}

TapAPITradeCenterFrontAddressQryReq = {
    "FrontAddress": "string",
    "FrontPort": "string",
    "TradeCenter": "char",
    "IsSSL": "char",
}

TapAPITradeCenterFrontAddressInfo = {
    "FrontName": "string",
    "FrontAddress": "string",
    "FrontPort": "string",
    "TradeCenter": "char",
    "IsEnable": "char",
    "IsSSL": "char",
}

TapAPIAccountStorageQryReq = {
    "AccountNo": "string",
}

TapAPIAccountStorageInfo = {
    "AccountNo": "string",
    "ExchangeNo": "string",
    "CommodityType": "char",
    "CommodityNo": "string",
    "StorageQty": "double",
}

TapAPISpotLockQryReq = {
    "StreamAccountNo": "string",
    "AccountNo": "string",
}

TapAPISpotLockInfo = {
    "AccountNo": "string",
    "ExchangeNo": "string",
    "CommodityType": "char",
    "CommodityNo": "string",
    "PositionQty": "unsigned int",
    "LockQty": "unsigned int",
    "CoveredQty": "unsigned int",
    "CanCoveredQty": "unsigned int",
}

TapAPISpecialOrderInsertReq = {
    "AccountNo": "string",
    "SpecialOrderType": "char",
    "OrderSource": "char",
    "CombineNo": "string",
    "RefString": "string",
    "ExchangeNo": "string",
    "CommodityType": "char",
    "CommodityNo": "string",
    "ContractNo": "string",
    "StrikePrice": "string",
    "CallOrPutFlag": "char",
    "ContractNo2": "string",
    "StrikePrice2": "string",
    "CallOrPutFlag2": "char",
    "OrderQty": "unsigned int",
    "OrderSide": "char",
    "HedgeFlag": "char",
}

TapAPISpecialOrderInfo = {
    "AccountNo": "string",
    "ServerFlag": "char",
    "OrderNo": "string",
    "RefString": "string",
    "SpecialOrderType": "char",
    "OrderSource": "char",
    "CombineStrategy": "string",
    "CombineNo": "string",
    "OrderQty": "unsigned int",
    "ExchangeNo": "string",
    "CommodityType": "char",
    "CommodityNo": "string",
    "ContractNo": "string",
    "StrikePrice": "string",
    "CallOrPutFlag": "char",
    "OrderSide1": "char",
    "CombineQty1": "unsigned int",
    "HedgeFlag1": "char",
    "ContractNo2": "string",
    "StrikePrice2": "string",
    "CallOrPutFlag2": "char",
    "OrderSide2": "char",
    "CombineQty2": "unsigned int",
    "HedgeFlag2": "char",
    "LicenseNo": "string",
    "OrderStreamID": "unsigned int",
    "UpperNo": "string",
    "UpperChannelNo": "string",
    "OrderLocalNo": "string",
    "OrderSystemNo": "string",
    "OrderExchangeSystemNo": "string",
    "OrderInsertUserNo": "string",
    "OrderInsertTime": "string",
    "OrderState": "char",
    "ErrorCode": "unsigned int",
    "ErrorText": "string",
}

TapAPISpecialOrderQryReq = {
    "AccountNo": "string",
    "DataSeqID": "unsigned int",
}

TapAPICombinePositionQryReq = {
    "AccountNo": "string",
    "DataSeqID": "unsigned int",
}

TapAPICombinePositionInfo = {
    "AccountNo": "string",
    "PositionStreamId": "unsigned int",
    "ServerFlag": "char",
    "UpperNo": "string",
    "CombineStrategy": "string",
    "CombineNo": "string",
    "PositionQty": "unsigned int",
    "ExchangeNo": "string",
    "CommodityType": "char",
    "CommodityNo": "string",
    "ContractNo": "string",
    "StrikePrice": "string",
    "CallOrPutFlag": "char",
    "OrderSide1": "char",
    "CombineQty1": "unsigned int",
    "HedgeFlag1": "char",
    "ContractNo2": "string",
    "StrikePrice2": "string",
    "CallOrPutFlag2": "char",
    "OrderSide2": "char",
    "CombineQty2": "unsigned int",
    "HedgeFlag2": "char",
    "CommodityCurrencyGroup": "string",
    "CommodityCurrency": "string",
    "AccountInitialMargin": "double",
    "AccountMaintenanceMargin": "double",
    "UpperInitialMargin": "double",
    "UpperMaintenanceMargin": "double",
}

TapAPIContractQuoteInfo = {
    "ExchangeNo": "string",
    "CommodityType": "char",
    "CommodityNo": "string",
    "ContractNo": "string",
    "StrikePrice": "string",
    "CallOrPutFlag": "char",
    "LastPrice": "double",
    "PreSettlePrice": "double",
    "PreClosingPrice": "double",
    "LimitUpPrice": "double",
    "LimitDownPrice": "double",
}

TapAPIBackUpAddress = {
    "LoginIP": "string",
    "LoginPort": "unsigned int",
}

TapAPIVerifyIdentity = {
    "UserNo": "string",
    "CertificateType": "char",
    "CertificateNo": "string",
    "EMail": "string",
    "PhoneNo": "string",
}

TapAPITrustDeviceQryReq = {
}

TapAPITrustDeviceInfo = {
    "UserNo": "string",
    "LicenseNo": "string",
    "Mac": "string",
    "DeviceName": "string",
}

TapAPITrustDeviceAddReq = TapAPITrustDeviceInfo
TapAPITrustDeviceAddRsp = TapAPITrustDeviceAddReq
TapAPITrustDeviceDelReq = {
    "UserNo": "string",
    "LicenseNo": "string",
    "Mac": "string",
}

TapAPITrustDeviceDelRsp = TapAPITrustDeviceDelReq
TapAPIStepTickSize = {
    "ExchangeNo": "string",
    "BeginPrice": "double",
    "EndPrice": "double",
    "TickSize": "double",
}

TapAPIManagerConfigFileQryReq = {
    "FileName": "string",
    "FileDirectory": "string",
}

TapAPIManagerConfigFileQryRsp = {
    "Reqdata": "dict",
    "ManagerConfigFileLen": "int",
    "ManagerConfigFileText": "char",
}

#} 删除1282行

