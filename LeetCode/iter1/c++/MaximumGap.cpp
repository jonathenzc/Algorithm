#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maximumGap(vector<int>& nums) {
	if (nums.size() < 2)
		return 0;
	
	sort(nums.begin(),nums.end());

	int max = INT_MIN;
	for (int i = 0; i < nums.size()-1; i++)
	{
		if (nums[i + 1] - nums[i] > max)
			max = nums[i + 1] - nums[i];
	}

	return max;
}


int main()
{
	vector<int> nums;
	nums.push_back(4);
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(3);
	nums.push_back(7);
	nums.push_back(6);
	nums.push_back(100);

	cout << maximumGap(nums) << endl;


	return 0;
}