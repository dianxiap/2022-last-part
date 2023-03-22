#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

typedef int HpdataType;

typedef struct Heap
{
	HpdataType* a;
	int size;
	int capacity;
}Hp;

//堆的初始化
void HeapInit(Hp* php);
//堆的销毁
void HeapDestory(Hp* php);
//增加数据
void HeapPush(Hp* php, HpdataType x);
//弹出堆顶数据
void HeapPop(Hp* php);
//返回堆顶数据
HpdataType HeapTop(Hp* php);
//判断堆是否为空
bool Heapempty(Hp* php);
//堆内元素个数
int HeapSize(Hp* php);
//向上调整
void AdjustUp(HpdataType* a, int child);
//向下调整
void AdjustDown(HpdataType* a,int n, int paret);