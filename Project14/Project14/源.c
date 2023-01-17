#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main(void) {
    FILE* pf = fopen("test5.txt", "r");
    if (pf == NULL) {
        perror("fopen");
        return 1;
    }

    // 调整文件指针
    fseek(pf, 5, SEEK_CUR); // SEEK_CUR为当前文件指针位置，偏移量为5，向后移动5个单位

    // 返回偏移量
    int loc = ftell(pf);
    printf("fseek调整文件指针后：%d\n", loc); // 6

    // 让文件指针回到起始位置
    rewind(pf);

    // 再次返回偏移量，看看是不是回到起始位置了
    loc = ftell(pf);
    printf("使用rewind后：%d\n", loc); // 6

    // 关闭文件
    fclose(pf);
    pf = NULL;

    return 0;
}