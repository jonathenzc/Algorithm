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
	Solution() {
		string target = "\", ";
		string morseMapStr = "\".-\", \"-...\", \"-.-.\", \"-..\", \".\", \"..-.\", \"--.\", \"....\", \"..\", \".---\", \"-.-\", \".-..\", \"--\", \"-.\", \"---\", \".--.\", \"--.-\", \".-.\", \"...\", \"-\", \"..-\", \"...-\", \".--\", \"-..-\", \"-.--\", \"--..\"";
		int idx = 0-target.length();
		while (idx < (int)morseMapStr.length()) {
			int start = idx+ target.length();
			idx = morseMapStr.find(target, start);
			if (idx != -1) {
				morseMap.push_back(morseMapStr.substr(start+1, idx - start-1));
			}
			else {
				morseMap.push_back(morseMapStr.substr(start + 1, morseMapStr.length() - start - 2));
				break;
			}
		}
	}

	int uniqueMorseRepresentations(vector<string>& words) {
		unordered_map<string, int> morseStrMap;
		for (string word : words) {
			string morseStr = "";
			for (char ch : word) {
				morseStr += morseMap[ch - 'a'];
			}

			morseStrMap[morseStr]++;
		}

		return morseStrMap.size();
	}
private:
	vector<string> morseMap;
};

int main(void)
{
	vector<string> v;
	v.push_back("gin");
	v.push_back("zen");
	v.push_back("gig");
	v.push_back("msg");

	Solution s;
	cout << s.uniqueMorseRepresentations(v);

	return 0;
}