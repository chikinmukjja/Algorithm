// code6.3.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
// BOGGLE 

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

bool hasWord(int x, int y, const string& word);
bool inRange(int x, int y);

const char map[5][5] = { { 'U','R','L','P','M' },
{ 'X','P','R','E','T' },
{ 'G','I','A','E','T' },
{ 'X','T','N','Z','Y' },
{ 'X','O','Q','R','S' } };

const int dx[8] = { -1,0,1,-1,1,-1,0,1 }; //  상하좌우 대각선 8방향 탐색팁 
const int dy[8] = { 1,1,1,0,0,-1,-1,-1 };

int main()
{
	
	string word="REPEAT";

	cout << hasWord(1, 2, word) << endl;


    return 0;
}


bool hasWord(int x, int y, const string& word) 
{
	//기저사례1: 시작위치가 범위 밖이면 무조건 실패
	if (!inRange(x, y))return false;
	//기저사례2: 첫글자가 일치하지 않으면 실패
	if (map[x][y] != word[0])return false;
	//기저사례3: 단어길이가 1이면 성공
	if (word.size() == 1)return true;
	//인접한  여덟칸을 검사한다.
	for (int i = 0; i < 8; i++) {
		if (hasWord(x + dx[i], y + dy[i], word.substr(1)))return true;
	}

	return false;
}

bool inRange(int x, int y)
{
	if (x < 0 || x >= 5)return false;
	if (y < 0 || y >= 5)return false;
	
	return true;
}

