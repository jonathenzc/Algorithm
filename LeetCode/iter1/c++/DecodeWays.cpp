#include <iostream>
#include <string>

using namespace std;

bool decode(string s)
{
	if (s[0] == '0')
		return false;

	if (s.size() == 1)
		return true;
	else
	{
		int int_s = 10 * (s[0] - '0') + (s[1] - '0');
		if (int_s > 26)
			return false;
		else
			return true;
	}

	return false;
}

int numDecodings(string s) {
	int strSize = s.size();
	if (strSize == 0)
		return 0;

	int *cnt = new int[strSize +1]; //cnt[i]表示字符串s[0...i]被解码的可能性，那么cnt[i] = cnt[i-1] + decode(s[i]) + cnt[i-2]+decode(s[i-1...i])
	cnt[0] = 1;
	
	if (s[0] != '0') //不为0即可
		cnt[1] = 1;
	else
		cnt[1] = 0;

	for (int i = 2; i <= strSize; i++)
	{
		string tmp = "";
		tmp += s[i - 1];

		cnt[i] = 0;

		if (decode(tmp))
			cnt[i] = cnt[i - 1];

		tmp = s.substr(i-2,2);

		if (decode(tmp))
			cnt[i] += cnt[i - 2];
	}


	return cnt[strSize];
}

int main()
{	
	//cout << numDecodings("12") << endl;
	//cout << numDecodings("123") << endl;
	//cout << numDecodings("200") << endl;
	//cout << numDecodings("20") << endl;
	//cout << numDecodings("0") << endl;
	//cout << numDecodings("10") << endl;

	//cout << numDecodings("10") << endl;
	//cout << numDecodings("1") << endl;
	cout << numDecodings("27") << endl;
	cout << numDecodings("103") << endl;
	cout << numDecodings("1032") << endl;
	cout << numDecodings("10324") << endl;
	cout << numDecodings("1280") << endl;
	cout << numDecodings("1224") << endl;


	return 0;
}
