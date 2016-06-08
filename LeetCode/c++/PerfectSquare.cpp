#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

int numSquares(int n) {
	if (n <= 3)
		return n;

	if (n == 4)
		return 1;

	int squareSize = sqrt(n);
	int *squareCnt = new int[n +1];
	squareCnt[0] = 0;
	squareCnt[1] = 1;
	squareCnt[2] = 2;
	squareCnt[3] = 3;
	squareCnt[4] = 1;

	//储存完美平方数
	int *perfectSquare = new int[squareSize +1];
	for (int i = 1; i <= squareSize; i++)
	{
		int square = i*i;
		perfectSquare[i] = square;
		squareCnt[square] = 1;
	}

	perfectSquare[0] = 0;

	for (int i = 5; i <= n; i++)
	{
		int min = INT_MAX;

		int square_i_Size = sqrt(i);

		for (int j = 1; j <= square_i_Size; j++)
		{
			int candidate = squareCnt[i - perfectSquare[j]] + squareCnt[perfectSquare[j]];
			if (min > candidate)
				min = candidate;
		}

		squareCnt[i] = min;
	}

	return squareCnt[n];
}

void testPrint(int n)
{
	for (int i = 1; i < n; i++)
		cout << numSquares(i)<<" ";
}

int main()
{
	testPrint(20);

	//cout << numSquares(9) << " ";

	return 0;
}
