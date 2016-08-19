#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;


int numDistinct(string s, string t) {
	if (t.size() == 0)
		return 1;

	if (s.size() == 0)
		return 0;

	int **dp = new int*[s.size()+1];
	for (int i = 0; i <= s.size(); i++)
		dp[i] = new int[t.size()+1];

	for (int i = 0; i <= s.size(); i++)
		dp[i][0] = 1;

	for (int i = 1; i <= t.size(); i++)
		dp[0][i] = 0;

	for (int i = 1; i <= s.size(); i++)
	{
		for (int j = 1; j <= t.size(); j++)
		{
			if (s[i-1] == t[j-1])
				dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
			else
				dp[i][j] = dp[i - 1][j];
		}
	}

	return dp[s.size()][t.size()];
}

int main()
{
	cout << numDistinct("rabbbit","rabbit")<<endl;
	cout << numDistinct("ccc", "c")<<endl;

	return 0;
}