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
	vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
		int oldR = nums.size();
		int oldC = nums[0].size();

		if (oldR*oldC != r*c)
			return nums;

		vector<vector<int>> v(r, vector<int>(c, 0));

		int preI = 0, preJ = 0;
		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				v[i][j] = nums[preI][preJ];

				preJ++;

				if (preJ == oldC)
				{
					preI++;
					preJ = 0;
				}
			}
		}

		return v;
	}
};

void testPrint(vector<vector<int>> v)
{
	for (auto tmpV : v)
	{
		for (int num : tmpV)
			cout << num << " ";

		cout << endl;
	}
}

void test(vector<vector<int>> v, int r, int c)
{
	cout << "row[" << r << "] col[" << c << "]\n";

	Solution s;
	vector<vector<int>> ret = s.matrixReshape(v, r, c);

	testPrint(ret);
}

int main(void)
{
	vector<vector<int>> v;
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);

	vector<int> v2;
	v2.push_back(4);
	v2.push_back(3);

	v.push_back(v1);
	v.push_back(v2);

	test(v, 2, 2);
	test(v, 1, 4);
	test(v, 4, 1);


	return 0;
}