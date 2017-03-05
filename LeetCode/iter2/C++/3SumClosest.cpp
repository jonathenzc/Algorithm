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
	int threeSumClosest(vector<int>& nums, int target) {
		sort(nums.begin(), nums.end());

		int i = 0;
		candidate = INT_MAX / 2;

		while (i < nums.size())
		{
			int a = nums[i];

			findBC(a, i, nums, target);

			while (i < nums.size() && nums[i] == a)
				i++;
		}

		return candidate;
	}

private:
	int candidate;
	bool isEqual;

	void findBC(int a, int bIndex, vector<int>& nums, int target)
	{
		int start = bIndex + 1, end = nums.size() - 1;
		while (start < end)
		{
			int diff = target - nums[start] - nums[end] - a;

			if (diff > 0)
				start++;
			else
				end--;

			if (abs(diff) < abs(target - candidate))
				candidate = target - diff;
		}
	}
};

int main(void)
{
	vector<int> v;
	v.push_back(0);
	v.push_back(2);
	v.push_back(1);
	v.push_back(-3);

	Solution s;
	cout << s.threeSumClosest(v, 1) << endl;

	return 0;
}