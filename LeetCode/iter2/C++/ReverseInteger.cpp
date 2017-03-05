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
	int reverse(int x) {
		long long longNum = x;
		bool isNegative = false;
		if (longNum < 0) {
			longNum = -longNum;
			isNegative = true;
		}

		stringstream ss;
		ss << longNum;
		string s;
		ss >> s;

		//翻转字符串
		int start = 0, end = s.size() - 1;
		while (start < end)
		{
			char tmp = s[start];
			s[start] = s[end];
			s[end] = tmp;
			start++;
			end--;
		}

		ss.clear();

		ss << s;
		ss >> longNum;
		int ret = 0;
		if (longNum <= (long long)INT_MAX)
		{
			ret = longNum;
			if (isNegative)
				ret = -ret;
		}

		return ret;
	}
};

int main(void)
{
	Solution s;
	cout << s.reverse(123) << endl;
	cout << s.reverse(-123) << endl;
	cout << s.reverse(10100) << endl;
	cout << s.reverse(1000000003) << endl;
	 
	return 0;
}