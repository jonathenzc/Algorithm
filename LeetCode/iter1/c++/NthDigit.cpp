#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int tenDigit(int num)
{
	int sum = 1;
	int i = 0;
	while (i < num)
	{
		sum *= 10;
		i++;
	}

	return sum;
}

int findNthDigit(int n) {
	if (n <= 9)
		return n;

	long long nL = n;
	long long base = 9;
	int power = 1;
	int digitCnt = 1;

	while (nL>base*digitCnt)
	{
		nL -= base*digitCnt;
		base *= 10;
		digitCnt++;
	}

	int step = (nL +digitCnt-1)%digitCnt;
	int num = (nL +digitCnt-1) / digitCnt + tenDigit(digitCnt - 1) - 1;

	string numStr;
	stringstream ss;
	ss << num;
	ss >> numStr;

	return (numStr[step]-'0');
}

int main()
{
	//for (int i = 1; i <= 30; i++)
	//	cout << findNthDigit(i) << " ";
	//cout << findNthDigit(10) << " ";
	//cout << findNthDigit(11) << " ";
	//cout << findNthDigit(189) << " ";
	//cout << findNthDigit(188) << " ";
	//cout << findNthDigit(183) << " ";

	cout << findNthDigit(190) << " ";
	cout << findNthDigit(191) << " ";
	cout << findNthDigit(192) << " ";
	cout << findNthDigit(1000) << " ";
	cout << findNthDigit(1000000000) << " ";
	cout << findNthDigit(INT_MAX) << " ";
	return 0;
}