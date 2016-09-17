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
	bool canWordBreak(string s, unordered_set<string>& wordDict) {
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


	vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
		
		if (canWordBreak(s, wordDict))
		{

			string target = "";

			helper(0, target, s, wordDict);
		}

		return v;
	}
private:
	vector<string> v;

	void helper(int start, string target, string s, unordered_set<string>& wordDict) {

		for (auto iter = wordDict.begin(); iter != wordDict.end(); iter++)
		{

			if (start + (*iter).size() <= s.size()) {
				string subStr = s.substr(start, (*iter).size());
				if (subStr.compare((*iter)) == 0)
				{
					string tmpStr = target + subStr + " ";

					if (start + subStr.size() >= s.size()) {
						tmpStr.pop_back();
						v.push_back(tmpStr);
					}
					else
					{
						helper(start + subStr.size(), tmpStr, s, wordDict);
					}
				}
			}
		}


	}
};

int main()
{
	Solution s;

	unordered_set<string> wordDict;
	wordDict.insert("cat");
	wordDict.insert("cats");
	wordDict.insert("and");
	wordDict.insert("sand");
	wordDict.insert("dog");

	vector<string> v = s.wordBreak("catsanddog", wordDict);

	for (string str : v)
		cout << str << endl;

	return 0;
}