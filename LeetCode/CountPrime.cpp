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

//����С�ڷǸ�����n����������
int countPrimes(int n) 
{
	//prime[i]Ϊtrue��ʾi+1Ϊ����
	bool *prime = new bool[n-1];

	for (int i = 0; i < n-1; i++)
		prime[i] = true;

	prime[0] = false;//1��Ϊ����

	int squareRoot = sqrt(n);

	for (int i = 1; i <= squareRoot ; i++)
	{
		//��iΪ��������i�ı����϶���Ϊ����
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