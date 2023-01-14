#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

union Un
{
    char c; // 1
    int i; // 4
};

int main()
{
    union Un u;
    printf("%p\n", &u);
    printf("%p\n", &(u.c));
    printf("%p\n", &(u.i));

    return 0;
}