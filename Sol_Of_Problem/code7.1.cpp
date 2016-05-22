// code7.1.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

long long int divideConquerSum(long long int n);

int main()
{
	//휠씬 빠르다
	long long int n = 1000000000;
	cout << n<<endl;
	cout << divideConquerSum(n)<<endl;
	
	
	// 일반 for문
	long long int sum=0;
	for (long long int i = 1; i <= n; i++)sum+=i;
	cout << sum << endl;

    return 0;
}

long long int divideConquerSum(long long int n)
{
	//base case
	if (n == 1)return 1;
	//odd case
	if (n % 2 == 1)return divideConquerSum(n-1) + n;
	//divide - merge
	return 2 * divideConquerSum(n / 2) + n / 2 * n / 2;

}

