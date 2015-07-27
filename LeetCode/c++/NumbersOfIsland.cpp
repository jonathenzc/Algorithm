#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<vector<char>>& grid,int i, int j)
{
	if (i >= 0 && i < grid.size() && j >= 0 && j < grid[i].size())
	{
		if (grid[i][j] == '1')
		{
			grid[i][j] = '2';//2表示访问过了
			//访问grid[i][j]上下左右的四个位置
			dfs(grid, i - 1, j);
			dfs(grid, i + 1, j);
			dfs(grid, i, j - 1);
			dfs(grid, i, j + 1);
		}
	}
}

int numIslands(vector<vector<char>>& grid)
{
	int cnt = 0;

	for (int i = 0; i < grid.size(); i++)
	{
		for (int j = 0; j < grid[i].size(); j++)
		{
			if (grid[i][j] == '1')
			{
				dfs(grid, i,j);
				cnt++;
			}
		}
	}

	return cnt;
}

void initiateIslandV1(vector<vector<char>>& v)
{
	vector<char> temp;
	temp.push_back('1');
	temp.push_back('1');
	temp.push_back('0');
	temp.push_back('0');
	temp.push_back('0');

	v.push_back(temp);
	v.push_back(temp);
	temp.clear();

	temp.push_back('0');
	temp.push_back('0');
	temp.push_back('1');
	temp.push_back('0');
	temp.push_back('0');

	v.push_back(temp);
	temp.clear();

	temp.push_back('0');
	temp.push_back('0');
	temp.push_back('0');
	temp.push_back('1');
	temp.push_back('1');

	v.push_back(temp);
}

void initiateIslandV(vector<vector<char>>& v)
{
	vector<char> temp;
	temp.push_back('1');
	temp.push_back('1');
	temp.push_back('1');
	temp.push_back('1');
	temp.push_back('0');

	v.push_back(temp);
	temp.clear();

	temp.push_back('1');
	temp.push_back('1');
	temp.push_back('0');
	temp.push_back('1');
	temp.push_back('0');

	v.push_back(temp);
	temp.clear();

	temp.push_back('1');
	temp.push_back('1');
	temp.push_back('0');
	temp.push_back('0');
	temp.push_back('0');

	v.push_back(temp);
	temp.clear();

	temp.push_back('0');
	temp.push_back('0');
	temp.push_back('0');
	temp.push_back('0');
	temp.push_back('0');

	v.push_back(temp);
}

int main()
{
	vector<vector<char>> v;
	vector<vector<char>> v1;

	initiateIslandV(v);
	initiateIslandV1(v1);

	//输出输入的两个“岛”
	//for (int i = 0; i < v.size(); i++)
	//{
	//	for (int j = 0; j < v[i].size(); j++)
	//		cout << v[i][j];

	//	cout << endl;
	//}

	//cout << endl;

	//for (int i = 0; i < v1.size(); i++)
	//{
	//	for (int j = 0; j < v1[i].size(); j++)
	//		cout << v1[i][j];

	//	cout << endl;
	//}

	cout << numIslands(v) << endl
		<< numIslands(v1) << endl;

	return 0;
}