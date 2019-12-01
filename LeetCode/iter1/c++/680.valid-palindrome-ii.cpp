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
	bool validPalindrome(string s) {
		bool ret = true;
		int l = 0, r = s.size() - 1;
		while (l < r) {
			if (s[l] != s[r]) {
				ret = isPalindromeHelper(s, l + 1, r) || isPalindromeHelper(s, l, r - 1);
				break;
			}

			l++;
			r--;
		}

		return ret;
	}
private:
	bool isPalindromeHelper(string s, int l, int r) {
		bool ret = true;

		while (l < r) {
			if (s[l++] != s[r--]) {
				ret = false;
				break;
			}
		}

		return ret;
	}
};

int main()
{
	Solution solution;
	cout << (solution.validPalindrome("deeee") ? "Yes\n" : "No\n");
	cout << (solution.validPalindrome("aba") ? "Yes\n" : "No\n");
	cout << (solution.validPalindrome("abca") ? "Yes\n" : "No\n");
	cout << (solution.validPalindrome("abcd") ? "Yes\n" : "No\n");

	return 0;
}