#pragma once
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>

#define MAX 100
#define NAME_MAX 20
#define SEX_MAX 5
#define ADDR_MAX 30
#define TELE_MAX 12

#define DEFAULT_SZ 3
#define INC_SZ 2

//人的信息
typedef struct PeoInfo
{
	char name[NAME_MAX];  //姓名
	int age;              //年龄
	char sex[SEX_MAX];    //性别
	char addr[ADDR_MAX];  //住址
	char tele[TELE_MAX];  //电话号码
}PeoInfo;

typedef struct Contact
{
	PeoInfo* data; //指向存放人的信息的空间
	int sz;        //当前已经放的信息的个数
	int capacity;  //当前通讯录的最大容量
}Contact;

//初始化通讯录
void InitContact(Contact* pc);

//销毁通讯录
void DestroyContact(Contact* pc);

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

//保存通讯录中的信息到文件中
void SaveContact(Contact* pc);

//加载文件信息到通讯录
void LoadContact(Contact* pc);

