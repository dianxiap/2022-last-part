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
        printf("数据库已满，无法添加物品！\n");
        return;
    }

    printf("请输入新物品编号：");
    scanf("%d", &temp_item.number);

    i = ItemDB_FindItem(temp_item.number);
    if (i != -1)
    {
        printf("物品已经存在！\n");
        return;
    }

    printf("请输入新物品名称：");
    while (getchar() != '\n');
    ReadLine(temp_item.name, ITEM_NAME_MAX_LEN);

    printf("请输入新物品数量：");
    scanf("%d", &temp_item.quantity);

    ItemDB_AddItem(&temp_item);
}

void UI_DeleteItem(void)
{
    int number, i;

    if (ItemDB_IsEmpty())
    {
        printf("数据库为空！\n");
        return;
    }

    /*输入要删除物品的编号*/
    printf("请输入要删除物品的编号：");
    scanf("%d", &number);

    /*检查物品编号是否已经存在*/
    /*如果不存在则显示错误信息并返回*/
    i = ItemDB_FindItem(number);
    if (i == -1)
    {
        printf("物品不存在！\n");
        return;
    }

    /*把物品从数据库中删除*/
    while (i < num_items - 1)
    {
        item_database[i] = item_database[i + 1];
        ++i;
    }

    /*物品总数减1*/
    --num_items;
}

void UI_SearchItem(void)
/*搜索物品*/
{
    int number, i;

    /*输入物品编号*/
    printf("请输入物品编号：");
    scanf("%d", &number);

    /*检查物品编号是否已经存在*/
    /*如果不存在则显示不存在*/
    /*否则显示物品的名称和数量*/
    i = ItemDB_FindItem(number);
    if (i == -1)
    {
        printf("物品不存在。\n");
    }
    else
    {
        printf("物品名称：%s\n物品数量：%d\n",
            item_database[i].name,
            item_database[i].quantity);
    }
}

void UI_UpdateItem(void)
/*更新物品*/
{
    int number, i;
    char ch;

    /*输入物品编号*/
    printf("请输入物品编号：");
    scanf("%d", &number);

    /*检查物品编号是否已经存在*/
    /*如果不存在则显示错误信息并返回*/
    i = ItemDB_FindItem(number);
    if (i == -1)
    {
        printf("物品不存在！\n");
        return;
    }

    /*询问用户是否需要修改名称*/
    /*是则输入新的名称*/
    printf("是否需要修改名称？"
        "(输入y代表是，其他代表否)：");
    while (getchar() != '\n');
    ch = getchar();
    if (ch == 'y' || ch == 'Y')
    {
        printf("请输入新的名称：");
        while (getchar() != '\n');
        ReadLine(item_database[i].name,
            ITEM_NAME_MAX_LEN);
    }
    else if (ch != '\n')
    {
        while (getchar() != '\n');
    }

    /*询问用户是否需要修改数量*/
    /*是则输入新的数量*/
    printf("是否需要修改数量？"
        "(输入y代表是，其他代表否)：");
    ch = getchar();
    if (ch == 'y' || ch == 'Y')
    {
        printf("请输入新的数量：");
        scanf("%d", &item_database[i].quantity);
    }
}

void UI_ClearDatabase(void)
/*清除数据库*/
{
    char ch;

    /*询问用户是否真的要清除数据库*/
    /*是则清除数据库*/
    printf("按y键确认清除数据库，按其他键取消：");
    while (getchar() != '\n');
    ch = getchar();
    if (ch == 'y' || ch == 'Y')
    {
        num_items = 0;
    }
}

void UI_PrintDatabase(void)
/*显示数据库*/
{
    int i;

    /*显示表头*/
    printf("编号      名称                数量\n");

    /*遍历数据库中的每个物品*/
    for (i = 0; i < num_items; ++i)
    {
        /*显示当前物品信息*/
        printf("%-10d%-20s%d\n",
            item_database[i].number,
            item_database[i].name,
            item_database[i].quantity);
    }
}