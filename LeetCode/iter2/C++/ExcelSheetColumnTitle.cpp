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
	string convertToTitle(int n) {
		string ret = "";

		while (n > 0)
		{
			char ch = (n-1) % 26+'A';
			ret = ch + ret;

			n = (n - 1) / 26;
		}

		return ret;
	}
};

void testPrint(int num)
{
	Solution s;

	cout << num <<" Excel Sheet Column Title "<<s.convertToTitle(num) << endl;
}

int main(void)
{
	testPrint(1);
	testPrint(25);
	testPrint(26);
	testPrint(703);
	testPrint(704);
	testPrint(28);
	testPrint(52);
	testPrint(53);

	return 0;
}