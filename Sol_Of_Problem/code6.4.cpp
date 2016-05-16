// code6.4.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <set>

using namespace std;

int numMatch(int n, vector<set<int>> mate, set<int> friendCase,int& num);
void showSet(set<int> x);
int main()
{
	int C; //test case 수
	int n; //학생 수
	int m; //친구 쌍의 수
	vector<set<int>> mate;
	

	//입력 1
	cin >> C;

	for (int Ci = 0; Ci < C; Ci++)
	{
		//입력2
		cin >> n;
		cin >> m;
		
		mate.clear();

		for (int mi = 0; mi < m; mi++)
		{
			set<int> tmp;
			int f1 =0;
			int f2 =0;
			//입력3
			cin >> f1;
			cin >> f2;

			tmp.insert(f1);
			tmp.insert(f2);
			
			mate.push_back(tmp);
		}

		//문제 해결
		set<int> friendCase;
		int num=0;

		for (int i = 0; i < n; i++)friendCase.insert(i);
		numMatch(n, mate, friendCase, num);
		cout << num << endl;

	}
    return 0;
}

int numMatch(int n,vector<set<int>> mate,set<int> friendCase,int& num)
{

	//사람이 없음
	if (n == 0&&!friendCase.empty())return 0;
	//친구 쌍 없음
	//if (mate.size() == 0)return 0;
	// 쌍이 만들어짐
	if (friendCase.empty()) {
		cout << " hear ";
		num++;
		return 1;
	}
	int m = mate.size();
	for (int mi = 0; mi < m; mi++)
	{
		
		vector<set<int>> nextMate = mate;
		set<int> nextFriendCase = friendCase;

		if(nextFriendCase.find(*mate[mi].begin())!= nextFriendCase.end())
			nextFriendCase.erase(nextFriendCase.find(*mate[mi].begin()));
		if (nextFriendCase.find(*(++mate[mi].begin())) != nextFriendCase.end())
			nextFriendCase.erase(nextFriendCase.find(*(++mate[mi].begin())));
		
		//if(mate.begin() + mi != mate.end())showSet(*(mate.begin()+mi)); 디버그용

		nextMate.erase(nextMate.begin(),nextMate.begin()+mi+1);
		
		numMatch(n - 2, nextMate, nextFriendCase,num);
		
	}
	cout << endl;
	return 0;
	
}

void showSet(set<int> x)
{
	set<int>::iterator iter = x.begin();
	cout << "{ ";
	for (; iter != x.end(); iter++)cout << *iter;
	cout <<" } ";

}
