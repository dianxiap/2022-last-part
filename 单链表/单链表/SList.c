#define _CRT_SECURE_NO_WARNINGS 1
#include "SList.h"

//申请一个新节点
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
//打印
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
	assert(pphead);
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
	assert(pphead);
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
	assert(pphead);
	SLTnode* newnode = BuySLTNode(x);
	newnode->next = *pphead;
	*pphead = newnode;
}
//头删
void SLTPopFront(SLTnode** pphead)
{
	assert(pphead);
	//1.检查是否为空
	assert(*pphead);
	SLTnode* first = *pphead;
	*pphead = first->next;
	free(first);
	first = NULL;
}
//查找
SLTnode* SLTFind(SLTnode* phead, SLTDataType)
{
	SLTnode* cur = phead;
	while (cur)
	{
		if (cur->data == x)  //找到了
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL; //没找到
}
//在pos之前插入
void SLTInsert(SLTnode** pphead, SLTnode* pos, SLTDataType x)
{
	assert(pos);  //pos这个节点存在
	assert(pphead);  //正确传值，不能为空
	if (pos == *pphead)  //pos在第一个节点处
	{
		SLTPushFront(pphead, x); //复用头插函数
	}
	else
	{
		//找到pos的前一个位置
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
//删除pos之前的节点
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
		//找到pos的前一个位置
		SLTnode* prev = *pphead;
		while (prev->next != pos)
		{
			prev = prev->next;
		}
		prev->next = pos->next;  //覆盖掉pos
		free(pos);
	}
}
//在pos之后插入
void SLTInsertAftter(SLTnode* pos, SLTDataType x)
{
	assert(pos);
	SLTnode* newnode = BuySLTNode(x);
	newnode->next = pos->next;
	pos->next = newnode;
}
//删除pos之后的节点
void SLTEraseAfter(SLTnode* pos)
{
	assert(pos);
	assert(pos->next);  //保证pos之后有节点
	SLTnode* del = pos->next;
	pos->next = del->next;  //覆盖以删除
	free(del);
	del = NULL;
}