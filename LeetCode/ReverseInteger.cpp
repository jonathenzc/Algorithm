#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int reverse(int x) 
{
	stringstream ss;
	ss << x;
	string s;
	ss >> s;

	ss.clear();

	string reversedStr = "";
	if (s[0] == '-')
		reversedStr += '-';

	for (int i = s.size() - 1; i >= 0; i--)
	{
		if (s[i] >= '0' && s[i] <= '9')
			reversedStr += s[i];
	}

	ss << reversedStr;
	int reversedX;
	ss >> reversedX;

	if (reversedX >= 2147483647 || reversedX <= -2147483647)
		reversedX = 0;

	return reversedX;
}

int main()
{
	cout << reverse(123) << endl << reverse(-123) << endl
		<< reverse(1534236469)<<endl<<reverse(10100)<<endl;
	//1534236469在leetcode上跑出来是2147483647，所以我只加了超过正负值的情况。可能在64机上就不是这个答案了

	return 0;
}