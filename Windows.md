Google 搜索 Visual Studio tutorials | C++
https://learn.microsoft.com/en-us/cpp/get-started/?view=msvc-170

[C++课程资源.md](https://github.com/ritianpig/-/blob/main/C++%E8%AF%BE%E7%A8%8B%E8%B5%84%E6%BA%90.md)

# 1 错误处理

常见函数返回值的数据类型

void
bool
handle | 可操作对象,失败返回 NULL, INVALID_HANDLE_VALUE 值为-1
pvoid | 标识数据块的内存地址, 失败为 NULL
LONG/DWORD | 阅读 SDK

thread-local-storage 子线程处理错误，返回值指向已发生的错误, 具体错误调用

```c
DWORD GetLastError();
```

winerror.h 中包含了错误列表。

```
// MessageId: ERROR_SUCCESS
#define ERROR_SUCCESS                    0L
#define NO_ERROR 0L                                                 // dderror
```

每个错误分为: 消息 ID，消息文本，编号。

Windows 函数失败后应该马上调用 GetLastError, 因为其他函数调用后可能会改写, 成功调用的 Windows 函数可以用 ERROR_SUCCESS 改写此值。

已存在具名事件返回 ERROR_ALREADY_EXISTS

调试时 在监视 1 窗口(Watch 1)中输入 $err,hr 即可查看 GetLastError

[FormatMesage](https://learn.microsoft.com/en-us/windows/win32/api/winbase/nf-winbase-formatmessage) 将错误代码转为文本描述。

## 1.1 定义自己的错误代码

设置线程的上一个错误代码，令自己的函数返回 FALSE, INVALID_HANDLE_VALUE, NULL 或其他适合值。

```
VOID SetLastError(DWORD dwErrCode)
```

| 位   | 31-30                                                        | 29                                             | 28       | 27-16                        | 15-0                       |
| ---- | ------------------------------------------------------------ | ---------------------------------------------- | -------- | ---------------------------- | -------------------------- |
| 内容 | 严重性                                                       | Microsoft                                      | 保留     | Facility                     | 异常代码                   |
| 含义 | 0 = 成功<br />1 = 信息（提示） <br />2 = 警告<br /> 3 = 错误 | 0 = Microsoft 定义的代码<br>1 = 客户定义的代码 | 必须为 0 | 前 256 个值由 Microsoft 保留 | Microsoft / 客户定义的代码 |

## 1.2 ErrorShow 示例程序

# 2 字符和字符串处理

有 2 个版本 CreateWindowEx, 平时只用 CreateWindowEx 即可 它是一个宏。默认会调 W 版本

CreateWindowExW 接受 Unicode // Wide
CreateWindowExA 接受 Unicode // Ansi

# 4 进程

## 4.1 编写第一个 Windows 应用程序

CUI 程序链接器开关 /SUBSYSTEM:CONSOLE
GUI 程序链接器开关 /SUBSYSTEM:WINDOWS

入口点 两种

```c
int WINAPI _tWinMain()
int _tmain()
```

`-entry:启动函数`

| 应用程序类型                             | 入口点函数            | 嵌入可执行文件的启动函数 |
| :--------------------------------------- | :-------------------- | :----------------------- |
| 处理 ANSI 字符和字符串的 GUI 应用程序    | \_tWinMain (WinMain)  | WinMainCRTStartup        |
| 处理 Unicode 字符和字符串的 GUI 应用程序 | \_tWinMain (wWinMain) | wWinMainCRTStartup       |
| 处理 ANSI 字符和字符串的 CUI 应用程序    | \_tmain (Main)        | mainCRTStartup           |
| 处理 Unicode 字符和字符串的 CUI 应用程序 | \_tmain (Wmain)       | wmainCRTStartup          |

/SUBSYSTEM:WINDOWS 会找 `WinMain` 或 `wWinMain` 找不到会返回 "unresolved external symbol" 否则根据情况选择 `WinMainCRTStartup` 或 `wWinMainCRTStartup`

# Windows 全新开发编程实例教程

## Visual Studio

- 头文件包含 prgama 和 ifndef 一样, 包含一次
  #prgama once
  #ifndef
  #define

## 安全编程
- CTF\binary\Reverse\index.md

[Windows_Shellcode_内联汇编](https://secondbc.github.io/SecondBC/2023/06/19/Windows_Shellcode/)
[Windows 编程](https://secondbc.github.io/SecondBC/2022/12/04/Windows编程/)
[DLL 注入与 HOOK](https://secondbc.github.io/SecondBC/2022/12/12/DLL注入与HOOK/)
[远程线程注入-极安御信网络安全系列课程-病毒分析](https://www.bilibili.com/video/BV1ww411U71g/)
[PE 简单解析器](https://secondbc.github.io/SecondBC/2022/11/12/PE简单解析器/)
[一周学会 Windbg 调试器使用第 8 篇 - 何时使用 Windbg 进行动态调试](https://www.bilibili.com/video/BV1DX4y1b7bq/)
[极安御信网络安全系列课程-C++ shellcode加载器原理](https://www.bilibili.com/video/BV19P411v7rX/) 
[DLL显式调用及隐式调用](https://www.bilibili.com/video/BV1M44y1F79S/)
[dll延迟加载技术](https://mp.weixin.qq.com/s/wxNQ7yn1W1s85hR8CZGeRQ)
[免杀基础之DLL远程线程注入](https://mp.weixin.qq.com/s/oaVq98wxbA6OOxoMcStBIw)
[【逆向学习】Windows平台下的DLL注入](https://www.xunflash.top/archives/DLLInject.html) 

## 寻址
[动态寻找函数地址](https://mp.weixin.qq.com/s/zVJvggesZTtvvK__aR4jtw)

# Aritcle

[键盘消息 | [原创] 从应用层到 MCU，看 Windows 处理键盘输入 [1.在应用层调试 Notepad.exe (按键消费者)] ](https://bbs.kanxue.com/user-home-399589.htm)
[国外油管大神 C++游戏编程实战教程，新手 6 小时入门，并快速达到游戏开发能力（中英字](https://www.bilibili.com/video/BV16h4y1d766/)
[Windows远端线程执行任意API的设计与实现](https://mp.weixin.qq.com/s/bqLiDI-kt6dDIWyl-C3K0Q)
[windows-api-function-cheatsheets](https://github.com/snowcra5h/windows-api-function-cheatsheets)
[极安御信网络安全系列课程Windows编程基础-Windows窗口API详解](https://www.bilibili.com/video/BV1cV4y1e7pq/)
## network
[socket 网络编程的 5 大隐患](https://mp.weixin.qq.com/s/KDF0lTR7PiA4K2JQjsZxEg)

## MFC
[极安御信网络安全系列课程-Windows逆向基础-MFC源码分析(MFC窗口创建机制)](https://www.bilibili.com/video/BV1Ym4y1q7FD/) 

## 内核编程
[Windows内核编程》1.环境搭建以及第一个内核程序](https://www.bilibili.com/video/BV1Uw41127Vd/)

## Tools

[Dependency Ms](https://learn.microsoft.com/zh-cn/cpp/windows/understanding-the-dependencies-of-a-visual-cpp-application?view=msvc-170) [Win8 前](https://www.dependencywalker.com/) [Win8 后](https://github.com/lucasg/Dependencies)
