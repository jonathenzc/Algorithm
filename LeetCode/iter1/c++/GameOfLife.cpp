#include <iostream>
#include <vector>

using namespace std;

bool isLive(int n)
{
	if (n == 1 || n == 3)
		return true;
	else
		return false;
}

bool isDead(int n)
{
	if (n == 0 || n == 2)
		return true;
	else
		return false;
}

int getLiveCnt(vector<vector<int>>& board, int i, int j, int row, int col)
{
	int liveCnt = 0;
	//上三个
	if (i - 1 >= 0 && j - 1 >= 0 && isLive(board[i - 1][j - 1]))
		liveCnt++;

	if (i - 1 >= 0 && isLive(board[i - 1][j]))
		liveCnt++;

	if (i - 1 >= 0 && j + 1 < col && isLive(board[i - 1][j + 1]))
		liveCnt++;

	//左右两个
	if (j - 1 >= 0 && isLive(board[i][j - 1]))
		liveCnt++;

	if (j + 1 < col && isLive(board[i][j + 1]))
		liveCnt++;

	//下三个
	if (i + 1 < row && j - 1 >= 0 && isLive(board[i + 1][j - 1]))
		liveCnt++;

	if (i + 1 < row && isLive(board[i + 1][j]))
		liveCnt++;

	if (i + 1 < row && j + 1 < col && isLive(board[i + 1][j + 1]))
		liveCnt++;

	return liveCnt;
}

void check(vector<vector<int>>& board, int i, int j, int row, int col)
{
	int liveCnt = getLiveCnt(board, i, j, row, col);

	if (isDead(board[i][j])) //dead
	{
		if (liveCnt == 3)
			board[i][j] = 2;
	}
	else if (isLive(board[i][j])) //live
	{
		if (liveCnt < 2 || liveCnt > 3)
			board[i][j] = 3;
	}
}

void gameOfLife(vector<vector<int>>& board) {
	for (int i = 0; i < board.size(); i++)
	{
		for (int j = 0; j < board[i].size(); j++)
		{
			check(board, i, j, board.size(), board[i].size());
		}
	}

	for (int i = 0; i < board.size(); i++)
	{
		for (int j = 0; j < board[i].size(); j++)
		{
			if (board[i][j] == 2) //0->1
				board[i][j] = 1;
			else if (board[i][j] == 3) //1->0
				board[i][j] = 0;
		}
	}
}

void testPrint(vector<vector<char>>& board)
{
	for (auto row : board)
	{
		for (auto col : row)
			cout << col << " ";

		cout << endl;
	}

	cout << endl;
}

int main()
{
	vector<vector<char>> board;



	return 0;
}