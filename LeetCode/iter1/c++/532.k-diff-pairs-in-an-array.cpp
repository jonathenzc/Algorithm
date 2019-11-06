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
	int findPairs(vector<int>& nums, int k) {
		if (k < 0) {
			return 0;
		}
		int pairsCnt = 0;
		unordered_map<int, unordered_set<int>> key2Used;
		for (int num : nums) {
			if (key2Used.find(num - k) == key2Used.end() &&
				key2Used.find(num + k) == key2Used.end()) {
				unordered_set<int> tmpSet;
				key2Used[num] = tmpSet;
			}
			else {
				if (key2Used.find(num - k) != key2Used.end()) {
					if (key2Used[num - k].count(num) == 0) {
						pairsCnt++;
						key2Used[num - k].insert(num);
						key2Used[num].insert(num - k);
					}
				}
				if (key2Used.find(num + k) != key2Used.end()) {
					if (key2Used[num + k].count(num) == 0) {
						pairsCnt++;
						key2Used[num + k].insert(num);
						key2Used[num].insert(num + k);
					}
				}
			}
		}

		return pairsCnt;
	}
};

int main()
{
	vector<int> v1;
	v1.push_back(3);
	v1.push_back(1);
	v1.push_back(4);
	v1.push_back(1);
	v1.push_back(5);

	vector<int> v2;
	v2.push_back(1);
	v2.push_back(2);
	v2.push_back(3);
	v2.push_back(4);
	v2.push_back(5);


	Solution solution;
	cout << solution.findPairs(v1, 2) << endl; //2
	cout << solution.findPairs(v1, 0) << endl; //1
	cout << solution.findPairs(v2, 1) << endl; //4
	cout << solution.findPairs(v2, 2) << endl; //3
	cout << solution.findPairs(v2, -1) << endl; //0

	return 0;
}