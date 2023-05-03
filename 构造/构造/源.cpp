#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <iostream>
using namespace std;

//typedef int STDataType;
//
//typedef struct Stack
//{
//	STDataType* a;
//	int top;
//	int capacity;
//}St;
//
//void StackInit(St* ps);

//class Data
//{
//public:
//	void print()
//	{
//		cout << _year << '-' << _month << "-" << _day << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//void TestData1()
//{
//	Data d1;
//	d1.print();
//}

//class stack
//{
//public:
//	// stack��Ĭ�Ϲ��캯��
//	stack()
//	{
//		cout << "stack" << endl;
//		_a = nullptr;
//		_top = _capacity = 0;
//	}
//private:
//	int* _a;
//	int _top;
//	int _capacity;
//};
//
//class queue
//{
//public:
//	// ����queue�Ĺ��캯������ʾ���壬���Թ��캯��
//private:
//	stack _s;
//};
//
//void TestQueue()
//{
//	queue q;
//}
//int main()
//{
//	TestQueue();
//	return 0;
//}

//class Date
//{
//public:
//	// 1.�޲ε�Ĭ�Ϲ��캯��
//	// Date()
//	// {
//		// ����
//	// }
//	
//	// 2.ȫȱʡ��Ĭ�Ϲ��캯��
//	Date(int year = 0, int month = 0, int day = 0)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	void print()
//	{
//		cout << _year << '-' << _month << '-' << _day << endl;
//	}
//private:
//	int _year = 0;
//	int _month = 0;
//	int _day = 0;
//};
//
//void TestDate2()
//{
//	Date d2;
//	d2.print();
//}
//
//int main()
//{
//	TestDate2();
//	return 0;
//}

//class Stack
//{
//public:
//	// ���캯��
//	Stack()
//	{
//
//	}
//	void push(int x);
//	bool empty();
//	int Top();
//	// �ֶ��ͷ�
//	void Destory();
//private:
//	// ��Ա����
//	int* _a;
//	int _top;
//	int _capacity;
//};
//
//void TestStack()
//{
//	Stack s;
//	s.push(1);
//	s.push(2);
//	// �ֶ��ͷ�
//	s.Destory();
//}

//class Date
//{
//public:
//	// ���캯��
//	Date()
//	{
//		cout << "Date()" << endl;
//	}
//	// ��������
//	~Date()
//	{
//		cout << "~Date()" << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//void TestDate3()
//{
//	// d3�������ڽ���ʱ�Զ����ù��캯��
//	Date d3;
//}
//
//int main()
//{
//	TestDate3();
//}

//class Stack
//{
//public:
//	// ���캯��
//	Stack()
//	{
//		cout << "stack()" << endl;
//		_a = nullptr;
//		_top = _capacity = 0;
//	}
//	// ��������
//	~Stack()
//	{
//		cout << "~Stack()" << endl;
//		free(_a);
//		_a = nullptr;
//		_top = _capacity = 0;
//	}
//private:
//	int* _a;
//	int _top;
//	int _capacity;
//};
//
//class queue
//{
//public:
//	// ����queue�Ĺ��캯����������������ʾ����
//	// ����Ĭ�Ϲ��캯����Ĭ����������
//private:
//	Stack _s;
//};
//
//void TestQueue1()
//{
//	queue q;
//}
//
//int main()
//{
//	TestQueue1();
//	return 0;
//}

//class Date
//{
//public:
//	// ���캯��
//	Date()
//	{
//		cout << "Date()" << endl;
//	}
//	// �������캯��
//	Date(const Date& d)
//	{
//		cout << "Date(&)" << endl;
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//	}
//	~Date()
//	{
//		cout << "~Date()" << endl;
//	}
//private:
//	int _year = 0;
//	int _month = 0;
//	int _day = 0;
//};
//
//void TestDate()
//{
//	Date d1;
//	Date d2(d1);
//}
//
//int main()
//{
//	TestDate();
//}

//class Date
//{
//public:
//	// ����ʾ����
//	// ����д���������ͻᱨ������������ݹ�
//	Date(int year=0,int month=0,int day=0)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	// δ��ʾ����Ŀ������캯��
//	//Date(const Date& d)
//	//{
//	//	_year = d._year;
//	//	_month = d._month;
//	//	_day = d._day;
//	//}
//	void print()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//private:
//	int _year = 0;
//	int _month = 0;
//	int _day = 0;
//};
//
//void TestDate()
//{
//	Date d1(2023,5,3);
//	Date d2(d1);
//	d2.print();
//}
//
//int main()
//{
//	TestDate();
//	return 0;
//}

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
	~stack()
	{
		cout << "~stack()" << endl;
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