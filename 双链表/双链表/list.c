#define _CRT_SECURE_NO_WARNINGS 1
#include "list.h"

//创建节点
listnode* Buylistnode(LTDataType x)
{
	listnode* node = (listnode*)malloc(sizeof(listnode));

	if ((node == NULL))
	{
		perror("malloc");
		return NULL;
	}
	node->next = NULL;
	node->prev = NULL;
	node->data = x;
	return node;
}

//双链表初始化
listnode* init()
{
	listnode* phead = Buylistnode(-1);
	//自己指向自己
	phead->next = phead;
	phead->prev = phead;
	return phead;
}
//双向链表的打印
void listprint(listnode* phead)
{
	//phead不能为空，至少有哨兵卫的头节点
	assert(phead);
	printf("<=head=>");
	//从哨兵卫头节点下一个节点开始打印
	listnode* cur = phead->next;
	while (cur != phead)
	{
		printf("%d<=>",cur->next);
		cur = cur->next;
	}
	printf("\n");
}
//双向链表的尾插
void listpushback(listnode* phead, LTDataType x)
{
	assert(phead);
	//头节点指向的上一个节点就是尾节点
	listnode* newnode = Buylistnode(x);
	listnode* tail = phead->prev;

	tail->next = newnode;
	newnode->prev = tail;

	newnode->next = phead;
	phead->prev = newnode;
}
//判断是否只有一个头节点
bool ltempty(listnode* phead)
{
	assert(phead);
	return phead->next == phead;
}
//双向链表的尾删
void listpopback(listnode* phead)
{
	assert(phead);
	assert(!ltempty(phead));

	listnode* tail = phead->prev;
	listnode* tailprev = tail->prev;

	tailprev->next = phead;
	phead->prev = tailprev;

	free(tail);
	tail = NULL;
}
//双向链表的头插
void listpushfront(listnode* phead, LTDataType x)
{
	assert(phead);

	listnode* newnode = Buylistnode(x);
	listnode* first = phead->next;

	phead->next = newnode;
	newnode->prev = phead;

	newnode->next = first;
	first->prev = newnode;
}
//双向链表的头删
void listpopfront(listnode* phead)
{
	assert(phead);
	assert(!ltempty(phead));

	listnode* first = phead->next;
	listnode* firstnext = first->next;

	firstnext->prev = phead;
	phead->next = firstnext;

	free(first);
	first = NULL;
}
//双向链表查找
listnode* listfind(listnode* phead, LTDataType x)
{

}

//双向链表pos位置前面插入
void listinsert(listnode* pos, LTDataType x)
{
	assert(pos);
	listnode* prev = pos->prev;
	listnode* newnode = Buylistnode(x);

	prev->next = newnode;
	newnode->prev = prev;

	newnode->next = pos;
	pos->prev = newnode;
}

//双向链表删除pos处的节点
void listerase(listnode* pos)
{
	assert(pos);
	listnode* prev = pos->prev;
	listnode* next = pos->next;

	prev->next = next;
	next->prev = prev;

	free(pos);
	pos = NULL;
}