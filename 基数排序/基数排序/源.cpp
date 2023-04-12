#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <queue>

using namespace std;

#define K 3
#define RADIX 10

queue<int> q[RADIX];

//ȡ��ÿһλ�ϵ�����
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

//������Ϸַ�ÿһ������
void Distribute(int* a, int left, int right, int k)
{
	for (int i = left; i < right; i++)
	{
		int key = GetKey(a[i], k);
		q[key].push(a[i]);
	}
}

//���ն����е�Ԫ����ԭ������
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
	//ö�����ݵ������
	for (int i = 0; i < K; i++)
	{
		//�ַ�����
		Distribute(a, left, right, i);
		//��������
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