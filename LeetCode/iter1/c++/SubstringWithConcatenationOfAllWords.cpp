#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> findSubstring(string s, vector<string>& words) {
	vector<int> returnV;
	if (words.size() == 0)
		return returnV;

	int wordsLen = words[0].size(); //单词长度都一样
	int wordsCnt = words.size();

	if (s.size() < wordsLen*wordsCnt) //不可能组成合并字符串
		return returnV;

	//先构建words的map,记录单词出现的个数，words中可能重复
	unordered_map<string,int> wordsMap;
	unordered_map<string, int> tmpMap;
	for (auto word : words)
		wordsMap[word]++;

	//从可能是组合字符串的头下标开始
	for (int i = 0; i <= s.size() - wordsLen*wordsCnt; i++)
	{
		tmpMap = wordsMap;
		bool isFound = true;
		//遍历所有的words是否出现在由i开始的字符串中
		for (int j = 0; j < wordsCnt;j++)
		{
			string subStr = s.substr(i+j*wordsLen, wordsLen);
			if (tmpMap.find(subStr) == tmpMap.end() || tmpMap[subStr] == 0) //未发现或者发现了但数量不够
			{
				isFound = false;
				break;
			}
			else
				tmpMap[subStr]--;
		}

		if (isFound)
			returnV.push_back(i);
	}

	return returnV;
}

void testPrint(string s,vector<string> v)
{
	vector<int> v1 = findSubstring(s,v);

	for (auto i : v1)
		cout << i << " ";

	cout << endl;
}

int main()
{
	vector<string> v1;
	v1.push_back("ab");
	v1.push_back("ba");

	testPrint("abbababa",v1);

	return 0;
}
