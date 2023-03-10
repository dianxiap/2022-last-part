#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <windows.h>
#include <string.h>
#include<time.h>
//#pragma warning(disable : 4996)// VS已经不支持strcpy函数认为是不安全的,加上它表示为忽略改警告，但如果是codeblock可以不加

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
    while (i <= 6964) {//视频总帧数
        if (i % 30 == 0) {
            delay = 43;
        }
        else {
            delay = 33;
        }
        strcpy(add, "E:\\badapple\\picture\\a (");//这里填写文件ASCII字符txt文件夹位置
        sprintf(ai, "%d", i);//这里提醒一下，如果图片全部转换为ASCII字符txt文件后，记得全部重命名排序  方法是：Ctrl+A 按F2 点击一个文件删除名字或者输入新的
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