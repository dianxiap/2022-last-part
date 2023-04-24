#define _CRT_SECURE_NO_WARNINGS 1
#include "stack.h"

// 初始化
void STInit(ST* ps)
{
	assert(ps);
	ps->a = (STDataType*)malloc(sizeof(STDataType)*4);
	if (ps->a == NULL)
	{
		perror("malloc fail");
		return;
	}
	ps->capacity = 4;
	ps->top = 0;

}
// 销毁
void STDestroy(ST* ps)
{
	assert(ps);
	free(ps->a);
	ps->a = NULL;
	ps->capacity = 0;
	ps->top = 0;

}
// 插入
void STPush(ST* ps, STDataType x)
{
	assert(ps);
	if (ps->top == ps->capacity)
	{
		STDataType* tmp = (STDataType*)realloc(ps->a,
			sizeof(STDataType) * ps->capacity * 2);
		if (tmp == NULL)
		{
			perror("realloc fail");
			return;
		}
		ps->a = tmp;
		ps->capacity *= 2;
	}
	ps->a[ps->top++] = x;
}
//
bool STEmpty(ST* ps)
{
	assert(ps);
	return ps->top == 0;
}

//
STDataType STTop(ST* ps)
{
	assert(ps);
	assert(!STEmpty(ps));
	return ps->a[ps->top - 1];
}
// 弹出
void STPop(ST* ps)
{
	assert(ps);
	assert(!STEmpty(ps));
	ps->top--;
}
//
int STSize(ST* ps)
{
	assert(ps);
	return ps->top;
}

