#include <iostream>
#include <vector>
#include <string>

using namespace std;


void helper(int row, int col, int wordIndex, string word, vector<vector<bool>> &isUsed, vector<vector<char>>& board, bool &isFound)
{
	if (wordIndex < word.size())
	{
		//最后一个元素
		if (wordIndex == word.size()-1 && word[wordIndex] == board[row][col])
		{
			isFound = true;
			return;
		}
		else
		{
			//left
			if (!isFound && col > 0)
			{
				if (!isUsed[row][col - 1] && board[row][col - 1] == word[wordIndex + 1])
				{
					isUsed[row][col - 1] = true;
					helper(row, col - 1, wordIndex + 1, word, isUsed, board, isFound);
					isUsed[row][col - 1] = false;
				}
			}

			//right
			if (!isFound && col < board[0].size() - 1)
			{
				if (!isUsed[row][col + 1] && board[row][col + 1] == word[wordIndex + 1])
				{
					isUsed[row][col + 1] = true;
					helper(row, col + 1, wordIndex + 1, word, isUsed,board,isFound);
					isUsed[row][col + 1] = false;
				}
			}
			//up
			if (!isFound && row > 0)
			{
				if (!isUsed[row - 1][col] && board[row - 1][col] == word[wordIndex + 1])
				{
					isUsed[row - 1][col] = true;
					helper(row - 1, col, wordIndex + 1, word, isUsed, board, isFound);
					isUsed[row - 1][col] = false;
				}
			}
			//down
			if (!isFound &&  row < board.size() - 1)
			{
				if (!isUsed[row + 1][col] && board[row + 1][col] == word[wordIndex + 1])
				{
					isUsed[row + 1][col] = true;
					helper(row + 1, col, wordIndex + 1, word, isUsed, board, isFound);
					isUsed[row + 1][col] = false;
				}
			}
		}
	}
}

bool exist(vector<vector<char>>& board, string word) {
	bool isFound = false;

	if (board.size() == 0)
		return false;

	vector<vector<bool>> isUsed(board.size(), vector<bool>(board[0].size(), false));

	for (int i = 0; i < board.size(); i++)
	{
		for (int j = 0; j < board[i].size(); j++)
		{
			if (board[i][j] == word[0])
			{
				isUsed[i][j] = true;
				helper(i, j, 0, word, isUsed, board, isFound);
				isUsed[i][j] = false;

				if (isFound)
					return isFound;
			}
		}
	}

	return isFound;
}

void testPrint(vector<vector<char>>& board, string word)
{
	if (exist(board, word))
		cout << "Exist\n";
	else
		cout << "Not Exist\n";
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

	testPrint(v, "ABCCED");
	testPrint(v, "SEE");
	testPrint(v, "ABCB");

	return 0;
}