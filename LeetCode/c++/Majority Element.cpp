#include <iostream>
#include <vector>
#include <map>

using namespace std;

//���������г��ֵ����ͳ��ֵĴ�����ӳ�䣬���������
//ע����Ŀ���Ѿ������˾���Ϊ�ն��ҿ϶���������
int majorityElement(vector<int>& nums)
{
	map<int, int> m;//����ʾ�����е�����ֵ��ʾ�������ֵĴ���

	int maxCnt = 0;
	int majorityNum = nums[0];

	for (int i = 0; i < nums.size(); i++)
	{
		if (m.find(nums[i]) == m.end())
			m[nums[i]] = 1;
		else
		{
			m[nums[i]]++;

			if (maxCnt < m[nums[i]])
			{
				maxCnt = m[nums[i]];
				majorityNum = nums[i];
			}
		}
	}

	return majorityNum;
}

int main()
{
	vector<int> v;

	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(3);
	v.push_back(4);

	cout << majorityElement(v);

	return 0;
}