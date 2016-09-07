#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <sstream>
#include <unordered_map>

using namespace std;

class Solution {
public:

	int combinationSum4(vector<int>& nums, int target) {
		vector<int> dp(target+1,0);

		dp[0] = 1;

		for (int i = 1; i <= target; i++)
		{
			for (int j = 0; j < nums.size(); j++)
			{
				if (nums[j] <= i)
					dp[i] += dp[i-nums[j]];
			}
		}

		return dp[target];
	}
};

int main()
{
	Solution s;

	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);

	cout<<s.combinationSum4(v, 4);

	return 0;
}