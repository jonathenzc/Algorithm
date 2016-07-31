#include <iostream>
#include <string>
#include <vector>

using namespace std;

string shortestPalindrome(string s) {
	string reversedStr = s;

	reverse(reversedStr.begin(), reversedStr.end());

	int i = s.size();
	for (i; i >= 1; i--)
	{
		if (s.substr(0,i).compare(reversedStr.substr(s.size()-i)) == 0)
			break;
	}

	string returnStr = reversedStr.substr(0, s.size() - i) + s;

	return returnStr;
}


int main()
{
	cout<< shortestPalindrome ("aacecaaa")<<endl;
	cout << shortestPalindrome("aaccaaaert") << endl;
	cout << shortestPalindrome("abcd") << endl;
	cout << shortestPalindrome("abeba") << endl;
	cout << shortestPalindrome("ba") << endl;
	cout << shortestPalindrome("a") << endl;
	cout << shortestPalindrome("bac") << endl;
	cout << shortestPalindrome("aa") << endl;
	cout << shortestPalindrome("aba") << endl;
	cout << shortestPalindrome("aaa") << endl;
	cout << shortestPalindrome("abab") << endl;
	cout << shortestPalindrome("aaaa") << endl;
	cout << shortestPalindrome("abba") << endl;
	cout << shortestPalindrome("aaaaa") << endl;
	cout << shortestPalindrome("aaaaaa") << endl;
	return 0;
}