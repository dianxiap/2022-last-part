#pragma once
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

void PrintArray(int* a, int n);
// ������
void HeapSort(int* a, int n);
// ð������
void BubbleSort(int* a, int n);
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