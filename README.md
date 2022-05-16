# C++项目推荐
10日c++实战狂练
https://light-city.club/sc/practical_exercises/10_day_practice/10_day/
一、一个项目就能入门C++： 
https://github.com/Light-City/CPlusPlusThings
二、C++实现的算法合集：C-Plus-Plus
https://github.com/TheAlgorithms/C-Plus-Plus
三、进阶指南：CppTemplateTutorial
https://github.com/wuye9036/CppTemplateTutorial
一、写一个小型STL库：MyTinySTL
https://github.com/Alinshans/MyTinySTL
二、小实战—俄罗斯广块：Tinytetris
https://github.com/taylorconor/tinytetris
三、学习下大佬们的代码，做个计算器：calculator
https://github.com/microsoft/calculator
四、TinyWebServer（3.6k+ star）
https://github.com/qinguoyi/TinyWebServer
以上所有资源的百度网盘地址：
链接: https://pan.baidu.com/s/11t9DU2faWzzc7YmveKjLWg 提取码: gggn 
如果地址失效，可以加qijianShow，备注322，我会发你最新链接
## 单引号与双引号
https://blog.csdn.net/xiebs/article/details/93466116
单引号 -> ascii码
双引号 -> 字符串->内存地址
## char*与char[]区别
```c
char ch1[] = "hello world";//字符数组, 大小不可变
char * ch3 = "hello world";//字符指针, 大小可变
strcpy(ch3, ch1);
printf("%s\n", ch1); // 这里不会执行的，上面出错了
```

## puts/putchar/printf
__puts(s)__
`s`可以是字符数组名或字符串常量。输出时遇到`'\0'`自动将其转换为`'\n'`，即输出字符串后换行。
puts()函数有返回值，如果输出成功，则返回换行符号`'\n'`，否则返回`EOF`（End Of File）。

__putchar(x)__
输出单个字符，x可以是一个字符常量、一个数组元素或一个整型数字（将输出其值所对应的编码符号，以ASCII码为例，当整型变量ch超出8位变量的范围时，ch则会变强制转化为8位变量（即取其低八位传过去输出），当为负数的时候，由于计算机存储负数是用补码表示的，所以传过去的二进制补码也被当做正数处理，也是取其低八位）。

__printf("%s"，s)__
s可以是字符数组名或字符串常量。输出时遇到'\0'结束。

# 编译
gcc -Os -ffunction-sections -fdata-sections -s -Wl,--gc-sections setkey.c
gcc -Os -ffunction-sections -fdata-sections -s setkey.c
链接参数LDFLAGS: -Wl,-Map=object.map,--cref,--gc-section
-g 产生带调试信息的编译后目标代码，供调试器(如gdb使用)
-m32  将int，long和指针设为32位，适用于i386
-m64  将int设为32位，long和指针设为64位，适用于X86-64
-mx32  将int，long和指针设为32位，适用于X86-64

最后上upx