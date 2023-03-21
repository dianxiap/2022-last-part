#define _CRT_SECURE_NO_WARNINGS 1
#include "database.h"

struct Item item_database[MAX_NUM_ITEMS];
int num_items = 0;

int ReadLine(char* str, int max_size)
{
    char ch;
    int i = 0;
    while ((ch = getchar()) != '\n')
    {
        if (i < max_size)
            str[i++] = ch;
    }
    str[i] = '\0';
    return i;
}

int ItemDB_FindItem(int item_number)
{
    int i;
    for (i = 0; i < num_items; ++i)
    {
        if (item_database[i].number == item_number)
            return i;
    }
    return -1;
}

int ItemDB_IsFull(void)
{
    return num_items == MAX_NUM_ITEMS;
}

int ItemDB_IsEmpty(void)
{
    return num_items == 0;
}

void ItemDB_AddItem(const struct Item* p_item)
{
    item_database[num_items] = *p_item;
    ++num_items;
}

void ItemDB_DeleteItem(int item_index)
{
    while (item_index < num_items - 1)
    {
        item_database[item_index] = item_database[item_index + 1];
        ++item_index;
    }
    --num_items;
}

struct Item* ItemDB_GetItemPointer(int item_index)
{
    return item_database + item_index;
}

void ItemDB_Clear(void)
{
    num_items = 0;
}

int ItemDB_GetNumItems(void)
{
    return num_items;
}

void UI_AddItem(void)
{
    int i;
    struct Item temp_item;

    if (ItemDB_IsFull())
    {
        printf("���ݿ��������޷������Ʒ��\n");
        return;
    }

    printf("����������Ʒ��ţ�");
    scanf("%d", &temp_item.number);

    i = ItemDB_FindItem(temp_item.number);
    if (i != -1)
    {
        printf("��Ʒ�Ѿ����ڣ�\n");
        return;
    }

    printf("����������Ʒ���ƣ�");
    while (getchar() != '\n');
    ReadLine(temp_item.name, ITEM_NAME_MAX_LEN);

    printf("����������Ʒ������");
    scanf("%d", &temp_item.quantity);

    ItemDB_AddItem(&temp_item);
}

void UI_DeleteItem(void)
{
    int number, i;

    if (ItemDB_IsEmpty())
    {
        printf("���ݿ�Ϊ�գ�\n");
        return;
    }

    /*����Ҫɾ����Ʒ�ı��*/
    printf("������Ҫɾ����Ʒ�ı�ţ�");
    scanf("%d", &number);

    /*�����Ʒ����Ƿ��Ѿ�����*/
    /*�������������ʾ������Ϣ������*/
    i = ItemDB_FindItem(number);
    if (i == -1)
    {
        printf("��Ʒ�����ڣ�\n");
        return;
    }

    /*����Ʒ�����ݿ���ɾ��*/
    while (i < num_items - 1)
    {
        item_database[i] = item_database[i + 1];
        ++i;
    }

    /*��Ʒ������1*/
    --num_items;
}

void UI_SearchItem(void)
/*������Ʒ*/
{
    int number, i;

    /*������Ʒ���*/
    printf("��������Ʒ��ţ�");
    scanf("%d", &number);

    /*�����Ʒ����Ƿ��Ѿ�����*/
    /*�������������ʾ������*/
    /*������ʾ��Ʒ�����ƺ�����*/
    i = ItemDB_FindItem(number);
    if (i == -1)
    {
        printf("��Ʒ�����ڡ�\n");
    }
    else
    {
        printf("��Ʒ���ƣ�%s\n��Ʒ������%d\n",
            item_database[i].name,
            item_database[i].quantity);
    }
}

void UI_UpdateItem(void)
/*������Ʒ*/
{
    int number, i;
    char ch;

    /*������Ʒ���*/
    printf("��������Ʒ��ţ�");
    scanf("%d", &number);

    /*�����Ʒ����Ƿ��Ѿ�����*/
    /*�������������ʾ������Ϣ������*/
    i = ItemDB_FindItem(number);
    if (i == -1)
    {
        printf("��Ʒ�����ڣ�\n");
        return;
    }

    /*ѯ���û��Ƿ���Ҫ�޸�����*/
    /*���������µ�����*/
    printf("�Ƿ���Ҫ�޸����ƣ�"
        "(����y�����ǣ����������)��");
    while (getchar() != '\n');
    ch = getchar();
    if (ch == 'y' || ch == 'Y')
    {
        printf("�������µ����ƣ�");
        while (getchar() != '\n');
        ReadLine(item_database[i].name,
            ITEM_NAME_MAX_LEN);
    }
    else if (ch != '\n')
    {
        while (getchar() != '\n');
    }

    /*ѯ���û��Ƿ���Ҫ�޸�����*/
    /*���������µ�����*/
    printf("�Ƿ���Ҫ�޸�������"
        "(����y�����ǣ����������)��");
    ch = getchar();
    if (ch == 'y' || ch == 'Y')
    {
        printf("�������µ�������");
        scanf("%d", &item_database[i].quantity);
    }
}

void UI_ClearDatabase(void)
/*������ݿ�*/
{
    char ch;

    /*ѯ���û��Ƿ����Ҫ������ݿ�*/
    /*����������ݿ�*/
    printf("��y��ȷ��������ݿ⣬��������ȡ����");
    while (getchar() != '\n');
    ch = getchar();
    if (ch == 'y' || ch == 'Y')
    {
        num_items = 0;
    }
}

void UI_PrintDatabase(void)
/*��ʾ���ݿ�*/
{
    int i;

    /*��ʾ��ͷ*/
    printf("���      ����                ����\n");

    /*�������ݿ��е�ÿ����Ʒ*/
    for (i = 0; i < num_items; ++i)
    {
        /*��ʾ��ǰ��Ʒ��Ϣ*/
        printf("%-10d%-20s%d\n",
            item_database[i].number,
            item_database[i].name,
            item_database[i].quantity);
    }
}