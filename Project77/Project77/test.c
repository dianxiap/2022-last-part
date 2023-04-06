#define _CRT_SECURE_NO_WARNINGS 1
#include "sort.h"

int main()
{
	int a[] = { 9,8,7,1,2,3,6,5,4 };
	int len = sizeof(a) / sizeof(a[0]);
	QuickSort(a, 0,len-1);
	for (int i = 0; i < len; i++)
	{
		printf("%d ", a[i]);
	}
}