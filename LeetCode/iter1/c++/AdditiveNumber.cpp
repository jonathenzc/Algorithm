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
	//i和j分别表示两个数的长度
	bool isAdditiveNumber(string num) {
		for (int i = 1; i <= num.size() / 2; i++)
		{
			for (int j = 1; j <= (num.size() - i) / 2; j++)
			{
				if (checkHelper(num.substr(0, i), num.substr(i, j), num.substr(i + j)))
					return true;
			}
		}

		return false;
	}

private:
	bool checkHelper(string num1Str, string num2Str, string target)
	{
		if ((num1Str[0] == '0' && num1Str.size() > 1) || (num2Str[0] == '0' && num2Str.size() > 1))
			return false;

		long long num1 = str2longlong(num1Str);
		long long num2 = str2longlong(num2Str);
		long long sum = num1 + num2;
		int len = numLen(sum);

		if (len <= target.size())
		{
			long long candidateSum = str2longlong(target.substr(0,len));
			if (sum == candidateSum)
			{
				if (len == target.size())
					return true;

				string candidateSumStr = longlong2str(candidateSum);
				return checkHelper(num2Str, candidateSumStr, target.substr(candidateSumStr.size()));
			}
		}

		return false;
	}

	long long str2longlong(string s)
	{
		stringstream ss;
		ss << s;
		long long num;
		ss >> num;

		return num;
	}

	string longlong2str(long long num)
	{
		stringstream ss;
		ss << num;
		string s;
		ss >> s;

		return s;
	}

	int numLen(long long num) 
	{
		if (num == 0)
			return 1;

		int len = 0;
		while (num > 0) 
		{
			num /= 10;
			len++;
		}

		return len;
	}
};

void testPrint(string s)
{
	Solution ss;
	if (ss.isAdditiveNumber(s))
		cout << "Is additive\n";
	else
		cout << "Is not additive\n";
}

int main(void)
{
	testPrint("000");
	testPrint("112358");
	testPrint("199100199");
	testPrint("100010");
	testPrint("101");
	testPrint("121474836472147483648");

	return 0;
}