#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "Binary.h"

typedef BTNode* QDataType;

typedef struct QNode
{
	struct QNode* next;
	QDataType data;
}QNode;

typedef struct Queue
{
	QNode* head;
	QNode* tail;
	int size;
}Queue;

void QueueInit(Queue* ps);
void QueueDestroy(Queue* ps);
void QueuePush(Queue* ps, QDataType x);
void QueuePop(Queue* ps);
int QueueSize(Queue* ps);
bool QueueEmpty(Queue* ps);
QDataType QueueFront(Queue* ps);
QDataType QueueBack(Queue* ps);