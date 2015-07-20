#include <iostream>
#include <vector>

using namespace std;

int max(int a, int b)
{
	if (a < b)
		return b;
	else
		return a;
}

int stolenMoney(vector<int> v, bool firstStolen)
{
	int *dp = new int[v.size()];
	dp[0] = v[0];

	if (firstStolen)
		dp[1] = v[0];
	else
	{
		dp[0] = 0;
		dp[1] = v[1];
	}

	for (int i = 2; i < v.size(); i++)
		dp[i] = max(dp[i-2]+v[i],dp[i-1]);
	
	if (firstStolen)
		return dp[v.size() - 2];
	else
		return dp[v.size()-1];
}

int rob(vector<int>& nums) 
{
	if (nums.size() == 0)
		return 0;
	
	if (nums.size() == 1)
		return nums[0];
		
	int valueWithFirst = stolenMoney(nums, true);
	int valueWithoutFirst = stolenMoney(nums,false);

	return max(valueWithFirst,valueWithoutFirst);
}

int main()
{
	//vector<int> v(2, 1);
	//v.push_back(3);
	//v.push_back(6);
	//v.push_back(7);
	//v.push_back(10);
	//v.push_back(7);
	//v.push_back(1);
	//v.push_back(8);
	//v.push_back(5);
	//v.push_back(9);
	//v.push_back(1);
	//v.push_back(4);
	//v.push_back(4);
	//v.push_back(3);


	//vector<int> v;
	//v.push_back(1);
	//v.push_back(3);
	//v.push_back(1);
	//v.push_back(3);
	//v.push_back(100);

	vector<int> v;
	v.push_back(2);
	v.push_back(1);
	v.push_back(1);
	v.push_back(1);

	cout << rob(v);

	return 0;
}
