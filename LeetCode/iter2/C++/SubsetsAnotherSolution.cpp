#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Solution {
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		vector<int> curV;

		helper(0,nums,curV);

		return v;
	}
private:
	vector<vector<int>> v;

	void helper(int size, vector<int> nums, vector<int> curV)
	{
		if (size <= nums.size()) {
			v.push_back(curV);

			for (int i = size; i < nums.size(); i++)
			{
				vector<int> tmpV = curV;
				tmpV.push_back(nums[i]);
				helper(i+1,nums,tmpV);
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
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(3);

	vector<vector<int>> v = s.subsets(nums);
	testPrint(v);

	return 0;
}