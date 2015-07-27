#include <iostream>
#include <vector>

using namespace std;

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) 
{
	int m = obstacleGrid.size();
	if (m == 0)
		return 0;

	int n = obstacleGrid[0].size();
	if (n == 0)
		return 0;

	int **path = new int*[m];
	for (int i = 0; i < m; i++)
		path[i] = new int[n];

	//初始化
	//第一列
	bool oneFound = false;
	for (int i = 0; i < m; i++)
	{
		if (oneFound)
			path[i][0] = 0;
		else
		{
			if (obstacleGrid[i][0] == 1)
			{
				oneFound = true;
				path[i][0] = 0;
			}
			else
				path[i][0] = 1;
		}
	}

	//第一行
	oneFound = false;
	for (int i = 0; i < n; i++)
	{
		if (oneFound)
			path[0][i] = 0;
		else
		{
			if (obstacleGrid[0][i] == 1)
			{
				oneFound = true;
				path[0][i] = 0;
			}
			else
				path[0][i] = 1;
		}
	}

	for (int i = 1; i < m; i++)
	{
		for (int j = 1; j < n; j++)
		{
			if (obstacleGrid[i][j] == 1)
				path[i][j] = 0;
			else
				path[i][j] = path[i - 1][j] + path[i][j-1];
		}
	}

	return path[m - 1][n - 1];
}

int main()
{
	vector < vector<int>> v;
	vector<int> s(4,0);
	v.push_back(s);
	 
	vector<int> s1;
	s1.push_back(0);
	s1.push_back(1);
	s1.push_back(0);
	s1.push_back(0);
	v.push_back(s1);

	vector < int > s2(4,0);
	v.push_back(s2);

	vector<int> s3(2,0);
	s3.push_back(1);
	s3.push_back(0);
	v.push_back(s3);

	vector < int > s4(4,0);
	v.push_back(s4);

	cout << uniquePathsWithObstacles(v);

	return 0;
}