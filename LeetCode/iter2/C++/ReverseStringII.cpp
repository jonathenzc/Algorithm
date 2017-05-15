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
	string reverseStr(string s, int k) {
		int start = 0;

		while (start < s.size())
		{
			int end = start + k - 1;
			if(end >= s.size())
				end = s.size() - 1;

			reverseHelper(s, start, end);
			start += 2*k;
		}

		return s;
	}
private:
	void reverseHelper(string &s,int start,int end)
	{
		while (start < end)
		{
			char tmp = s[start];
			s[start] = s[end];
			s[end] = tmp;

			start++;
			end--;
		}
	}
};

int main(void)
{
	Solution s;
	cout << s.reverseStr("abcdefg",2) << endl;
	cout << s.reverseStr("abcdefg", 3) << endl;
	cout << s.reverseStr("abcdefghijk", 3) << endl;


	return 0;
}