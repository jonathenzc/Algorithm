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
	int removeDuplicates(vector<int>& nums) {
		if (nums.size() < 2)
			return nums.size();

		int uniqueSize = 1;
		int preNum = nums[0];
		int index = 1;

		while (index < nums.size())
		{
			if (nums[index] != preNum)
			{
				preNum = nums[index];
				nums[uniqueSize++] = nums[index];
			}

			index++;
		}

		return uniqueSize;
	}
};

int main(void)
{
	vector<int> v;
	v.push_back(1);
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);

	Solution s;
	cout << s.removeDuplicates(v) << endl;

	for (int num : v)
		cout << num << " ";

	cout << endl;

	return 0;
}