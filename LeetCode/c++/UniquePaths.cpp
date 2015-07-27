#include <iostream>

using namespace std;

int uniquePaths(int m, int n) 
{
	if (m <= 0 || n <= 0)
		return 0;

	//path[i][j]表示到达坐标(i,j)的路径数
	int **path = new int*[m];
	for (int i = 0; i < m; i++)
		path[i] = new int[n];

	//初始化，第一行和第一列都为1
	//第一列
	for (int i = 0; i < m;i++)
		path[i][0] = 1;

	//第一行
	for (int i = 0; i < n; i++)
		path[0][i] = 1;

	for (int i = 1; i < m; i++)
	{
		for (int j = 1; j < n; j++)
			path[i][j] = path[i-1][j] + path[i][j-1];
	}

	return path[m-1][n-1];
}

int main()
{
	cout << uniquePaths(3,7);

	return 0;
}