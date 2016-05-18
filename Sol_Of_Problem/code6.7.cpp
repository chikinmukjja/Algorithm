// code6.7.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include <iostream>
#include <vector>



#define MAX 10
#define MIN(x,y) x>y ? y : x 


// n  2<= n =<10 
// n���� ���ø� �����ϴ� ���� ª�� ���

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
		//�� �Է� 
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
		// ��θ� �� ã�� ���� ª�� ���� ��ȯ
		vector<int> path;
		path.push_back(0);
		visited[0] = true;
		cout << shortestPath(path, visited, 0) << endl;

	}


    return 0;
}

double shortestPath(vector<int>& path,vector<bool>& visited,double currentLength)
{
	// ���� ù��°�� �������� �մ� �Ÿ�
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

