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
	bool checkRecord(string s) {
		bool isAFound = false;
		int LCnt = 0;

		bool checkResult = true;
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == 'A') 
			{
				LCnt = 0;
				if (!isAFound)
					isAFound = true;
				else
				{
					checkResult = false;
					break;
				}
			}
			else if (s[i] == 'L')
			{
				LCnt++;
				if (LCnt > 2)
				{
					checkResult = false;
					break;
				}
			}
			else
				LCnt = 0;
		}

		return checkResult;
	}
};

void testPrint(string s)
{
	Solution ss;
	if (ss.checkRecord(s))
		cout << s << " is good\n";
	else
		cout << s << " is bad\n";
}

int main(void)
{
	testPrint("PPALLP");
	testPrint("PPALLL");

	return 0;
}