#include <iostream>
#include <string>
#include <sstream>

using namespace std;

string countAndSay(int n) 
{
	if (n <= 0)
		return "";
	else
	{
		string result = "1";
		stringstream ss;//用来将int转化成string
		int cnt = 1;

		while (cnt < n)
		{
			char lastNumber = result[0];
			int numberCnt = 1;
			string temp = "";

			for (int i = 1; i < result.size(); i++)
			{
				if (lastNumber == result[i])
					numberCnt++;
				else
				{
					//将result[i-1]出现的次数转化成string
					ss << numberCnt;
					string numberStr;
					ss >> numberStr;

					if (lastNumber == ' ')
						lastNumber = result[0];

					temp += numberStr + lastNumber;

					//记录当前出现的新的字符
					lastNumber = result[i];
					numberCnt = 1;

					ss.clear();
				}
			}

			ss << numberCnt;
			string numberStr;
			ss >> numberStr;
			temp += numberStr + lastNumber;

			result = temp;
			cnt++;

			ss.clear();
		}

		return result;
	}
}

int main()
{
	cout << countAndSay(4) << endl;
	cout << countAndSay(5) << endl;
	cout << countAndSay(6) << endl;
	cout << countAndSay(7) << endl;
	cout << countAndSay(8) << endl;

	return 0;
}