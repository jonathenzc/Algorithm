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
	bool isOneBitCharacter(vector<int>& bits) {
		bool ret = true;

		int i = 0;
		while (i < bits.size() - 1) { //最后一个为0
			if (bits[i] == 1) {
				if (i + 1 < bits.size() - 1) {
					i += 2;
				}
				else {
					ret = false;
					break;
				}
			}
			else {
				i++;
			}
		}

		return ret;
	}
};

void testPrint(vector<int> v) {
	Solution s;

	if (s.isOneBitCharacter(v))
		cout << "Yes\n";
	else
		cout << "No\n";
}

int main(void)
{
	vector<int> v0;
	v0.push_back(1);
	v0.push_back(1);
	v0.push_back(0);

	testPrint(v0);

	vector<int> v1;
	v1.push_back(1);
	v1.push_back(0);

	testPrint(v1);

	vector<int> v2;
	v2.push_back(1);
	v2.push_back(0);
	v2.push_back(0);

	testPrint(v2);

	vector<int> v3;
	v3.push_back(0);
	v3.push_back(0);
	v3.push_back(0);
	v3.push_back(0);

	testPrint(v3);

	vector<int> v4;
	v4.push_back(0);
	v4.push_back(0);
	v4.push_back(1);
	v4.push_back(0);

	testPrint(v4);

	vector<int> v5;
	v5.push_back(1);
	v5.push_back(0);
	v5.push_back(1);
	v5.push_back(0);

	testPrint(v5);

	return 0;
}