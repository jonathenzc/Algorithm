#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int helper(int num, int num_index, int target, int& min,vector<int>& nums)
{
	int i = num_index + 1, j = nums.size() - 1;
	int returnSum = 0;

	while (i < j)
	{
		int num_i = nums[i];
		int num_j = nums[j];
		int sum = num_i + num_j + num;

		int diff = target - sum;
		if (diff == 0)
		{
			returnSum = sum;
			min = 0;
			break;
		}
		else 
		{
			if(diff>0) //target>sum
				i++;
			else //target < sum
				j--;

			//记录候选最小值
			if (diff < 0)
				diff = -diff;

			if (diff < min)
			{
				min = diff;
				returnSum = sum;
			}
		}
	}

	return returnSum;
}

int threeSumClosest(vector<int>& nums, int target) {
	sort(nums.begin(), nums.end());

	int preMin = INT_MAX;
	int resultSum = INT_MAX;

	for (int i = 0; i < nums.size(); i++)
	{
		int min = INT_MAX;
		int sum = helper(nums[i], i, target, min,nums);
		
		if (min == 0)
		{
			resultSum = sum;
			break;
		}

		if (min < preMin)
		{
			preMin = min;
			resultSum = sum;
		}
	}

	return resultSum;
}

int main()
{
	vector<int> v;
	v.push_back(-1);
	v.push_back(0);
	v.push_back(1);
	v.push_back(2);
	v.push_back(-1);
	v.push_back(-4);

	cout << threeSumClosest(v,0)<<endl;


	vector<int> v1;
	v1.push_back(-1);
	v1.push_back(2);
	v1.push_back(1);
	v1.push_back(-4);

	cout << threeSumClosest(v1, 1) << endl;

	vector<int> v2;
	v2.push_back(0);
	v2.push_back(1);
	v2.push_back(2);

	cout << threeSumClosest(v2, 3) << endl;

	return 0;
}