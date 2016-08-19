#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int maxCoins(vector<int>& nums) {
	int n = nums.size();
	nums.insert(nums.begin(), 1);
	nums.push_back(1);

	int **dp = new int*[n+2];
	for (int i = 0; i < n + 2; i++)
	{
		dp[i] = new int[n + 2];
		for (int j = 0; j < n + 2; j++)
			dp[i][j] = 0;
	}

	for (int len = 1; len <= n; len++)
	{
		for (int start = 1; start <= n - len+1; start++)
		{
			int end = start + len - 1;

			int maxCoin = INT_MIN;
			for (int i = start; i <= end; i++)
			{
				int cur = dp[start][i-1] + dp[i + 1][end];
				cur += nums[start-1] * nums[i] * nums[end+1];

				maxCoin = max(cur,maxCoin);
			}

			dp[start][end] = maxCoin;
		}
	}

	return dp[1][n];
}

int main()
{
	vector<int> v;
	v.push_back(3);
	v.push_back(1);
	v.push_back(5);
	v.push_back(8);

	cout << maxCoins(v)<<endl;

	return 0;
}