#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <stdlib.h>;

using namespace std;

int main()
{
	int a = 10;
	int& ra = a;
	ra = 20;

	int* pa = &a;
	*pa = 20;
	return 0;
}