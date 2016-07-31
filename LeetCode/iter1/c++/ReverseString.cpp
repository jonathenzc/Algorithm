#include <iostream>
#include <string>

using namespace std;

string reverseString(string s) {
	if (s.size() == 0 || s.size() == 1)
		return s;

	int end = s.size() - 1;

	for (int i = 0;i<s.size()/2;i++)
	{
		char tmp = s[i];
		s[i] = s[end];
		s[end] = tmp;

		end--;
	}

	return s;
}

int main()
{
	cout << reverseString("") << endl
		<< reverseString("a") << endl
		<< reverseString("abc") << endl
		<< reverseString("abcd") << endl;

	return 0;
}