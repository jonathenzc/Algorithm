#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<int> singleNumber(vector<int>& nums) 
{
	vector<int> v;
	//����ʾ�����е�����ֵ����Щ�����ֵĴ���
	map<int, int> m;
	for (int i = 0; i < nums.size(); i++)
	{
		if (m.find(nums[i]) != m.end())
			m[nums[i]]++;
		else
			m[nums[i]] = 1;
	}

	//�ٱ���mapһ�飬�ҳ���������Ϊ1������
	map<int, int>::iterator iter;
	for (iter = m.begin(); iter != m.end(); iter++)
	{
		if (iter->second == 1)
			v.push_back(iter->first);

		if (v.size() == 2)
			break;
	}

	return v;
}

int main()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(1);
	v.push_back(3);
	v.push_back(2);
	v.push_back(5);

	v = singleNumber(v);
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << " ";

	return 0;
}