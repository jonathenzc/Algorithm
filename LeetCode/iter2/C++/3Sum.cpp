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
	vector<vector<int>> threeSum(vector<int>& nums) {
		
		sort(nums.begin(), nums.end());
		int i = 0;

		while(i<nums.size())
		{
			int a = nums[i];
			findBC(a,i,nums);

			//消除与a相同
			while (i < nums.size() && a == nums[i])
				i++;
		}

		return v;
	}
private:
	vector<vector<int>> v;

	void findBC(int a, int aIndex, vector<int>& nums)
	{
		int start = aIndex + 1, end = nums.size() - 1;

		while (start < end)
		{
			if (nums[start] + nums[end] == -a)
			{
				vector<int> tmpV;
				tmpV.push_back(a);
				tmpV.push_back(nums[start]);
				tmpV.push_back(nums[end]);

				v.push_back(tmpV);

				int b = nums[start];
				int c = nums[end];
				while (start < end && b == nums[start])
					start++;

				while (start < end && c == nums[end])
					end--;
			}
			else if (nums[start] + nums[end]>-a)
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
	v.push_back(2);
	v.push_back(-1);
	v.push_back(-4);

	Solution s;
	vector<vector<int>> retV = s.threeSum(v);

	for (auto tmpV : retV)
	{
		for (int num : tmpV)
			cout << num << " ";

		cout << endl;
	}

	return 0;
}