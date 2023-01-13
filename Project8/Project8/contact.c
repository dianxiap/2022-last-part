#define _CRT_SECURE_NO_WARNINGS 1
#include "contact.h"

void InitContact(Contact* pc)
{
	assert(pc);
	pc->sz = 0;
	memset(pc->data, 0, sizeof(pc->data));
}

void AddContact(Contact* pc)
{
	assert(pc);
	if (pc->sz == MAX)
	{
		printf("通讯录已满，无法添加\n");
		return;
	}
	//增加一个人的信息
	printf("请输入名字:>");
	scanf("%s", pc->data[pc->sz].name);
	printf("请输入年龄:>");
	scanf("%d", &(pc->data[pc->sz].age));
	printf("请输入性别:>");
	scanf("%s", pc->data[pc->sz].sex);
	printf("请输入地址:>");
	scanf("%s", pc->data[pc->sz].addr);
	printf("请输入电话:>");
	scanf("%s", pc->data[pc->sz].tele);

	pc->sz++;
}


void ShowContact(const Contact* pc)
{
	assert(pc);
	int i = 0;
	printf("%-20s\t%-4s\t%-5s\t%-20s\t%-12s\n", "名字", "年龄", "性别", "地址", "电话");
	for (i = 0; i < pc->sz; i++)
	{
		printf("%-20s\t%-4d\t%-5s\t%-20s\t%-12s\n", pc->data[i].name,
			pc->data[i].age,
			pc->data[i].sex,
			pc->data[i].addr,
			pc->data[i].tele);
	}
}


int FindByName(const Contact* pc, char name[])
{
	assert(pc);

	int i = 0;
	for (i = 0; i < pc->sz; i++)
	{
		if (strcmp(pc->data[i].name, name) == 0)
		{
			return i;
		}
	}
	return -1;
}

void DelContact(Contact* pc)
{
	assert(pc);

	char name[NAME_MAX] = { 0 };
	if (pc->sz == 0)
	{
		printf("通讯录为空，无法删除\n");
		return;
	}
	//删除
	//找到要删除的人
	printf("请输入要删除的人的名字:>");
	scanf("%s", name);
	int ret = FindByName(pc, name);
	if (-1 == ret)
	{
		printf("要删除的人不存在\n");
		return;
	}

	int i = 0;
	//删除
	for (i = ret; i < pc->sz - 1; i++)
	{
		pc->data[i] = pc->data[i + 1];
	}
	pc->sz--;
	printf("删除成功\n");
}

void SearchContact(const Contact* pc)
{
	assert(pc);
	char name[NAME_MAX] = { 0 };
	printf("请输入要查找人的名字:>");
	scanf("%s", name);
	int pos = FindByName(pc, name);
	if (-1 == pos)
	{
		printf("要查找的人不存在\n");
		return;
	}
	//打印信息
	printf("%-20s\t%-4s\t%-5s\t%-20s\t%-12s\n", "名字", "年龄", "性别", "地址", "电话");
	printf("%-20s\t%-4d\t%-5s\t%-20s\t%-12s\n", pc->data[pos].name,
		pc->data[pos].age,
		pc->data[pos].sex,
		pc->data[pos].addr,
		pc->data[pos].tele);
}


void ModifyContact(Contact* pc)
{
	assert(pc);
	char name[NAME_MAX] = { 0 };
	printf("请输入要修改人的名字:>");
	scanf("%s", name);
	int pos = FindByName(pc, name);
	if (-1 == pos)
	{
		printf("要修改的人不存在\n");
		return;
	}

	printf("请输入名字:>");
	scanf("%s", pc->data[pos].name);
	printf("请输入年龄:>");
	scanf("%d", &(pc->data[pos].age));
	printf("请输入性别:>");
	scanf("%s", pc->data[pos].sex);
	printf("请输入地址:>");
	scanf("%s", pc->data[pos].addr);
	printf("请输入电话:>");
	scanf("%s", pc->data[pos].tele);

	printf("修改完成\n");
}

//qsort
int cmp(const void* s1, const void* s2)
{
	assert(s1 && s2);
	return strcmp((char*)s1, (char*)s2);
}