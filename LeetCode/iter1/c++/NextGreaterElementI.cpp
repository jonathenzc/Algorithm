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
	vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
		//先构建nums的下标索引
		unordered_map<int, int> map;
		for (int i = 0; i < nums.size(); i++)
			map[nums[i]] = i;

		for (int i = 0; i < findNums.size(); i++)
		{
			int index = map[findNums[i]];
			while (index < nums.size() && nums[index] <= findNums[i])
				index++;

			if (index == nums.size())
				findNums[i] = -1;
			else
				findNums[i] = nums[index];
		}

		return findNums;
	}
};

void testPrint(vector<int> v)
{
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << " ";
}

int main(void)
{
	vector<int> nums1;
	nums1.push_back(4);
	nums1.push_back(1);
	nums1.push_back(2);

	vector<int> nums2;
	nums2.push_back(1);
	nums2.push_back(3);
	nums2.push_back(4);
	nums2.push_back(2);

	Solution s;
	vector<int> ret1 = s.nextGreaterElement(nums1, nums2);
	testPrint(ret1);

	cout << endl;

	vector<int> nums3;
	nums3.push_back(2);
	nums3.push_back(4);

	vector<int> nums4;
	for (int i = 1; i <= 4; i++)
		nums4.push_back(i);

	vector<int> ret2 = s.nextGreaterElement(nums3,nums4);
	testPrint(ret2);
	

	return 0;
}