// code6.5.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>

int countPairings(bool taken[10]);
using namespace std;

int n;
bool areFriends[10][10] = { { false, } };

int main()
{
	int C; //test case 수
	int m; //친구 쌍의 수
	
	//입력 1
	cin >> C;

	for (int Ci = 0; Ci < C; Ci++)
	{
		//입력2
		cin >> n;
		cin >> m;
		
		for (int mi = 0; mi < m; mi++)
		{		
			int f1 = 0;
			int f2 = 0;
			//입력3
			cin >> f1;
			cin >> f2;

			areFriends[f1][f2] = true;
			if(f1>f2)areFriends[f2][f1] = true;

		}

		bool taken[10] = { false, };
		//문제 해결
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
		if (!taken[pairWith] && areFriends[firstFree][pairWith]) {//짝이 정해지지 않았고 그 짝과 친구 일때
			taken[firstFree] = taken[pairWith] = true;
			ret += countPairings(taken);
			taken[firstFree] = taken[pairWith] = false; // 다른 친구에 대한 방법으로 시작
		}
	}

	return ret;

}
