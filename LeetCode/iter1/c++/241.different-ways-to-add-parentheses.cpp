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
	vector<int> diffWaysToCompute(string input) {
		return diffWaysToComputeHelper(input, 0, input.size() - 1);
	}
private:
	vector<int> diffWaysToComputeHelper(string s, int startIdx, int endIdx) {
		vector<int> v;
		int num = isAllNumber(s, startIdx, endIdx);
		if (num != -1) {
			v.push_back(num);
			return v;
		}

		for (int i = startIdx; i <= endIdx; i++) {
			if (s[i] == '+' || s[i] == '-' || s[i] == '*') {
				vector<int> leftV = diffWaysToComputeHelper(s, startIdx, i - 1);
				vector<int> rightV = diffWaysToComputeHelper(s, i + 1, endIdx);

				for (int leftVal : leftV) {
					for (int rightVal : rightV) {
						if (s[i] == '+') v.push_back(leftVal + rightVal);
						if (s[i] == '-') v.push_back(leftVal - rightVal);
						if (s[i] == '*') v.push_back(leftVal * rightVal);
					}
				}
			}
		}

		return v;
	}


	int isAllNumber(string input, int startIdx, int endIdx) {
		int ret = 0, digit = 1;
		for (int i = endIdx; i >= startIdx; i--) {
			if (input[i] < '0' || input[i] > '9') {
				ret = -1;
				break;
			}

			ret += (input[i] - '0') * digit;
			digit *= 10;
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
	testPrint(s.diffWaysToCompute("2-1-1"));
	testPrint(s.diffWaysToCompute("2*3-4*5"));

	return 0;
}