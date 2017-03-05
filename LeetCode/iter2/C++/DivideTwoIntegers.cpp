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
	int divide(int dividend, int divisor) {
		if (divisor == 0)
			return INT_MAX;

		if (dividend == 0)
			return 0;

		if (divisor == 1)
			return dividend;

		if (dividend == INT_MIN && divisor == -1) //overflow
			return INT_MAX;

		long long dividendL = dividend;
		long long divisorL = divisor;

		bool isNegative = false;
		if (dividendL < 0 && divisorL > 0 || dividendL > 0 && divisorL < 0)
			isNegative = true;
		
		if (dividendL < 0)
			dividendL = -dividendL;

		if (divisorL < 0)
			divisorL = -divisorL;

		//确定最大的二进制位
		long long sumL = divisorL;
		long long bit = 1;

		while (dividendL > sumL)
		{
			sumL <<= 1;
			bit <<= 1;
		}

		int ret = 0;

		while (dividendL >= divisorL)
		{
			while (dividendL >= sumL) 
			{
				dividendL -= sumL;
				ret += bit;
			}

			bit >>= 1;
			sumL >>= 1;
		}
		
		if (isNegative)
			ret = -ret;

		return ret;
	}
};

int main(void)
{
	Solution s;
	cout << s.divide(1, -1) << endl;
	cout << s.divide(-5,-2) << endl;
	cout << s.divide(20, 3) << endl;
	cout << s.divide(21, 3) << endl;
	cout << s.divide(32,2) << endl;
	cout << s.divide(INT_MIN, 2) << endl;

	return 0;
}