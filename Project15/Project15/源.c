#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <windows.h>

int main(void) {
    FILE* pf = fopen("test7.txt", "w");
    fputs("abcdef", pf);//�Ƚ�����������������
    printf("˯��10��-�Ѿ�д�����ˣ���test.txt�ļ��������ļ�û������\n");
    Sleep(10000);
    printf("ˢ�»�����\n");
    fflush(pf);//ˢ�»�����ʱ���Ž����������������д���ļ������̣�
    //ע��fflush �ڸ߰汾��VS�ϲ���ʹ����
    printf("��˯��10��-��ʱ���ٴδ�test.txt�ļ����ļ���������\n");
    Sleep(10000);
    fclose(pf);
    //ע��fclose�ڹر��ļ���ʱ��Ҳ��ˢ�»�����
    pf = NULL;

    return 0;
}