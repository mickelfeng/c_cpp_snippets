cmake_minimum_required(VERSION 3.19)
project(c_project C)

set(CMAKE_C_STANDARD 99)
#add_executable(rc4  RC4.c)
# 遍历项目根目录下所有的 .c 文件
file (GLOB files *.c **/*.c)
foreach (file ${files})
    # 正则替换file的字符, 保存到exe
    string(REGEX REPLACE ".+/(.+)\\..*" "\\1" exe ${file})
    # add_executable (${exe} ${file} file_07_getFileSize.c)
    add_executable (${exe} ${file})
    message (\ \ \ \ --\ src/${exe}.c\ will\ be\ compiled\ to\ bin/${exe})
endforeach ()
