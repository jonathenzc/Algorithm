#include <iostream>
#include <vector>

using namespace std;

int combinationSum4(vector<int>& nums, int target) {

	int *dp = new int[target+1];
	for(int i=0;i<=target;i++)
		dp[i] = 0;

	for (int i = 0; i < nums.size(); i++)
	{
		if(nums[i]<= target)
			dp[nums[i]] = 1;
	}

	for (int i = 1; i <= target; i++)
	{
		for (int j = 0; j < nums.size(); j++)
		{
			if (i - nums[j] >= 0)
				dp[i] += dp[i-nums[j]];
		}
	}

	return dp[target];
}

void testPrint(vector<int>& nums, int target)
{
	cout << combinationSum4(nums,target) << endl;
}

int main()
{
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(4);

	testPrint(nums,32);

	return 0;
}