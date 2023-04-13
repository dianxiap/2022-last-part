#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "MyIOLib.h"
#include "ItemDataBase.h"
//#include "Itemdatabase.c"

//������Ʒ
void UI_SearchItem()
{
    //������Ʒ��� 
    printf("��������Ҫ��ѯ����Ʒ���: ");
    int num; scanf("%d", &num);
    ItemIterator iter;
    iter = ItemDB_FindItem(num);

    //�����Ʒ����Ƿ��Ѿ�����,�����������ʾ������ 
    if (!ItemDB_IsItemIteratorValid(iter))
        puts("����Ʒ�����ڣ�");

    //������ʾ��Ʒ�����ƺ����� 
    else
    {
        struct Item* p_item = ItemDB_GetItemPointer(iter);
        printf("����: %s\n����: %d\n",
            p_item->name, p_item->quantity);
    }
}

//���� 
void UI_UpdateItem(void)
{
    printf("��������Ʒ���: ");
    ItemIterator iter;

    //������Ʒ��� 
    int num; scanf("%d", &num);
    iter = ItemDB_FindItem(num);

    //�����Ʒ����Ƿ��Ѿ����� 
    //�������������ʾ������Ϣ������ 
    if (!ItemDB_IsItemIteratorValid(iter))
    {
        puts("����Ʒ�����ڣ�"); return;
    }
    struct Item* p_item;
    p_item = ItemDB_GetItemPointer(iter);

    //ѯ���û��Ƿ���Ҫ�޸����� 
    printf("�Ƿ��޸���Ʒ���� [y/n] :");
    char choice[10]; scanf("%s", choice);
    if (choice[0] == 'y') //���������µ����� 
    {
        getchar();
        printf("�������µ���Ʒ����: ");
        ReadLine(p_item->name, ITEM_NAME_MAX_LEN + 1);
        puts("����Ʒ�������޸�!");
    }

    //ѯ���û��Ƿ���Ҫ�޸����� 
    printf("�Ƿ��޸���Ʒ���� [y/n] :");
    scanf("%s", choice);

    //���������µ����� 
    if (choice[0] == 'y')
    {
        printf("�������µ���Ʒ����: ");
        scanf("%d", &p_item->quantity);
        puts("����Ʒ�������޸�!");
    }
}

//������ݿ�
void UI_ClearDatabase(void)
{
    //ѯ���û��Ƿ����Ҫ������ݿ� 
    printf("�Ƿ�ɾ�����ݿ�[y/n] ");
    //����������ݿ� 
    char choice[100]; scanf("%s", choice);
    if (!strcmp("y", choice))
    {
        ItemDB_Clear();
        printf("���ݿ������!\n");
    }
    else puts("���ݿ����ʧ��!\n");
}

//ɾ����Ʒ 
void UI_DeleteItem(void)
{
    //������ݿ��Ƿ�Ϊ�� 
    //���Ϊ������ʾ������Ϣ������ 
    if (ItemDB_IsEmpty())
    {
        printf("���ݿ�Ϊ�գ��޷�ɾ����Ʒ��"); return;
    }

    //����Ҫɾ����Ʒ��� 
    printf("�������ɾ����Ʒ���: ");
    int num; scanf("%d", &num);

    //�������������ʾ������Ϣ������ 
    ItemIterator iter = ItemDB_FindItem(num);
    if (!ItemDB_IsItemIteratorValid(iter))
    {
        printf("����Ʒ�����ڻ��ѱ�ɾ��!\n"); return;
    }
    //����Ʒ�����ݿ���ɾ��
    ItemDB_DeleteItem(iter);
    printf("ɾ���ɹ�!\n");
}

//�����Ʒ 
void UI_AddItem(void)
{
    //��ʱ��Ʒ 
    ItemIterator i;
    struct Item temp_item;

    //��������Ʒ��� 
    printf("����������Ʒ���: ");
    int number;
    scanf("%d", &number);
    i = ItemDB_FindItem(number);

    //�������Ʒ����Ƿ��Ѿ����� 
    //����Ѿ���������ʾ������Ϣ������ 
    if (ItemDB_IsItemIteratorValid(i))
    {
        printf("��Ʒ�Ѿ����ڣ�\n");
        return;
    }
    temp_item.number = number;

    //������Ʒ���� 
    printf("����������Ʒ����: ");
    while (getchar() != '\n');
    ReadLine(temp_item.name, ITEM_NAME_MAX_LEN);

    //������Ʒ���� 
    printf("����������Ʒ����: ");
    scanf("%d", &temp_item.quantity);

    //������Ʒ�������ݿ��� 
    if (!ItemDB_AddItem(&temp_item))
    {
        printf("��Ʒ���ʧ�ܣ�\n");
    }
}

//��ʾ���ݿ� 
void UI_PrintDatabase(void)
{
    if (ItemDB_IsEmpty())
    {
        puts(" ���ݿ�Ϊ�գ�"); return;
    }

    //��ʾ��ͷ 
    printf("���	  ����               ����\n");

    //�������ݿ��е�ÿ����Ʒ 
    ItemIterator iter;
    struct Item* p_item;

    for (iter = ItemDB_GetFirstItemIterator(); ItemDB_IsItemIteratorValid(iter); iter = ItemDB_GetNextItemIterator(iter))
    {
        //��ȡָ��ǰ��Ʒ��ָ�� 
        p_item = ItemDB_GetItemPointer(iter);
        //��ʾ��ǰ��Ʒ��Ϣ 
        printf("%-10d%-20s%d\n",
            p_item->number,
            p_item->name,
            p_item->quantity);
    }
}

//��ʱ���Ժ��� 
//�����������ݿ� 
void CreateTestDatabase(void)
{
    int i, k;
    struct Item temp_item;

    srand(123);

    for (i = 0; i < 20; i++)
    {
        temp_item.number = i + 1;
        for (k = 0; k < 8; k++)
            temp_item.name[k] = 'A' + rand() % 26;
        temp_item.name[k] = '\0';
        temp_item.quantity = rand() % 1000;
        ItemDB_AddItem(&temp_item);
    }

}
int main()
{
    CreateTestDatabase();
    while (1)
    {
        //�û���ѡ�˵����� 
        char choice;
        //��ʾ�˵� 
        printf(" | 1-�����Ʒ   |\n");
        printf(" | 2-ɾ����Ʒ   |\n");
        printf(" | 3-������Ʒ   |\n");
        printf(" | 4-������Ʒ   |\n");
        printf(" | 5-��ʾ���ݿ� |\n");
        printf(" | 6-������ݿ� |\n");
        printf(" | 0-�˳�       |\n");
        //�û�ѡ��˵�һ�� 
        printf("Please input the number of the menu: ");
        scanf("%c", &choice);
        //�����û�ѡ�������Ӧ���� 
        switch (choice)
        {
        case '1': UI_AddItem(); break;
        case '2': UI_DeleteItem(); break;
        case '3': UI_SearchItem(); break;
        case '4': UI_UpdateItem(); break;
        case '5': UI_PrintDatabase(); break;
        case '6': UI_ClearDatabase(); break;
        case '0': puts("�˳�\n"); break;
        default: puts("ѡ�����������ѡ��"); break;
        }
        if (choice == '0') break;
        while ((choice = getchar()) != '\n');

    }
    return 0;
}
