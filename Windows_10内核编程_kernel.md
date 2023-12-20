
* [安装 wdk 要和SDK版本相对应](https://learn.microsoft.com/zh-cn/windows-hardware/drivers/download-the-wdk#download-icon-step-3-install-wdk)
	- 其他wdk https://learn.microsoft.com/zh-cn/windows-hardware/drivers/other-wdk-downloads
* Installer 单个组件 MSVC v143 - VS 2022 C++ x64/x86 Spectre 缓解库 (要对应你的C++桌面开发的MSVC版本)
* [error: "No Target Architecture"](https://blog.csdn.net/wcc27857285/article/details/85197877)  项目属性 - C/C++ - 预处理器, 预处理定义添加 `_AMD64_`

# 1. Hello World
* 新建工程 - Empty WDM Driver
1. 顶部环境	修改为 x64
1. 项目属性 - C/C++ - 常规 - 警告视为错误 - 否
1. (可选, 找不到ntddk.h时) 项目属性 - C/C++ - 常规 - 附加包含目录 , 添加C:\Program Files (x86)\Windows Kits\10\Include\10.0.22621.0\km;
1. 项目属性 - C/C++ - 代码生成 - Spectre Mitigation - Disabled
2. Driver Files 下的 .inf 删除（初学不用）


# 内核编程
[Windows 内核编程》1.环境搭建以及第一个内核程序](https://www.bilibili.com/video/BV1Uw41127Vd/)
[Driver Download](https://learn.microsoft.com/zh-cn/windows-hardware/drivers/download-the-wdk#download-icon-step-3-install-wdk)
[Windows内核安全-字符串操作【逆向安全/漏洞安全/2023最新课程/CTF】- 极安御信系列课程](https://www.bilibili.com/video/BV19u4y1P7Cx/)
[Windows内核安全-R3与R0通信【逆向安全/漏洞安全/CTF】](https://www.bilibili.com/video/BV16Q4y1n7wu/)
[0环与3环通信方式](https://mp.weixin.qq.com/s/6nT5pwL9EXCAV2EIqaloPQ)
[驱动-内核空间与内核模块](https://mp.weixin.qq.com/s/GAWEoz4y0-UV-OZsgDflew)
[驱动第一次作业](https://mp.weixin.qq.com/s/AB9ygZfESAQHPzmJSwGK_w)
[2023零基础开发驱动之编写第一个驱动文件](https://www.bilibili.com/video/BV1Gy4y1w73n/)
[系统调用-3环进0环](https://mp.weixin.qq.com/s/ys4vFIP89Eozcq1Rpn_laA)
[3环与0环通信-代码](https://mp.weixin.qq.com/s/LRtn3YVR0eZuMPG3h_CQNw)
[进程与线程-EPROCESS&ETHREAD&KPCR](https://mp.weixin.qq.com/s/fxQUbD-OAlt57a9-28EShQ)
[进程与线程-内核隐藏进程](https://mp.weixin.qq.com/s/x3Lap1OMR3acMyIUJsWCug)
[进程与线程-模拟线程切换](https://mp.weixin.qq.com/s/CnbiMbHh_5FwHCYTRuXJdQ)