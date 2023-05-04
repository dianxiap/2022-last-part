#define _CRT_SECURE_NO_WARNINGS 1
#include "Sort.h"

void PrintArray(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << ' ';
	}
	cout << endl;
}
void Swap(int* p1, int* p2)
{
	int t = *p1;
	*p1 = *p2;
	*p2 = t;
}

void AdjustDown(int* a, int n, int parent)
{
	int child = parent * 2 + 1;
	while (child < n)
	{
		if (child + 1 < n && a[child + 1] < a[child])
		{
			child++;
		}
		if (a[child] < a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else break;
	}
}
// ∂—≈≈–Ú
void HeapSort(int* a, int n)
{
	for (int i = (n - 2) / 2; i >= 0; i--)
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

// √∞≈›≈≈–Ú
void BubbleSort(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 1; j < n - i; j++)
		{
			if (a[j - 1] > a[j])
			{
				Swap(&a[j - 1], &a[j]);
			}
		}
	}
}

int GetMidNumi(int* a, int left, int right)
{
	int mid = (left + right) / 2;
	if (a[left] < a[mid])
	{
		if (a[mid] < a[right])return mid;
		else if (a[left] < a[right]) return left;
		else return right;
	}
	else
	{
		if (a[mid] > a[right])return mid;
		else if (a[left] < a[right])return left;
		else return right;
	}
}

int PartSort1(int* a, int left, int right)
{
	int mid = GetMidNumi(a, left, right);
	if (mid != left)Swap(&a[left], &a[mid]);
	int keyi = left;
	while (left < right)
	{
		while (left < right && a[right] >= a[keyi])
			--right;
		while (left < right && a[left] <= a[keyi])
			++left;
	}
	Swap(&a[keyi], &a[left]);
	keyi = left;
	return keyi;
}

int PartSort2(int* a, int left, int right)
{
	int mid = GetMidNumi(a, left, right);
	if (mid != left)Swap(&a[left], &a[mid]);

	int key = a[left];
	int hole = left;
	while (left < right)
	{
		while (left < right && a[right] >= key)
			--right;
		a[hole] = a[right];
		hole = right;
		while (left <= right && a[left] <= key)
			++left;
		a[hole] = a[left];
		hole = left;
	}
	a[hole] = key;
	return hole;
}

int PartSort3(int* a, int left, int right)
{
	int mid=Get
}
// øÏÀŸ≈≈–Ú
void QuickSort(int* a, int left, int right)
{

}
// ∑«µ›πÈøÏÀŸ≈≈–Ú
void QuickSortNorR(int* a, int left, int right);
// πÈ≤¢≈≈–Ú
void MergeSort(int* a, int n);
// ∑«µ›πÈπÈ≤¢≈≈–Ú
void MergeSOrtNonR(int* a, int n);

// º∆ ˝≈≈–Ú
void CountSort(int* a, int n);