// code6.4.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
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
	int C; //test case ��
	int n; //�л� ��
	int m; //ģ�� ���� ��
	vector<set<int>> mate;
	

	//�Է� 1
	cin >> C;

	for (int Ci = 0; Ci < C; Ci++)
	{
		//�Է�2
		cin >> n;
		cin >> m;
		
		mate.clear();

		for (int mi = 0; mi < m; mi++)
		{
			set<int> tmp;
			int f1 =0;
			int f2 =0;
			//�Է�3
			cin >> f1;
			cin >> f2;

			tmp.insert(f1);
			tmp.insert(f2);
			
			mate.push_back(tmp);
		}

		//���� �ذ�
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

	//����� ����
	if (n == 0&&!friendCase.empty())return 0;
	//ģ�� �� ����
	//if (mate.size() == 0)return 0;
	// ���� �������
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
		
		//if(mate.begin() + mi != mate.end())showSet(*(mate.begin()+mi)); ����׿�

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
