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
	bool containsDuplicate(vector<int>& nums) {
		unordered_map<int, int> numCntMap;

		for (int num : nums)
		{
			if (numCntMap[num] == 1)
				return true;

			numCntMap[num]++;
		}

		return false;
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
	if (s.containsDuplicate(nums))
		cout << "Contain\n";
	else
		cout << "Not Contain\n";

	return 0;
}