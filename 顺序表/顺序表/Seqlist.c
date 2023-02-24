#define _CRT_SECURE_NO_WARNINGS 1
#include "Seqlist.h"

void SLInit(SL* pc)
{
	assert(pc);
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
	assert(pc);
	free(pc->a);
	pc->a = NULL;  //�ǵ��ÿ�
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
	////����Ƿ�����
	//if (pc->size == pc->capacity)
	//{
	//	//�п���������ݣ����¶���һ��ָ��
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
	//����Ƿ�����
	if (pc->size == pc->capacity)
	{
		//�п���������ݣ����¶���һ��ָ��
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
	////�����ļ��
	//assert(pc->size > 0);
	//
	////����ļ��
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
	//	//�����һλ��ʼ����������ݺ���һλ
	//	pc->a[end + 1] = pc->a[end];
	//	--end;
	//}
	//pc->a[0] = x;
	//pc->size++;
	SLInsert(pc, 0, x);
}
//ͷɾ
void SLPopFront(SL* pc)
{
	//assert(pc);
	//assert(pc->size > 0); //��֤������
	//int begin = 1;
	//while (begin < pc->size)
	//{
	//	pc->a[begin - 1] = pc->a[begin];
	//}
	//pc -> size--;
	SLErase(pc, 0);
}
//����
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

//����λ�ò���
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

//����λ��ɾ��
void SLErase(SL* pc, int pos)
{
	assert(pc);
	assert(pc >= 0 && pos < pc->size);  //sizeָ��ǰ���ݵ���һλ����û�д�����ݣ�����û������ɾ��Ҫע��������λ�ò���Ĵ�������

	int begin = pos + 1;
	while (begin < pc->size)
	{
		pc->a[begin - 1] = pc->a[begin];
		begin++;
	}
	pc->size--;
}
