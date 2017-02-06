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
	string intToRoman(int num) {
		string ret = "";

	}
};


int main(void)
{
	//vector<int> prices;
	//prices.push_back(1);
	//prices.push_back(4);
	//prices.push_back(2);
	//prices.push_back(6);
	//prices.push_back(5);
	//prices.push_back(8);
	//prices.push_back(9);

	//vector<int> prices;
	//prices.push_back(7);
	//prices.push_back(1);
	//prices.push_back(5);
	//prices.push_back(3);
	//prices.push_back(6);
	//prices.push_back(4);

	vector<int> prices;
	prices.push_back(7);
	prices.push_back(6);
	prices.push_back(5);
	prices.push_back(4);
	prices.push_back(3);
	prices.push_back(2);

	Solution s;
	cout << s.maxProfit(prices) << endl;

	return 0;
}