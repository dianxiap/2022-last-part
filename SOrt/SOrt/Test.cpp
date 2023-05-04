#define _CRT_SECURE_NO_WARNINGS 1
#include "Sort.h"

int main()
{
	int a[10] = { 0,5,1,3,46,56,46,7,321,86 };
	HeapSort(a, 10);
	PrintArray(a, 10);
	return 0;
}