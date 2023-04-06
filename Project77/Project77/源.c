#define _CRT_SECURE_NO_WARNINGS 1
#include "sort.h"

void PrintArray(int* a, int n);
//插入排序
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
//希尔排序
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
//选择排序
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
		//交换最小的元素
		Swap(&a[left], &a[minn]);
		//如果left等于maxx，则在交换后修正一下maxn的值，因为原来maxn位置上的值在上一步操作中交换到了minn位置
		if (left == maxn)
		{
			maxn = minn;
		}
		Swap(&a[right], &a[maxn]);
		++left;
		--right;
	}
}

//向下调整
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
//堆排序
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
//冒泡排序
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

//三数取中
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

//第一种快速排序：hoare
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

//第二种快速排序：挖坑法
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
		//找到比a[key]小的树，该位置形成新的坑位
		a[hole] = a[right];
		hole = right;
		while (left < right && a[left] <= key)
		{
			left++;
		}
		//找到比a[key]大的树，该位置形成新的坑位
		a[hole] = a[left];
		hole = left;
	}

	a[hole] = key;
	return hole;
}

//前后指针法
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
	//prev前面都比key小，prev后面都比key大
	Swap(&a[prev], &a[keyi]);
	keyi = prev;
	//交换形成新的起始点
	return keyi;
}
//快速排序
void QuickSort(int* a, int left, int right)
{
	if (left >= right)return;
	int keyi = PartSort3(a, left, right);
	QuickSort(a, left, keyi-1);
	QuickSort(a, keyi+1, right);
}