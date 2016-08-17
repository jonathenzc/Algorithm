#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int coinChange(vector<int>& coins, int amount) {
	int *dp = new int[amount + 1];
	dp[0] = 0;
	
	for (int i = 1; i <= amount; i++)
	{
		int minChanges = INT_MAX;
		for (int j = 0; j < coins.size(); j++)
		{
			if (i >= coins[j] && dp[i-coins[j]] != INT_MAX)
				minChanges = min(minChanges,dp[i-coins[j]]+1);
		}

		dp[i] = minChanges;
	}

	if (dp[amount] == INT_MAX)
		dp[amount] = -1;

	return dp[amount];
}

int main()
{
	vector<int> coins;
	coins.push_back(1);
	coins.push_back(2);
	coins.push_back(5);

	cout << coinChange(coins, 11)<<endl;

	vector<int> coins1;
	coins1.push_back(2);

	cout << coinChange(coins1, 3) << endl;
	return 0;
}