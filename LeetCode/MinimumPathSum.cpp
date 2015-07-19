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

	//��һ��
	for (int i = 1; i < n; i++)
		grid[0][i] += grid[0][i - 1];
	
	//��һ��
	for (int i = 1; i < m; i++)
		grid[i][0] += grid[i-1][0];

	//grid[i][j]��ʾ����grid[i][j]����С·�����Ƕ���
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