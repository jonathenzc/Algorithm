#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

int getNumCnt(int A, int scale) 
{
	int sum = 0;

	while (A != 0) {
		sum += A%scale;

		A /= scale;
	}

	return sum;
}

int gcd(int a, int b)
{
	if (a < b) 
	{
		int tmp = b;
		b = a;
		a = tmp;
	}

	while (b != 0) {
		int tmp = a%b;
		a = b;
		b = tmp;
	}

	return a;
}

int main()
{
	int A;

	while (cin >> A)
	{
		if (A == 1)
			cout << "1/1\n";
		else if (A == 2)
			cout << "1/1\n";
		else
		{
			int M = A - 2;
			int sum = 0;

			for (int i = 2; i <= A - 1; i++) {
				sum += getNumCnt(A,i);
			}

			int gcdNum = gcd(sum,M);
			int simpleSum = sum / gcdNum;
			int simpleM = M / gcdNum;

			cout << simpleSum << "/" << simpleM << endl;
		}
	}

	return 0;
}
