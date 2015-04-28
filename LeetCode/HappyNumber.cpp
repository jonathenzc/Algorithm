#include <iostream>

using namespace std;

//获取正整数n的各个数位，存进digitArray中
int squareSum(int n)
{
	int sum = 0;
	int digit;

	while (n != 0)
	{
		digit = n % 10;
		sum += digit*digit;
		n = n / 10;
	}
	
	return sum;
}

bool isHappy(int n)
{
	if (n == 1)
		return true;
	else
	{
		//循环判断该数是否为happy number
		int sum = squareSum(n);;
		int fastSum = squareSum(squareSum(n));

		while (sum != 1 && fastSum != 1 && sum != fastSum)
		{
			sum = squareSum(sum);
			fastSum = squareSum(squareSum(fastSum));//fastSum比sum跑得快
		}

		if (sum == 1 || fastSum == 1)
			return true;
		else
			return false;
	}
}

int main()
{
	if (isHappy(2))
		cout << "Happy\n";
	else
		cout << "Unhappy\n";

	return 0;
}