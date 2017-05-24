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
	vector<int> constructRectangle(int area) {
		vector<int> v;

		int sqrt = sqrt_int(area);
		if (sqrt * sqrt == area)
		{
			v.push_back(sqrt);
			v.push_back(sqrt);
		}
		else
		{
			int W = sqrt;

			while (W < area && area % W != 0)
				W--;

			v.push_back(area/W);
			v.push_back(W);
		}

		return v;
	}
private:
	int sqrt_int(int num)
	{
		double sqrtD = num;
		double preSqrtD = sqrtD;

		//牛顿迭代法 Xn+1 = (Xn+num/Xn)/2
		do
		{
			preSqrtD = sqrtD;
			sqrtD = (sqrtD + num/sqrtD) / 2.0;
		} while (abs(sqrtD - preSqrtD) > 0.1);

		return (int)sqrtD;
	}

	double abs(double num)
	{
		if (num < 0)
			num = -num;

		return num;
	}
};

void testPrint(vector<int> v)
{
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << " ";
}

int main(void)
{
	Solution s;

	cout << "square 2\n";
	vector<int> v = s.constructRectangle(2);
	testPrint(v);

	cout << "\nsquare 4\n";
	v = s.constructRectangle(4);
	testPrint(v);

	cout << "\nsquare 6\n";
	v = s.constructRectangle(6);
	testPrint(v);

	cout << "\nsquare 10\n";
	v = s.constructRectangle(10);
	testPrint(v);

	return 0;
}