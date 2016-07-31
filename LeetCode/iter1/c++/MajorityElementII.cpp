#include <iostream>
#include <vector>

using namespace std;

//正确，先判断是否与候选数相等，如果相等那么cnt+1
vector<int> majorityElement(vector<int>& nums) {
	//数量大于n/3的只有可能是两个数
	int candidate1 = -1, candidate2 = -1;
	int cnt1 = 0, cnt2 = 0;

	//先找出两个候选数
	for (int i = 0; i < nums.size(); i++)
	{
		if (nums[i] == candidate1)
			cnt1++;
		else if (nums[i] == candidate2)
			cnt2++;
		else if (cnt1 == 0)
		{
			candidate1 = nums[i];
			cnt1 = 1;
		}
		else if (cnt2 == 0)
		{
			candidate2 = nums[i];
			cnt2 = 1;
		}
		else
		{
			cnt1--;
			cnt2--;
		}
	}

	//统计数量
	cnt1 = 0, cnt2 = 0;
	for (auto num : nums)
	{
		if (num == candidate1)
			cnt1++;

		if (num == candidate2)
			cnt2++;
	}

	//判断数量是否超过nums的大小
	vector<int> v;
	if (cnt1 > nums.size() / 3)
		v.push_back(candidate1);

	if (candidate1 != candidate2 && cnt2 > nums.size() / 3)
		v.push_back(candidate2);

	return v;
}

//有问题，因为是先判断是否为0，这样会导致第一个候选数的个数为0，当前数正好是第二个候选数，这样就导致第二个候选数的个数不能加上去
//vector<int> majorityElement(vector<int>& nums) {
//	//数量大于n/3的只有可能是两个数
//	int candidate1 = -1, candidate2 = -1;
//	int cnt1 = 0,cnt2=0;
//	
//	//先找出两个候选数
//	for (int i = 0; i < nums.size();i++)
//	{
//		if (cnt1 == 0)
//		{
//			candidate1 = nums[i];
//			cnt1 = 1;
//		}
//		else if (cnt2 == 0)
//		{
//			candidate2 = nums[i];
//			cnt2 = 1;
//		}
//		else if (nums[i] == candidate1)
//			cnt1++;
//		else if (nums[i] == candidate2)
//			cnt2++;
//		else
//		{
//			cnt1--;
//			cnt2--;
//		}
//	}
//
//	//统计数量
//	cnt1 = 0, cnt2 = 0;
//	for (auto num : nums)
//	{
//		if (num == candidate1)
//			cnt1++;
//
//		if (num == candidate2)
//			cnt2++;
//	}
//
//	//判断数量是否超过nums的大小
//	vector<int> v;
//	if (cnt1 > nums.size() / 3)
//		v.push_back(candidate1);
//
//	if (candidate1 != candidate2 && cnt2 > nums.size() / 3)
//		v.push_back(candidate2);
//
//	return v;
//}

int main()
{
	//vector<int> v;
	//v.push_back(2);
	//v.push_back(2);
	//v.push_back(2);
	//v.push_back(1);
	//v.push_back(1);
	//v.push_back(1);
	//v.push_back(3);
	//v.push_back(4);

	//[1,2,2,3,2,1,1,3]
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(2);
	v.push_back(3);
	v.push_back(2);
	v.push_back(1);
	v.push_back(1);
	v.push_back(3);


	vector<int> retV = majorityElement(v);
	for (int i = 0; i < retV.size(); i++)
		cout << retV[i] << " ";

	return 0;
}