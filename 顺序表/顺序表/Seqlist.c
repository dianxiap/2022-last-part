#define _CRT_SECURE_NO_WARNINGS 1
#include "Seqlist.h"

void SLInit(SL* pc)
{
	//1.ǿ��ת������ 2.��������ֽڣ�sizeof(SLDataType) * INIT_CAPACITY
	pc->a = (SLDataType*)malloc(sizeof(SLDataType) * INIT_CAPACITY);  //�տ�ʼ����4��
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
	pc->a = NULL;  //�ǵ��ÿ�
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
	//����Ƿ�����
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
	//�����ļ��
	assert(pc->size > 0);
	
	//����ļ��
	if (pc->size == 0)
		return;
	pc->size--;
}