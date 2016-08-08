#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int firstMissingPositive(vector<int>& nums) {
	//将数i放到nums[i-1]处，最终遍历数组，如果第i个数不等于i+1，那么就返回i+1
	for (int i = 0; i < nums.size(); i++)
	{
		while (nums[i] > 0 && nums[i] < nums.size() && nums[i] != nums[nums[i] - 1])
			swap(nums[i],nums[nums[i]-1]);
	}

	for (int i = 0; i < nums.size(); i++)
	{
		if (nums[i] != i + 1)
			return i + 1;
	}

	return nums.size() + 1;
}

void testPrint(vector<vector<char>>& board)
{
	for (auto row : board)
	{
		for (auto col : row)
			cout << col << " ";

		cout << endl;
	}

	cout << endl;
}

int main()
{
	vector<int> v1;

	v1.push_back(3);
	v1.push_back(3);
	v1.push_back(1);

	cout << firstMissingPositive(v1);

	return 0;
}