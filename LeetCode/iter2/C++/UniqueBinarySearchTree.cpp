#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int numTrees(int n) {
	int *dp = new int[n+1];
	dp[0] = 1;

	for (int i = 1; i <= n; i++)
	{
		dp[i] = 0;
		for (int j = 0; j < i; j++)
			dp[i] += dp[j] * dp[i-j-1];
	}

	return dp[n];
}

int main()
{
	cout << numTrees(3)<<endl;

	return 0;
}