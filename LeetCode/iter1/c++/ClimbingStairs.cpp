#include <iostream>

using namespace std;

int climbStairs(int n)
{
	if (n < 0)
		return 0;
	else if (n == 0)
		return 1;
	else
	{
		int *waysToTop = new int[n + 1];
		waysToTop[0] = 1;
		waysToTop[1] = 1;

		for (int i = 2; i <= n; i++)
			waysToTop[i] = waysToTop[i - 1] + waysToTop[i - 2];

		return waysToTop[n];
	}
}

int main()
{
	cout << climbStairs(5)<<" "<<climbStairs(2);

	return 0;
}