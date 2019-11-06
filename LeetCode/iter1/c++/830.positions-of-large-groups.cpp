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
	vector<vector<int>> largeGroupPositions(string S) {
		S += ' ';
		vector<vector<int>> ret;
		if (S.length() == 0) return ret;

		char preChar = S[0];
		int preIdx = 0;
		for (int i = 1; i < S.length();i++) {
			if (preChar == S[i]) continue;

			if (i - preIdx >= 3) {
				vector<int> tmpV;
				tmpV.push_back(preIdx);
				tmpV.push_back(i-1);
				ret.push_back(tmpV);
			}
			preChar = S[i];
			preIdx = i;
		}

		return ret;
	}	
};

void printHelper(vector<vector<int>> v) {
	for (auto numV : v) {
		cout << "[";
		for (int num : numV) {
			cout << num<<" ";
		}
		cout << "]";
	}
	cout << endl;
}

int main()
{
	Solution solution;
	printHelper(solution.largeGroupPositions("aaa"));
	printHelper(solution.largeGroupPositions("abbxxxxzzy"));
	printHelper(solution.largeGroupPositions("abc"));
	printHelper(solution.largeGroupPositions("abcdddeeeeaabbbcd"));

	return 0;
}