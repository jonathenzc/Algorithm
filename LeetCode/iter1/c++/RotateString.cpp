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
	bool rotateString(string A, string B) {
		if (A.size() != B.size()) return false;
		if (A == "" && B == "") return true;

		bool ret = false;
		for (int i = 0; i < A.size(); i++) {
			if (B.compare(A.substr(i, A.size() - i) + A.substr(0, i)) == 0) {
				ret = true;
				break;
			}
		}

		return ret;
	}
};

void testPrint(string A, string B) {
	Solution solution;
	if (solution.rotateString(A, B)) {
		cout << A << " is equal to " << B << endl;
	}
	else {
		cout << A << " is not equal to " << B << endl;
	}


	cout << endl;
}

int main(void)
{
	testPrint("abcde", "bcdea");
	testPrint("abcde", "abced");
	testPrint("", "");
	testPrint("", "a");

	return 0;
}