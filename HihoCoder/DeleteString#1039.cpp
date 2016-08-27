#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int score(string s)
{
	int len = s.size();
	if (len == 0)
		return 0;

	//开始消除
	string newS = "";
	int preIndex = 0;
	s += "#"; 
	for (int i = 1; i <= len; i++)
	{
		if (s[preIndex] != s[i])
		{
			if (preIndex == i - 1) //只差一个字符
				newS += s[preIndex];

			preIndex = i;
		}
	}

	if (len == newS.size()) //没有变化
		return 0;

	return len - newS.size() + score(newS);
}

int main()
{
	int cnt;
	cin >> cnt;
	int index = 0;

	while (index < cnt)
	{
		string s;
		cin >> s;

		int maxScore = 0;
		for (int i = 0; i < s.size(); i++)
		{
			//枚举插入A、B、C
			string tmpS = s;
			tmpS.insert(i, "A");
			int tmpScore = score(tmpS);
			if (tmpScore > maxScore)
				maxScore = tmpScore;

			tmpS = s;
			tmpS.insert(i,"B");
			tmpScore = score(tmpS);
			if (tmpScore > maxScore)
				maxScore = tmpScore;

			tmpS = s;
			tmpS.insert(i, "C");
			tmpScore = score(tmpS);
			if (tmpScore > maxScore)
				maxScore = tmpScore;
		}

		cout << maxScore << endl;

		index++;
	}

	return 0;
}