#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stddef.h>
struct S
{
	char c1;
	int a;
	char c2;
};
#define OFFSETOF(type,member) (size_t)&(((type*)0)->member)
int main()
{
	printf("%zd\n", OFFSETOF(struct S, c1));
	printf("%zd\n", OFFSETOF(struct S, a));
	printf("%zd\n", OFFSETOF(struct S, c2));
}