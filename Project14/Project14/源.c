#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main(void) {
    FILE* pf = fopen("test5.txt", "r");
    if (pf == NULL) {
        perror("fopen");
        return 1;
    }

    // �����ļ�ָ��
    fseek(pf, 5, SEEK_CUR); // SEEK_CURΪ��ǰ�ļ�ָ��λ�ã�ƫ����Ϊ5������ƶ�5����λ

    // ����ƫ����
    int loc = ftell(pf);
    printf("fseek�����ļ�ָ���%d\n", loc); // 6

    // ���ļ�ָ��ص���ʼλ��
    rewind(pf);

    // �ٴη���ƫ�����������ǲ��ǻص���ʼλ����
    loc = ftell(pf);
    printf("ʹ��rewind��%d\n", loc); // 6

    // �ر��ļ�
    fclose(pf);
    pf = NULL;

    return 0;
}