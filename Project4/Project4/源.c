#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>

int main()
{
    //1300300100@qq.com
    //1300300100 qq com
    char arr[] = "1300300100@qq.com";
    printf("ԭ�ַ���: %s\n", arr);

    const char* sep = "@."; // ����sep
    char arr1[30];
    char* ret = NULL;
    strcpy(arr1, arr); // �����ݿ���һ�ݣ�����arr���������

    // ���д�ӡ�и�����
    for (ret = strtok(arr, sep); ret != NULL; ret = strtok(NULL, sep)) {
        printf("%s\n", ret);
    }

    printf("������ԭ���ݣ�%s\n", arr1); // �����arr���������
    printf("�ָ��ԭ�ַ������ƻ�: %s\n", arr); // �ָ��ԭ�ַ���������һ���ָ��ǰ���ַ�

    return 0;
}
