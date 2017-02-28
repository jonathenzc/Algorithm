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
	int search(vector<int>& nums, int target) {
		if (nums.size() < 1)
			return -1;

		//找到最小值的下标
		int minIndex = findMinIndex(nums);

		if (target == nums[nums.size() - 1])
			return nums.size() - 1;
		else if (target > nums[nums.size() - 1])
			return binarySearch(nums, target, 0, minIndex - 1);
		else
			return binarySearch(nums,target,minIndex,nums.size()-1);
	}
private:
	int findMinIndex(vector<int>& nums) {
		int start = 0, end = nums.size() - 1;

		while (start < end)
		{
			int mid = start + (end - start) / 2;
			if (nums[mid] > nums[end])
				start = mid + 1;
			else
				end = mid;
		}

		return start;
	}

	int binarySearch(vector<int> &nums, int target, int start, int end)
	{
		int index = -1;
		while (start <= end)
		{
			int mid = start + (end - start) / 2;
			if (nums[mid] == target)
			{
				index = mid;
				break;
			}
			else if (nums[mid] > target)
				end = mid - 1;
			else
				start = mid + 1;
		}

		return index;
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