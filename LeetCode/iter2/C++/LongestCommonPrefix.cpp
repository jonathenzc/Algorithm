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
	string longestCommonPrefix(vector<string>& strs) {
		if (strs.size() == 0)
			return "";

		//找出最短的字符串长度
		int minStrLen = INT_MAX;
		for (string s : strs)
			minStrLen = min(minStrLen, (int)s.size());

		string candidate = "";
		string cur = "";

		bool isCommon = true;
		for (int i = 0; i < minStrLen && isCommon; i++)
		{
			for (int j = 0; j < strs.size()-1; j++)
			{
				if (strs[j][i] != strs[j + 1][i])
				{
					isCommon = false;
					break;
				}
			}

			if (isCommon)
				candidate += strs[0][i];
		}

		return candidate;
	}
};

int main(void)
{
	vector<string> v;
	v.push_back("abcdefg");
	v.push_back("abcde");
	v.push_back("accdefgre");

	Solution s;
	cout << s.longestCommonPrefix(v) << endl;

	return 0;
}