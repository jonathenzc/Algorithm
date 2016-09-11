#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <sstream>
#include <unordered_map>

using namespace std;

void helper(long long n, int&step) {
	if (n > 1) {
		if ((n & 1) == 1) //奇数
		{
			int stepPlus = step + 1;
			helper(n + 1, stepPlus);
			int stepMinus = step + 1;
			helper(n - 1, stepMinus);

			step = min(stepPlus,stepMinus);
		}
		else
		{
			step++;
			helper(n / 2, step);
		}
	}
}

int integerReplacement(int n) {
	if (n == 1)
		return 0;

	long long nn = n;
	int step = 0;
	
	if ((nn & 1) == 1) //奇数
	{
		int stepPlus = 1;
		int stepMinus = 1;
		helper(nn + 1, stepPlus);
		helper(nn - 1, stepMinus);

		step = min(stepPlus,stepMinus);
	}
	else
	{
		step++;
		helper(nn /2,step);
	}

	return step;
}

int main()
{
	cout << integerReplacement(8) << endl;
	cout << integerReplacement(7) << endl;
	cout << integerReplacement(3) << endl;
	cout << integerReplacement(65535) << endl;
	cout << integerReplacement(2147483647) << endl;

	return 0;
}
