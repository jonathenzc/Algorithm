#include <iostream>
#include <unordered_set>
#include <string>

using namespace std;

bool wordBreak(string s, unordered_set<string>& wordDict) {
	//canBeSegmented[i]表示子字符串[0...i]能否由wordDict中的元素组成
	bool *canBeSegmented = new bool[s.size() + 1];
	canBeSegmented[0] = true;
	for (int i = 1; i <= s.size(); i++)
		canBeSegmented[i] = false;//空字符串不能由wordDict中的元素组成

	for (int i = 1; i <= s.size(); i++)
	{
		unordered_set<string>::iterator iter;
		for (iter = wordDict.begin(); iter != wordDict.end(); iter++)
		{
			int strSize = (*iter).size();
			if (i >= strSize && canBeSegmented[i - strSize])//子字符串[0...j-strSize]能由wordDict中的元素组成
			{
				//判断子字符串[j-strSize...strSize]是否可以和该元素相同
				string substr = s.substr(i - strSize, strSize);
				if (substr == (*iter))
					canBeSegmented[i] = true;
			}
		}
	}

	//输出动态规划数组的内容
	//for (int i = 0; i <= s.size(); i++)
	//{
	//	if (canBeSegmented[i])
	//		cout << "1 ";
	//	else
	//		cout << "0 ";
	//}

	//cout << endl;

	return canBeSegmented[s.size()];
}

int main()
{
	string s = "catsanddog";
	unordered_set<string> wordDict;

	wordDict.insert("cat");
	wordDict.insert("cats");
	wordDict.insert("and");
	wordDict.insert("sand");
	wordDict.insert("dog");

	if (wordBreak(s, wordDict))
		cout << "Yes";
	else
		cout << "No";

	return 0;
}