#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <errno.h>//必须包含的头文件
int main()
{
    FILE* pFile;
    pFile = fopen("unexist.ent", "r");
    if (pFile == NULL)
    {   
        perror("error message :");
    }
    return 0;
}