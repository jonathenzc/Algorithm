#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxProduct(vector<int>& nums) {
	if (nums.size() == 0)
		return 0;
	
	int maxRet = nums[0];
	int *maxDp = new int[nums.size()]{0};
	int *minDp = new int[nums.size()]{0};

	maxDp[0] = nums[0];
	minDp[0] = nums[0];

	for (int i = 1; i < nums.size(); i++)
	{
		maxDp[i] = max(max(maxDp[i-1]*nums[i],minDp[i-1]*nums[i]),nums[i]);
		minDp[i] = min(min(maxDp[i-1]*nums[i],minDp[i-1]*nums[i]),nums[i]);

		maxRet = max(maxRet,max(maxDp[i],minDp[i]));
	}

	return maxRet;
}

int main()
{
	vector<int> v;
	v.push_back(0);
	v.push_back(3);
	v.push_back(-2);
	v.push_back(4);

	cout << maxProduct(v);


	return 0;
}