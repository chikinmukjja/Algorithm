// code6.1.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
// comparision with loop and recursive 
//

#include "stdafx.h"
#include <time.h>
#include <stdlib.h>
#include <windows.h>

#define CHECK_TIME_START  __int64 freq, start, end; if (QueryPerformanceFrequency((_LARGE_INTEGER*)&freq))  {QueryPerformanceCounter((_LARGE_INTEGER*)&start);   
#define CHECK_TIME_END(a, b)   QueryPerformanceCounter((_LARGE_INTEGER*)&end);  a = (float)((double)(end - start) / freq * 1000); b = TRUE; } else b=FALSE; 


int sum(int n);
int recursiveSum(int n);

int main()
{
	double recursive;
	double loop;

	bool err;

	{
		CHECK_TIME_START;
		printf("%d\n", sum(2000));
		CHECK_TIME_END(loop, err);
		printf("time %f\n", loop);
	}

	{
		CHECK_TIME_START;
		printf("%d\n", recursiveSum(2000));
		CHECK_TIME_END(recursive, err);
		printf("r time %f\n", recursive);
	}
	
	
	return 0;
}

int sum(int n)
{
	int ret = 0;

	for (int i = 1; i <= n; i++) {
		ret += i;
	}

	return ret;
}

int recursiveSum(int n)
{
	if (n == 1)return 1;	//쪼개지지 않는 가장 작은 작업들 == base case
	
	return recursiveSum(n - 1)+n;
}
