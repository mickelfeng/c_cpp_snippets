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
| 3   | Test.py  |
