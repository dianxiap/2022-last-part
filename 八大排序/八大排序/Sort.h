#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

void PrintArray(int* a, int n);
// ²åÈëÅÅĞò
void InsertSort(int* a, int n);
// Ï£¶ûÅÅĞò
void ShellSort(int* a, int n);
// Ñ¡ÔñÅÅĞò
void SelectSort(int* a, int n);
// ¶ÑÅÅĞò
void HeapSort(int* a, int n);
// Ã°ÅİÅÅĞò
void BubbleSort(int* a, int n);
// ¿ìËÙÅÅĞò
void QuickSort(int* a, int left,int right);
// ·Çµİ¹é¿ìËÙÅÅĞò
void QuickSortNorR(int* a, int left, int right);
// ¹é²¢ÅÅĞò
void MergeSort(int* a, int n);
// ·Çµİ¹é¹é²¢ÅÅĞò
void MergeSOrtNonR(int* a, int n);

// ¼ÆÊıÅÅĞò
void CountSort(int* a, int n);