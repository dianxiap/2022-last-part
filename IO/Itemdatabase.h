#ifndef ITEMDATABASE_H_INCLUDED
#define ITEMDATABASE_H_INCLUDED

#define ITEM_NAME_MAX_LEN 64/*��Ʒ���Ƶ���󳤶�*/


struct Item
{
	int number;/*���*/
	char name[ITEM_NAME_MAX_LEN + 1];/*����*/
	int quantity; /*����*/
};

typedef struct
{
    int i;/*��Ʒ�������е�����*/
}ItemIterator;/*��Ʒ������*/

ItemIterator ItemDB_GetFirstItemIterator(void);
/*���ص�һ����Ʒ�ĵ�����*/

ItemIterator ItemDB_GetNextItemIterator(ItemIterator iter);
/*������һ����Ʒ�ĵ�����*/

int ItemDB_IsItemIteratorValid(ItemIterator iter);
/*�����Ʒ������iter�Ƿ���Ч����Ч�򷵻�1�����򷵻�0*/

ItemIterator ItemDB_FindItem(int item_number);
/*�����ݿ����������Ϊitem_number����Ʒ*/
/*�ҵ�������Ʒ������*/
/*���򷵻�һ����Ч�ĵ�����*/
int ItemDB_IsEmpty(void);

struct Item* ItemDB_GetItemPointer(ItemIterator iter);
/*����ָ�����ݿ��е�����iter��Ӧ����Ʒ��ָ��*/

int ItemDB_AddItem(const struct Item *p_item);
/*��p_itemָ�����Ʒ�������ݿ���*/
    /*����Ʒ�������ݿ��β*/
    /*�ɹ�����1�����򷵻�0*/

void ItemDB_DeleteItem(ItemIterator iter);
/*�����ݿ��е�����iter��Ӧ����Ʒɾ��*/
    /*��Ʒ����-1*/

void ItemDB_Clear(void);/*������ݿ�*/

int ItemDB_GetNumItems();

#endif // ITEMDATABASE_H_INCLUDED
