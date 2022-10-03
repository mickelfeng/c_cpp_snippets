#include <string.h>
#include "stdio.h"

static const unsigned long FK[4] = {0xa3b1bac6, 0x56aa3350, 0x677d9197, 0xb27022dc};

int main(int argc, char *argv[], char **env) {
    __int64 a[] = {0, 0x410A4335494A0942, 0x0B0EF2F50BE619F0, 0x4F0A3A064A35282B, 0};
    __int64 i;
    char str[] = "zer0pts{********CENSORED********}\0";
    char emptyArr[256] ={}; // 全都是 \x00


    // long long int 1
    for (i = 0; i < 5; i++) {
        printf("%lld\n", ((long long int *) str)[i]);
    }

    // long long int 2
    __int64 *b;
    b = (long long int *) str;
    for (i = 0; i < 5; i++) {
        printf("%lld\n", b[i]);
    }

    // 0x31, 0x32, 0x33, 0x34 => 0x34333231
    char c[] = {0x31, 0x32, 0x33, 0x34};
    for (int j = 0; j < sizeof(c); j += 4) {
        printf("\n%x", *(int *) (c + j));
    };

    return 0;
}