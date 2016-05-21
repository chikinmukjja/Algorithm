// code6.8.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include <iostream>
#include <list>
#include <vector>

using namespace std;

int findMinimum(list<vector<int>>& Succ, int limit);
int isAllTwelve(const vector<int>& Clock);
int power(int n);
bool Switch[10][16] = { {false,}, };
//  action switch push => ����� �ð谡 3 6 9 12 �� ���ư�
int convert[4] = { 3,6,9,12 };
int moveClock[4] = {1,2,3,0};
int C = 0;

// ��� �ð谡 12�� �Ǳ����� �ּ� ������ Ƚ��



int main()
{
	Switch[0][0] = Switch[0][1] = Switch[0][2] = true;
	Switch[1][3] = Switch[1][7] = Switch[1][9] = Switch[1][11] = true;
	Switch[2][4] = Switch[2][10] = Switch[2][14] = Switch[2][15] = true;
	Switch[3][0] = Switch[3][4] = Switch[3][5] = Switch[3][6] = Switch[3][7] = true;
	Switch[4][6] = Switch[4][7] = Switch[4][8] = Switch[4][10] = Switch[4][12] = true;

	Switch[5][0] = Switch[5][2] = Switch[5][14] = Switch[5][15] = true;
	Switch[6][3] = Switch[6][14] = Switch[6][15] = true;
	Switch[7][4] = Switch[7][5] = Switch[7][7] = Switch[7][14] = Switch[7][15] = true;
	Switch[8][1] = Switch[8][2] = Switch[8][3] = Switch[8][4] = Switch[8][5] = true;
	Switch[9][3] = Switch[9][4] = Switch[9][5] = Switch[9][9] = Switch[9][13] = true;

	vector<int> Clock;
	
	cin >> C;

	for (int Ci = 0; Ci < C; Ci++)
	{
		for (int ni = 0l; ni < 16; ni++)
		{
			Clock.push_back(-1);
			cin >> Clock[ni];
			for (int i = 0; i < 4; i++)
			{
				if (convert[i] == Clock[ni]) {
					Clock[ni] = i;
					break;
				}
			}
		}

		//�ʱ���� ����
		list<vector<int>> Succ;
		Succ.push_back(Clock);
		cout << findMinimum(Succ,8)<<endl;



	}


    return 0;
}

//�ٲ�� �ϴ� Ƚ�� �����ϴ� �� 


int findMinimum(list<vector<int>>& Succ,int limit)
{
	int depth = 1;
	int num = 0;
	if (isAllTwelve(Succ.front()))return 1;
	//������� 2 : �ƴϸ� �ٽ� breath search�� �Ѵ�.
	
	while (Succ.size()!=0)
	{
		if (limit == 0)return -1;
		//10���� action�� ����
		vector<int> currentState = Succ.front();
		Succ.pop_front();

		for (int i = 0; i < 10; i++)
		{
			vector<int> tmpState = currentState;
			//����ġ�� ����� �ð踦 ã�´�
			for (int j = 0; j < 16; j++)
			{
				//����ġ�� ����� Ŭ����������
				if (Switch[i][j])
				{
					int tmp = moveClock[tmpState[j]];
					tmpState[j] = tmp;
				}
			}
			num++;
			if (isAllTwelve(tmpState))return depth;
			Succ.push_back(tmpState);
		}
		if (num / power(depth) > 0) {
			cout<<depth++<<endl;
			limit--;
		}
		
	}
	

}
int power(int n)
{
	if (n == 0)return 1;
	return power(n - 1) * 10;

}

int isAllTwelve(const vector<int>& Clock)
{
	for (int i = 0; i < 16;i++){
		if (Clock[i] != 3) {
			return false;
		}
	}
	return true;	
}