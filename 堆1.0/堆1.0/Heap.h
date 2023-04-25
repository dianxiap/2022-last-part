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

// �ѵĳ�ʼ��
void HeapInit(HP* ps);
// �ѵ�����
void HeapDestroy(HP* ps);
// �ѵĲ���
void HeapPush(HP* ps, HPDataType x);
// ����
void HeapPop(HP* ps);
// ���ضѶ�Ԫ��
HPDataType HeapTop(HP* ps);
// �ѵĴ�С
int HeapSize(HP* ps);
// �ж϶��Ƿ�Ϊ��
bool HeapEmpty(HP* ps);
// ���ϵ���
void AdjustUp(HPDataType* a, int child);
// ���µ���
void AdjustDown(HPDataType* a, int n, int parent);
