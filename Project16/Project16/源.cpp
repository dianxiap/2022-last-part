#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

const int N = 100010;

int n;
int a[N], s[N];
int main()
{
    cin >> n;
    int res = 0;
    for (int i = 0; i < n; i++)cin >> a[i];
    for (int i = 0, j = 0; i < n; i++)
    {
        s[a[i]]++;
        while (s[a[i]] > 1)  //当出现重复数字的时候，需要把j向后移动
        {
            s[a[j]]--;   //j指向的数字弹出去
            j++;         //j向后移动
        }
        res = max(res, i - j + 1);
    }
    cout << res;
}