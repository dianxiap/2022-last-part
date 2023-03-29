#define _CRT_SECURE_NO_WARNINGS 1
#include "queue.h"

void QueueInit(Queue* q)
{
	assert(q);
	q->head = q->tail = NULL;
	q->size = 0;
}
void QueuePush(Queue* q, QDatatype x)
{
	QNode* newnode = (QNode*)malloc(sizeof(QNode));
	if (newnode == NULL)
	{
		perror("malloc fail");
		return;
	}
	newnode->data = x;
	newnode->next = NULL;

	//队列为空
	if (q->head == NULL)
	{
		assert(q->tail == NULL);
		q->head = q->tail = newnode;
	}
	//队列不空
	else
	{
		q->tail->next = newnode;
		q->tail = newnode;
	}
	q->size++;
}
void QueuePop(Queue* q)
{
	assert(q);
	assert(q->head != NULL);
	//队中只有一个元素
	if (q->head->next == NULL)
	{
		free(q->head);
		q->head = q->tail = NULL;
	}
	else
	{
		QNode* next = q->head->next;
		free(q->head);
		q->head = next;
	}
	q->size--;
}
QDatatype QueueFront(Queue* q)
{
	assert(q);
	assert(!QueueEmpty(q));
	return q->head->data;
}
QDatatype QueueBack(Queue* q)
{
	assert(q);
	assert(!QueueEmpty(q));
	return q->tail->data;
}
int Queuesize(Queue* q)
{

	assert(q);
	return q->size;
}
int QueueEmpty(Queue* q)
{
	assert(q);
	return q->size == 0;
}
void QueueDestroy(Queue* q)
{
	assert(q);
	QNode* cur = q->head;
	while (cur)
	{
		QNode* next = cur->next;
		free(cur);
		cur = next;
	}
	q->head = q->tail = NULL;
	q->size = 0;
}
void BinaryTreeLevelOrder(QNode* root)
{
	Queue q;
	QueueInit(&q);

	if (root)
		QueuePush(&q, root);
	while (!QueueEmpty(&q))
	{
		QNode* front = QueueFront(&q);
		printf("%d ", front->data);

		QueuePop(&q);

		if()
	}
}