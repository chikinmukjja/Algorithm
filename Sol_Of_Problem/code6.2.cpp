// code6.2.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;

void Pick(int n, int toPick, vector<int>& picked);
void printPicked(vector<int>& picked);

int main()
{
	int n = 5;

	// 0 ~ n-1 중에서 4만큼의 원소를 고르고 출력하는 문제
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			for (int k = j + 1; k < n; k++)
				for (int l = k + 1; l < n; l++)
					cout << i << "" << j << "" << k << "" << l << endl;
	

	vector<int> picked;

	Pick(5, 4, picked);

    return 0;
}

// 위의 반복문을 재귀함수로 해결
// 원소들의 총개수, 더 골라야할 원소들의 개수, 지금까지 고른 원소들의 번호
// n,k, num[]                
// 종료조건 n < k, k == 0;

void Pick(int n, int toPick,vector<int>& picked)
{
	//기저사례: 더 고를 원소가 없을 때 고른 원소들을 출력한다.
	if (toPick == 0) { printPicked(picked); return;} 
	// 고를 수 있는 가장 작은 번호를 계산한다.
	int smallest = picked.empty() ? 0 : picked.back()+1;
	// 이 단계에서 원소 하나를 고른다.
	for (int next = smallest; next < n; ++next)
	{
		picked.push_back(next);
		Pick(n, toPick - 1, picked);
		picked.pop_back();
	}

}

void printPicked(vector<int>& picked) 
{
	for (unsigned int i = 0; i < picked.size(); i++)
	{
		cout << picked[i];
	}
	cout << endl;
}