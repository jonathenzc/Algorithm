#include <iostream>

using namespace std;

int min(int *num,int &a,int &b,int &c)
{
	int two = 2 * num[a];
	int three = 3 * num[b];
	int five = 5 * num[c];

	if (two <= three && five >= two) //min two
	{
		a++;
		if (two == three) //处理公约数的情况
			b++;

		if (two == five)
			c++;

		return two;
	}
	else if (three <= two && five >= three) //min three
	{
		b++;

		if (two == three) //处理公约数的情况
			a++;

		if (three == five)
			c++;

		return three;
	}
	else if (five <= two && three >= five) //min five
	{
		c++;

		if (two == five) //处理公约数的情况
			a++;

		if (three == five)
			b++;

		return five;
	}
}

int nthUglyNumber(int n) 
{
	int *uglyNumber = new int[n];
	int pointerTwo = 0;
	int pointerThree = 0;
	int pointerFive = 0;
	uglyNumber[0] = 1;

	for (int i = 1; i < n; i++)
		uglyNumber[i] = min(uglyNumber,pointerTwo,pointerThree,pointerFive);

	return uglyNumber[n - 1];
}

int main()
{
	for (int i = 1; i < 16; i++)
		cout << nthUglyNumber(i) << " ";

	return 0;
}