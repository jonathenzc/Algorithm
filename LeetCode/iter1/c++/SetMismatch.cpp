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

	//solution 1
	//expected - current = missing - duplicate = value1                        [1]
	//each expected^2 - each current^2 = missing^2 - duplicate^2 = value2      [2]
	//missing + duplicate = value2 / value1 = value3                           [3] 
	//with [1] & [3] => missing & duplicate
	vector<int> findErrorNums(vector<int>& nums) {
		long long value1 = 0, value2 = 0;
		for (int i = 1; i <= nums.size(); i++) {
			value1 += i - nums[i - 1];
			value2 += i * i - nums[i - 1] * nums[i - 1];
		}

		long long value3 = value2 / value1;

		vector<int> ret;
		ret.push_back((value3 - value1) / 2);
		ret.push_back((value1 + value3) / 2);

		return ret;
	}

	//solution 2
	vector<int> findErrorNumsOld(vector<int>& nums) {
		vector<int> numMap(nums.size() + 1, 1);

		for (size_t i = 0; i < nums.size(); i++)
			numMap[nums[i]]--;

		vector<int> ret;
		int duplicate = -1, missing = -1;
		for (size_t i = 1; i <= nums.size(); i++)
		{
			if (numMap[i] == 1)
				missing = i;
			else if (numMap[i] == -1)
				duplicate = i;
		}

		ret.push_back(duplicate);
		ret.push_back(missing);
		return ret;
	}
};

void print(vector<int> v) {
	for (int num : v)
		cout << num << " ";

	cout << endl;
}

int main(void)
{
	vector<int> num1;
	num1.push_back(1);
	num1.push_back(2);
	num1.push_back(2);
	num1.push_back(4);

	vector<int> num2;
	num2.push_back(1);
	num2.push_back(2);
	num2.push_back(2);
	num2.push_back(3);
	num2.push_back(4);
	num2.push_back(5);

	Solution s;
	print(s.findErrorNums(num1)); //[2,3]
	print(s.findErrorNums(num2)); //[2,6]

	return 0;
}