// code6.8sol.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#define MIN(x,y) x<y ? x : y

using namespace std;

int limit = 19000;

const int INF = 9999, SWITCHES = 10, CLOCKS = 16;
// linked[i][j]='x' : i번 스위치와 j번 시계가 연결되어 있다.
// linked[i][j]='.' : i번 스위치와 j번 시계가 연결되어 있지 않다.

const char Linked[SWITCHES][CLOCKS + 1] = {

	"xxx.............",
	"...x...x.x.x....",
	"....x.....x...xx",
	"x...xxxx........",
	"......xxx.x.x...",

	"x.x...........xx",
	"...x..........xx",
	"....xx.x......xx",
	".xxxxx..........",
	"...xxx...x...x.."

};

bool areAligned(const vector<int>& clocks)
{
	for (int i = 0; i < CLOCKS; i++)
	{
		if (clocks[i] != 12)return false;
	}

	
	return true;
}

void push(vector<int>& clocks,int swtch)
{
	for (int clock = 0; clock < CLOCKS; clock++) 
	{
		if (Linked[swtch][clock] == 'x') {
			clocks[clock] += 3;
			if (clocks[clock] == 15)clocks[clock] = 3;
		}
	}
}

int solve(vector<int>& clocks, int swtch,int current)
{
	if (swtch == SWITCHES)return areAligned(clocks) ? 0 : INF;
	int ret = INF;
	for (int cnt = 0; cnt < 4; cnt++)
	{
		if (limit <= current)break;
		int tmp = cnt + solve(clocks, swtch + 1,current+cnt);
		limit = ret = MIN(ret, tmp);		
		push(clocks, swtch);
	}
	return ret;
}

int main()
{
	int C;
	vector<int> clocks;
	cin >> C;

	for (int i = 0; i < C; i++)
	{
		for (int j = 0; j < CLOCKS;j++)
		{
			clocks.push_back(0);
			cin >> clocks[j];
		}

		int ret=-2;
		if ((ret = solve(clocks,0,0)) == INF)cout<<-1<<endl;
		else cout << ret << endl;

	}




    return 0;
}

