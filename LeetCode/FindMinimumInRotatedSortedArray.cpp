#include <iostream>
#include <vector>

using namespace std;

//int findMin(vector<int>& nums) 
//{
//	for (int i = 0; i < nums.size(); i++)
//	{
//		if (i == nums.size() - 1)
//			return nums[0];
//		else
//		{
//			if (nums[i + 1] < nums[i])
//				return nums[i + 1];
//		}
//	}
//}

int findMin(vector<int>& nums)
{
	int left = 0, right = nums.size() - 1;

	while (left < right)
	{
		if (nums[left] < nums[right])
			return nums[left];

		int mid = (left + right) / 2;
		if (nums[mid] > nums[right])
			left = mid + 1;
		else
			right = mid;
	}

	return nums[left];
}

int main()
{
	vector<int> v;
	v.push_back(4);
	v.push_back(5);
	v.push_back(6);
	v.push_back(7);
	v.push_back(0);
	v.push_back(1);
	v.push_back(2);

	cout << findMin(v);

	return 0;
}