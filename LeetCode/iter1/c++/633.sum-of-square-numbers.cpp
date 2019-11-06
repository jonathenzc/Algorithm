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
	bool judgeSquareSum(int c) {
		int upperBound = sqrt(c);
		unordered_set<int> set;
		for (int i = 0; i <= upperBound; i++) {
			int iSquare = i*i;
			set.insert(iSquare);
			if (set.count(c-iSquare) > 0) {
				return true;
			}
		}

		return false;
	}
};

int main()
{
	Solution solution;
	cout << (solution.judgeSquareSum(2) ? "true\n" : "false\n");
	cout << (solution.judgeSquareSum(4) ? "true\n" : "false\n");
	cout << (solution.judgeSquareSum(5) ? "true\n" : "false\n");
	cout << (solution.judgeSquareSum(9) ? "true\n" : "false\n");
	cout << (solution.judgeSquareSum(147) ? "true\n" : "false\n");
	cout << (solution.judgeSquareSum(2147482647) ? "true\n" : "false\n");

	return 0;
}