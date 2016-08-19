#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

bool isScramble(string s1, string s2) {
	if (s1 == s2)
		return true;

	int count[26] = {0};

	for (int i = 0; i < s1.size(); i++) {
		count[s1[i] - 'a']++;
		count[s2[i] - 'a']--;
	}

	for (int i = 0; i < 26; i++)
	{
		if (count[i] != 0)
			return false;
	}

	for (int len = 1; len < s1.size(); len++)
	{
		if (isScramble(s1.substr(0, len), s2.substr(0, len)) && isScramble(s1.substr(len), s2.substr(len)))
			return true;
		if (isScramble(s1.substr(0, len), s2.substr(s1.size()-len)) && isScramble(s1.substr(len), s2.substr(0, s1.size()-len)))
			return true;
	}

	return false;
}

void testPrint(string s1, string s2)
{
	if (isScramble(s1, s2))
		cout << "Yes\n";
	else
		cout << "No\n";
}

int main()
{
	testPrint("great","rgeat");
	testPrint("great", "rgtae");
	

	return 0;
}