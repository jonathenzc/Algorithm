#include <iostream>
#include <vector>
#include <map>
#include <math.h>

using namespace std;

bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) 
{
	//键为vector中的元素，值为元素所对的下标
	map<int, int> m;
	for (int i = 0; i < nums.size(); i++)
	{
		auto it = m.lower_bound(nums[i] - t);
		
		if (it != m.end())
		{
			long long diff = it->first - nums[i];//用来处理溢出
			if (abs(diff) <= t)
			{
				int duplicateIndex = it->second;
				if (abs(duplicateIndex - i) <= k)
					return true;
			}
		}

		it = m.lower_bound(nums[i] + t);
		
		if (it != m.end())
		{
			long long diff = it->first - nums[i];//用来处理溢出
			if (abs(diff) <= t)
			{
				int duplicateIndex = it->second;
				if (abs(duplicateIndex - i) <= k)
					return true;
			}
		}

		m[nums[i]] = i;
	}

	return false;
}

int main()
{
	vector<int> v;
	//v.push_back(-1);
	//v.push_back(6);
	//v.push_back(0);
	//v.push_back(4);

	v.push_back(-1);
	v.push_back(2147483647);

	if (containsNearbyAlmostDuplicate(v, 1, 2147483647))
		cout << "Yes";
	else
		cout << "No";

	//map<int, int> m;
	//m[12] = 1;
	//m[15] = 2;
	//m[20] = 3;
	//m[25] = 4;
	//m[5] = 5;

	//auto it = m.lower_bound(26);
	//cout << it->first;

	return 0;
}