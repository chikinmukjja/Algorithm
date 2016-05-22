// code7.1.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

long long int divideConquerSum(long long int n);

int main()
{
	//�پ� ������
	long long int n = 1000000000;
	cout << n<<endl;
	cout << divideConquerSum(n)<<endl;
	
	
	// �Ϲ� for��
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

