#define _CRT_SECURE_NO_WARNINGS 1
#include "SList.h"

//����һ���½ڵ�
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
//��ӡ
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
	assert(pphead);
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
//βɾ
void SLTPopBack(SLTnode** pphead)
{
	assert(pphead);
	//1.����Ƿ�Ϊ��
	assert(*pphead);
	//2.ֻ��һ���ڵ�
	if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}
	else
	{
		SLTnode* tail = *pphead;
		while (tail->next->next != NULL)
		{
			tail = tail->next;
		}
		free(tail->next);
		tail->next = NULL;
	}
}
//ͷ��
void SLTPushFront(SLTnode** pphead, SLTDataType x)
{
	assert(pphead);
	SLTnode* newnode = BuySLTNode(x);
	newnode->next = *pphead;
	*pphead = newnode;
}
//ͷɾ
void SLTPopFront(SLTnode** pphead)
{
	assert(pphead);
	//1.����Ƿ�Ϊ��
	assert(*pphead);
	SLTnode* first = *pphead;
	*pphead = first->next;
	free(first);
	first = NULL;
}
//����
SLTnode* SLTFind(SLTnode* phead, SLTDataType)
{
	SLTnode* cur = phead;
	while (cur)
	{
		if (cur->data == x)  //�ҵ���
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL; //û�ҵ�
}
//��pos֮ǰ����
void SLTInsert(SLTnode** pphead, SLTnode* pos, SLTDataType x)
{
	assert(pos);  //pos����ڵ����
	assert(pphead);  //��ȷ��ֵ������Ϊ��
	if (pos == *pphead)  //pos�ڵ�һ���ڵ㴦
	{
		SLTPushFront(pphead, x); //����ͷ�庯��
	}
	else
	{
		//�ҵ�pos��ǰһ��λ��
		SLTnode* prev = *pphead;
		while (prev->next != pos)
		{
			prev = prev->next;
		}
		SLTnode* newnode = BuySLTNode(x);
		prev->next = newnode;
		newnode->next = pos;
	}
}
//ɾ��pos֮ǰ�Ľڵ�
voide SLTErase(SLTnode** pphead, SLTnode* pos)
{
	assert(pphead);
	assert(pos);
	if (*pphead == pos)
	{
		SLTPopFront(pphead);
	}
	else
	{
		//�ҵ�pos��ǰһ��λ��
		SLTnode* prev = *pphead;
		while (prev->next != pos)
		{
			prev = prev->next;
		}
		prev->next = pos->next;  //���ǵ�pos
		free(pos);
	}
}
//��pos֮�����
void SLTInsertAftter(SLTnode* pos, SLTDataType x)
{
	assert(pos);
	SLTnode* newnode = BuySLTNode(x);
	newnode->next = pos->next;
	pos->next = newnode;
}
//ɾ��pos֮��Ľڵ�
void SLTEraseAfter(SLTnode* pos)
{
	assert(pos);
	assert(pos->next);  //��֤pos֮���нڵ�
	SLTnode* del = pos->next;
	pos->next = del->next;  //������ɾ��
	free(del);
	del = NULL;
}