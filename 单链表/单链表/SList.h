#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int SLTDataType;


//��ʽ�ṹ�洢ÿһ���ڵ�
typedef struct SListNode
{
	SLTDataType data;   //�������
 	struct SListNade* next;  //ָ����һ���ڵ�
}SLTnode;

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

