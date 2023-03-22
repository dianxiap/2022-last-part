#define _CRT_SECURE_NO_WARNINGS 1
#include "heap.h"

//堆的初始化
void HeapInit(Hp* php)
{
	assert(php);
	php->a = (HpdataType*)malloc(sizeof(HpdataType) * 4);
	if (php->a == NULL)
	{
		perror("malloc fail");
		return;
	}
	php->size = 0;
	php->capacity = 4;
}

//交换堆里的两个数据
void Swap(HpdataType* p1, HpdataType* p2)
{
	HpdataType x = *p1;
	*p1 = *p2;
	*p2 = x;
}
//向上调整
void AdjustUp(HpdataType* a, int child)
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
		else
		{
			break;
		}
	}
}
//向下调整
void AdjustDown(HpdataType* a,int n, int parent)
{
	int child = parent * 2 + 1;
	while(child<n)
	{
		if (child + 1 < n && a[child + 1] > a[child])
		{
			++child;
		}
		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}
//堆的销毁
void HeapDestory(Hp* php)
{
	free(php->a);
	php->a == NULL;
	php->size = php->capacity = 0;
}
//增加数据
void HeapPush(Hp* php, HpdataType x)
{
	assert(php);
	if (php->size == php->capacity)
	{
		HpdataType* tem = (HpdataType*)realloc(php->a, sizeof(HpdataType) * php->capacity * 2);
		if (tem == NULL)
		{
			perror("realloc fail");
			return;
		}
		php->a = tem;
		php->capacity *= 2;
	}
	php->a[php->size++] = x;
	AdjustUp(php->a, php->size - 1);
}
//弹出堆顶数据
void HeapPop(Hp* php)
{
	assert(php);
	assert(!Heapempty(php));
	Swap(&php->a[0], &php->a[php->size - 1]);
	php->size--;
	AdjustDown(php->a, php->size, 0);
}
//返回堆顶数据
HpdataType HeapTop(Hp* php)
{
	assert(php);
	return php->a[0];
}
//判断堆是否为空
bool Heapempty(Hp* php)
{
	assert(php);
	return php->size == 0;
}
//堆内元素个数
int HeapSize(Hp* php)
{
	assert(php);
	return php->size;
}