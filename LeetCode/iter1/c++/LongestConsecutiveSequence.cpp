#include <iostream>
#include <vector>
#include <map>

using namespace std;


int longestConsecutive(vector<int>& nums) {
	if (nums.size() == 0)
		return 0;
	
	map<int, int> nums_map;
	int min = INT_MAX;
	for (int i = 0; i < nums.size(); i++)
	{
		nums_map[nums[i]] = 1;
		if (nums[i] < min)
			min = nums[i];
	}

	int maxLen = INT_MIN;
	int curLen = 1;
	int pre = INT_MIN;

	for (auto iter = nums_map.begin(); iter != nums_map.end(); iter++)
	{
		if (iter->first == pre + 1)
			curLen++;
		else
		{
			if (curLen > maxLen)
				maxLen = curLen;

			curLen = 1;
		}

		pre = iter->first;
	}

	if (curLen > maxLen)
		maxLen = curLen;

	return maxLen;
}

int main()
{
	vector<int> v1;
	v1.push_back(0);
	v1.push_back(-1);
	v1.push_back(100);
	v1.push_back(4);
	v1.push_back(200);
	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(2);
	v1.push_back(-1);

	cout << longestConsecutive(v1)<<endl;

	return 0;
}