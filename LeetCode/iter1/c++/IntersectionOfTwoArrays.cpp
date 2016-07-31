#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
	vector<int> result;
	if (nums1.size() == 0 || nums2.size() == 0)
		return result;

	//根据nums1建立映射
	map<int, int> m;
	for (int i = 0; i < nums1.size(); i++)
	{
		if (m.find(nums1[i]) == m.end())
			m.insert(map<int,int>::value_type(nums1[i],1));
	}
	
	//遍历nums2寻找交集
	for (int i = 0; i < nums2.size(); i++)
	{
		if (m.find(nums2[i]) != m.end())
		{
			m[nums2[i]]++;
			if(m[nums2[i]] == 2)
				result.push_back(nums2[i]);
		}
	}

	return result;
}

int main()
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(2);
	v1.push_back(1);
	v1.push_back(1);

	vector<int> v2;
	v2.push_back(2);
	v2.push_back(2);
	v2.push_back(1);
	v2.push_back(1);
	v2.push_back(1);
	v2.push_back(1);

	vector<int> result = intersection(v1,v2);
	for (int i = 0; i < result.size(); i++)
		cout << result[i] << " ";

	return 0;
}
