#pragma once
#include <iostream>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

typedef int SLTDataType;

typedef struct Node
{
	SLTDataType a;
	struct Node* next;
}Node;

// �����ʼ��
Node* BuyNode(SLTDataType x);
// ��ӡ
void SLPrint(Node* ps);
// �������
Node* SLTFint(SLTDataType x);
// ��������
void SLTDestroy(Node* ps);
// ����β��
void SLTPushBack(Node** ps,SLTDataType x);
// ����βɾ
void SLTPopBack(Node** ps);
// ����ͷ��
void SLTPushFront(Node** ps, SLTDataType x );
// ����ͷɾ
void SLTPopBack(Node** ps);
// ����posǰ����
void SLTInsert(Node** ps, Node* pos, SLTDataType x);
// ����posλ��ǰɾ��
void SLTErase(Node** ps, Node* pos);
// ����posλ�ú����
void SLTInsert(Node** ps, Node* pos, SLTDataType x);
// ����posλ�ú�ɾ��
void SLTInsert(Node** ps, Node* pos);




