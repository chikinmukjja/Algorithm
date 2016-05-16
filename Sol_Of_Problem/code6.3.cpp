// code6.3.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
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

const int dx[8] = { -1,0,1,-1,1,-1,0,1 }; //  �����¿� �밢�� 8���� Ž���� 
const int dy[8] = { 1,1,1,0,0,-1,-1,-1 };

int main()
{
	
	string word="REPEAT";

	cout << hasWord(1, 2, word) << endl;


    return 0;
}


bool hasWord(int x, int y, const string& word) 
{
	//�������1: ������ġ�� ���� ���̸� ������ ����
	if (!inRange(x, y))return false;
	//�������2: ù���ڰ� ��ġ���� ������ ����
	if (map[x][y] != word[0])return false;
	//�������3: �ܾ���̰� 1�̸� ����
	if (word.size() == 1)return true;
	//������  ����ĭ�� �˻��Ѵ�.
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

