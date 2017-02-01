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
	bool isPowerOfFour(int num) {
		return num > 0 && (num&(num-1)) == 0 && (num - 1) % 3 == 0; //整除3是因为4^n-1 = (4-1)(4^(n-1)+4^(n-2)+...+4+1)
	}
};

void testPrint(int n)
{
	Solution s;
	
	if (s.isPowerOfFour(n))
		cout << n<<" is power of three\n";
	else
		cout << n<<" is not power of three\n";
}

int main(void)
{
	testPrint(81);
	testPrint(89);
	testPrint(64);
	return 0;
}