#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
// ���м��г�Ա���������г�Ա����
class A1 {
public:
	void f1() {}
private:
	int _a;
	char _b;
};

// ���н��г�Ա����
class A2 {
public:
	void f2() {}
};

// ����ʲô��û��---����
class A3
{};

int main()
{
	cout << sizeof(A1) << endl;
	cout << sizeof(A2) << endl;
	cout << sizeof(A3) << endl;

	return 0;
}
