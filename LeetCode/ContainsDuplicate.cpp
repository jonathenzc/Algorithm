#include <iostream>
#include <vector>
#include <map>

using namespace std;

bool containsDuplicate(vector<int>& nums) 
{
	map<int, int> m;
	bool isDuplicateFound = false;

	for (int i = 0; i < nums.size(); i++)
	{
		if (m.find(nums[i]) != m.end())
		{
			isDuplicateFound = true;
			break;
		}
		else
			m[nums[i]] = 1;
	}

	return isDuplicateFound;
}

int main()
{
	vector<int> v;
	//v.push_back(1);
	//v.push_back(1);
	//v.push_back(1);
	//v.push_back(2);
	//v.push_back(2);
	//v.push_back(3);
	//v.push_back(3);
	//v.push_back(4);
	//v.push_back(4);
	//v.push_back(5);
	//v.push_back(5);
	//v.push_back(5);
	//v.push_back(5);
	//v.push_back(5);
	//v.push_back(6);

	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);

	if (containsDuplicate(v))
		cout << "Yes";
	else
		cout << "No";

	return 0;
}