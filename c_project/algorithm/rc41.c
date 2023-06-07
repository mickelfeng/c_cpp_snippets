#include <string.h>
#include "stdio.h"

// 初始化函数
void rc4_init(unsigned char *s, unsigned char *key, unsigned long Len) {
    int i = 0, j = 0;
    // char k[256]={0};
    unsigned char k[256] = {0};
    unsigned char tmp = 0;
    for (i = 0; i < 256; i++) {
        s[i] = i;
        k[i] = key[i % Len];
    }
    for (i = 0; i < 256; ++i) {
        j = (j + s[i] + k[i]) % 256;
        tmp = s[i];
        s[i] = s[j]; // 交换 s[i] 和 s[j]
        s[j] = tmp;
    }
}

/* 加解密 */
void rc4_crypt(unsigned char *s, unsigned char *Data, unsigned long Len) {
    int i = 0, j = 0, t = 0;
    unsigned long k = 0;
    unsigned char tmp;
    for (k = 0; k < Len; ++k) {
        i = (i + 1) % 256;
        j = (j + s[i]) % 256;
        tmp = s[i];
        s[i] = s[j]; // 交换 s[i] 和 s[j]
        s[j] = tmp;
        t = (s[i] + s[j]) % 256;
        Data[k] ^= s[t];
    }
}

int main(int argc, char *argv[], char **env) {
    char sbox[8];
    char k[] = "12345678";
    char data[8] = "12345678";

    rc4_init(sbox, k, 8);
    rc4_crypt(sbox, data, 8);
    return 0;
}