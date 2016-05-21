#include <iostream>

using namespace std;

int divide(int dividend, int divisor) {
	long long dividend_long = (long long)dividend;
	long long divisor_long = (long long)divisor;
	
	if (divisor == 0)
		return INT_MAX;

	if (dividend == 0)
		return 0;

	if (divisor == 1)
		return dividend;

	if (divisor == -1)
	{
		if (dividend == INT_MIN)
			return INT_MAX;

		return -dividend;
	}

	if (dividend == divisor)
		return 1;

	if (dividend == divisor)
		return -1;

	bool isNegative = false;
	if ((dividend_long < 0 && divisor_long > 0) || (dividend_long > 0 && divisor_long < 0))
		isNegative = true;

	if (dividend_long < 0)
		dividend_long = -dividend_long;

	if (divisor_long < 0)
		divisor_long = -divisor_long;

	if (dividend_long < divisor_long)
		return 0;

	long long sum = divisor_long;
	int base = 1;

	//通过左移确定范围
	while (dividend_long > sum)
	{
		sum = sum << 1;
		base = base << 1;
	}

	int result = 0;

	while (dividend_long >= divisor_long)
	{
		while (dividend_long >= sum)
		{
			dividend_long -= sum;
			result += base;
		}

		sum = sum >> 1;
		base = base >> 1;
	}

	if (isNegative)
		result = -result;

	return result;
}

int main()
{
	cout << divide(6, 3) << endl;
	cout << divide(-6, 3) << endl;
	cout << divide(7, 3) << endl;
	cout << divide(-7, 3) << endl;

	cout << divide(15, 3) << endl;
	cout << divide(-15, 3) << endl;
	cout << divide(20, 3) << endl;
	cout << divide(-20, 3) << endl;

	cout << divide(2147483647, 2) << endl;
	cout << divide(1004958205, -2137325331) << endl;
	cout << divide(-1006986286, -2145851451) << endl;
	cout << divide(-1010369383, 2147483648) << endl;
	cout << divide(-2147483647, -1) << endl;

	cout << divide(INT_MIN, -1) << endl;

	return 0;
}