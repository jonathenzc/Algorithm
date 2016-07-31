#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isIPValid(string s)
{
	int ip = 0;
	if (s.size() == 1)
		return true;
	else if (s.size() == 2)
	{
		ip = 10 * (s[0] - '0') + (s[1] - '0');
		if (ip >= 10) //处理09、08
			return true;
	}
	else if (s.size() == 3)
	{
		ip = 100 * (s[0] - '0') + 10 * (s[1] - '0') + (s[2] - '0');

		if (ip >= 100 && ip <= 255)
			return true;
	}
	
	return false;
}

void restoreHelper(string preStr, string restStr,int dotCnt,vector<string> &v)
{
	if (dotCnt == 3)
	{
		if (restStr.size() < 4 && isIPValid(restStr))
			v.push_back(preStr + restStr);
	}
	else
	{
		string prefixStr = "";
		string postfixStr = "";

		//设置第dotCnt+1个点
		if (restStr.size() < 11 - dotCnt * 3)
		{
			prefixStr = preStr + restStr.substr(0, 1) + ".";
			postfixStr = restStr.substr(1);

			restoreHelper(prefixStr, postfixStr, dotCnt + 1, v);
		}


		//设置第dotCnt+1个点
		if (restStr.size() < 12 - dotCnt * 3 && restStr.size() >= 5-dotCnt)
		{
			prefixStr = restStr.substr(0, 2);
			if (isIPValid(prefixStr))
			{
				prefixStr = preStr + prefixStr + ".";
				postfixStr = restStr.substr(2);

				restoreHelper(prefixStr, postfixStr, dotCnt + 1, v);
			}
		}

		if (restStr.size() >= 6 - dotCnt)
		{
			prefixStr = restStr.substr(0, 3);
			if (isIPValid(prefixStr))
			{
				prefixStr = preStr + prefixStr + ".";
				postfixStr = restStr.substr(3);

				restoreHelper(prefixStr, postfixStr, dotCnt + 1, v);
			}
		}
	}
}

vector<string> restoreIpAddresses(string s) {
	vector<string> v;

	//字符串长度必须大于3
	if (s.size() > 3 && s.size() < 13)
		restoreHelper("",s,0,v);

	return v;
}

void testPrint(string s)
{
	cout << s << " restore ip:\n";

	vector<string> v = restoreIpAddresses(s);
	for (auto str : v)
		cout << str << endl;

	cout << endl;
}

int main()
{
	testPrint("25525511135");
	testPrint("0000");
	testPrint("00000");
	testPrint("1111");
	testPrint("11112");
	testPrint("111123");

	testPrint("010010");
	return 0;
}