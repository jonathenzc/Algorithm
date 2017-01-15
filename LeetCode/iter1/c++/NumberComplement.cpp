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
	//方法1：找到比原数大的二进制位数
	//int findComplement(int num) {
	//	long long sum = 1;

	//	while (sum <= num)
	//	{
	//		sum = sum << 1;
	//	}

	//	return sum - num-1;
	//}

	//方法2：用异或来处理
	int findComplement(int num) {
		int ret = 0;
		int cnt = 0;
		while (num != 0)
		{
			ret += ((num & 1) ^ 1)<<cnt;

			num >>= 1;

			cnt++;
		}

		return ret;
	}
};

void testPrint(vector<string> v)
{
	for (auto s : v)
		cout << s << endl;
}

int main(void)
{
	Solution s;
	
	cout << s.findComplement(5)<<endl;
	cout << s.findComplement(1)<<endl;

	return 0;
}