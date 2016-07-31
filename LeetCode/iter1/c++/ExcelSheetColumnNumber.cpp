#include <iostream>
#include <string>

using namespace std;

bool checkStrUpper(string s)//检查字符串s中的字符是否都为大写
{
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i]<'A' || s[i]>'Z')
			return false;

		if (i == s.size() - 1)
			return true;
	}
}

int titleToNumber(string s) 
{
	if (s.size() == 0 || !checkStrUpper(s))
		return 0;
	else
	{
		int titleNumber = 0;
		int sSize = s.size();

		for (int i = 0; i < sSize; i++)
		{
			int powCnt = 0;
			int digit = s[i]-'A'+1;
			while (powCnt++ < sSize - 1 - i)
				digit *= 26;

			titleNumber += digit;
		}

		return titleNumber;
	}
}

int main()
{
	string s = "AB";

	cout << titleToNumber(s);

	return 0;
}