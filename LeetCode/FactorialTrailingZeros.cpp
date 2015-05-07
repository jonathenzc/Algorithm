#include <iostream>

using namespace std;

int trailingZeroes(int n) 
{
	int zeroCnt = 0;
	int fivePow = 5;

	while (n/fivePow != 0)
	{
		zeroCnt += n/fivePow;

		if (n / fivePow == 1)//´¦ÀíÒç³ö
			break;

		fivePow *= 5;
	}


	return zeroCnt;
}

int main()
{
	cout << trailingZeroes(1000);

	return 0;
}