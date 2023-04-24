#pragma once
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>

typedef int SLDataType;

typedef struct Node
{
	SLDataType data;
	struct Node* prev;
	struct Node* next;
}Node;

// 创建一个节点
Node* BuyNode(SLDataType x);
//
Node* SLInit();
//
void SLPrint(Node* ps);
// 
void SLPushBack(Node* ps, SLDataType x);
//
void SLPopBack(Node* ps);
//
void SLPushFront(Node* ps, SLDataType x);
//
void SLPopFront(Node* ps);
//
Node* SLFind(Node* ps, SLDataType x);
//
void SLDestroy(Node* ps);
//
void SLInsert(Node* ps, Node* pos, SLDataType x);
//
void SLErase(Node* ps, Node* pos);

