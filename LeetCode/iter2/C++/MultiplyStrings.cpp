#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <queue>
#include <stack>

using namespace std;

class Solution {
public:
	string multiply(string num1, string num2) {
		if (num1[0] == '0' || num2[0] == '0')
			return "0";

		productStr = "0";

		//将num2作为第二个乘数
		for (int i = num2.size() - 1; i >= 0; i--)
		{
			int addDigit = 0; //进位的数字

			string tmpRetStr = "";

			for (int j = num1.size() - 1; j >= 0; j--)
			{
				int digitPro = (num2[i]-'0') * (num1[j]-'0') + addDigit;
				tmpRetStr = char(digitPro%10+'0')+tmpRetStr;

				addDigit = digitPro / 10;
			}

			//添加进位
			if (addDigit != 0)
				tmpRetStr = char(addDigit + '0') + tmpRetStr;

			//补末尾0
			for (int cnt = 0; cnt < num2.size() - 1 - i; cnt++)
				tmpRetStr += '0';

			productStr = addStr(productStr,tmpRetStr);
		}

		return productStr;
	}

private:
	string productStr;

	string addStr(string num1, string num2)
	{
		int i = num1.size() - 1, j = num2.size() - 1;
		int addDigit = 0;

		string ret = "";

		while (i >= 0 && j >= 0)
		{
			int tmpSum = (num1[i] - '0') + (num2[j] - '0') + addDigit;

			ret = char(tmpSum % 10 + '0')+ ret;
			addDigit = tmpSum / 10;

			i--;
			j--;
		}

		if (i >= 0) //num1长
		{
			while (i >= 0)
			{
				int tmpSum = (num1[i]-'0')+addDigit;
				ret = char(tmpSum % 10 + '0') + ret;
				addDigit = tmpSum / 10;

				i--;
			}

			if (addDigit == 1)
				ret = '1' + ret;
		}
		else
		{
			while (j >= 0)
			{
				int tmpSum = (num2[j] - '0') + addDigit;
				ret = char(tmpSum % 10 + '0') + ret;
				addDigit = tmpSum / 10;

				j--;
			}

			if (addDigit == 1)
				ret = '1' + ret;
		}

		return ret;
	}
};

int main(void)
{
	Solution s;

	//测addStr
	//cout << s.addStr("1","2") << endl;
	//cout << s.addStr("123", "999") << endl;
	//cout << s.addStr("5555", "5555555") << endl;
	//cout << s.addStr("5555555", "5555") << endl;
	//cout << s.addStr("1", "999999") << endl;
	//cout << s.addStr("999999","1") << endl;

	//测multiply
	cout << s.multiply("1", "2") << endl;
	cout << s.multiply("123", "999") << endl;
	cout << s.multiply("5555", "5555555") << endl;
	cout << s.multiply("5555555", "5555") << endl;
	cout << s.multiply("1", "999999") << endl;
	cout << s.multiply("999999","1") << endl;
	cout << s.multiply("999999", "0") << endl;
	cout << s.multiply("0","999999") << endl;


	return 0;
}