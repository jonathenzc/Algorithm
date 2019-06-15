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
	int thirdMax(vector<int>& nums) {
		long long first = LLONG_MIN, second = LLONG_MIN, third = LLONG_MIN;
		for (int num : nums) {
			if (num >= first) {
				if (num != first) {
					long long preFirst = first;
					first = num;
					if (preFirst >= second) {
						if (preFirst != second) {
							long long preSecond = second;
							second = preFirst;
							if (preSecond > third) {
								third = preSecond;
							}
						}
					}
					else if (preFirst > third) {
						third = preFirst;
					}
				}
			}
			else if (num >= second) {
				if (num != second) {
					long long preSecond = second;
					second = num;
					if (preSecond > third) {
						third = preSecond;
					}
				}
			}
			else if (num > third) {
				third = num;
			}
		}

		return third == LLONG_MIN ? first : third;
	}
};

void printVector(vector<char> v) {
	for (char ch : v) {
		cout << ch << " ";
	}
	cout << endl;
}

int main(void)
{
	Solution s;
	vector<int> v1;
	v1.push_back(3);
	v1.push_back(2);
	v1.push_back(1);

	cout << s.thirdMax(v1) << endl;

	vector<int> v2;
	v2.push_back(1);
	v2.push_back(2);
	cout << s.thirdMax(v2) << endl;

	vector<int> v3;
	v3.push_back(2);
	v3.push_back(2);
	v3.push_back(3);
	v3.push_back(1);
	cout << s.thirdMax(v3) << endl;

	vector<int> v4;
	v4.push_back(2);
	v4.push_back(2);
	v4.push_back(2);
	v4.push_back(2);
	v4.push_back(2);
	v4.push_back(2);
	v4.push_back(3);
	v4.push_back(3);
	v4.push_back(3);
	v4.push_back(3);
	v4.push_back(1);
	cout << s.thirdMax(v4) << endl;

	vector<int> v5;
	v5.push_back(2);
	v5.push_back(2);
	v5.push_back(2);
	v5.push_back(2);
	v5.push_back(2);
	v5.push_back(2);
	v5.push_back(3);
	v5.push_back(3);
	v5.push_back(3);
	v5.push_back(3);
	v5.push_back(1);
	v5.push_back(4);
	v5.push_back(1);
	cout << s.thirdMax(v5) << endl;

	vector<int> v6;
	v6.push_back(1);
	v6.push_back(2);
	v6.push_back(INT_MIN);
	cout << s.thirdMax(v6) << endl;

	return 0;
}