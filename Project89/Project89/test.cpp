#define _CRT_SECURE_NO_WARNINGS 1
#include "HP.h"

int main()
{
	Heap p;
	HeapInit(&p);
	HeapPush(&p, 1);
	HeapPush(&p, 2);
	HeapPush(&p, 4);
	HeapPush(&p, 19);
	HeapPush(&p, 32);
	HeapPush(&p, 76);
	HeapPush(&p, 23);
	HeapPush(&p, 3);
	HeapPush(&p, 2);
	int k = 0;
	cin >> k;
	while (HeapSize(&p) && k--)
	{
		cout << HeapTop(&p) << ' ';
		HeapPop(&p);
	}

}