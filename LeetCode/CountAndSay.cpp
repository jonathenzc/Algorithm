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
		stringstream ss;//������intת����string
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
					//��result[i-1]���ֵĴ���ת����string
					ss << numberCnt;
					string numberStr;
					ss >> numberStr;

					if (lastNumber == ' ')
						lastNumber = result[0];

					temp += numberStr + lastNumber;

					//��¼��ǰ���ֵ��µ��ַ�
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