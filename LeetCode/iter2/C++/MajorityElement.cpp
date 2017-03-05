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
	////方法1：空间O(n)，时间O(n)
	//int majorityElement(vector<int>& nums) {
	//	int maxCnt = 0;
	//	int candidate;

	//	unordered_map<int, int> numCntV;
	//	for (int num : nums)
	//	{
	//		numCntV[num]++;
	//		if (numCntV[num] > maxCnt)
	//		{
	//			maxCnt = numCntV[num];
	//			candidate = num;
	//		}
	//	}

	//	return candidate;
	//}

	//方法1：空间O(1)，时间O(n)
	int majorityElement(vector<int>& nums) {
		int candidate = nums[0];
		int cnt = 1;
		for (int i = 1; i < nums.size(); i++)
		{
			if (cnt == 0)
				candidate = nums[i];

			if (candidate == nums[i])
				cnt++;
			else
				cnt--;
		}

		return candidate;
	}
};

int main(void)
{
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(100);
	nums.push_back(100);
	nums.push_back(100);
	nums.push_back(100);
	nums.push_back(100);
	nums.push_back(100);
	nums.push_back(100);
	nums.push_back(100);
	nums.push_back(5);
	nums.push_back(5);
	nums.push_back(1);

	Solution s;
	cout << s.majorityElement(nums)<<endl;

	return 0;
}