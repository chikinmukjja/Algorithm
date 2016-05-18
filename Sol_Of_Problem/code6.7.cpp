// code6.7.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <vector>



#define MAX 10
#define MIN(x,y) x>y ? y : x 


// n  2<= n =<10 
// n개의 도시를 여행하는 가장 짧은 경로

using namespace std;

double shortestPath(vector<int>& path, vector<bool>& visited, double currentLength);

double dist[MAX][MAX];
int C = 0;
int n = 0;


int main()
{

	cin >> C;

	for (int Ci = 0; Ci < C; Ci++)
	{
		//맵 입력 
		cin >> n;
		vector<bool> visited;

		for (int ni = 0; ni < n; ni++)
		{
			visited.push_back(false);
			for (int nj = 0; nj < n; nj++)
			{
				cin >> dist[ni][nj];
			}
		}
		// 경로를 다 찾고 가장 짧은 것을 반환
		vector<int> path;
		path.push_back(0);
		visited[0] = true;
		cout << shortestPath(path, visited, 0) << endl;

	}


    return 0;
}

double shortestPath(vector<int>& path,vector<bool>& visited,double currentLength)
{
	// 제일 첫번째와 마지막을 잇는 거리
	if (n == path.size())return currentLength + dist[path[0]][path.back()];

	double ret = 1000; // infinite

	for (int next = 0; next < n; next++)
	{
		if (visited[next])continue;
		int here = path.back();
		path.push_back(next);
		visited[next] = true;

		double cand = shortestPath(path, visited, currentLength + dist[here][next]);

		ret = MIN(ret, cand);
		visited[next] = false;
		path.pop_back();
	}

	return ret;


}

