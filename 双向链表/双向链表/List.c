#define _CRT_SECURE_NO_WARNINGS 1
#include "List.h"

LTNode* BuyNode(LTDataType x)
{
	LTNode* node = (LTNode*)malloc(sizeof(LTNode));
	if (node == NULL)
	{
		perror("malloc fail");
		return NULL;
	}
	node->next = NULL;
	node->prev = NULL;
	node->x = x;
}
LTNode* LTInit()
{
	LTNode* phead = BuyNode(-1);
	phead->next = phead;
	phead->prev = phead;
}

void LTDestroy(LTNode* phead)
{
	assert(phead);
	LTNode* cur = phead->next;
	while (cur != phead)
	{
		LTNode* next = cur->next;
		free(cur);
		cur = next;
	}
	free(phead);
}
void LTPrint(LTNode* phead)
{
	assert(phead);

	printf("<=head=>");
	LTNode* cur = phead->next;
	while (cur != phead)
	{
		printf("%d<=>", cur->x);
		cur = cur->next;
	}
	printf("\n");
}
bool LTEmpty(LTNode* phead)
{
	assert(phead);
	return phead->next == phead;
}

void LTPushBack(LTNode* phead, LTDataType x)
{
	assert(phead);
	LTNode* newnode = BuyNode(x);
	LTNode* tail = phead->prev;

	tail->next = newnode;
	newnode->prev = tail;
	newnode->next = phead;
	phead->prev = newnode;
}
void LTPopBack(LTNode* phead);

void LTPushFront(LTNode* pehad, LTDataType x);
void LTPopFront(LTNode* phead);

LTNode* LTFind(LTNode* phead, LTDataType x);
void LTInsert(LTNode* pos, LTDataType x);
void LTErase(LTNode* pos);