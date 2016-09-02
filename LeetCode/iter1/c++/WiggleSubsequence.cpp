#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

int wiggleMaxLength(vector<int>& nums) {
	if (nums.size() <= 1)
		return nums.size();

	vector<int> dp(nums.size(),1); //dp[i]表示以nums[i]结尾的wiggle序列的长度
	vector<int> dirDp(nums.size(),0); //记录以nums[i]结尾的wiggle序列的下一个方向
	dirDp[0] = 0;

	int maxLen = 1;

	for (int i = 1; i < nums.size(); i++)
	{

		for (int j = i-1; j>=0; j--)
		{
			if (dirDp[j] == 0) //向上向下都可以
			{
				if (dp[i] < 2)
				{
					if (nums[i] > nums[j]) {
						dirDp[i] = -1;
						dp[i] = 2;
					}
					else if (nums[i] < nums[j]) {
						dirDp[i] = 1;
						dp[i] = 2;
					}
				}
			}
			else if (dirDp[j] == 1 && nums[i] > nums[j]) {
				if (dp[i] < dp[j] + 1) {
					dp[i] = dp[j] + 1;
					dirDp[i] = -1;
				}
			}
			else if (dirDp[j] == -1 && nums[i] < nums[j]) {
				if (dp[i] < dp[j] + 1) {
					dp[i] = dp[j] + 1;
					dirDp[i] = 1;
				}
			}
		}

		maxLen = max(maxLen,dp[i]);
	}

	return maxLen;
}

int main()
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(7);
	v1.push_back(4);
	v1.push_back(9);
	v1.push_back(2);
	v1.push_back(5);

	cout << wiggleMaxLength(v1) << endl;

	vector<int> v2;
	v2.push_back(1);
	v2.push_back(17);
	v2.push_back(5);
	v2.push_back(10);
	v2.push_back(13);
	v2.push_back(15);
	v2.push_back(10);
	v2.push_back(5);
	v2.push_back(16);
	v2.push_back(8);

	cout << wiggleMaxLength(v2) << endl;

	vector<int> v3;
	v3.push_back(1);
	v3.push_back(2);
	v3.push_back(3);
	v3.push_back(4);
	v3.push_back(5);
	v3.push_back(6);
	v3.push_back(7);
	v3.push_back(8);
	v3.push_back(9);
	v3.push_back(10);

	cout << wiggleMaxLength(v3) << endl;

	vector<int> v4;
	v4.push_back(2);
	v4.push_back(2);

	cout << wiggleMaxLength(v4) << endl;
	return 0;
}