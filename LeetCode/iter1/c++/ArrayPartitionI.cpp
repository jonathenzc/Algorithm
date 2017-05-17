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
	int arrayPairSum(vector<int>& nums) {
		sort(nums.begin(),nums.end());

		int sum = 0,i=0;
		while(i<nums.size())
		{
			sum += nums[i];
			i += 2;
		}

		return sum;
	}
};

int main(void)
{
	Solution s;
	vector<int> v;
	v.push_back(1);
	v.push_back(4);
	v.push_back(3);
	v.push_back(2);

	cout << s.arrayPairSum(v) << endl;


	return 0;
}