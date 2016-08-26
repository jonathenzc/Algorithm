#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

int lengthOfLIS(vector<int>& nums) {
	if (nums.size() == 0)
		return 0;

	int *dp = new int[nums.size()];
	for (int i = 0; i < nums.size(); i++)
		dp[i] = 1;

	int ret = 1;

	for (int i = 1; i < nums.size(); i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (nums[i] > nums[j])
				dp[i] = max(dp[j] + 1, dp[i]);
		}

		ret = max(ret, dp[i]);
	}

	return ret;
}

int main()
{
	vector<int> v;
	v.push_back(10);
	v.push_back(9);
	v.push_back(2);
	v.push_back(5);
	v.push_back(3);
	v.push_back(7);	
	v.push_back(101);
	v.push_back(18);

	cout << lengthOfLIS(v) << endl;

		
	return 0;
}