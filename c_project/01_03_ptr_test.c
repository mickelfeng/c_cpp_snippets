// �� 17_CalcArrayCube ��ά��������ָ�����
#include <assert.h>
#include <string.h>
#include <malloc.h>

void char_test();

void ptrPlus1(char *ptr_s1);

void charPtrInit();

void charPtrInit2() {
    char a[] = "123456";
    char* input = a;
    strcpy(input, "888888"); // ���ܳ�����
    assert(strcmp(input, "888888") == 0);

}

int main(void) {
    charPtrInit();
    charPtrInit2();
    char_test();
    return 0;
}

void charPtrInit() {
    char *input = malloc(20);
    strcpy(input, "aaaabaaacaaadaaaeaaa");
}


void char_test() {
    char *ptr_s1 = "12345";
    assert(ptr_s1[0] == '1');
    ptrPlus1(ptr_s1);  // ���������Ӱ������
    assert(ptr_s1[0] == '1');
}

void ptrPlus1(char *ptr_s1) {
    ptr_s1++;
    assert(ptr_s1[0] == '2');
}
