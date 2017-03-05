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
	void moveZeroes(vector<int>& nums) {
		int nonZeroSize = 0;
		for (int num : nums)
		{
			if (num != 0)
				nums[nonZeroSize++] = num;
		}

		for (int i = nonZeroSize; i < nums.size(); i++)
			nums[i] = 0;
	}
};

int main(void)
{
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(0);
	nums.push_back(2);
	nums.push_back(0);
	nums.push_back(3);
	nums.push_back(0);
	nums.push_back(4);
	nums.push_back(0);
	nums.push_back(5);
	nums.push_back(0);
	nums.push_back(6);
	nums.push_back(0);
	nums.push_back(7);

	Solution s;

	cout << "Before removing zero\n";
	for (int num : nums)
		cout << num << " ";

	cout << "\nAfter removing zero\n";

	s.moveZeroes(nums);
	for (int num : nums)
		cout << num << " ";

	return 0;
}