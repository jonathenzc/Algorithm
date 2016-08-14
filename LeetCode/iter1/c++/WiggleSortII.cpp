#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void wiggleSort(vector<int>& nums) {
	sort(nums.begin(),nums.end());

	vector<int> smallHalf, largeHalf;

	int halfIndex = (nums.size() - 1) / 2;
	for (int i = halfIndex; i >= 0; i--)
		smallHalf.push_back(nums[i]);

	for (int i = nums.size()-1; i > halfIndex; i--)
		largeHalf.push_back(nums[i]);

	int smallIndex = 0, largeIndex = 0;
	bool isSmall = true;
	for (int i = 0; i < nums.size(); i++)
	{
		if (isSmall)
		{
			isSmall = false;
			nums[i] = smallHalf[smallIndex++];
		}
		else
		{
			isSmall = true;
			nums[i] = largeHalf[largeIndex++];
		}
	}
}


int main()
{
	vector<int> oddnums;
	oddnums.push_back(1);
	oddnums.push_back(2);
	oddnums.push_back(3);
	oddnums.push_back(4);
	oddnums.push_back(5);
	oddnums.push_back(6);
	oddnums.push_back(7);

	wiggleSort(oddnums);

	for (auto i : oddnums)
		cout << i << " ";

	cout << endl;

	vector<int> evennums;
	evennums.push_back(1);
	evennums.push_back(2);
	evennums.push_back(3);
	evennums.push_back(4);
	evennums.push_back(5);
	evennums.push_back(6);
	evennums.push_back(7);
	evennums.push_back(8);

	wiggleSort(evennums);

	for (auto i : evennums)
		cout << i << " ";


	return 0;
}