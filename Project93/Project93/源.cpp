#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
class stack
{
public:
	stack(int defaultCapacity = 10)
	{
		_a = (int*)malloc(sizeof(int) * defaultCapacity);
		if (_a == nullptr)
		{
			perror("malloc fail");
			exit(-1);
		}
		_top = 0;
		_capacity = defaultCapacity;
	}
	stack(const stack& s)
	{
		_a = (int*)malloc(sizeof(int) * s._capacity);
		if (_a == nullptr)
		{
			perror("malloc fail");
			exit(-1);
		}
		memcpy(_a, s._a, sizeof(int) * s._capacity);
		_top = s._top;
		_capacity = s._capacity;
	}
	~stack()
	{
		cout << "~Stack()" << endl;
		free(_a);
		_a = nullptr;
		_top = _capacity = 0;
	}
	void push(int n)
	{
		_a[_top++] = n;
	}
	void print()
	{
		for (int i = 0; i < _top; i++)
		{
			cout << _a[i] << " ";
		}
		cout << endl;
	}
private:
	int* _a;
	int _top;
	int _capacity;
};

void TestStack()
{
	stack s1;
	s1.push(1);
	s1.push(2);
	s1.push(3);
	s1.push(4);
	s1.print();

	stack s2(s1);
	s2.print();
	s2.push(5);
	s2.push(6);
	s2.push(7);
	s2.push(8);
	s2.print();
}
int main()
{
	TestStack();
	return 0;
}