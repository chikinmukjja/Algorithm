// code6.2.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
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

	// 0 ~ n-1 �߿��� 4��ŭ�� ���Ҹ� ���� ����ϴ� ����
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			for (int k = j + 1; k < n; k++)
				for (int l = k + 1; l < n; l++)
					cout << i << "" << j << "" << k << "" << l << endl;
	

	vector<int> picked;

	Pick(5, 4, picked);

    return 0;
}

// ���� �ݺ����� ����Լ��� �ذ�
// ���ҵ��� �Ѱ���, �� ������ ���ҵ��� ����, ���ݱ��� �� ���ҵ��� ��ȣ
// n,k, num[]                
// �������� n < k, k == 0;

void Pick(int n, int toPick,vector<int>& picked)
{
	//�������: �� �� ���Ұ� ���� �� �� ���ҵ��� ����Ѵ�.
	if (toPick == 0) { printPicked(picked); return;} 
	// �� �� �ִ� ���� ���� ��ȣ�� ����Ѵ�.
	int smallest = picked.empty() ? 0 : picked.back()+1;
	// �� �ܰ迡�� ���� �ϳ��� ����.
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