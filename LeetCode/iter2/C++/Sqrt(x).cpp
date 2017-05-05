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
	//牛顿迭代法：Xn+1 = (Xn+a/Xn)/2
	int mySqrt(int x) {
		if (x == 0)
			return 0;

		double base = x;
		double pre = base-1;

		while (absDiff(base -pre) >= 0.1) {
			pre = base;
			base = (base + x / base) / 2.0;
		}

		return (int)base;
	}
private:
	double absDiff(double diff)
	{
		if (diff < 0)
			diff = -diff;

		return diff;
	}
};

int main(void)
{
	Solution s;

	for(int i=0;i<130;i++)
		cout << i<<" "<<s.mySqrt(i) << endl;
	//cout << 3 << " " << s.mySqrt(3) << endl;

	return 0;
}