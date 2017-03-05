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
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
		unordered_map<int, int> numMap;
		for (int num : nums1)
			numMap[num] = 1;

		vector<int> retV;
		for (int num : nums2)
		{
			if (numMap[num] == 1)
			{
				numMap[num] = 0;
				retV.push_back(num);
			}
		}

		return retV;
	}
};

int main(void)
{
	vector<int> num1;
	num1.push_back(1);
	num1.push_back(2);
	num1.push_back(2);
	num1.push_back(1);

	vector<int> num2;
	num2.push_back(2);
	num2.push_back(2);

	Solution s;
	vector<int> retV = s.intersection(num1,num2);

	for (int num : retV)
		cout << num << " ";


	return 0;
}