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
	int countBinarySubstrings(string s) {
		int ret = 0;

		int consecutiveNum = s[0] - '0';
		int consecutiveLen = 1;
		int preConsecutiveLen = 0;

		for (int i = 1; i < s.size(); i++) {
			int sNum = s[i] - '0';

			if (sNum == consecutiveNum) {
				consecutiveLen++;
			}
			else {
				ret += min(preConsecutiveLen, consecutiveLen);

				preConsecutiveLen = consecutiveLen;
				consecutiveLen = 1;
				consecutiveNum = sNum;
			}
		}

		ret += min(preConsecutiveLen, consecutiveLen);

		return ret;
	}
};

int main(void)
{
	Solution s;
	cout << s.countBinarySubstrings("00110011") << endl;    //6
	cout << s.countBinarySubstrings("000110011") << endl;   //6
	cout << s.countBinarySubstrings("10101") << endl;       //4
	cout << s.countBinarySubstrings("01010") << endl;       //4
	cout << s.countBinarySubstrings("00110") << endl;       //3
	cout << s.countBinarySubstrings("100111001") << endl;   //6

	return 0;
}