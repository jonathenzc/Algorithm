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
	string decodeString(string s) {
		int start = 0;

		return helper(s,start);
	}
private:
	vector<int> kSt;
	vector<string> encodedSt;

	string helper(string s,int &start)
	{
		string ret = "";

		int k = 0;
		string subStr = "";

		while (start < s.size())
		{
			if (s[start] >= '0' && s[start] <= '9')
				k = k * 10 + (s[start] - '0');
			else
			{
				if (s[start] == '[')
				{
					kSt.push_back(k);
					encodedSt.push_back(subStr);
					encodedSt.push_back("[");

					k = 0;
					subStr = "";
				}
				else if (s[start] == ']')
				{
					int repCnt = kSt.back();
					kSt.pop_back();

					while (true)
					{
						string encodedStr = encodedSt.back();
						encodedSt.pop_back();
						if (encodedStr[0] == '[')
							break;
						else
							subStr = encodedStr + subStr;
					}

					string combinedStr = "";
					for (int i = 0; i < repCnt; i++)
						combinedStr += subStr;

					encodedSt.push_back(combinedStr);

					subStr = "";
				}
				else
				{
					subStr += s[start];
				}
			}

			start++;
		}

		if (!encodedSt.empty())
		{
			while (!encodedSt.empty())
			{
				string tmp = encodedSt.back();
				encodedSt.pop_back();

				ret = tmp + ret;
			}
		}

		ret += subStr;

		return ret;
	}
};

void testPrint(string s)
{
	Solution ss;
	cout << ss.decodeString(s) << endl;
}

int main(void)
{
	testPrint("2[bc]");
	testPrint("efa2[bc]");
	testPrint("3[a]2[bc]");
	testPrint("3[a2[c]ed3[ff]]");
	testPrint("2[abc]3[cd]ef");
	return 0;
}