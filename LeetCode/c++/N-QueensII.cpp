#include <iostream>

using namespace std;


bool isSafeHelper(int *chessBoard, int row, int col)
{
	bool result = false;

	for (int i = 0; i<col; i++)
	{
		if (chessBoard[i] == row)
			break;
		
		//对角
		if (row - chessBoard[i] == col - i)
			break;

		//斜对角
		if (row - chessBoard[i] == i - col)
			break;

		if (i == col - 1)
			result = true;
	}

	return result;
}

int isSafe(int *chessBoard, int col, int n)
{
	int cnt = 0;

	if (col == n)
	{
		cnt++;
	}
	else
	{
		for (int i = 0; i < n; i++)
		{
			if (isSafeHelper(chessBoard, i, col))
			{
				chessBoard[col] = i;
				cnt += isSafe(chessBoard, col + 1, n);
			}

		}
	}

	return cnt;
}

int totalNQueens(int n) {	
	int queenCnt = 0;

	//chessBoard[col] = row, 下标是列，数组的值是该列皇后所在的行
	int *chessBoard = new int[n];

	for (int i = 0; i<n; i++)
	{
		chessBoard[0] = i;

		queenCnt += isSafe(chessBoard, 1, n);
	}

	return queenCnt;
}int main()
{
	cout << totalNQueens(8);

	return 0;
}


