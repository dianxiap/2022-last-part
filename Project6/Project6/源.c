#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int my_strlen(char *arr)
{
	int cnt = 0;
	while (*arr)
	{
		cnt++;
		arr++;
	}
	return cnt;
}


int main()
{
	char arr[] = "abcdef";
	int len=my_strlen(arr);
	printf("%d", len);
}