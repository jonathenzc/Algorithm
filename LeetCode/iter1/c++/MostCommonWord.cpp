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
	string mostCommonWord(string paragraph, vector<string>& banned) {
		//从头过滤
		int start = 0;
		while (!judgeHelper(paragraph[start], 'a', 'z') && !judgeHelper(paragraph[start], 'A', 'Z')) {
			start++;
		}

		//从尾过滤
		int end = paragraph.size() - 1;
		while (!judgeHelper(paragraph[end], 'a', 'z') && !judgeHelper(paragraph[end], 'A', 'Z')) {
			end--;
		}

		//构建单词与个数的映射
		int startI = start - 1, endI = start;
		for (int i = start; i <= end; i++) {
			if (judgeHelper(paragraph[i], 'a', 'z') || (judgeHelper(paragraph[i], 'A', 'Z'))) {
				endI = i;
			}
			else {
				if (endI > startI) {
					strTolower(paragraph, startI, endI);
				}
				startI = i;
			}
		}

		strTolower(paragraph, startI, endI);

		//将banned存入map中
		unordered_set<string> bannedSet;
		for (string s : banned)
			bannedSet.insert(s);

		//遍历wordMap查找最大
		unordered_map<string, int>::iterator iter;
		string ret;
		int cnt = INT_MIN;
		for (iter = wordMap.begin(); iter != wordMap.end(); iter++) {
			if (bannedSet.find(iter->first) == bannedSet.end()) {
				if (iter->second > cnt) {
					ret = iter->first;
					cnt = iter->second;
				}
			}
		}

		return ret;
	}
private:
	unordered_map<string, int> wordMap;

	bool judgeHelper(char target, char a, char b) {
		return target >= a && target <= b;
	}

	void strTolower(string s, int start, int end) {
		string tmp = s.substr(start + 1, end - start);
		transform(tmp.begin(), tmp.end(), tmp.begin(), (int(*)(int))tolower);
		wordMap[tmp]++;
	}
};

int main(void)
{
	vector<string> banned;
	banned.push_back("hit");

	Solution s;
	cout << s.mostCommonWord("Bob hit a ball, the hit BALL flew far after it was hit.", banned);

	return 0;
}