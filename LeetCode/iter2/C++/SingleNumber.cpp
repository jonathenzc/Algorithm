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
	int singleNumber(vector<int>& nums) {
		int ret=0;
		for (int num : nums)
			ret ^= num;
		
		return ret;
	}
};


int main(void)
{
	vector<int> v;
	v.push_back(0);
	v.push_back(1);
	v.push_back(3);
	v.push_back(0);
	v.push_back(1);
	v.push_back(3);
	v.push_back(2);

	Solution s;
	cout << s.singleNumber(v)<<endl;

	return 0;
}