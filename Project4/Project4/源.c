#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>

int main()
{
    //1300300100@qq.com
    //1300300100 qq com
    char arr[] = "1300300100@qq.com";
    printf("原字符串: %s\n", arr);

    const char* sep = "@."; // 创建sep
    char arr1[30];
    char* ret = NULL;
    strcpy(arr1, arr); // 将数据拷贝一份，保留arr数组的内容

    // 分行打印切割内容
    for (ret = strtok(arr, sep); ret != NULL; ret = strtok(NULL, sep)) {
        printf("%s\n", ret);
    }

    printf("保留的原内容：%s\n", arr1); // 保存的arr数组的内容
    printf("分割后原字符串被破坏: %s\n", arr); // 分割后原字符串保留第一个分割符前的字符

    return 0;
}
