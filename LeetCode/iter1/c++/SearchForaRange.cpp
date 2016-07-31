#include <iostream>
#include <vector>

using namespace std;

//定位
int getPivot(vector<int>& nums,int target)
{
	int start = 0, end = nums.size(),mid = 0;
	int result = -1;

	while (start < end)
	{
		mid = (start + end) / 2;
		if (nums[mid] == target)
		{
			result = mid;
			break;
		}
		else if (nums[mid] > target)
			end = mid;
		else
			start = mid + 1;
	}

	return result;
}

int findLowerBound(vector<int>& nums, int target,int pivot)
{
	int result = -1;
	for (int i = pivot; i >= 0; i--)
	{
		if (nums[i] != target)
			break;
		else
			result = i;
	}

	return result;
}

int findUpperBound(vector<int>& nums, int target,int pivot)
{
	int result = -1;
	for (int i = pivot; i < nums.size(); i++)
	{
		if (nums[i] != target)
			break;
		else
			result = i;
	}

	return result;

	return -1;
}

vector<int> searchRange(vector<int>& nums, int target) {
	//定位
	int pivot = getPivot(nums,target);

	//先找下限
	int lowerBound = findLowerBound(nums,target,pivot);

	//再找上限
	int upperBound = -1;
	if(lowerBound != -1)
		upperBound = findUpperBound(nums,target,pivot);

	vector<int> v;
	v.push_back(lowerBound);
	v.push_back(upperBound);

	return v;
}

void testPrint(vector<int> v)
{
	vector<int> rV = searchRange(v, 8);

	cout << "[" << rV[0] << "," << rV[1] << "]\n";
}

/**************************** 提高效率的方法 *******************************/
    //定位
    int getPivot(vector<int>& nums, int target)
    {
    	int start = 0, end = nums.size(), mid = 0;
    	int result = -1;
    
    	while (start < end)
    	{
    		mid = (start + end) / 2;
    		if (nums[mid] == target)
    		{
    			result = mid;
    			break;
    		}
    		else if (nums[mid] > target)
    			end = mid;
    		else
    			start = mid + 1;
    	}
    
    	return result;
    }
    
    int findLowerBound(vector<int>& nums, int target, int pivot)
    {
    	int left = 0,right=pivot;
    	while(left < right)
    	{
    		int mid = (left + right) / 2;
    		if (nums[mid] == target)
    			right = mid;
    		else if(nums[mid] < target)
    			left = mid+1;
    	}
    
    	return left;
    }
    
    int findUpperBound(vector<int>& nums, int target, int pivot)
    {
    	int left = pivot, right = nums.size();
    	while (left +1< right)
    	{
    		int mid = (left + right) / 2;
    		if (nums[mid] == target)
    			left = mid;
    		else if (nums[mid] > target)
    			right = mid;
    	}
    
    	return left;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
    	//定位
    	int pivot = getPivot(nums, target);
        int lowerBound = -1;
        int upperBound = -1;
        
        if(pivot != -1)
        {
        	//先找下限
        	lowerBound = findLowerBound(nums, target, pivot);
        
        	//再找上限
        	if (lowerBound != -1)
        		upperBound = findUpperBound(nums, target, pivot);
        }
        
        vector<int> v;
        v.push_back(lowerBound);
        v.push_back(upperBound);
        
        return v;
    }

int main()
{
	vector<int> v;
	v.push_back(5);
	v.push_back(7);
	v.push_back(8);
	v.push_back(8);
	v.push_back(8);
	v.push_back(10);

	testPrint(v);

	return 0;
}
