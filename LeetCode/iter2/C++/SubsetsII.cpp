#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		vector<int> curV;

		sort(nums.begin(),nums.end());

		helper(0,nums,curV);

		return v;
	}
private:
	vector<vector<int>> v;

	unordered_map<int, int> map;

	void helper(int size, vector<int> nums, vector<int> curV)
	{
		if (size <= nums.size()) {
			v.push_back(curV);

			for (int i = size; i < nums.size(); i++)
			{
				if (i == size || nums[i] != nums[i - 1]) {
					curV.push_back(nums[i]);
					helper(i + 1, nums, curV);
					curV.pop_back();
				}
			}
		}
	}
};


void testPrint(vector<vector<int>> v)
{
	cout << "v size " << v.size()<<endl;

	for (auto tmpV : v)
	{
		for (auto num : tmpV)
			cout << num << " ";

		cout << endl;
	}
}

int main()
{
	Solution s;

	vector<int> nums;
	nums.push_back(2);
	nums.push_back(2);
	nums.push_back(2);

	vector<vector<int>> v = s.subsets(nums);
	testPrint(v);

	return 0;
}