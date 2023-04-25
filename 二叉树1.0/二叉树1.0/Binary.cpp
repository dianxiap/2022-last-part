#define _CRT_SECURE_NO_WARNINGS 1
#include "Binary.h"
#include "queue.h"

// �ֶ�����һ�Ŷ�����
BTNode* BuyNode(BTDataType x)
{
	BTNode* newNode = (BTNode*)malloc(sizeof(BTNode));
	assert(newNode);
	newNode->data = x;
	newNode->left = NULL;
	newNode->right = NULL;

	return newNode;
}
BTNode* CreatTree()
{
	BTNode* node1 = BuyNode(1);
	BTNode* node2 = BuyNode(2);
	BTNode* node3 = BuyNode(3);
	BTNode* node4 = BuyNode(4);
	BTNode* node5 = BuyNode(5);
	BTNode* node6 = BuyNode(6);
	BTNode* node7 = BuyNode(7);
	BTNode* node8 = BuyNode(8);

	node1->left = node2;
	node1->right = node4;
	node2->left = node3;
	node4->left = node5;
	node4->right = node6;
	node3->right = node7;
	node7->left = node8;

	return node1;
}

// ǰ�����
void PreOrder(BTNode* root)
{
	if (root ==NULL)
	{
		printf("NULL ");
		return;
	}
	printf("%d ", root->data);
	PreOrder(root->left);
	PreOrder(root->right);
}
// �������
void InOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	InOrder(root->left);
	printf("%d ",  root->data);
	InOrder(root->right);
}
// ��������
void PostOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	PostOrder(root->left);
	PostOrder(root->right);
	printf("%d ", root->data);
}
// �������
void LevelOrder(BTNode* root)
{
	Queue q;
	QueueInit(&q);

	if (root)
		QueuePush(&q, root);

	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);
		printf("%d ", front->data);

		if (front->left)
			QueuePush(&q, front->left);
		if (front->right)
			QueuePush(&q, front->right);
	}
	QueueDestroy(&q);
}
// �������ڵ�ĸ���
int TreeSize(BTNode* root);
// �����������
int TreeHight(BTNode* root);
// ��������k��ڵ�ĸ���
int TreeKLevel(BTNode* root, int k);
// ���Ҷ������ڵ�ֵΪx�Ľڵ�
BTNode* TreeFind(BTNode* root, BTDataType x);
// ����������
void TreeDestroy(BTNode* root);
