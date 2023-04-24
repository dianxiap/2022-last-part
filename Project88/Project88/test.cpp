#define _CRT_SECURE_NO_WARNINGS 1
#include "SL.h"

int main()
{
	Node* p =SLInit();
	SLPushBack(p, 1);
	SLPushBack(p, 2);
	SLPushBack(p, 3);
	SLPushBack(p, 4);
	SLPushBack(p, 5);
	SLPrint(p);
	SLPushFront(p, 7);
	SLPopFront(p);
	SLPopFront(p);
	SLPopFront(p);
	SLPopFront(p);
	SLPopFront(p);
	SLPopFront(p);

	SLPrint(p);

}