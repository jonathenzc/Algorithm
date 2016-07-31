#include <iostream>
#include <string>
#include <sstream>
#include <map>

using namespace std;

struct num_cnt
{
	int num; //数
	int cnt; //该数在循环中出现的次数
};

string fractionToDecimal(int numerator, int denominator) {
	if (denominator == 0)
		return "";

	if (numerator == 0)
		return "0";

	long long numerator_L = (long long)numerator;
	long long denominator_L = (long long)denominator;

	int sign = 1;
	if (numerator_L < 0)
	{
		sign = -1;
		numerator_L = -numerator_L;
	}

	if (denominator_L < 0)
	{
		sign *= -1;
		denominator_L = -denominator_L;
	}

	string result = "";
	if (sign == -1) //符号位
		result += '-';

	if (numerator_L < denominator_L)//小数
	{
		numerator_L *= 10;
		result += "0.";
	}
	else
	{
		long long divisor = numerator_L / denominator_L;
		stringstream ss;
		ss << divisor;
		string s;
		ss >> s;

		result += s;
		numerator_L = numerator_L%denominator_L;

		if (numerator_L != 0)
		{
			result += '.';
			numerator_L *= 10;
		}
	}

	int digit = 0;

	string wholeLoopStr = ""; //包括循环和不循环
	string loopStr = "";

	map<long long, num_cnt> m;

	bool isLoop = false;
	while (numerator_L != 0)
	{
		digit = numerator_L / denominator_L;

		if (m.find(numerator_L) != m.end())
		{
			m[numerator_L].cnt++;

			int cnt = m[numerator_L].cnt;

			if (cnt == 2)
			{
				loopStr += (digit+'0');
			}
			else if (cnt == 3)
			{
				isLoop = true;
				break;
			}
		}
		else
		{
			num_cnt tmp;
			tmp.num = digit;
			tmp.cnt = 1;
			m.insert(map<int, num_cnt>::value_type(numerator_L, tmp));

			wholeLoopStr += (digit + '0');
		}

		numerator_L = numerator_L % denominator_L;

		numerator_L *= 10;
	}

	if (isLoop)
	{
		string nonLoopStr = wholeLoopStr.substr(0, wholeLoopStr.size()- loopStr.size());


		result += nonLoopStr+"(" + loopStr + ")";
	}
	else
		result += wholeLoopStr;

	return result;
}


int main()
{
	cout << fractionToDecimal(1, 7) << endl;
	cout << fractionToDecimal(10, 7) << endl;
	cout << fractionToDecimal(-100, 7) << endl;
	cout << fractionToDecimal(8, 2) << endl;
	cout << fractionToDecimal(8, 3) << endl;
	cout << fractionToDecimal(2, 5) << endl;
	cout << fractionToDecimal(1, 6) << endl;
	cout << fractionToDecimal(334, 300) << endl;
	cout << fractionToDecimal(-1, -2147483648) << endl;
	cout << fractionToDecimal(-2147483648,-1) << endl;
	cout << fractionToDecimal(-2147483648, 1) << endl;
	return 0;
}