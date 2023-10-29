
* [安装 wdk](https://learn.microsoft.com/zh-cn/windows-hardware/drivers/download-the-wdk#download-icon-step-3-install-wdk)
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