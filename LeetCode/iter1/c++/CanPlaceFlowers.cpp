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
	bool canPlaceFlowers(vector<int>& flowerbed, int n) {
		vector<int> tmpV(flowerbed.size() + 2, 0);
		for (int i = 1; i <= flowerbed.size(); i++) {
			tmpV[i] = flowerbed[i - 1];
		}

		int i = 1;
		int flowerCnt = 0;
		while (i < tmpV.size() - 1) {
			if (tmpV[i] == 1) {
				i += 2;
			}
			else {
				if (tmpV[i - 1] + tmpV[i] + tmpV[i + 1] == 0) {
					flowerCnt++;
					i += 2;
				}
				else {
					i++;
				}
			}
		}

		return flowerCnt >= n;
	}
};

void print(bool result) {
	result ? cout << "true\n" : cout << "false\n";
}

int main(void)
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(0);
	v1.push_back(0);
	v1.push_back(0);
	v1.push_back(1);

	vector<int> v2;
	v2.push_back(0);
	v2.push_back(0);
	v2.push_back(1);
	v2.push_back(0);
	v2.push_back(0);

	Solution s;
	print(s.canPlaceFlowers(v1, 1));
	print(s.canPlaceFlowers(v1, 2));
	print(s.canPlaceFlowers(v2, 1));
	print(s.canPlaceFlowers(v2, 2));
	print(s.canPlaceFlowers(v2, 3));
	print(s.canPlaceFlowers(v2, 4));
	print(s.canPlaceFlowers(v2, 5));

	return 0;
}