#include <iostream>
#include <string>

using namespace std;

//返回两字符串和的逆反
string sum(string num1, string num2)
{
	if (num1.size() == 0)
		return num2;

	if (num2.size() == 0)
		return num1;

	int index1 = 0;
	int index2 = 0;

	int addDigit = 0;
	string result = "";
	int sumNum = 0;
	while (index1 < num1.size() && index2 < num2.size())
	{
		sumNum = (num1[index1] - '0') + (num2[index2] - '0') + addDigit;
		if (sumNum > 9)
		{
			sumNum -= 10;
			addDigit = 1;
		}
		else
			addDigit = 0;

		result += (sumNum + '0');

		index1++;
		index2++;
	}

	if (index1 == num1.size() && index2 == num2.size()) //l2还有数字
	{
		if (addDigit == 1) //看进位是否为1
			result += '1';
	}
	else if (index1 == num1.size()) //l2还有数字
	{
		while (index2 < num2.size())
		{
			sumNum = (num2[index2] - '0') + addDigit;
			if (sumNum > 9)
			{
				sumNum -= 10;
				addDigit = 1;
			}
			else
				addDigit = 0;

			result += (sumNum + '0');

			index2++;
		}

		if (addDigit == 1) //看进位是否为1
			result += '1';
	}
	else if (index2 == num2.size()) // l1还有数字
	{
		while (index1 < num1.size())
		{
			sumNum = (num1[index1] - '0') + addDigit;
			if (sumNum > 9)
			{
				sumNum -= 10;
				addDigit = 1;
			}
			else
				addDigit = 0;

			result += (sumNum + '0');

			index1++;
		}

		if (addDigit == 1) //看进位是否为1
			result += '1';
	}

	return result;
}


string multiply(string num1, string num2) {
	if (num1.compare("0") == 0 || num2.compare("0") == 0)
		return "0";
	
	//返回结果
	string powerResult = "0";

	if (num1.size() < num2.size())
	{
		string tmp = num1;
		num1 = num2;
		num2 = tmp;
	}

	//num1长，num2短
	int num1Index = num1.size()-1;
	int num2Index = num2.size()-1;

	int addDigit = 0;//进位
	int power = 0;
	int digit = 0;
	string tmpResult = "";

	while (num2Index >= 0)
	{
		num1Index = num1.size() - 1;
		tmpResult = "";

		//补0
		for (int i = num2.size() - 1; i > num2Index; i--)
			tmpResult += '0';

		//计算num2[num2Index]与num1的乘积
		addDigit = 0;
		power = 0;
		digit = 0;

		while (num1Index >= 0)
		{
			power = (num1[num1Index] - '0') * (num2[num2Index] - '0') + addDigit;

			addDigit = power / 10;
			digit = power % 10;

			tmpResult += (digit + '0');

			num1Index--;
		}

		if (addDigit != 0)
			tmpResult += (addDigit + '0');

		powerResult = sum(powerResult,tmpResult);


		num2Index--;
	}
	
	//反转字符串
	reverse(powerResult.begin(), powerResult.end());

	return powerResult;
}


int main()
{
	//cout << sum("12", "11") << endl;
	//cout << sum("999", "1") << endl;
	//cout << sum("1", "999") << endl;
	//cout << sum("425", "0") << endl;
	//cout << sum("0", "425") << endl;
	cout << multiply("12", "113") << endl;
	cout << multiply("10", "110") << endl;
	cout << multiply("554", "99") << endl;
	cout << multiply("99", "554") << endl;
	cout << multiply("100", "100") << endl;
	return 0;
}