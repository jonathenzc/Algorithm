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
	int myAtoi(string str) {
		//先去掉空格
		int startIndex = 0;
		while (startIndex<str.size() && str[startIndex] == ' ')
			startIndex++;

		long long ret = 0;

		bool isNegative = false;

		if (str[startIndex] == '-') {
			isNegative = true;	
			startIndex++;
		}
		else if (str[startIndex] == '+')
			startIndex++;

		int i = startIndex;
		for (; i < str.size(); i++) 
		{
			if (str[i] >= '0' && str[i] <= '9')
				ret = 10 * ret + (str[i] - '0');
			else
				break;
		}

		if (i - startIndex > 10)
		{
			if (isNegative)
				return INT_MIN;
			else
				return INT_MAX;
		}

		if (isNegative)
			ret = -ret;

		if (ret > INT_MAX)
			ret = INT_MAX;

		if (ret < INT_MIN)
			ret = INT_MIN;

		return ret;
	}
};

int main(void)
{
	Solution s;

	cout << s.myAtoi("9223372036854775809") << endl;
	cout << s.myAtoi("   -1123u3761867") << endl;
	cout << s.myAtoi("-1") << endl;
	cout << s.myAtoi("23") << endl;
	cout << s.myAtoi("2147483647") << endl;
	cout << s.myAtoi("-2147483647") << endl;
	cout << s.myAtoi("-2147483648") << endl;
	cout << s.myAtoi("+") << endl;
	cout << s.myAtoi("+-2") << endl;
	cout << s.myAtoi("+-") << endl;
	cout << s.myAtoi("    010") << endl;
	cout << s.myAtoi("  -0012a42") << endl;

	return 0;
}