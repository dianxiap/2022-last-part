#pragma once
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

typedef int SLDataType;  //������int��double���ṹ�壬����Ҫ����
#define INIT_CAPACITY 4  //��ʼ����СΪ4

typedef struct Seqlist
{
	SLDataType* a;   //ָ�������ݵ�ÿһ���ڴ�ռ�
	int size;        //��Ч���ݸ���
	int capacity;    //�ռ�����
}SL;

//��ʼ��
void SLInit(SL* pc);
//����
void SLDestory(SL* pc);
//��ӡ
void SLPrint(SL* pc);
//β��
void SLPushBack(SL* pc,SLDataType x);
//βɾ
void SLPopBakc(SL* pc);
//ͷ��
void SLPushFront(SL* pc);
//ͷɾ
void SLPopFront(SL* pc);