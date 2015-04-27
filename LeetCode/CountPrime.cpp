#include <iostream>
#include <math.h>

using namespace std;

//bool isPrime(int n)
//{
//	int squareRoot = sqrt(n);
//
//	for (int i = 2; i <= squareRoot; i++)
//	{
//		if (n%i == 0)
//			return false;
//
//		if (i == squareRoot)
//			return true;
//	}
//}

//计算小于非负整数n的所有质数
int countPrimes(int n) 
{
	//prime[i]为true表示i+1为质数
	bool *prime = new bool[n-1];

	for (int i = 0; i < n-1; i++)
		prime[i] = true;

	prime[0] = false;//1不为质数

	int squareRoot = sqrt(n);

	for (int i = 1; i <= squareRoot ; i++)
	{
		//若i为质数，则i的倍数肯定不为质数
		if (prime[i])
		{
			for (int j = 2*i+1 ; j < n-1; j += i+1)
				prime[j] = false;
		}
	}

	int primeCnt = 0;
	for (int i = 0; i < n-1; i++)
	{
		if (prime[i])
			primeCnt++;
	}

	return primeCnt;
}

int main()
{
	cout << countPrimes(1)<<endl;
	cout << countPrimes(2) << endl;
	cout << countPrimes(3) << endl;
	cout << countPrimes(4) << endl;
	cout << countPrimes(5) << endl;
	cout << countPrimes(20) << endl;
	cout << countPrimes(50) << endl;
	cout << countPrimes(100) << endl;

	return 0;
}