# functions

## strcmp(s1, s2)

当 s1<s2 时，返回为负数；
当 s1=s2 时，返回值= 0；
当 s1>s2 时，返回正数。 [2]

if !(strcmp(s1, s2)) --> s1 == s2 时 echo
echo

## read(int fd, void \*buf, size_t count)

成功返回读取的字节数，出错返回-1 并设置 errno，如果在调 read 之前已到达文件末尾，则这次 read 返回 0。

## fd

| fd  | 文件指针 |
| --- | -------- |
| 0   | stdin    |
| 1   | stdout   |
| 2   | stderr   |
| 3   | Test.py - 通常由3开始 |

### dup/dup2

dup用来复制参数oldfd所指的文件描述符。当复制成功是，返回最小的尚未被使用过的文件描述符，若有错误则返回-1.错误代码存入errno中返回的新文件描述符和参数oldfd指向同一个文件，这两个描述符共享同一个数据结构，共享所有的锁定，读写指针和各项全现或标志位。

```
#include <unistd.h>
int dup2(int oldfd, int newfd);
```

dup2与dup区别是dup2可以用参数newfd指定新文件描述符的数值。若参数newfd已经被程序使用，则系统就会将newfd所指的文件关闭，若newfd等于oldfd，则返回newfd,而不关闭newfd所指的文件。dup2所复制的文件描述符与原来的文件描述符共享各种文件状态。共享所有的锁定，读写位置和各项权限或flags等.

返回值： 若dup2调用成功则返回新的文件描述符，出错则返回-1.