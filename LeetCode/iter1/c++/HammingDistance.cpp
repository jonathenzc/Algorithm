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
	int hammingDistance(int x, int y) {
		int cnt = 0;

		while (!(x == 0 && y == 0))
		{
			int XOR_Result = (x & 1) ^ (y & 1);
			cnt += XOR_Result;

			x = x >> 1;
			y = y >> 1;
		}

		return cnt;
	}
};


int main(void)
{
	Solution s;

	cout << s.hammingDistance(1,4) << endl;


	return 0;
}