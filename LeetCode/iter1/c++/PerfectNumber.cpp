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
	bool checkPerfectNumber(int num) {
		if (num <= 1) return false;

		int target = num-1, divisor = sqrt(num);
		while (target > 0 && divisor > 1) {
			if (num % divisor == 0) {
				target -= divisor;
				target -= (num / divisor);
			}
			divisor--;
		}

		return target == 0;
	}
};

void print(int num, bool result) {
	result ? cout << num << " true\n" : cout << num << " false\n";
}

int main(void)
{
	Solution s;
	for (int i = 0; i < 50; i++) {
		print(i, s.checkPerfectNumber(i));
	}
	print(496, s.checkPerfectNumber(496));
	print(8128, s.checkPerfectNumber(8128));
	print(33550336, s.checkPerfectNumber(33550336));

	return 0;
}