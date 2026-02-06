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

