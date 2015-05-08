#include <iostream>
#include <vector>
#include <map>

using namespace std;

//建立矩阵中出现的数和出现的次数的映射，计算出众数
//注：题目中已经限制了矩阵不为空而且肯定存在众数
int majorityElement(vector<int>& nums)
{
	map<int, int> m;//键表示矩阵中的数，值表示该数出现的次数

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