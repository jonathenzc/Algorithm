#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

//int maxProfit(int k, vector<int>& prices) {
//
//}

int maxProfit(vector<int>& prices) {
	if (prices.size() <= 1)
		return 0;

	int K = 2; //K次交易
	vector<vector<int>> local(prices.size(),vector<int>(K+1,0));
	vector<vector<int>> global(prices.size(),vector<int>(K+1,0));

	for (int i = 1; i < prices.size(); i++)
	{
		int diff = prices[i] - prices[i-1];
		for (int j = 1; j <= K; j++)
		{
			local[i][j] = max(global[i-1][j-1]+max(0,diff),local[i-1][j]+diff); 

			global[i][j] = max(global[i-1][j],local[i][j]);
		}
	}

	return global[prices.size()-1][K];
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

	return 0;
}