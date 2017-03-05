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
	string countAndSay(int n) {
		string curStr = "1";
		int cnt = 1;
		
		while (cnt < n)
		{
			curStr = helper(curStr);
			cnt++;
		}

		return curStr;
	}
private:
	string helper(string s)
	{
		string tmpStr = "";

		//遍历当前s
		int i = 1;
		int sameCnt = 1;
		char preChar = s[0];

		while (i < s.size())
		{
			if (preChar == s[i])
				sameCnt++;
			else
			{
				tmpStr += to_string(sameCnt);
				tmpStr += preChar;

				sameCnt = 1;
				preChar = s[i];
			}

			i++;
		}

		tmpStr += to_string(sameCnt);
		tmpStr += preChar;

		return tmpStr;
	}

	//使用to_string效率提高很多
	string int2str(int num)
	{
		stringstream ss;
		ss << num;
		string s;
		ss >> s;

		return s;
	}
};

int main(void)
{
	Solution s;
	for (int i = 1; i < 8; i++)
		cout << i<<" "<<s.countAndSay(i) << endl;

	return 0;
}