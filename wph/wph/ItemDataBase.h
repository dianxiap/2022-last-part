#ifndef ITEMDATABASE_H_INCLUDED
#define ITEMDATABASE_H_INCLUDED

#define ITEM_NAME_MAX_LEN 64//��Ʒ���Ƶ���󳤶� 


struct Item
{
	int number;//��� 
	char name[ITEM_NAME_MAX_LEN + 1];//���� 
	int quantity; //���� 
};

//��Ʒ������ 
typedef struct
{
	int i;//��Ʒ�������е����� 
}ItemIterator;

//���ص�һ����Ʒ�ĵ����� 
ItemIterator ItemDB_GetFirstItemIterator(void);

//������һ����Ʒ�ĵ����� 
ItemIterator ItemDB_GetNextItemIterator(ItemIterator iter);

//�����Ʒ������iter�Ƿ���Ч����Ч�򷵻�1�����򷵻�0 
int ItemDB_IsItemIteratorValid(ItemIterator iter);

//�����ݿ����������Ϊitem_number����Ʒ 
//�ҵ�������Ʒ������ 
//���򷵻�һ����Ч�ĵ����� 
ItemIterator ItemDB_FindItem(int item_number);

int ItemDB_IsEmpty(void);

//����ָ�����ݿ��е�����iter��Ӧ����Ʒ��ָ�� 
struct Item* ItemDB_GetItemPointer(ItemIterator iter);

//��p_itemָ�����Ʒ�������ݿ��� 
//����Ʒ�������ݿ��β 
//�ɹ�����1�����򷵻�0 
int ItemDB_AddItem(const struct Item* p_item);

//�����ݿ��е�����iter��Ӧ����Ʒɾ�� 
//��Ʒ����-1 
void ItemDB_DeleteItem(ItemIterator iter);

//������ݿ� 
void ItemDB_Clear(void);

int ItemDB_GetNumItems();

#endif 
