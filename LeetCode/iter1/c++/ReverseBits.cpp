#include <iostream>
#include <stdint.h>
#include <string>

using namespace std;

string uint32_tToReversedStr(uint32_t n)
{
	string s = "";

	while (n != 0)
	{
		s += n % 2 + '0';
		n = n / 2;
	}

	int sSize = s.size();//因为下面s会变所以先赋值

	for (int i = 0; i < 32-sSize; i++)
		s += '0';

	return s;
}

//求数位的二次幂
uint32_t bit2Pow(int bit)
{
	int cnt = 0;
	uint32_t result = 1;

	while (cnt < bit)
	{
		result *= 2;
		cnt++;
	}

	return result;
}

uint32_t reverseBits(uint32_t n) 
{
	string reversedStr = uint32_tToReversedStr(n);

	uint32_t reversedN = 0;
	int reversedStrSize = reversedStr.size();
	for (int i = 0; i < reversedStrSize; i++)
	{ 
		if (reversedStr[i] == '1')
			reversedN += bit2Pow(reversedStrSize - i - 1);
	}
		
	return reversedN;
}

int main()
{
	uint32_t n = 43261596;

	cout << reverseBits(n);

	return 0;
}