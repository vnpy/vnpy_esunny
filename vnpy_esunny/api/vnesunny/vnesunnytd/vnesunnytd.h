//系统
#ifdef WIN32
#include "stdafx.h"
#endif

#include "vnesunny.h"
#include "pybind11/pybind11.h"
#include "esunny/EsTradeAPI.h"
#include "esunny/TapDataCollectAPI.h"


using namespace pybind11;
using namespace EsTradeAPI;

//常量
#define ONCONNECT 0
#define ONRSPLOGIN 1
#define ONRTNCONTACTINFO 2
#define ONRSPREQUESTVERTIFICATECODE 3
#define ONRSPREQUESTVERIFYIDENTITY 4
#define ONRSPSETVERTIFICATECODE 5
#define ONRTNERRORMSG 6
#define ONAPIREADY 7
#define ONDISCONNECT 8
#define ONRSPSUBMITUSERLOGININFO 9
#define ONRSPCHANGEPASSWORD 10
#define ONRSPSETRESERVEDINFO 11
#define ONRTNCONTRACT 12
#define ONRTNFUND 13
#define ONRTNORDER 14
#define ONRSPORDERACTION 15
#define ONRSPQRYORDERPROCESS 16
#define ONRTNFILL 17
#define ONRTNPOSITION 18
#define ONRTNCLOSE 19
#define ONRTNPOSITIONPROFIT 20
#define ONRSPQRYDEEPQUOTE 21
#define ONRTNEXCHANGESTATEINFO 22
#define ONRTNREQQUOTENOTICE 23
#define ONRSPACCOUNTRENTINFO 24
#define ONRSPTRADEMESSAGE 25
#define ONRTNTRADEMESSAGE 26
#define ONRSPQRYHISORDER 27
#define ONRSPQRYHISORDERPROCESS 28
#define ONRSPQRYHISFILL 29
#define ONRSPQRYHISPOSITION 30
#define ONRSPQRYHISDELIVERY 31
#define ONRSPQRYACCOUNTCASHADJUST 32
#define ONRSPQRYBILL 33
#define ONRSPACCOUNTFEERENT 34
#define ONRSPACCOUNTMARGINRENT 35
#define ONRSPADDMOBILEDEVICE 36
#define ONRSPQRYMANAGEINFOFORESTAR 37
#define ONRSPQRYSYSTEMPARAMETER 38
#define ONRSPQRYTRADECENTERFRONTADDRESS 39
#define ONRTNCOMMODITYINFO 40
#define ONRTNCURRENCYINFO 41
#define ONRSPQRYACCOUNTSTORAGE 42
#define ONRTNACCOUNTSTORAGE 43
#define ONRSPQRYSPOTLOCK 44
#define ONRTNSPOTLOCK 45
#define ONRSPSPECIALORDERACTION 46
#define ONRTNSPECIALORDER 47
#define ONRTNCOMBINEPOSITION 48
#define ONRTNCONTRACTQUOTE 49
#define ONRSPQRYTRUSTDEVICE 50
#define ONRSPADDTRUSTDEVICE 51
#define ONRSPDELTRUSTDEVICE 52
#define ONRTNADDUSERRIGHT 53
#define ONRTNDELUSERRIGHT 54
#define ONRSPQRYMANAGERCONFIGFILE 55


///-------------------------------------------------------------------------------------
///C++ SPI的回调函数方法实现
///-------------------------------------------------------------------------------------

//API的继承实现
class TdApi : public IEsTradeAPINotify
{
private:
	IEsTradeAPI* api;            //API????
    thread task_thread;                    //????????????python???????????
    TaskQueue task_queue;                //???????
    bool active = false;                //??????

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

	virtual void ES_CDECL OnConnect(const TAPISTR_20 UserNo);
	/**
	* @brief	系统登录过程回调
	* @details	此函数为StartUser()登录函数的回调，调用StartUser()成功后建立了连接，然后API将向服务器发送登录认证信息，登录期间的数据发送情况和登录的回馈信息传递到此回调函数中。
	* @param[in] UserNo 登录用户UserNo
	* @param[in] nErrorCode 返回错误码,0表示成功
	* @param[in] pLoginRspInfo 登陆应答信息，如果nErrorCode!=0，则loginRspInfo=NULL。
	* @attention	该回调返回成功，说明用户登录成功。但是不代表当前登录用户准备完毕。
    * 
	* @ingroup G_T_Login
	*/
	virtual void ES_CDECL OnRspLogin(const TAPISTR_20 UserNo, TAPIINT32 nErrorCode, const TapAPITradeLoginRspInfo *pLoginRspInfo);
	/**
	* @brief	二次认证联系方式通知。(北斗星、股票专用)
	* @details	登录完成后，如果需要二次认证，会收到联系方式的通知，可以选择通知消息的一个联系方式（邮箱或者电话）,请求发送二次认证授权码。
	* @param[in] UserNo 登录用户UserNo
	* @param[in] nErrorCode 返回错误码,0表示成功
	* @param[in] isLast 标识是否是最后一条联系信息
	* @param[in] pInfo 认证方式信息，如果errorCode!=0，则ContactInfo为空。
	* @attention	该回调返回成功，说明需要二次认证，并且需要选择一个联系方式然后调用RequestVertificateCode()设置结束验证信息的方式和账号。
	*
    * @ingroup G_T_Login
	*/
	virtual void ES_CDECL OnRtnContactInfo(const TAPISTR_20 UserNo, TAPIINT32 nErrorCode, TAPIYNFLAG isLast, const TapAPISecondInfo* pInfo);
	/**
	* @brief	请求发送二次认证码应答。(北斗星、股票专用)
	* @details	请求获取二次认证授权码，后台发送邮件或者短信，并给出应答，包含发送序号以及认证码有效期
	* @param[in] UserNo 登录用户UserNo
	* @param[in] nSessionID 请求二次认证码会话ID
	* @param[in] nErrorCode 如果没有绑定联系，返回错误.
	* @param[in] isLast 标识是否是最后一条联系信息
	* @param[in] pInfo 二次认证码有效期，以分钟返回，在二次认证有效期内，可以重复设置二次认证码，但是不能再重新申请二次认证码。
	* @attention 该回调返回成功，然后调用SetVertificateCode()。
    * 
	* @ingroup G_T_Login
	*/
	virtual void ES_CDECL OnRspRequestVertificateCode(const TAPISTR_20 UserNo, TAPIUINT32 nSessionID, TAPIINT32 nErrorCode, TAPIYNFLAG isLast, const TapAPIVertificateCode *pInfo);
	/**
     * @brief	验证信息应答(北斗星、股票专用)
	 * @details	 重置密码时，首先要通过身份验证，验证通过才可以发送验证码请求，验证失败可以重新发起验证请求
     * @param UserNo 登录用户UserNo
     * @param nSessionID 验证信息会话ID
     * @param nErrorCode 错误码,0表示成功
     * @param isLast 标识是否是最后一条信息
     * @param pInfo 验证信息应答
     * @attention 该回调返回成功，然后调用RequestVertificateCode()。
     * 
	 * @ingroup G_T_Login
     */
    virtual void ES_CDECL OnRspRequestVerifyIdentity(const TAPISTR_20 UserNo, TAPIUINT32 nSessionID, TAPIINT32 nErrorCode, TAPIYNFLAG isLast, const TapAPIVerifyIdentity* pInfo);
    /**
     * @brief	验证码设置应答(北斗星、股票专用)
     * @param UserNo 登录用户UserNo
     * @param nSessionID 设置验证码会话ID
     * @param nErrorCode 错误码,0表示成功
     * @param isLast 标识是否是最后一条信息
     * @param pInfo 认证码信息
     * 
	 * @ingroup G_T_Login
     */
    virtual void ES_CDECL OnRspSetVertificateCode(const TAPISTR_20 UserNo, TAPIUINT32 nSessionID, TAPIINT32 nErrorCode, TAPIYNFLAG isLast, const TapAPISecondCertificationRsp *pInfo);
    /**
	* @brief 重要错误信息提示
	* @details 当API内部出现严重错误时提示用户错误信息
	* @param[in] UserNo 登录用户UserNo
	* @param[in] ErrorMsg 错误提示信息
	* @attention 该函数回调，则说明API运行时存在严重错误
    * 
	* @ingroup G_T_TradeSystem
	*/
	virtual void ES_CDECL OnRtnErrorMsg(const TAPISTR_20 UserNo, const TAPISTR_500 ErrorMsg);
	/**
	* @brief	通知用户API准备就绪
	* @details	只有用户回调收到此就绪通知时才能进行对应登录用户后续的各种操作。此回调函数是某个登录用户能否正常工作的标志。
	* @param[in] UserNo 登录用户UserNo
	* @attention 就绪后才可以进行后续操作
    * 
	* @ingroup G_T_Login
	*/
	virtual void ES_CDECL OnAPIReady(const TAPISTR_20 UserNo);
	/**
	* @brief API和服务失去连接的回调
	* @details 在API使用过程中主动或者被动与服务器服务失去连接后都会触发此回调通知用户与服务器的连接已经断开。
	* @param[in] UserNo 登录用户UserNo
	* @param[in] nReasonCode 断开原因代码
    * 
	* @ingroup G_T_Disconnect
	*/
	virtual void ES_CDECL OnDisconnect(const TAPISTR_20 UserNo, TAPIINT32 nReasonCode);
	/**
	* @brief 通知用户提交用户登录信息结果(启明星专用)
	* @param[in] UserNo 指向该信息对应的UserNo
	* @param[in] nSessionID 提交用户登录信息的请求ID,和SubmitUserLoginInfo返回的请求ID对应
	* @param[in] pRspInfo 指向返回的信息结构体
	* @attention 不要修改和删除pRspInfo所指示的数据；函数调用结束，参数不再有效。
    * 
	* @ingroup G_T_UserInfo
	*/
	virtual void ES_CDECL OnRspSubmitUserLoginInfo(const TAPISTR_20 UserNo, TAPIUINT32 nSessionID, const TapAPISubmitUserLoginInfoRsp *pRspInfo);
	/**
	* @brief 用户密码修改应答
	* @param[in] UserNo 指向该信息对应的UserNo
	* @param[in] nSessionID 修改密码的请求ID,和ChangePassword的请求ID对应
	* @param[in] nErrorCode 返回错误码，0表示成功
    * 
	* @ingroup G_T_UserInfo
	*/
	virtual void ES_CDECL OnRspChangePassword(const TAPISTR_20 UserNo, TAPIUINT32 nSessionID, TAPIINT32 nErrorCode, const TapAPIChangePasswordRsp* pInfo);
	/**
	* @brief 设置用户预留信息反馈
	* @param[in] UserNo 指向该信息对应的UserNo
	* @param[in] nSessionID 设置用户预留信息的请求ID
	* @param[in] nErrorCode 返回错误码，0表示成功
	* @param[in] info 指向返回的信息结构体
	* @attention 不要修改和删除info所指示的数据；函数调用结束，参数不再有效。
	* @note 该接口暂未实现
    * 
	* @ingroup G_T_UserInfo
	*/
	virtual void ES_CDECL OnRspSetReservedInfo(const TAPISTR_20 UserNo, TAPIUINT32 nSessionID, TAPIINT32 nErrorCode, const TAPISTR_50 info);
	/**
	* @brief	返回新增合约信息(启明星、北斗星专用)
	* @details	向用户推送新的合约。主要用来处理在交易时间段中服务器添加了新合约时，向用户发送这个合约的信息。
	* @param[in] UserNo 指向该信息对应的UserNo
	* @param[in] pRtnInfo	指向返回的信息结构体
	* @attention 不要修改和删除pRspInfo所指示的数据；函数调用结束，参数不再有效。
	* 
	* @ingroup G_T_Contract
	*/
	virtual void ES_CDECL OnRtnContract(const TAPISTR_20 UserNo, const TapAPITradeContractInfo *pRtnInfo);
	/**
	* @brief 用户资金变化通知
	* @details 用户的委托成交后会引起资金数据的变化，因此需要向用户实时反馈。
	* @param[in] UserNo 指向该信息对应的UserNo
	* @param[in] pRtnInfo 指向返回的信息结构体
	* @note 如果不关注此项内容，可以设定Login时的NoticeIgnoreFlag以屏蔽。
	* @attention 不要修改和删除pRspInfo所指示的数据；函数调用结束，参数不再有效。
	*
	* @ingroup G_T_FundInfo
	*/
	virtual void ES_CDECL OnRtnFund(const TAPISTR_20 UserNo, const TapAPIFundData *pRtnInfo);
	/**
	* @brief 返回新委托。新下的或者其他地方下的推送过来的
	* @details 服务器接收到客户下的委托内容后就会触发委托处理逻辑，同时向用户回馈一个委托应答说明服务器正确处理了用户的请求，返回的信息中包含了全部的委托信息，
	*			同时有一个用来标示此委托的委托号。如果是本地发出去的委托，委托应答中会返回请求ID
	* @param[in] UserNo 指向该信息对应的UserNo
	* @param[in] nRequestID 请求的会话ID
	* @param[in] pRtnInfo 指向返回的信息结构体
	* @note 如果不关注此项内容，可以设定Login时的NoticeIgnoreFlag以屏蔽。
	* @attention 不要修改和删除pRspInfo所指示的数据；函数调用结束，参数不再有效。
	*
	* @ingroup G_T_TradeActions
	*/
	virtual void ES_CDECL OnRtnOrder(const TAPISTR_20 UserNo, TAPIUINT32 nRequestID, const TapAPIOrderInfo *pRtnInfo);
	/**
    * @brief	订单操作应答(北斗星、股票专用)
    * @details	下单、撤单、改单应答。下单都会有次应答回调，如果下单请求结构中没有填写合约或者资金账号，则仅返回错误号.
    *     撤单、改单错误有应答和OnRtnOrder，成功仅返回OnRtnOrder回调。
    * @param[in] nRequestID 请求的会话ID
    * @param[in] nErrorCode 错误码。0 表示成功
    * @param[in] pRtnInfo 指向返回的信息结构体
    * @attention 不要修改和删除pRtnInfo所指示的数据；函数调用结束，参数不再有效。
    *
    * @ingroup G_T_TradeActions
    */
    virtual void ES_CDECL OnRspOrderAction(const TAPISTR_20 UserNo, TAPIUINT32 nRequestID, TAPIINT32 nErrorCode, const TapAPIOrderActionRsp *pRtnInfo);
    /**
	* @brief 返回查询的委托变化流程信息
	* @param[in] UserNo 指向该信息对应的UserNo
	* @param[in] nRequestID 请求的会话ID
	* @param[in] nErrorCode 错误码。0 表示成功
	* @param[in] isLast 标示是否是最后一批数据
	* @param[in] pRspInfo 指向返回的信息结构体
	* @attention 不要修改和删除pRspInfo所指示的数据；函数调用结束，参数不再有效。
	*
	* @ingroup G_T_TradeInfo
	*/
	virtual void ES_CDECL OnRspQryOrderProcess(const TAPISTR_20 UserNo, TAPIUINT32 nRequestID, TAPIINT32 nErrorCode, TAPIYNFLAG isLast, const TapAPIOrderInfo *pRspInfo);
	/**
	* @brief 推送来的成交信息
	* @details 用户的委托成交后将向用户推送成交信息
	* @param[in] UserNo 指向该信息对应的UserNo
	* @param[in] pRtnInfo 指向返回的信息结构体
	* @note 如果不关注此项内容，可以设定Login时的NoticeIgnoreFlag以屏蔽。
	* @attention 不要修改和删除pRspInfo所指示的数据；函数调用结束，参数不再有效。
	*
	* @ingroup G_T_TradeActions
	*/
	virtual void ES_CDECL OnRtnFill(const TAPISTR_20 UserNo, const TapAPIFillInfo *pRtnInfo);
	/**
	* @brief 持仓变化推送通知
	* @param[in] UserNo 指向该信息对应的UserNo
	* @param[in] pRtnInfo 指向返回的信息结构体
	* @note 如果不关注此项内容，可以设定Login时的NoticeIgnoreFlag以屏蔽。
	* @attention 不要修改和删除pRspInfo所指示的数据；函数调用结束，参数不再有效。
	*
	* @ingroup G_T_TradeActions
	*/
	virtual void ES_CDECL OnRtnPosition(const TAPISTR_20 UserNo, const TapAPIPositionInfo *pRtnInfo);
	/**
	* @brief 平仓数据变化推送(启明星专用)
	* @param[in] UserNo 指向该信息对应的UserNo
	* @param[in] pRtnInfo 指向返回的信息结构体
	* @note 如果不关注此项内容，可以设定Login时的NoticeIgnoreFlag以屏蔽。
	* @attention 不要修改和删除pRspInfo所指示的数据；函数调用结束，参数不再有效。
	*
	* @ingroup G_T_TradeActions
	*/
	virtual void ES_CDECL OnRtnClose(const TAPISTR_20 UserNo, const TapAPICloseInfo *pRtnInfo);
	/**
	* @brief 持仓盈亏通知(启明星专用)
	* @param[in] UserNo 指向该信息对应的UserNo
	* @param[in] pRtnInfo 指向返回的信息结构体
	* @note 如果不关注此项内容，可以设定Login时的NoticeIgnoreFlag以屏蔽。
	* @attention 不要修改和删除pRspInfo所指示的数据；函数调用结束，参数不再有效。
	*
	* @ingroup G_T_TradeActions
	*/
	virtual void ES_CDECL OnRtnPositionProfit(const TAPISTR_20 UserNo, const TapAPIPositionProfitNotice *pRtnInfo);
	/**
	* @brief 深度行情查询应答(启明星专用)
	* @param[in] UserNo 指向该信息对应的UserNo
	* @param[in] nRequestID 请求ID
	* @param[in] nErrorCode 错误码。0 表示成功
	* @param[in] isLast 标示是否是最后一批数据
	* @param[in] pRspInfo 指向返回的深度行情信息结构体。当nErrorCode不为0时，pRspInfo为空。
	* @attention 不要修改和删除pRspInfo所指示的数据；函数调用结束，参数不再有效。
	*
	* @ingroup G_T_DeepQuote
	*/
	virtual void ES_CDECL OnRspQryDeepQuote(const TAPISTR_20 UserNo, TAPIUINT32 nRequestID, TAPIINT32 nErrorCode, TAPIYNFLAG isLast, const TapAPIDeepQuoteQryRsp *pRspInfo);
	/**
	* @brief 交易所时间状态信息通知(启明星专用)
	* @param[out] UserNo 指向该信息对应的UserNo
	* @param[out] pRtnInfo 指向返回的信息结构体
	* @attention 不要修改和删除pRspInfo所指示的数据；函数调用结束，参数不再有效。
	*
	* @ingroup G_T_TradeSystem
	*/
	virtual void ES_CDECL OnRtnExchangeStateInfo(const TAPISTR_20 UserNo, const TapAPIExchangeStateInfoNotice *pRtnInfo);
	/**
	* @brief 询价通知(启明星、北斗星专用)
	* @param[in] UserNo 指向该信息对应的UserNo
	* @param[in] pRtnInfo 指向返回的信息结构体
	* @attention 不要修改和删除pRspInfo所指示的数据；函数调用结束，参数不再有效。
	*
	* @ingroup G_T_TradeActions
	*/
	virtual void ES_CDECL OnRtnReqQuoteNotice(const TAPISTR_20 UserNo, const TapAPIReqQuoteNotice *pRtnInfo);
	/**
	* @brief 客户最终费率应答(启明星专用)
	* @details 保证金比例计算方式：手数*每手乘数*计算参数*价格
	*          保证金定额计算方式：手数*计算参数
	*          手续费绝对方式计算方式：手数*按手数计算参数+手数*每手乘数*价格*按金额计算参数
	* @param[in] UserNo 指向该信息对应的UserNo
	* @param[in] nRequestID 请求ID
	* @param[in] nErrorCode 错误码。0 表示成功
	* @param[in] isLast 	标示是否是最后一批数据
	* @param[in] pRspInfo	指向返回的信息结构体
	* @attention  不要修改和删除pRspInfo所指示的数据；函数调用结束，参数不再有效。
	*
	* @ingroup G_T_AccountRentInfo
	*/
	virtual void ES_CDECL OnRspAccountRentInfo(const TAPISTR_20 UserNo, TAPIUINT32 nRequestID, TAPIINT32 nErrorCode, TAPIYNFLAG isLast, const TapAPIAccountRentInfo *pRspInfo);
	/**
	* @brief	交易消息查询应答
	* @details	用户可以查询相关的交易消息
	* @param[in] UserNo 指向该信息对应的UserNo
	* @param[in] nRequestID 请求ID
	* @param[in] nErrorCode 错误码。0 表示成功
	* @param[in] isLast 	标示是否是最后一批数据
	* @param[in] pRspInfo	指向返回的信息结构体
	* @attention 不要修改和删除pRspInfo所指示的数据；函数调用结束，参数不再有效。
	*
	* @ingroup G_T_TradeSystem
	*/
	virtual void ES_CDECL OnRspTradeMessage(const TAPISTR_20 UserNo, TAPIUINT32 nRequestID, TAPIINT32 nErrorCode, TAPIYNFLAG isLast, const TapAPITradeMessage *pRspInfo);
    /**
	* @brief	交易消息通知
	* @details	用户在交易过程中可能因为资金、持仓、平仓的状态变动使账户处于某些危险状态，或者某些重要的信息需要向用户通知。
	* @param[in] UserNo 指向该信息对应的UserNo
	* @param[in] pRtnInfo	指向返回的信息结构体
	* @attention 不要修改和删除pRtnInfo所指示的数据；函数调用结束，参数不再有效。
	*
	* @ingroup G_T_TradeSystem
	*/
	virtual void ES_CDECL OnRtnTradeMessage(const TAPISTR_20 UserNo, const TapAPITradeMessage *pRtnInfo);
	/**
	* @brief 历史委托查询应答(北斗星、股票专用)
	* @param[in] UserNo 指向该信息对应的UserNo
	* @param[in] nRequestID 请求的会话ID
	* @param[in] nErrorCode 错误码。0 表示成功
	* @param[in] isLast 	标示是否是最后一批数据
	* @param[in] pInfo		指向返回的信息结构体
	* @attention 不要修改和删除pInfo所指示的数据；函数调用结束，参数不再有效。
	*
	* @ingroup G_T_HisInfo
	*/
	virtual void ES_CDECL OnRspQryHisOrder(const TAPISTR_20 UserNo, TAPIUINT32 nRequestID, TAPIINT32 nErrorCode, TAPIYNFLAG isLast, const TapAPIHisOrderQryRsp *pInfo);
	/**
	* @brief 历史委托流程查询应答(北斗星、股票专用)
	* @param[in] UserNo 指向该信息对应的UserNo
	* @param[in] nRequestID 请求的会话ID
	* @param[in] nErrorCode 错误码。0 表示成功
	* @param[in] isLast 	标示是否是最后一批数据
	* @param[in] pInfo		指向返回的信息结构体
	* @attention 不要修改和删除pInfo所指示的数据；函数调用结束，参数不再有效。
	*
	* @ingroup G_T_HisInfo
	*/
	virtual void ES_CDECL OnRspQryHisOrderProcess(const TAPISTR_20 UserNo, TAPIUINT32 nRequestID, TAPIINT32 nErrorCode, TAPIYNFLAG isLast, const TapAPIHisOrderProcessQryRsp *pInfo);
	/**
	* @brief 历史成交查询应答(北斗星、股票专用)
	* @param[in] UserNo 指向该信息对应的UserNo
	* @param[in] nRequestID 请求的会话ID
	* @param[in] nErrorCode 错误码。0 表示成功
	* @param[in] isLast 	标示是否是最后一批数据
	* @param[in] pInfo		指向返回的信息结构体
	* @attention 不要修改和删除pInfo所指示的数据；函数调用结束，参数不再有效。
	*
	* @ingroup G_T_HisInfo
	*/
	virtual void ES_CDECL OnRspQryHisFill(const TAPISTR_20 UserNo, TAPIUINT32 nRequestID, TAPIINT32 nErrorCode, TAPIYNFLAG isLast, const TapAPIHisFillQryRsp *pInfo);
	/**
	* @brief 历史持仓查询应答(北斗星、股票专用)
	* @param[in] UserNo 指向该信息对应的UserNo
	* @param[in] nRequestID 请求的会话ID
	* @param[in] nErrorCode 错误码。0 表示成功
	* @param[in] isLast 	标示是否是最后一批数据
	* @param[in] pInfo		指向返回的信息结构体
	* @attention 不要修改和删除pInfo所指示的数据；函数调用结束，参数不再有效。
	*
	* @ingroup G_T_HisInfo
	*/
	virtual void ES_CDECL OnRspQryHisPosition(const TAPISTR_20 UserNo, TAPIUINT32 nRequestID, TAPIINT32 nErrorCode, TAPIYNFLAG isLast, const TapAPIHisPositionQryRsp *pInfo);
	/**
	* @brief 历史交割查询应答(北斗星专用)
	* @param[in] UserNo 指向该信息对应的UserNo
	* @param[in] nRequestID 请求的会话ID
	* @param[in] nErrorCode 错误码。0 表示成功
	* @param[in] isLast 	标示是否是最后一批数据
	* @param[in] pInfo		指向返回的信息结构体
	* @attention 不要修改和删除pInfo所指示的数据；函数调用结束，参数不再有效。
	*
	* @ingroup G_T_HisInfo
	*/
	virtual void ES_CDECL OnRspQryHisDelivery(const TAPISTR_20 UserNo, TAPIUINT32 nRequestID, TAPIINT32 nErrorCode, TAPIYNFLAG isLast, const TapAPIHisDeliveryQryRsp *pInfo);
	/**
	* @brief 资金调整查询应答(北斗星、股票专用)
	* @param[in] UserNo 指向该信息对应的UserNo
	* @param[in] nRequestID 请求的会话ID
	* @param[in] nErrorCode 错误码。0 表示成功
	* @param[in] isLast 	标示是否是最后一批数据
	* @param[in] pInfo		指向返回的信息结构体
	* @attention 不要修改和删除pInfo所指示的数据；函数调用结束，参数不再有效。
	*
	* @ingroup G_T_FundInfo
	*/
	virtual void ES_CDECL OnRspQryAccountCashAdjust(const TAPISTR_20 UserNo, TAPIUINT32 nRequestID, TAPIINT32 nErrorCode, TAPIYNFLAG isLast, const TapAPIAccountCashAdjustQryRsp *pInfo);
	/**
	* @brief 查询用户账单应答
	* @param[in] UserNo 指向该信息对应的UserNo
	* @param[in] nRequestID 请求的会话ID
	* @param[in] nErrorCode 错误码。0 表示成功
	* @param[in] isLast 	标示是否是最后一批数据
	* @param[in] pInfo		指向返回的信息结构体
	* @attention 不要修改和删除pInfo所指示的数据；函数调用结束，参数不再有效。
	*
	* @ingroup G_T_Bill
	*/
	virtual void ES_CDECL OnRspQryBill(const TAPISTR_20 UserNo, TAPIUINT32 nRequestID, TAPIINT32 nErrorCode, TAPIYNFLAG isLast, const TapAPIBillQryRsp *pInfo);
	/**
	* @brief 查询用户手续费参数(北斗星、股票专用)
	* @param[in] UserNo 指向该信息对应的UserNo
	* @param[in] nRequestID 请求的会话ID
	* @param[in] nErrorCode 错误码。0 表示成功
	* @param[in] isLast 	标示是否是最后一批数据
	* @param[in] pInfo		指向返回的信息结构体
	* @attention 不要修改和删除pInfo所指示的数据；函数调用结束，参数不再有效。
	*
	* @ingroup G_T_AccountRentInfo
	*/
	virtual void ES_CDECL OnRspAccountFeeRent(const TAPISTR_20 UserNo, TAPIUINT32 nRequestID, TAPIINT32 nErrorCode, TAPIYNFLAG isLast, const TapAPIAccountFeeRentQryRsp *pInfo);
	/**
	* @brief 查询用户保证金参数(北斗星专用)
	* @param[in] UserNo 指向该信息对应的UserNo
	* @param[in] nRequestID 请求的会话ID
	* @param[in] nErrorCode 错误码。0 表示成功
	* @param[in] isLast 	标示是否是最后一批数据
	* @param[in] pInfo		指向返回的信息结构体
	* @attention 不要修改和删除pInfo所指示的数据；函数调用结束，参数不再有效。
	*
	* @ingroup G_T_AccountRentInfo
	*/
	virtual void ES_CDECL OnRspAccountMarginRent(const TAPISTR_20 UserNo, TAPIUINT32 nRequestID, TAPIINT32 nErrorCode, TAPIYNFLAG isLast, const TapAPIAccountMarginRentQryRsp *pInfo);
	/**
	* @brief 登录用户手机设备增加应答(北斗星、股票专用)
	* @param[in] UserNo 登录用户UserNo
	* @param[in] nRequestID 请求ID
	* @param[in] nErrorCode 错误码。0 表示成功
	* @param[in] isLast 	标示是否是最后一批数据
	* @param[in] pInfo		指向返回的信息结构体
	* @attention 不要修改和删除pInfo所指示的数据；函数调用结束，参数不再有效。
	* @operationtype 异步操作
	*
	* @ingroup G_T_Cellphone
	*/
	virtual void ES_CDECL OnRspAddMobileDevice(const TAPISTR_20 UserNo, TAPIUINT32 nRequestID, TAPIINT32 nErrorCode, TAPIYNFLAG isLast, const TapAPIMobileDeviceAddRsp *pInfo);
	/**
	* @brief 管理日志查询(北斗星、股票专用)
	* @param[in] UserNo 登录用户UserNo
	* @param[in] nRequestID 请求ID
	* @param[in] nErrorCode 错误码。0 表示成功
	* @param[in] isLast 	标示是否是最后一批数据
	* @param[in] pInfo		指向返回的信息结构体
	* @attention 不要修改和删除pInfo所指示的数据；函数调用结束，参数不再有效。
	* @operationtype 异步操作
	*
	* @ingroup G_T_Cellphone
	*/
	virtual void ES_CDECL OnRspQryManageInfoForEStar(const TAPISTR_20 UserNo, TAPIUINT32 nRequestID, TAPIINT32 nErrorCode, TAPIYNFLAG isLast, const TapAPIManageInfo *pInfo);
	/**
	* @brief 系统参数查询(北斗星、股票专用)
	* @param[in] UserNo 登录用户UserNo
	* @param[in] nRequestID 请求ID
	* @param[in] nErrorCode 错误码。0 表示成功
	* @param[in] isLast 	标示是否是最后一批数据
	* @param[in] pInfo		指向返回的信息结构体
	* @attention 不要修改和删除pInfo所指示的数据；函数调用结束，参数不再有效。
	* @operationtype 异步操作
	*
	* @ingroup G_T_Cellphone
	*/
	virtual void ES_CDECL OnRspQrySystemParameter(const TAPISTR_20 UserNo, TAPIUINT32 nRequestID, TAPIINT32 nErrorCode, TAPIYNFLAG isLast, const TapAPISystemParameterInfo *pInfo);
	/**
	* @brief 交易中心前置地址信息查询(北斗星、股票专用)
	* @param[in] UserNo 登录用户UserNo
	* @param[in] nRequestID 请求ID
	* @param[in] nErrorCode 错误码。0 表示成功
	* @param[in] isLast 	标示是否是最后一批数据
	* @param[in] pInfo		指向返回的信息结构体
	* @attention 不要修改和删除pInfo所指示的数据；函数调用结束，参数不再有效。
	* @operationtype 异步操作
	*
	* @ingroup G_T_Cellphone
	*/
	virtual void ES_CDECL OnRspQryTradeCenterFrontAddress(const TAPISTR_20 UserNo, TAPIUINT32 nRequestID, TAPIINT32 nErrorCode, TAPIYNFLAG isLast, const TapAPITradeCenterFrontAddressInfo *pInfo);
	/**
	* @brief 品种信息通知(北斗星专用)
	* @param[in] UserNo 指向该信息对应的UserNo
	* @param[in] pInfo	指向返回的信息结构体
	* @attention  不要修改和删除pRspInfo所指示的数据；函数调用结束，参数不再有效。
	*
	* @ingroup G_T_Commodity
	*/
	virtual void ES_CDECL OnRtnCommodityInfo(const TAPISTR_20 UserNo, const TapAPICommodityInfo *pInfo);
	/**
	* @brief 币种信息通知(北斗星专用)
	* @param[in] UserNo 指向该信息对应的UserNo
	* @param[in] pInfo	指向返回的信息结构体
	* @attention  不要修改和删除pRspInfo所指示的数据；函数调用结束，参数不再有效。
	*
	* @ingroup G_T_TradeSystem
	*/
	virtual void ES_CDECL OnRtnCurrencyInfo(const TAPISTR_20 UserNo, const TapAPICurrencyInfo *pInfo);
    /**
    * @brief 客户现货库存查询应答(启明星专用)
	* @param[in] UserNo 指向该信息对应的UserNo
	* @param[in] nRequestID 请求ID
	* @param[in] nErrorCode 错误码。0 表示成功
	* @param[in] isLast 	标示是否是最后一批数据
	* @param[in] pInfo	指向返回的信息结构体
	* @attention  不要修改和删除pRspInfo所指示的数据；函数调用结束，参数不再有效。
	*
	* @ingroup G_T_TradeActions
    */
    virtual void ES_CDECL OnRspQryAccountStorage(const TAPISTR_20 UserNo, TAPIUINT32 nRequestID, TAPIINT32 nErrorCode, TAPIYNFLAG isLast, const TapAPIAccountStorageInfo* pInfo);
    /**
    * @brief 客户现货库存通知(启明星专用)
	* @param[in] UserNo 指向该信息对应的UserNo
	* @param[in] pInfo	指向返回的信息结构体
	* @attention  不要修改和删除pRspInfo所指示的数据；函数调用结束，参数不再有效。
	*
	* @ingroup G_T_TradeActions
    */
    virtual void ES_CDECL OnRtnAccountStorage(const TAPISTR_20 UserNo, const TapAPIAccountStorageInfo* pInfo);
    /**
    * @brief 客户现货锁定量查询应答(北斗星专用)
	* @param[in] UserNo 指向该信息对应的UserNo
	* @param[in] nRequestID 请求ID
	* @param[in] nErrorCode 错误码。0 表示成功
	* @param[in] isLast 	标示是否是最后一批数据
	* @param[in] pInfo	指向返回的信息结构体
	* @attention  不要修改和删除pRspInfo所指示的数据；函数调用结束，参数不再有效。
	*
	* @ingroup G_T_TradeActions
    */
    virtual void ES_CDECL OnRspQrySpotLock(const TAPISTR_20 UserNo, TAPIUINT32 nRequestID, TAPIINT32 nErrorCode, TAPIYNFLAG isLast, const TapAPISpotLockInfo* pInfo);
    /**
    * @brief 客户现货锁定量通知(北斗星专用)
	* @param[in] UserNo 指向该信息对应的UserNo
	* @param[in] pInfo	指向返回的信息结构体
	* @attention  不要修改和删除pRspInfo所指示的数据；函数调用结束，参数不再有效。
	*
	* @ingroup G_T_TradeActions
    */
    virtual void ES_CDECL OnRtnSpotLock(const TAPISTR_20 UserNo, const TapAPISpotLockInfo* pInfo);
    /**
    * @brief	特殊业务委托操作应答(ETF专用)
	* @param[in] UserNo 指向该信息对应的UserNo
    * @details	特殊业务操作都会有次应答回调，sessionID标识请求对应的sessionID，以便确定该笔应答对应的请求。
    * @param[in] sessionID 请求的会话ID
    * @param[in] errorCode 错误码。0 表示成功
    * @param[in] pRtnInfo 指向返回的信息结构体
    * @attention 不要修改和删除pRtnInfo所指示的数据；函数调用结束，参数不再有效。
	*
    * @ingroup G_T_ETF
    */
    virtual void ES_CDECL OnRspSpecialOrderAction(const TAPISTR_20 UserNo, TAPIUINT32 nRequestID, TAPIINT32 nErrorCode, const TapAPISpecialOrderInfo *pRtnInfo);
    /**
    * @brief 客户特殊业务委托通知(ETF专用)
 	* @param[in] UserNo 指向该信息对应的UserNo
    * @param[in] nRequestID 请求ID
    * @param[in] nErrorCode 错误码。0 表示成功
    * @param[out] pInfo	指向返回的信息结构体
    * @attention  不要修改和删除pRspInfo所指示的数据；函数调用结束，参数不再有效。
	*
    * @ingroup G_T_ETF
    */
    virtual void ES_CDECL OnRtnSpecialOrder(const TAPISTR_20 UserNo, TAPIUINT32 nRequestID, const TapAPISpecialOrderInfo* pInfo);
    /**
    * @brief 客户组合持仓通知(ETF专用)
	* @param[out] UserNo 指向该信息对应的UserNo
	* @param[out] pInfo	指向返回的信息结构体
	* @attention  不要修改和删除pRspInfo所指示的数据；函数调用结束，参数不再有效。
	*
	* @ingroup G_T_ETF
    */
    virtual void ES_CDECL OnRtnCombinePosition(const TAPISTR_20 UserNo, const TapAPICombinePositionInfo* pInfo);
    /**
    * @brief 交易合约行情信息通知(北斗星、股票专用)
	* @param[out] UserNo 指向该信息对应的UserNo
	* @param[out] pInfo	指向返回的信息结构体
	* @attention  不要修改和删除pRspInfo所指示的数据；函数调用结束，参数不再有效。
	*
	* @ingroup G_T_TradeActions 
    */
    virtual void ES_CDECL OnRtnContractQuote(const TAPISTR_20 UserNo, const TapAPIContractQuoteInfo* pInfo);
    /**
    * @brief 用户信任设备查询应答(北斗星、股票专用)
	* @param[in] UserNo 指向该信息对应的UserNo
	* @param[in] nRequestID 请求ID
	* @param[in] nErrorCode 错误码。0 表示成功
	* @param[in] isLast 	标示是否是最后一批数据
	* @param[in] pInfo	指向返回的信息结构体
	* @attention  不要修改和删除pRspInfo所指示的数据；函数调用结束，参数不再有效。
	*
	* @ingroup G_T_UserInfo
    */
    virtual void ES_CDECL OnRspQryTrustDevice(const TAPISTR_20 UserNo, TAPIUINT32 nRequestID, TAPIINT32 nErrorCode, TAPIYNFLAG isLast, const TapAPITrustDeviceInfo* pInfo);
    /**
    * @brief 用户信任设备增加应答(北斗星、股票专用)
	* @param[in] UserNo 指向该信息对应的UserNo
	* @param[in] nRequestID 请求ID
	* @param[in] nErrorCode 错误码。0 表示成功
	* @param[in] isLast 	标示是否是最后一批数据
	* @param[in] pInfo	指向返回的信息结构体
	* @attention  不要修改和删除pRspInfo所指示的数据；函数调用结束，参数不再有效。
	*
	* @ingroup G_T_UserInfo
    */
    virtual void ES_CDECL OnRspAddTrustDevice(const TAPISTR_20 UserNo, TAPIUINT32 nRequestID, TAPIINT32 nErrorCode, TAPIYNFLAG isLast, const TapAPITrustDeviceAddRsp* pInfo);
    /**
    * @brief 用户信任设备删除应答(北斗星、股票专用)
	* @param[in] UserNo 指向该信息对应的UserNo
	* @param[in] nRequestID 请求ID
	* @param[in] nErrorCode 错误码。0 表示成功
	* @param[in] isLast 	标示是否是最后一批数据
	* @param[in] pInfo	指向返回的信息结构体
	* @attention  不要修改和删除pRspInfo所指示的数据；函数调用结束，参数不再有效。
	*
	* @ingroup G_T_UserInfo
    */
    virtual void ES_CDECL OnRspDelTrustDevice(const TAPISTR_20 UserNo, TAPIUINT32 nRequestID, TAPIINT32 nErrorCode, TAPIYNFLAG isLast, const TapAPITrustDeviceDelRsp* pInfo);
    /**
    * @brief 用户权限增加通知(北斗星专用)
	* @param[out] UserNo 指向该信息对应的UserNo
	* @param[out] pInfo	指向返回的信息结构体
	* @attention  不要修改和删除pRspInfo所指示的数据；函数调用结束，参数不再有效。
	*
	* @ingroup G_T_UserInfo 
    */
    virtual void ES_CDECL OnRtnAddUserRight(const TAPISTR_20 UserNo, const TapAPIUserRightInfo* pInfo);
    /**
    * @brief 用户权限删除通知(北斗星专用)
	* @param[out] UserNo 指向该信息对应的UserNo
	* @param[out] pInfo	指向返回的信息结构体
	* @attention  不要修改和删除pRspInfo所指示的数据；函数调用结束，参数不再有效。
	*
	* @ingroup G_T_UserInfo 
    */
    virtual void ES_CDECL OnRtnDelUserRight(const TAPISTR_20 UserNo, const TapAPIUserRightInfo* pInfo);
    /**
    * @brief 柜台配置文件查询应答结构(北斗星、股票专用)
    * @param[out] UserNo 指向该信息对应的UserNo
    * @param[out] nRequestID 请求ID
    * @param[out] nErrorCode 错误码。0 表示成功
    * @param[out] isLast 标示是否是最后一批数据
    * @param[out] pInfo 指向返回的信息结构体
	* @attention  不要修改和删除pRspInfo所指示的数据；函数调用结束，参数不再有效。
    * 
	* @ingroup G_T_TradeSystem
    */
    virtual void ES_CDECL OnRspQryManagerConfigFile(const TAPISTR_20 UserNo, TAPIUINT32 nRequestID, TAPIINT32 nErrorCode, TAPIYNFLAG isLast, const TapAPIManagerConfigFileQryRsp* pInfo);



    //-------------------------------------------------------------------------------------
    //task：任务
    //-------------------------------------------------------------------------------------

	void processTask();

    void processConnect(Task *task);
    
    void processRspLogin(Task *task);
    
    void processRtnContactInfo(Task *task);
    
    void processRspRequestVertificateCode(Task *task);
    
    void processRspRequestVerifyIdentity(Task *task);
    
    void processRspSetVertificateCode(Task *task);
    
    void processRtnErrorMsg(Task *task);
    
    void processAPIReady(Task *task);
    
    void processDisconnect(Task *task);
    
    void processRspSubmitUserLoginInfo(Task *task);
    
    void processRspChangePassword(Task *task);
    
    void processRspSetReservedInfo(Task *task);
    
    void processRtnContract(Task *task);
    
    void processRtnFund(Task *task);
    
    void processRtnOrder(Task *task);
    
    void processRspOrderAction(Task *task);
    
    void processRspQryOrderProcess(Task *task);
    
    void processRtnFill(Task *task);
    
    void processRtnPosition(Task *task);
    
    void processRtnClose(Task *task);
    
    void processRtnPositionProfit(Task *task);
    
    void processRspQryDeepQuote(Task *task);
    
    void processRtnExchangeStateInfo(Task *task);
    
    void processRtnReqQuoteNotice(Task *task);
    
    void processRspAccountRentInfo(Task *task);
    
    void processRspTradeMessage(Task *task);
    
    void processRtnTradeMessage(Task *task);
    
    void processRspQryHisOrder(Task *task);
    
    void processRspQryHisOrderProcess(Task *task);
    
    void processRspQryHisFill(Task *task);
    
    void processRspQryHisPosition(Task *task);
    
    void processRspQryHisDelivery(Task *task);
    
    void processRspQryAccountCashAdjust(Task *task);
    
    void processRspQryBill(Task *task);
    
    void processRspAccountFeeRent(Task *task);
    
    void processRspAccountMarginRent(Task *task);
    
    void processRspAddMobileDevice(Task *task);
    
    void processRspQryManageInfoForEStar(Task *task);
    
    void processRspQrySystemParameter(Task *task);
    
    void processRspQryTradeCenterFrontAddress(Task *task);
    
    void processRtnCommodityInfo(Task *task);
    
    void processRtnCurrencyInfo(Task *task);
    
    void processRspQryAccountStorage(Task *task);
    
    void processRtnAccountStorage(Task *task);
    
    void processRspQrySpotLock(Task *task);
    
    void processRtnSpotLock(Task *task);
    
    void processRspSpecialOrderAction(Task *task);
    
    void processRtnSpecialOrder(Task *task);
    
    void processRtnCombinePosition(Task *task);
    
    void processRtnContractQuote(Task *task);
    
    void processRspQryTrustDevice(Task *task);
    
    void processRspAddTrustDevice(Task *task);
    
    void processRspDelTrustDevice(Task *task);
    
    void processRtnAddUserRight(Task *task);
    
    void processRtnDelUserRight(Task *task);
    
    void processRspQryManagerConfigFile(Task *task);



    //-------------------------------------------------------------------------------------
    //data：回调函数的数据字典
    //error：回调函数的错误字典
    //id：请求id
    //last：是否为最后返回
    //i：整数
    //-------------------------------------------------------------------------------------
    
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



    //-------------------------------------------------------------------------------------
    //req:主动函数的请求字典
    //-------------------------------------------------------------------------------------
	void createEsTradeAPI(int nResult);

	void release();

	void init();

	int exit();

	int esunny_getloginInfo(const dict&req);

	string getEsTradeAPIVersion();

	int setEsTradeAPIDataPath(string pPath);

	int setEsTradeAPILogLevel(string LogLevel);

	int setUserInfo(const dict &req);

	int setBackUpAddress(string UserNo, const dict &req);

	pybind11::tuple requestVerifyIdentity(string UserNo, const dict &req, TAPIUINT32 nRequestID);

	int startUser(string UserNo, const dict &req);

	int stopUser(string UserNo);

	pybind11::tuple requestVertificateCode(string UserNo, const dict &req, TAPIUINT32 nRequestID);

	pybind11::tuple setVertificateCode(string UserNo, const dict &req, TAPIUINT32 nRequestID);

    //pybind11::tuple getAccount(const dict &req);

	//pybind11::tuple getExchange(const dict &req);

	//pybind11::tuple getCommodity(const dict &req);

	//pybind11::tuple getContract(const dict &req);

	pybind11::tuple insertOrder(string UserNo, const dict &req, TAPIUINT32 nRequestID);

	pybind11::tuple cancelOrder(string UserNo, const dict &req, TAPIUINT32 nRequestID);

	//pybind11::tuple getFund(string UserNo, const dict &req);

	//pybind11::tuple getOrder(const dict &req);

    pybind11::tuple qryOrderProcess(string UserNo, const dict &data, TAPIUINT32 nRequestID);
    
    pybind11::tuple qryDeepQuote(string UserNo, const dict &data, TAPIUINT32 nRequestID);
    
    pybind11::tuple qryAccountRent(string UserNo, const dict &data, TAPIUINT32 nRequestID);
    
    pybind11::tuple qryAccountFeeRent(string UserNo, const dict &data, TAPIUINT32 nRequestID);
    
    pybind11::tuple qryAccountMarginRent(string UserNo, const dict &data, TAPIUINT32 nRequestID);
    
    pybind11::tuple qryAccountCashAdjust(string UserNo, const dict &data, TAPIUINT32 nRequestID);
    
    pybind11::tuple qryBill(string UserNo, const dict &data, TAPIUINT32 nRequestID);
    
    pybind11::tuple qryHisOrder(string UserNo, const dict &data, TAPIUINT32 nRequestID);
    
    pybind11::tuple qryHisOrderProcess(string UserNo, const dict &data, TAPIUINT32 nRequestID);
    
    pybind11::tuple qryHisFill(string UserNo, const dict &data, TAPIUINT32 nRequestID);
    
    pybind11::tuple qryHisPosition(string UserNo, const dict &data, TAPIUINT32 nRequestID);
    
    pybind11::tuple qryHisDelivery(string UserNo, const dict &data, TAPIUINT32 nRequestID);
    
    pybind11::tuple qryManageInfoForEStar(string UserNo, const dict &data, TAPIUINT32 nRequestID);
    
    pybind11::tuple qrySystemParameter(string UserNo, const dict &data, TAPIUINT32 nRequestID);
    
    pybind11::tuple qryTradeCenterFrontAddress(string UserNo, const dict &data, TAPIUINT32 nRequestID);
    
    pybind11::tuple qryTradeMessage(string UserNo, const dict &data, TAPIUINT32 nRequestID);
    
    pybind11::tuple qryAccountStorage(string UserNo, const dict &data, TAPIUINT32 nRequestID);
    
    pybind11::tuple qrySpotLock(string UserNo, const dict &data, TAPIUINT32 nRequestID);
    
    pybind11::tuple qryTrustDevice(string UserNo, const dict &data, TAPIUINT32 nRequestID);
    
    pybind11::tuple qryManagerConfigFile(string UserNo, const dict &data, TAPIUINT32 nRequestID);

};
