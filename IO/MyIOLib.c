#include<stdio.h>
#include "MyIOLib.h"
int ReadLine(char *str, int max_size)
{
    //����һ���ַ�������str�� 
    char ch;
    int i = 0;

    //������max_size���ַ�(��������β���'\0') 
    while((ch = getchar()) != '\n')
        if(i < max_size) str[i++] = ch;
           str[i] = '\0';
    //����ʵ�ʶ�����ַ�����(��������β���'\0')
    return i; 
}
