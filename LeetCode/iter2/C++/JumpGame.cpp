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
	bool canJump(vector<int>& nums) {
		int target = nums.size() - 1;

		for (int i = target - 1; i >= 0; i--)
		{
			if (nums[i] + i >= target)
				target = i;
		}

		return target == 0;
	}
};

void testPrint(vector<int> v)
{
	Solution s;
	bool ret = s.canJump(v);
	if (ret)
		cout << "Can Jump\n";
	else
		cout << "Can't Jump\n";
}

int main(void)
{
	vector<int> v1;
	v1.push_back(3);
	v1.push_back(2);
	v1.push_back(1);
	v1.push_back(0);
	v1.push_back(4);
	
	vector<int> v2;
	v2.push_back(2);
	v2.push_back(3);
	v2.push_back(1);
	v2.push_back(1);
	v2.push_back(4);

	vector<int> v3;
	v3.push_back(2);
	v3.push_back(5);
	v3.push_back(0);
	v3.push_back(0);

	testPrint(v1);
	testPrint(v2);
	testPrint(v3);

	return 0;
}