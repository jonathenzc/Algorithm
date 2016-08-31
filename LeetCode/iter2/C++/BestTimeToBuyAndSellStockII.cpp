#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

int maxProfit(vector<int>& prices) {
	if (prices.size() <= 1)
		return 0;

	int sum = 0;

	int lowerBound = prices[0];

	for (int i = 1; i < prices.size();i++)
	{
		if (prices[i] > lowerBound)
			sum += prices[i] - lowerBound;
		
		lowerBound = prices[i];
	}

	return sum;
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