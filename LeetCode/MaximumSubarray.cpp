#include <iostream>
#include <vector>

using namespace std;

int maxSubArray(vector<int>& nums) {
	//int sum = nums[0];
	if (nums.size() == 0)
		return 0;

	int max = nums[0];
	int cur = nums[0];
	int prev = nums[0];

	for (int i = 1; i < nums.size(); i++)
	{
		if (prev < 0)
			cur = nums[i];
		else
			cur = prev+nums[i];

		if (cur > max)
			max = cur;

		prev = cur;
	}

	return max;
}

int main()
{
	vector<int> v;
	v.push_back(-2);
	v.push_back(1);
	v.push_back(-3);
		
	v.push_back(4);
	v.push_back(-1);
	v.push_back(2);

	v.push_back(1);
	v.push_back(-5);
	v.push_back(4);

	//vector<int> v;
	//v.push_back(1);
	//v.push_back(-1);
	//v.push_back(1);

	cout << maxSubArray(v);

	return 0;
}