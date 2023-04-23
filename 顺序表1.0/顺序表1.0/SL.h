#pragma once
#pragma once
#include <iostream>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

#define MAX_CAPACITY 4
typedef int SLDataType;

typedef struct SeqList
{
	SLDataType* a;
	int size;
	int capacity;
}SL;

// ÔöÉ¾²é¸Ä
void SLInit(SL* ps);
void SLDestroy(SL* ps);
void SLPrint(SL* ps);
void SLCheckCapacity(SL* ps);
void SLPushBack(SL* ps, SLDataType x);
void SLPopBack(SL* ps);
void SLPushFront(SL* ps, SLDataType x);
void SLPopFront(SL* ps);
void SLInsert(SL* ps, SLDataType x);
void SLErase(SL* ps);
void SLFind(SL* ps);