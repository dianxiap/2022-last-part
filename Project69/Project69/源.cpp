#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <cstring>

using namespace std;

const int N = 8;
int n;
int path[N];  //��¼ѡ���·��

//u�Ǵ�u��ʼѡ��sumΪ��ѡ���ĺͣ�cntΪѡ�˶��ٸ�
void dfs(int u,int sum,int cnt)
{
	if (u == n)return;
	if (sum == n)
	{
		for (int i = 0; i < cnt; i++)
		{
			if (i == 0)cout << path[i];
			else
			{
				cout << '+' << path[i];
			}
		}
		cout << endl;
		return;
	}
	for (int i = u; i <= n - sum; i++)
	{	
		path[cnt] = i;
		dfs(i, sum + i, cnt + 1);
	}
}

int main()
{
	cin >> n;
	dfs(1,0,0);
}