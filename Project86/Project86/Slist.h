#pragma once
#include <iostream>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

typedef int SLTDataType;

typedef struct Node
{
	SLTDataType a;
	struct Node* next;
}Node;

// 链表初始化
Node* BuyNode(SLTDataType x);
// 打印
void SLPrint(Node* ps);
// 链表查找
Node* SLTFint(SLTDataType x);
// 链表销毁
void SLTDestroy(Node* ps);
// 链表尾插
void SLTPushBack(Node** ps,SLTDataType x);
// 链表尾删
void SLTPopBack(Node** ps);
// 链表头插
void SLTPushFront(Node** ps, SLTDataType x );
// 链表头删
void SLTPopBack(Node** ps);
// 链表pos前插入
void SLTInsert(Node** ps, Node* pos, SLTDataType x);
// 链表pos位置前删除
void SLTErase(Node** ps, Node* pos);
// 链表pos位置后插入
void SLTInsert(Node** ps, Node* pos, SLTDataType x);
// 链表pos位置后删除
void SLTInsert(Node** ps, Node* pos);




