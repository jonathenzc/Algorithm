#include <iostream>
#include <vector>

using namespace std;

int countNumbersWithUniqueDigits(int n) {
	if (n <= 0)
		return 1;
	
	if (n == 1)
		return 10;

	int sum = 10 ,power = 9;
	for (int i = 2; i <= n;i++)
	{
		power *= (11-i);
		
		sum += power;
	}

	return sum;
}

int main()
{
	for (int i = -2; i <= 15; i++)
		cout << i<<" "<<countNumbersWithUniqueDigits(i) << endl;

	return 0;
}