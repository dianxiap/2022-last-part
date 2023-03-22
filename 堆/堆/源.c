#define _CRT_SECURE_NO_WARNINGS 1
#include "heap.h"
int main()
{
	Hp hp;
	HeapInit(&hp);
	HeapPush(&hp, 2);
	HeapPush(&hp, 22);
	HeapPush(&hp, 42);
	HeapPush(&hp, 5);
	HeapPush(&hp, 76);
	HeapPush(&hp, 100);
	while (HeapSize(&hp))
	{
		printf("%d ", HeapTop(&hp));
		HeapPop(&hp);
	}
}