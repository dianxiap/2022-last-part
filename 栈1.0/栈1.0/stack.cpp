#define _CRT_SECURE_NO_WARNINGS 1
#include "stack.h"

int main()
{
	ST q;
	STInit(&q);
	STPush(&q, 1);
	STPush(&q, 2);
	STPush(&q, 3);
	STPush(&q, 4);
	STPush(&q, 5);
	int a = STTop(&q);
	printf("%d", a);
	STPop(&q);
	a = STTop(&q);
	printf("%d", a);


}