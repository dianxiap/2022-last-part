#include"Itemdatabase.h"
#include<stdlib.h>

#if 1
#define ENABLE_LOG
#endif

//��̬�洢�����ӿ��С 
#define CHUNK_SIZE 5

int num_items = 0;//��Ʒ���� 
int max_capacity = 0; //��Ʒ���ݿ��������� 

//��Ʒ���ݿ�
struct Item *item_database = NULL; 

ItemIterator ItemDB_GetFirstItemIterator(void)
{
    ItemIterator iter;
    iter.i = 0;
    return iter;
}

//������һ����Ʒ�ĵ����� 
ItemIterator ItemDB_GetNextItemIterator(ItemIterator iter)
{
    ItemIterator iter_next;
    iter_next.i = iter.i+1;
    return iter_next;
}

//�����Ʒ������iter�Ƿ���Ч 
int ItemDB_IsItemIteratorValid(ItemIterator iter)
{
    return iter.i >= 0 && iter.i < num_items;
}

//�����ݿ����������Ϊitem_number����Ʒ 
//�ҵ�������Ʒ������ 
//���򷵻�һ����Ч�ĵ����� 
ItemIterator ItemDB_FindItem(int item_number)
{
    ItemIterator iter;
    int i;
    for(i = 0; i < num_items; i ++)
    {
        if(item_database[i].number == item_number)
        {
            iter.i = i;
            return iter;
        }
    }
    iter.i = -1;
    return iter;
}

int ItemDB_IsEmpty(void)
{
    return !num_items;
}

//����ָ�����ݿ��е�����iter��Ӧ����Ʒ��ָ�� 
struct Item* ItemDB_GetItemPointer(ItemIterator iter)
{
    return item_database + iter.i;
}

//��������Ƿ���Ҫ�������� 
int ItemDB_AddItem(const struct Item *p_item)
{ 
    if(num_items == max_capacity)
    {
        //���������� 
        int new_max_capacity = max_capacity + CHUNK_SIZE;
        //�������ݿ����� 
        item_database = (struct Item *)realloc(item_database,new_max_capacity*sizeof(struct Item));

        //������������Ƿ�ɹ� 
        if(item_database == NULL) return 0;

#ifdef ENABLE_LOG
    printf("���ݿ���������%d -> %d\n",max_capacity,new_max_capacity);
#endif 
        //������������Ϊ��ǰ���� 
        max_capacity = new_max_capacity;
    }

    //��p_itemָ�����Ʒ�������ݿ��� 
    //����Ʒ�������ݿ��β 
    //�ɹ�����1�����򷵻�0 
    item_database[num_items] = *p_item;
    ++num_items; //��Ʒ����+1 
    return 1;
}

//�����ݿ�������ֵΪitem_index��Ԫ��ɾ��
void ItemDB_DeleteItem(ItemIterator iter)
{ 
    int j = iter.i;
    while(j < num_items-1)
    {
        item_database[j] = item_database[++j];
    }
    //��Ʒ����-1 
    -- num_items;

    //������ݿ��Ƿ���Ҫ��С���� 
    if(num_items == max_capacity - CHUNK_SIZE)
    {

#ifdef ENABLE_LOG
    printf("���ݿ�������С��%d -> %d\n",max_capacity,num_items);
#endif // ENABLE_LOG

        if(num_items == 0)
        {
            //�ͷ����ݿ�洢�ռ� 
            free(item_database);
            item_database = NULL;
            max_capacity = 0;
        }
        else
        {
            //��С���ݿ����� 
            item_database = (struct Item *)realloc(item_database,num_items*sizeof(struct Item));
            max_capacity = num_items;
        }
    }
}

void ItemDB_Clear(void)
{
    num_items = 0;
    max_capacity = 0;
    if(item_database != NULL)
    {
        free(item_database);
        item_database = NULL;
    }
}

//������Ʒ����
int ItemDB_GetNumItems()
{ 
    return num_items;
}
