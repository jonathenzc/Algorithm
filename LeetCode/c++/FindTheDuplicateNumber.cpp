#include <iostream>
#include <vector>

using namespace std;

//通过二分的方法逐步逼近重复数应该在的范围
int findDuplicate(vector<int>& nums) {
	if (nums.size() == 0)
		return 0;
	
	int n = nums.size()-1;
	int low = 1;
	int high = n;
	int half = (n+1)/2;
	int mid = (low + high) / 2;
	int count = 0;

	while (low < high)
	{
		count = 0;
		mid = (low + high) / 2;
		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[i] <= mid) //统计小于中位数的数的个数
				count++;
		}

		if (count > mid) //缩小重复数所在的区域在[low,mid]
			high = mid;
		else
			low = mid+1;
	}

	return low;
}

int main()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.push_back(1);

	cout << findDuplicate(v);

	return 0;
}