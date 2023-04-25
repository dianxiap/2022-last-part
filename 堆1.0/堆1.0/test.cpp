#define _CRT_SECURE_NO_WARNINGS 1
#include "Heap.h"

int main()
{
	Heap p;
	HeapInit(&p);
	HeapPush(&p, 1);
	HeapPush(&p, 6);
	HeapPush(&p, 5);
	HeapPush(&p, 4);
	HeapPush(&p, 3);
	HeapPush(&p, 2);
	
	while (HeapSize(&p))
	{
		printf("%d ", HeapTop(&p));
		HeapPop(&p);
	}
}