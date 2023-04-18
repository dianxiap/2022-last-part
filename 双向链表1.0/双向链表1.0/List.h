#pragma once
#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>

typedef int LTDataType;

typedef struct ListNode
{
	struct ListNode* prev;
	struct ListNode* next;

	LTDataType data;
}LTNode;