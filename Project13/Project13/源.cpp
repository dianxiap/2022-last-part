#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

struct S {
    int n;
    int arr[0];  //ǰ��������һ����Ա
};

int main() {

    printf("%d", sizeof(struct S));
    //����+�Ĵ�С���Ǹ���������׼����
    struct S* ps = (struct S*)malloc(sizeof(struct S) + sizeof(int));

    return 0;
}