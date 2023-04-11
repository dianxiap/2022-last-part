#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int GetMidNumi(int* a, int left ,int right)
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
		else right;

	}
}

void Swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}
int PartSort1(int* a, int left, int right)
{
	int midi = GetMidNumi(a, left, right);
	if (midi != left)Swap(&a[midi], &a[left]);
	int keyi = left;

	while (left < right)
	{
		while (left < right && a[right] >= a[keyi])--right;
		while (left < right && a[left] <= a[keyi])++left;
		Swap(&a[left], &a[right]);
	}
	Swap(&a[left], &a[right]);
	keyi = left;
	return keyi;
}

int PartSort2(int* a, int left, int right)
{
	int midi = GetMidNumi(a, left, right);
	if (midi != left)Swap(&a[midi], &a[left]);
	int key = a[left];
	int hole = left;
	while (left <= right)
	{
		while (left < right && a[left] >= key)--right;
		a[hole] = a[right];
		hole = right;
		while (left < right && a[left] <= key)++left;
		a[hole] = a[left];
		hole = left;
	}
	a[hole] = key;
	return hole;
}

int PartSort3(int* a, int left, int right)
{
	int midi = GetMidNumi(a, left, right);
	if (midi != left)Swap(&a[left], &a[midi]);
	int keyi = left;
	int prev = left;
	int cur = left + 1;

	while (cur <= right)
	{
		if (a[cur] < a[keyi] && ++prev != cur)Swap(&a[cur], &a[prev]);

		++cur;
	}
	Swap(&a[prev], &a[keyi]);
	keyi = prev;
	return keyi;
}

void QuickSort(int* a, int left, int right)
{
	if (left >= right)return;
	int keyi = PartSort3(a, left, right);
	QuickSort(a, left, keyi - 1);
	QuickSort(a, keyi + 1, right);
}

//void QuickSortNonR(int* a, int left, int right)
//{
//	St st;
//	StInit(&st);
//	STPush(&st, right);
//	STPush(&st, left);
//
//	while (!STEmpty(&st))
//	{
//		int begin = StTop(&st);
//		STPop(&st);
//		int end = STTop(&st);
//		STPop(&st);
//
//		int keyi = PartSort3(a, begin, end);
//		if (keyi + 1 < end)
//		{
//			STPush(&st, end);
//			STPush(&st, keyi + 1);
//		}
//		if (begin < keyi - 1)
//		{
//			STPush(&st, keyi - 1);
//			STPush(&st, begin);
//		}
//	}
//	STDestoy(&st);
//}

void _MergeSort(int* a, int begin, int end, int* tmp)
{
	if (begin >= end)return;
	int mid = (begin + end) / 2;
	_MergeSort(a, begin, mid, tmp);
	_MergeSort(a, mid + 1, end, tmp);

	int begin1 = begin, end1 = mid;
	int begin2 = mid + 1, end2 = end;
	int i = begin;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] < a[begin2])
		{
			tmp[i++] = a[begin1++];
		}
		else
		{
			tmp[i++] = a[begin2++];
		}
	}
	while (begin1 <= end1)
	{
		tmp[i++] = a[begin1++];
	}
	while (begin2 <= end2)
	{
		tmp[i++] = a[begin2++];
	}
	memcpy(a + begin, tmp + begin, sizeof(int) * (end - begin + 1));
}

void MergeSort(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	if (tmp == NULL)
	{
		perror("malloc error");
		return;
	}
	_MergeSort(a, 0, n - 1, tmp);
	free(tmp);
}


void MergeSortNonR(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	if(tmp==NULL)
	{ 
		perror("malloc error");
		return;
	}
	int gap = 1;
	while (gap < n)
	{
		for (int i = 0; i < n; i += 2 * gap)
		{
			int begin1 = i, end1 = i + gap - 1;
			int begin2 = i + gap, end2 = i + 2 * gap - 1;

			if (end1 >= n || begin2 >= n)
			{
				break;
			}
			if (end2 >= n)
			{
				end2 = n - 1;
			}
			int j = i;
			while (begin1 <= end1&&begin2<=end2)
			{
				if (a[begin1] < a[begin2])
				{
					tmp[j++] = a[begin1++];
				}
				else
				{
					tmp[j++] = a[begin2++];
				}
			}
			while (begin1 <= end1)
			{
				tmp[j++] = a[begin1++];
			}
			while (begin2 <= end2)
			{
				tmp[j++] = a[begin2++];
			}
			memcpy(a + i, tmp + i, sizeof(int) * (end2 - i + 1));

		}
		gap *= 2;
	}
	free(tmp);
}