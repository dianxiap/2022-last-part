#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

void F(int a, int b, int c = 30)
{
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "c = " << c << endl;
	cout << endl;
}

int main()
{
	F(100, 200);
	F(100, 200, 300);

	return 0;
}