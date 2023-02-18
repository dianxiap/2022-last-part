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

//�˵���Ϣ
typedef struct PeoInfo
{
	char name[NAME_MAX];  //����
	int age;              //����
	char sex[SEX_MAX];    //�Ա�
	char addr[ADDR_MAX];  //סַ
	char tele[TELE_MAX];  //�绰����
}PeoInfo;

typedef struct Contact
{
	PeoInfo* data; //ָ�����˵���Ϣ�Ŀռ�
	int sz;        //��ǰ�Ѿ��ŵ���Ϣ�ĸ���
	int capacity;  //��ǰͨѶ¼���������
}Contact;

//��ʼ��ͨѶ¼
void InitContact(Contact* pc);

//����ͨѶ¼
void DestroyContact(Contact* pc);

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

//����ͨѶ¼�е���Ϣ���ļ���
void SaveContact(Contact* pc);

//�����ļ���Ϣ��ͨѶ¼
void LoadContact(Contact* pc);

