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

//创建节点
listnode* Buylistnode(LTDataType x);
//双链表初始化
listnode* init();
//双向链表的打印
void listprint(listnode* phead);
//双向链表的尾插
void listpushback(listnode* phead, LTDataType x);
//双向链表的尾删
void listpopback(listnode* phead);
//双向链表的头插
void listpushfront(listnode* phead, LTDataType x);
//双向链表的头删
void listpopfront(listnode* phead);
//双向链表查找
listnode* listfind(listnode* phead, LTDataType x);
//双向链表pos位置前面插入
void listinsert(listnode* pos, LTDataType x);
//双向链表删除pos处的节点
void listerase(listnode* pos);