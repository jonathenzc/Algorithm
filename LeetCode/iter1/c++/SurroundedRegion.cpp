#include <iostream>
#include <vector>

using namespace std;

void helper(int i, int j, int row, int col, vector<vector<char>>& board)
{
	if (board[i][j] == 'O')
	{
		board[i][j] = '1';

		if (i > 1) //边缘不需要变1
			helper(i-1,j,row,col,board);

		if (j > 1) //边缘不需要变1
			helper(i, j-1, row, col, board);

		if (i < row-1) //边缘不需要变1
			helper(i+1, j, row, col, board);

		if (j < col-1) //边缘不需要变1
			helper(i, j + 1, row, col, board);
	}
}

void solve(vector<vector<char>>& board) {
	int row = board.size();
	if (row == 0)
		return;

	int col = board[0].size();

	//先由边拓展，变成1

	//左右两边
	for (int i = 0; i < row; i++)
	{
		helper(i,0,row,col,board);

		helper(i,col-1,row,col,board);
	}

	//上下两边
	for (int i = 0; i < col; i++)
	{
		helper(0, i, row, col, board);

		helper(row-1,i, row, col, board);
	}

	//如果board中仍有O，那么就应该被flip
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (board[i][j] == 'O')
				board[i][j] = 'X';
		}
	}

	//将1转成O
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (board[i][j] == '1')
				board[i][j] = 'O';
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
	//vector<char> v1;
	//v1.push_back('X');
	//v1.push_back('X');
	//v1.push_back('X');
	//v1.push_back('X');

	//vector<char> v2;
	//v2.push_back('X');
	//v2.push_back('O');
	//v2.push_back('O');
	//v2.push_back('X');

	//vector<char> v3;
	//v3.push_back('X');
	//v3.push_back('X');
	//v3.push_back('O');
	//v3.push_back('X');

	//vector<char> v4;
	//v4.push_back('X');
	//v4.push_back('O');
	//v4.push_back('X');
	//v4.push_back('X');

	//board.push_back(v1);
	//board.push_back(v2);
	//board.push_back(v3);
	//board.push_back(v4);


	vector<char> v1;
	v1.push_back('X');
	v1.push_back('X');
	v1.push_back('X');
	v1.push_back('X');
	v1.push_back('X');

	vector<char> v2;
	v2.push_back('X');
	v2.push_back('O');
	v2.push_back('O');
	v2.push_back('O');
	v2.push_back('X');

	vector<char> v3;
	v3.push_back('X');
	v3.push_back('X');
	v3.push_back('O');
	v3.push_back('O');
	v3.push_back('X');


	vector<char> v4;
	v4.push_back('X');
	v4.push_back('X');
	v4.push_back('X');
	v4.push_back('O');
	v4.push_back('X');

	vector<char> v5;
	v5.push_back('X');
	v5.push_back('O');
	v5.push_back('X');
	v5.push_back('X');
	v5.push_back('X');

	board.push_back(v1);
	board.push_back(v2);
	board.push_back(v3);
	board.push_back(v4);
	board.push_back(v5);



	cout << "Before Flipping\n";
	testPrint(board);

	cout << "After Flipping\n";
	solve(board);
	testPrint(board);


	return 0;
}