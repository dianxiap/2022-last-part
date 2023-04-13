#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "MyIOLib.h"
#include "ItemDataBase.h"
//#include "Itemdatabase.c"

//搜索物品
void UI_SearchItem()
{
    //输入物品编号 
    printf("请输入需要查询的物品编号: ");
    int num; scanf("%d", &num);
    ItemIterator iter;
    iter = ItemDB_FindItem(num);

    //检查物品编号是否已经存在,如果不存在显示不存在 
    if (!ItemDB_IsItemIteratorValid(iter))
        puts("该物品不存在！");

    //否则显示物品的名称和数量 
    else
    {
        struct Item* p_item = ItemDB_GetItemPointer(iter);
        printf("名称: %s\n数量: %d\n",
            p_item->name, p_item->quantity);
    }
}

//更新 
void UI_UpdateItem(void)
{
    printf("请输入物品编号: ");
    ItemIterator iter;

    //输入物品编号 
    int num; scanf("%d", &num);
    iter = ItemDB_FindItem(num);

    //检查物品编号是否已经存在 
    //如果不存在则显示错误信息并返回 
    if (!ItemDB_IsItemIteratorValid(iter))
    {
        puts("该物品不存在！"); return;
    }
    struct Item* p_item;
    p_item = ItemDB_GetItemPointer(iter);

    //询问用户是否需要修改名称 
    printf("是否修改物品名称 [y/n] :");
    char choice[10]; scanf("%s", choice);
    if (choice[0] == 'y') //是则输入新的名称 
    {
        getchar();
        printf("请输入新的物品名称: ");
        ReadLine(p_item->name, ITEM_NAME_MAX_LEN + 1);
        puts("该物品名称已修改!");
    }

    //询问用户是否需要修改数量 
    printf("是否修改物品数量 [y/n] :");
    scanf("%s", choice);

    //是则输入新的数量 
    if (choice[0] == 'y')
    {
        printf("请输入新的物品数量: ");
        scanf("%d", &p_item->quantity);
        puts("该物品数量已修改!");
    }
}

//清除数据库
void UI_ClearDatabase(void)
{
    //询问用户是否真的要清除数据库 
    printf("是否删除数据库[y/n] ");
    //是则清除数据库 
    char choice[100]; scanf("%s", choice);
    if (!strcmp("y", choice))
    {
        ItemDB_Clear();
        printf("数据库已清空!\n");
    }
    else puts("数据库清除失败!\n");
}

//删除物品 
void UI_DeleteItem(void)
{
    //检查数据库是否为空 
    //如果为空则显示错误信息并返回 
    if (ItemDB_IsEmpty())
    {
        printf("数据库为空，无法删除物品！"); return;
    }

    //输入要删除物品编号 
    printf("请输入待删除物品编号: ");
    int num; scanf("%d", &num);

    //如果不存在则显示错误信息并返回 
    ItemIterator iter = ItemDB_FindItem(num);
    if (!ItemDB_IsItemIteratorValid(iter))
    {
        printf("该物品不存在或已被删除!\n"); return;
    }
    //把物品从数据库中删除
    ItemDB_DeleteItem(iter);
    printf("删除成功!\n");
}

//添加物品 
void UI_AddItem(void)
{
    //临时物品 
    ItemIterator i;
    struct Item temp_item;

    //输入新物品编号 
    printf("请输入新物品编号: ");
    int number;
    scanf("%d", &number);
    i = ItemDB_FindItem(number);

    //检查新物品编号是否已经存在 
    //如果已经存在则显示错误信息并返回 
    if (ItemDB_IsItemIteratorValid(i))
    {
        printf("物品已经存在！\n");
        return;
    }
    temp_item.number = number;

    //输入物品名称 
    printf("请输入新物品名称: ");
    while (getchar() != '\n');
    ReadLine(temp_item.name, ITEM_NAME_MAX_LEN);

    //输入物品数量 
    printf("请输入新物品数量: ");
    scanf("%d", &temp_item.quantity);

    //把新物品加入数据库中 
    if (!ItemDB_AddItem(&temp_item))
    {
        printf("物品添加失败！\n");
    }
}

//显示数据库 
void UI_PrintDatabase(void)
{
    if (ItemDB_IsEmpty())
    {
        puts(" 数据库为空！"); return;
    }

    //显示表头 
    printf("编号	  名称               数量\n");

    //遍历数据库中的每个物品 
    ItemIterator iter;
    struct Item* p_item;

    for (iter = ItemDB_GetFirstItemIterator(); ItemDB_IsItemIteratorValid(iter); iter = ItemDB_GetNextItemIterator(iter))
    {
        //获取指向当前物品的指针 
        p_item = ItemDB_GetItemPointer(iter);
        //显示当前物品信息 
        printf("%-10d%-20s%d\n",
            p_item->number,
            p_item->name,
            p_item->quantity);
    }
}

//临时测试函数 
//创建测试数据库 
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
        //用户所选菜单项编号 
        char choice;
        //显示菜单 
        printf(" | 1-添加物品   |\n");
        printf(" | 2-删除物品   |\n");
        printf(" | 3-搜索物品   |\n");
        printf(" | 4-更新物品   |\n");
        printf(" | 5-显示数据库 |\n");
        printf(" | 6-清除数据库 |\n");
        printf(" | 0-退出       |\n");
        //用户选择菜单一项 
        printf("Please input the number of the menu: ");
        scanf("%c", &choice);
        //根据用户选择调用相应功能 
        switch (choice)
        {
        case '1': UI_AddItem(); break;
        case '2': UI_DeleteItem(); break;
        case '3': UI_SearchItem(); break;
        case '4': UI_UpdateItem(); break;
        case '5': UI_PrintDatabase(); break;
        case '6': UI_ClearDatabase(); break;
        case '0': puts("退出\n"); break;
        default: puts("选择错误，请重新选择"); break;
        }
        if (choice == '0') break;
        while ((choice = getchar()) != '\n');

    }
    return 0;
}
