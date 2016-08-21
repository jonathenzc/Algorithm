#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

int numSquares(int n) {
	if (n == 1)
		return 1;
	if (n == 2)
		return 2;
	if (n == 3)
		return 3;
	
	int squareCnt = sqrt(n);
	int *squareArray = new int[squareCnt];
	for (int i = 1; i <= squareCnt; i++)
		squareArray[i - 1] = i*i;

	int *dp = new int[n+1];
	for (int i = 2; i < n + 1; i++)
		dp[i] = INT_MAX;

	dp[0] = 0;
	dp[1] = 1;

	for (int i = 2; i <= n; i++)
	{
		for (int j = 0; j < squareCnt; j++)
		{
			if(i>=squareArray[j])
				dp[i] = min(dp[i], dp[i - squareArray[j]] + 1);
		}
	}

	return dp[n];
}


int main()
{
	for (int i=0; i < 20; i++)
		cout << i<<" "<<numSquares(i)<<endl;

	return 0;
}