// code6.5.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include <iostream>

int countPairings(bool taken[10]);
using namespace std;

int n;
bool areFriends[10][10] = { { false, } };

int main()
{
	int C; //test case ��
	int m; //ģ�� ���� ��
	
	//�Է� 1
	cin >> C;

	for (int Ci = 0; Ci < C; Ci++)
	{
		//�Է�2
		cin >> n;
		cin >> m;
		
		for (int mi = 0; mi < m; mi++)
		{		
			int f1 = 0;
			int f2 = 0;
			//�Է�3
			cin >> f1;
			cin >> f2;

			areFriends[f1][f2] = true;
			if(f1>f2)areFriends[f2][f1] = true;

		}

		bool taken[10] = { false, };
		//���� �ذ�
		cout << countPairings(taken)<<endl;

	}
	return 0;
}

int countPairings(bool taken[10]) {

	int firstFree = -1;
	
	for (int i = 0; i < n; ++i)
	{
		if (!taken[i]) {
			firstFree = i;
			break;
		}
	}

	if (firstFree == -1)return 1;

	int ret = 0;
	
	for (int pairWith = firstFree + 1; pairWith < n; ++pairWith) {
		if (!taken[pairWith] && areFriends[firstFree][pairWith]) {//¦�� �������� �ʾҰ� �� ¦�� ģ�� �϶�
			taken[firstFree] = taken[pairWith] = true;
			ret += countPairings(taken);
			taken[firstFree] = taken[pairWith] = false; // �ٸ� ģ���� ���� ������� ����
		}
	}

	return ret;

}
