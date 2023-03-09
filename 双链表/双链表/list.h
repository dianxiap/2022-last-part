#pragma once
#include <stdbool.h>
#include <stdio.h>
#include <assert.h>

typedef int LTDataType;
typedef struct ListNode
{
	LTDataType data;
	struct ListNode* next;
	struct ListNode* prev;
}listnode;

//�����ڵ�
listnode* Buylistnode(LTDataType x);
//˫�����ʼ��
listnode* init();
//˫������Ĵ�ӡ
void listprint(listnode* phead);
//˫�������β��
void listpushback(listnode* phead, LTDataType x);
//˫�������βɾ
void listpopback(listnode* phead);
//˫�������ͷ��
void listpushfront(listnode* phead, LTDataType x);
//˫�������ͷɾ
void listpopfront(listnode* phead);
//˫���������
listnode* listfind(listnode* phead, LTDataType x);
//˫������posλ��ǰ�����
void listinsert(listnode* pos, LTDataType x);
//˫������ɾ��pos���Ľڵ�
void listerase(listnode* pos);