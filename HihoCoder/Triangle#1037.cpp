#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int main()
{
	int height;
	cin >> height;

	int *dp = new int[height]{0};
	int *tmp = new int[height] {0};
	int *coupon = new int[1];
	cin >> coupon[0];

	dp[0] = coupon[0];
	tmp[0] = coupon[0];

	int i = 2;
	while (i <= height)
	{
		for (int j = 0; j < i; j++)
			cin >> coupon[j];

		for (int j = i-1; j>=0 ; j--)
		{
			if (j == 0)
				dp[j] += coupon[j];
			else
				dp[j] = max(dp[j],dp[j-1])+coupon[j];
		}

		i++;
	}


	int maxAns = 0;

	for (int i = 0; i < height; i++)
		maxAns = max(maxAns,dp[i]);

	cout << maxAns;


	return 0;
}