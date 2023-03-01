#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int SLTDataType;

//定义节点
typedef struct SListNode
{
	SLTDataType data;   //存放数据
 	struct SListNade* next;  //指向下一个节点
}SLTnode;

//申请节点
SLTnode* BuySLTNode(SLTDataType x);
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
//查找
SLTnode* SLTFind(SLTnode* phead, SLTDataType);
//在pos之前插入
void SLTInsert(SLTnode** pphead, SLTnode* pos, SLTDataType x);
//删除pos之前的节点
voide SLTErase(SLTnode** pphead, SLTnode* pos);
//在pos之后插入
void SLTInsertAftter(SLTnode* pos, SLTDataType x);
//删除pos之后的节点
void SLTEraseAfter(SLTnode* pos);
