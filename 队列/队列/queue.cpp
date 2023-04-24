#define _CRT_SECURE_NO_WARNINGS 1
#include "queue.h"


void QueueInit(Queue* ps)
{
	assert(ps);
	ps->head = ps->tail = NULL;
	ps->size = 0;
}
void QueueDestroy(Queue* ps)
{
	assert(ps);
	QNode* cur = ps->head;
	while (cur)
	{
		QNode* next = cur->next;
		free(cur);
		cur = next;
	}
	ps->head = ps->tail = NULL;
	ps->size = 0;
}
void QueuePush(Queue* ps, QDataType x)
{
	assert(ps);
	QNode* newNode = (QNode*)malloc(sizeof(QNode));
	if (newNode == NULL)
	{
		perror("fail malloc");
		return;
	}
	newNode->data = x;
	newNode->next = NULL;

	if (ps->head == NULL)
	{
		assert(ps->tail == NULL);
		ps->head = ps->tail = newNode;
	}
	else
	{
		ps->tail->next = newNode;
		ps->tail = newNode;
	}
	ps->size++;
}
void QueuePop(Queue* ps)
{
	assert(ps);
	if (ps->head->next == NULL)
	{
		free(ps->head);
		ps->head = ps->tail = NULL;
	}
	else {
		QNode* next = ps->head->next;
		free(ps->head);
		ps->head = next;
	}
	ps->size--;
}
int QueueSize(Queue* ps)
{
	assert(ps);

	return ps->size;
}
bool QueueEmpty(Queue* ps)
{
	assert(ps);
	return ps->size == 0;
}
QDataType QueueFront(Queue* ps)
{
	assert(ps);
	assert(!QueueEmpty(ps));
	return ps->head->data;
}
QDataType QueueBack(Queue* ps)
{
	assert(ps);
	assert(!QueueEmpty(ps));
	return ps->tail->data;
}