#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <windows.h>
#include <string.h>
#include<time.h>
//#pragma warning(disable : 4996)// VS�Ѿ���֧��strcpy������Ϊ�ǲ���ȫ��,��������ʾΪ���Ըľ��棬�������codeblock���Բ���

static void SetPos(int x, int y) {
    COORD point = { 150 , 150 };
    HANDLE HOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(HOutput, point);
}
int main() {
    FILE* fp;
    char buf[150], add[60], ai[5];
    int i = 1, delay = 33;
    clock_t stime = 0, ftime = 0;
    stime = clock();
    while (i <= 6964) {//��Ƶ��֡��
        if (i % 30 == 0) {
            delay = 43;
        }
        else {
            delay = 33;
        }
        strcpy(add, "E:\\badapple\\picture\\a (");//������д�ļ�ASCII�ַ�txt�ļ���λ��
        sprintf(ai, "%d", i);//��������һ�£����ͼƬȫ��ת��ΪASCII�ַ�txt�ļ��󣬼ǵ�ȫ������������  �����ǣ�Ctrl+A ��F2 ���һ���ļ�ɾ�����ֻ��������µ�
        strcat(add, ai);
        strcat(add, ").txt");
        ftime = clock();
        if (ftime - stime >= delay) {
            fp = fopen(add, "r");
            if (NULL == fp) {}
            else {
                while (fgets(buf, 150, fp)) {
                    printf("%s", buf);
                }
                fclose(fp);
                SetPos(0, 0);
                i++;
                stime += delay;
            }
        }
    }
    return 0;
}