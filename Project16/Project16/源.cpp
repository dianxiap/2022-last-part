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
        while (s[a[i]] > 1)  //�������ظ����ֵ�ʱ����Ҫ��j����ƶ�
        {
            s[a[j]]--;   //jָ������ֵ���ȥ
            j++;         //j����ƶ�
        }
        res = max(res, i - j + 1);
    }
    cout << res;
}