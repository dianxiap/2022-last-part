#define _CRT_SECURE_NO_WARNINGS 1
#include "Sort.h"

void PrintArray(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}
// ��������
void InsertSort(int* a, int n)
{
	for (int i = 1; i < n; i++)
	{
		int end = i - 1;
		int tmp = a[i];
		while (end >= 0)
		{
			if (tmp < a[end])
			{
				a[end + 1] = a[end];
				end--;
			}
			else break;
		}
		a[end + 1] = tmp;
	}
}
// ϣ������
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
				if (tmp < a[end])
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
	int t = *p1;
	*p1 = *p2;
	*p2 = t;
}
// ѡ������
void SelectSort(int* a, int n)
{
	int left = 0;
	while (left < n)
	{
		int minn = left;
		for (int i = left + 1; i < n; i++)
		{
			if (a[i] < a[minn])
			{
				minn = i;
			}
		}
		Swap(&a[left], &a[minn]);
		++left;
	}
}
// ������
void HeapSort(int* a, int n);
// ð������
void BubbleSort(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 1; j < n - i; j++)
		{
			if (a[j-1] > a[j])
			{
				Swap(&a[j-1], &a[j]);
			}
		}
	}
}
// ��������
void QuickSort(int* a, int left, int right);
// �ǵݹ��������
void QuickSortNorR(int* a, int left, int right);
// �鲢����
void MergeSort(int* a, int n);
// �ǵݹ�鲢����
void MergeSOrtNonR(int* a, int n);

// ��������
void CountSort(int* a, int n);