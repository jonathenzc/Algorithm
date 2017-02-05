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

		prices.push_back(INT_MIN);
		int profitSum = 0;
		int lowerPrice = prices[0];
		int highCandidate = prices[0];
		for (int i = 1; i<prices.size(); i++)
		{
			if (highCandidate <= prices[i])
				highCandidate = prices[i];
			else
			{
				profitSum += (highCandidate-lowerPrice);
				lowerPrice = prices[i];
				highCandidate = prices[i];
			}
		}

		return profitSum;
	}
};


int main(void)
{
	vector<int> prices;
	prices.push_back(1);
	prices.push_back(4);
	prices.push_back(2);
	prices.push_back(6);
	prices.push_back(5);
	prices.push_back(8);
	prices.push_back(9);

	Solution s;
	cout << s.maxProfit(prices) << endl;

	return 0;
}