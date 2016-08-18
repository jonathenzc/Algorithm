#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
	int m = obstacleGrid.size();
	int n = 0;
	if (m > 0)
		n = obstacleGrid[0].size();
	else
		return 0;

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (obstacleGrid[i][j] == 1)
				obstacleGrid[i][j] = -1;
		}
	}

	bool obstacleFound = false;
	for (int i = 0; i < m; i++)
	{
		if (!obstacleFound)
		{
			if (obstacleGrid[i][0] == -1)
				obstacleFound = true;
			else
				obstacleGrid[i][0] = 1;
		}
		else
			obstacleGrid[i][0] = -1;
	}

	obstacleFound = false;
	for (int i = 0; i < n; i++)
	{
		if (!obstacleFound)
		{
			if (obstacleGrid[0][i] == -1)
				obstacleFound = true;
			else
				obstacleGrid[0][i] = 1;
		}
		else
			obstacleGrid[0][i] = -1;
	}

	for (int i = 1; i < m; i++)
	{
		for (int j = 1; j < n; j++)
		{
			if (obstacleGrid[i][j] != -1)
			{ 
				if (obstacleGrid[i - 1][j] != -1)
					obstacleGrid[i][j] += obstacleGrid[i - 1][j];

				if (obstacleGrid[i][j - 1] != -1)
					obstacleGrid[i][j] += obstacleGrid[i][j - 1];

				if (obstacleGrid[i - 1][j] == -1 && obstacleGrid[i][j - 1] == -1)
					obstacleGrid[i][j] = 0;
			}
		}
	}

	if (obstacleGrid[m - 1][n - 1] == -1)
		obstacleGrid[m - 1][n - 1] = 0;

	return obstacleGrid[m - 1][n - 1];
}

int main()
{
	vector<vector<int>> v;

	vector<int> v1;
	v1.push_back(0);
	v1.push_back(0);
	v1.push_back(0);

	vector<int> v2;
	v2.push_back(0);
	v2.push_back(1);
	v2.push_back(0);

	vector<int> v3;
	v3.push_back(0);
	v3.push_back(0);
	v3.push_back(0);

	v.push_back(v1);
	v.push_back(v2);
	v.push_back(v3);

	cout << uniquePathsWithObstacles(v)<<endl;


	return 0;
}