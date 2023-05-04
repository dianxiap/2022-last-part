#pragma once
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

void PrintArray(int* a, int n);
// 堆排序
void HeapSort(int* a, int n);
// 冒泡排序
void BubbleSort(int* a, int n);
// 快速排序
void QuickSort(int* a, int left, int right);
// 非递归快速排序
void QuickSortNorR(int* a, int left, int right);
// 归并排序
void MergeSort(int* a, int n);
// 非递归归并排序
void MergeSOrtNonR(int* a, int n);

// 计数排序
void CountSort(int* a, int n);