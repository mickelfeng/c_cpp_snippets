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

# Make
./configure --prefix=/home/kali/Downloads/yafu/ecm_bin # 安装目录

```sh
LIBS += -L../msieve
LIBS += -lmsieve -ldl
# 即等于, -L指定查找路径 -l指定库
LIBS += -L../msieve -lmsieve -ldl

# INC加.h, LIBS加库
INC += -I../gmp_install/gmp-6.2.0/include
LIBS += -L../gmp_install/gmp-6.2.0/lib

```

**指定LIB目录的方式, 可用以下几种**

1. 用libtool，and specify the full pathname of the library
2. use the '-LLIBDIR' 配合下面
   - add LIBDIR to the 'LD_LIBRARY_PATH' environment variable
     during execution
   - add LIBDIR to the 'LD_RUN_PATH' environment variable
     during linking
   - use the '-Wl,-rpath -Wl,LIBDIR' linker flag
   - have your system administrator add LIBDIR to '/etc/ld.so.conf'
   /bin/bash ./libtool   --mode=install /usr/bin/install -c ecm '/usr/local/bin' 
   libtool: install: /usr/bin/install -c ecm /usr/local/bin/ecm
