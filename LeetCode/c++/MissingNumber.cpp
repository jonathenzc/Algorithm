#include <iostream>
#include <vector>

using namespace std;

int missingNumber(vector<int>& nums) 
{
	//先求和
	int sum=0;
	int size = nums.size();
	sum = (size+1)*size/2;
	
	//再减去容器中的元素
	for(int i=0;i<size;i++)
		sum -= nums[i];
		
	return sum;        
}

int main()
{
	vector<int> v;
	v.push_back(0);
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);	
	v.push_back(5);
	v.push_back(6);
	
	cout<<missingNumber(v);
	
	return 0;
}