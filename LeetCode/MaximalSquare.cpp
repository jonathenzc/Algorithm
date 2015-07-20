#include <iostream>
#include <vector>

using namespace std;

int min(int a, int b, int c)
{
	if (a <= b && c >= a)//min a
		return a;
	else if (b <= a && c >= b)//min b
		return b;
	else if (c <= a && b >= c)//min c
		return c;
}

int maximalSquare(vector<vector<char>>& matrix)
{
	int m = matrix.size();
	if (m == 0)
		return 0;

	int n = matrix[0].size();
	if (n == 0)
		return 0;

	//length[i][j]表示以matrix(i,j)为右下角的正方形的最大边长
	int **length = new int*[m];
	for (int i = 0; i < m; i++)
		length[i] = new int[n];

	//初始化
	//第一列
	int max = 0;
	for (int i = 0; i < m; i++)
	{
		if (matrix[i][0] == '1')
		{
			length[i][0] = 1;
			max = 1;
		}
		else
			length[i][0] = 0;
	}

	//第一行
	for (int i = 0; i < n; i++)
	{
		if (matrix[0][i] == '1')
		{
			length[0][i] = 1;
			max = 1;
		}
		else
			length[0][i] = 0;
	}

	//length[i][j]取决于min(length[i-1][j-1],length[i][j-1],length[i-1][j])+1
	for (int i = 1; i < m; i++)
	{
		for (int j = 1; j < n; j++)
		{
			if (matrix[i][j] == '1')
			{
				length[i][j] = min(length[i - 1][j - 1], length[i][j - 1], length[i - 1][j]) + 1;
				if (length[i][j] > max)
					max = length[i][j];
			}
			else
				length[i][j] = 0;
		}
	}

	////输出length
	//for (int i = 0; i < m; i++)
	//{
	//	for (int j = 0; j < n; j++)
	//		cout << length[i][j] << " ";

	//	cout << endl;
	//}

	return max*max;
}

int main()
{
	vector<vector<char>> v;
	vector<char> v1;
	v1.push_back('0');
	v1.push_back('1');
	v1.push_back('1');
	v1.push_back('0');
	v1.push_back('1');

	v.push_back(v1);

	vector<char> v2;
	v2.push_back('1');
	v2.push_back('1');
	v2.push_back('0');
	v2.push_back('1');
	v2.push_back('0');

	v.push_back(v2);

	vector<char> v3;
	v3.push_back('0');
	v3.push_back('1');
	v3.push_back('1');
	v3.push_back('1');
	v3.push_back('0');

	v.push_back(v3);

	vector<char> v4;
	v4.push_back('1');
	v4.push_back('1');
	v4.push_back('1');
	v4.push_back('1');
	v4.push_back('0');

	v.push_back(v4);

	vector<char> v5;
	v5.push_back('1');
	v5.push_back('1');
	v5.push_back('1');
	v5.push_back('1');
	v5.push_back('1');

	v.push_back(v5);

	vector<char> v6(5,0);
	v.push_back(v6);

	cout << maximalSquare(v);

	return 0;
}