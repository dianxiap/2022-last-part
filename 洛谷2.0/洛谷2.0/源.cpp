#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int n;
struct Edge
{
	int head, tail, val;
}a[150005];

int f[150005];

bool cmp(Edge p1, Edge p2)
{
	return p1.tail < p2.tail;
}
//�ҵ��ȵ�ǰͷС����С��������˵�
int check(int l, int r, int key)
{
	int ans = 0;
	while (l < r)
	{
		int mid = l + r + 1 >> 1;
		if (a[mid].tail < key)
		{
			ans = mid;
			l = mid;
		}
		else r = mid - 1;
	}
	return ans;
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i].head >> a[i].tail;
		a[i].val = a[i].tail - a[i].head + 1;
	}
	//�������Ҷ˵�����
	sort(a + 1, a + n + 1, cmp);
	for (int i = 1; i <= n; i++)
	{
		//ת�Ʒ��̣�f[i]=max(f[i-1],f[j]+a[i].tail-a[i].head+1)
		//1.f[i-1]��ʾ���Բ�ѡ
		//2.f[j]��ʾѡ��ǰ����ʱ��������˵����Сλ�ã���f[j]ת�Ƶ�f[i]������a[i].tail-a[i].head+1
		f[i] = max(f[i - 1], f[check(1, i - 1, a[i].head)] + a[i].val);
	}
	cout << f[n];
}