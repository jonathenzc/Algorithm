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
	int arrangeCoins(int n) {
		return sqrt((long long)2 * n + 1) - 1.0 / 2;
	}
};

int main(void)
{
	Solution s;
	cout << s.arrangeCoins(5) << endl;
	cout << s.arrangeCoins(8) << endl;
	cout << s.arrangeCoins(1804289383) << endl;
	cout << s.arrangeCoins(INT_MAX) << endl;

	return 0;
}