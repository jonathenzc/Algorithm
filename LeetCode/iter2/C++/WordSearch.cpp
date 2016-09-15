#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <sstream>
#include <unordered_map>

using namespace std;

class Solution {
public:
	bool exist(vector<vector<char>>& board, string word) {
		isFound = false;

		for (int i = 0; i < board.size(); i++)
		{
			for (int j = 0; j < board[i].size(); j++)
			{
				if (!isFound && board[i][j] == word[0]) {
					board[i][j] = '.';
					helper(i, j, 1, board, word);
					board[i][j] = word[0];
				}
			}
		}

		return isFound;
	}


private:
	bool isFound;

	void helper(int row, int col, int index, vector<vector<char>> board, string word) {
		if (index >= word.size())
			isFound = true;
		else {
			//上
			if (!isFound && row > 0 && board[row - 1][col] == word[index])
			{
				board[row-1][col] = '.';
				helper(row-1, col, index+1, board, word);
				board[row-1][col] = word[index];
			}

			//左
			if (!isFound && col > 0 && board[row][col-1] == word[index])
			{
				board[row][col-1] = '.';
				helper(row, col-1, index + 1, board, word);
				board[row][col-1] = word[index];
			}

			//右
			if (!isFound && col < board[0].size()-1  && board[row][col+1] == word[index])
			{
				board[row][col + 1] = '.';
				helper(row, col + 1, index + 1, board, word);
				board[row][col + 1] = word[index];
			}

			//下
			if (!isFound && row < board.size()-1 && board[row + 1][col] == word[index])
			{
				board[row + 1][col] = '.';
				helper(row + 1, col, index + 1, board, word);
				board[row + 1][col] = word[index];
			}
		}
	}

};

void testPrint(vector<vector<char>> v,string word) {
	Solution s;
	
	if (s.exist(v, word))
		cout << "Yes\n";
	else
		cout << "No\n";
}

int main()
{
	vector<vector<char>> v;
	vector<char> v1;
	v1.push_back('A');
	v1.push_back('B');
	v1.push_back('C');
	v1.push_back('E');

	vector<char> v2;
	v2.push_back('S');
	v2.push_back('F');
	v2.push_back('C');
	v2.push_back('S');

	vector<char> v3;
	v3.push_back('A');
	v3.push_back('D');
	v3.push_back('E');
	v3.push_back('E');

	v.push_back(v1);
	v.push_back(v2);
	v.push_back(v3);

	testPrint(v,"ABCCED"); //Yes
	testPrint(v, "SEE"); //Yes
	testPrint(v, "ABCB"); //No

	return 0;
}