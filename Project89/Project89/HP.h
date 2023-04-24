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


// �ѵĴ���
void HeapInit(Heap* ps);
// �ѵ�����
void HeapDestroy(Heap* ps);
// ����
void HeapPush(Heap* ps, HPDataType x);
// ����
void HeapPop(Heap* ps);
// ���ضѶ�����
HPDataType HeapTop(Heap* ps);
// ����Ԫ�ظ���
int HeapSize(Heap* ps);
// ���Ƿ�Ϊ��
bool HeapEmpty(Heap* ps);
// ���ϵ���
void AdjustUp(HPDataType* a, int child);
// ���µ���
void AdjustDown(HPDataType* a, int n, int parent);
