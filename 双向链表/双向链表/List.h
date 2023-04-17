#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

typedef int LTDataType;

typedef struct ListNode
{
	struct ListNode* next;
	struct ListNode* prev;
	LTDataType x;
}LTNode;

LTNode* LTInit();
void LTDestroy(LTNode* phead);
void LTPrint(LTNode* phead);
bool LTEmpty(LTNode* phead);

void LTPushBack(LTNode* phead, LTDataType x);
void LTPopBack(LTNode* phead);

void LTPushFront(LTNode* pehad, LTDataType x);
void LTPopFront(LTNode* phead);

LTNode* LTFind(LTNode* phead, LTDataType x);
void LTInsert(LTNode* pos, LTDataType x);
void LTErase(LTNode* pos);

