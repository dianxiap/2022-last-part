#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>

void Swap(int* p1, int* p2)
{
	int x = *p1;
	*p1 = *p2;
	*p2 = x;
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
//top-k
void CreateData()
{
	int n = 10000;
	srand((unsigned int)time(NULL));
	const char* file = "data.txt";
	FILE* fin = fopen(file, "w");
	if (fin == NULL)
	{
		perror("fopen erroe");
		return;
	}
	for (int i = 0; i < n; ++i)
	{
		int x = rand() % 10000;
		fprintf(fin, "%d\n", x);
	}
	fclose(fin);
}

void PrintTopK(const char* file, int k)
{
	int* topk = (int*)malloc(sizeof(int) * k);
	assert(topk);

	FILE* fout = fopen(file, "r");
	if (fout == NULL)
	{
		perror("fopen error");
		return;
	}
	//读取前k个数据建小根堆
	for (int i = 0; i < k; i++)
	{
		fscanf(fout, "%d", &topk[i]);
	}

	for (int i = (k - 1 - 1) / 2; i >= 0; --i)
	{
		AdjustDown(topk, k, i);
	}
	int val = 0;
	int ret = fscanf(fout, "%d", &val);
	while (ret != EOF)
	{
		if (val > topk[0])
		{
			topk[0] = val;
			AdjustDown(topk, k, 0);
		}
		ret = fscanf(fout, "%d", &val);
	}

	for (int i = 0; i < k; i++)
	{
		printf("%d ", topk[i]);
	}

	free(topk);
	fclose(fout);
}

int main()
{
	//CreateData();
	PrintTopK("data.txt", 10);
}