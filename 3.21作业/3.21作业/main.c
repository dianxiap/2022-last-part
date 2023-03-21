#define _CRT_SECURE_NO_WARNINGS 1
#include "database.h"
int main()
{

    while (1)
    {
        int choice; /*用户所选菜单项编号*/

        /*显示菜单*/
        printf("1-添加物品\n");
        printf("2-删除物品\n");
        printf("3-搜索物品\n");
        printf("4-更新物品\n");
        printf("5-显示数据库\n");
        printf("6-清除数据库\n");
        printf("0-退出\n");

        /*用户选择菜单一项*/
        printf("请输入菜单项编号: ");
        scanf("%d", &choice);

        /*根据用户选择调用相应的功能*/
        if (choice == 0) break;
        switch (choice)
        {
        case 1: UI_AddItem(); break;
        case 2: UI_DeleteItem(); break;
        case 3: UI_SearchItem(); break;
        case 4: UI_UpdateItem(); break;
        case 5: UI_PrintDatabase(); break;
        case 6: UI_ClearDatabase(); break;
        }
    }

    return 0;
}