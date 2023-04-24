#pragma once
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

typedef int HPDataType;

typedef struct Heap
{
	HPDataType* a;
	int size;
	int capacity;
}Heap;


// 堆的创建
void HeapInit(Heap* ps);
// 堆的销毁
void HeapDestroy(Heap* ps);
// 插入
void HeapPush(Heap* ps, HPDataType x);
// 弹出
void HeapPop(Heap* ps);
// 返回堆顶数据
HPDataType HeapTop(Heap* ps);
// 堆内元素个数
int HeapSize(Heap* ps);
// 堆是否为空
bool HeapEmpty(Heap* ps);
// 向上调整
void AdjustUp(HPDataType* a, int child);
// 向下调整
void AdjustDown(HPDataType* a, int n, int parent);
