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
	int trailingZeroes(int n) {
		int cnt = 0;
		while (n > 0)
		{
			cnt += n / 5;
			n = n / 5;
		}

		return cnt;
	}
};

int main(void)
{
	Solution s;

	for(int i=0;i<130;i++)
		cout << i<<" "<<s.trailingZeroes(i) << endl;
	

	return 0;
}