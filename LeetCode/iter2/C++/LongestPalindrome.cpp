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
	int longestPalindrome(string s) {
		vector<int> letterDict(60,0);

		//先构建一个大小写字母的映射
		for (int i = 0; i < s.size(); i++)
			letterDict[s[i] - 'A']++;
		
		//遍历letterDict，统计出现次数为偶数的个数，和出现次数最多的奇数
		bool hasOdd = false;
		int palinLen = 0;
		for (int i = 0; i < 60; i++)
		{
			if (letterDict[i] & 1 == 1) //奇数
			{
				palinLen += letterDict[i] - 1;
				hasOdd = true;
			}
			else
				palinLen += letterDict[i];
		}

		if (hasOdd)
			palinLen++;

		return palinLen;
	}
};

void testPrint(string str)
{
	Solution s;

	cout << str <<" len palindrome "<<s.longestPalindrome(str) << endl;
}

int main(void)
{
	testPrint("abccccdd");
	testPrint("aabbbbcccddddd");

	return 0;
}