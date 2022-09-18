#include <string.h>
#include "stdio.h"
#include <assert.h>


void printCharArray(const char *s1);

int cmp_test(const char *s1, const char *s2);

void printCharArray2();

int getInt(const char *sa, const char *str2);

void cmp_work1();

int getInt1( char *inst1,  char *inst2);

int main(int argc, char *argv[], char **env) {
    char s1[] = {'1', '2', '3', '\0'};
    printCharArray(s1);
    printCharArray2();

    cmp_work1();

    char inst1[] = "A";
    char inst2[] = "A";
    assert(strcmp(inst1, inst2) == 0);
    printf("%d\n", getInt1(inst1, inst2));

    return 0;
}

int getInt1(char *inst1, char *inst2) {
    return strcmp(inst1, inst2);
}

void cmp_work1() {
    char inst1[] = "A";
    char inst2[] = "A";
    assert(strcmp(inst1, inst2) == 0);
}

void printCharArray(const char *s1) {
    printf("%s", s1);
}

void printCharArray2() {
    char s[3] = {0x31, 0x32, 0x33};
    s[3] = '\0';
    printf("%s", s);
}

int cmp_test(const char *s1, const char *s2) {
    return strcmp(s1, s2);
}

