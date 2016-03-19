#include <iostream>
#include <vector>
#include <string>

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

vector< vector<string> > isSafe(int *chessBoard, int col, int n)
{
	vector< vector<string> > v;

	if (col == n)
	{
		//构建n*n的空棋盘
		vector<string> oneCondition;

		for (int i = 0; i<n; i++)
		{
			string s = "";
			for (int j = 0; j<n; j++)
				s += ".";

			oneCondition.push_back(s);
		}

		//获取n皇后的row和col
		for (int i = 0; i<n; i++)
			oneCondition[chessBoard[i]][i] = 'Q';

		v.push_back(oneCondition);
	}
	else
	{
		for (int i = 0; i < n; i++)
		{
			if (isSafeHelper(chessBoard, i, col))
			{
				chessBoard[col] = i;

				vector< vector<string> > tmpV;

				tmpV = isSafe(chessBoard, col + 1, n);

				//将结果塞入tmpV中
				for (int j = 0; j<tmpV.size(); j++)
					v.push_back(tmpV[j]);
			}
		}
	}

	return v;
}

vector< vector<string> > solveNQueens(int n) {
	vector< vector<string> > v;

	//chessBoard[col] = row, 下标是列，数组的值是该列皇后所在的行
	int *chessBoard = new int[n];

	for (int i = 0; i<n; i++)
	{
		chessBoard[0] = i;

		vector< vector<string> > tmpV;
		tmpV = isSafe(chessBoard, 1, n);

		//将结果塞入tmpV中
		for (int j = 0; j<tmpV.size(); j++)
			v.push_back(tmpV[j]);
	}

	return v;
}

int main()
{
	vector< vector<string> > v = solveNQueens(8);
	cout << v.size()<<endl;

	for (int i = 0; i<8; i++)
		cout << v[0][i] << endl;

	return 0;
}