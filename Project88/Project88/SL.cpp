#define _CRT_SECURE_NO_WARNINGS 1
#include "SL.h"

// 创建一个节点
Node* BuyNode(SLDataType x)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	if (newNode == NULL)
	{
		perror("malloc fail");
		return NULL;
	}
	newNode->data = x;
	newNode->next = NULL;
	newNode->prev = NULL;
	return newNode;
}
//
Node* SLInit()
{
	Node* cur = BuyNode(-1);
	cur->prev = cur;
	cur->next = cur;
	return cur;
}
//
void SLPrint(Node* ps)
{
	assert(ps);
	printf("<=head=>");
	Node* cur = ps->next;
	while (cur != ps)
	{
		printf("%d<=>", cur->data);
		cur = cur->next;
	}
	printf("\n");

}
// 
void SLPushBack(Node* ps, SLDataType x)
{
	assert(ps);
	Node* newNode = BuyNode(x);
	Node* tail = ps->prev;
	
	tail->next = newNode;
	newNode->prev = tail;

	newNode->next = ps;
	ps->prev = newNode;
}

bool lempty(Node* ps)
{
	assert(ps);
	return ps->next == ps;
}
//
void SLPopBack(Node* ps)
{
	assert(ps);
	assert(!lempty(ps));

	Node* tail = ps->prev;
	Node* prev = tail->prev;

	prev->next = ps;
	ps->prev = prev;

	free(tail);
	tail = NULL;

}
//
void SLPushFront(Node* ps, SLDataType x)
{
	assert(ps);
	Node* newNode = BuyNode(x);
	Node* first = ps->next;

	newNode->next = first;
	first->prev = newNode;
	newNode->prev = ps;
	ps->next = newNode;

}
//
void SLPopFront(Node* ps)
{
	assert(ps);
	assert(!lempty(ps));

	Node* first = ps->next;
	Node* next = first->next;

	ps->next = next;
	next->prev = ps;
	free(first);
	first = NULL;

}
//
Node* SLFind(Node* ps, SLDataType x)
{
	assert(ps);
	assert(!lempty(ps));
	Node* cur = ps->next;
	while (cur!=ps->next)
	{
		if (cur->data == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}
//
void SLDestroy(Node* ps)
{
	assert(ps);
	Node* cur = ps->next;
	while (cur != ps)
	{
		Node* next = cur->next;
		free(cur);
		cur = next;
	}
	free(ps);
	ps = NULL;
}
//
void SLInsert(Node* ps, Node* pos, SLDataType x)
{
	assert(ps);
	Node* prev = pos->prev;
	Node* newNode = BuyNode(x);

	newNode->next = pos;
	pos->prev = newNode;

	newNode->prev = prev;
	prev->next = newNode;

}
//
void SLErase(Node* ps, Node* pos)
{
	assert(ps);
	Node* prev = pos->prev;
	Node* next = pos->next;
	prev->next = next;
	next->prev = prev;

	free(pos);
	pos = NULL;
}