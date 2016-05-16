// code6.6Sol.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

bool set(vector<vector<int>>& board, int y, int x, int type, int delta);
int cover(vector<vector<int>>& board);

const int coverType[4][3][2] = {
	{ { 0, 0 },{ 1, 0 },{ 0, 1 }},
	{ { 0, 0 },{ 0, 1 },{ 1, 1 }},
	{ { 0 ,0 },{ 1, 0 },{ 1, 1 }},
	{ { 0 ,0 },{ 1, 0 },{ 1,-1 }}
};


int main()
{
	int C = 0;
	int H = 0;
	int W = 0;
	vector<vector<int>> map;

	cin >> C;

	for (int Ci = 0; Ci < C; ++Ci) {

		cin >> H;
		cin >> W;
		int numOfBlank = 0;
		for (int Hi = 0; Hi < H; ++Hi) {
			vector<int> mapTmp;

			for (int Wi = 0; Wi < W; ++Wi) {
				char tmp;
				cin >> tmp;
				if (tmp == '#')mapTmp.push_back(1);
				else {
					numOfBlank++;
					mapTmp.push_back(0);
				}
			}

			map.push_back(mapTmp);
		}

		//문제 해결
		cout << cover(map) << endl;


	}


	return 0;;
}


bool set(vector<vector<int>>& board, int y, int x, int type,int delta) {
	bool ok = true;
	for (int i = 0; i < 3; i++) {
		const int ny = y + coverType[type][i][0];
		const int nx = x + coverType[type][i][1];
		
		if (ny < 0 || ny >= board.size() || nx < 0 || nx > board.size())ok = false;
		else if ((board[ny][nx] += delta)>1)ok = false;
		
	}
	return ok;
}

int cover(vector<vector<int>>& board) {
	int y = -1;
	int x = -1;

	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board[i].size(); j++)
		{
			if (board[i][j] == 0) {
				y = i;
				x = j;
				break;
			}

		}
		if (y != -1)break;
	}

	if (y == -1)return 1;

	int ret = 0;
	for (int type = 0; type < 4; ++type) {
		if (set(board, y, x, type, 1))
			ret += cover(board);
		set(board, y, x, type, -1);
	}
	return ret;
}



