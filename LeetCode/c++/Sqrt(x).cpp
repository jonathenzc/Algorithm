#include <iostream>

using namespace std;

//牛顿法
int mySqrt(int x) {
	if (x <= 0)
		return 0;

	double precision = 0.01;

	double pre = 0;
	double result = x;

	while (result - pre > precision || pre - result > precision)
	{
		pre = result;
		result = result / 2.0 + x / 2.0 / result;
	}

	return result;
}

int main()
{
	for (int i = 1; i < 40; i++)
		cout << i<<" "<<mySqrt(i) << endl;

	return 0;
}