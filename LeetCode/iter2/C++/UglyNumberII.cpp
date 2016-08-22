#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int nthUglyNumber(int n) {
	int *dp = new int[n];
	dp[0] = 1;
	int twoI = 0, threeI = 0,fiveI = 0;

	for (int i = 1; i < n; i++)
	{
		int two = 2 * dp[twoI];
		int three = 3 * dp[threeI];
		int five = 5 * dp[fiveI];

		if (two <= three && two <= five) //min two
		{
			dp[i] = two;
			twoI++;

			if (two == three)
				threeI++;
			if (two == five)
				fiveI++;
		}
		else if (three <= two && three <= five) //min three
		{
			dp[i] = three;
			threeI++;

			if (three == two)
				twoI++;
			if (three == five)
				fiveI++;
		}
		else if (five <= two && five <= three) //min five
		{
			dp[i] = five;
			fiveI++;

			if (five == two)
				twoI++;
			if (five == three)
				threeI++;
		}
	}

	return dp[n - 1];
}

int main()
{
	for (int i = 0; i < 16; i++)
		cout << nthUglyNumber(i) << endl;
	


	return 0;
}