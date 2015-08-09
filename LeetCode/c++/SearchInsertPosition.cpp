#include <iostream>
#include <vector>

using namespace std;

int searchInsert(vector<int>& nums, int target) 
{
	if (nums.size() == 0)
		return 0;

	if (target <= nums[0]) //插在最前
		return 0;

	if (target > nums[nums.size() - 1]) //插在最后
		return nums.size();

	int startIndex = 0;
	int endIndex = nums.size();
	int midIndex = 0;
	bool isFound = false;
	while (startIndex < endIndex)
	{
		midIndex = (startIndex + endIndex) / 2;
		//cout << "start: " << startIndex << " end: " << endIndex << " mid: " << midIndex << endl;
		if (target == nums[midIndex])
		{
			isFound = true;
			break;
		}
		else if (target > nums[midIndex])
			startIndex = midIndex+1;
		else
			endIndex = midIndex;
	}

	if (!isFound && midIndex<nums.size() && endIndex<nums.size() &&
		nums[midIndex] < nums[endIndex])
		midIndex++;

	return midIndex;
}

int main()
{
	vector<int> v;
	
	for (int i = 0; i < 9; i += 2)
		v.push_back(i);

	for (int i = -2; i < 12; i++)
		cout << i<<" "<<searchInsert(v,i)<<endl;

	return 0;
}