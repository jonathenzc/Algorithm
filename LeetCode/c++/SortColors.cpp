#include <iostream>
#include <vector>

using namespace std;

void arrangeColors(vector<int>& nums, int start, int end,int value)
{
	for (int i = start; i < end; i++)
		nums[i] = value;
}

void sortColors(vector<int>& nums) 
{
	int zeroCnt = 0;
	int oneCnt = 0;
	int twoCnt = 0;

	//统计数组中012的个数
	for (int i = 0; i < nums.size(); i++)
	{
		if (nums[i] == 0)
			zeroCnt++;
		else if (nums[i] == 1)
			oneCnt++;
		else if (nums[i] == 2)
			twoCnt++;
	}

	cout << zeroCnt << " " << oneCnt << " " << twoCnt << endl;

	//按统计好的个数分配数组空间
	arrangeColors(nums, 0, zeroCnt, 0);
	arrangeColors(nums, zeroCnt, zeroCnt+oneCnt, 1);
	arrangeColors(nums, oneCnt+zeroCnt, oneCnt + zeroCnt+twoCnt, 2);
}

int main()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(0);
	v.push_back(2);
	v.push_back(2);
	v.push_back(0);
	v.push_back(1);
	v.push_back(0);
	v.push_back(0);
	v.push_back(2);

	sortColors(v);

	for (int i = 0; i < v.size(); i++)
		cout << v[i] << " ";

	return 0;
}