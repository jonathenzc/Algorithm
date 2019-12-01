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
	int findShortestSubArray(vector<int>& nums) {
		unordered_map<int, int> num2FirstIdx, num2Cnt;
		int ret = INT_MAX, maxDegree = 0;
		for (int i = 0; i < nums.size(); i++) {
			if (num2FirstIdx.count(nums[i]) == 0) {
				num2FirstIdx[nums[i]] = i;
			}

			int degree = num2Cnt[nums[i]] + 1;
			num2Cnt[nums[i]] = degree;
			if (degree > maxDegree) {
				maxDegree = degree;
				ret = i - num2FirstIdx[nums[i]] + 1;
			}
			else if (degree == maxDegree) {
				ret = min(ret, i - num2FirstIdx[nums[i]] + 1);
			}
		}


		return ret;
	}
};

int main()
{
	Solution solution;
	vector<int> num1;
	num1.push_back(1);
	num1.push_back(2);
	num1.push_back(2);
	num1.push_back(3);
	num1.push_back(1);

	vector<int> num2;
	num2.push_back(1);
	num2.push_back(2);
	num2.push_back(2);
	num2.push_back(3);
	num2.push_back(1);
	num2.push_back(4);
	num2.push_back(2);

	vector<int> num3;
	num3.push_back(3);

	cout << solution.findShortestSubArray(num1) << endl;
	cout << solution.findShortestSubArray(num2) << endl;
	cout << solution.findShortestSubArray(num3) << endl;

	return 0;
}