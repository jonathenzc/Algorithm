#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>

using namespace std;

int BADVERSION;

string removeDuplicateLetters(string s) {
	string ret = "0";
	bool isVisited[26]{ false };
	int cnt[26]{ 0 };

	for (int i = 0; i < s.size(); i++)
		cnt[s[i] - 'a']++;

	for (int i = 0; i < s.size(); i++)
	{
		cnt[s[i] - 'a']--;
		if (!isVisited[s[i] - 'a'])
		{
			//调整s[i]的位置
			while (cnt[ret.back()-'a']>0 && s[i] < ret.back()) //个数为0不用调整必须选择
			{
				isVisited[ret.back() - 'a'] = false;
				ret.pop_back();
			}

			isVisited[s[i] - 'a'] = true;
			ret += s[i];
		}
	}

	return ret.substr(1);
}

int main()
{
	cout << removeDuplicateLetters("bcabc") << endl;
	cout << removeDuplicateLetters("cbacdcbc") << endl;

	return 0;
}