#ifndef TAPDATACOLLECTAPI_H
#define TAPDATACOLLECTAPI_H

//! 成功
const int TAPIERROR_DataCollect_SUCCEED                                = 0;
//! 获取IP失败
const int TAPIERROR_IP                                                 = -1;
//! 获取MAC失败
const int TAPIERROR_MAC                                                = -2;
//! 获取设备名称失败
const int TAPIERROR_ComputerName                                       = -3;
//! 获取操作系统版本失败
const int TAPIERROR_OSVersion                                          = -4;
//! 获取硬盘序列号失败
const int TAPIERROR_HDID                                               = -5;
//! 获取CPU序列号失败
const int TAPIERROR_CPUSerialID                                        = -6;
//! 获取BIOS序列号失败
const int TAPIERROR_BIOSSerailID                                       = -7;
//! 获取系统分盘信息失败
const int TAPIERROR_SysDiskInfo                                        = -8;
//! 获取MacOS设备序列号失败
const int TAPIERROR_MacOsSerialID                                      = -9;

#pragma pack(push, 1)

//! 字符类型定义
typedef char ESSTR;
typedef char ESSTR_6[6];
typedef char ESSTR_10[10];
typedef char ESSTR_11[11];
typedef char ESSTR_13[13];
typedef char ESSTR_17[17];
typedef char ESSTR_20[20];
typedef char ESSTR_25[25];
typedef char ESSTR_30[30];
typedef char ESSTR_40[40];
typedef char ESSTR_50[50];
typedef char ESSTR_500[501];

//! 采集及采集库信息
struct LoginInfo
{
    ESSTR_500     GatherInfo;							///< 用户终端信息
    int           KeyVersion;                           ///< 采集库密钥版本
    ESSTR_50      ItemFalg;                             ///< 采集字段信息
    ESSTR_30      GatherLibVersion;                     ///< 采集库版本号
    ESSTR         IsTestKey;                            ///< 是否是测试密钥
    ESSTR         OperatingSystmeType;                  ///< 终端类型
};

#pragma pack(pop)

#if defined WIN32 || defined _WIN64
#define TAP_CDECL __cdecl
#define TAP_DLLEXPORT __declspec(dllexport)
#else
#define TAP_CDECL
#define TAP_DLLEXPORT
#endif

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus
  
TAP_DLLEXPORT int TAP_CDECL esunny_getLoginInfo(LoginInfo* pInfo);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif /* TAPDATACOLLECTAPI_H */

