#include <iostream>
#include <vector>
#include <string>

using namespace std;

void helper(int index, vector<int> &nums, vector<int> &curV,vector<vector<int>> &v)
{
	if (index < (signed int)nums.size()) //如果不加的话，会以unsigned int来判断
	{
		v.push_back(curV);
		for (int i = index + 1; i < nums.size(); i++)
		{
			curV.push_back(nums[i]);
			helper(i,nums,curV,v);
			curV.pop_back();
		}
	}
}

vector<vector<int>> subsets(vector<int>& nums) {
	vector<vector<int>> v;
	vector<int> curv;

	helper(-1,nums, curv, v);

	return v;
}

void testPrint(vector<int>& nums)
{
	vector<vector<int>> v = subsets(nums);

	cout << "v Size "<<v.size() << endl;

	for (auto tmpV : v)
	{
		for (auto num : tmpV)
			cout << num << " ";

		cout << endl;
	}

	cout << endl;
}

int main()
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);

	testPrint(v1);

	return 0;
}