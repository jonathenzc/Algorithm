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
	vector<int> twoSum(vector<int>& nums, int target) {
		unordered_map<int, int> numMap;
		numMap[nums[0]] = 1;

		vector<int> retV;

		for (int i = 1; i < nums.size(); i++)
		{
			if (numMap[target - nums[i]] != 0)
			{
				retV.push_back(numMap[target-nums[i]]-1);
				retV.push_back(i);
				break;
			}

			numMap[nums[i]] = i + 1;
		}

		return retV;
	}
};

int main(void)
{
	vector<int> num1;
	num1.push_back(2);
	num1.push_back(7);
	num1.push_back(11);
	num1.push_back(15);

	Solution s;
	vector<int> retV = s.twoSum(num1,9);

	for (int num : retV)
		cout << num << " ";


	return 0;
}