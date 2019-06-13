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
	// 1 2 3 4 5 6 7 8 9
	// h     h   h
	// 0 1 2 0 1 0 1 2 3  右边覆盖
	// 0 2 1 2 1 0 0 0 0  左边覆盖
	//求左右覆盖中的最小值，最后再对整个数列求最大值
	int findRadius(vector<int>& houses, vector<int>& heaters) {
		sort(houses.begin(), houses.end());
		sort(heaters.begin(), heaters.end());

		vector<int> res(houses.size(), INT_MAX);
		//左边覆盖
		int houseIdx = 0, heaterIdx = 0;
		while (houseIdx < houses.size() && heaterIdx < heaters.size()) {
			if (heaters[heaterIdx] >= houses[houseIdx]) {
				res[houseIdx] = heaters[heaterIdx] - houses[houseIdx];
				houseIdx++;
			}
			else {
				heaterIdx++;
			}
		}

		//右边覆盖
		houseIdx = houses.size() - 1, heaterIdx = heaters.size()-1;
		while (houseIdx >= 0 && heaterIdx >= 0) {
			if (houses[houseIdx] >= heaters[heaterIdx]) {
				res[houseIdx] = min(houses[houseIdx] - heaters[heaterIdx], res[houseIdx]);
				houseIdx--;
			}
			else {
				heaterIdx--;
			}
		}

		return *max_element(res.begin(), res.end());
	}
};

void print(bool result) {
	result ? cout << "true\n" : cout << "false\n";
}

int main(void)
{
	Solution s;
	vector<int> houses0;
	houses0.push_back(1);
	houses0.push_back(2);
	houses0.push_back(3);
	houses0.push_back(4);
	houses0.push_back(5);
	houses0.push_back(6);
	houses0.push_back(7);
	houses0.push_back(8);
	houses0.push_back(9);

	vector<int> heaters0;
	heaters0.push_back(1);
	heaters0.push_back(4);
	heaters0.push_back(6);

	cout << s.findRadius(houses0, heaters0) << endl;

	vector<int> houses1;
	houses1.push_back(1);
	houses1.push_back(2);
	houses1.push_back(3);
	houses1.push_back(4);
	houses1.push_back(5);

	vector<int> heaters1;
	heaters1.push_back(1);
	heaters1.push_back(5);

	cout << s.findRadius(houses1, heaters1) << endl;

	vector<int> houses2;
	houses2.push_back(1);
	houses2.push_back(5);

	vector<int> heaters2;
	heaters2.push_back(2);

	cout << s.findRadius(houses2, heaters2) << endl;

	vector<int> houses3;
	houses3.push_back(11);
	houses3.push_back(15);

	vector<int> heaters3;
	heaters3.push_back(12);
	cout << s.findRadius(houses3, heaters3) << endl;

	vector<int> houses4;
	houses4.push_back(1);
	houses4.push_back(2);
	houses4.push_back(3);
	houses4.push_back(4);

	vector<int> heaters4;
	heaters4.push_back(1);
	heaters4.push_back(4);
	cout << s.findRadius(houses4, heaters4) << endl;

	return 0;
}