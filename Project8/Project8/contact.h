#pragma once

#include <stdio.h>
#include <string.h>
#include <assert.h>


#define MAX 100
#define NAME_MAX 20
#define SEX_MAX 5
#define ADDR_MAX 30
#define TELE_MAX 12

//人的信息
typedef struct PeoInfo
{
	char name[NAME_MAX];
	int age;
	char sex[SEX_MAX];
	char addr[ADDR_MAX];
	char tele[TELE_MAX];
}PeoInfo;


typedef struct Contact
{
	PeoInfo data[MAX];//存放人的信息的
	int sz;//当前已经放的信息的个数
}Contact;

//初始化通讯录
void InitContact(Contact* pc);

//增加联系人
void AddContact(Contact* pc);

//删除指定联系人
void DelContact(Contact* pc);

//显示通讯录中的信息
void ShowContact(const Contact* pc);

//查找指定联系人
void SearchContact(const Contact* pc);

//修改指定联系人
void ModifyContact(Contact* pc);

//按名字排序通讯录
int cmp(const void* s1, const void* s2);