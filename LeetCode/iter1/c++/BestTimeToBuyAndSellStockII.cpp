#include <iostream>
#include <vector>

using namespace std;

int maxProfit(vector<int>& prices) {
	if (prices.size() <= 1)
		return 0;

	int max = 0;

	//������Ʊ�۸�Ѱ��������������
	for (int i = 1; i < prices.size(); i++)
	{
		if (prices[i] > prices[i - 1]) //ֻҪ����������
			max += prices[i] - prices[i - 1];
	}

	return max;
}

int main()
{
	vector<int> v;

	//max profit:8
	for (int i = 1; i < 10; i++)
		v.push_back(i);

	cout << maxProfit(v) << endl;

	//max profit:2
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

	//max profit:7
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

	//max profit:5
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

	//max profit:7
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