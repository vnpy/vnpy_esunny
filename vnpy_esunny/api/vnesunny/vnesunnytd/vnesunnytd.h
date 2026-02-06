//系统
#ifdef WIN32
#include "stdafx.h"
#endif

#include "vnesunny.h"
#include "pybind11/pybind11.h"
#include "esunny/TapTradeAPI.h"


using namespace pybind11;

//常量
#define ONCONNECT 0
#define ONRSPLOGIN 1
#define ONAPIREADY 2
#define ONDISCONNECT 3
#define ONRSPCHANGEPASSWORD 4
#define ONRSPSETRESERVEDINFO 5
#define ONRSPQRYACCOUNT 6
#define ONRSPQRYFUND 7
#define ONRTNFUND 8
#define ONRSPQRYEXCHANGE 9
#define ONRSPQRYCOMMODITY 10
#define ONRSPQRYCONTRACT 11
#define ONRTNCONTRACT 12
#define ONRTNORDER 13
#define ONRSPORDERACTION 14
#define ONRSPQRYORDER 15
#define ONRSPQRYORDERPROCESS 16
#define ONRSPQRYFILL 17
#define ONRTNFILL 18
#define ONRSPQRYPOSITION 19
#define ONRTNPOSITION 20
#define ONRSPQRYCLOSE 21
#define ONRTNCLOSE 22
#define ONRTNPOSITIONPROFIT 23
#define ONRSPQRYDEEPQUOTE 24
#define ONRSPQRYEXCHANGESTATEINFO 25
#define ONRTNEXCHANGESTATEINFO 26
#define ONRTNREQQUOTENOTICE 27
#define ONRSPUPPERCHANNELINFO 28
#define ONRSPACCOUNTRENTINFO 29
#define ONRSPSUBMITUSERLOGININFO 30
#define ONRSPQRYBILL 31
#define ONRSPQRYACCOUNTSTORAGE 32
#define ONRTNACCOUNTSTORAGE 33


///-------------------------------------------------------------------------------------
///C++ SPI的回调函数方法实现
///-------------------------------------------------------------------------------------

//API的继承实现
class TdApi : public ITapTradeAPINotify
{
private:
	ITapTradeAPI* api;            //API对象
    thread task_thread;                    //工作线程指针（向python中推送数据）
    TaskQueue task_queue;                //任务队列
    bool active = false;               //工作状态

public:
    TdApi()
    {
    };

    ~TdApi()
    {
        if (this->active)
        {
            this->exit();
        }
    };

    //-------------------------------------------------------------------------------------
    //API回调函数
    //-------------------------------------------------------------------------------------

	/**
	* @brief 连接成功回调通知
	* @ingroup G_T_Login
	*/
	virtual void TAP_CDECL OnConnect();
	/**
	* @brief	系统登录过程回调。
	* @details	此函数为Login()登录函数的回调，调用Login()成功后建立了链路连接，然后API将向服务器发送登录认证信息，
	*			登录期间的数据发送情况和登录的回馈信息传递到此回调函数中。
	* @param[in] errorCode 返回错误码,0表示成功。
	* @param[in] loginRspInfo 登陆应答信息，如果errorCode!=0，则loginRspInfo=NULL。
	* @attention	该回调返回成功，说明用户登录成功。但是不代表API准备完毕。
	* @ingroup G_T_Login
	*/
	virtual void TAP_CDECL OnRspLogin(TAPIINT32 errorCode, const TapAPITradeLoginRspInfo* loginRspInfo);
	/**
	* @brief	通知用户API准备就绪。
	* @details	只有用户回调收到此就绪通知时才能进行后续的各种行情数据查询操作。\n
	*			此回调函数是API能否正常工作的标志。
	* @attention 就绪后才可以进行后续正常操作
	* @ingroup G_T_Login
	*/
	virtual void TAP_CDECL OnAPIReady();
	/**
	* @brief	API和服务失去连接的回调
	* @details	在API使用过程中主动或者被动与服务器服务失去连接后都会触发此回调通知用户与服务器的连接已经断开。
	* @param[in] reasonCode 断开原因代码。
	* @ingroup G_T_Disconnect
	*/
	virtual void TAP_CDECL OnDisconnect(TAPIINT32 reasonCode);
	/**
	* @brief 通知用户密码修改结果
	* @param[in] sessionID 修改密码的会话ID,和ChangePassword返回的会话ID对应。
	* @param[in] errorCode 返回错误码，0表示成功。
	* @ingroup G_T_UserInfo
	*/
	virtual void TAP_CDECL OnRspChangePassword(TAPIUINT32 sessionID, TAPIINT32 errorCode);
	/**
	* @brief 设置用户预留信息反馈
	* @param[in] sessionID 设置用户预留信息的会话ID
	* @param[in] errorCode 返回错误码，0表示成功。
	* @param[in] info 指向返回的信息结构体。当errorCode不为0时，info为空。
	* @attention 不要修改和删除info所指示的数据；函数调用结束，参数不再有效。
	* @note 该接口暂未实现
	* @ingroup G_T_UserInfo
	*/
	virtual void TAP_CDECL OnRspSetReservedInfo(TAPIUINT32 sessionID, TAPIINT32 errorCode, const TAPISTR_50 info);
	/**
	* @brief	返回用户信息
	* @details	此回调接口向用户返回查询的资金账号的详细信息。用户有必要将得到的账号编号保存起来，然后在后续的函数调用中使用。
	* @param[in] sessionID 请求的会话ID；
	* @param[in] errorCode 错误码。0 表示成功。
	* @param[in] isLast 标示是否是最后一批数据；
	* @param[in] info 指向返回的信息结构体。当errorCode不为0时，info为空。
	* @attention 不要修改和删除info所指示的数据；函数调用结束，参数不再有效。
	* @ingroup G_T_AccountInfo
	*/
	virtual void TAP_CDECL OnRspQryAccount(TAPIUINT32 sessionID, TAPIUINT32 errorCode, TAPIYNFLAG isLast, const TapAPIAccountInfo* info);
	/**
	* @brief 返回资金账户的资金信息
	* @param[in] sessionID 请求的会话ID；
	* @param[in] errorCode 错误码。0 表示成功。
	* @param[in] isLast 	标示是否是最后一批数据；
	* @param[in] info		指向返回的信息结构体。当errorCode不为0时，info为空。
	* @attention 不要修改和删除info所指示的数据；函数调用结束，参数不再有效。
	* @ingroup G_T_AccountDetails
	*/
	virtual void TAP_CDECL OnRspQryFund(TAPIUINT32 sessionID, TAPIINT32 errorCode, TAPIYNFLAG isLast, const TapAPIFundData* info);
	/**
	* @brief	用户资金变化通知
	* @details	用户的委托成交后会引起资金数据的变化，因此需要向用户实时反馈。
	* @param[in] info		指向返回的信息结构体。当errorCode不为0时，info为空。
	* @note 如果不关注此项内容，可以设定Login时的NoticeIgnoreFlag以屏蔽。
	* @attention 不要修改和删除info所指示的数据；函数调用结束，参数不再有效。
	* @ingroup G_T_AccountDetails
	*/
	virtual void TAP_CDECL OnRtnFund(const TapAPIFundData* info);
	/**
	* @brief 返回系统中的交易所信息
	* @param[in] sessionID 请求的会话ID；
	* @param[in] errorCode 错误码。0 表示成功。
	* @param[in] isLast 	标示是否是最后一批数据；
	* @param[in] info		指向返回的信息结构体。当errorCode不为0时，info为空。
	* @attention 不要修改和删除info所指示的数据；函数调用结束，参数不再有效。
	* @ingroup G_T_TradeSystem
	*/
	virtual void TAP_CDECL OnRspQryExchange(TAPIUINT32 sessionID, TAPIINT32 errorCode, TAPIYNFLAG isLast, const TapAPIExchangeInfo* info);
	/**
	* @brief	返回系统中品种信息
	* @details	此回调接口用于向用户返回得到的所有品种信息。
	* @param[in] sessionID 请求的会话ID，和GetAllCommodities()函数返回对应；
	* @param[in] errorCode 错误码。0 表示成功。
	* @param[in] isLast 	标示是否是最后一批数据；
	* @param[in] info		指向返回的信息结构体。当errorCode不为0时，info为空。
	* @attention 不要修改和删除info所指示的数据；函数调用结束，参数不再有效。
	* @ingroup G_T_Commodity
	*/
	virtual void TAP_CDECL OnRspQryCommodity(TAPIUINT32 sessionID, TAPIINT32 errorCode, TAPIYNFLAG isLast, const TapAPICommodityInfo* info);
	/**
	* @brief 返回系统中合约信息
	* @param[in] sessionID 请求的会话ID；
	* @param[in] errorCode 错误码。0 表示成功。
	* @param[in] isLast 	标示是否是最后一批数据；
	* @param[in] info		指向返回的信息结构体。当errorCode不为0时，info为空。
	* @attention 不要修改和删除info所指示的数据；函数调用结束，参数不再有效。
	* @ingroup G_T_Contract
	*/
	virtual void TAP_CDECL OnRspQryContract(TAPIUINT32 sessionID, TAPIINT32 errorCode, TAPIYNFLAG isLast, const TapAPITradeContractInfo* info);
	/**
	* @brief	返回新增合约信息
	* @details	向用户推送新的合约。主要用来处理在交易时间段中服务器添加了新合约时，向用户发送这个合约的信息。
	* @param[in] info		指向返回的信息结构体。当errorCode不为0时，info为空。
	* @attention 不要修改和删除info所指示的数据；函数调用结束，参数不再有效。
	* @ingroup G_T_Contract
	*/
	virtual void TAP_CDECL OnRtnContract(const TapAPITradeContractInfo* info);
	/**
	* @brief 返回新委托。新下的或者其他地方下的推送过来的。
	* @details	服务器接收到客户下的委托内容后就会保存起来等待触发，同时向用户回馈一个
	*			新委托信息说明服务器正确处理了用户的请求，返回的信息中包含了全部的委托信息，
	*			同时有一个用来标示此委托的委托号。
	* @param[in] info 指向返回的信息结构体。当errorCode不为0时，info为空。
	* @note 如果不关注此项内容，可以设定Login时的NoticeIgnoreFlag以屏蔽。
	* @attention 不要修改和删除info所指示的数据；函数调用结束，参数不再有效。
	* @ingroup G_T_TradeActions
	*/
	virtual void TAP_CDECL OnRtnOrder(const TapAPIOrderInfoNotice* info);
	/**
	* @brief	返回对报单的主动操作结果
	* @details	如下单，撤单等操作的结果。
	* @param[in] sessionID 请求的会话ID；
	* @param[in] errorCode 错误码。0 表示成功。
	* @param[in] info 报单的具体信息。当errorCode不为0时，info为空。
	* @attention 不要修改和删除info所指示的数据；函数调用结束，参数不再有效。
	* @note 该接口目前没有用到，所有操作结果通过OnRtnOrder返回
	* @ingroup G_T_TradeActions
	*/
	virtual void TAP_CDECL OnRspOrderAction(TAPIUINT32 sessionID, TAPIUINT32 errorCode, const TapAPIOrderActionRsp* info);
	/**
	* @brief	返回查询的委托信息
	* @details	返回用户查询的委托的具体信息。
	* @param[in] sessionID 请求的会话ID；
	* @param[in] errorCode 错误码。0 表示成功。
	* @param[in] isLast 标示是否是最后一批数据；
	* @param[in] info 指向返回的信息结构体。当errorCode不为0时，info为空。
	* @attention 不要修改和删除info所指示的数据；函数调用结束，参数不再有效。
	* @ingroup G_T_TradeInfo
	*/
	virtual void TAP_CDECL OnRspQryOrder(TAPIUINT32 sessionID, TAPIINT32 errorCode, TAPIYNFLAG isLast, const TapAPIOrderInfo* info);
	/**
	* @brief 返回查询的委托变化流程信息
	* @param[in] sessionID 请求的会话ID；
	* @param[in] errorCode 错误码，当errorCode==0时，info指向返回的委托变化流程结构体，不然为NULL；
	* @param[in] isLast 标示是否是最后一批数据；
	* @param[in] info 返回的委托变化流程指针。
	* @attention 不要修改和删除info所指示的数据；函数调用结束，参数不再有效。
	* @ingroup G_T_TradeInfo
	*/
	virtual void TAP_CDECL OnRspQryOrderProcess(TAPIUINT32 sessionID, TAPIINT32 errorCode, TAPIYNFLAG isLast, const TapAPIOrderInfo* info);
	/**
	* @brief 返回查询的成交信息
	* @param[in] sessionID 请求的会话ID；
	* @param[in] errorCode 错误码。0 表示成功。
	* @param[in] isLast 	标示是否是最后一批数据；
	* @param[in] info		指向返回的信息结构体。当errorCode不为0时，info为空。
	* @attention 不要修改和删除info所指示的数据；函数调用结束，参数不再有效。
	* @ingroup G_T_TradeInfo
	*/
	virtual void TAP_CDECL OnRspQryFill(TAPIUINT32 sessionID, TAPIINT32 errorCode, TAPIYNFLAG isLast, const TapAPIFillInfo* info);
	/**
	* @brief	推送来的成交信息
	* @details	用户的委托成交后将向用户推送成交信息。
	* @param[in] info		指向返回的信息结构体。当errorCode不为0时，info为空。
	* @note 如果不关注此项内容，可以设定Login时的NoticeIgnoreFlag以屏蔽。
	* @attention 不要修改和删除info所指示的数据；函数调用结束，参数不再有效。
	* @ingroup G_T_TradeActions
	*/
	virtual void TAP_CDECL OnRtnFill(const TapAPIFillInfo* info);
	/**
	* @brief 返回查询的持仓
	* @param[in] sessionID 请求的会话ID；
	* @param[in] errorCode 错误码。0 表示成功。
	* @param[in] isLast 	标示是否是最后一批数据；
	* @param[in] info		指向返回的信息结构体。当errorCode不为0时，info为空。
	* @attention 不要修改和删除info所指示的数据；函数调用结束，参数不再有效。
	* @ingroup G_T_TradeInfo
	*/
	virtual void TAP_CDECL OnRspQryPosition(TAPIUINT32 sessionID, TAPIINT32 errorCode, TAPIYNFLAG isLast, const TapAPIPositionInfo* info);
	/**
	* @brief 持仓变化推送通知
	* @param[in] info		指向返回的信息结构体。当errorCode不为0时，info为空。
	* @note 如果不关注此项内容，可以设定Login时的NoticeIgnoreFlag以屏蔽。
	* @attention 不要修改和删除info所指示的数据；函数调用结束，参数不再有效。
	* @ingroup G_T_TradeActions
	*/
	virtual void TAP_CDECL OnRtnPosition(const TapAPIPositionInfo* info);
	/**
	* @brief 返回查询的平仓
	* @param[in] sessionID 请求的会话ID；
	* @param[in] errorCode 错误码。0 表示成功。
	* @param[in] isLast 	标示是否是最后一批数据；
	* @param[in] info		指向返回的信息结构体。当errorCode不为0时，info为空。
	* @attention 不要修改和删除info所指示的数据；函数调用结束，参数不再有效。
	* @ingroup G_T_TradeInfo
	*/
	virtual void TAP_CDECL OnRspQryClose(TAPIUINT32 sessionID, TAPIINT32 errorCode, TAPIYNFLAG isLast, const TapAPICloseInfo* info);
	/**
	* @brief 平仓数据变化推送
	* @param[in] info		指向返回的信息结构体。当errorCode不为0时，info为空。
	* @note 如果不关注此项内容，可以设定Login时的NoticeIgnoreFlag以屏蔽。
	* @attention 不要修改和删除info所指示的数据；函数调用结束，参数不再有效。
	* @ingroup G_T_TradeActions
	*/
	virtual void TAP_CDECL OnRtnClose(const TapAPICloseInfo* info);
	/**
	* @brief 持仓盈亏通知
	* @param[in] info		指向返回的信息结构体。当errorCode不为0时，info为空。
	* @note 如果不关注此项内容，可以设定Login时的NoticeIgnoreFlag以屏蔽。
	* @attention 不要修改和删除info所指示的数据；函数调用结束，参数不再有效。
	* @ingroup G_T_TradeActions
	*/
	virtual void TAP_CDECL OnRtnPositionProfit(const TapAPIPositionProfitNotice* info);
	/**
	* @brief 深度行情查询应答
	* @param[in] sessionID 请求的会话ID；
	* @param[in] errorCode 错误码。0 表示成功。
	* @param[in] isLast 	标示是否是最后一批数据；
	* @param[in] info	  指向返回的深度行情信息结构体。当errorCode不为0时，info为空。
	* @attention 不要修改和删除info所指示的数据；函数调用结束，参数不再有效。
	* @ingroup G_T_DeepQuote
	*/
	virtual void TAP_CDECL OnRspQryDeepQuote(TAPIUINT32 sessionID, TAPIINT32 errorCode, TAPIYNFLAG isLast, const TapAPIDeepQuoteQryRsp* info);
	/**
	* @brief 交易所时间状态信息查询应答
	* @param[in] sessionID 请求的会话ID；
	* @param[in] errorCode 错误码。0 表示成功。
	* @param[in] isLast 	标示是否是最后一批数据
	* @param[in] info		指向返回的信息结构体。当errorCode不为0时，info为空。
	* @attention  不要修改和删除info所指示的数据；函数调用结束，参数不再有效。
	* @ingroup G_T_TradeSystem
	*/
	virtual void TAP_CDECL OnRspQryExchangeStateInfo(TAPIUINT32 sessionID, TAPIINT32 errorCode, TAPIYNFLAG isLast, const TapAPIExchangeStateInfo* info);
	/**
	* @brief 交易所时间状态信息通知
	* @param[in] info		指向返回的信息结构体。当errorCode不为0时，info为空。
	* @attention  不要修改和删除info所指示的数据；函数调用结束，参数不再有效。
	* @ingroup G_T_TradeSystem
	*/
	virtual void TAP_CDECL OnRtnExchangeStateInfo(const TapAPIExchangeStateInfoNotice* info);
	/**
	* @brief 询价通知
	* @param[in] info		指向返回的信息结构体。当errorCode不为0时，info为空。
	* @attention 不要修改和删除info所指示的数据；函数调用结束，参数不再有效。
	* @ingroup G_T_TradeActions
	*/
	virtual void TAP_CDECL OnRtnReqQuoteNotice(const TapAPIReqQuoteNotice* info);

	/**
	* @brief 上手信息查询应答
	* @param[in] sessionID 请求的会话ID；
	* @param[in] errorCode 错误码。0 表示成功。
	* @param[in] isLast 	标示是否是最后一批数据
	* @param[in] info		指向返回的信息结构体。当errorCode不为0时，info为空。
	* @attention  不要修改和删除info所指示的数据；函数调用结束，参数不再有效。
	* @ingroup G_T_UpperChannelInfo
	*/
	virtual void TAP_CDECL OnRspUpperChannelInfo(TAPIUINT32 sessionID, TAPIINT32 errorCode, TAPIYNFLAG isLast, const TapAPIUpperChannelInfo* info);
	/**
* @brief 客户最终费率应答
	* @details   保证金比例计算方式：手数*每手乘数*计算参数*价格\n
	*             保证金定额计算方式：手数*计算参数\n
	*             手续费绝对方式计算方式：手数*按手数计算参数+手数*每手乘数*价格*按金额计算参数
* @param[in] sessionID 请求的会话ID；
* @param[in] errorCode 错误码。0 表示成功。
* @param[in] isLast 	标示是否是最后一批数据
* @param[in] info		指向返回的信息结构体。当errorCode不为0时，info为空。
* @attention  不要修改和删除info所指示的数据；函数调用结束，参数不再有效。
* @ingroup G_T_AccountRentInfo
*/
	virtual void TAP_CDECL OnRspAccountRentInfo(TAPIUINT32 sessionID, TAPIINT32 errorCode, TAPIYNFLAG isLast, const TapAPIAccountRentInfo* info);
	/**
	* @brief 用户提交用户登录信息应答。(直连和中继用户都会收到应答)
	* @param[in] sessionID 请求的会话ID；
	* @param[in] errorCode 错误码。0 表示成功。
	* @param[in] isLast 	标示是否是最后一批数据
	* @param[in] info		指向返回的信息结构体。当errorCode不为0时，info为空。
	* @attention  不要修改和删除info所指示的数据；函数调用结束，参数不再有效。
	* @ingroup G_T_UserInfo
	*/
	virtual void TAP_CDECL OnRspSubmitUserLoginInfo(TAPIUINT32 sessionID, TAPIINT32 errorCode, TAPIYNFLAG isLast, const TapAPISubmitUserLoginRspInfo* info);
	/**
	* @brief 查询用户账单应答
	* @details	查询txt文件格式时将回调数据写入到本地的txt文件中查看，查询pdf文件时，需要将回调数据转存到pdf文件中，用pdf阅读工具打开。
	*           写文件需要用二进制的方式写入。如果文件较大，数据会分包回调，isLast为APIYNFLAG_YES时，文件传送完毕。
	* @param[in] sessionID 请求的会话ID；
	* @param[in] errorCode 错误码。0 表示成功。
	* @param[in] info		指向返回的信息结构体。当errorCode不为0时，info为空。
	* @attention 不要修改和删除info所指示的数据；函数调用结束，参数不再有效。
	* @ingroup G_T_TradeInfo
	*/
	virtual void TAP_CDECL OnRspQryBill(TAPIUINT32 sessionID, TAPIINT32 errorCode, TAPIYNFLAG isLast, const TapAPIBillQryRsp* info);
	/**
	* @brief 客户现货库存查询应答
	* @param[in] sessionID 请求ID
	* @param[in] errorCode 错误码。0 表示成功。
	* @param[in] isLast 	标示是否是最后一批数据
	* @param[out] info	指向返回的信息结构体。
	* @attention  不要修改和删除pRspInfo所指示的数据；函数调用结束，参数不再有效。
	* @ingroup G_T_TradeInfo
	*/
	virtual void TAP_CDECL OnRspQryAccountStorage(TAPIUINT32 sessionID, TAPIINT32 errorCode, TAPIYNFLAG isLast, const TapAPIAccountStorageInfo* info);
	/**
	* @brief 客户现货库存通知
	* @param[out] pInfo	指向返回的信息结构体。
	* @attention  不要修改和删除pRspInfo所指示的数据；函数调用结束，参数不再有效。
	* @ingroup G_T_TradeInfo
	*/
	virtual void TAP_CDECL OnRtnAccountStorage(const TapAPIAccountStorageInfo* info);

    //-------------------------------------------------------------------------------------
    //task：任务
    //-------------------------------------------------------------------------------------

	void processTask();

	void processConnect(Task* task);

	void processRspLogin(Task* task);

	void processAPIReady(Task* task);

	void processDisconnect(Task* task);

	void processRspChangePassword(Task* task);

	void processRspSetReservedInfo(Task* task);

	void processRspQryAccount(Task* task);

	void processRspQryFund(Task* task);

	void processRtnFund(Task* task);

	void processRspQryExchange(Task* task);

	void processRspQryCommodity(Task* task);

	void processRspQryContract(Task* task);

	void processRtnContract(Task* task);

	void processRtnOrder(Task* task);

	void processRspOrderAction(Task* task);

	void processRspQryOrder(Task* task);

	void processRspQryOrderProcess(Task* task);

	void processRspQryFill(Task* task);

	void processRtnFill(Task* task);

	void processRspQryPosition(Task* task);

	void processRtnPosition(Task* task);

	void processRspQryClose(Task* task);

	void processRtnClose(Task* task);

	void processRtnPositionProfit(Task* task);

	void processRspQryDeepQuote(Task* task);

	void processRspQryExchangeStateInfo(Task* task);

	void processRtnExchangeStateInfo(Task* task);

	void processRtnReqQuoteNotice(Task* task);

	void processRspUpperChannelInfo(Task* task);

	void processRspAccountRentInfo(Task* task);

	void processRspSubmitUserLoginInfo(Task* task);

	void processRspQryBill(Task* task);

	void processRspQryAccountStorage(Task* task);

	void processRtnAccountStorage(Task* task);


    //-------------------------------------------------------------------------------------
    //data：回调函数的数据字典
    //error：回调函数的错误字典
    //id：请求id
    //last：是否为最后返回
    //i：整数
    //-------------------------------------------------------------------------------------
    
	virtual void onConnect() {};

	virtual void onRspLogin(int error, const dict& data) {};

	virtual void onAPIReady() {};

	virtual void onDisconnect(int reason) {};

	virtual void onRspChangePassword(unsigned int sessionID, int error) {};

	virtual void onRspSetReservedInfo(unsigned int sessionID, int error, string info) {};

	virtual void onRspQryAccount(unsigned int sessionID, unsigned int errorCode, char last, const dict& data) {};

	virtual void onRspQryFund(unsigned int sessionID, int error, char last, const dict& data) {};

	virtual void onRtnFund(const dict& data) {};

	virtual void onRspQryExchange(unsigned int sessionID, int error, char last, const dict& data) {};

	virtual void onRspQryCommodity(unsigned int sessionID, int error, char last, const dict& data) {};

	virtual void onRspQryContract(unsigned int sessionID, int error, char last, const dict& data) {};

	virtual void onRtnContract(const dict& data) {};

	virtual void onRtnOrder(const dict& data) {};

	virtual void onRspOrderAction(unsigned int sessionID, unsigned int errorCode, const dict& data) {};

	virtual void onRspQryOrder(unsigned int sessionID, int error, char last, const dict& data) {};

	virtual void onRspQryOrderProcess(unsigned int sessionID, int error, char last, const dict& data) {};

	virtual void onRspQryFill(unsigned int sessionID, int error, char last, const dict& data) {};

	virtual void onRtnFill(const dict& data) {};

	virtual void onRspQryPosition(unsigned int sessionID, int error, char last, const dict& data) {};

	virtual void onRtnPosition(const dict& data) {};

	virtual void onRspQryClose(unsigned int sessionID, int error, char last, const dict& data) {};

	virtual void onRtnClose(const dict& data) {};

	virtual void onRtnPositionProfit(const dict& data) {};

	virtual void onRspQryDeepQuote(unsigned int sessionID, int error, char last, const dict& data) {};

	virtual void onRspQryExchangeStateInfo(unsigned int sessionID, int error, char last, const dict& data) {};

	virtual void onRtnExchangeStateInfo(const dict& data) {};

	virtual void onRtnReqQuoteNotice(const dict& data) {};

	virtual void onRspUpperChannelInfo(unsigned int sessionID, int error, char last, const dict& data) {};

	virtual void onRspAccountRentInfo(unsigned int sessionID, int error, char last, const dict& data) {};

	virtual void onRspSubmitUserLoginInfo(unsigned int sessionID, int error, char last, const dict& data) {};

	virtual void onRspQryBill(unsigned int sessionID, int error, char last, const dict& data) {};

	virtual void onRspQryAccountStorage(unsigned int sessionID, int error, char last, const dict& data) {};

	virtual void onRtnAccountStorage(const dict& data) {};



    //-------------------------------------------------------------------------------------
    //req:主动函数的请求字典
    //-------------------------------------------------------------------------------------
	void createTapTradeAPI(const dict& req, int& iResult);

	void release();

	void init();

	int exit();

	int login(const dict&req);

	int disconnect();

	string getTapTradeAPIVersion();

	int setTapTradeAPIDataPath(string pPath);

	int setTapTradeAPILogLevel(string LogLevel);

	int setHostAddress(string IP, int port);

	int insertOrder(int sessionID, const dict& data);

	int cancelOrder(int sessionID, const dict& data);

	int qryAccount(int sessionID, const dict& req);

	int qryFund(int sessionID, const dict& req);

	int qryExchange(int sessionID);

	int qryCommodity(int sessionID);

	int qryContract(int sessionID, const dict& req);

	int qryOrder(int sessionID, const dict& req);

	int qryOrderProcess(int sessionID, const dict& req);

	int qryFill(int sessionID, const dict& req);

	int qryPosition(int sessionID, const dict& req);

	int qryClose(int sessionID, const dict& req);

	int qryDeepQuote(int sessionID, const dict& req);

	int qryExchangeStateInfo(int sessionID, const dict& req);

	int qryUpperChannel(int sessionID, const dict& req);

	int qryAccountRent(int sessionID, const dict& req);

	int qryBill(int sessionID, const dict& req);

	int qryAccountStorage(int sessionID, const dict& req);

};
