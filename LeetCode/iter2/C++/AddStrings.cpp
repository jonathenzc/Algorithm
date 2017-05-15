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
		string ret = "";
		int num1Index = num1.size() - 1;
		int num2Index = num2.size() - 1;
		int addDigit = 0;

		while (num1Index >= 0 && num2Index >= 0)
		{
			int digitSum = (num1[num1Index] - '0') + (num2[num2Index] - '0') + addDigit;
			addDigit = digitSum / 10;
			ret = char((digitSum % 10) + '0') + ret;

			num1Index--;
			num2Index--;
		}

		if (num1Index >= 0)
		{
			while (num1Index >= 0)
			{
				int digitSum = num1[num1Index] - '0' + addDigit;
				addDigit = digitSum / 10;
				ret = char((digitSum % 10) + '0') + ret;
				num1Index--;
			}
		}
		else if (num2Index >= 0)
		{
			while (num2Index >= 0)
			{
				int digitSum = num2[num2Index] - '0' + addDigit;
				addDigit = digitSum / 10;
				ret = char((digitSum % 10) + '0') + ret;
				num2Index--;
			}
		}

		if (addDigit == 1)
			ret = '1' + ret;

		return ret;
	}
};

int main(void)
{
	Solution s;
	cout << s.addStrings("99999", "1") << endl;
	cout << s.addStrings("1", "99999") << endl;
	cout << s.addStrings("1234", "542345") << endl;
	cout << s.addStrings("542345", "14321") << endl;


	return 0;
}