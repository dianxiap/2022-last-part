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

//�ѵĳ�ʼ��
void HeapInit(Hp* php);
//�ѵ�����
void HeapDestory(Hp* php);
//��������
void HeapPush(Hp* php, HpdataType x);
//�����Ѷ�����
void HeapPop(Hp* php);
//���ضѶ�����
HpdataType HeapTop(Hp* php);
//�ж϶��Ƿ�Ϊ��
bool Heapempty(Hp* php);
//����Ԫ�ظ���
int HeapSize(Hp* php);
//���ϵ���
void AdjustUp(HpdataType* a, int child);
//���µ���
void AdjustDown(HpdataType* a,int n, int paret);