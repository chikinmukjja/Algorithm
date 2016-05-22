// code7.2.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <vector>
#include <iostream>

using namespace std;



class matrix
{
public:
	int row;
	int col;
	vector<vector<int>> value;

	matrix operator *(matrix &ref); // mat*mat

	matrix(int _row, int _col)
	{
		row = _row;
		col = _col;
		for (int i = 0; i < row; i++) {
			vector<int> tmp;
			for (int j = 0; j < col; j++)
			{
				tmp.push_back(i+j);
			}
			value.push_back(tmp);
		}
	}
};

matrix divideConquerMat(int n);
void showMat(matrix &x);

int main()
{
	int n = 100000;
	matrix x = divideConquerMat(n);
	showMat(x);
	
	matrix x1(2, 2);
	for (int i = 1; i < n; i++)
	{
		matrix y(2, 2);
		x1 = x1*y;
	}

	showMat(x1);

    return 0;
}

void showMat(matrix &x)
{
	for (int i = 0; i < x.row; i++)
	{
		for (int j = 0; j < x.col; j++)
		{
			cout << x.value[i][j]<<" ";
		}
		cout << endl;
	}
	cout << endl;
}


matrix divideConquerMat(int n)
{
	matrix x(2, 2);
	if (n == 1) {
		return x;
	}
	if (n % 2 == 1) {
		return divideConquerMat(n - 1)*x;
	}
	{
		matrix y = divideConquerMat(n / 2);
		return y*y;

	}
}

matrix matrix::operator*(matrix & ref)
{
	matrix x(this->row, this->row);
	
	for (int i = 0; i < this->row; i++)
	{
		for (int j = 0; j < ref.col; j++)
		{
			int sum = 0;
			for (int k = 0; k < this->col; k++)
			{
				sum = sum +	this->value[i][k] * ref.value[k][j];
			}
			x.value[i][j] = sum;

		}

	}

	return x;
}
