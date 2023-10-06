# 编译
## curl编译
Developer Command Prompt for VS 2022 启动命令行
nmake /f Makefile.vc mode=static VC=14 debug=no RTLIBCFG=static ENABLE_IDN=no
nmake /f Makefile.vc mode=static VC=14 RTLIBCFG=static ENABLE_IDN=no

# Cmake

```
# 去除未使用的函数
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wunused-function")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wunused-function")

# 设置CMake的构建类型为Release
set(CMAKE_BUILD_TYPE "Release")

## 设置编译器标志
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O3")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3")

```