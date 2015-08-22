#include <iostream>
#include <vector>

using namespace std;

int maxProfit(vector<int>& prices) {
	if (prices.size() <= 0)
		return 0;

	int *profit = new int[prices.size()]; //profit[i]表示从第1天到第i天的股票收益
	profit[0] = 0;
	int lowestPrice = prices[0]; //最低价
	for (int i = 1; i < prices.size(); i++)
	{
		//更新最低价
		if (lowestPrice > prices[i])
			lowestPrice = prices[i];

		int todayProfit = prices[i] - lowestPrice;
		if (todayProfit < 0)
			profit[i] = profit[i - 1];
		else
			profit[i] = (profit[i - 1]>todayProfit) ? profit[i - 1] : todayProfit;
	}

	return profit[prices.size() - 1];
}


int main()
{
	vector<int> v;

	//max profit:8
	for (int i = 1; i < 10; i++)
		v.push_back(i);

	cout << maxProfit(v)<<endl;

	//max profit:1
	v.clear();
	v.push_back(2);
	v.push_back(1);
	v.push_back(2);
	v.push_back(0);
	v.push_back(1);

	cout << maxProfit(v) << endl;

	//max profit:1
	v.clear();
	v.push_back(2);
	v.push_back(1);
	v.push_back(2);
	v.push_back(1);
	v.push_back(0);

	cout << maxProfit(v) << endl;

	//max profit:3
	v.clear();
	v.push_back(2);
	v.push_back(1);
	v.push_back(2);
	v.push_back(4);
	v.push_back(3);

	cout << maxProfit(v) << endl;

	//max profit:4
	v.clear();
	v.push_back(2);
	v.push_back(1);
	v.push_back(2);
	v.push_back(4);
	v.push_back(3);
	v.push_back(0);
	v.push_back(4);
	v.push_back(3);

	cout << maxProfit(v) << endl;

	//max profit:3
	v.clear();
	v.push_back(2);
	v.push_back(1);
	v.push_back(2);
	v.push_back(4);
	v.push_back(3);
	v.push_back(0);
	v.push_back(2);
	v.push_back(-1);

	cout << maxProfit(v) << endl;

	//max profit:6
	v.clear();
	v.push_back(6);
	v.push_back(1);
	v.push_back(3);
	v.push_back(2);
	v.push_back(4);
	v.push_back(7);
	v.push_back(2);
	v.push_back(-1);

	cout << maxProfit(v) << endl;

	return 0;
}