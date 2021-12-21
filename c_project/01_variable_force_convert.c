#include <string.h>
#include "stdio.h"

int main(int argc, char *argv[], char **env) {
    __int64 a[] = {0, 0x410A4335494A0942, 0x0B0EF2F50BE619F0, 0x4F0A3A064A35282B, 0};
    __int64 i;
    char str[] = "zer0pts{********CENSORED********}\0";

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
    return 0;
}