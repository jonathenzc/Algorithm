#include <iostream>
#include <string>
#include <map>

using namespace std;

string isPalindrome(string s, int leftStart, int rightStart)
{
	if (leftStart > rightStart)
		return "";

	string result= "";

	while (leftStart >= 0 && rightStart<s.size())
	{
		if (s[leftStart] != s[rightStart])
		{
			break;
		}

		leftStart--;
		rightStart++;
	}

	result = s.substr(leftStart + 1, rightStart - leftStart - 1);

	return result;
}

string longestPalindrome(string s) {
	int sSize = s.size();
	if (sSize == 0 || sSize == 1)
		return s;
	
	string result = "";

	for (int i = 0; i < sSize; i++)
	{
		string odd = isPalindrome(s,i,i);
		if (result.size() < odd.size())
			result = odd;

		string even = isPalindrome(s, i, i+1);

		if (result.size() < even.size())
			result = even;
	}

	return result;
}


int main()
{
	cout << longestPalindrome("bb") << endl;
	cout << longestPalindrome("ababacdefgfgfgfg")<<endl;

	return 0;
}
