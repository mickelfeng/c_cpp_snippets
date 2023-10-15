cmake_minimum_required(VERSION 3.19)
project(del1)

set(CMAKE_CXX_STANDARD 14)

#add_executable(del1 main.cpp)
#
#add_executable(cpp_file_02_write file_02_write.cpp)
#add_executable(cpp_file_03_read file_03_read.cpp)
#add_executable(cpp_string_30_reverse string_30_reverse.cpp)
#add_executable(1123 file_03_read_whole_content.cpp)
file (GLOB files *.cpp a01_basic/*.cpp)
foreach (file ${files})
    string(REGEX REPLACE ".+/(.+)\\..*" "\\1" exe ${file})
    add_executable (${exe}cpp ${file})
    message (\ \ \ \ --\ src/${exe}.cpp\ will\ be\ compiled\ to\ bin/${exe})
endforeach ()
