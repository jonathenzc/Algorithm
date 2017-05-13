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
	int hammingDistance2(int x, int y) {
		int cnt = 0;
		int digitX = 0, digitY = y;

		while (x != 0 || y != 0)
		{
			digitX = x & 1;
			digitY = y & 1;

			if (digitX != digitY)
				cnt++;

			x >>= 1;
			y >>= 1;
		}

		return cnt;
	}

	int hammingDistance(int x, int y) {
		int XOR = x^y;

		int cnt = 0;
		while (XOR > 0)
		{
			cnt += (XOR & 1);
			XOR >>= 1;
		}


		return cnt;
	}
};

int main(void)
{
	Solution s;

	cout << s.hammingDistance(1, 2) << endl;
	cout << s.hammingDistance(1, 7) << endl;
	cout << s.hammingDistance(1, 4) << endl;



	return 0;
}