#define _CRT_SECURE_NO_WARNINGS 1
//在[L,R]区域中找到最大值Max，最小值Min，若max - min == j - i，则说明该区域[L,R]是递增且连续的
#include <iostream>
using namespace std;

const int N = 10010;
int a[N];

int main()
{
    int n;
    cin >> n;
    int res = 0;
    for (int i = 0; i < n; i++)cin >> a[i];
    for (int i = 0; i < n; i++)  //区间左端点
    {
        int maxv = -10000, minv = 10000;
        for (int j = i; j < n; j++)  //区间右端点
        {
            maxv = max(maxv, a[j]);
            minv = min(minv, a[j]);
            if (maxv - minv == j - i)res++;
        }
    }
    cout << res;
}