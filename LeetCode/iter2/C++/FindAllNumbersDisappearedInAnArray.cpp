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
	vector<int> findDisappearedNumbers(vector<int>& nums) {
		vector<int> retV;

		//1st iter to negatify unique num
		for (int i = 0; i < nums.size(); i++) {
			int absVal = abs(nums[i]) - 1;
			if (nums[absVal] > 0) {
				nums[absVal] = -nums[absVal];
			}
		}

		//2nd iter to find 
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] > 0)
				retV.push_back(i+1);
		}

		return retV;
    }
};

int main(void)
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(2);
	v.push_back(3);
	v.push_back(3);
	v.push_back(4);
	v.push_back(7);
	v.push_back(8);

	Solution s;
	auto retV = s.findDisappearedNumbers(v);

	for (int num : retV){
		cout << num << " ";
	}

	return 0;
}