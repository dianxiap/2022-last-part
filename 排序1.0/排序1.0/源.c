#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdbool.h>

void Swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

//—°‘Ò≈≈–Ú
void selectsort(int* a, int n)
{
	int left = 0, right = n - 1;
	while (left < right)
	{
		int mini = left, maxi = left;
		for (int i = left + 1; i <= right; i++)
		{
			if (a[i] < a[mini])
			{
				mini = i;
			}
			if (a[i] > a[maxi])
			{
				maxi = i;
			}
		}
		Swap(&a[left], &a[mini]);
		if (left == maxi)
		{
			maxi = mini;
		}
		Swap(&a[right], &a[maxi]);
		++left;
		--right;
	}
}
//∂—≈≈–Ú
void AdjustDown(int* a, int n, int parent)
{
	int child = parent * 2 + 1;
	while (child < n)
	{
		if (child + 1 < n && a[child + 1] > a[child])
		{
			++child;
		}
		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else break;
	}
}

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
//√∞≈›≈≈–Ú
void BubbleSort(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		bool exchange = false;
		for (int j = 1; j < n - i; j++)
		{
			if (a[j-1] > a[j])
			{
				Swap(&a[i], &a[j]);
				exchange = true;
			}
		}
		if (!exchange)break;
	}
}

//≤Â»Î≈≈–Ú
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

//œ£∂˚≈≈–Ú
void ShellSort(int* a, int n)
{
	int gap = n;
	while (gap > 1)
	{
		gap /= 2;
		for (int i = 0; i < n - gap; i++)
		{
			int end = i;
			int tmp = a[i + gap];
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
}//øÏÀŸ≈≈–Ú
void QuickSort(int* a, int left, int right)
{
	if (left >= right)return;
	int begin = left, end = right;
	int keyi = left;
	while (left < right)
	{
		while (left < right && a[right] >= a[keyi])
		{
			--right;
		}
		while (left < right && a[left] <= a[keyi])
		{
			++left;
		}
		Swap(&a[left], &a[right]);
	}
	Swap(&a[keyi], &a[right]);
	QuickSort(a, begin, right);
	QuickSort(a, right+1, end);
}

int main()
{
	int a[10] = { 9,8,7,6,5,3,1,2,4,0 };
	QuickSort(a, 0, 9);
	for (int i = 0; i < 10; i++)printf("%d ", a[i]);
}