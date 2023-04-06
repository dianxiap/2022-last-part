#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 110, Mod = 1e6 + 7;

int n;
int f[N];
struct Edge
{
	int l, w;
}gun[N];


int cmp(Edge p1, Edge p2)
{
	if (p1.l != p2.l)return p1.l > p2.l;
	return p1.w > p2.w;
}
//dwith���� ��һ�����л��ֳ����ٵ�����������е���Ŀ�͵���������е�����������еĳ���
//�ȶԹ��ӵĳ�����������Ȼ��������ܶȵ������������
int main()
{
	cin >> n;
	for (int i = 1;i <= n;i++)cin >> gun[i].l >> gun[i].w;
	sort(gun + 1, gun + 1 + n, cmp);
	//�����������
	for (int i = 1;i <= n;i++)
	{
		f[i] = 1;
		for (int j = 1;j<i;j++)
		{
			//���ǰ����ӵ��ܶ�С�ڵ�ǰ���ӵ��ܶȣ�����ת�Ʒ���
			if(gun[i].w > gun[j].w)
 			{
				f[i] = max(f[i], f[j] + 1);
			}
		}
	}	
	int res = 0;
	for (int i = 1;i <= n;i++)res = max(f[i], res);
	cout << res;
}