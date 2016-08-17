#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using namespace std;

//方法1：效率慢
//bool diffOne(string a, string b)
//{
//	int diffCnt = 0;
//	for (int i = 0; i < a.size(); i++)
//	{
//		if (a[i] != b[i])
//			diffCnt++;
//
//		if (diffCnt == 2)
//			return false;
//	}
//
//	if (diffCnt != 0)
//		return true;
//	else
//		return false;
//}
//
//void helper(string s, string endWord, unordered_map<string, bool> map, int &minLength, int &length)
//{
//	if (diffOne(s, endWord))
//	{
//		length++;
//		minLength = min(minLength,length);
//	}
//	else
//	{
//		for (auto iter = map.begin(); iter != map.end(); iter++)
//		{
//			if (!map[iter->first] && diffOne(s, iter->first))
//			{
//				unordered_map<string, bool> curMap = map;
//
//				curMap[iter->first] = true;
//
//				int curlength = length+1;
//				helper(iter->first, endWord, curMap, minLength, curlength);
//			}
//		}
//	}
//}
//
//int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
//	int min = INT_MAX;
//	int length = 1;
//
//	unordered_map<string, bool> map;
//	for (auto iter = wordList.begin(); iter != wordList.end(); iter++)
//		map[*iter] = false;
//
//	helper(beginWord, endWord, map, min, length);
//
//	if (min == INT_MAX)
//		min = 0;
//
//	return min;
//}

//方法2：构建一个两节点只差一个字符的图（图的储存形式反相储存），从start广搜至end
void helper(string beginWord, string endWord, unordered_map<string, unordered_set<string>> &levelGraph, int length, int &minLength)
{
	if (beginWord == endWord)
		minLength = min(minLength,length);
	else
	{
		unordered_set<string> levelNodeSet = levelGraph[beginWord];
		unordered_set<string>::iterator iter = levelNodeSet.begin();

		while (iter != levelNodeSet.end())
		{
			int tmpL = length+1;
			helper(*iter, endWord, levelGraph, tmpL, minLength);

			iter++;
		}
	}
}

int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
	//根据wordList构建单词差别只差1个字符的图
	unordered_map<string, unordered_set<string>> levelGraph; //键是图中的节点，值为该节点指向的下一层的节点集合
	unordered_set<string> restSet; //保留剩余未被选中的节点

	unordered_set<string> currentNodeSet; //当前层中的节点
	currentNodeSet.insert(beginWord);

	unordered_set<string> iterSet; //用于遍历的集合

								   //从wordList中移除beginWord并插入endWord
	wordList.erase(beginWord);
	wordList.insert(endWord);

	restSet = wordList;

	//构建图
	while (currentNodeSet.size() != 0)
	{
		restSet = wordList;

		//对每层的节点判断与未被选中的节点进行比较，是否只相差一个字符
		iterSet = currentNodeSet;
		currentNodeSet.clear();

		for (auto i = iterSet.begin(); i != iterSet.end(); i++)
		{
			string oldS = *i;
			string s = oldS;//当前层的节点

							//将s[i]至为26个字母中的某位，在剩余节点集中查找是否存在该单词
							//遍历当前节点单词中的每个字符
			for (int ch = 0; ch < oldS.size(); ch++)
			{
				s = oldS;
				//字符串只包含小写字母
				for (int j = 0; j < 26; j++)
				{
					if (s[ch] != 'a' + j)
					{
						s[ch] = 'a' + j;
						//在剩余节点集中寻找
						if (restSet.count(s) > 0)
						{
							levelGraph[s].insert(oldS);
							wordList.erase(s);
							currentNodeSet.insert(s); //保存下一次遍历时的一层节点
						}
					}
				}
			}
		}
	}

	//广度优先搜索找到beginWord到endWord的路径
	int length = 1;
	int minLength = INT_MAX;
	helper(endWord, beginWord, levelGraph, length, minLength);

	if (minLength == INT_MAX)
		minLength = 0;

	return minLength;
}

int main()
{
	unordered_set<string> wordList;
	wordList.insert("hot");
	wordList.insert("dot");
	wordList.insert("dog");
	wordList.insert("lot");
	wordList.insert("log");

	cout<<ladderLength("hit","cog",wordList)<<endl;

	unordered_set<string> wordList1;
	wordList1.insert("hot");
	wordList1.insert("dog");

	cout << ladderLength("hot", "dog", wordList1)<<endl;


	return 0;
}