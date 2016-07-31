#include <iostream>
#include <string>

using namespace std;

bool isVowel(char ch)
{
	if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
		ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
		return true;
	else
		return false;
}

string reverseVowels(string s) {
	if (s.size() == 0 && s.size() == 1)
		return s;

	int start = 0, end = s.size()-1;
	int isStartVowelFound = false, isEndVowelFound = false;

	while (start < end)
	{
		if (!isStartVowelFound && isVowel(s[start]))
			isStartVowelFound = true;

		if (!isEndVowelFound && isVowel(s[end]))
			isEndVowelFound = true;

		if (isStartVowelFound && isEndVowelFound)
		{
			char tmp = s[start];
			s[start] = s[end];
			s[end] = tmp;

			isStartVowelFound = false;
			isEndVowelFound = false;
		}

		if(!isStartVowelFound)
			start++;

		if(!isEndVowelFound)
			end--;
	}

	return s;
}

int main()
{
	cout << reverseVowels("")<<endl
		<<reverseVowels("a")<<endl
		<< reverseVowels("abc") << endl
		<< reverseVowels("abe") << endl
		<< reverseVowels("acde") << endl
		<< reverseVowels("aceid") << endl
		<< reverseVowels("aecbd") << endl
		<< reverseVowels("aeioubcd") << endl
		<< reverseVowels("aA") << endl;

	return 0;
}