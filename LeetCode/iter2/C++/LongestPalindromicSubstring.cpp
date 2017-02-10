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

class Solution {
public:
	string longestPalindrome(string s) {
		if (s.size() == 0)
			return s;

		//选中中间点，从两边扩出去
		string ret = "";
		for (int i = 0; i < s.size(); i++)
		{
			string oddStr = subPalindrome(s, i, i);
			if (ret.size() < oddStr.size())
				ret = oddStr;

			string evenStr = subPalindrome(s, i, i + 1);
			if (ret.size() < evenStr.size())
				ret = evenStr;
		}

		return ret;
	}
private:
	string subPalindrome(string s, int leftStart, int rightStart)
	{
		while (leftStart >= 0 && rightStart < s.size())
		{
			if (s[leftStart] != s[rightStart])
				break;

			leftStart--;
			rightStart++;
		}

		return s.substr(leftStart + 1, rightStart - leftStart - 1);
	}
};

int main(void)
{
	Solution s;
	//cout << s.longestPalindrome("a") << endl;
	cout << s.longestPalindrome("babad") << endl;
	cout << s.longestPalindrome("cbbd") << endl;
	cout << s.longestPalindrome("babab") << endl;
	cout << s.longestPalindrome("cc") << endl;
	cout << s.longestPalindrome("ab") << endl;
	cout << s.longestPalindrome("abcde") << endl;
	cout << s.longestPalindrome("abcdef") << endl;

	return 0;
}