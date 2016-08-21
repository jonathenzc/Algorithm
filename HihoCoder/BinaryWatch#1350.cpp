#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int oneDigitCnt(int n)
{
	int cnt = 0;
	while (n != 0)
	{
		cnt += (n & 1);
		n = n >> 1;
	}

	return cnt;
}

void binaryWatch()
{
	//构建数与1个数的映射
	int oneCntMap[60];
	for (int i = 0; i < 60; i++)
		oneCntMap[i] = oneDigitCnt(i);

	int oneDigit;
	cin >> oneDigit;
	
	for (int i = 0; i < 24; i++)
	{
		for (int j = 0; j < 60; j++)
		{
			int hour = oneCntMap[i];
			int minute = oneCntMap[j];
			if (hour + minute == oneDigit)
			{
				if (i >= 0 && i <= 9)
					cout << "0";
				cout << i<<":";

				if (j >= 0 && j <= 9)
					cout << "0";
				cout << j << endl;
			}
		}
	}
}


int main()
{
	binaryWatch();

	return 0;
}