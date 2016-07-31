#include <iostream>
#include <vector>

using namespace std;

void helper(vector<int> curV, vector<int> nums, int index,vector<vector<int>>& v)
{
	if (curV.size() > 0)
	{
		v.push_back(curV);

		for (int i = index+1; i < nums.size(); i++)
		{
			vector<int> tmpV = curV;
			tmpV.push_back(nums[i]);

			helper(tmpV, nums,i,v);
		}
	}
}

vector<vector<int>> subsets(vector<int>& nums) {
	vector<vector<int>> v;

	vector<int> emptySet;
	v.push_back(emptySet);

	if (nums.size() > 0)
	{
		for (int i = 0; i < nums.size(); i++)
		{
			vector<int> tmpV;
			tmpV.push_back(nums[i]);
			helper(tmpV, nums,i,v);
		}
	}

	return v;
}

void testPrint(vector<int> testV)
{
	vector<vector<int>> sets = subsets(testV);

	cout << "setsSize " << sets.size() << endl;

	for (int i = 0; i < sets.size(); i++)
	{
		vector<int> v = sets[i];
		for (int j = 0; j < v.size(); j++)
		{
			cout << v[j] << " ";
		}

		cout << endl;
	}
}

int main()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);

	testPrint(v);

	return 0;
}