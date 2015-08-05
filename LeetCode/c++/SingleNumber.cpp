#include <iostream>
#include <vector>
#include <map>

using namespace std;

int singleNumber(vector<int>& nums) {
	//方法1：用map的方法
// 	map<int, int> m;
// 	//为nums中的数建立索引
// 	for (int i = 0; i<nums.size(); i++)
// 	{
// 		if (m.find(nums[i]) == m.end())
// 			m[nums[i]] = 1;
// 		else
// 			m[nums[i]]++;
// 	}
// 
// 	map<int, int>::iterator iter;
// 	for (iter = m.begin(); iter != m.end(); iter++)
// 	{
// 		if (iter->second == 1)
// 			return iter->first;
// 	}
	//方法2：用异或的方法
	int result=0;
	for(int i=0;i<nums.size();i++)
		result ^= nums[i];
		
	return result;
}

int main()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(2);

	cout << singleNumber(v) << endl;

	return 0;
}