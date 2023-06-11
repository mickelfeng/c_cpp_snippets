Google搜索 Visual Studio tutorials | C++
https://learn.microsoft.com/en-us/cpp/get-started/?view=msvc-170

# 1 错误处理

常见函数返回值的数据类型

void
bool
handle | 可操作对象,失败返回NULL, INVALID_HANDLE_VALUE 值为-1
pvoid | 标识数据块的内存地址, 失败为NULL
LONG/DWORD | 阅读SDK

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

每个错误分为: 消息ID，消息文本，编号。

Windows函数失败后应该马上调用 GetLastError, 因为其他函数调用后可能会改写, 成功调用的 Windows 函数可以用 ERROR_SUCCESS 改写此值。

已存在具名事件返回  ERROR_ALREADY_EXISTS

调试时 在监视1窗口(Watch 1)中输入 $err,hr 即可查看GetLastError

[FormatMesage](https://learn.microsoft.com/en-us/windows/win32/api/winbase/nf-winbase-formatmessage) 将错误代码转为文本描述。

## 1.1 定义自己的错误代码
设置线程的上一个错误代码，令自己的函数返回FALSE, INVALID_HANDLE_VALUE, NULL或其他适合值。

```
VOID SetLastError(DWORD dwErrCode)
```

| 位   | 31-30                                                        | 29                                              | 28       | 27-16                    | 15-0                        |
| ---- | ------------------------------------------------------------ | ----------------------------------------------- | -------- | ------------------------ | --------------------------- |
| 内容 | 严重性                                                       | Microsoft                                       | 保留     | Facility                 | 异常代码                    |
| 含义 | 0 = 成功<br />1 = 信息（提示） <br />2 = 警告<br />     3 = 错误 | 0  = Microsoft 定义的代码<br>1  = 客户定义的代码 | 必须为 0 | 前256个值由Microsoft保留 | Microsoft  / 客户定义的代码 |

## 1.2 ErrorShow示例程序

# 2 字符和字符串处理
有2个版本 CreateWindowEx, 平时只用 CreateWindowEx 即可 它是一个宏。默认会调W版本

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

| 应用程序类型                         | 入口点函数           | 嵌入可执行文件的启动函数 |
| :----------------------------------- | :------------------- | :----------------------- |
| 处理ANSI字符和字符串的GUI应用程序    | _tWinMain (WinMain)  | WinMainCRTStartup        |
| 处理Unicode字符和字符串的GUI应用程序 | _tWinMain (wWinMain) | wWinMainCRTStartup       |
| 处理ANSI字符和字符串的CUI应用程序    | _tmain (Main)        | mainCRTStartup           |
| 处理Unicode字符和字符串的CUI应用程序 | _tmain (Wmain)       | wmainCRTStartup          |

/SUBSYSTEM:WINDOWS 会找 `WinMain` 或 `wWinMain` 找不到会返回 "unresolved external symbol" 否则根据情况选择 `WinMainCRTStartup` 或 `wWinMainCRTStartup`


# Windows全新开发编程实例教程

## Visual Studio

* 头文件包含 prgama 和 ifndef 一样, 包含一次
#prgama once
#ifndef
#define


# Aritcle

[键盘消息 | [原创] 从应用层到MCU，看Windows处理键盘输入 [1.在应用层调试Notepad.exe (按键消费者)] ](https://bbs.kanxue.com/user-home-399589.htm)
[国外油管大神C++游戏编程实战教程，新手6小时入门，并快速达到游戏开发能力（中英字](https://www.bilibili.com/video/BV16h4y1d766/) 


