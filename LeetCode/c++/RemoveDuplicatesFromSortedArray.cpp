#include <iostream>
#include <vector>

using namespace std;

int removeDuplicates(vector<int>& nums) 
{
	if (nums.size() == 0)
		return 0;
	else
	{
		int removedLength = 0;
		int vSize = nums.size();
		for (int i = 1; i < vSize; i++)
		{
			if (nums[removedLength] != nums[i])
			{
				removedLength++;
				nums[removedLength] = nums[i];
			}
		}

		return removedLength+1;
	}
}

int main()
{
	vector<int> v;
	v.push_back(1);
	//v.push_back(1);
	//v.push_back(1);
	v.push_back(2);
	//v.push_back(2);
	v.push_back(3);
	//v.push_back(3);
	//v.push_back(4);
	//v.push_back(4);
	//v.push_back(5);
	//v.push_back(5);
	//v.push_back(5);
	//v.push_back(5);
	//v.push_back(5);
	//v.push_back(6);


	cout << removeDuplicates(v)<<endl;

	for (int i = 0; i < v.size(); i++)
		cout << v[i] << " ";

	return 0;
}