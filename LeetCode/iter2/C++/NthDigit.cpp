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

		long long nLL = n;
		long long base = 9;
		int digitCnt = 1;
		long long baseSum = 0;

		while (nLL > 0)
		{
			nLL -= base * digitCnt;
			if (nLL < 0)
				break;

			baseSum += base;
			base *= 10;
			digitCnt++;
		}

		nLL += base * (digitCnt);

		int target = (nLL - 1) / digitCnt + 1 + baseSum;
		int targetDigit = (nLL - 1) % digitCnt;

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
	
	for (int i = 1; i < 30; i++)
		cout << s.findNthDigit(i) << " ";

	cout << endl << s.findNthDigit(199) << endl;
	cout << s.findNthDigit(200) << endl;
	cout << s.findNthDigit(201) << endl;
	cout << s.findNthDigit(INT_MAX) << endl;




	return 0;
} 