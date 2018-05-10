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
	vector<string> letterCasePermutation(string S) {
		permutationStr(S, "", 0);

		return v;
	}
private:
	vector<string> v;

	void permutationStr(string s, string prefix, int index) {
		if (index >= s.size()) {
			v.push_back(prefix);
		}
		else {
			if (s[index] < '0' || s[index] > '9') {
				permutationStr(s, prefix + toLower(s[index]), index + 1);
				permutationStr(s, prefix + toUpper(s[index]), index + 1);
			}
			else {
				permutationStr(s, prefix + s[index], index + 1);
			}
		}
	}

	char toLower(char ch) {
		if (ch >= 'A' && ch <= 'Z') {
			ch = ch - 'A' + 'a';
		}

		return ch;
	}

	char toUpper(char ch) {
		if (ch >= 'a' && ch <= 'z') {
			ch = ch - 'a' + 'A';
		}

		return ch;
	}
};

void testPrint(string s) {
	Solution solution;
	vector<string> v = solution.letterCasePermutation(s);
	cout << "Original String " << s << endl;
	for (string tmp : v) {
		cout << tmp << endl;
	}

	cout << endl;
}

int main(void)
{
	testPrint("a1b2");
	testPrint("3z4");
	testPrint("3Z4");
	testPrint("12345");

	return 0;
}