#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <queue>
#include <stack>

using namespace std;

class Solution {
public:
	vector<int> findSubstring(string s, vector<string>& words) {
		int wordLen = words[0].size();
		int subStrLen = wordLen*words.size();

		if (subStrLen > s.size())
			return v;
		
		unordered_map<string, int> wordCntMap;
		for (string tmpS : words)
			wordCntMap[tmpS]++;

		int strI = 0;

		while (strI <= s.size()- subStrLen)
		{
			int i = strI;
			int candidate = findSubstrCandidate(wordCntMap,s,strI,wordLen,subStrLen);

			if (candidate != -1)
				v.push_back(candidate);

			strI++;
		}

		return v;
	}
private:
	vector<int> v;

	int findSubstrCandidate(unordered_map<string, int> wordCntMap,string s,int index,int wordLen,int subStrLen)
	{
		int ret = -1;

		int i = index;

		while (i < index + subStrLen)
		{
			string s_subStr = s.substr(i, wordLen);

			if (wordCntMap[s_subStr] > 0)
			{
				wordCntMap[s_subStr]--;
				i += wordLen;
			}
			else
				break;
		}

		if (i == index+subStrLen)
			ret = index;

		return ret;
	}
};

void testPrint(vector<int> v)
{
	for (int num : v)
		cout << num << " ";

	cout << endl;
}

int main(void)
{
	vector<string> word;
	word.push_back("foo");
	word.push_back("bar");
	
	Solution s;
	//vector<int> v1 = s.findSubstring("barfoothefoobarman",word);
	vector<int> v2 = s.findSubstring("barbar", word);

	//testPrint(v1);
	testPrint(v2);
	return 0;
}