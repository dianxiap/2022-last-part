#pragma once

#include <stdio.h>
#include <string.h>
#include <assert.h>


#define MAX 100
#define NAME_MAX 20
#define SEX_MAX 5
#define ADDR_MAX 30
#define TELE_MAX 12

//�˵���Ϣ
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
	PeoInfo data[MAX];//����˵���Ϣ��
	int sz;//��ǰ�Ѿ��ŵ���Ϣ�ĸ���
}Contact;

//��ʼ��ͨѶ¼
void InitContact(Contact* pc);

//������ϵ��
void AddContact(Contact* pc);

//ɾ��ָ����ϵ��
void DelContact(Contact* pc);

//��ʾͨѶ¼�е���Ϣ
void ShowContact(const Contact* pc);

//����ָ����ϵ��
void SearchContact(const Contact* pc);

//�޸�ָ����ϵ��
void ModifyContact(Contact* pc);

//����������ͨѶ¼
int cmp(const void* s1, const void* s2);