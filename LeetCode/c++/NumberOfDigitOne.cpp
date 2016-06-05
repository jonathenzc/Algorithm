#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int countDigitOne(int n) {
	if (n <= 0)
		return 0;

	if (n < 10)
		return 1;

	int tenPower = 1; //从1位开始
	int digit = -1;
	int cnt = 0;
	int formerNum = n;//在digit位前的数
	int preNum = 0;//在digit位后的数
	int tmpN = n;

	while(tmpN > 0)
	{ 
		digit = tmpN % 10;
		formerNum = tmpN / 10;
		preNum = n % tenPower;

		if (digit < 2)
		{
			cnt += formerNum*tenPower; //当前数位的数为0
			if (digit == 1) //当前数位为1时除了加上0的情况，还要考虑之前的数
				cnt += preNum + 1;
		}
		else //>=2
		{ 
			cnt += (formerNum+1)*tenPower ;
		}

		tenPower *= 10;
		tmpN = tmpN / 10;
	}

	return cnt;
}

int main()
{
	cout << countDigitOne(4999) << endl;
	cout << countDigitOne(5000) << endl;
	cout << countDigitOne(1400) << endl;
	cout << countDigitOne(23) << endl;
	cout << countDigitOne(2432) << endl;
	cout << countDigitOne(400) << endl;
	cout << countDigitOne(399) << endl;
	cout << countDigitOne(0) << endl;
	cout << countDigitOne(1) << endl;
	cout << countDigitOne(5432) << endl;
	cout << countDigitOne(1000) << endl;
	cout << countDigitOne(1432) << endl;
	cout << countDigitOne(432) << endl;
	cout << countDigitOne(32) << endl;
	cout << countDigitOne(5412) << endl;

	return 0;
}