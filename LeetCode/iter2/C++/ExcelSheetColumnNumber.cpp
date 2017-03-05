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
	int titleToNumber(string s) {
		int bitCnt = 0;
		int ret = 0;

		for (int i = s.size() - 1; i >= 0; i--)
		{
			//获取26的基数
			int base = 1;
			int j = 0;
			while (j < bitCnt)
			{
				base *= 26;
				j++;
			}
			
			ret += base*(s[i] - 'A' + 1);

			bitCnt++;
		}

		return ret;
	}
};

void testPrint(string str)
{
	Solution s;

	cout << str <<" Excel Sheet Column Number "<<s.titleToNumber(str) << endl;
}

int main(void)
{
	testPrint("A");
	testPrint("Z");
	testPrint("AA");
	testPrint("AB");
	testPrint("AAA");

	return 0;
}