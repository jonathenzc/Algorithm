#include <iostream>
#include <vector>

using namespace std;

int minSubArrayLen(int s, vector<int>& nums) {
	int sum = 0, left=0, right=0, minLen = INT_MAX;

	while (right < nums.size())
	{
		//先找到一个候选的子列表
		while (sum < s && right < nums.size())
		{
			sum += nums[right];
			right++;
		}

		//逐步减少元素
		while (left < right && sum-nums[left] >= s)
		{
			sum = sum - nums[left];
			left++;
		}

		if (sum >= s)
		{
			//记录长度的最小值
			if (minLen > right - left)
				minLen = right - left;

			sum = sum - nums[left];
			left++;
		}
	}

	if (minLen == INT_MAX)
		minLen = 0;

	return minLen;
}
void testPrint(int s,vector<int>& nums)
{
	cout << minSubArrayLen(s,nums)<<endl;
}

int main()
{
	vector<int> v1;
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(4);
	v1.push_back(3);

	testPrint(100,v1);

	return 0;
}