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
	double myPow(double x, int n) {
		if (x == 0 || x == 1)
			return x;

		if (x == -1)
		{
			if (n & 1 == 1) //奇数
				return -1;
			else
				return 1;
		}

		bool isNegative = false;
		long long nL = n;
		if (n < 0)
		{
			isNegative = true;
			nL = -nL;
		}

		long long cnt = 1;
		double ret = x;

		while (cnt < nL)
		{
			ret = ret*ret;
			cnt *= 2;
		}

		while (cnt > nL)
		{
			ret /= x;
			cnt--;
		}
		
		if (isNegative)
			ret = 1.0 / ret;

		return ret;
	}
};

int main(void)
{
	Solution s;
	cout << s.myPow(2, 1) << endl;
	cout << s.myPow(2, -1) << endl;
	cout << s.myPow(2, -6) << endl;
	cout << s.myPow(2,6) << endl;
	cout << s.myPow(-2, 7) << endl;
	cout << s.myPow(-2, 8) << endl;
	cout << s.myPow(2, 8) << endl;
	cout << s.myPow(2, 9) << endl;
	cout << s.myPow(2, 10) << endl;
	cout << s.myPow(0.00001, 2147483647) << endl;
	cout << s.myPow(2, -2147483648) << endl;

	return 0;
}