#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

int maxProfit(vector<int>& prices) {
	if (prices.size() == 0)
		return 0;

	int max = 0;

	int currentPrice = prices[0];
	int startIndex = 0;

	for (int i = 1; i < prices.size(); i++)
	{
		int diff = prices[i] - prices[startIndex];

		if (diff > max)
			max = diff;
		
		if (diff < 0)
			startIndex = i;
	}

	return max;
}


int main()
{
	vector<int> v;
	v.push_back(7);
	v.push_back(1);
	v.push_back(5);
	v.push_back(3);
	v.push_back(6);
	v.push_back(4);

	cout << maxProfit(v) << endl;

	vector<int> v1;
	v1.push_back(7);
	v1.push_back(6);
	v1.push_back(4);
	v1.push_back(3);
	v1.push_back(1);

	cout << maxProfit(v1) << endl;
}