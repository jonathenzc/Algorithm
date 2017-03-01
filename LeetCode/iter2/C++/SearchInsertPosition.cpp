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
	int searchInsert(vector<int>& nums, int target) {
		int start = 0, end = nums.size() - 1;
		int candIndex = -1;
		while (start <= end)
		{
			int mid = start+(end-start) / 2;
			if (nums[mid] == target)
			{
				candIndex = mid;
				break;
			}
			else if (nums[mid] > target)
				end = mid - 1;
			else
				start = mid + 1;
		}

		if(candIndex == -1)
			candIndex = start;

		return candIndex;
	}
};

int main(void)
{
	vector<int> v;
	v.push_back(1);
	v.push_back(3);
	v.push_back(5);
	v.push_back(7);

	Solution s;
	for (int i = -3; i < 10; i++)
		cout << i<<" "<<s.searchInsert(v, i) << endl;


	return 0;
}