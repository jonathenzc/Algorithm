#include <iostream>

using namespace std;

double myPow(double x, int n) {
	if (n == 0 || x == 1) //处理底数是1或者指数为0
		return 1.0;

	if (x == 0 && n < 0) //处理过小
		return INFINITY;

	if (x == -1)//处理-1
	{
		if (n & 1 == 1) //奇数
			return -1;
		else
			return 1;
	}

	if (x <= -2 || x >= 2)
	{
		if (n > 1000)//处理过大的数
			return INFINITY;
		else if (n < -1000)
			return 0.000001;
	}

	bool isNegative = false;
	if (n < 0)
	{
		isNegative = true;
		n = -n;
	}

	double result = 1;
	double base = x;
	while (n != 0) //快速幂算法
	{
		if (n & 1 == 1)
			result = result * base;
		base = base*base;
		n = n >> 1;
	}

	if (isNegative && x != 0)
		result = 1.0 / result;

	return result;
}

int main()
{
	cout << myPow(2,3)<<endl;
	cout << myPow(3.2, 3) << endl;
	cout << myPow(4, -3) << endl;
	cout << myPow(2, -2) << endl;
	cout << myPow(-4, -3) << endl;
	cout << myPow(-2, -2) << endl;
	cout << myPow(0, -3) << endl;
	cout << myPow(0, 0) << endl;
	cout << myPow(0.00001, 2147483647) << endl;
	cout << myPow(3,1000) << endl;

	return 0;
}