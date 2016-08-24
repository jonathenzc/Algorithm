#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int BADVERSION;

bool isInterleave(string s1, string s2, string s3) {
	int size1 = s1.size(), size2 = s2.size(), size3 = s3.size();
	if (size1 + size2 != size3)
		return false;

	int **dp = new int*[size1+1];
	for (int i = 0; i <= size1; i++)
		dp[i] = new int[size2+1];

	dp[0][0] = true;

	for (int i = 1; i <= size1;i++)
	{
		if (dp[i - 1][0] && s1[i - 1] == s3[i - 1])
			dp[i][0] = true;
		else
			dp[i][0] = false;
	}

	for (int i = 1; i <= size2; i++)
	{
		if (dp[0][i-1] && s2[i - 1] == s3[i - 1])
			dp[0][i] = true;
		else
			dp[0][i] = false;
	}

	for (int i = 1; i <= size1; i++)
	{
		for (int j = 1; j <= size2; j++)
		{
			if ((dp[i - 1][j] && s1[i - 1] == s3[i + j - 1]) || (dp[i][j - 1] && s2[j - 1] == s3[i + j - 1]))
				dp[i][j] = true;
			else
				dp[i][j] = false;
		}
	}

	return dp[size1][size2];
}

int main()
{
	if (isInterleave("aabcc", "dbbca", "aadbbcbcac"))
		cout << "Yes\n";
	else
		cout << "No\n";

	if (isInterleave("aabcc", "dbbca", "aadbbbaccc"))
		cout << "Yes\n";
	else
		cout << "No\n";

	return 0;
}