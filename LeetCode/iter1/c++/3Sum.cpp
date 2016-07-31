#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void helper(int num, int num_index, int target, vector<int>& nums, vector<vector<int>> &v)
{
	int i = num_index + 1, j = nums.size() - 1;

	while (i < j)
	{
		int num_i = nums[i];
		int num_j = nums[j];
		int sum = num_i + num_j;
		if (sum == target)
		{
			vector<int> tmpV;
			tmpV.push_back(num);
			tmpV.push_back(nums[i]);
			tmpV.push_back(nums[j]);

			v.push_back(tmpV);

			//忽视掉重复的数
			while(i<nums.size() && num_i == nums[i])
				i++;	

			while (j>=0 && num_j == nums[j])
				j--;
		}
		else if (sum < target) //只能提高最小的数，因为排序后的num[j]是最大的数
			i++;
		else
			j--;

	}
}


vector<vector<int>> threeSum(vector<int>& nums) {
	vector<vector<int>> v;

	sort(nums.begin(), nums.end());

	for (int i = 0; i < nums.size(); )
	{
		helper(nums[i], i, 0 - nums[i], nums, v);

		int num = nums[i];

		while (i<nums.size() && num == nums[i])
			i++;
	}

	return v;
}

void testPrint(vector<int> v, int target)
{
	vector<vector<int>> resultV = threeSum(v);

	for (int i = 0; i < resultV.size(); i++)
	{
		cout << "[ ";

		for (int j = 0; j < resultV[i].size(); j++)
			cout << resultV[i][j] << " ";

		cout << "]\n";
	}

	cout << endl;
}

int main()
{
	vector<int> v;
	v.push_back(-1);
	v.push_back(0);
	v.push_back(1);
	v.push_back(2);
	v.push_back(-1);
	v.push_back(-4);



	testPrint(v, 0);


	vector<int> v1;
	v1.push_back(-2);
	v1.push_back(0);
	v1.push_back(0);
	v1.push_back(2);
	v1.push_back(2);

	testPrint(v1, 0);

	return 0;
}