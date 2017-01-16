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
	vector<int> findDisappearedNumbers(vector<int>& nums) {
		vector<int> ret;

		for (int i = 0; i < nums.size(); i++)
		{
			int index = abs(nums[i]) - 1;
			if (nums[index] > 0)
				nums[index] = -nums[index];
		}

		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[i] > 0)
				ret.push_back(i+1);
		}

		return ret;
	}
};

void testPrint(vector<string> v)
{
	for (auto s : v)
		cout << s << endl;
}

int main(void)
{
	Solution s;
	
	vector<int> v;
	v.push_back(4);
	v.push_back(3);
	v.push_back(2);
	v.push_back(7);
	v.push_back(8);
	v.push_back(2);
	v.push_back(3);
	v.push_back(1);
	
	vector<int> ret = s.findDisappearedNumbers(v);

	for (auto num : ret)
		cout << num << endl;

	return 0;
}