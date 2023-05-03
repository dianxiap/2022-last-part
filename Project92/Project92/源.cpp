#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>	
int main()
{
	int a = 305419896, b = 1985229328, c, d;
	unsigned int ua = 305419896, ub = 1985229328, uc, ud;

	c = a + b;
	uc = ua + ub;

	d = a - b;
	ud = ua - ub;

	printf("%d+%d=%d\n", a, b, c);
	printf("%u+%u=%u\n", ua, ub, uc);
	printf("%d-%d=%d\n", a, b, d);
	printf("%u-%u=%u\n", ua, ub, ud);
}