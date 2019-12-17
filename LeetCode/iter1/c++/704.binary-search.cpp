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
		int start = 0, end = nums.size(), mid = -1, targetIdx = -1;
		while (start < end) {
			mid = start + (end - start) / 2;
			if (nums[mid] == target) {
				targetIdx = mid;
				break;
			}
			else if (nums[mid] < target) {
				start = mid + 1;
			}
			else {
				end = mid;
			}
		}

		return targetIdx;
	}
};

int main(void)
{
	vector<int> nums1;
	nums1.push_back(-1);
	nums1.push_back(0);
	nums1.push_back(3);
	nums1.push_back(5);
	nums1.push_back(9);
	nums1.push_back(12);

	Solution s;
	int i = -5;
	while (i < 15) {
		cout << i << " " << s.search(nums1, i) << endl;
		i++;
	}

	return 0;
}