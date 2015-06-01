#include <iostream>
#include <vector>
#include <map>

using namespace std;

bool containsNearbyDuplicate(vector<int>& nums, int k) 
{
	//键为vector中的元素，值为元素所对的下标
	map<int, int> m;
	for (int i = 0; i < nums.size(); i++)
	{
		if (m.find(nums[i]) != m.end())
		{
			int duplicateIndex = m[nums[i]];
			if (duplicateIndex - i >= -k && duplicateIndex - i <= k)
				return true;
			else
				m[nums[i]] = i;
		}
		else
			m[nums[i]] = i;
	}

	return false;
}

int main()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(0);
	v.push_back(2);
	v.push_back(1);

	if (containsNearbyDuplicate(v, 1))
		cout << "Yes";
	else
		cout << "No";

	return 0;
}