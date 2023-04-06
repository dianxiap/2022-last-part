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
//dwith定理： 把一个序列划分成最少的最长不升子序列的数目就等于这个数列的最长上升子序列的长度
//先对棍子的长度做降序处理，然后求棍子密度的最长上升子序列
int main()
{
	cin >> n;
	for (int i = 1;i <= n;i++)cin >> gun[i].l >> gun[i].w;
	sort(gun + 1, gun + 1 + n, cmp);
	//最长上升子序列
	for (int i = 1;i <= n;i++)
	{
		f[i] = 1;
		for (int j = 1;j<i;j++)
		{
			//如果前面棍子的密度小于当前棍子的密度，更新转移方程
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