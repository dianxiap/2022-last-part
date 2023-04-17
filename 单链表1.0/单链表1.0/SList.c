#define _CRT_SECURE_NO_WARNINGS 1
#include "SList.h"

// ��ӡ
void SLTPrint(SLTNode* phead)
{
	SLTNode* cur = phead;

	while (cur)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL");
}

SLTNode* BuyNode(SLTDataType x)
{
	SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));
	if (newnode == NULL)
	{
		perror("malloc fail");
		return NULL;
	}
	newnode->data = x;
	newnode->next = NULL;
	return newnode;
}
// β��
void SLTPushBack(SLTNode** pphead, SLTDataType x)
{
	assert(pphead);
	SLTNode* newnode = BuyNode(x);

	if (*pphead == NULL)
	{
		*pphead = newnode;
	}
	else
	{
		SLTNode* tail = *pphead;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		tail->next = newnode;
	}
}
// ͷ��
void SLTPushFront(SLTNode** pphead, SLTDataType x)
{
	assert(pphead);
	SLTNode* newnode = BuyNode(x);

	newnode->next = *pphead;
	*pphead = newnode;
}
// βɾ
void SLTPopBack(SLTNode** pphead)
{
	assert(pphead);
	assert(*pphead);

	if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}
	else
	{
		SLTNode* tail = *pphead;
		while (tail->next->next != NULL)
		{
			tail = tail->next;
		}
		free(tail->next);
		tail->next = NULL;
	}

}
// ͷɾ
void SLTPopFront(SLTNode** pphead)
{
	assert(pphead);
	assert(*pphead);

	SLTNode* first = *pphead;
	*pphead = first->next;
	free(first);
	first = NULL;
}
// ����
SLTNode* SLTFind(SLTNode* phead, SLTDataType x)
{
	SLTNode* cur = phead;
	while (cur)
	{
		if (cur->data == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}
// posǰ����
void SLTInerst(SLTNode** pphead, SLTNode* pos, SLTDataType x)
{
	assert(pos);
	assert(pphead);

	if (pos == *pphead)
	{
		SLTPushFront(pphead, x);
	}
	else
	{
		SLTNode* cur = *pphead;
		while (cur->next != pos)
		{
			cur = cur->next;
		}
		SLTNode* newnode = BuyNode(x);
		cur->next = newnode;
		newnode->next = pos;

	}
}
// posǰɾ��
void SLTErase(SLTNode** pphead, SLTNode* pos)
{
	assert(pos);
	assert(pphead);

	if (*pphead == NULL)
	{
		SLTPopFront(pphead);
	}
	else
	{
		SLTNode* cur = *pphead;
		while (cur->next != pos)
		{
			cur = cur->next;
		}
		cur ->next= pos->next;
		free(pos);
	}
}
// pos�����
void SLTInsertAf(SLTNode* pos, SLTDataType x)
{
	assert(pos);
	SLTNode* newnode = BuyNode(x);
	newnode->next = pos->next;
	pos->next = newnode;

}
// pos��ɾ��
void SLTEraseAf(SLTNode* pos)
{
	assert(pos);
	assert(pos->next);

	SLTNode* cur = pos->next;
	pos->next = cur->next;
	free(cur);
	cur = NULL;
}
