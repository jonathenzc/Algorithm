#include <iostream>
#include <string>

using namespace std;

bool isNumber(string s) {
	int startIndex = 0;

	//先忽视掉空格
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] != ' ')
		{
			startIndex = i;
			break;
		}
	}

	//消掉之前的正负号
	if (s[startIndex] == '+' || s[startIndex] == '-')
		startIndex++;

	//从忽视掉空格后的字符开始判断
	bool result = false;
	bool isSpaceFound = false; //在表达式中是否发现空格
	bool isEFound = false; //在表达式中是否发现e
	bool symbolBehindEFound = false; //e之后的符号已经被定位
	bool isNumFound = false; //是否发现数字
	bool isDotFound = false;
	bool isNumBehindEFound = false; //e后的数字是否存在

	for (int i = startIndex; i < s.size(); i++)
	{
		if (s[i] == ' ')
			isSpaceFound = true;
		else if ((s[i] >= '0' && s[i] <= '9') || s[i] == 'e' || s[i] == '+' || s[i] == '-' || s[i] == '.')
		{
			if (isSpaceFound)
				break;

			if (s[i] >= '0' && s[i] <= '9')
			{
				isNumFound = true;

				if (isEFound)
					isNumBehindEFound = true;
			}

			if (s[i] == '+' || s[i] == '-')
			{
				if (!isEFound)
					break;

				if (symbolBehindEFound) //多个符号
					break;

				if (s[i - 1] != 'e') //符号前应是e
					break;

				symbolBehindEFound = true;
			}

			if (s[i] == '.') 
			{
				if (isEFound) //e后不能有.
					break;

				if (isDotFound) //.只能一次
					break;

				isDotFound = true;
			}

			if (s[i] == 'e')
			{
				if (!isNumFound) //e前必须有数字
					break;

				if (isEFound) //只能有一个e
					break;

				isEFound = true;

			}
		}
		else
			break;

		if (i == s.size() - 1)
		{
			if(isNumFound)
				result = true;

			if (isEFound && !isNumBehindEFound)
				result = false;
		}
	}

	return result;
}

void printTest(string s)
{
	if (isNumber(s))
		cout << s + "   Yes\n";
	else
		cout << s + "   No\n";
}

int main()
{
	printTest("abc");
	printTest("1.e3");
	printTest(".");
	printTest("1.");
	printTest("1.32e-41");
	printTest("1.32e--41");
	printTest("1.32e-+41");
	printTest("241.96");
	printTest("  134");
	printTest("  12   ");
	printTest("  1  2");
	printTest("    0.1");
	printTest("    0.");
	printTest("1.e");
	printTest("1.e32");
	printTest("e9");
	printTest("4e.9-");
	printTest("4e.9");
	printTest("459277e38+");

	

	return 0;
}
