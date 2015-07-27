#include <iostream>
#include <vector>

using namespace std;

int rob(vector<int>& nums)
{
	if (nums.size() == 0)
		return 0;
	else
	{
		int *moneyStash = new int[nums.size()];//moneyStash[i]表示从nums[0]到nums[i]能拿到最多的钱
		moneyStash[0] = nums[0];

		if (nums[1] > nums[0])
			moneyStash[1] = nums[1];
		else
			moneyStash[1] = nums[0];

		for (int i = 2; i < nums.size(); i++)
		{
			int temp = nums[i] + moneyStash[i - 2];
			if (temp > moneyStash[i - 1])
				moneyStash[i] = temp;
			else
				moneyStash[i] = moneyStash[i - 1];
		}

		return moneyStash[nums.size() - 1];
	}
}

int main()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(1);
	v.push_back(1);
	v.push_back(100);

	cout << rob(v)<<endl;

	return 0;
}