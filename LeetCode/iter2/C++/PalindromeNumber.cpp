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
	bool isPalindrome(int x) {
		if (x < 0 || (x != 0 && x%10 == 0))
			return false;

		int halfInt = 0;
		while (halfInt < x)
		{
			halfInt = 10 * halfInt + x%10;
			x /= 10;
		}

		if (halfInt == x)
			return true;
		else
		{
			if (halfInt / 10 == x) //处理12321
				return true;
			else
				return false;
		}
	}
};

void testPrint(int num)
{
	Solution s;
	if (s.isPalindrome(num))
		cout << num << " is palindrome\n";
	else
		cout << num << " is not palindrome\n";
}

int main(void)
{
	testPrint(10);
	testPrint(11);
	testPrint(10100);
	testPrint(3221);
	testPrint(1223);
	testPrint(12421);
	testPrint(1221);
	testPrint(34541);

	return 0;
}