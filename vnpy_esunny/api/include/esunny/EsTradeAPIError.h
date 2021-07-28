/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   EsTradeAPIError.h
 * Author: guoxg
 *
 * Created on 2018年5月24日, 下午2:50
 */

#ifndef ESTRADEAPIERROR_H
#define ESTRADEAPIERROR_H

namespace EsTradeAPI
{

	//=============================================================================
	/**
	 *	\addtogroup G_ERR_INNER_API		EsAPI内部返回的错误码定义
	 *	@{
	 */
	 //=============================================================================
	 //! 成功
	const int TAPIERROR_SUCCEED = 0;
	//! 连接服务失败
	const int TAPIERROR_ConnectFail = -1;
	//! 链路认证失败
	const int TAPIERROR_LinkAuthFail = -2;
	//! 主机地址不可用
	const int TAPIERROR_HostUnavailable = -3;
	//! 发送数据错误
	const int TAPIERROR_SendDataError = -4;
	//! 测试编号不合法
	const int TAPIERROR_TestIDError = -5;
	//! 没准备好测试网络
	const int TAPIERROR_NotReadyTestNetwork = -6;
	//! 当前网络测试还没结束
	const int TAPIERROR_CurTestNotOver = -7;
	//! 没用可用的接入前置
	const int TAPIERROR_NOFrontAvailable = -8;
	//! 日志文件路径不可用
	const int TAPIERROR_DataPathAvaiable = -9;
	//! 重复登录
	const int TAPIERROR_RepeatLogin = -10;
	//! 内部错误
	const int TAPIERROR_InnerError = -11;
	//! 上一次请求还没有结束
	const int TAPIERROR_LastReqNotFinish = -12;
	//! 输入参数非法
	const int TAPIERROR_InputValueError = -13;
	//! 授权码不合法
	const int TAPIERROR_AuthCode_Invalid = -14;
	//! 授权码超期
	const int TAPIERROR_AuthCode_Expired = -15;
	//! 授权码类型不匹配
	const int TAPIERROR_AuthCode_TypeNotMatch = -16;
	//! API还没有准备好
	const int TAPIERROR_API_NotReady = -17;
	//! UDP端口监听失败
	const int TAPIERROR_UDP_LISTEN_FAILED = -18;
	//! UDP正在监听
	const int TAPIERROR_UDP_LISTENING = -19;
	//! 接口未实现
	const int TAPIERROR_NotImplemented = -20;
	//! 只允许调用一次
	const int TAPIERROR_CallOneTimeOnly = -21;
	//! 操作频率太高
	const int TAPIERROR_Frequently = -22;
	//! 用户编号重复
	const int TAPIERROR_UserNoDuplicate = -23;
	//! 用户编号错误
	const int TAPIERROR_UserNoError = -24;
	//! 没有所需要查询的数据
	const int TAPIERROR_HaveNoData = -25;
	//! 用户已经就绪不需要再次启动
	const int TAPIERROR_UserReady = -26;
	//! 不支持的操作类型
	const int TAPIERROR_NotSupportType = -27;
	//! 当前用户对应的系统暂不支持的功能
	const int TAPIERROR_NotSupportFunction = -28;
	//! 用户登录信息不完整
	const int TAPIERROR_LoginInfoIncompletion = -29;
	//! 非中继用户不能主动上报登录信息
	const int TAPIERROR_NotAllowSubmit = -30;
	//! 加载下层API动态库失败
	const int TAPIERROR_LoadDll = -31;
	//! 日志文件已经打开
	const int TAPIERROR_LogFileReady = -32;
	//! 打开日志文件错误
	const int TAPIERROR_LogFile_OpenError = -33;
	//! 创建TCPClient失败
	const int TAPIERROR_CreateTcpClient_Error = -34;
    //! 错误的系统类型
    const int TAPIERROR_SystemType_Error = -35;
	//! 登录成功后不允许调用
	const int TAPIERROR_NotAllowAfterLogin = -36;
	//! 验证码有效期内不允许第二次请求
	const int TAPIERROR_NotAllowRequestAgain = -37;
    //! 登录授权码不允许为空
    const int TAPIERROR_NoNULLAuthCode = -38;
    //! 用户不允许为空
    const int TAPIERROR_UserNoNULL = -39;
    //! 设置用户和登录用户不相同
    const int TAPIERROR_UserNoSame = -40;
    //! 该用户下没有该委托
    const int TAPIERROR_UserNoHasOrder = -41;
    //! 设置备用地址重复
    const int TAPIERROR_BackUpAddressRepeat = -42;
    //! 输入错误的密码类型
    const int TAPIERROR_PasswordType = -43;
    //! 输入错误的登录类型
    const int TAPIERROR_LoginType = -44;
    //! 重置密码前需要先通过身份验证
    const int TAPIERROR_Identity = -45;
    //! 重置密码前需要先通过验证码验证
    const int TAPIERROR_VertificateCode = -46;
    //! 只有易星用户支持
    const int TAPIERROR_OnlyEstarSupport = -47;
    //! 后台不支持该协议
    const int TAPIERROR_ProtocolSupport = -48;
    //! 委托价格精度不对
    const int TAPIERROR_OrderPricePrecision = -49;
    //! 委托价最小变动价不对
    const int TAPIERROR_OrderPriceInvalid = -50;
	/** @}*/


	//=============================================================================
	/**
	 *	\addtogroup G_ERR_INPUT_CHECK		输入参数检查错误
	 *	@{
	 */
	 //=============================================================================
	 //! 输入数据为NULL
	const int TAPIERROR_INPUTERROR_NULL = -10000;
	//! 输入错误的:TAPIYNFLAG
	const int TAPIERROR_INPUTERROR_TAPIYNFLAG = -10001;
	//! 输入错误的:TAPILOGLEVEL
	const int TAPIERROR_INPUTERROR_TAPILOGLEVEL = -10002;
	//! 输入错误的:TAPICommodityType
	const int TAPIERROR_INPUTERROR_TAPICommodityType = -10003;
	//! 输入错误的:TAPICallOrPutFlagType
	const int TAPIERROR_INPUTERROR_TAPICallOrPutFlagType = -10004;
	//! 输入错误的:TAPISystemTypeType
	const int TAPIERROR_INPUTERROR_TAPISystemTypeType = -10005;
	//! 输入错误的:TAPILoginTypeType
	const int TAPIERROR_INPUTERROR_TAPILoginTypeType = -10006;
	//! 输入错误的:TAPIAccountType
	const int TAPIERROR_INPUTERROR_TAPIAccountType = -12001;
	//! 输入错误的:TAPIAccountState
	const int TAPIERROR_INPUTERROR_TAPIAccountState = -12003;
	//! 输入错误的:TAPIAccountFamilyType
	const int TAPIERROR_INPUTERROR_TAPIAccountFamilyType = -12004;
	//! 输入错误的:TAPIOrderTypeType
	const int TAPIERROR_INPUTERROR_TAPIOrderTypeType = -12005;
	//! 输入错误的:TAPIOrderSourceType
	const int TAPIERROR_INPUTERROR_TAPIOrderSourceType = -12006;
	//! 输入错误的:TAPITimeInForceType
	const int TAPIERROR_INPUTERROR_TAPITimeInForceType = -12007;
	//! 输入错误的:TAPISideType
	const int TAPIERROR_INPUTERROR_TAPISideType = -12008;
	//! 输入错误的:TAPIPositionEffectType
	const int TAPIERROR_INPUTERROR_TAPIPositionEffectType = -12009;
	//! 输入错误的:TAPIHedgeFlagType
	const int TAPIERROR_INPUTERROR_TAPIHedgeFlagType = -12010;
	//! 输入错误的:TAPIOrderStateType
	const int TAPIERROR_INPUTERROR_TAPIOrderStateType = -12011;
	//! 输入错误的:TAPICalculateModeType
	const int TAPIERROR_INPUTERROR_TAPICalculateModeType = -12012;
	//! 输入错误的:TAPIMatchSourceType
	const int TAPIERROR_INPUTERROR_TAPIMatchSourceType = -12013;
	//! 输入错误的:TAPIOpenCloseModeType
	const int TAPIERROR_INPUTERROR_TAPIOpenCloseModeType = -12014;
	//! 输入错误的:TAPIFutureAlgType
	const int TAPIERROR_INPUTERROR_TAPIFutureAlgType = -12015;
	//! 输入错误的:TAPIOptionAlgType
	const int TAPIERROR_INPUTERROR_TAPIOptionAlgType = -12016;
	//! 输入错误的:TAPIBankAccountLWFlagType
	const int TAPIERROR_INPUTERROR_TAPIBankAccountLWFlagType = -12017;
	//! 输入错误的:TAPIMarginCalculateModeType
	const int TAPIERROR_INPUTERROR_TAPIMarginCalculateModeType = -12021;
	//! 输入错误的:TAPIOptionMarginCalculateModeType
	const int TAPIERROR_INPUTERROR_TAPIOptionMarginCalculateModeType = -12022;
	//! 输入错误的:TAPICmbDirectType
	const int TAPIERROR_INPUTERROR_TAPICmbDirectType = -12023;
	//! 输入错误的:TAPIDeliveryModeType
	const int TAPIERROR_INPUTERROR_TAPIDeliveryModeType = -12024;
	//! 输入错误的:TAPIContractTypeType
	const int TAPIERROR_INPUTERROR_TAPIContractTypeType = -12025;
	//! 输入错误的:TAPITacticsTypeType
	const int TAPIERROR_INPUTERROR_TAPITacticsTypeType = -12035;
	//! 输入错误的:TAPIORDERACT
	const int TAPIERROR_INPUTERROR_TAPIORDERACT = -12036;
	//! 输入错误的:TAPITriggerConditionType
	const int TAPIERROR_INPUTERROR_TAPITriggerConditionType = -12041;
	//! 输入错误的:TAPITriggerPriceTypeType
	const int TAPIERROR_INPUTERROR_TAPITriggerPriceTypeType = -12042;
	//! 输入错误的:TAPITradingStateType
	const int TAPIERROR_INPUTERROR_TAPITradingStateType = -12043;
	//! 输入错误的:TAPIMarketLevelType
	const int TAPIERROR_INPUTERROR_TAPIMarketLevelType = -12044;
	//! 输入错误的:TAPIOrderQryTypeType
	const int TAPIERROR_INPUTERROR_TAPIOrderQryTypeType = -12045;
	//! 输入错误的：TapAPICommodity
	const int TAPIERROR_INPUTERROR_TAPICommodity = -12046;
	//! 输入错误的：TAPIContract
	const int TAPIERROR_INPUTERROR_TAPIContract = -12047;
	//! 输入错误的:TAPIOrderPriceTypeType
	const int TAPIERROR_INPUTERROR_TAPIOrderPriceTypeType = -12048;
	//! 输入错误的:TAPIExpireTime
	const int TAPIERROR_INPUTERROR_TAPIExpireTime = -12049;
	//! 输入错误的二次认证信息
	const int TAPIERROR_INPUTERROR_VertificateCode = -12050;
	//! 输入错误: AddOneIsValid
	const int TAPIERROR_INPUTERROR_TAPIAddOneIsValid = -12051;
    //! 输入错误: SpecialOrderType
	const int TAPIERROR_INPUTERROR_TAPISpecialOrderTypeType = -12052;
    //! 输入错误: ClientID，ClientID包含特殊字符
    const int TAPIERROR_INPUTERROR_TAPIClientID = -12053;
    //! 输入错误: ISModifyPassword
    const int TAPIERROR_INPUTERROR_TAPIForceModifyPasswordType = -12054;
    //! 输入错误: CertificateType
    const int TAPIERROR_INPUTERROR_TAPICertificateType = -12055;
    //! 输入错误: SendType
    const int TAPIERROR_INPUTERROR_TAPISendTypeType = -12056;
    //! 输入错误: PasswordType
    const int TAPIERROR_INPUTERROR_TAPIPasswordType = -12057;
    //! 输入错误: SecondLoginType
    const int TAPIERROR_INPUTERROR_TAPISecondLoginTypeType = -12058;

	/** @}*/

	//=============================================================================
	/**
	 *	\addtogroup G_ERR_DISCONNECT_REASON	网络断开错误代码定义
	 *	@{
	 */
	 //=============================================================================
	 //! 主动断开
	const int TAPIERROR_DISCONNECT_CLOSE_INIT = 1;
	//! 被动断开
	const int TAPIERROR_DISCONNECT_CLOSE_PASS = 2;
	//! 读错误
	const int TAPIERROR_DISCONNECT_READ_ERROR = 3;
	//! 写错误
	const int TAPIERROR_DISCONNECT_WRITE_ERROR = 4;
	//! 缓冲区满
	const int TAPIERROR_DISCONNECT_BUF_FULL = 5;
	//! 异步操作错误
	const int TAPIERROR_DISCONNECT_IOCP_ERROR = 6;
	//! 解析数据错误
	const int TAPIERROR_DISCONNECT_PARSE_ERROR = 7;
	//! 连接超时
	const int TAPIERROR_DISCONNECT_CONNECT_TIMEOUT = 8;
	//! 初始化失败
	const int TAPIERROR_DISCONNECT_INIT_ERROR = 9;
	//! 已经连接
	const int TAPIERROR_DISCONNECT_HAS_CONNECTED = 10;
	//! 工作线程已结束
	const int TAPIERROR_DISCONNECT_HAS_EXIT = 11;
	//! 操作正在进行，请稍后重试
	const int TAPIERROR_DISCONNECT_TRY_LATER = 12;
	//! 心跳检测失败
	const int TAPIERROR_DISCONNECT_HEARTBEAT_FAILED = 13;
	//! Socket处理错误
	const int TAPIERROR_DISCONNECT_SOCKETSELECT_ERROR = 14;
	//! 被动登出
	const int TAPIERROR_DISCONNECT_LOGOUT = 15;
	/** @}*/

	//=============================================================================
	/**
	 *	\addtogroup G_ERR_LOGIN	登陆过程返回的错误代码定义
	 *	@{
	 */
	 //=============================================================================
	//! 登录过程执行错误
	const int TAPIERROR_LOGIN = 210001;
	//! 登录用户不存在
	const int TAPIERROR_LOGIN_USER = 210002;
	//! 需要进行动态认证
	const int TAPIERROR_LOGIN_DDA = 210003;
	//! 登录用户未授权
	const int TAPIERROR_LOGIN_LICENSE = 210004;
	//! 登录模块不正确
	const int TAPIERROR_LOGIN_MODULE = 210005;
	//! 需要强制修改密码
	const int TAPIERROR_LOGIN_FORCE = 210006;
	//! 登录状态禁止登陆
	const int TAPIERROR_LOGIN_STATE = 210007;
	//! 登录密码不正确
	const int TAPIERROR_LOGIN_PASS = 210008;
	//! 没有该模块登录权限
	const int TAPIERROR_LOGIN_RIGHT = 210009;
	//! 登录数量超限
	const int TAPIERROR_LOGIN_COUNT = 210010;
	//! 登录用户不在服务器标识下可登录用户列表中
	const int TAPIERROR_LOGIN_NOTIN_SERVERFLAGUSRES = 210011;
	//! 登陆用户交易日验证出错
	const int TAPIERROR_LOGIN_USER_EXPIRED = 210012;
	//! 登陆用户无下属客户
	const int TAPIERROR_LOGIN_NO_ACCOUNT = 210013;
	//! 登录用户是子帐号且授权中未包含机构通标记
	const int TAPIERROR_LOGIN_NO_JGT = 210014;
	//! 登录用户密码错误次数超限，禁止登陆
	const int TAPIERROR_LOGIN_ERROR_TIMES = 210015;
	//! 登录用户授权类型错误
	const int TAPIERROR_LOGIN_SECONDCERTIFICATION = 210016;
	//! 登录用户授权到期或到期日错误
	const int TAPIERROR_LOGIN_ERROR_AUTHEXPIRED = 210017;
	//! 登录用户密码超过有效天数
	const int TAPIERROR_LOGIN_ERROR_PASSWDEXPIRED = 210018;
	//! 登录用户未授权的登录IP和MAC
	const int TAPIERROR_LOGIN_ERROR_USERTRUST = 210019;
    //! 8.2客户端禁止登录请升级8.3
    const int TAPIERROR_LOGIN_ERROR_CLIENTVERSION = 210020;
    //! 用户授权信息错误
    const int TAPIERROR_LOGIN_ERROR_AUTHCODEINFO = 210021;

	//! 登录过程执行错误
	const int TAPIERROR_ILOGIN = 110001;
	//! 登录用户不存在
	const int TAPIERROR_ILOGIN_USER = 110002;
	//! 需要进行动态认证
	const int TAPIERROR_ILOGIN_DDA = 110003;
	//! 登录用户未授权
	const int TAPIERROR_ILOGIN_LICENSE = 110004;
	//! 登录模块不正确
	const int TAPIERROR_ILOGIN_MODULE = 110005;
	//! 需要强制修改密码
	const int TAPIERROR_ILOGIN_FORCE = 110006;
	//! 登录状态禁止登陆
	const int TAPIERROR_ILOGIN_STATE = 110007;
	//! 登录密码不正确
	const int TAPIERROR_ILOGIN_PASS = 110008;
	//! 没有该模块登录权限
	const int TAPIERROR_ILOGIN_RIGHT = 110009;
	//! 登录数量超限
	const int TAPIERROR_ILOGIN_COUNT = 110010;
	//! 登录用户不在服务器标识下可登录用户列表中
	const int TAPIERROR_ILOGIN_NOTIN_SERVERFLAGUSRES = 110011;
	//! 登录用户已被冻结
	const int TAPIERROR_ILOGIN_FREEZE = 110012;
	//! 密码错误，用户冻结
	const int TAPIERROR_ILOGIN_TOFREEZE = 110013;
	//! 客户状态不允许登录
	const int TAPIERROR_ILOGIN_ACCOUNTSTATE = 110014;
	//! 需要进行二次认证
	const int TAPIERROR_ILOGIN_SECCERTIFI = 110015;
	//! 未绑定二次认证信息
	const int TAPIERROR_ILOGIN_NOSECONDSET = 110016;
	//! 不受信任的计算机登录
	const int TAPIERROR_ILOGIN_NOTURSTHOST = 110017;
	//! 请求二维码失败
	const int TAPIERROR_ILOGIN_GETQRCODE = 110018;
	//! 非本交易中心客户
	const int TAPIERROR_ILOGIN_NOTINTRADECENTER = 110019;
	//! 版本和后台版本不不一致
	const int TAPIERROR_ILOGIN_INCONSISTENT = 110020;
	//! 客户所属交易中心前置地址未配置
	const int TAPIERROR_ILOGIN_NOCENTERFRONTADDRESS = 110021;
	//! 不允许此账号类型登录
	const int TAPIERROR_ILOGIN_PROHIBITACCOUNTTYPE = 110022;
    //! 需要信息采集-直连
    const int TAPIERROR_ILOGIN_GATHERINFO_DIRECT = 110023;
    //! 需要信息采集-中继
    const int TAPIERROR_ILOGIN_GATHERINFO_RELAY = 110024;
    //! 允许重置密码
    const int TAPIERROR_ILOGIN_RESET_PASSWORD = 110025;
    //! 重置密码链接次数超限
    const int TAPIERROR_ILOGIN_RESET_PASSWORD_EXCEEDED = 110026;
    //! 不支持操作员重置密码
    const int TAPIERROR_ILOGIN_OPERATOR_UNALLOWED_RESET = 110027;
    //! 冻结重置密码
    const int TAPIERROR_ILOGIN_RESET_PASSWORD_FROZEN = 110028;
    //! 身份验证失败
    const int TAPIERROR_ILOGIN_VERIFYIDENTITY_FAILED = 110029;
    //! 身份验证次数超限
    const int TAPIERROR_ILOGIN_VERIFYIDENTITY_EXCEED = 110030;
    //! 授权已到期
    const int TAPIERROR_ILOGIN_LICENSE_EXPIRED = 110031;
    //! 不允许重置密码-没有设置发送方式
    const int TAPIERROR_ILOGIN_PROHIBITRESETPASSWORD = 110032;
    //! 允许冻结状态解冻
    const int TAPIERROR_ILOGIN_UNFREEZE	= 110033;
    //! 冻结状态解冻结链接数量超限
    const int TAPIERROR_ILOGIN_UNFREEZE_EXCEEDED = 110034;
    //! 不允许解冻-没有设置发送方式
    const int TAPIERROR_ILOGIN_PROHIBIT_UNFREEZE = 110035;
    //! 不需要解冻-登录未冻结
    const int TAPIERROR_ILOGIN_NONEED_UNFREEZE = 110036;

	/** @}*/

	//=============================================================================
	/**
	 *	\addtogroup G_ERR_MANAGE 管理业务处理返回错误码
	 *	@{
	 */
	 //==============================================================================
	//! 登录用户信息查询失败
	const int TAPIERROR_USERINFO_QRY = 210101;
	//! 登录用户下属权限查询失败
	const int TAPIERROR_USERRIGHT_QRY = 210901;
	//! 登录用户下属所有权限查询失败
	const int TAPIERROR_USERALLRIGHT_QRY = 211001;
	//! 登录用户下属所有资金账号查询失败
	const int TAPIERROR_USERALLACCOUNT_QRY = 211501;
	//! 登录用户密码修改失败
	const int TAPIERROR_USERPASSWORD_MOD = 211701;
	//! 登录用户密码修改失败,原始密码错误
	const int TAPIERROR_USERPASSWORD_MOD_SOURCE = 211702;
	//! 登录用户密码修改失败,不能与前n次密码相同
	const int TAPIERROR_USERPASSWORD_MOD_SAME = 211703;
	//! 新密码不符合密码复杂度要求
	const int TAPIERROR_USERPASSWORD_MOD_COMPLEXITY = 211704;
	//! 交易币种查询失败
	const int TAPIERROR_TCURRENCYINFO_QRY = 220102;
	//! 资金账号信息查询失败
	const int TAPIERROR_ACCOUNTINFO_QRY = 220201;
	//! 交易所信息查询失败
	const int TAPIERROR_EXCHANGEINFO_QRY = 220601;
	//! 客户交易编码查询失败
	const int TAPIERROR_TRADENO_QRY = 220701;
	//!上手通道信息查询失败
	const int TAPIERROR_UPPERCHANNEL_QRY = 221401;
	//! 品种信息查询失败
	const int TAPIERROR_COMMODITYINFO_QRY = 222001;
	//! 合约信息查询失败
	const int TAPIERROR_CONTRACTINFO_QRY = 222801;
	//! 特殊期权标的查询失败
	const int TAPIERROR_SPECIALOPTIONFUTURE_QRY = 222901;
	//! 用户下单频率查询失败
	const int TAPIERROR_USER_ORDER_FREQUENCE_QRY = 228901;
	//! 客户最终手续费查询失败
	const int TAPIERROR_ACCOUNTFEE_PARAMETER_QRY = 229431;
	//! 客户最终保证金查询失败
	const int TAPIERROR_ACCOUNTMARGIN_PARAMETER_QRY = 229432;
    //! 提交信息用户授权类型错误
    const int TAPIERROR_USERSUBMITAUTHTYPE_ERROR = 229591;
    //! 用户采集终端数据为空
    const int TAPIERROR_USERSUBMITINFO_EMPTY = 229592;
    //! 用户密钥版本错误
    const int TAPIERROR_USERAUTHKEYVERSION_ERROR = 229593;
    //! 用户采集信息不全，权限不够
    const int TAPIERROR_USERSUBMITINFO_PARTY = 229594;
    //! 用户采集信息采用测试密钥加密
    const int TAPIERROR_USERSUBMITINFO_TESTKEY = 229595;
    //! 用户采集信息用户不存在
    const int TAPIERROR_USERSUBMITINFO_USERNO = 229596;
	//! 交易消息发送错误
	const int TAPIERROR_TRADEMESSAGE_SEND = 242301;
	//! 交易消息查询错误
	const int TAPIERROR_TRADEMESSAGE_QRY = 242302;
	//! 交易消息推送通知错误
	const int TAPIERROR_TRADEMESSAGE_NOTICE = 242303;
	//! 交易消息有效时间内查询错误
	const int TAPIERROR_TRADEMESSAGEINVALIDTIME_QRY = 242304;


	//! 数据库连接失败
	const int TAPIERROR_CONN_DATABASE = 111000;
	//! 数据库操作失败
	const int TAPIERROR_OPER_DATABASE = 111001;
	//! 不允许一对多
	const int TAPIERROR_NEED_ONETOONE = 111002;
	//! 删除失败-存在关联信息
	const int TAPIERROR_EXIST_RELATEINFO = 111003;
	//! 删除分组失败-分组有下属或在操作员下属中
	const int TAPIERROR_EXIST_RELATEINFOOFGROUP = 111004;
	//! 不允许对超级管理员操作
	const int TAPIERROR_FORBIDDEN_SUPER = 111005;
	//! 审核状态不予许修改
	const int TAPIERROR_CHECK_FAILED = 111006;
	//! 不允许存在重复3.0外部品种编号
	const int TAPIERROR_EXIST_OUTSIDECOMMODITYNO = 111007;
	//! 客户结算单不存在
	const int TAPIERROR_NOTEXIST_BILL = 111008;
	//! 不允许增加此类型账号
	const int TAPIERROR_LOGIN_PROHIBITADDACCOUNTTYPE = 111009;
	//! 账号类型不允许为空
	const int TAPIERROR_ACCOUNTINFO_NOTEXPTY = 111010;
	//! 主账号不允许为空
	const int TAPIERROR_ACCOUNTINFO_SuperiorNOTEMPTY = 111011;
    //! 超过信任设备绑定数量上限
    const int TAPIERROR_USERTRUSTDEVICE_ADDLIMITE = 111012;
    //! 非法映射
    const int TAPIERROR_UPPERACCOUNTMAPPING_NOTALLOW = 111013;

	//! 登录用户密码修改失败-原始密码错误
	const int TAPIERROR_IUSERPASSWORD_MOD_SOURCE = 112001;
	//! 登录用户密码修改失败-不能与前n次密码相同
	const int TAPIERROR_IUSERPASSWORD_MOD_SAME = 112002;
	//! 登录用户密码修改失败-新密码不符合密码复杂度要求
	const int TAPIERROR_IUSERPASSWORD_MOD_COMPLEXITY = 112003;
    
    //! 一个币种组只能设置一个基币
    const int TAPIERROR_CURRENCY_ONLY_ONEBASE = 113001;
    //! 基币只能是美元或港币
    const int TAPIERROR_CURRENCY_ONLY_USDHKD = 113002;

	//! 二次验证失败
	const int TAPIERROR_SECONDCERTIFICATION_FAIL = 114001;
	//! 二次验证超时
	const int TAPIERROR_SECONDCERTIFICATION_TIMEOVER = 114002;
	//! 二次认证错误次数超限，重新登录
	const int TAPIERROR_SECONDCERTIFICATION_RELOGIN = 114003;
	//! 二次认证错误次数超限，用户冻结
	const int TAPIERROR_SECONDCERTIFICATION_FREEZE = 114004;
    
    //! 期货公司不予许自助换汇
    const int TAPIERROR_AUTOSWAP_NOTALLOWED = 115001;
    //! 期货公司允许在该时段换汇
    const int TAPIERROR_AUTOSWAP_TIMENOTALLOWED = 115002;
    //! 超出单笔额度
    const int TAPIERROR_AUTOSWAP_SINGLEQUOTA = 115003;
    //! 超出单日次数
    const int TAPIERROR_AUTOSWAP_SINGLEDAY = 115004;
    //! 超出单日额度
    const int TAPIERROR_AUTOSWAP_ONEDAYQUOTA = 115005;
    //! 超出公司单日额度
    const int TAPIERROR_AUTOSWAP_COMPANYONEDAYQUOTA = 115006;
    
    //! 解押手数超过质押手数
    const int TAPIERROR_PLEDGE_OUTOFRANGE = 116001;

	//! 密钥未找到
	const int TAPIERROR_GATHERINFO_NO_AUTHKEY = 117001;
	//! 认证失败
	const int TAPIERROR_GATHERINFO_AUTH_FAILED = 117002;

	/** @}*/

	//=============================================================================
	/**
	 *	\addtogroup G_ERR_TRADE 交易业务处理返回错误码
	 *	@{
	 */
	 //==============================================================================
	 //! 资金账号不存在
	const int TAPIERROR_ORDERINSERT_ACCOUNT = 260001;
	//! 资金账号状态不正确
	const int TAPIERROR_ORDERINSERT_ACCOUNT_STATE = 260002;
	//! 资金账号无委托方向交易权限
	const int TAPIERROR_ORDERINSERT_SIDE_TRADE = 260003;
	//! 资金账号无期权交易权限
	const int TAPIERROR_ORDERINSERT_OPTIONS_TRADE = 260004;
	//! 资金账号无品种交易权限
	const int TAPIERROR_ORDERINSERT_COMMODITY_TRADE = 260005;
	//! 资金账号无开仓权限
	const int TAPIERROR_ORDERINSERT_OPEN_RIGHT = 260006;
	//! 资金账号风控项检查失败
	const int TAPIERROR_ORDERINSERT_RISK_CHECK = 260007;
	//! 下单无效的合约
	const int TAPIERROR_ORDERINSERT_CONTRACT = 260011;
	//! 下单合约无交易路由
	const int TAPIERROR_ORDERINSERT_TRADEROUTE = 260021;
	//! 持仓量超过最大限制
	const int TAPIERROR_ORDERINSERT_POSITIONMAX = 260022;
	//! 禁止交易
	const int TAPIERROR_ORDER_NOTRADE = 260023;
	//! 只可平仓
	const int TAPIERROR_ORDER_CLOSE = 260024;
	//! 下单资金不足
	const int TAPIERROR_ORDERINSERT_NOTENOUGHFUND = 260031;
	//! 不支持的订单类型
	const int TAPIERROR_ORDERINSERT_ORDERTYPE = 260032;
	//! 不支持的时间有效类型
	const int TAPIERROR_ORDERINSERT_TIMEINFORCE = 260033;
	//! 不支持的策略单类型
	const int TAPIERROR_ORDERINSERT_NO_TACTICS = 260034;
	//! 平仓数量超过已有持仓量
	const int TAPIERROR_ORDERINSERT_POSITION_CANNOT_CLOSE = 260035;
	//! 下单自动审核失败
	const int TAPIERROR_ORDERINSERT_AUTOCHECK_FAIL = 260036;
	//! LME未准备就绪
	const int TAPIERROR_ORDERINSERT_LME_NOTREADY = 260037;
	//! 平仓方式错误
	const int TAPIERROR_ORDERINSERT_CLOSEMODE = 260038;
	//! 下单对应的父账号资金不足
	const int TAPIERROR_ORDERINSERT_PARENTNOTENOUGHFUND = 260039;
	//! 互换单的合约格式错误
	const int TAPIERROR_SWAP_CONTRACT = 260040;
    //! 委托价格不合理
    const int TAPIERROR_ORDERINSERT_PRICE = 260041;
    //! 开平标记不合理
    const int TAPIERROR_ORDERINSERT_EFFECT = 260042;
    //! 关联合约错误
    const int TAPIERROR_ORDERINSERT_TARGETCONTRACT = 260043;
	//! 当前客户不能使用此账号交易
	const int TAPIERROR_USERNO_NOTHAS_ACCOUNT = 260051;
	//! 上手通道状态不正常
	const int TAPIERROR_UPPERCHANNEL_BROKEN = 260052;
	//! 上手通道未开通EXIST
	const int TAPIERROR_UPPERCHANNEL_NOT_EXIST = 260053;
	//! 撤单无此系统号
	const int TAPIERROR_ORDERDELETE_NOT_SYSNO = 260061;
	//! 此状态不允许撤单
	const int TAPIERROR_ORDERDELETE_NOT_STATE = 260062;
	//! 此状态不允许激活
	const int TAPIERROR_ORDERACTIVE_NOT_STATE = 260063;
	//! 只允许撤销本合约最新一次委托
	const int TAPIERROR_ORDERDELETE_NOT_LAST = 260064;
	//! 此状态禁止审核
	const int TAPIERROR_ORDERCHECK_NOT_STATE = 260071;
	//! 订单审核失败
	const int TAPIERROR_ORDERCHECK_FAIL = 260072;
	//! 此状态不允许改单
	const int TAPIERROR_ORDERMODIFY_NOT_STATE = 260081;
	//! 人工单不允许改单
	const int TAPIERROR_ORDERMODIFY_BACK_INPUT = 260082;
	//! 手续费参数错误
	const int TAPIERROR_ORDERINSERT_FEE = 260091;
	//! 保证金参数错误
	const int TAPIERROR_ORDERINSERT_MARGIN = 260092;
	//! 操作账号只可查询
	const int TAPIERROR_ORDER_NO_PERMIT = 260100;
	//! 非做市商不能应价
	const int TAPIERROR_RSPQUOTE_NO_PERMIT = 260101;
	//! 既是子帐号又是做市商不能应价
	const int TAPIERROR_RSPQUOTE_CHILD_NO_PERMIT = 260102;
	//! 下单找不到交易编码
	const int TAPIERROR_TRADENO_NOT_FIND = 260103;
	//! 操作账号只可开仓
	const int TAPIERROR_ORDER_NO_CLOSE = 260104;
	//! 操作账号没有上期挂单查询权限
	const int TAPIERROR_QRY_QUOTE_NO_PERMIT = 260105;
	//! 限期有效单不能小于当前交易日
	const int TAPIERROR_EXPIREDATE_NO_PERMIT = 260106;
	//! 该编码不允许申请或拆分组合
	const int TAPIERROR_CMB_NO_PERMIT = 260107;
	//! 非本服务器标记下的账号不允许操作
	const int TAPIERROR_ORDERSERVER_NO_PERMIT = 260108;
	//! 行权或弃权量超过可用量
	const int TAPIERROR_POSITION_CANNOT_EXEC_OR_ABANDON = 260109;
	//! 没有订单审核权限
	const int TAPIERROR_ORDERCHECK_NO_PERMIT = 260110;
	//! 超过当日最大开仓量
	const int TAPIERROR_ORDERMAXOPENVOL_NO_PERMIT = 260111;
	//! 涨跌停附近禁止反向开仓
	const int TAPIERROR_ORDERLIMIT_OPEN_NO_PERMIT = 260112;
	//! 超过单笔最大下单量
	const int TAPIERROR_ORDER_SINGLEVOL_NO_PERMIT = 260113;
	//! 超过最大持仓量
	const int TAPIERROR_ORDER_POSITIONVOL_NO_PERMIT = 260114;
	//! 非大连应价单不允许两笔委托量不一致
	const int TAPIERROR_ORDER_QTY_NO_PERMIT = 260115;
	//! 子帐号不允许套利申请
	const int TAPIERROR_ORDER_CMB_CHILD_NO_PERMIT = 260116;
	//! 申请不允许重复提交
	const int TAPIERROR_ORDER_APPLY_NO_PERMIT = 260117;
	//! 超过账号下单频率限制
	const int TAPIERROR_ORDER_FREQ_OVERRUN = 260118;
	//! 组合表不存在的组合方向或投保标志
	const int TAPIERROR_COMB_NO_SIDEORHEDGE = 260119;
	//! 当前期权存在合理价差不需要询价
	const int TAPIERROR_REQQUOTE_EXITREASONABLPRICE = 260120;
    //! 应价委托价格不合理
    const int TAPIERROR_RSPQUOTE_PRICE = 260121;
    //! 普通客户不允许撤销强平单
    const int TAPIERROR_RISKORDER_CANCEL = 260122;
    //! 应价委托开平标志不正确
    const int TAPIERROR_RSPQUOTE_EFFECT = 260123;
    //! 买卖方式错误
    const int TAPIERROR_ORDERINSERT_SIDEMODE = 260124;
    //! 自动单超过最大委托数量
    const int TAPIERROR_AUTOORDER_MAXCOUNT = 260125;
    //! 上期所深度行情查询请求超过最大队列数
    const int TAPIERROR_SHFEDEEPQUOTE_LIMIT = 260126;
    //! 上期所深度行情查询请求没有数据
    const int TAPIERROR_SHFEDEEPQUOTE_NODATA = 260127;
    //! 存在自成交可能
    const int TAPIERROR_SELFMATCH = 260128;
    //! 错单超过最大数量
    const int TAPIERROR_ERRORORDER_MAXCOUNT = 260129;
    //! 超过席位下单频率限制
    const int TAPIERROR_ORDER_UPPERFREQ_OVERRUN = 260130;
    //! 客户禁止当前类型委托
    const int TAPIERROR_ORDERTYPE_LIMIT = 260131;


	//! 资金账号不存在
	const int TAPIERROR_IORDERINSERT_ACCOUNT = 160001;
	//! 资金账号状态不正确
	const int TAPIERROR_IORDERINSERT_ACCOUNT_STATE = 160002;
	//! 资金账号交易中心不一致
	const int TAPIERROR_IORDERINT_ACC_TRADECENT_ERROR = 160003;
	//! 主账号不允许下单
	const int TAPIERROR_IORDERINT_MAINACCOUNT_ERROR = 160004;
	//! 主账号信息错误
	const int TAPIERROR_IORDERINT_MAINACCINFO_ERROR = 160005;
	//! 账号禁止期权市价下单
	const int TAPIERROR_IORDERINT_NO_OPTMARKET_ERROR = 160006;
    //! 目前不支持的指令
    const int TAPIERROR_IORDERINT_UN_SUPPORT_ERROR = 160007;
	//! 下单无效的合约(外盘)
	const int TAPIERROR_IORDERINSERT_CONTRACT = 160011;
	//! LME未准备就绪(外盘)
	const int TAPIERROR_IORDERINSERT_LME_NOTREADY = 160012;
	//! 不支持的下单类型
	const int TAPIERROR_ORDERINSERT_ERROR_ORDER_TYPE = 160013;
	//! 错误的埋单类型
	const int TAPIERROR_IORDERINSERT_READY_TYPE_ERROR = 160014;
	//! 不合法的委托类型
	const int TAPIERROR_IORDERINSERT_ORDER_TYPE_ERROR = 160015;
    //! 下单合约标的合约不存在
    const int TAPIERROR_IORDERINSERT_SUBCONTRACT = 160016;
    //! 现货下单买入数量错误
    const int TAPIERROR_IORDERINSERT_SPOTBUYQTY = 160017;
    //! 非认购期权不允许备兑
    const int TAPIERROR_IORDERINSERT_RESERVE_PUT = 160018;
    //! 买入开仓不允许备兑
    const int TAPIERROR_IORDERINSERT_RESERVE_B_OPEN = 160019;
    //! 卖出平仓不允许备兑
    const int TAPIERROR_IORDERINSERT_RESERVE_S_COVER	= 160020;
	//! 客户权限禁止交易
	const int TAPIERROR_ORDER_NOTRADE_ACCOUNT = 160021;
	//! 客户品种分组禁止交易
	const int TAPIERROR_ORDER_NOTRADE_COM_GROUP = 160022;
	//! 客户合约特设禁止交易
	const int TAPIERROR_ORDER_NOTRADE_ACC_CONTRACT = 160023;
	//! 系统权限禁止交易
	const int TAPIERROR_ORDER_NOTRADE_SYSTEM = 160024;
	//! 客户权限只可平仓
	const int TAPIERROR_ORDER_CLOSE_ACCOUNT = 160025;
	//! 客户合约特设只可平仓
	const int TAPIERROR_ORDER_CLOSE_ACC_CONTRACT = 160026;
	//! 系统权限只可平仓
	const int TAPIERROR_ORDER_CLOSE_SYSTEM = 160027;
	//! 只可平仓提前天数限制只可平仓
	const int TAPIERROR_ORDER_CLOSE_DAYS = 160028;
	//! 客户品种风控权限禁止交易
	const int TAPIERROR_ORDER_NOTRADE_RISK = 160029;
	//! 客户品种风控权限只可平仓
	const int TAPIERROR_ORDER_CLOSE_RISK = 160030;
	//! 合约层持仓量超过最大限制
	const int TAPIERROR_IORDERINSERT_POSITIONMAX = 160031;
	//! 下单超过单笔最大量
	const int TAPIERROR_ORDERINSERT_ONCEMAX = 160032;
	//! 下单合约无交易路由(外盘)
	const int TAPIERROR_IORDERINSERT_TRADEROUTE = 160033;
	//! 委托价格超出偏离范围
	const int TAPIERROR_ORDER_IN_MOD_PRICE_ERROR = 160034;
	//! 超过GiveUp最大持仓量
	const int TAPIERROR_ORDER_IN_GIVEUP_POS_MAX = 160035;
    //! 持仓量超过ETF总持仓限制
    const int TAPIERROR_ORDER_ETF_POSITIONMAX = 160036;
    //! 持仓量超过ETF权利仓限制
    const int TAPIERROR_ORDER_ETF_BUYPOSITIONMAX = 160037;
    //! 持仓量超过ETF单日买入开仓限制
    const int TAPIERROR_ORDER_ETF_BUYONEDAYPOSITIONMAX = 160038;
    //! 可用锁定现货不足
    const int TAPIERROR_ORDERINSERT_NOTENOUGHSPOT = 160039;
    //! 现货不支持备兑
    const int TAPIERROR_ORDERINSERT_RESERVE_SPOT = 160040;
	//! 未登录网关
	const int TAPIERROR_UPPERCHANNEL_NOT_LOGIN = 160041;
	//! 未找到网关信息
	const int TAPIERROR_UPPERCHANNEL_NOT_FOUND = 160042;
    //! 此品种不支持解锁或锁定
    const int TAPIERROR_COMMODITY_LOCK = 160043;
    //! 现货未设置对应期权品种
    const int TAPIERROR_SPOT_ROOT_COMMODITY = 160044;
    //! 现货对应期权无交易路由
    const int TAPIERROR_SPOT_ROOTCOM_TRADEROUTE = 160045;
	//! 下单资金不足(外盘)
	const int TAPIERROR_IORDERINSERT_NOTENOUGHFUND = 160051;
	//! 手续费参数错误(外盘)
	const int TAPIERROR_IORDERINSERT_FEE = 160052;
	//! 保证金参数错误(外盘)
	const int TAPIERROR_IORDERINSERT_MARGIN = 160053;
	//! 总基币资金不足
	const int TAPIERROR_ORDERINSERT_BASENOFUND = 160054;
	//! 超过保证金额度
	const int TAPIERROR_ORDERINSERT_MARGINAMOUNT = 160055;
	//! 总基币超过开仓比例限制
	const int TAPIERROR_ORDERINSERT_OPENRATIO = 160056;
	//! 独立币种组超过开仓比例限制
	const int TAPIERROR_ORDERINSERT_GROUP_OPENRATIO = 160057;
	//! 风险阵列参数错误
	const int TAPIERROR_ORDERINSERT_RISKARRAY = 160058;
    //! 总基币超过限购额度限制
    const int TAPIERROR_ORDERINSERT_BUYLIMITE = 160059;
    //! 独立币种组超过限购额度限制
    const int TAPIERROR_ORDERINSERT_GROUP_BUYLIMITE = 160060;

	//! 撤单无此系统号(外盘)
	const int TAPIERROR_IORDERDELETE_NOT_SYSNO = 160061;
	//! 此状态不允许撤单(外盘)
	const int TAPIERROR_IORDERDELETE_NOT_STATE = 160062;
	//! 录单不允许撤单
	const int TAPIERROR_ORDERDELETE_NO_INPUT = 160063;
    //! 不允许撤销锁定/解锁指令
    const int TAPIERROR_ORDERDELETE_NO_TRADE = 160064;
	//! 此状态不允许改单(外盘)
	const int TAPIERROR_IORDERMODIFY_NOT_STATE = 160071;
	//! 人工单不允许改单(外盘)
	const int TAPIERROR_IORDERMODIFY_BACK_INPUT = 160072;
	//! 风险报单不允许改单
	const int TAPIERROR_ORDERMODIFY_RISK_ORDER = 160073;
	//! 成交量大于改单量
	const int TAPIERROR_ORDERMODIFY_ERROR_QTY = 160074;
	//! 预埋单不允许改单
	const int TAPIERROR_ORDERMODIFY_ERROR_READY = 160075;
	//! 已删除报单不能转移
	const int TAPIERROR_ORDERINPUT_CANNOTMOVE = 160081;
	//! 录单重复
	const int TAPIERROR_ORDERINPUT_REPEAT = 160091;
	//! 合约行情价格修改失败
	const int TAPIERROR_CONTRACT_QUOTE = 160101;
	//! 下单超过上手单笔最大量
	const int TAPIERROR_UPPER_ONCEMAX = 160111;
	//! 下单超过上手最大持仓量
	const int TAPIERROR_UPPER_POSITIONMAX = 160112;
    //! 品种总仓层最大持仓量超限
    const int TAPIERROR_ORDERINSERT_POSMAX_COM = 160113;
    //! 品种净仓层最大持仓量超限
    const int TAPIERROR_ORDERINSERT_POSMAX_COM_NET = 160114;
	//! 开平方式错误
	const int TAPIERROR_IORDERINSERT_CLOSEMODE = 160121;
	//! 委托平仓持仓不足
	const int TAPIERROR_CLOSE_ORDER = 160122;
	//! 成交平仓失败
	const int TAPIERROR_CLOSE_MATCH = 160123;
    //! 现货平仓超过锁定量
    const int TAPIERROR_CLOSE_SPOT_OUT_LOCK = 160124;
    //! 现货备兑基数为空
    const int TAPIERROR_CLOSE_SPOT_OUT_NULL = 160125;
	//! 未找到本地委托
	const int TAPIERROR_MOD_DEL_NO_ORDER = 160131;
	//! 与网关断开连接
	const int TAPIERROR_MOD_DEL_GATEWAY_DISCON = 160132;
	//! 录单成交重复
	const int TAPIERROR_MATCHINPUT_REPEAT = 160141;
	//! 录单成交未找到对应委托
	const int TAPIERROR_MATCHINPUT_NO_ORDER = 160142;
	//! 录单成交合约不存在
	const int TAPIERROR_MATCHINPUT_NO_CONTRACT = 160143;
	//! 录单成交参数错误
	const int TAPIERROR_MATCHINPUT_PARM_ERROR = 160144;
	//! 录单成交委托状态错误
	const int TAPIERROR_MATCHINPUT_OSTATE_ERROR = 160145;
    //! 录单成交开平标志错误
    const int TAPIERROR_MATCHINPUT_OCMODE_ERROR = 160146;
	//! 成交删除未找到成交
	const int TAPIERROR_MATCHREMOVE_NO_MATCH = 160151;
	//! 此状态成交不可删
	const int TAPIERROR_MATCHREMOVE_STATE_ERROR = 160152;
	//! 不允许录入此状态订单
	const int TAPIERROR_ORDERINPUT_STATE_ERROR = 160161;
	//! 错误的修改订单请求
	const int TAPIERROR_ORDERINPUT_MOD_ERROR = 160162;
	//! 订单不可删，存在对应成交
	const int TAPIERROR_ORDERREMOVE_ERROR = 160163;
	//! 不合法的委托状态
	const int TAPIERROR_ORDERINPUT_MOD_STATE_ERROR = 160164;
	//! 此状态不允许订单转移
	const int TAPIERROR_ORDEREXCHANGE_STATE_ERROR = 160165;
	//! 订单不允许删除
	const int TAPIERROR_ORDERREMOVE_NOT_ERROR = 160166;
	//! 做市商双边撤单未找到委托
	const int TAPIERROR_ORDERMARKET_DELETE_NOTFOUND = 160171;
	//! 做市商双边撤单客户不一致
	const int TAPIERROR_ORDERMARKET_DEL_ACCOUNT_NE = 160172;
	//! 做市商双边撤单品种不一致
	const int TAPIERROR_ORDERMARKET_DEL_COMMODITY_NE = 160173;
	//! 做市商双边撤单合约不一致
	const int TAPIERROR_ORDERMARKET_DEL_CONTRACT_NE = 160174;
	//! 做市商双边撤单买卖方向相同
	const int TAPIERROR_ORDERMARKET_DEL_SIDE_EQ = 160175;
	//! 做市商双边撤单买卖方向错误
	const int TAPIERROR_ORDERMARKET_DEL_SIDE_ERROR = 160176;
	//! 做市商单边检查未通过
	const int TAPIERROR_ORDERMARKET_OTHER_SIDE_ERROR = 160177;
	//! 埋单激活失败，订单未找到
	const int TAPIERROR_ORDERACTIVATE_NOTFOUND_ERROR = 160181;
	//! 埋单激活失败，非有效状态
	const int TAPIERROR_ORDERACTIVATE_STATE_ERROR = 160182;
    //! 挂起激活失败，网关不支持
    const int TAPIERROR_ORDERACTIVATE_GATEWAY_ERROR = 160183;
    //! 操作员无跨中心下单权限
    const int TAPIERROR_TRANSIT_ORDERINSERT_RIGHT = 160191;
    //! 未连接中转服务
    const int TAPIERROR_TRANSIT_ORDERINSERT_DISCON = 160192;
    //! 下单未连接目标交易中心
    const int TAPIERROR_TRANSIT_ORDERINSERT_DISCON_DEST	= 160193;
    //! 撤单未连接目标交易中心
    const int TAPIERROR_TRANSIT_ORDERDELETE_DISCON_DEST	= 160194;
    //! 改单未连接目标交易中心
    const int TAPIERROR_TRANSIT_ORDERMODIFY_DISCON_DEST	= 160195;
    //! 错误的中转订单操作
    const int TAPIERROR_TRANSIT_ORDER_OPERATOR = 160196;
    //! 客户权限禁止买入
    const int TAPIERROR_ORDER_DISALLOWBUY_ACCOUNT = 160201;
    //! 客户权限禁止卖出
    const int TAPIERROR_ORDER_DISALLOWSELL_ACCOUNT = 160202;
    //! 系统权限禁止买入
    const int TAPIERROR_ORDER_DISALLOWBUY_SYSTEM = 160203;
    //! 系统权限禁止卖出
    const int TAPIERROR_ORDER_DISALLOWSELL_SYSTEM = 160204;
    //! 客户权限禁止卖开仓期权 -仅外盘系统
    const int TAPIERROR_ORDER_DIS_SELLOPTION_ACCOUNT = 160205;
    //! 系统权限禁止卖开仓期权 -仅外盘系统
    const int TAPIERROR_ORDER_DIS_SELLOPTION_SYSTEM = 160206;
    //! 非标准合约只可平仓
    const int TAPIERROR_ORDER_CONTRACT_CLOSE = 160207;
    //! 超出贷款限额
    const int TAPIERROR_ORDERINSERT_LOANAMOUNT = 160211;

    //! 此品种不支持组合策略
    const int TAPIERROR_COMBINE_COMMODITY = 160220;
    //! 组合申报合约期权类型不符合要求
    const int TAPIERROR_COMBINE_CALLORPUT = 160221;
    //! 拆分的组合持仓不存在
    const int TAPIERROR_COMBINE_COMPOSITION = 160222;
    //! 拆分的组合持仓数量不足
    const int TAPIERROR_COMBINE_COMPOSITION_QTY = 160223;
    //! 组合申报合约备兑标识不符合要求
    const int TAPIERROR_COMBINE_HEDGEFLAG = 160224;
    //! 组合申报合约买卖方向不符合要求
    const int TAPIERROR_COMBINE_ORDERSIDE = 160225;
    //! 组合申报合约大小不符合要求
    const int TAPIERROR_COMBINE_CONTRACTSIZE = 160226;
    //! 组合申报合约到期日不符合要求
    const int TAPIERROR_COMBINE_CONTRACTDAYS = 160227;
    //! 组合申报合约行权价不符合要求
    const int TAPIERROR_COMBINE_STRIKEPRICE = 160228;
    //! 相同合约不允许组合
    const int TAPIERROR_COMBINE_CONTRACT_SAME = 160229;
    
    //! 备兑解锁量不足
    const int TAPIERROR_ORDERINSERT_UNLOCK_NOE = 160230;
    //! 期权开仓备兑量不足
    const int TAPIERROR_ORDEROPEN_OPT_SPOT_NOE = 160231;
    //! 期权平仓备兑量不足
    const int TAPIERROR_ORDERCLOSE_OPT_SPOT_NOE = 160232;
    //! 无效的备兑订单
    const int TAPIERROR_ORDERINSERT_COVERED_UNVLD = 160233;

	//! 订单操作频率过高
	const int TAPIERROR_ORDER_FREQUENCY = 61001;
	//! 委托查询返回前不能进行下次查询
	const int TAPIERROR_ORDER_QUERYING = 61002;

    //! 前置不允许该模块登录
    const int TAPIERROR_TRADEFRONT_MODULETYPEERR = 190001;
    //! 一次请求太多数据
    const int TAPIERROR_TRADEFRONT_TOOMANYDATA = 190002;
    //! 前置没有所要数据
    const int TAPIERROR_TRADEFRONT_NODATA = 190003;
    //! 所查询的操作员信息不存在
    const int TAPIERROR_TRADEFRONT_NOUSER = 190004;
    //! 前置与交易断开
    const int TAPIERROR_TRADEFRONT_DISCONNECT_TRADE = 190011;
    //! 前置与管理断开
    const int TAPIERROR_TRADEFRONT_DISCONNECT_MANAGE = 190012;
    //! 下属资金账号不存在
    const int TAPIERROR_TRADEFRONT_ACCOUNT = 190021;
    //! 该操作员不允许交易
    const int TAPIERROR_TRADEFRONT_ORDER = 190022;
    //! 查询频率过快
    const int TAPIERROR_TRADEFRONT_FREQUENCY = 190023;
    //! 该授权不予许登录
    const int TAPIERROR_TRADEFRONT_RUFUSE = 190024;
    //! 自成交验证不通过
    const int TAPIERROR_TRADEFRONT_SELFMATCH = 190025;
    //! 非交易员不予许撤强平单
    const int TAPIERROR_TRADEFRONT_DELETEFORCE = 190026;
	/** @}*/

	//=============================================================================
	/**
	 *	\addtogroup G_ERR_CELPHONE 手机仿真返回错误码
	 *	@{
	 */
	//==============================================================================
	//! 会员系统地址信息不存在
	const int TAPIERROR_AddressLoss = 990001;
	//! 系统尚未登录
	const int TAPIERROR_UnLogin = 990002;
	//! 认证信息加密失败
	const int TAPIERROR_AuthEncryptFail = 990003;
	//! 网关未连或无效的后台
	const int TAPIERROR_ChannelCreateFail = 990004;
	//! 网关未就绪
	const int TAPIERROR_ChannelUnready = 990005;
	//! 协议格式错误
	const int TAPIERROR_PtlFmtError = 990006;
	//! 策略单服务未启用
	const int TAPIERROR_StrategyInactive = 990007;
	//! 策略单数据正在初始化中
	const int TAPIERROR_StrategyIniting = 990008;
	//! 密码错误
	const int TAPIERROR_PwdFail = 990009;
	//! 未找到原有连接
	const int TAPIERROR_NoUser = 990010;
	//! 登录数超限
	const int TAPIERROR_OnlineCountFail = 990011;
	//! 策略单已登录
	const int TAPIERROR_StrategyLogined = 990012;
	//! 请重新登录
	const int TAPIERROR_ReLogin = 990013;
	//! 触发时无法找到合适委托价
	const int TAPIERROR_NoPrice = 990101;
	//! 无法识别的策略单
	const int TAPIERROR_NoStrategy = 990102;
	//! 无法找到父单号
	const int TAPIERROR_NoParentOrder = 990103;
	//! 父单触发失败子单失效
	const int TAPIERROR_ParentOrderFail = 990104;
	//! 策略单未填写交易日
	const int TAPIERROR_NoTradeDate = 990105;
	//! 策略单操作未找到原定单
	const int TAPIERROR_NoOrderNo = 990106;
	//! 可平量不足
	const int TAPIERROR_CannotClose = 990107;
	//! 策略单立即触发
	const int TAPIERROR_ImmediateTrigger = 990108;
	//! 策略单立即触发
	const int TAPIERROR_OrderUnusual = 990109;
	//! 没有行情的合约
	const int TAPIERROR_NoQuote = 990110;
	//! 不支持的操作
	const int TAPIERROR_UnsupportedAction = 990201;
	//! 期货公司地址无法连接
	const int TAPIERROR_InvalidAddress = 990202;
	//! 不支持交易员登录
	const int TAPIERROR_UnsupportedLoginNo = 990203;
	//! 密码错误
	const int TAPIERROR_GwPwdFail = 990204;
	//! 密码错误次数超限
	const int TAPIERROR_PwdFailLimit = 990205;
	//! 非正常交易时段
	const int TAPIERROR_InvalidMarketState = 990206;
	//! 强制修改密码
	const int TAPIERROR_ForceChangePwd = 990207;
	//! 登录数超限
	const int TAPIERROR_LoginCount = 990208;
	//! 不支持的合约
	const int TAPIERROR_UnsupportedContract = 990301;
	//! 不支持的订单类型
	const int TAPIERROR_UnsupportedOrderType = 990302;
	//! 持仓不足平
	const int TAPIERROR_InadequatePosiQty = 990303;
	//! 资金不足
	const int TAPIERROR_InadequateMoney = 990304;
	//! 价格不在涨跌停范围
	const int TAPIERROR_UnsupportedPrice = 990305;
	//! 价格订单操作类型
	const int TAPIERROR_UnsupportedActType = 990306;
	//! 该委托状态无法撤单
	const int TAPIERROR_CancelState = 990307;
	//! 报单字段有误
	const int TAPIERROR_OrderFieldErr = 990308;
	//! 下单账号与登录账号不一致
	const int TAPIERROR_UnsupportedAcc = 990309;
	//! 委托不存在
	const int TAPIERROR_UnsupportedOrder = 990310;
	//! 不支持的币种
	const int TAPIERROR_UnsupportedCurrency = 990311;
	//! 发送登录请求失败
	const int TAPIERROR_SendLoginFail = 990312;
	//! 非交易时间
	const int TAPIERROR_InvalidTime = 990313;
	//! 行权/弃权可用量不足
	const int TAPIERROR_InadequateExecQty = 990314;

	/** @}*/
    
    //=============================================================================
    /**
     *	\addtogroup G_ERR_GATEWAY 上手网关错误代码	
     *	@{
     */
    //=============================================================================
    //! 发送数据失败
    const int TAPIERROR_ORDER_SEND                                         = 280001;
    //! 发送报单失败，网关没连接到交易所
    const int TAPIERROR_DLG_NULL                                           = 280002;
    //! 报单字段有误
    const int TAPIERROR_ORDER_FIELD                                        = 280003;
    //! 被上手拒绝
    const int TAPIERROR_TRADE_REJ_BYUPPER                                  = 280004;
    //! 当前时间不允许发送行权申请
    const int TAPIERROR_ORDER_FORBIDEXEC                                   = 280005;
	//! 网关未就绪，未连接上手
	const int TAPIERROR_GW_NOT_READY                                       = 180001;
	//! 品种错误
	const int TAPIERROR_GW_INVALID_COMMODITY                               = 180002;
	//! 合约错误
	const int TAPIERROR_GW_INVALID_CONTRACT                                = 180003;
	//! 报单字段有误
	const int TAPIERROR_GW_INVALID_FIELD                                   = 180004;
	//! 价格不合法
	const int TAPIERROR_GW_INVALID_PRICE                                   = 180005;
	//! 数量不合法
	const int TAPIERROR_GW_INVALID_VOLUME                                  = 180006;
	//! 报单类型不合法
	const int TAPIERROR_GW_INVALID_TYPE                                    = 180007;
	//! 委托模式不合法
	const int TAPIERROR_GW_INVALID_MODE                                    = 180008;
	//! 委托不存在（改单、撤单）
	const int TAPIERROR_GW_ORDER_NOT_EXIST                                 = 180009;
	//! 发送报单失败
	const int TAPIERROR_GW_SEND_FAIL                                       = 180010;
	//! 被上手拒绝
	const int TAPIERROR_GW_REJ_BYUPPER                                     = 180011;

    /** @}*/
}

#endif /* ESTRADEAPIERROR_H */
