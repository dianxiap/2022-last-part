#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

namespace dx
{
    // 命名空间中可以定义变量/函数/类型
    int a = 0;
    int b = 1;
    int Add(int left, int right)
    {
        return left + right;
    }
    struct Node
    {
        struct Node* next;
        int val;
    };
}
int main()
{
    printf("%d\n", a);
    return 0;
}
