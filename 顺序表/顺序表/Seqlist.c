#define _CRT_SECURE_NO_WARNINGS 1
#include "Seqlist.h"

void SLInit(SL* pc)
{
	assert(pc);
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
	assert(pc);
	free(pc->a);
	pc->a = NULL;  //记得置空
	pc->capacity = pc->size = 0;
}

void SLPrint(SL* pc)
{
	assert(pc);
	for (int i = 0; i < pc->size; i++)
	{
		printf("%d", pc->a[i]);
	}
	printf("\n");
}
void SLPushBack(SL* pc, SLDataType x)
{
	//assert(pc);
	////检查是否扩容
	//if (pc->size == pc->capacity)
	//{
	//	//有可能异地扩容，再新定义一个指针
	//	SLDataType* tmp = (SLDataType*)realloc(pc->a, sizeof(SLDataType) * pc->capacity * 2);
	//	if (tmp == NULL)
	//	{
	//		printf("relloc");
	//		return;
	//	}
	//	pc->a = tmp;  
	//	pc->capacity *= 2;
	//}
	/*SLCheckCapacity(pc);
	pc->a[pc->size++] = x;*/
	SLInsert(pc, pc->size, x);
}

void SLCheckCapacity(SL* pc)
{
	assert(pc);
	//检查是否扩容
	if (pc->size == pc->capacity)
	{
		//有可能异地扩容，再新定义一个指针
		SLDataType* tmp = (SLDataType*)realloc(pc->a, sizeof(SLDataType) * pc->capacity * 2);
		if (tmp == NULL)
		{
			printf("relloc");
			return;
		}
		pc->a = tmp;
		pc->capacity *= 2;
	}
}

void SLPopBakc(SL* pc)
{
	//assert(pc);
	////暴力的检查
	//assert(pc->size > 0);
	//
	////温柔的检查
	//if (pc->size == 0)
	//	return;
	//pc->size--;
	SLErase(pc, pc->size - 1);
}

void SLPushFront(SL* pc, SLDataType x)
{
	//assert(pc);
	//SLCheckCapacity(pc);
	//int end = pc->size - 1;  
	//while (end >= 0)
	//{
	//	//从最后一位开始，整体把数据后移一位
	//	pc->a[end + 1] = pc->a[end];
	//	--end;
	//}
	//pc->a[0] = x;
	//pc->size++;
	SLInsert(pc, 0, x);
}
//头删
void SLPopFront(SL* pc)
{
	//assert(pc);
	//assert(pc->size > 0); //保证有数据
	//int begin = 1;
	//while (begin < pc->size)
	//{
	//	pc->a[begin - 1] = pc->a[begin];
	//}
	//pc -> size--;
	SLErase(pc, 0);
}
//查找
int SLFind(SL* pc, SLDataType x)
{
	assert(pc);
	for (int i = 0; i < pc->size; i++)
	{
		if (pc->a[i] == x)
		{
			return i;
		}
	}
	return -1;
}

//任意位置插入
void SLInsert(SL* pc, int pos, SLDataType x)
{
	assert(pc);
	assert(pos >= 0 && pos <= pc->size);
	SLCheckCapacity(pc);
	int end = pc->size - 1;
	while (end >= pos)
	{
		pc->a[end + 1] = pc->a[end];
		end--;
	}
	pc->a[pos] = x;
	pc->size++;
}

//任意位置删除
void SLErase(SL* pc, int pos)
{
	assert(pc);
	assert(pc >= 0 && pos < pc->size);  //size指向当前数据的下一位，还没有存放数据，所以没东西可删，要注意与任意位置插入的代码区分

	int begin = pos + 1;
	while (begin < pc->size)
	{
		pc->a[begin - 1] = pc->a[begin];
		begin++;
	}
	pc->size--;
}
