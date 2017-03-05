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

struct cntIndex
{
	int cnt;
	int index;
};

class Solution {
public:
	int firstUniqChar(string s) {
		cntIndex *cntIndexMap = new cntIndex[26];
		for (int i = 0; i < 26; i++)
			cntIndexMap[i].cnt = 0;

		for (int i = 0; i < s.size(); i++)
		{
			cntIndexMap[s[i] - 'a'].cnt++;

			if (cntIndexMap[s[i] - 'a'].cnt == 1)
				cntIndexMap[s[i] - 'a'].index = i;
		}

		//查找个数为1且index最少的
		int minIndex = INT_MAX;

		for (int i = 0; i < 26; i++)
		{
			if (cntIndexMap[i].cnt == 1)
				minIndex = min(cntIndexMap[i].index,minIndex);
		}

		if (minIndex == INT_MAX)
			minIndex = -1;

		return minIndex;
	}
};

void testPrint(string str)
{
	Solution s;
	
	cout << s.firstUniqChar(str) << endl;
}

int main(void)
{
	testPrint("leetcode");
	testPrint("loveleetcode");

	return 0;
}