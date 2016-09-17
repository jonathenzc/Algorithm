#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <sstream>
#include <unordered_map>

using namespace std;

class Solution {
public:

	bool helper(vector<vector<char>> &v,int row,int col) {

		if (row == 9)
			return true;

		if (col == 9)
			return helper(v,row+1,0);

		if (v[row][col] != '.')
			return helper(v,row,col+1);
		else
		{

			for (int i = 1; i <= 9; i++) {
				if (!rowUsed[row][i - 1] && !colUsed[col][i - 1] && !gridUsed[3 * (row / 3) + col / 3][i - 1]) {

					v[row][col] = i + '0';
					rowUsed[row][i - 1] = true;
					colUsed[col][i - 1] = true;
					gridUsed[3 * (row / 3) + col / 3][i - 1] = true;

					if (!helper(v, row, col + 1))
					{
						v[row][col] = '.';
						rowUsed[row][i - 1] = false;
						colUsed[col][i - 1] = false;
						gridUsed[3 * (row / 3) + col / 3][i - 1] = false;
					}
					else
						return true;
				}
			}
		}

		return false;
	}

	void solveSudoku(vector<vector<char>>& board) {
		rowUsed = new bool*[9];
		colUsed = new bool*[9];
		gridUsed = new bool*[9];

		for (int i = 0; i < 9; i++)
		{
			rowUsed[i] = new bool[9];
			for (int j = 0; j < 9; j++)
				rowUsed[i][j] = false;

			colUsed[i] = new bool[9];
			for (int j = 0; j < 9; j++)
				colUsed[i][j] = false;

			gridUsed[i] = new bool[9];
			for (int j = 0; j < 9; j++)
				gridUsed[i][j] = false;
		}

		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				if (board[i][j] != '.') {
					rowUsed[i][board[i][j]-'1'] = true;
					colUsed[j][board[i][j] - '1'] = true;
					gridUsed[3*(i/3)+j/3][board[i][j] - '1'] = true;
				}
			}
		}

		helper(board, 0, 0);
	}
private:
	bool **rowUsed;
	bool **colUsed;
	bool **gridUsed;
};

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

	Solution s;
	s.solveSudoku(board);

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