#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>

using namespace std;

int lastRemaining(int n) {
	if (n == 1)
		return 1;

	int start = 1, end = n,diff=2;
	int numCnt = n;
	bool flag = true;

	while (numCnt != 1)
	{
		if (flag) //正向
		{ 
			flag = false;
			start = start + diff / 2;
			end = start + diff*(numCnt/2-1);
		}
		else //方向
		{
			flag = true;
			end = end - diff/2;
			start = end - diff*(numCnt / 2 - 1);
		}

		numCnt /= 2;
		diff *= 2;
	}

	return start;
}

int main()
{
	cout << lastRemaining(16) << endl;
	cout << lastRemaining(1) << endl;
	cout << lastRemaining(2) << endl;
	cout << lastRemaining(9) << endl;
}