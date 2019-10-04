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
	vector<int> shortestToChar(string S, char C) {
		vector<int> CIdxMap;
		CIdxMap.push_back(INT_MAX);
		for (int i = 0; i < S.length(); i++) {
			if (S[i] == C) {
				CIdxMap.push_back(i);
			}
		}
		CIdxMap.push_back(INT_MAX);

		vector<int> ret;
		int CIdx = 1, preCIdx = CIdxMap[CIdx-1], curCIdx = CIdxMap[CIdx];
		for (int i = 0; i < S.length(); i++) {
			if (i > curCIdx) {
				preCIdx = curCIdx;
				curCIdx = CIdxMap[++CIdx];
			}
			
			ret.push_back(min(abs(preCIdx - i), abs(curCIdx - i)));
		}

		return ret;
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
	string S = "loveleetcode";
	char C = 'e';
	printHelper(solution.shortestToChar(S, C));

	return 0;
}