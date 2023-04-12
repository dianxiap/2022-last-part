#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <queue>

using namespace std;

#define K 3
#define RADIX 10

queue<int> q[RADIX];

//取出每一位上的数据
int GetKey(int value, int k)
{
	int key = 0;
	while (k >= 0)
	{
		key = value % 10;
		value /= 10;
		k--;
	}
	return key;
}

//向队列上分发每一组数据
void Distribute(int* a, int left, int right, int k)
{
	for (int i = left; i < right; i++)
	{
		int key = GetKey(a[i], k);
		q[key].push(a[i]);
	}
}

//回收队列中的元素至原数组中
void Collect(int* a)
{
	int k = 0;
	for (int i = 0; i < RADIX; i++)
	{
		while (q[i].size())
		{
			a[k++] = q[i].front();
			q[i].pop();
		}
	}
}

void RadixSort(int* a, int left, int right)
{
	//枚举数据的最长长度
	for (int i = 0; i < K; i++)
	{
		//分发数据
		Distribute(a, left, right, i);
		//回收数据
		Collect(a);
	}
}
int main()
{
	int a[] = { 999,52,554,4,16,13,464};
	int n = sizeof(a) / sizeof(a[0]);
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << ' ';
	}
	cout << endl;

	RadixSort(a, 0, n);

	for (int i = 0; i < n; i++)
	{
		cout << a[i] << ' ';
	}
	cout << endl;

}