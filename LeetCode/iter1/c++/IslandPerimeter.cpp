#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <queue>
#include <stack>

using namespace std;

class Solution {
public:
	int islandPerimeter(vector<vector<int>>& grid) {
		int perimeter = 0;

		for (int i = 0; i < grid.size(); i++)
		{
			for (int j = 0; j < grid[i].size(); j++)
			{
				if (grid[i][j] == 1) //陆地
				{
					if (i == 0 || grid[i - 1][j] == 0) //左边
						perimeter++;

					if (i == grid.size() - 1 || grid[i + 1][j] == 0) //右边
						perimeter++;

					if (j == 0 || grid[i][j-1] == 0) //上边
						perimeter++;

					if (j == grid[i].size()-1 || grid[i][j+1] == 0) //下边
						perimeter++;
				}
			}
		}

		return perimeter;
	}
};

int main(void)
{
	Solution s;

	vector<vector<int>> v;
	vector<int> v1;
	v1.push_back(0);
	v1.push_back(1);
	v1.push_back(0);
	v1.push_back(0);

	vector<int> v2;
	v2.push_back(1);
	v2.push_back(1);
	v2.push_back(1);
	v2.push_back(0);

	vector<int> v3;
	v3.push_back(0);
	v3.push_back(1);
	v3.push_back(0);
	v3.push_back(0);

	vector<int> v4;
	v4.push_back(1);
	v4.push_back(1);
	v4.push_back(0);
	v4.push_back(0);

	v.push_back(v1);
	v.push_back(v2);
	v.push_back(v3);
	v.push_back(v4);

	cout << s.islandPerimeter(v) << endl;


	vector<vector<int>> vv;
	vector<int> v5;
	v5.push_back(1);
	v5.push_back(0);

	vv.push_back(v5);

	cout << s.islandPerimeter(vv) << endl;
		
	return 0;
}