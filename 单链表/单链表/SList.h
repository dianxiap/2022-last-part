#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int SLTDataType;

//����ڵ�
typedef struct SListNode
{
	SLTDataType data;   //�������
 	struct SListNade* next;  //ָ����һ���ڵ�
}SLTnode;

//����ڵ�
SLTnode* BuySLTNode(SLTDataType x);
//��ӡ
void SLTPrint(SLTnode* phead);
//β��
void SLTPushBack(SLTnode** pphead, SLTDataType x);
//ͷ��
void SLTPushFront(SLTnode** pphead, SLTDataType x);
//βɾ
void SLTPopBack(SLTnode** pphead);
//ͷɾ
void SLTPopFront(SLTnode** pphead);
//����
SLTnode* SLTFind(SLTnode* phead, SLTDataType);
//��pos֮ǰ����
void SLTInsert(SLTnode** pphead, SLTnode* pos, SLTDataType x);
//ɾ��pos֮ǰ�Ľڵ�
voide SLTErase(SLTnode** pphead, SLTnode* pos);
//��pos֮�����
void SLTInsertAftter(SLTnode* pos, SLTDataType x);
//ɾ��pos֮��Ľڵ�
void SLTEraseAfter(SLTnode* pos);
