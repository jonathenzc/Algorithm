#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

string int2Str(int num)
{
	stringstream ss;
	ss << num;
	string ret;
	ss >> ret;

	return ret;
}

vector<string> readBinaryWatch(int num) {
	vector<int> binaryDigit(60,0);
	for (int i = 0; i < 60; i++)
	{
		int oneDigitCnt = 0;
		int tmpI = i;
		while (tmpI > 0)
		{
			oneDigitCnt += (tmpI & 1);
			tmpI = tmpI >> 1;
		}

		binaryDigit[i] = oneDigitCnt;
	}

	vector<string> v;

	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 60; j++)
		{
			int hour = binaryDigit[i];
			int minute = binaryDigit[j];

			if (hour + minute == num)
			{
				string s = "";
				s = int2Str(i) + ":";

				if (j >= 0 && j <= 9)
					s += "0";
				
				s += int2Str(j);

				v.push_back(s);
			}
		}
	}

	return v;
}

int main()
{
	vector<string> v= readBinaryWatch(1);
	for (auto str : v)
		cout << str << endl;

	return 0;
}