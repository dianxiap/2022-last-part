#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

struct S {
    int n;
    int arr[0];  //前面至少有一个成员
};

int main() {

    printf("%d", sizeof(struct S));
    //后面+的大小就是给柔性数组准备的
    struct S* ps = (struct S*)malloc(sizeof(struct S) + sizeof(int));

    return 0;
}