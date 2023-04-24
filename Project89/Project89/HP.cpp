#define _CRT_SECURE_NO_WARNINGS 1
#include "HP.h"

void Swap(int* p1, int* p2)
{
	int t = *p1;
	*p1 = *p2;
	*p2 = t;
}
// 堆的创建
void HeapInit(Heap* ps)
{
	assert(ps);
	ps->a = (HPDataType*)malloc(sizeof(HPDataType) * 4);
	if (ps->a == NULL)
	{
		perror("malloc fail");
		return;
	}
	ps->size = 0;
	ps->capacity = 4;
}
// 向上调整
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
// 向下调整
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

// 堆的销毁
void HeapDestroy(Heap* ps)
{
	assert(ps);
	free(ps->a);
	ps->a = NULL;
	ps->size = ps->capacity = 0;
}
// 插入
void HeapPush(Heap* ps, HPDataType x)
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
// 堆是否为空
bool HeapEmpty(Heap* ps)
{
	assert(ps);
	return ps->size == 0;
}

// 弹出
void HeapPop(Heap* ps)
{
	assert(ps);
	assert(!HeapEmpty(ps));
	Swap(&ps->a[0], &ps->a[ps->size - 1]);
	ps->size--;
	AdjustDown(ps->a, ps->size, 0);
}
// 返回堆顶数据
HPDataType HeapTop(Heap* ps)
{
	assert(ps);

	return ps->a[0];
}
// 堆内元素个数
int HeapSize(Heap* ps)
{
	assert(ps);
	return ps->size;
}