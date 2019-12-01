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
	bool hasAlternatingBits(int n) {
		bool ret = true;
		int digit = n & 1, oldDigit;
		while (n != 0) {
			n = n >> 1;
			oldDigit = n & 1;
			if (digit == oldDigit) {
				ret = false;
				break;
			}
			digit = oldDigit;
		}

		return ret;
	}
};

int main()
{
	Solution solution;
	for (int i = 0; i < 30; i++) {
		cout << i << " " << (solution.hasAlternatingBits(i) ? "Yes\n" : "No\n");
	}

	return 0;
}