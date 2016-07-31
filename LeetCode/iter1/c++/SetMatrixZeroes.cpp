#include <iostream>
#include <vector>

using namespace std;

void setZeroes(vector<vector<int>>& matrix) {
	//用第一行和第一列来记录matrix[i][j]是0的情况
	bool is1stRowHasZero = false, is1stColHasZero = false; //因为用第一行和第一列做了记录，那么需要变量来记录第一行和第一列是0的情况

	//将0的位置映射到第一行和第一列
	for (int i = 0; i < matrix.size(); i++)
	{
		for (int j = 0; j < matrix[i].size(); j++)
		{
			if (matrix[i][j] == 0)
			{
				matrix[i][0] = 0; //映射到第i行
				matrix[0][j] = 0; //映射到第i列
				if (i == 0) //第1行是0
					is1stRowHasZero = true;

				if (j == 0) //第1列是0
					is1stColHasZero = true;
			}
		}
	}

	//从第二行和第二列开始
	for (int i = 1; i < matrix.size(); i++)
	{
		for (int j = 1; j < matrix[i].size(); j++)
		{
			if (matrix[i][0] == 0 || matrix[0][j] == 0) //第i行或第j列是0
				matrix[i][j] = 0;
		}
	}

	//第一行
	if (is1stRowHasZero)
	{
		for (int j = 0; j < matrix[0].size(); j++)
			matrix[0][j] = 0;
	}

	//第一列
	if (is1stColHasZero)
	{
		for (int i = 0; i < matrix.size(); i++)
			matrix[i][0] = 0;
	}
}

void testPrint(vector<vector<int>> v)
{
	for (int i = 0; i < v.size(); i++)
	{
		for (int j = 0; j < v[i].size(); j++)
			cout << v[i][j] << " ";

		cout << endl;
	}
}

int main()
{
	vector<vector<int>> v;


	vector<int> v1;
	v1.push_back(1);
	v1.push_back(1);
	v1.push_back(1);
	v1.push_back(1);
	v1.push_back(1);

	vector<int> v2;
	v2.push_back(1);
	v2.push_back(1);
	v2.push_back(1);
	v2.push_back(1);
	v2.push_back(1);

	vector<int> v3;
	v3.push_back(0);
	v3.push_back(1);
	v3.push_back(0);
	v3.push_back(1);
	v3.push_back(1);

	vector<int> v4;
	v4.push_back(1);
	v4.push_back(1);
	v4.push_back(1);
	v4.push_back(1);
	v4.push_back(1);

	v.push_back(v1);
	v.push_back(v2);
	v.push_back(v3);
	v.push_back(v4);

	testPrint(v);

	cout << "after set zero\n";

	setZeroes(v);

	testPrint(v);

	return 0;
}