#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

int integerBreak(int n) {
	if (n <= 0)
		return 0;
	if (n <= 2)
		return 1;
	if (n == 3)
		return 2;
	if (n == 4)
		return 4;

	int threeCnt = n / 3;
	int rest = n - threeCnt*3;

	int result = 1;

	if (rest <= 1) {
		for (int i = 0; i < threeCnt - rest; i++)
			result *= 3;

		for (int i = 0; i < rest; i++)
			result *= 4;
	}
	else
	{
		for (int i = 0; i < threeCnt; i++)
			result *= 3;

		result *= 2;
	}

	return result;
}


int main()
{
	for (int i = 0; i < 26; i++)
		cout << i << " " << integerBreak(i) << endl;
	
	return 0;
}