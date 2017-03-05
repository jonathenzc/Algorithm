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
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		sort(nums.begin(), nums.end());

		int i = 0;

		while (i<nums.size())
		{
			int a = nums[i];
			int j = i + 1;

			while (j<nums.size())
			{
				int b = nums[j];

				findCD(a,b,j,target,nums);

				while (j < nums.size() && nums[j] == b)
					j++;
			}

			while (i < nums.size() && nums[i] == a)
				i++;
		}

		return v;
	}
private:
	vector<vector<int>> v;

	void findCD(int a, int b, int bIndex, int target, vector<int>& nums)
	{
		int start = bIndex + 1, end = nums.size() - 1;

		while (start < end)
		{
			if (nums[start] + nums[end] == target-a-b)
			{
				vector<int> tmpV;
				tmpV.push_back(a);
				tmpV.push_back(b);
				tmpV.push_back(nums[start]);
				tmpV.push_back(nums[end]);

				v.push_back(tmpV);

				int c = nums[start];
				int d = nums[end];
				while (start < end && c == nums[start])
					start++;

				while (start < end && d == nums[end])
					end--;
			}
			else if (nums[start] + nums[end]>target - a - b)
				end--;
			else
				start++;
		}
	}
};

int main(void)
{
	vector<int> v;
	v.push_back(-1);
	v.push_back(0);
	v.push_back(1);
	v.push_back(0);
	v.push_back(-2);
	v.push_back(2);

	Solution s;
	vector<vector<int>> retV = s.fourSum(v,0);

	for (auto tmpV : retV)
	{
		for (int num : tmpV)
			cout << num << " ";

		cout << endl;
	}

	return 0;
}