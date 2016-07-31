#include <iostream>
#include <vector>

using namespace std;

int removeDuplicates(vector<int>& nums) 
{
	if (nums.size() == 0)
		return 0;
	else
	{
		vector<int> tempV;
		int numCnt = 1;
		int target = nums[0];
		tempV.push_back(target);

		for (int i = 1; i < nums.size(); i++)
		{
			if (nums[i] == target)
				numCnt++;
			else
			{
				numCnt=1;
				target = nums[i];
			}

			if (numCnt <= 2)
				tempV.push_back(target);
		}

		nums = tempV;

		return tempV.size();
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

	cout << removeDuplicates(v)<<endl;

	for (int i = 0; i < v.size(); i++)
		cout << v[i]<<" ";

	return 0;
}