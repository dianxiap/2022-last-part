#define _CRT_SECURE_NO_WARNINGS 1
#include "Slist.h"

// �����ʼ��
Node* BuyNode(SLTDataType x)
{
	Node* p = (Node*)malloc(sizeof(Node));
	if (p == NULL)
	{
		perror("malloc fail");
		return NULL;
	}
	p->a = x;
	p->next = NULL;
	return p;
}
// ��ӡ
void SLPrint(Node* ps)
{
	Node* cur = ps;
	while (cur)
	{
		printf("%d->", cur->a);
		cur = cur->next;
	}
	printf("NULL");
}
// �������
Node* SLTFint(Node* ps, SLTDataType x)
{
	Node* cur = ps;
	while (cur)
	{
		if(cur->a==x)
		{ 
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}
// ��������
void SLTDestroy(Node* ps)
{
	free(ps);
	ps = NULL;
}
// ����β��
void SLTPushBack(Node** ps, SLTDataType x)
{
	assert(ps);
	Node* newnode=BuyNode(x);

	if (*ps == NULL)
	{
		*ps = newnode;
	}
	else
	{
		Node* cur = *ps;
		while (cur->next!=NULL)
		{
			cur = cur->next;
		}
		cur->next = newnode;
	}
}
// ����βɾ
void SLTPopBack(Node** ps)
{
	assert(ps);
	assert(*ps);
	Node* cur = *ps;
	if ((*ps)->next == NULL)
	{
		free(*ps);
		*ps = NULL;
	}
	else
	{
		while (cur->next->next)
		{
			cur= cur->next;
		}
		free(cur->next);
		cur->next = NULL;
	}
}
// ����ͷ��
void SLTPushFront(Node** ps, SLTDataType x)
{
	assert(ps);
	Node* newNode = BuyNode(x);
	newNode->next = *ps;
	*ps = newNode;
}
// ����ͷɾ
void SLTPopFront(Node** ps)
{
	assert(ps);
	assert(*ps);
	Node* head = *ps;
	*ps = head->next;
	free(head);
	head = NULL;
}
// ����posǰ����
void SLTInsert(Node** ps, Node* pos, SLTDataType x)
{
	assert(pos);
	assert(ps);

	if (pos == *ps)
	{
		SLTPushFront(ps, x);
	}
	else
	{
		Node* cur = *ps;
		while (cur->next != pos)
		{
			cur = cur->next;
		}
		Node* newNode = BuyNode(x);
		newNode->next = pos;
		cur->next = newNode;
	}
}
// ����posλ��ǰɾ��
void SLTErase(Node** ps, Node* pos)
{
	assert(pos);
	assert(ps);
	if (*ps == pos)
	{
		SLTPopFront(ps);
	}
	else
	{
		Node* cur = *ps;
		while (cur->next != pos)
		{
			cur = cur->next;
		}
		cur->next = pos->next;
		free(pos);
	}
}
// ����posλ�ú����
void SLTInsert(Node* pos, SLTDataType x)
{
	assert(pos);
	Node* newNode = BuyNode(x);
	newNode->next = pos->next;
	pos->next = newNode;

}
// ����posλ�ú�ɾ��
void SLTInsert(Node* pos)
{
	assert(pos);
	assert(pos->next);
	Node* del = pos->next;
	pos->next = del->next;
	free(del);
	del = NULL;
}