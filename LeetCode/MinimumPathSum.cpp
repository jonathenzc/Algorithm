#include <iostream>
#include <vector>

using namespace std;

int min(int a, int b)
{
	if (a < b)
		return a;
	else
		return b;
}

int minPathSum(vector<vector<int>>& grid) 
{
	int m = grid.size();
	if (m == 0)
		return 0;
	
	int n = grid[0].size();
	if (n == 0)
		return 0;

	//第一行
	for (int i = 1; i < n; i++)
		grid[0][i] += grid[0][i - 1];
	
	//第一列
	for (int i = 1; i < m; i++)
		grid[i][0] += grid[i-1][0];

	//grid[i][j]表示到达grid[i][j]的最小路径和是多少
	for (int i = 1; i < m; i++)
	{
		for (int j = 1; j < n; j++)
			grid[i][j] += min(grid[i-1][j],grid[i][j-1]);
	}

	return grid[m-1][n-1];
}

int main()
{
	return 0;
}