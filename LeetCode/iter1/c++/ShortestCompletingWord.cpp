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
	string shortestCompletingWord(string licensePlate, vector<string>& words) {
		string ret = "";
		int minLen = INT_MAX;
		for (string s : words) {
			vector<int> dictionary = str2dictionary(s);
			bool isFound = true;
			for (char ch : licensePlate) {
				char loweredChar = tolower(ch);
				if (loweredChar >= 'a' && loweredChar <= 'z') {
					if (dictionary[loweredChar - 'a'] == 0) {
						isFound = false;
						break;
					}
					dictionary[loweredChar - 'a']--;
				}
			}
			if (isFound && s.size() < minLen) {
				minLen = s.size();
				ret = s;
			}
		}

		return ret;
	}
private:
	vector<int> str2dictionary(string s) {
		vector<int> v(26, 0);
		for (char ch : s) {
			v[tolower(ch) - 'a']++;
		}
		return v;
	}
};

void print(bool result) {
	result ? cout << "true\n" : cout << "false\n";
}

int main(void)
{
	Solution s;
	vector<string> v1;
	v1.push_back("step");
	v1.push_back("steps");
	v1.push_back("stripe");
	v1.push_back("stepple");

	cout << s.shortestCompletingWord("1s3 PSt", v1) << endl;

	vector<string> v2;
	v2.push_back("looks");
	v2.push_back("pest");
	v2.push_back("stew");
	v2.push_back("stow");
	cout << s.shortestCompletingWord("1s3 456", v2) << endl;

	return 0;
}