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
		int curOnes = 0;
		int maxOnes = 0;

		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[i] == 0)
			{
				maxOnes = max(maxOnes, curOnes);
				curOnes = 0;
			}
			else
				curOnes++;
		}

		maxOnes = max(maxOnes, curOnes);

		return maxOnes;
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
	v.push_back(1);
	v.push_back(1);
	v.push_back(1);
	v.push_back(1);
	v.push_back(1);
	v.push_back(1);

	cout << s.findMaxConsecutiveOnes(v);

	return 0;
}