[常用的Linux Hooking技术总结](https://mp.weixin.qq.com/s/AmOw6JQtkP7XXrisYtHq1Q)
[快速了解操作系统的文件系统设计](https://mp.weixin.qq.com/s/OOjhVuNLJr_r1jzVJRocXA)


FAQ

编译共享库 -shared时失败 `gcc -shared -o "libalg.so"  ./sort.o`
1. relocation `R_X86_64_PC32 against undefined symbol`
Q. -fPIC

## no such instruction: 'endbr64'

```
sudo apt-get remove binutils
sudo apt-get remove --auto-remove binutils
sudo apt install build-essential
```

