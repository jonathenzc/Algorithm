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
	bool detectCapitalUse(string word) {
		if (word.size() == 0 || word.size() == 1)
			return true;

		bool startCapital = isCapital(word[0]);
		bool secondCapital = isCapital(word[1]);

		if (!startCapital && secondCapital)
			return false;

		bool isValid = true;

		for (int i = 2; i < word.size(); i++)
		{
			if (word[i] >= 'A' && word[i] <= 'Z')
			{
				//第一个字母小写，之后出现大写 或者 有小写出现大写
				if (!startCapital || !secondCapital)
				{
					isValid = false;
					break;
				}
			}
			else
			{
				if (secondCapital)
				{
					isValid = false;
					break;
				}
			}
		}

		return isValid;
	}
private:
	bool isCapital(char ch)
	{
		return ch >= 'A' && ch <= 'Z';
	}
};

void testPrint(string s)
{
	Solution ss;
	if (ss.detectCapitalUse(s))
		cout << s << " true\n";
	else
		cout << s << " no\n";
}

int main(void)
{
	testPrint("");
	testPrint("GG");
	testPrint("Ge");
	testPrint("USA");
	testPrint("Google");
	testPrint("G");
	testPrint("g");
	testPrint("GOOGLE");
	testPrint("GOogle");
	testPrint("GOOgle");
	testPrint("GoOgle");
	testPrint("GoOGle");
	testPrint("GooGle");
	testPrint("FlaG");
	testPrint("flaG");
	testPrint("leetcode");


	return 0;
}