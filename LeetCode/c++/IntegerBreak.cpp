#include <iostream>
#include <math.h>

using namespace std;
	
int integerBreak(int n) 
{
	if (n == 1)
		return 1;
	else if (n == 2)
		return 1;
	else if (n == 3)
		return 2;

	int cnt = n/3;
	int mod = n % 3;

	int result = 0;

	if (mod == 1)
	{
		cnt--;
		result = pow(3, cnt) * 4;
	}
	else if(mod == 2)
	{
		result = pow(3, cnt) * 2;
	}
	else
		result = pow(3,cnt);

	return result;
}

int main()
{
	cout << integerBreak(2) << endl
		<< integerBreak(7) << endl
		<< integerBreak(8) << endl
		<< integerBreak(9) << endl
		<< integerBreak(10) << endl
		<< integerBreak(16) << endl
		<< integerBreak(15) << endl
		<< integerBreak(25) << endl
		<< integerBreak(26) << endl;

	return 0;
}
