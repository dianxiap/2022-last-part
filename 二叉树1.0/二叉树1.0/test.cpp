#define _CRT_SECURE_NO_WARNINGS 1
#include "Binary.h"
#include "queue.h"

int main()
{
	BTNode* node=CreatTree();
	//PreOrder(node);
	//InOrder(node);
	PostOrder(node);
}