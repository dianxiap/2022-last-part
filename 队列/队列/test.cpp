#define _CRT_SECURE_NO_WARNINGS 1
#include "queue.h"

int main()
{
	Queue p;
	QueueInit(&p);
	QueuePush(&p, 1);
	QueuePush(&p, 2);
	QueuePush(&p, 3);
	QueuePush(&p, 4);
	QueuePush(&p, 5);
	int a=QueueFront(&p);
	printf("%d\n", a);
	QueuePop(&p);
	a = QueueFront(&p);
	printf("%d\n", a);
}