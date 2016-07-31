#include <iostream>
#include <vector>

using namespace std;
	
int partition(vector<int>& nums,int start,int end)
{
	int target = nums[start];
	int j = start;

	for (int i = start+1; i <= end; i++)
	{
		if (nums[i] <= target)
		{
			j++;
			int tmp = nums[j];
			nums[j] = nums[i];
			nums[i] = tmp;
		}
	}

	int tmp = nums[j];
	nums[j] = target;
	nums[start] = tmp;

	return j;
}

int getKthPivot(vector<int>& nums, int start, int end,int k)
{
	int pivot = partition(nums,start,end);

	int diff = end - pivot +1;

	if (k == diff)
		return end+1-k;
	else if (k > diff)
		return getKthPivot(nums, start, pivot - 1, k-diff);
	else
		return getKthPivot(nums,pivot+1,end,k);
}

int findKthLargest(vector<int>& nums, int k) {
	int vSize = nums.size()-1;
	
	int pivot = getKthPivot(nums,0,vSize,k);

	return nums[pivot];
}


int main()
{
	vector<int> nums;
	nums.push_back(3);
	nums.push_back(2);
	nums.push_back(1);
	nums.push_back(5);
	nums.push_back(6);
	nums.push_back(4);

	cout << findKthLargest(nums,3)<< endl;

	return 0;
}
