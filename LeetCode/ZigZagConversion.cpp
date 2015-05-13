#include <iostream>
#include <string>

using namespace std;

string convert(string s, int numRows) 
{
	//先处理列长大于字符串长度的情况，这样的情况就直接输出字符串即可
	if (s.size() <= numRows || numRows == 1)
		return s;
	else
	{
		string result = "";

		int interval = 2 * (numRows - 1);

		for (int i = 0; i < numRows; i++)
		{
			if (i % (numRows - 1) == 0)
			{
				int j = i;
				while (j <= s.size() - 1)
				{
					result += s[j];
					j += interval;
				}
			}
			else
			{
				int j = i;
				int dis = interval - 2*i;

				while (j <= s.size() - 1)
				{
					result += s[j];
					j += dis;

					dis = interval - dis;
				}
			}
		}

		return result;
	}
}

int main()
{
	cout << convert("AB", 1);

	return 0;
}