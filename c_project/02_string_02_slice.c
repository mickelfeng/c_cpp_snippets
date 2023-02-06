#include <stdio.h>
#include <string.h>

int main() {
    char src[40];
    char dest[12];

    memset(dest, '\0', sizeof(dest));
    strcpy(src, "Hello World!");
    strncpy(dest, src, 5);
    dest[5] = '\0';   /* 手动加上终止符, 不然可能出问题 */

    printf("Result： %s\n", dest);
    return (0);
}