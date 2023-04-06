#define _CRT_SECURE_NO_WARNINGS 1
#include "sort.h"

void PrintArray(int* a, int n);
//��������
void InsertSort(int* a, int n)
{
	for (int i = 1; i < n; i++)
	{
		int end = i-1;
		int tmp = a[i];
		while (end>=0)
		{
			if (a[end] > tmp)
			{
				a[end + 1] = a[end];
				end--;
			}
			else break;
		}
		a[end + 1] = tmp;
	}
}
//ϣ������
void ShellSort(int* a, int n)
{
	int gap = n;
	while (gap > 1)
	{
		gap /= 2;
		for (int i = gap; i < n; i++)
		{
			int end = i - gap;
			int tmp = a[i];
			while (end >= 0)
			{
				if (a[end] > tmp)
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else break;
			}
			a[end + gap] = tmp;
		}

	}
}

void Swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}
//ѡ������
void SelectSort(int* a, int n)
{
	int left = 0, right = n - 1;
	while (left < right)
	{
		int minn = left, maxn = left;
		for (int i = left + 1; i <= right; i++)
		{
			if (a[i] < a[minn])
			{
				minn = i;
			}
			if (a[i] > a[maxn])
			{
				maxn = i;
			}
		}
		//������С��Ԫ��
		Swap(&a[left], &a[minn]);
		//���left����maxx�����ڽ���������һ��maxn��ֵ����Ϊԭ��maxnλ���ϵ�ֵ����һ�������н�������minnλ��
		if (left == maxn)
		{
			maxn = minn;
		}
		Swap(&a[right], &a[maxn]);
		++left;
		--right;
	}
}

//���µ���
void AdjustDown(int* a, int n,int parent)
{
	int child = parent * 2 + 1;
	while (child < n)
	{
		if (child + 1 < n && a[child + 1] > a[child])
			++child;
		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else break;
	}
}
//������
void HeapSort(int* a, int n)
{
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(a, n, i);
	}
	int end = n - 1;
	while (end > 0)
	{
		Swap(&a[end], &a[0]);
		AdjustDown(a, end, 0);

		--end;
	}
}
//ð������
void BubbleSort(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		bool exchange = false;
		for (int j = 1; j < n - i; j++)
		{
			if (a[j - 1] > a[j])
			{
				Swap(&a[j - 1], &a[j]);
				exchange = true;
			}
		}
		if (!exchange)break;
	}
}

//����ȡ��
int GetMidNumi(int* a, int left, int right)
{
	int mid = (left + right) / 2;
	if (a[left] < a[mid])
	{
		if (a[mid] < a[right])return mid;
		else if (a[left] > a[right])return left;
		else return right;
	}
	else
	{
		if (a[right] < a[mid])return mid;
		else if (a[left] < a[right])return left;
		else return right;
	}
}

//��һ�ֿ�������hoare
int PartSort1(int* a, int left, int right)
{
	int mid = GetMidNumi(a, left, right);
	if (mid != left)Swap(&a[mid], &a[left]);

	int keyi = left;
	while (left < right)
	{
		while (left < right && a[right] >= a[keyi]) right--;
		while (left < right && a[left] <= a[keyi])left++;
		Swap(&a[left], &a[right]);
	}
	Swap(&a[keyi], &a[left]);
	keyi = left;
	return keyi;
}

//�ڶ��ֿ��������ڿӷ�
int PartSort2(int* a, int left, int right)
{
	int mid = GetMidNumi(a, left, right);
	if (mid != left)Swap(&a[mid], &a[left]);

	int key = a[left];
	int hole = left;
	while (left < right)
	{
		while (left < right && a[right] >= key)
		{
			right--;
		}
		//�ҵ���a[key]С��������λ���γ��µĿ�λ
		a[hole] = a[right];
		hole = right;
		while (left < right && a[left] <= key)
		{
			left++;
		}
		//�ҵ���a[key]���������λ���γ��µĿ�λ
		a[hole] = a[left];
		hole = left;
	}

	a[hole] = key;
	return hole;
}

//ǰ��ָ�뷨
int PartSort3(int* a, int left, int right)
{
	int mid = GetMidNumi(a, left, right);
	if (mid != left)Swap(&a[mid], &a[left]);

	int keyi = left;
	int prev = left;
	int cur = left + 1;
	while (cur <= right)
	{
		if (a[cur] < a[keyi])
		{
			prev++;
			Swap(&a[prev], &a[cur]);
		}
		cur++;
	}
	//prevǰ�涼��keyС��prev���涼��key��
	Swap(&a[prev], &a[keyi]);
	keyi = prev;
	//�����γ��µ���ʼ��
	return keyi;
}
//��������
void QuickSort(int* a, int left, int right)
{
	if (left >= right)return;
	int keyi = PartSort3(a, left, right);
	QuickSort(a, left, keyi-1);
	QuickSort(a, keyi+1, right);
}