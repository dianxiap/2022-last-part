#define _CRT_SECURE_NO_WARNINGS 1
#include "list.h"

//�����ڵ�
listnode* Buylistnode(LTDataType x)
{
	listnode* node = (listnode*)malloc(sizeof(listnode));

	if ((node == NULL))
	{
		perror("malloc");
		return NULL;
	}
	node->next = NULL;
	node->prev = NULL;
	node->data = x;
	return node;
}

//˫�����ʼ��
listnode* init()
{
	listnode* phead = Buylistnode(-1);
	//�Լ�ָ���Լ�
	phead->next = phead;
	phead->prev = phead;
	return phead;
}
//˫������Ĵ�ӡ
void listprint(listnode* phead)
{
	//phead����Ϊ�գ��������ڱ�����ͷ�ڵ�
	assert(phead);
	printf("<=head=>");
	//���ڱ���ͷ�ڵ���һ���ڵ㿪ʼ��ӡ
	listnode* cur = phead->next;
	while (cur != phead)
	{
		printf("%d<=>",cur->next);
		cur = cur->next;
	}
	printf("\n");
}
//˫�������β��
void listpushback(listnode* phead, LTDataType x)
{
	assert(phead);
	//ͷ�ڵ�ָ�����һ���ڵ����β�ڵ�
	listnode* newnode = Buylistnode(x);
	listnode* tail = phead->prev;

	tail->next = newnode;
	newnode->prev = tail;

	newnode->next = phead;
	phead->prev = newnode;
}
//�ж��Ƿ�ֻ��һ��ͷ�ڵ�
bool ltempty(listnode* phead)
{
	assert(phead);
	return phead->next == phead;
}
//˫�������βɾ
void listpopback(listnode* phead)
{
	assert(phead);
	assert(!ltempty(phead));

	listnode* tail = phead->prev;
	listnode* tailprev = tail->prev;

	tailprev->next = phead;
	phead->prev = tailprev;

	free(tail);
	tail = NULL;
}
//˫�������ͷ��
void listpushfront(listnode* phead, LTDataType x)
{
	assert(phead);

	listnode* newnode = Buylistnode(x);
	listnode* first = phead->next;

	phead->next = newnode;
	newnode->prev = phead;

	newnode->next = first;
	first->prev = newnode;
}
//˫�������ͷɾ
void listpopfront(listnode* phead)
{
	assert(phead);
	assert(!ltempty(phead));

	listnode* first = phead->next;
	listnode* firstnext = first->next;

	firstnext->prev = phead;
	phead->next = firstnext;

	free(first);
	first = NULL;
}
//˫���������
listnode* listfind(listnode* phead, LTDataType x)
{

}

//˫������posλ��ǰ�����
void listinsert(listnode* pos, LTDataType x)
{
	assert(pos);
	listnode* prev = pos->prev;
	listnode* newnode = Buylistnode(x);

	prev->next = newnode;
	newnode->prev = prev;

	newnode->next = pos;
	pos->prev = newnode;
}

//˫������ɾ��pos���Ľڵ�
void listerase(listnode* pos)
{
	assert(pos);
	listnode* prev = pos->prev;
	listnode* next = pos->next;

	prev->next = next;
	next->prev = prev;

	free(pos);
	pos = NULL;
}