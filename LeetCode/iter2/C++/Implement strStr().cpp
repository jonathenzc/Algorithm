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
	int strStr(string haystack, string needle) {
		if (needle.size() == 0)
			return 0;

		int hIndex = 0;
		int nIndex = 0;

		int retIndex = -1;
		
		while (hIndex < haystack.size())
		{
			if (needle[nIndex] == haystack[hIndex])
			{
				if (nIndex == 0)
				{
					if (haystack.size() - hIndex < needle.size())
						break;

					retIndex = hIndex;
				}

				if (nIndex == needle.size() - 1)
					break;


				nIndex++;
				hIndex++;
			}
			else
			{
				if (retIndex != -1)
					hIndex = retIndex + 1;
				else
					hIndex++;

				nIndex = 0;
				retIndex = -1;
			}
		}

		return retIndex;
	}
};

int main(void)
{
	Solution s;
	cout << s.strStr("abcdefg", "") << endl; //0
	cout << s.strStr("abcdefg","def") << endl; //3
	cout << s.strStr("abcdefg", "defg") << endl; //3
	cout << s.strStr("abcaaaaabcdefg", "abcd") << endl; //7
	cout << s.strStr("abcdefg", "defgh") << endl; //-1
	cout << s.strStr("abcdefgg", "defgh") << endl; //-1
	cout << s.strStr("abcdefg", "abcdefgh") << endl; //-1
	cout << s.strStr("abcdefg", "abcefgh") << endl; //-1

	return 0;
}