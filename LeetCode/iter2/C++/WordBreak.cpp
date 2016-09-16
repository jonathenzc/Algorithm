#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
	bool wordBreak(string s, unordered_set<string>& wordDict) {
		vector<bool> dp(s.size()+1,false);

		dp[0] = true;

		for (int i = 1; i <= s.size(); i++) {

			for (auto iter = wordDict.begin(); iter != wordDict.end(); iter++)
			{
				if ((*iter).size() <= i)
					dp[i] = dp[i] || dp[i - (*iter).size()] && (*iter == s.substr(i - (*iter).size(),(*iter).size()));
			}
		}

		return dp[s.size()];
	}
};

int main()
{
	Solution s;

	unordered_set<string> wordDict;
	wordDict.insert("leet");
	wordDict.insert("code");

	if (s.wordBreak("leetcode", wordDict))
		cout << "Yes\n";
	else
		cout << "No\n";

	return 0;
}