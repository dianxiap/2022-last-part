#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <cstring>

using namespace std;

const int N = 8;
int n;
int path[N];  //记录选择的路径

//u是从u开始选，sum为所选数的和，cnt为选了多少个
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