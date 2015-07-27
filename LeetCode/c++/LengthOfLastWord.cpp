#include <iostream>
#include <string>

using namespace std;

int lengthOfLastWord(string s) 
{
	int lastWordLength = 0;
	int lastWordIndex = -1;

	//找到最后一个空格
	for (int i = s.size()-1; i >= 0; i--)
	{
		if (s[i] == ' ')
			lastWordIndex = i;
		else//找到最后空格前的
		{
			if (lastWordIndex != -1)
				break;
		}
	}

	//判断空格后是否有字母表
	for (int i = lastWordIndex+1; i < s.size(); i++)
	{
		if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
			lastWordLength++;
	}

	//空格后没有找到的话，返回前面一个字符串
	if (lastWordLength == 0)
	{
		int cnt = lastWordIndex-1;

		while (cnt >= 0 && s[cnt] != ' ')
		{
			lastWordLength++;
			cnt--;
		}
	}

	return lastWordLength;
}

int main()
{
	cout << lengthOfLastWord("b    afsda         ");

	return 0;
}
