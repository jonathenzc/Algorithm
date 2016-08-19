#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int countNumbersWithUniqueDigits(int n) {
	if (n == 0)
		return 1;
	if (n == 1)
		return 10;
	
	int sum = 10;
	
	for (int i = 2; i <= n; i++)
	{
		int j = 1;
		int cnt = 9;
		while(j<i)
		{
			cnt *= (10-j);
			j++;
		}

		sum += cnt;
	}

	return sum;
}


int main()
{
	for (int i = 0; i <= 12; i++)
		cout << countNumbersWithUniqueDigits(i) << endl;
	

	return 0;
}