# VeighNa框架的易盛底层接口

<p align="center">
  <img src ="https://vnpy.oss-cn-shanghai.aliyuncs.com/vnpy-logo.png"/>
</p>

<p align="center">
    <img src ="https://img.shields.io/badge/version-9.0.3.16.0-blueviolet.svg"/>
    <img src ="https://img.shields.io/badge/platform-windows|linux-yellow.svg"/>
    <img src ="https://img.shields.io/badge/python-3.10|3.11|3.12|3.13-blue.svg" />
    <img src ="https://img.shields.io/github/license/vnpy/vnpy.svg?color=orange"/>
</p>

## 说明

基于易盛的启明星V9API的9.0.3.16接口封装开发，支持启明星后台系统，适用于内盘交易所交易。

## 安装

安装环境推荐基于4.3.0版本以上的【[**VeighNa Studio**](https://www.vnpy.com)】。

直接使用pip命令：

```
pip install vnpy_esunny
```


或者下载源代码后，解压后在cmd中运行：

```
pip install .
```

使用源代码安装时需要进行C++编译，因此在执行上述命令之前请确保已经安装了【Visual Studio（Windows）】或者【GCC（Linux）】编译器。

## 使用

以脚本方式启动（script/run.py）：

```
from vnpy.event import EventEngine
from vnpy.trader.engine import MainEngine
from vnpy.trader.ui import MainWindow, create_qapp

from vnpy_esunny import EsunnyGateway


def main():
    """主入口函数"""
    qapp = create_qapp()

    event_engine = EventEngine()
    main_engine = MainEngine(event_engine)
    main_engine.add_gateway(EsunnyGateway)
    
    main_window = MainWindow(main_engine, event_engine)
    main_window.showMaximized()

    qapp.exec()


if __name__ == "__main__":
    main()
```

## gateway调整说明

对比之前基于易盛的启明星/北斗星兼容交易API的1.0.2.2接口封装开发的esunny_gateway.py，目前的esunny_gateway.py做了以下调整：

1. QuoteApi中品种查询、合约查询以及行情订阅函数调用时都需要传入session（int）入参；

2. TradeApi采用vnpy_tap中tap_gateway.py的方式，登录之后先查询资金、持仓、委托、成交推送一次，后续收到更新再继续推送；

3. TradeApi调用insertOrder函数进行委托时，新增指定TacticsType策略单类型、TriggerCondition触发条件类型、TriggerPriceType触发价格类型字段传N，OrderSource委托来源字段传A（TAPI_ORDER_SOURCE_ESUNNY_API 易盛API）

4. TradeApi调用insertOrder函数进行委托时，金交所合约的HedgeFlag投机保值/HedgeFlag2投机保值2都和期货委托一致，传TAPI_HEDGEFLAG_T投机（之前esunny_gateway.py中金交所合约是传TAPI_HEDGEFLAG_N无）
