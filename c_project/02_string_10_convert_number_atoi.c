#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void left_align_sprintf();

void left_align_itoa();

void right_align_snprintf();

void basic();

int main() {
    // basic();
    // left_align_sprintf();
    // left_align_itoa();
    right_align_snprintf();

    return(0);

}

void basic() {
    int val;
    char str[20];

    strcpy(str, "98993489");
    val = atoi(str);
    printf("字符串值 = %s, 整型值 = %d\n", str, val);

    strcpy(str, "runoob.com");
    val = atoi(str);
    printf("字符串值 = %s, 整型值 = %d\n", str, val);
}

void right_align_snprintf() {
    // 右对齐, n为长度+1，需要1个结束符
    char a[16];
    size_t i;
    int len = 12;
    i = snprintf(a, len + 1, "%012d", 12345);  // 第 1 种情况
    printf("i = %lu, a = %s\n", i, a);    // 输出：i = 12, a = 000000012345
    i = snprintf(a, 8 + 1, "%012d", 12345);   // 第 2 种情况
    printf("i = %lu, a = %s\n", i, a);    // 输出：i = 12, a = 00000001
    i = snprintf(a, 3 + 1, "%04d", 12345);   // 第 2 种情况
    printf("i = %lu, a = %s\n", i, a);    // 输出：i = 12, a = 00000001


}

void left_align_itoa() {
    char str[6];
    itoa(123, str, 10); // 3 转为了 [3, 0, 0,0,0,0]
    itoa(123, str, 16);
    printf("%s\n", str);
}

void left_align_sprintf() {
    char str[6];
    sprintf(str, "%d", 3); // 3 转为了 [3, 0, 0,0,0,0]
    printf("%s\n", str);
}
