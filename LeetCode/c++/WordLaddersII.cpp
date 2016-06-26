#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>

using namespace std;

//方法1：
////判断两个字符串是否只相差一个字符
//bool isDiffOneCh(string s1, string s2)
//{
//	bool result = true;
//
//	bool isDiffFound = false;
//	for (int i = 0; i < s1.size(); i++)
//	{
//		if (s1[i] != s2[i])
//		{
//			if (isDiffFound) //两个
//			{
//				result = false;
//				break;
//			}
//			else
//				isDiffFound = true;
//		}
//	}
//
//	if (result && !isDiffFound)
//		result = false;
//
//	return result;
//}
//
//void helper(string beginword,string endword, unordered_set<string> wordList, vector<string> strV,vector<vector<string>> &v)
//{
//	unordered_set<string>::iterator iter = wordList.begin();
//
//	if (iter != wordList.end())
//	{
//		if (isDiffOneCh(beginword, endword))
//		{
//			strV.push_back(endword);
//
//			v.push_back(strV);
//		}
//		else
//		{
//			while (iter != wordList.end())
//			{
//
//				if (isDiffOneCh(beginword, *iter))
//				{
//					unordered_set<string> tmpSet = wordList;
//					tmpSet.erase(*iter);
//
//					vector<string> tmpStrV = strV;
//					tmpStrV.push_back(*iter);
//
//					helper(*iter, endword, tmpSet, tmpStrV, v);
//				}
//
//				iter++;
//			}
//		}
//	}
//}
//
//vector<vector<string>> findLadders(string beginWord, string endWord, unordered_set<string> &wordList) {
//	vector<string> strV;
//	strV.push_back(beginWord);
//
//	vector<vector<string>> v;
//
//	helper(beginWord, endWord, wordList, strV,v);
//
//	//去除数量最多的
//	int minSize = INT_MAX;
//
//	for (int i = 0; i < v.size(); i++)
//	{
//		if (v[i].size() < minSize)
//			minSize = v[i].size();
//	}
//
//	vector<vector<string>> resultV;
//
//	for (int i = 0; i < v.size(); i++)
//	{
//		if (v[i].size() == minSize)
//			resultV.push_back(v[i]);
//	}
//
//
//	return resultV;
//}

//方法2：
void helper(string beginWord, string endWord,unordered_map<string, unordered_set<string>> levelGraph,vector<string> path,vector<vector<string>> &v)
{
	if (beginWord == endWord)
	{
		reverse(path.begin(),path.end());

		v.push_back(path);
	}
	else
	{
		unordered_set<string> levelNodeSet = levelGraph[beginWord];
		unordered_set<string>::iterator iter = levelNodeSet.begin();

		while (iter != levelNodeSet.end())
		{
			vector<string> tmp = path;
			tmp.push_back(*iter);
			helper(*iter,endWord,levelGraph,tmp,v);

			iter++;
		}
	}
}

vector<vector<string>> findLadders(string beginWord, string endWord, unordered_set<string> &wordList) {
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
	while (iterSet.count(endWord) == 0 && restSet.size() > 0)
	{
		for (auto curIter = currentNodeSet.begin(); curIter != currentNodeSet.end(); curIter++)
		{
			restSet.erase(*curIter);
		}

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
						if(restSet.find(s) != restSet.end())
						{
							levelGraph[s].insert(oldS);
							currentNodeSet.insert(s); //保存下一次遍历时的一层节点
						}
					}
				}
			}
		}

		if (currentNodeSet.size() == 0)
			break;
	}
	
	//广度优先搜索找到beginWord到endWord的路径
	vector<vector<string>> resultV;
	vector<string> path;
	path.push_back(endWord);

	helper(endWord,beginWord,levelGraph,path,resultV);

	return resultV;
}

void testPrint(string beginWord, string endWord, unordered_set<string> wordList)
{
	vector<vector<string>> v = findLadders(beginWord, endWord, wordList);

	for (int i = 0; i < v.size(); i++)
	{
		vector<string> tmpV = v[i];		for (int j = 0; j < tmpV.size(); j++)
			cout << tmpV[j] << " ";

		cout << endl;
	}
}

int main()
{
	unordered_set<string> set;
	set.insert("hot");
	set.insert("dot");
	set.insert("dog");
	set.insert("lot");
	set.insert("log");
	set.insert("abc");

	testPrint("hit", "cog", set);

	unordered_set<string> set1;
	set1.insert("a");
	set1.insert("b");
	set1.insert("c");

	testPrint("a", "c", set1);

	unordered_set<string> set2;
	set2.insert("hot");
	set2.insert("dog");

	testPrint("hot", "dog", set2);

	return 0;
}