#define _CRT_SECURE_NO_WARNINGS 1
#include "Seqlist.h"

void SLInit(SL* pc)
{
	//1.强制转化类型 2.分配的是字节：sizeof(SLDataType) * INIT_CAPACITY
	pc->a = (SLDataType*)malloc(sizeof(SLDataType) * INIT_CAPACITY);  //刚开始分配4个
	if (pc->a == NULL)
	{
		perror("malloc");
		return;
	}
	pc->size = 0;
	pc->capacity = INIT_CAPACITY;
}

void SLDestory(SL* pc)
{
	free(pc->a);
	pc->a = NULL;  //记得置空
	pc->capacity = pc->size = 0;
}

void SLPrint(SL* pc)
{
	for (int i = 0; i < pc->size; i++)
	{
		printf("%d", pc->a[i]);
	}
	printf("\n");
}
void SLPushBack(SL* pc, SLDataType x)
{
	//检查是否扩容
	if (pc->size == pc->capacity)
	{
		SLDataType* tmp = (SLDataType*)realloc(pc->a, sizeof(SLDataType) * pc->capacity * 2);
		if (tmp == NULL)
		{
			printf("relloc");
			return;
		}
		pc->a = tmp;
		pc->capacity *= 2;
	}
	pc->a[pc->size++] = x;
}

void SLPopBakc(SL* pc)
{
	//暴力的检查
	assert(pc->size > 0);
	
	//温柔的检查
	if (pc->size == 0)
		return;
	pc->size--;
}