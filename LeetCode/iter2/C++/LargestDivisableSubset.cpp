#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> largestDivisibleSubset(vector<int>& nums) {
	sort(nums.begin(), nums.end());

	vector<int> maxV;
	
	vector<vector<int>> v;

	for (int i = 0; i < nums.size(); i++)
	{
		int maxLength = 0;
		int maxIndex = -1;
		for (int j = i-1; j >= 0; j--)
		{
			if (nums[i] % nums[j] == 0)
			{
				if (maxLength < v[j].size())
				{
					maxLength = v[j].size();
					maxIndex = j;
				}
			}

		}

		vector<int> curV;

		if (maxIndex == -1 || v.size() == 0)
		{
			curV.push_back(nums[i]);
			v.push_back(curV);
		}
		else
		{
			curV = v[maxIndex];
			curV.push_back(nums[i]);
			v.push_back(curV);
		}

		if (maxV.size() < curV.size())
			maxV = curV;
	}

	sort(maxV.begin(), maxV.end());

	return maxV;
}

int main()
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);

	auto ret1 = largestDivisibleSubset(v1);
	for (int i = 0; i < ret1.size(); i++)
		cout << ret1[i] << " ";

	cout << endl;

	vector<int> v2;
	v2.push_back(1);
	v2.push_back(2);
	v2.push_back(4);
	v2.push_back(8);

	auto ret2 = largestDivisibleSubset(v2);
	for (int i = 0; i < ret2.size(); i++)
		cout << ret2[i] << " ";

	cout << endl;


	vector<int> v3;
	v3.push_back(1);
	v3.push_back(2);
	v3.push_back(3);
	v3.push_back(4);
	v3.push_back(6);
	v3.push_back(7);
	v3.push_back(8);
	v3.push_back(9);
	v3.push_back(27);
	v3.push_back(54);

	auto ret3 = largestDivisibleSubset(v3);
	for (int i = 0; i < ret3.size(); i++)
		cout << ret3[i] << " ";

	cout << endl;


	vector<int> v4;
	v4.push_back(1);
	v4.push_back(2);
	v4.push_back(4);
	v4.push_back(8);
	v4.push_back(9);
	v4.push_back(72);

	auto ret4 = largestDivisibleSubset(v4);
	for (int i = 0; i < ret4.size(); i++)
		cout << ret4[i] << " ";

	cout << endl;

	return 0;
}