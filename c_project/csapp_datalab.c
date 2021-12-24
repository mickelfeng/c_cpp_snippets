// http://saladk.com/index.php/archives/15/#toc-6isAsciiDigit
#include <stdio.h>
#include <stdbool.h>

void print_bin(int number) {
    int bit = sizeof(int) * 8;
    int i;
    for (i = bit - 1; i >= 0; i--) {
        int bin = (number & (1 << i)) >> i;
        printf("%d", bin);
    }
    printf("\n");
}

int bitXor(int x, int y) {
    return ~((~x) & (~y)) & (~(x & y));
}

int tmin(void) { // 最小的二进制补码整数

    return 2 << 30;

}

// 所有奇数位都设置为1是包括了 0xAAAAAAAA 和 0xffffffff 两种情况，实验要求只能使用的数据是 0 - 0xff, 所以用 0xAA构造掩码 0xAAAAAAAA，用 x & 0xAAAAAAAA ，排除 0xffffffff的情况
int allOddBits(int x) {
    int mask = 0xAA + (0xAA << 8); // A -> 1010
    mask = mask + (mask << 16);
    x = (x & mask) ^ mask;
    return !x;
}

int negate(int x) {
    return (~x + 1);
}

int conditional(int x, int y, int z) {
    int flag = (~!!x) + 1;
    return ((flag & y) | (~flag & z));
}

/**
 * 需要写一个函数判断参数是不是在'0'-'9'范围之间。（也就是int类型的30-39）
   因为本题要返回1或者0，所以return中应该使用&（两个条件需要同时满足）。
   如果x≥30，则(x + (~min + 1))就≥0，则最高位就是0.反之，最高位就是1.
 * @param x
 * @return
 */
int isAsciiDigit(int x) {
    int min = 0x30;
    int max = 0x39;

    return (!((x + (~min + 1)) >> 31)) & (!((max + (~x + 1)) >> 31));
    //tip: return with &.
}

int isAsciiDigit2(int x) {
    int sign = 1 << 31;
    int upperBound = ~(sign | 0x39);   /*if > 0x39 is added, result goes negative*/
    int lowerBound = ~0x30;            /*when < 0x30 is added, result is negative*/

    /*now add x and check the sign bit for each*/
    upperBound = sign & (upperBound + x) >> 31;
    lowerBound = sign & (lowerBound + 1 + x) >> 31;
    /*if either result is negative, it is not in desired range*/
    return !(upperBound | lowerBound);
}


int main() {
    print_bin(8);
    printf("%d\n", bitXor(3, 8)); // 011 | 100 => 111 = 11
    printf("%d\n", tmin());
    printf("%d\n", allOddBits(0xAAAAAAAA));
    printf("%d\n", negate(11));
    printf("%d\n", conditional(2 < 1, 991992, 59193));
    printf("%d\n", conditional(2 > 1, 991992, 59193));
    printf("%d\n", isAsciiDigit('a'));
    printf("%d\n", isAsciiDigit('0'));
    printf("%d\n", isAsciiDigit('9'));

    return 0;
}
