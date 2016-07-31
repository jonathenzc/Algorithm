#include <iostream>
#include <vector>

using namespace std;

int findMin(vector<int>& nums) {
	int preNum = nums[0];
	
	for(int i=1;i<nums.size();i++)
	{
		if(nums[i] >= preNum)
			preNum = nums[i];
		else
			return nums[i];			
	}
	
	return nums[0];        
}

int main()
{
	vector<int> v;
	v.push_back(3);
	v.push_back(3);
	v.push_back(4);
	v.push_back(4);
	v.push_back(5);
	v.push_back(5);	
	v.push_back(2);
	v.push_back(2);

	cout<<findMin(v);
	
	return 0;
}