#define _CRT_SECURE_NO_WARNINGS 1
#include "database.h"
int main()
{

    while (1)
    {
        int choice; /*�û���ѡ�˵�����*/

        /*��ʾ�˵�*/
        printf("1-�����Ʒ\n");
        printf("2-ɾ����Ʒ\n");
        printf("3-������Ʒ\n");
        printf("4-������Ʒ\n");
        printf("5-��ʾ���ݿ�\n");
        printf("6-������ݿ�\n");
        printf("0-�˳�\n");

        /*�û�ѡ��˵�һ��*/
        printf("������˵�����: ");
        scanf("%d", &choice);

        /*�����û�ѡ�������Ӧ�Ĺ���*/
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