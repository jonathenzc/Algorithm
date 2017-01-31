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
	bool isPowerOfThree(int n) {
		return (n > 0 && (1162261467 %n == 0)); //1162261467是3的19次方
	}
};

void testPrint(int n)
{
	Solution s;
	
	if (s.isPowerOfThree(n))
		cout << n<<" is power of three\n";
	else
		cout << n<<" is not power of three\n";
}

int main(void)
{
	testPrint(81);
	testPrint(89);

	return 0;
}