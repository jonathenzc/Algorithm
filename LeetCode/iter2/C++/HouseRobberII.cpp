#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int rob(vector<int>& nums) {
	if (nums.size() == 0)
		return 0;

	if (nums.size() == 1)
		return nums[0];

	if (nums.size() == 2)
		return max(nums[0],nums[1]);

	int *dp = new int[nums.size()];
	dp[0] = 0;
	dp[1] = nums[1];

	//不包含第一个，包含最后一个
	for (int i = 2; i < nums.size(); i++)
		dp[i] = max(dp[i-2]+nums[i],dp[i-1]);

	int candidate = dp[nums.size() - 1];

	//包含第一个，不包含最后一个
	dp[0] = nums[0];
	dp[1] = max(nums[0],nums[1]);
	for (int i = 2; i < nums.size() - 1; i++)
		dp[i] = max(dp[i-2]+nums[i],dp[i-1]);

	return max(candidate,dp[nums.size()-2]);
}


int main()
{
	vector<int> v;
	v.push_back(2);
	v.push_back(4);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);

	cout << rob(v)<<endl;

	vector<int> v1;
	v1.push_back(2);
	v1.push_back(2);
	v1.push_back(4);
	v1.push_back(3);
	v1.push_back(2);
	v1.push_back(5);

	cout << rob(v1)<<endl;

	vector<int> v2;
	v2.push_back(2);
	v2.push_back(1);
	v2.push_back(1);
	v2.push_back(1);

	cout << rob(v2) << endl;

	vector<int> v3;
	v3.push_back(1);
	v3.push_back(1);
	v3.push_back(2);
	v3.push_back(1);

	cout << rob(v3) << endl;

	return 0;
}