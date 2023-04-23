#define _CRT_SECURE_NO_WARNINGS 1
#include "Slist.h"

int main()
{
	Node* p=NULL;
	SLTPushBack(&p, 1);
	SLTPushBack(&p, 2);
	SLTPushBack(&p, 3);
	SLTPushBack(&p, 4);
	SLTPushBack(&p, 5);
	SLTInsert(&p, p, 7);
	SLPrint(p);

}