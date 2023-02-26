#define _CRT_SECURE_NO_WARNINGS 1
#include "SList.h"



SLTnode* BuySLTNode(SLTDataType x)
{
	SLTnode* newnode = (SLTnode*)malloc(sizeof(SLTnode));
	if (newnode == NULL)
	{
		perror("malloc");
		return;
	}
	newnode->data = x;
	newnode->next = NULL;

	return newnode;
}
void SLTPrint(SLTnode* phead)
{
	SLTnode* cur = phead;  //��ʱָ��
	while (cur != NULL)   //��Ϊ��
	{
		printf("%d->", cur->data);  //�����ǰ�ڵ���ֵ
		cur=cur->next;    //�ýڵ�ָ����һ���ڵ�
	}
	printf("NULL\n");
}
//β��
void SLTPushBack(SLTnode** pphead, SLTDataType x)
{
	SLTnode* newnode = BuySLTNode(x);

	if (*pphead == NULL)  //������
	{
		*pphead = newnode;
	}
	else
	{
		//�ҵ�β��
		SLTnode* tail = *pphead;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		tail->next = newnode;
	}
}