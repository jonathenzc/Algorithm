#include <iostream>
#include <string>

using namespace std;

int lengthOfLastWord(string s) 
{
	int lastWordLength = 0;
	int lastWordIndex = -1;

	//�ҵ����һ���ո�
	for (int i = s.size()-1; i >= 0; i--)
	{
		if (s[i] == ' ')
			lastWordIndex = i;
		else//�ҵ����ո�ǰ��
		{
			if (lastWordIndex != -1)
				break;
		}
	}

	//�жϿո���Ƿ�����ĸ��
	for (int i = lastWordIndex+1; i < s.size(); i++)
	{
		if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
			lastWordLength++;
	}

	//�ո��û���ҵ��Ļ�������ǰ��һ���ַ���
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
