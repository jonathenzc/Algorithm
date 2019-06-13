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
#include <fstream>

using namespace std;

class Solution {
public:
	string licenseKeyFormatting(string S, int K) {
		int start = 0, end = S.size() - 1;
		while (start < S.size() && S[start] == '-') {
			start++;
		}

		while (end >= 0 && S[end] == '-') {
			end--;
		}

		string s = "";
		int i = end;
		while (i >= start) {
			if (S[i] == '-') {
				i--;
				continue;
			}

			int cnt = 0;
			while (cnt < K && i >= start) {
				if (S[i] != '-') {
					s += char(toupper(S[i]));
					cnt++;
				}

				i--;
			}

			if (i >= start)
				s += '-';
		}

		reverse(s.begin(), s.end());

		return s;
	}
private:
	char toUpperCase(char ch) {
		return ch + (ch >= 'a' && ch <= 'z' ? 'A' - 'a' : 0);
	};
};

void print(bool result) {
	result ? cout << "true\n" : cout << "false\n";
}

int main(void)
{
	Solution s;
	cout << s.licenseKeyFormatting("5F3Z-2e-9-w", 4) << endl;
	cout << s.licenseKeyFormatting("5F3Z-2e-9-w", 3) << endl;
	for (int i = 1; i < 8; i++) {
		cout << i << " " << s.licenseKeyFormatting("2-5g-3-J", i) << endl;
	}

	cout << s.licenseKeyFormatting("--a-a-a-a--", 2) << endl;
	cout << s.licenseKeyFormatting("--a-a----a-a--", 2) << endl;
	cout << s.licenseKeyFormatting("--------------", 2) << endl;
	cout << s.licenseKeyFormatting("------a--------", 2) << endl;
	cout << s.licenseKeyFormatting("------a--------", 3) << endl;

	return 0;
}