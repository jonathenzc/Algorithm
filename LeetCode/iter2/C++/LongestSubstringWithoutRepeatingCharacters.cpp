#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <queue>
#include <stack>

using namespace std;

const int ALPHABATSIZE = 130;

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		vector<int> alphabat(ALPHABATSIZE, -1);

		int maxLen = 0;
		int curLen = 0;

		//利用alphabat来记录当前子串中字母的出现情况
		for (int i = 0; i < s.size();i++)
		{
			if (alphabat[s[i]] != -1)
			{
				maxLen = max(maxLen, curLen);
				curLen = 0;

				i = alphabat[s[i]];
				//重新初始化alphabat
				for (int j = 0; j < ALPHABATSIZE; j++)
					alphabat[j] = -1;
			}
			else
			{
				alphabat[s[i]] = i;
				curLen++;
			}
		}

		maxLen = max(maxLen, curLen);

		return maxLen;
	}
};

int main(void)
{
	Solution s;
	cout << s.lengthOfLongestSubstring("abcd") << endl;
	cout << s.lengthOfLongestSubstring("abcabcbb") << endl;
	cout << s.lengthOfLongestSubstring("bbbbb") << endl;
	cout << s.lengthOfLongestSubstring("pwwkew") << endl;
	cout << s.lengthOfLongestSubstring("ibaz") << endl;
	cout << s.lengthOfLongestSubstring("dvdf") << endl;
	

	return 0;
}