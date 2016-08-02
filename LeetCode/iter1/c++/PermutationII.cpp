#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


void swap(vector<int> &nums, int start, int end)
{
	int tmp = nums[start];
	nums[start] = nums[end];
	nums[end] = tmp;
}

void helper(int index, vector<int> nums, vector<vector<int>> &v)
{
	if (index == nums.size())
		v.push_back(nums);
	else
	{
		for (int i = index; i < nums.size(); i++)
		{
			if (i == index || nums[i] != nums[index])
			{
				swap(nums, i, index);
				helper(index + 1, nums, v);
				//swap(nums, i, index); //再交换回来不行，比如1 1 2 2 会变成1 2 1 2，交换的是i为1和2的两个元素；下一个交换的下标是1和3，如果变回来就变成交换1 1 2 2 中的第二个1和第二个2，重复步骤
			}
		}
	}
}

vector<vector<int>> permuteUnique(vector<int>& nums) {
	vector<vector<int>> v;

	sort(nums.begin(),nums.end());

	helper(0, nums, v);

	return v;
}

void testPrint(vector<int> &v)
{
	vector<vector<int>> retV = permuteUnique(v);

	cout << "v Size " << retV.size() << endl;

	for (auto innerV : retV)
	{
		for (auto num : innerV)
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
	v1.push_back(2);
	v1.push_back(1);

	testPrint(v1);

	vector<int> v2;
	v2.push_back(0);
	v2.push_back(1);
	v2.push_back(0);
	v2.push_back(0);
	v2.push_back(9);

	testPrint(v2);

	return 0;
}