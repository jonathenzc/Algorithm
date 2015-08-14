#include <iostream>
#include <vector>
#include <map>

using namespace std;

int singleNumber(vector<int>& nums) 
{
	//用map来储存遍历后的结果
	map<int,int> m;
	for(int i=0;i<nums.size();i++)
	{
		if(m.find(nums[i]) != m.end())
			m[nums[i]]++;
		else
			m[nums[i]] = 1;
	}
	
	//遍历一遍寻找个数为1个的变量
	map<int,int>::iterator iter;
	for(iter = m.begin();iter!=m.end();iter++)
	{
		if(iter->second == 1)
			return iter->first;
	}        
}

int main()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(1);
	v.push_back(1);
	
	v.push_back(2);
	v.push_back(2);
	v.push_back(2);

	v.push_back(3);
	v.push_back(3);
	v.push_back(3);
	
	v.push_back(4);			
	
	cout<<singleNumber(v);
	
	return 0;
}