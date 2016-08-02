#include <iostream>
#include <vector>

using namespace std;

//方法1：
//void helper(vector<int> &nums, vector<bool> &isUsed,vector<int> &curV,vector<vector<int>> &v)
//{
//	if (curV.size() == nums.size())
//		v.push_back(curV);
//	else
//	{
//		for (int i = 0; i < nums.size(); i++)
//		{
//			if (!isUsed[i])
//			{
//				curV.push_back(nums[i]);
//				isUsed[i] = true;
//				helper(nums, isUsed,curV,v);
//				isUsed[i] = false;
//				curV.pop_back();
//			}
//		}
//	}
//}
//
//vector<vector<int>> permute(vector<int>& nums) {
//	vector<vector<int>> v;
//	vector<int> curV;
//	vector<bool> isUsed(nums.size(),false);
//
//	for (int i = 0; i < nums.size(); i++)
//	{
//		curV.push_back(nums[i]);
//		isUsed[i] = true;
//		helper(nums, isUsed, curV, v);
//		isUsed[i] = false;
//		curV.pop_back();
//	}
//
//	return v;
//}

//方法2,使用交换
void swap(vector<int> &nums, int start, int end)
{
	int tmp = nums[start];
	nums[start] = nums[end];
	nums[end] = tmp;
}

void helper(int index, vector<int> &nums, vector<vector<int>> &v)
{
	if (index == nums.size())
		v.push_back(nums);
	else
	{
		for (int i = index; i < nums.size(); i++)
		{
			swap(nums,i,index);
			helper(index+1,nums,v);
			swap(nums,i,index);
		}
	}
}

vector<vector<int>> permute(vector<int>& nums) {
	vector<vector<int>> v;
	
	helper(0, nums, v);

	return v;
}
void testPrint(vector<int>& nums)
{
	vector<vector<int>> v = permute(nums);

	cout << "v Size " << v.size() << endl;

	for (auto innerV : v)
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
	v1.push_back(3);

	testPrint(v1);

	return 0;
}