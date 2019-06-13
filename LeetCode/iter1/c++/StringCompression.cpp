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
	int compress(vector<char>& chars) {
		int retLen = 0, tmpLen = 1;
		char preChar = chars[0];
		int preIdx = 0;
		for (int i = 1; i < chars.size(); i++) {
			if (chars[i] == preChar) {
				tmpLen++;
			}
			else {
				chars[preIdx] = preChar;
				string lenStr = num2Str(tmpLen);
				retLen++;
				if (tmpLen > 1) {
					for (int j = 1; j <= lenStr.size(); j++) {
						chars[preIdx + j] = lenStr[j - 1];
					}
					retLen += lenStr.size();
					preIdx += lenStr.size();
				}

				preIdx++;
				preChar = chars[i];
				tmpLen = 1;
			}
		}

		chars[preIdx] = preChar;
		if (tmpLen > 1) {
			string lenStr = num2Str(tmpLen);
			for (int j = 1; j <= lenStr.size(); j++) {
				chars[preIdx + j] = lenStr[j - 1];
			}

			retLen += lenStr.size();
		}

		return retLen + 1;
	}
private:
	string num2Str(int num) {
		stringstream ss;
		ss << num;
		string s;
		ss >> s;
		return s;
	}
};

void printVector(vector<char> v) {
	for (char ch : v) {
		cout << ch << " ";
	}
	cout << endl;
}

int main(void)
{
	Solution s;
	vector<char> chars1; //a2b2c5
	chars1.push_back('a');
	chars1.push_back('a');
	chars1.push_back('b');
	chars1.push_back('b');
	chars1.push_back('c');
	chars1.push_back('c');
	chars1.push_back('c');
	chars1.push_back('c');
	chars1.push_back('c');

	vector<char> chars2; //a3
	chars2.push_back('a');
	chars2.push_back('a');
	chars2.push_back('a');

	vector<char> chars3; //a2b
	chars3.push_back('a');
	chars3.push_back('b');
	chars3.push_back('a');

	vector<char> chars4; //abc
	chars4.push_back('a');
	chars4.push_back('b');
	chars4.push_back('c');

	vector<char> chars5; //a3b
	chars5.push_back('a');
	chars5.push_back('b');
	chars5.push_back('a');
	chars5.push_back('a');

	vector<char> chars6; //a2b100c99
	chars6.push_back('a');
	chars6.push_back('a');
	for (int i = 0; i < 100; i++) {
		chars6.push_back('b');
	}
	for (int i = 0; i < 99; i++) {
		chars6.push_back('c');
	}

	vector<char> chars7; //a2b100c
	chars7.push_back('a');
	chars7.push_back('a');
	for (int i = 0; i < 100; i++) {
		chars7.push_back('b');
	}
	chars7.push_back('c');

	vector<char> chars8; //abc6
	chars8.push_back('a');
	chars8.push_back('b');
	for (int i = 0; i < 6; i++) {
		chars8.push_back('c');
	}

	vector<char> chars9; //a5b2
	chars9.push_back('a');
	chars9.push_back('a');
	chars9.push_back('a');
	chars9.push_back('b');
	chars9.push_back('b');
	chars9.push_back('a');
	chars9.push_back('a');

	cout << s.compress(chars1) << endl;
	printVector(chars1);
	cout << s.compress(chars2) << endl;
	printVector(chars2);
	cout << s.compress(chars3) << endl;
	printVector(chars3);
	cout << s.compress(chars4) << endl;
	printVector(chars4);
	cout << s.compress(chars5) << endl;
	printVector(chars5);
	cout << s.compress(chars6) << endl;
	printVector(chars6);
	cout << s.compress(chars7) << endl;
	printVector(chars7);
	cout << s.compress(chars8) << endl;
	printVector(chars8);
	cout << s.compress(chars9) << endl;
	printVector(chars9);

	return 0;
}