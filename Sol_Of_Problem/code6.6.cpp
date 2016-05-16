// code6.6.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include <iostream>
#include <vector>



using namespace std;

int coverBlock(int numOfBlank, vector<vector<int>>& map);
void showMap(vector<vector<int>> map);
bool inRange(int x, int y, int limitX, int limitY);

int coverTypeY[4][2] = { {1,1}, {1,0}, {0,1}, {0,-1} };
int coverTypeX[4][2] = { {0,1}, {1,1}, {1,0}, {1,1} };


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

		//���� �ذ�
		cout << coverBlock(numOfBlank,map)<<endl;

	
	}


    return 0;
}


int coverBlock(int numOfBlank,vector<vector<int>>& map)
{
	//�� ä����.
	if (numOfBlank == 0)return 1;
	//������� 1 : 3���� ������������ �Ѵ�.
	if (numOfBlank % 3 != 0)return 0;
	//�������

	// �� ä��ٸ� ��ȯ

	bool finished = true;
	int x=0;
	int y=0;

	for (int Hi = 0; Hi < map.size(); ++Hi) {
		for (int Wi = 0; Wi < map[Hi].size();++Wi)
			if (map[Hi][Wi] == 0) {
				finished = false;
				y = Wi;
				x = Hi;
				//cout << y;
				//cout << x<<endl;
				break;
			}
		if (!finished)break;
	}
	//���� ���� �˾ƺ��� ! -- > ����	����� �����ϸ� �Ǵµ� ����� ���۷��̼� ��ü�� ����� �����ɸ� 6�ʿ� 20�� ����
	if (finished)return 1;
	
	
	int ret = 0;
	for (int i = 0; i < 4; i++) {
		
		//inrange �߰�
		if (!inRange(x + coverTypeX[i][0], y + coverTypeY[i][0], map.size(), map[0].size()))continue;
		if (!inRange(x + coverTypeX[i][1], y + coverTypeY[i][1], map.size(), map[0].size()))continue;
		
		if (map[x + coverTypeX[i][0]][y + coverTypeY[i][0]] == 0
			&& map[x + coverTypeX[i][1]][y + coverTypeY[i][1]] == 0)
		{
			map[x + coverTypeX[i][0]][y + coverTypeY[i][0]] = 1;
			map[x + coverTypeX[i][1]][y + coverTypeY[i][1]] = 1;
			map[x ][y] = 1;
			// show
			//showMap(tmpMap);
			//cout << endl;
			ret += coverBlock(numOfBlank-3,map);

			map[x + coverTypeX[i][0]][y + coverTypeY[i][0]] = 0;
			map[x + coverTypeX[i][1]][y + coverTypeY[i][1]] = 0;
			map[x][y] = 0;

		}

	}
	return ret;
}

void showMap(vector<vector<int>> map)
{
	for (int Hi = 0; Hi < map.size(); ++Hi) {
		for (int Wi = 0; Wi < map[Hi].size(); ++Wi)
		{
			cout << map[Hi][Wi];
		}
		cout << endl;
	}
}

bool inRange(int x,int y,int limitX,int limitY)
{
	if (x < 0 || x >= limitX)return false;
	if (y < 0 || y >= limitY)return false;

	return true;
}