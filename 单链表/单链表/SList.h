#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int SLTDataType;


//链式结构存储每一个节点
typedef struct SListNode
{
	SLTDataType data;   //存放数据
 	struct SListNade* next;  //指向下一个节点
}SLTnode;

//打印
void SLTPrint(SLTnode* phead);
//尾插
void SLTPushBack(SLTnode** pphead, SLTDataType x);
//头插
void SLTPushFront(SLTnode** pphead, SLTDataType x);
//尾删
void SLTPopBack(SLTnode** pphead);
//头删
void SLTPopFront(SLTnode** pphead);

