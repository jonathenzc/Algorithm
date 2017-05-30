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
	int findMaxConsecutiveOnes(vector<int>& nums) {
		int index = 0, preIndex = 0;
		int len = 0;

		while (index < nums.size())
		{
			if (nums[index] == 0)
			{
				len = max(len, index - preIndex);
				preIndex = index + 1;
			}

			index++;
		}

		len = max(len, int(nums.size()-preIndex));

		return len;
	}
};

int main(void)
{
	Solution s;

	vector<int> v0;
	v0.push_back(1);
	v0.push_back(1);
	v0.push_back(1);
	v0.push_back(1);
	cout << s.findMaxConsecutiveOnes(v0) << endl;

	vector<int> v1;
	v1.push_back(1);
	cout << s.findMaxConsecutiveOnes(v1) << endl;
		
	vector<int> v2;
	v2.push_back(0);
	cout << s.findMaxConsecutiveOnes(v2) << endl;

	vector<int> v3;
	v3.push_back(0);
	v3.push_back(0);
	v3.push_back(0);
	v3.push_back(0);
	cout << s.findMaxConsecutiveOnes(v3) << endl;


	vector<int> v4;
	v4.push_back(1);
	v4.push_back(1);
	v4.push_back(0);
	v4.push_back(1);
	v4.push_back(1);
	v4.push_back(1);
	cout << s.findMaxConsecutiveOnes(v4) << endl;

	vector<int> v5;
	v5.push_back(1);
	v5.push_back(1);
	v5.push_back(0);
	v5.push_back(0);
	v5.push_back(1);
	v5.push_back(1);
	v5.push_back(1);
	cout << s.findMaxConsecutiveOnes(v5) << endl;


	vector<int> v6;
	v6.push_back(1);
	v6.push_back(1);
	v6.push_back(1);
	v6.push_back(0);
	v6.push_back(1);
	v6.push_back(1);
	v6.push_back(0);
	v6.push_back(0);
	cout << s.findMaxConsecutiveOnes(v6) << endl;

	return 0;
}