#include <iostream>
#include <unordered_set>
#include <string>
#include <vector>

using namespace std;

bool isWordBreakable(string s, unordered_set<string>& wordDict) {
	//canBeSegmented[i]��ʾ���ַ���[0...i]�ܷ���wordDict�е�Ԫ�����
	bool *canBeSegmented = new bool[s.size() + 1];
	canBeSegmented[0] = true;
	for (int i = 1; i <= s.size(); i++)
		canBeSegmented[i] = false;//���ַ���������wordDict�е�Ԫ�����

	for (int i = 1; i <= s.size(); i++)
	{
		unordered_set<string>::iterator iter;
		for (iter = wordDict.begin(); iter != wordDict.end(); iter++)
		{
			int strSize = (*iter).size();
			if (i >= strSize && canBeSegmented[i - strSize])//���ַ���[0...j-strSize]����wordDict�е�Ԫ�����
			{
				//�ж����ַ���[j-strSize...strSize]�Ƿ���Ժ͸�Ԫ����ͬ
				string substr = s.substr(i - strSize, strSize);
				if (substr == (*iter))
					canBeSegmented[i] = true;
			}
		}
	}

	//�����̬�滮���������
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


void dfs(string s, unordered_set<string>& wordDict,int index,string sentence,vector<string> &v)
{
	unordered_set<string>::iterator iter;

	for (iter = wordDict.begin(); iter != wordDict.end(); iter++)
	{
		if ((*iter) == s.substr(index, (*iter).size()))
		{
			string newStr = sentence + (*iter);

			if (index + (*iter).size() != s.size())
			{
				newStr += " ";
				dfs(s, wordDict, index + (*iter).size(), newStr, v);
			}
			else
				v.push_back(newStr); 
		}
	}
}

//void dfs(string s, unordered_set<string>& wordDict,vector<string> &v)
//{
//	for (int i = 0; i < s.size(); i++)
//	{
//		if (wordDict.find(s.substr(1)))
//	}
//}

vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
	vector<string> v;

	if (s.size() != 0 && wordDict.size() != 0)
	{
		for (int j = s.size() - 1; j >= 0; j--){
			if (wordDict.find(s.substr(j)) != wordDict.end())
				break;
			else{
				if (j == 0)
					return v;
			}
		}
		
		dfs(s, wordDict, 0, "", v);
	}

	return v;
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

	vector<string> v;
	v = wordBreak(s,wordDict);

	for (int i = 0; i < v.size(); i++)
		cout << v[i] << endl;

	return 0;
}