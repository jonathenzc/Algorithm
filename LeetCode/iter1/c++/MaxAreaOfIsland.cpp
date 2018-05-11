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
	int maxAreaOfIsland(vector<vector<int>>& grid) {
		int ret = 0;

		for (int i = 0; i < grid.size(); i++) {
			for (int j = 0; j < grid[i].size(); j++) {
				ret = max(ret, traverse(grid, i, j));
			}
		}

		return ret;
	}
private:
	int traverse(vector<vector<int>>& grid, int i, int j) {
		if (i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size() && grid[i][j] == 1) {
			grid[i][j] = 0;
			return 1 + traverse(grid, i - 1, j) + traverse(grid, i, j - 1) + traverse(grid, i + 1, j) + traverse(grid, i, j + 1);
		}

		return 0;
	}
};

int main(void)
{
	vector<int> v;
	for (int i = 0; i < 8; i++) {
		v.push_back(0);
	}

	vector<vector<int>> V;
	V.push_back(v);
	Solution s;
	cout << s.maxAreaOfIsland(V) << endl;

	return 0;
}