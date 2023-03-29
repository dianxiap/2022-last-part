#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>


typedef int QDatatype;

typedef struct QueueNode
{
	struct QNode* next;
	QDatatype data;
}QNode;

typedef struct Queue
{
	QNode* head;
	QNode* tail;
	int size;
}Queue;

void QueueInit(Queue* q);
void QueuePush(Queue* q, QDatatype x);
void QueuePop(Queue* q);
QDatatype QueueFront(Queue* q);
QDatatype QueueBack(Queue* q);
int Queuesize(Queue* q);
int QueueEmpty(Queue* q);
void QueueDestroy(Queue* q);
void BinaryTreeLevelOrder(QNode* root);