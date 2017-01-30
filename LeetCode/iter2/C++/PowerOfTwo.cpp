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
	bool isPowerOfTwo(int n) {
		if (n <= 0)
			return false;

		if ((n&(n - 1)) == 0)
			return true;
		else
			return false;
	}
};

void testPrint(int n)
{
	Solution s;
	
	if (s.isPowerOfTwo(n))
		cout << "Yes\n";
	else
		cout << "No\n";
}

int main(void)
{
	Solution s;
	
	testPrint(0);
	testPrint(2);
	testPrint(1);
	testPrint(3);
	testPrint(15);

	return 0;
}