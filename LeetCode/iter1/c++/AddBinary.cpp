#include <iostream>
#include <string>

using namespace std;

string addBinary(string a, string b) 
{
	bool whichSmaller = false;//false表示a短，true表示b短
	int smallerSize = a.size();
	if (b.size() < smallerSize)
	{
		smallerSize = b.size();
		whichSmaller = true;
	}

	bool plusOne = false;
	int bPointer = b.size() - 1;
	int aPointer = a.size() - 1;
	string resultS = "";
	int diffSize = a.size() - smallerSize;


	while (aPointer >= diffSize)
	{
		int digit=0;
		if (plusOne)
			digit = 1;

		digit += a[aPointer]-'0'+b[bPointer]-'0';

		if (digit > 1)
		{
			digit -= 2;
			plusOne = true;
		}
		else
			plusOne = false;

		resultS += digit + '0';

		bPointer--;
		aPointer = aPointer - 1;
	}

	//计算剩下来的长度
	if (aPointer >= 0 || bPointer >= 0)
	{
		aPointer = a.size() - smallerSize - 1;
		if (aPointer < 0)
			aPointer = b.size() - smallerSize - 1;

		for (aPointer; aPointer >= 0; aPointer--)
		{
			int digit = 0;
			if (plusOne)
				digit = 1;

			if (!whichSmaller)//b长
				digit += b[aPointer] - '0';
			else//a长
				digit += a[aPointer] - '0';

			if (digit > 1)
			{
				digit -= 2;
				plusOne = true;
			}
			else
				plusOne = false;

			resultS += digit + '0';
		}
	}

	if (plusOne)
		resultS += "1";

	//反转字符串
	string reversedS = "";
	for (int i = resultS.size() - 1; i >= 0; i--)
		reversedS += resultS[i];

	return reversedS;
}

int main()
{

	string s = "11";
	string b = "11111111";

	cout << addBinary(s,b);

	return 0;
}