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
	vector<int> searchRange(vector<int>& nums, int target) {
		int lowerBound = lowerBinarySearch(nums,target);
		v.push_back(lowerBound);

		if (lowerBound == -1)
			v.push_back(-1);
		else
		{
			int upperBound = upperBinarySearch(nums,target, lowerBound);
			v.push_back(upperBound);
		}

		return v;
	}
private:
	vector<int> v;

	int lowerBinarySearch(vector<int>& nums, int target)
	{
		int start = 0, end = nums.size() - 1;
		int candIndex = -1;
		while (start <= end)
		{
			int mid = start + (end - start) / 2;
			if (nums[mid] == target)
			{
				candIndex = mid;
				end = mid-1;
			}
			else if (nums[mid] > target)
				end = mid - 1;
			else
				start = mid + 1;
		}

		return candIndex;
	}

	int upperBinarySearch(vector<int>& nums, int target, int lowerIndex)
	{
		int start = lowerIndex, end = nums.size() - 1;
		int candIndex = -1;

		while (start <= end)
		{
			int mid = start + (end - start) / 2;
			if (nums[mid] == target)
			{
				candIndex = mid;
				start = mid + 1;
			}
			else if (nums[mid] > target)
				end = mid - 1;
		}

		return candIndex;
	}
};

void testPrint(vector<int> v,int target)
{
	Solution s;
	vector<int> ret = s.searchRange(v, target);

	cout << "Find " << target << endl;
	cout << "Range: ["<<ret[0]<<","<<ret[1]<<"]\n";

	cout << endl;
}

int main(void)
{
	vector<int> v;
	v.push_back(5);
	v.push_back(7);
	v.push_back(7);
	v.push_back(8);
	v.push_back(10);
	v.push_back(10);
	v.push_back(10);

	for (int i = 0; i < 13;i++)
		testPrint(v,i);

	return 0;
}