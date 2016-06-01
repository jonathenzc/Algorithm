#include <iostream>
#include <vector>

using namespace std;

bool sudokuHelper(vector<vector<char>>& board,int rowmap[9],int colmap[9],int blockmap[9],int i_val,int j_val)
{
	if (i_val == 9)
		return true;
	
	if (j_val == 9) //列到头了
		return sudokuHelper(board,rowmap,colmap,blockmap,i_val+1,0);

	if (board[i_val][j_val] != '.')
	{
		return sudokuHelper(board, rowmap, colmap, blockmap, i_val, j_val+1);
	}
	else
	{
		for (int i = 1; i <= 9; i++)
		{
			int binaryBit = 1 << i;
			if ((rowmap[i_val] & binaryBit) == 0 && (colmap[j_val] & binaryBit) == 0 &&
				(blockmap[i_val / 3 * 3 + j_val / 3] & binaryBit) == 0)
			{
				board[i_val][j_val] = i + '0';
				rowmap[i_val] |= binaryBit;
				colmap[j_val] |= binaryBit;
				blockmap[i_val / 3 * 3 + j_val / 3] |= binaryBit;

				if (!sudokuHelper(board, rowmap, colmap, blockmap, i_val , j_val + 1))
				{
					board[i_val][j_val] = '.';
					rowmap[i_val] -= binaryBit;
					colmap[j_val] -= binaryBit;
					blockmap[i_val / 3 * 3 + j_val / 3] -= binaryBit;
				}
				else
					return true;
			}
		}
	}

	return false;
}

void solveSudoku(vector<vector<char>>& board) {
	int rowmap[9];
	int colmap[9];
	int blockmap[9];

	//初始化3个映射的map
	for (int i = 0; i < 9; i++)
	{
		rowmap[i] = 0;
		colmap[i] = 0;
		blockmap[i] = 0;
	}

	//遍历整个数独
	for (int i = 0; i < board.size(); i++)
	{
		for (int j = 0; j < board[i].size(); j++)
		{
			if (board[i][j] != '.')
			{
				int num = board[i][j] - '0';
				int binaryBit = 1 << num;

				rowmap[i] |= binaryBit;
				colmap[j] |= binaryBit;
				blockmap[i / 3 * 3 + j / 3] |= binaryBit;
			}
		}
	}

	sudokuHelper(board,rowmap,colmap,blockmap,0,0);
}

int main()
{
	vector<vector<char>> board;

	vector<char> v1;
	v1.push_back('5');
	v1.push_back('3');
	v1.push_back('.');
	v1.push_back('.');
	v1.push_back('7');
	v1.push_back('.');
	v1.push_back('.');
	v1.push_back('.');
	v1.push_back('.');

	board.push_back(v1);

	vector<char> v2;
	v2.push_back('6');
	v2.push_back('.');
	v2.push_back('.');
	v2.push_back('1');
	v2.push_back('9');
	v2.push_back('5');
	v2.push_back('.');
	v2.push_back('.');
	v2.push_back('.');

	board.push_back(v2);

	vector<char> v3;
	v3.push_back('.');
	v3.push_back('9');
	v3.push_back('8');
	v3.push_back('.');
	v3.push_back('.');
	v3.push_back('.');
	v3.push_back('.');
	v3.push_back('6');
	v3.push_back('.');

	board.push_back(v3);

	vector<char> v4;
	v4.push_back('8');
	v4.push_back('.');
	v4.push_back('.');
	v4.push_back('.');
	v4.push_back('6');
	v4.push_back('.');
	v4.push_back('.');
	v4.push_back('.');
	v4.push_back('3');

	board.push_back(v4);

	vector<char> v5;
	v5.push_back('4');
	v5.push_back('.');
	v5.push_back('.');
	v5.push_back('8');
	v5.push_back('.');
	v5.push_back('3');
	v5.push_back('.');
	v5.push_back('.');
	v5.push_back('1');

	board.push_back(v5);

	vector<char> v6;
	v6.push_back('7');
	v6.push_back('.');
	v6.push_back('.');
	v6.push_back('.');
	v6.push_back('2');
	v6.push_back('.');
	v6.push_back('.');
	v6.push_back('.');
	v6.push_back('6');

	board.push_back(v6);

	vector<char> v7;
	v7.push_back('.');
	v7.push_back('6');
	v7.push_back('.');
	v7.push_back('.');
	v7.push_back('.');
	v7.push_back('.');
	v7.push_back('2');
	v7.push_back('8');
	v7.push_back('.');

	board.push_back(v7);


	vector<char> v8;
	v8.push_back('.');
	v8.push_back('.');
	v8.push_back('.');
	v8.push_back('4');
	v8.push_back('1');
	v8.push_back('9');
	v8.push_back('.');
	v8.push_back('.');
	v8.push_back('5');

	board.push_back(v8);

	vector<char> v9;
	v9.push_back('.');
	v9.push_back('.');
	v9.push_back('.');
	v9.push_back('.');
	v9.push_back('8');
	v9.push_back('.');
	v9.push_back('.');
	v9.push_back('7');
	v9.push_back('9');

	board.push_back(v9);

	solveSudoku(board);

	for (int i = 0; i < board.size(); i++)
	{
		for (int j = 0; j < board[i].size(); j++)
		{
			cout << board[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}
