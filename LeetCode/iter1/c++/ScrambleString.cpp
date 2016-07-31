#include <iostream>
#include <string>
#include <stack>
#include <unordered_map>

using namespace std;

bool scrambleHelper(string s1, string s2, int sLen)
{
	if (s1.compare(s2) == 0)
		return true;

	int alphabat[26] = { 0 };
	for (int i = 0; i < s1.size(); i++)
	{
		alphabat[s1[i] - 'a']++;
		alphabat[s2[i] - 'a']--;
	}

	//遍历alphabat，如果不为0，说明两个字符串没有用到相同的字母
	for (int i = 0; i < 26; i++)
	{
		if (alphabat[i] != 0)
			return false;
	}

	for (int i = 1; i < sLen; i++)
	{
		if (scrambleHelper(s1.substr(0, i), s2.substr(0, i), i) && scrambleHelper(s1.substr(i), s2.substr(i), sLen - i))
			return true;

		if (scrambleHelper(s1.substr(0,i), s2.substr(sLen-i, i), i) && scrambleHelper(s1.substr(i), s2.substr(0,sLen-i), sLen - i))
			return true;
	}

	return false;
}

bool isScramble(string s1, string s2) {
	if (s1.size() != s2.size())
		return false;

	return scrambleHelper(s1,s2,s1.size());
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
	testPrint("great","great");
	testPrint("great","rgeat");
	testPrint("great", "rgtae");

	return 0;
}
