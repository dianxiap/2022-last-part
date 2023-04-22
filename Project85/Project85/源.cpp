#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
// 类中既有成员变量，又有成员函数
class A1 {
public:
	void f1() {}
private:
	int _a;
	char _b;
};

// 类中仅有成员函数
class A2 {
public:
	void f2() {}
};

// 类中什么都没有---空类
class A3
{};

int main()
{
	cout << sizeof(A1) << endl;
	cout << sizeof(A2) << endl;
	cout << sizeof(A3) << endl;

	return 0;
}
