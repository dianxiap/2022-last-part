#define _CRT_SECURE_NO_WARNINGS 1
//��[L,R]�������ҵ����ֵMax����СֵMin����max - min == j - i����˵��������[L,R]�ǵ�����������
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
    for (int i = 0; i < n; i++)  //������˵�
    {
        int maxv = -10000, minv = 10000;
        for (int j = i; j < n; j++)  //�����Ҷ˵�
        {
            maxv = max(maxv, a[j]);
            minv = min(minv, a[j]);
            if (maxv - minv == j - i)res++;
        }
    }
    cout << res;
}