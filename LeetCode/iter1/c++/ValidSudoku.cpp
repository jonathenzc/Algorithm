#include <iostream>
#include <map>
#include <vector>

using namespace std;

//�жϾŹ����Ƿ����
bool isSquareValid(vector<vector<char>> board)
{
	//�Ź�������ĵ�
	for (int i = 1; i <= 7; i += 3)
	{
		for (int j = 1; j <= 7; j += 3)
		{
			//ÿ���Ź���һ��map
			map<char, int> squareMap;

			for (int m = i - 1; m <= i + 1; m++)
			{
				for (int n = j - 1; n <= j + 1; n++)
				{
					if (board[m][n] != '.')
					{
						if (squareMap.find(board[m][n]) != squareMap.end())
							return false;

						squareMap[board[m][n]] = 1;
					}
				}
			}
		}
	}

	return true;
}

//�жϺ����Ƿ����
bool isRowValid(vector<vector<char>> board)
{
	for (int i = 0; i < 9; i++)
	{
		//ÿ��һ��map
		map<char, int> m;

		for (int j = 0; j < 9; j++)
		{
			if (board[i][j] != '.')
			{
				if (m.find(board[i][j]) != m.end())
					return false;

				m[board[i][j]] = 1;
			}
		}
	}

	return true;
}

//�ж������Ƿ����
bool isColumnValid(vector<vector<char>> board)
{
	for (int i = 0; i < 9; i++)
	{
		//ÿ��һ��map
		map<char, int> m;

		for (int j = 0; j < 9; j++)
		{
			if (board[j][i] != '.')
			{
				if (m.find(board[j][i]) != m.end())
					return false;

				m[board[j][i]] = 1;
			}
		}
	}

	return true;
}

bool isValidSudoku(vector<vector<char>>& board) 
{
	//���ж�board�ĳ����Ƿ�Ϊ9����Ϊ9�ͷ���false
	if (board.size() != 9)
		return false;

	for (int i = 0; i < board.size(); i++)
	{
		if (board[i].size() != 9)
			return false;
	}

	//���ж�9��9����
	if (!isSquareValid(board))
		return false;

	//���жϺ���
	if (!isRowValid(board))
		return false;

	//���ж�����
	if (!isColumnValid(board))
		return false;
	else
		return true;
}

int main()
{
	vector<vector<char>> board;

	vector<char> v;
	v.push_back('.');
	v.push_back('.');
	v.push_back('5');
	v.push_back('.');
	v.push_back('.');
	v.push_back('.');
	v.push_back('.');
	v.push_back('.');
	v.push_back('6');

	board.push_back(v);

	vector<char> v2;
	v2.push_back('.');
	v2.push_back('.');
	v2.push_back('.');
	v2.push_back('.');
	v2.push_back('1');
	v2.push_back('4');
	v2.push_back('.');
	v2.push_back('.');
	v2.push_back('.');

	board.push_back(v2);

	vector<char> v9;
	v9.push_back('.');
	v9.push_back('.');
	v9.push_back('.');
	v9.push_back('.');
	v9.push_back('.');
	v9.push_back('.');
	v9.push_back('.');
	v9.push_back('.');
	v9.push_back('.');

	board.push_back(v9);

	vector<char> v3;
	v3.push_back('.');
	v3.push_back('.');
	v3.push_back('.');
	v3.push_back('.');
	v3.push_back('.');
	v3.push_back('9');
	v3.push_back('2');
	v3.push_back('.');
	v3.push_back('.');

	board.push_back(v3);

	vector<char> v4;
	v4.push_back('5');
	v4.push_back('.');
	v4.push_back('.');
	v4.push_back('.');
	v4.push_back('.');
	v4.push_back('2');
	v4.push_back('.');
	v4.push_back('.');
	v4.push_back('.');

	board.push_back(v4);

	vector<char> v5;
	v5.push_back('.');
	v5.push_back('.');
	v5.push_back('.');
	v5.push_back('.');
	v5.push_back('.');
	v5.push_back('.');
	v5.push_back('.');
	v5.push_back('3');
	v5.push_back('.');

	board.push_back(v5);


	vector<char> v6;
	v6.push_back('.');
	v6.push_back('.');
	v6.push_back('.');
	v6.push_back('5');
	v6.push_back('4');
	v6.push_back('.');
	v6.push_back('.');
	v6.push_back('.');
	v6.push_back('.');

	board.push_back(v6);

	vector<char> v7;
	v7.push_back('3');
	v7.push_back('.');
	v7.push_back('.');
	v7.push_back('.');
	v7.push_back('.');
	v7.push_back('.');
	v7.push_back('4');
	v7.push_back('2');
	v7.push_back('.');

	board.push_back(v7);

	vector<char> v8;
	v8.push_back('.');
	v8.push_back('.');
	v8.push_back('.');
	v8.push_back('2');
	v8.push_back('7');
	v8.push_back('.');
	v8.push_back('6');
	v8.push_back('.');
	v8.push_back('.');

	board.push_back(v8);

	if (isValidSudoku(board))
		cout << "Yes";
	else
		cout << "No";

	return 0;
}