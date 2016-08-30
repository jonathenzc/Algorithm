#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

bool isMatch(string s, string p) {
	bool **dp = new bool*[s.size()+1];
	for (int i = 0; i <= s.size(); i++)
		dp[i] = new bool[p.size()+1];

	dp[0][0] = true;

	for (int i = 1; i <= s.size(); i++)
		dp[i][0] = false;

	for (int i = 1; i <= p.size(); i++) {
		if (p[i - 1] == '*')
			dp[0][i] = dp[0][i - 2];
		else
			dp[0][i] = false;
	}

	for (int i = 1; i <= s.size(); i++)
	{
		for (int j = 1; j <= p.size(); j++)
		{
			if (p[j - 1] == '*')
				dp[i][j] = dp[i][j-2] || (dp[i-1][j] && (s[i - 1] == p[j - 2] || p[j - 2] == '.'));
			else
				dp[i][j] = dp[i - 1][j - 1] && (s[i-1] == p[j-1] || p[j-1] == '.');
		}
	}

	return dp[s.size()][p.size()];
}

void testPrint(string a, string b)
{
	cout << a << " " << b;

	if (isMatch(a, b))
		cout << " Yes\n";
	else
		cout << " No\n";
}

int main()
{
	testPrint("aa", "a"); // false
	testPrint("aa", "aa"); // true
	testPrint("aaa", "aa"); //false
	testPrint("aa", "a*"); //true
	testPrint("aa", "b*"); //false
	testPrint("aa", ".*"); // true
	testPrint("ab", ".*"); // true
	testPrint("aab", "c*a*b"); // true
	testPrint("aab", "a*a*b"); // true

	testPrint("aaa","ab*ac*a"); //true
}