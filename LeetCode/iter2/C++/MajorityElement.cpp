#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int majorityElement(vector<int>& nums) {
	unordered_map<int, int> map;
	int maxCnt = 0;
	int maxNum = nums[0];

	for (int i = 0; i < nums.size(); i++)
	{
		map[nums[i]]++;

		int cnt = map[nums[i]];

		if (cnt > maxCnt)
		{
			maxCnt = cnt;
			maxNum = nums[i];
		}
	}

	return maxNum;
}



int main()
{
	vector<int> v;
	v.push_back(2);
	v.push_back(2);
	v.push_back(2);
	v.push_back(1);
	v.push_back(1);
	v.push_back(3);
	v.push_back(3);
	v.push_back(4);

	cout << majorityElement(v) << endl;

	return 0;
}