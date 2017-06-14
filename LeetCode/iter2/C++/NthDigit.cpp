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
#include <map>

using namespace std;

class Solution {
public:
	int findNthDigit(int n) 
	{
		if (n < 10)
			return n;

		int base = 9;
		int digitCnt = 1;

		while (n > 0) 
		{
			base *= 10;
			digitCnt++;

			n -= base * digitCnt;
		}

		n += base * (digitCnt);

		base /= 10;

		int target = (n - 1) / digitCnt + 1 + base/10*(digitCnt);
		int targetDigit = (n - 1) % digitCnt;

		return getNumDigit(target, digitCnt-targetDigit);
	}
private:
	int getNumDigit(int num, int digit)
	{
		int cnt = 0;
		int ret = -1;
		while (cnt < digit)
		{
			ret = num % 10;
			num /= 10;
			cnt++;
		}

		return ret;
	}
};

int main(void)
{
	Solution s;
	
	//for (int i = 1; i < 30; i++)
	//	cout << s.findNthDigit(i) << " ";
	cout << s.findNthDigit(10) << " ";


	return 0;
} 