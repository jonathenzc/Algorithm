#include <iostream>
#include <vector>

using namespace std;

vector<int> productExceptSelf(vector<int>& nums)
{
    int power = 1;
	int zeroCnt = 0;
	for(int i=0;i<nums.size();i++)
	{
		if(nums[i] == 0)
		{
			zeroCnt++;
			if(zeroCnt == 2)
			{
				power=0;
				break;
			}
		}
		else
			power *= nums[i];
	}
	
	if(power == 0)
	{
		for(int i=0;i<nums.size();i++)
			nums[i] = 0;
	}
	else
	{
		if(zeroCnt == 1)
		{
			for(int i=0;i<nums.size();i++)
			{
				if(nums[i] != 0)
					nums[i] = 0;
				else
					nums[i] = power;
			}			
		}
		else
		{
			for(int i=0;i<nums.size();i++)
				nums[i] = power / nums[i];
		}
	}
	
	return nums;
}

int main()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(0);
	v.push_back(3);	
	v.push_back(0);
	
	v = productExceptSelf(v);
	
	for(int i=0;i<v.size();i++)
		cout<<v[i]<<" ";
		
	return 0;
}