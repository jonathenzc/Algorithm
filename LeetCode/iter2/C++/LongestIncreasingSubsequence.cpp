#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int lengthOfLIS(vector<int>& nums) {
	int *dp = new int[nums.size()];
	for (int i = 0; i < nums.size(); i++)
		dp[i] = 1;

	//dp[i]表示以i为节点的最长序列

	int maxLength = 0;

	for (int i=0;i<nums.size();i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (nums[j] < nums[i])
				dp[i] = max(dp[i],dp[j]+1);
		}

		maxLength = max(maxLength,dp[i]);
	}

	return maxLength;
}

int main()
{
	vector<int> nums;
	nums.push_back(10);
	nums.push_back(9);
	nums.push_back(2);
	nums.push_back(5);
	nums.push_back(3);
	nums.push_back(7);
	nums.push_back(101);
	nums.push_back(18);

	cout << lengthOfLIS(nums) << endl;


	vector<int> nums1;
	nums1.push_back(1);
	nums1.push_back(3);
	nums1.push_back(6);
	nums1.push_back(7);
	nums1.push_back(9);
	nums1.push_back(4);
	nums1.push_back(10);
	nums1.push_back(5);
	nums1.push_back(6);

	cout << lengthOfLIS(nums1) << endl;

	return 0;
}