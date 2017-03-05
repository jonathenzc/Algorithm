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
	bool search(vector<int>& nums, int target) {
		if (nums.size() < 1)
			return false;

		//找到最小值的下标
		int minIndex = findMinIndex(nums);

		if (target == nums[nums.size() - 1])
			return true;
		else if (target > nums[nums.size() - 1])
			return binarySearch(nums, target, 0, minIndex - 1);
		else
			return binarySearch(nums,target,minIndex,nums.size()-1);
	}
private:
	//int findMinIndex(vector<int>& nums) {
	//	int start = 0, end = nums.size() - 1;

	//	while (start < end)
	//	{
	//		int mid = start + (end - start) / 2;
	//		if (nums[mid] > nums[end])
	//			start = mid + 1;
	//		else if (nums[mid] < nums[end])
	//			end = mid;
	//		else
	//			end--;
	//	}

	//	return start;
	//}

	//找到拐角的下标
	int findMinIndex(vector<int>& nums) {
		int preNum = nums[0];

		for (int i = 1; i<nums.size(); i++)
		{
			if (nums[i] >= preNum)
				preNum = nums[i];
			else
				return i;
		}

		return 0;
	}

	bool binarySearch(vector<int> &nums, int target, int start, int end)
	{
		bool isFound = false;
		while (start <= end)
		{
			int mid = start + (end - start) / 2;
			if (nums[mid] == target)
			{
				isFound = true;
				break;
			}
			else if (nums[mid] > target)
				end = mid - 1;
			else
				start = mid + 1;
		}

		return isFound;
	}
};

int main(void)
{
	vector<int> v;
	v.push_back(4);
	v.push_back(5);
	v.push_back(6);
	v.push_back(7);
	v.push_back(0);
	v.push_back(1);
	v.push_back(2);

	Solution s;
	for (int i = -3; i < 11; i++)
		cout << i << " " << s.search(v, i) << endl;

	//cout << 0 << " " << s.search(v, 0) << endl;

	return 0;
}