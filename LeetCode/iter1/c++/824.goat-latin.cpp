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
	string toGoatLatin(string S) {
		S = S.append(" ");
		string ret = "";
		int wordCnt = 1;
		bool isChecked = false;
		char consonantCh = NULL;
		for (int i = 0; i < S.size(); i++) {
			if (S[i] == ' ') {
				if (consonantCh != NULL) {
					ret += consonantCh;
				}
				ret += "ma";
				//结尾补a判断
				for (int i = 0; i < wordCnt; i++) {
					ret += "a";
				}
				if (i != S.size() - 1) {
					ret += S[i];
				}

				//重置状态
				wordCnt++;
				isChecked = false;
				consonantCh = NULL;
				continue;
			}

			if (isChecked) {
				ret += S[i];
				continue;
			}

			//元辅音规则判断
			if (!isVowel(S[i])) {
				consonantCh = S[i];
			}
			else {
				ret += S[i];
			}

			isChecked = true;
		}

		return ret;
	}
private:
	bool isVowel(char ch) {
		return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'
			|| ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U';
	}
};

void printHelper(vector<int> v) {
	for (int num : v) {
		cout << num << " ";
	}
	cout << endl;
}

int main()
{
	Solution solution;
	//eg1
	cout << "[" << solution.toGoatLatin("I speak Goat Latin") << "]" << endl;

	//eg2
	cout << "[" << solution.toGoatLatin("The quick brown fox jumped over the lazy dog") << "]" << endl;

	//eg3
	cout << "[" << solution.toGoatLatin("over the lazy dog") << "]" << endl;

	//eg4
	cout << "[" << solution.toGoatLatin("Each word consists of lowercase and uppercase letters only") << "]" << endl;

	return 0;
}