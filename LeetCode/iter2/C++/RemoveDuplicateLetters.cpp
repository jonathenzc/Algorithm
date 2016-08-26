#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

string removeDuplicateLetters(string s) {
	int letterCnt[26]{ 0 };
	for (int i = 0; i < s.size(); i++)
		letterCnt[s[i] - 'a']++;

	string ret = "0";
	bool isUsed[26]{ false };


	for (int i = 0; i < s.size(); i++)
	{
		letterCnt[s[i] - 'a']--;
		if (!isUsed[s[i] - 'a'])
		{
			while (ret.back() > s[i] && letterCnt[ret.back()-'a'] >= 1)
			{
				isUsed[ret.back() - 'a'] = false;
				ret.pop_back();
			}

			ret += s[i];
			isUsed[s[i] - 'a'] = true;
		}
	}

	return ret.substr(1);
}

int main()
{
	cout << removeDuplicateLetters("bcabc") << endl; //abc
	cout << removeDuplicateLetters("cbacdcbc") << endl; //acdb

		
	return 0;
}