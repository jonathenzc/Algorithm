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

	int triangleNumber(vector<int>& nums) {
		sort(nums.begin(), nums.end());

		int cnt = 0;
		int l = 0, r = 0;
		for (int i = nums.size() - 1; i >= 2; i--) {
			l = 0;
			r = i - 1;
			while (l < r) {
				if (nums[l] + nums[r] > nums[i]) {
					cnt += r - l; //l+r>nums[i],说明l+1, l+2与r, nums[i]可以构成有效三角形
					r--;
				}
				else {
					l++;
				}
			}
		}

		return cnt;
	}
};

int main(void)
{
	Solution solution;
	vector<int> nums;
	nums.push_back(2);
	nums.push_back(2);
	nums.push_back(3);
	nums.push_back(4);

	cout << solution.triangleNumber(nums) << endl;

	return 0;
}