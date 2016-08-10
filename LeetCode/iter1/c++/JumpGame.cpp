#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//方法1：回溯超时
//void helper(int diff, int index, vector<int>& nums, bool &result)
//{
//	if (index == 0)
//	{
//		if (nums[index] >= diff)
//			result = true;
//	}
//	else if(index > 0)
//	{
//		if (nums[index] >= diff)
//		{
//			for (int i = 1; i <= index; i++)
//			{
//				helper(i, index-i, nums, result);
//				if (result)
//					break;
//			}
//		}
//	}
//}
//
//bool canJump(vector<int>& nums) {
//	if (nums.size() < 2)
//		return true;
//
//	int size = nums.size();
//	bool result = false;
//
//	for (int i = 1; i < size; i++)
//	{
//		helper(i,size-i-1,nums,result);
//		if (result)
//			break;
//	}
//
//	return result;
//}

//方法2：从后遍历，找出可达的下标
bool canJump(vector<int>& nums) {
	int lastIndex = nums.size() - 1;
	for (int i = lastIndex - 1; i >= 0; i--)
	{
		if (nums[i] + i >= lastIndex)
			lastIndex = i;
	}

	return (lastIndex == 0);
}

void testPrint(vector<int>& nums)
{
	if (canJump(nums))
		cout << "Yes\n";
	else
		cout << "No\n";
}

int main()
{
	vector<int> v1;

	v1.push_back(3);
	v1.push_back(2);
	v1.push_back(1);
	v1.push_back(0);
	v1.push_back(4);

	//v1.push_back(1);
	//v1.push_back(1);
	//v1.push_back(2);
	//v1.push_back(2);
	//v1.push_back(0);
	//v1.push_back(1);
	//v1.push_back(1);

	testPrint(v1);

	return 0;
}