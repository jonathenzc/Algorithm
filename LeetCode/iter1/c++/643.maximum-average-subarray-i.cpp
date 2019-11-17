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
	double findMaxAverage(vector<int>& nums, int k) {
		double sum = 0;
		for (int i = 0; i < nums.size() && i < k; i++) {
			sum += nums[i];
		}

		double retMax = sum;
		for (int i = k; i < nums.size(); i++) {
			sum += nums[i] - nums[i - k];//window size k
			retMax = max(retMax, sum);
		}

		return retMax / k;
	}
};

int main()
{
	vector<int> num;
	num.push_back(1);
	num.push_back(12);
	num.push_back(-5);
	num.push_back(-6);
	num.push_back(50);
	num.push_back(3);

	Solution s;
	cout << s.findMaxAverage(num, 4) << endl;

	return 0;
}