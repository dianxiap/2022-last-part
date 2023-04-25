#define _CRT_SECURE_NO_WARNINGS 1
#include "Heap.h"

void Swap(int* p1, int* p2)
{
	int t = *p1;
	*p1 = *p2;
	*p2 = t;
}
// ���ϵ���
void AdjustUp(HPDataType* a, int child)
{
	int parent = (child - 1) / 2;
	while (child > 0)
	{
		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else break;
	}
}
// ���µ���
void AdjustDown(HPDataType* a, int n, int parent)
{
	int child = parent * 2 + 1;
	while (child < n)
	{
		if (child + 1 < n && a[child + 1] > a[child])
		{
			child++;
		}
		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else break;
	}
}
// �ѵĳ�ʼ��
void HeapInit(HP* ps)
{
	assert(ps);
	ps->a = (HPDataType*)malloc(sizeof(HPDataType) * 4);
	assert(ps->a);
	ps->capacity = 4;
	ps->size = 0;
}
// �ѵ�����
void HeapDestroy(HP* ps)
{
	assert(ps);
	free(ps->a);
	ps->a = NULL;
	ps->size = ps->capacity = 0;
}
// �ѵĲ���
void HeapPush(HP* ps, HPDataType x)
{
	assert(ps);
	if (ps->size == ps->capacity)
	{
		HPDataType* tmp = (HPDataType*)realloc(ps->a, sizeof(HPDataType) * ps->capacity * 2);
		if (tmp == NULL)
		{
			perror("realloc fail");
			return;
		}
		ps->a = tmp;
		ps->capacity *= 2;
	}
	ps->a[ps->size++] = x;
	AdjustUp(ps->a, ps->size - 1);
}
// ����
void HeapPop(HP* ps)
{
	assert(ps);
	Swap(&ps->a[0], &ps->a[ps->size - 1]);
	ps->size--;
	AdjustDown(ps->a, ps->size, 0);
}
// �ж϶��Ƿ�Ϊ��
bool HeapEmpty(HP* ps)
{
	assert(ps);
	return ps->size == 0;
}
// ���ضѶ�Ԫ��
HPDataType HeapTop(HP* ps)
{
	assert(ps);
	assert(!HeapEmpty(ps));
	return ps->a[0];
}
// �ѵĴ�С
int HeapSize(HP* ps)
{
	assert(ps);
	return ps->size;
}
