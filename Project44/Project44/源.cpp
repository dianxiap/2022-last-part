#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <algorithm>
#define x first
#define y second
using namespace std;
typedef pair<int, int> PII;

const int N = 100010;

int n, m, t;
int score[N];  //�������ȼ�
int last[N];   //��һ���ж�����ʱ��
int st[N];    //�����Ƿ������Ȼ���
PII order[N];  //���ж���

int main()
{
    cin >> n >> m >> t;
    for (int i = 0; i < m; i++)
    {
        cin >> order[i].x >> order[i].y;
    }
    sort(order, order + m);   //�Ƚ���������
    for (int i = 0; i < m;)
    {
        int j = i;
        while (j < m && order[j] == order[i])j++;  //ö��ͬһʱ�� ͬһ���̵Ķ���
        int t = order[i].x, id = order[i].y, cnt = j - i;   //��ͬһʱ�̣�ͬһ�����յ��˶��ٶ���
        i = j;

        score[id] -= t - last[id] - 1;   //��õ����ϴ��յ��������˶���ʱ��
        if (score[id] < 0)score[id] = 0;
        if (score[id] <= 3)st[id] = false;   //�������tʱ��֮ǰû���յ�������ʱ���

        score[id] += cnt * 2;
        if (score[id] > 5)st[id] = true;
        last[id] = t;

    }
    for (int i = 1; i <= n; i++)   //ÿ�ҵ������һ���յ����� �� ���ʱ��T ���������ȼ�
    {
        if (last[i] < t)
        {
            score[i] -= t - last[i];
            if (score[i] <= 3)st[i] = false;
        }
    }
    int res = 0;
    for (int i = 1; i <= n; i++)res += st[i];
    cout << res;
}
