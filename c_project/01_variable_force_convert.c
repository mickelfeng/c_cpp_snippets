#include <string.h>
#include "stdio.h"

void foo_cast();

void cast_char_int();

int main(int argc, char *argv[], char **env) {
//    foo_cast();
    cast_char_int();
    return 0;
}

void cast_char_int() {
    unsigned char ida_chars[] = {0x56, 0x02, 0x00, 0x00, 0xa, 0x00, 0x00, 0x00,};
    for (int i = 0; i < 2; ++i) {
        printf("%d\n", *((int *) ida_chars + i));
        // expected  {0x256, 0xa};
    }
};

void foo_cast() {
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
}
