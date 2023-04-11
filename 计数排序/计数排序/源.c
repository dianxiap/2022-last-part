#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

void CountSort(int* a, int n)
{
	int max = a[0], min = a[0];
	for (int i = 1; i < n; i++)
	{
		if (a[i] > max)
		{
			max = a[i];
		}
		if (a[i] < min)
		{
			min = a[i];
		}
	}

	int range = max - min + 1;
	int* countA = (int*)malloc(sizeof(int) * range);
	if (countA == NULL)
	{
		perror("malloc fail");
		return;
	}
	memset(countA, 0, sizeof countA);
	for (int i = 0; i < n; i++)
	{
		countA[a[i] - min]++;
	}
	int j = 0;
	for (int i = 0; i < range; i++)
	{
		while (countA[i]--)
		{
			a[j++] = i + min;
		}
	}
	free(countA);
}