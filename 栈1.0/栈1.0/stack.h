#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef int STDataType;

typedef struct stack
{
	STDataType* a;
	int top;
	int capacity;
}ST;

//
void STInit(ST* ps);
//
void STDestroy(ST* ps);
//
void STPush(ST* ps, STDataType x);
//
STDataType STTop(ST* ps);
//
void STPop(ST* ps);
//
int STSize(ST* ps);
//
bool STEmpty(ST* ps);