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
	string toHex(int num) {

		string hexStr = "";
		long long integerMax = INT_MAX;
		long long doubleINT_MAX = integerMax * 2+1;

		//取反+1.  3的反码是FFFC,则加一后,-3的Hex是FFFD
		if (num < 0)
			hexStr = dividedBy16(doubleINT_MAX +num+1);
		else
			hexStr = dividedBy16(num);

		return hexStr;
	}
private:

	string dividedBy16(long long num)
	{
		if (num == 0)
			return "0";

		string ret = "";

		while (num > 0)
		{
			long long digit = num % 16;
			if (digit > 9)
				ret = char((digit - 10) + 'a') + ret;
			else
				ret = char(digit + '0') + ret;

			num = num / 16;
		}

		return ret;
	}
};

int main(void)
{
	Solution s;
	cout << s.toHex(0) << endl; //1a
	cout << s.toHex(26) << endl; //1a
	cout << s.toHex(1523) << endl; //5f3
	cout << s.toHex(6436) << endl; //1924
	cout << s.toHex(7658) << endl; //1dea
	cout << s.toHex(-1) << endl;
	cout << s.toHex(-3) << endl;

	return 0;
}