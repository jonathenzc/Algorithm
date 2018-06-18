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
	int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
		int tank = 0, totalDiff = 0, source = 0;
		for (int i = 0; i < gas.size(); i++) {
			tank += gas[i] - cost[i];
			if (tank < 0) {
				source = i + 1;
				totalDiff += tank;
				tank = 0;
			}
		}

		if (totalDiff + tank < 0) //先前花费加上总tank仍小于0
			return -1;
		else
			return source;
	}
};

void printV(vector<int> gas, vector<int> cost) {
	Solution s;
	cout << s.canCompleteCircuit(gas, cost) << endl;
}

int main(void)
{
	vector<int> gas1;
	gas1.push_back(1);
	gas1.push_back(2);
	gas1.push_back(3);
	gas1.push_back(4);
	gas1.push_back(5);

	vector<int> cost1;
	cost1.push_back(3);
	cost1.push_back(4);
	cost1.push_back(5);
	cost1.push_back(1);
	cost1.push_back(2);

	printV(gas1, cost1);

	vector<int> gas2;
	gas2.push_back(2);
	gas2.push_back(3);
	gas2.push_back(4);

	vector<int> cost2;
	cost2.push_back(3);
	cost2.push_back(4);
	cost2.push_back(3);

	printV(gas2, cost2);


	return 0;
}