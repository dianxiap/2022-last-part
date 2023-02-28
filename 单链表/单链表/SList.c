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
	SLTnode* cur = phead;  //临时指针
	while (cur != NULL)   //不为空
	{
		printf("%d->", cur->data);  //输出当前节点存的值
		cur=cur->next;    //该节点指向下一个节点
	}
	printf("NULL\n");
}
//尾插
void SLTPushBack(SLTnode** pphead, SLTDataType x)
{
	SLTnode* newnode = BuySLTNode(x);

	if (*pphead == NULL)  //空链表
	{
		*pphead = newnode;
	}
	else
	{
		//找到尾部
		SLTnode* tail = *pphead;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		tail->next = newnode;
	}
}
//尾删
void SLTPopBack(SLTnode** pphead)
{
	//1.检查是否为空
	assert(*pphead);
	//2.只有一个节点
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
//头插
void SLTPushFront(SLTnode** pphead, SLTDataType x)
{
	SLTnode* newnode = BuySLTNode(x);
	newnode->next = *pphead;
	*pphead = newnode;
}
//头删
void SLTPopFront(SLTnode** pphead)
{
	//1.检查是否为空
	assert(*pphead);
	SLTnode* first = *pphead;
	*pphead = first->next;
	free(first);
	first = NULL;
}