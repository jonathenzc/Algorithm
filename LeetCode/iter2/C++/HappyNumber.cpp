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
	bool isHappy(int n) {
		int sum = n;
		usedMap[sum] = 1;
		bool happyOrNot = true;

		while (sum > 1)
		{	
			sum = getSquareDigitSum(sum);
			if (usedMap[sum] != 0)
			{
				happyOrNot = false;
				break;
			}
			else
				usedMap[sum] = 1;
		}

		return happyOrNot;
	}
private:
	unordered_map<int, int> usedMap;

	int getSquareDigitSum(int n)
	{
		int ret = 0;
		while (n > 0)
		{
			int digit = n % 10;
			n = n / 10;
			ret += (digit)*(digit);
		}

		return ret;
	}
};

void testPrint(int n)
{
	Solution s;

	if (s.isHappy(n))
		cout << n << " is happy number.\n";
	else
		cout << n << " is not happy number.\n";
}

int main(void)
{

	testPrint(19);
	testPrint(1);
	testPrint(18);

	return 0;
}