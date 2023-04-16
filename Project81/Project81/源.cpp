#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

const int N = 1010;
const int INF = 0x3f3f3f3f;

int n, m, k;
int w[N][N];
// row_max[i]����Ϊk������������ֵ
// row_min[i]����Ϊk�����������Сֵ��Ҫ����ӳ����У�
int row_min[N][N], row_max[N][N];
int q[N];

// ����ÿ��һά�������е����֣��ҳ������Լ����ڣ������Ϊk�ķ�Χ�ڣ���Сֵ�Ƕ���
void get_min(int a[], int b[], int tot)
{
    int hh = 0, tt = -1;
    for (int i = 1; i <= tot; i++)
    {
        // ��������߽����ģ��һ�£�
        // ����i=5,k=3,�򴰿ڷ�Χ��[3,4,5]
        // �±��i-k+1��ʼ
        while (hh <= tt && q[hh] < i - k + 1)hh++;
        while (hh <= tt && a[q[tt]] >= a[i])tt--;
        q[++tt] = i;
        b[i] = a[q[hh]];
    }

}
// ����ÿ��һά�������е����֣��ҳ������Լ����ڣ������Ϊk�ķ�Χ�ڣ����ֵ�Ƕ���
void get_max(int a[], int b[], int tot)
{
    int hh = 0, tt = -1;
    for (int i = 1; i <= tot; i++)
    {
        while (hh <= tt && q[hh] < i - k + 1)hh++;
        while (hh <= tt && a[q[tt]] <= a[i])tt--;
        q[++tt] = i;
        b[i] = a[q[hh]];
    }
}

int main()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> w[i][j];

    // Ԥ�����ȱ���ÿһ�У���¼��Χk�ڵ����ֵ����Сָ
    for (int i = 1; i <= n; i++)
    {
        get_min(w[i], row_min[i], m);
        get_max(w[i], row_max[i], m);
    }

    int t[N]; // ����תΪ�У��������
    int a[N]; // ��Сֵ����
    int b[N]; // ���ֵ����

    int res = INF;

    // �����У���k��ʼ��ֱ���ҵ�һ��k��Χ�������С
    for (int j = k; j <= m; j++)
    {
        // ͬһ�е�ÿһ�У�תΪһ��
        for (int i = 1; i <= n; i++)t[i] = row_min[i][j];
        get_min(t, a, n);

        for (int i = 1; i <= n; i++)t[i] = row_max[i][j];
        get_max(t, b, n);

        for (int i = k; i <= n; i++)res = min(res, b[i] - a[i]);
    }
    cout << res;
}