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
	int fib(int N) {
		if (N <= 1) {
			return N;
		}
		int fn = 1, fnpre = 0;
		for (int i = 2; i <= N; i++) {
			int f = fn + fnpre;
			fnpre = fn;
			fn = f;
		}
		return fn;
	}
};

int main(void)
{
	Solution s;
	for (int i = 0; i <= 30; i++) {
		cout << s.fib(i) << " ";
	}

	return 0;
}