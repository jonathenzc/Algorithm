#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minDistance(string word1, string word2) {
	int **dp = new int*[word1.size()+1];
	for (int i = 0; i <= word1.size(); i++)
		dp[i] = new int[word2.size()+1];

	for (int i = 0; i <= word1.size(); i++)
		dp[i][0] = i;

	for (int i = 0; i <= word2.size(); i++)
		dp[0][i] = i;

	for (int i = 1; i <= word1.size(); i++)
	{
		for (int j = 1; j <= word2.size(); j++)
		{
			dp[i][j] = min(dp[i-1][j],dp[i][j-1])+1;

			int replaceMin = dp[i-1][j-1];
			if (word1[i - 1] != word2[j - 1])
				replaceMin++;

			dp[i][j] = min(dp[i][j],replaceMin);
		}
	}

	return dp[word1.size()][word2.size()];
}

int main()
{
	cout << minDistance("a","ab") << endl;
	cout << minDistance("a", "ba") << endl;
	cout << minDistance("a", "b") << endl;
	cout << minDistance("a", "bb") << endl;
	return 0;
}