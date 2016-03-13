#pragma once;

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<Windows.h>


#define CHECK_TIME_START  __int64 freq, start, end; if (QueryPerformanceFrequency((_LARGE_INTEGER*)&freq))  {QueryPerformanceCounter((_LARGE_INTEGER*)&start);  
#define CHECK_TIME_END(a,b)   QueryPerformanceCounter((_LARGE_INTEGER*)&end);  a=(float)((double)(end - start)/freq*1000); b=TRUE;                        } else b=FALSE;
// a는 float type  milli second이고 b가 FALSE일때는 에러입니다


bool makeRandomArray(int *array, int size);
void insertionSort(int *array, int size);
void printArray(int *array, int size);
void swap(int *a, int * b);
void quickSort(int *array, int p, int r);
int partition(int *array, int p, int q);
bool copyArray(int *inputArray, int *outputArray, int size);