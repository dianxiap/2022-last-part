#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>

int main()
{
    // 40
    int arr[10] = { 0 };
    memset(arr, 1, sizeof(arr)); // 将前20个字节全部设置为1

    for(int i=0;i<10;i++)
        printf("%d ",arr[i]);
    return 0;
}