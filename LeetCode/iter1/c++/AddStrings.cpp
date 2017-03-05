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
	string addStrings(string num1, string num2) {
		string sumStr = "";

		//保证num1比num2长
		if (num1.size() < num2.size())
		{
			string tmp = num1;
			num1 = num2;
			num2 = tmp;
		}

		int addDigit = 0;
		int num1Index = num1.size() - 1;
		for (int i = 0; i < num2.size();i++)
		{
			int digitSum = num2[num2.size() - 1 - i] - '0' + num1[num1Index--] - '0' + addDigit;
			addDigit = digitSum /10;
			sumStr = char(digitSum % 10+'0')+sumStr;
		}

		for (int i = num1Index; i >= 0; i--)
		{
			int digitSum = num1[i] - '0' + addDigit;
			addDigit = digitSum / 10;
			sumStr = char(digitSum % 10 + '0') + sumStr;
		}

		if(addDigit == 1)
			sumStr = '1' + sumStr;

		return sumStr;
	}
};


int main(void)
{
	Solution s;
	cout << s.addStrings("9999", "1") << endl;
	cout << s.addStrings("9999", "11") <<endl;
	cout << s.addStrings("9999", "111") << endl;
	cout << s.addStrings("9999", "1111") << endl;
	cout << s.addStrings("9999", "11111") << endl;
	cout << s.addStrings("9999", "111111") << endl;

	return 0;
}