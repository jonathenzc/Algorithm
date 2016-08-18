#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int combinationSum4(vector<int>& nums, int target) {
	int *dp = new int[target+1];
	for (int i = 0; i <= target;i++)
		dp[i] = 0;

	for (int i = 1; i <= target; i++)
	{
		for (int j = 0; j < nums.size();j++)
		{
			if (i > nums[j])
				dp[i] += dp[i - nums[j]];
			else if (i == nums[j])
				dp[i] += 1;
		}
	}
	
	return dp[target];
}

int main()
{
	vector<int> nums;
	for (int i = 1; i <= 3;i++)
		nums.push_back(i);

	cout << combinationSum4(nums, 4)<<endl;


	vector<int> nums1;
	nums1.push_back(3);

	cout << combinationSum4(nums1, 2) << endl;


	vector<int> nums2;
	nums2.push_back(2);

	cout << combinationSum4(nums2, 3) << endl;

	return 0;
}