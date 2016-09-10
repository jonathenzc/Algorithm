#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <sstream>
#include <unordered_map>

using namespace std;

class Solution {
public:
	vector<vector<string>> solveNQueens(int n) {
		string s = "";
		for (int i = 0; i < n; i++)
			s += ".";

		vector<string> board(n,s);

		for (int i = 0; i < n; i++)
		{
			board[0][i] = 'Q';
			helper(1,board,n);
			board[0][i] = '.';
		}

		return v;
	}
private:
	vector<vector<string>> v;

	void helper(int row, vector<string> board, int n) {
		if (row == n)
			v.push_back(board);
		else
		{
			for (int col = 0; col < n; col++)//遍历列
			{
				if (isValid(row, col, board)) {
					board[row][col] = 'Q';
					helper(row + 1, board, n);
					board[row][col] = '.';
				}
			}

		}
	}

	bool isValid(int row,int col, vector<string> board) {
		//遍历列
		for (int i = 0; i < row; i++)
		{
			if (board[i][col] == 'Q')
				return false;
		}

		//遍历斜行
		int row_i = row - 1, diff = 1;
		while (row_i >= 0) {
			if (col - diff >= 0 && board[row_i][col - diff] == 'Q')
				return false;
			
			if (col + diff < board.size() && board[row_i][col + diff] == 'Q')
				return false;

			row_i--;
			diff++;
		}

		return true;
	}
};

int main()
{
	Solution s;
	string str = "aab";
	vector<vector<string>> v = s.solveNQueens(8);

	cout << v.size() << endl;

	for (auto tmpV : v) {
		for (auto tmpS : tmpV)
			cout << tmpS << endl;

		cout << endl;
	}

	return 0;
}