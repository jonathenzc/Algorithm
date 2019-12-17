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
	vector<int> selfDividingNumbers(int left, int right) {
		vector<int> v;
		for (int i = left; i <= right; i++) {
			if (whetherDividing(i)) {
				v.push_back(i);
			}
		}
		return v;
	}
private:
	bool whetherDividing(int num) {
		bool ret = true;
		int tmpNum = num, digit;
		while (tmpNum != 0) {
			digit = tmpNum % 10;
			tmpNum /= 10;
			if (digit == 0 || num % digit != 0) {
				ret = false;
				break;
			}
		}

		return ret;
	}
};

void testPrint(vector<int> v) {
	for (int num : v) {
		cout << num << " ";
	}
	cout << endl;
}

int main(void)
{
	Solution s;
	testPrint(s.selfDividingNumbers(1, 22));

	return 0;
}