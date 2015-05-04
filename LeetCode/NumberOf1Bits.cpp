#include <iostream>
#include <stdint.h>
#include <string>

using namespace std;

string uint32_tToStr(uint32_t n)
{
	string s = "";

	while (n != 0)
	{
		s += n%2+'0';
		n = n / 2;
	}

	return s;
}

int hammingWeight(uint32_t n) 
{
	string uint32_tStr = uint32_tToStr(n);

	int bit1Cnt = 0;
	for (int i = 0; i < uint32_tStr.size(); i++)
	{
		if (uint32_tStr[i] == '1')
			bit1Cnt++;
	}

	return bit1Cnt;
}

int main()
{

	cout << hammingWeight(11);
	return 0;
}