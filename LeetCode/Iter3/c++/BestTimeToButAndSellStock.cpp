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
	int maxProfit(vector<int>& prices) {
		if (prices.size() < 2)
			return 0;

		int lowestPrice = prices[0];
		int profitCandidate = 0;

		for (int i = 1; i < prices.size(); i++)
		{
			profitCandidate = max(profitCandidate,prices[i]-lowestPrice);

			if (lowestPrice > prices[i])
				lowestPrice = prices[i];
		}

		return profitCandidate;
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