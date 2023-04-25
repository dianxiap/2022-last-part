#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int HPDataType;

typedef struct Heap
{
	HPDataType* a;
	int size;
	int capacity;
}HP;

// 堆的初始化
void HeapInit(HP* ps);
// 堆的销毁
void HeapDestroy(HP* ps);
// 堆的插入
void HeapPush(HP* ps, HPDataType x);
// 弹出
void HeapPop(HP* ps);
// 返回堆顶元素
HPDataType HeapTop(HP* ps);
// 堆的大小
int HeapSize(HP* ps);
// 判断堆是否为空
bool HeapEmpty(HP* ps);
// 向上调整
void AdjustUp(HPDataType* a, int child);
// 向下调整
void AdjustDown(HPDataType* a, int n, int parent);
