#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>

using namespace std;
//ÄÚÁªº¯Êı
void f(int)
{
	cout << "f(int)" << endl;
}
void f(int*)
{
	cout << "f(int*)" << endl;
}
int main()
{
	f(0);
	f(NULL);
	f((int*)NULL);
	return 0;
}
