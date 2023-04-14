#include<stdio.h>
#include "MyIOLib.h"
int ReadLine(char *str, int max_size)
{
    //读入一行字符串存入str中 
    char ch;
    int i = 0;

    //最多读入max_size个字符(不包含结尾标记'\0') 
    while((ch = getchar()) != '\n')
        if(i < max_size) str[i++] = ch;
           str[i] = '\0';
    //返回实际读入的字符数量(不包含结尾标记'\0')
    return i; 
}
