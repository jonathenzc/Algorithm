#include <iostream>
#include <vector>
#include <string>

using namespace std;

//个位的英文描述
string digitArray[10] = {"Zero","One","Two","Three","Four", "Five","Six", "Seven","Eight", "Nine"};

//十位的英文描述
string tenDigitArray[10] = { "","","Twenty","Thirty","Forty", "Fifty","Sixty", "Seventy","Eighty", "Ninety" };

//11到19的特殊字符
string specialDigitArray[10] = { "Ten","Eleven","Twelve","Thirteen","Fourteen", "Fifteen","Sixteen", "Seventeen","Eighteen", "Nineteen" };

//输入3位长的数返回
string threeDigitWords(int hundredDigit,int tenDigit,int digit)
{
	string result = "";

	if (hundredDigit != 0)
		result += digitArray[hundredDigit]+" Hundred ";

	if (tenDigit != 0)
	{
		if (tenDigit == 1)
			result += specialDigitArray[digit];
		else
		{
			result += tenDigitArray[tenDigit] + " ";

			if (digit != 0)
				result += digitArray[digit];
		}
	}
	else
	{
		if (digit != 0)
			result += digitArray[digit];
	}

	if (result.size() != 0)
	{
		if (result[result.size() - 1] == ' ') //最后一个是空格
			result = result.substr(0, result.size() - 1);
	}

	return result;
}

string numberToWords(int num) {
	if (num == 0)
		return "Zero";

	//储存数
	vector<int> v;
	int digit = -1;

	while (num != 0)
	{
		digit = num % 10;
		v.push_back(digit);

		num = num / 10;
	}

	//补全到10位数
	for (int i = v.size(); i < 10; i++)
		v.push_back(0);

	string result = "";
	string billion = "";
	string million = "";
	string thousand = "";
	string hundred = "";

	billion = threeDigitWords(0,0,v[9]);
	million = threeDigitWords(v[8], v[7], v[6]);
	thousand = threeDigitWords(v[5], v[4], v[3]);
	hundred = threeDigitWords(v[2], v[1], v[0]);

	if (billion.size() != 0)
		result += billion + " Billion ";

	if (million.size() != 0)
		result += million + " Million ";

	if (thousand.size() != 0)
		result += thousand + " Thousand ";

	if (hundred.size() != 0)
		result += hundred;

	if (result.size() != 0)
	{
		if (result[result.size() - 1] == ' ') //最后一个是空格
			result = result.substr(0, result.size() - 1);
	}

	return result;
}

int main()
{

	cout << numberToWords(400100009) <<"abc\n";
	return 0;
}
