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
#include <map>

using namespace std;

class Solution {
public:
	bool repeatedSubstringPattern(string s) {
		if (s.size() <= 1)
			return false;

		int sublen = s.size() / 2;
		bool isRepeated = false;

		while (sublen > 0 && !isRepeated)
		{
			int start1 = 0, start2 = sublen;

			while (start2 < s.size() && isEqual(s, start1, start2, sublen))
			{
				start1 = start2;
				start2 += sublen;

				if (start2 == s.size())
					isRepeated = true;
			}

			sublen--;
		}

		return isRepeated;
	}
private:
	bool isEqual(string s, int start1, int start2, int size)
	{
		bool isEqual = true;
		int i = 0;
		while (start1 < s.size() && start2 < s.size() && i < size)
		{
			if (s[start1] != s[start2])
			{
				isEqual = false;
				break;
			}

			start1++;
			start2++;
			i++;
		}

		return isEqual;
	}
};

void testPrint(string str)
{
	Solution s;
	if (s.repeatedSubstringPattern(str))
		cout << "[" << str << "] is repeated\n";
	else
		cout << "[" << str << "] is not repeated\n";
}

int main(void)
{
	testPrint("aabaaba");
	testPrint("");
	testPrint("a");
	testPrint("aa");
	testPrint("aaa");
	testPrint("ab");
	testPrint("aba");
	testPrint("abba");
	testPrint("abab");
	testPrint("ababab");
	testPrint("ababababab");
	testPrint("abcdefabcdef");
	testPrint("abcabcabc");
	testPrint("abcabceabcabc");

	return 0;
}