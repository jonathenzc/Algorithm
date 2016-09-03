#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		sort(nums.begin(),nums.end());

		helper(0,nums);
		
		return v;
	}
private:
	vector<vector<int>> v;

	void helper(int index,vector<int> nums)
	{
		if (index == nums.size())
			v.push_back(nums);
		else
		{
			for (int i = index; i < nums.size(); i++) {
				
				if (i == index || nums[i] != nums[index]) {
					swap(nums[i], nums[index]);
					helper(index + 1, nums);
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
		for(auto num:tmpV)
			cout << num << " ";

		cout << endl;
	}
}

int main()
{
	Solution s;

	vector<int> tmpV;
	tmpV.push_back(1);
	tmpV.push_back(1);
	tmpV.push_back(2);

	auto v = s.permuteUnique(tmpV);
	testPrint(v);

	return 0;
}