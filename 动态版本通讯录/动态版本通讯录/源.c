#define _CRT_SECURE_NO_WARNINGS 1
#include "contatc.h"

//初始化通讯录
void InitContact(Contact* pc)
{
	assert(pc);
	pc->sz = 0;
	PeoInfo* ptr = (PeoInfo*)calloc(DEFAULT_SZ, sizeof(PeoInfo));
	if (ptr == NULL)
	{
		perror("InitContact::calloc");
		return;
	}
	pc->data = ptr;
	pc->capacity = DEFAULT_SZ;

	//加载文件信息到通讯录
	LoadContact(pc);
}

//销毁通讯录
void DestroyContact(Contact* pc)
{
	free(pc->data);
	pc->data = NULL;
	pc->capacity = 0;
	pc->sz = 0;
	pc = NULL;
}


//检查当前通讯录的容量
void check_capacity(Contact* pc)
{
	if (pc->sz == pc->capacity)
	{
		//增加容量
		PeoInfo* ptr = (PeoInfo*)realloc(pc->data, (pc->capacity + INC_SZ) * sizeof(PeoInfo));
		if (ptr == NULL)
		{
			perror("check_capacity::realloc");
			return;
		}
		pc->data = ptr;
		pc->capacity += INC_SZ;
		printf("增容成功\n");
	}
}


//增加联系人
void AddContact(Contact* pc)
{
	assert(pc);
	check_capacity(pc);

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


//显示通讯录中的信息
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

//根据名字查找信息
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

//删除指定联系人
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

//查找指定联系人
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

//修改指定联系人
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

//保存通讯录中的信息到文件中
void SaveContact(Contact* pc)
{
	//写数据
	//1, 打开文件
	FILE* pf = fopen("contact.txt", "wb");
	if (NULL == pf)
	{
		perror("SaveContact");
	}
	else
	{
		//写数据
		int i = 0;
		for (i = 0; i < pc->sz; i++)
		{
			fwrite(pc->data + i, sizeof(PeoInfo), 1, pf);
		}
		fclose(pf);
		pf = NULL;
		printf("保存成功\n");
	}
}

//加载文件信息到通讯录
void LoadContact(Contact* pc)
{
	//读数据
	//1. 打开文件
	FILE* pf = fopen("contact.txt", "rb");
	if (pf == NULL)
	{
		perror("LoadContact");
	}
	else
	{
		//2. 读数据
		PeoInfo tmp = { 0 };
		int i = 0;
		while (fread(&tmp, sizeof(PeoInfo), 1, pf))
		{
			//增容
			check_capacity(pc);
			pc->data[i] = tmp;
			pc->sz++;
			i++;
		}
		fclose(pf);
		pf = NULL;
	}
}

