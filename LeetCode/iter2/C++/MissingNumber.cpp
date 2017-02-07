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
	int missingNumber(vector<int>& nums) {
		long long candidateSum = (1 + nums.size())*nums.size() / 2;

		long long sum = 0;
		for (int num : nums)
			sum += num;

		return candidateSum - sum;
	}
};


int main(void)
{
	vector<int> v;
	v.push_back(0);
	v.push_back(1);
	v.push_back(3);

	Solution s;
	cout << s.missingNumber(v)<<endl;

	return 0;
}