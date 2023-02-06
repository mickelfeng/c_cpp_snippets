# include <stdio.h>

int main(void) {
    int a = 0x31;
    int b = 0xb;
    printf("int %d\n", a);
    printf("hex %x\n", a);
    printf("hex unsign %X\n", a);
    printf("char %c\n", a);
    printf(" %.2x", b); // 0b
    return 0;
}