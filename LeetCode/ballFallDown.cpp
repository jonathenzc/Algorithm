#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <queue>
#include <stack>

using namespace std;

class Solution {
public:
	void ballFallDown(vector<string>& board) {
		if (board.size() < 1) return;

		//每列自由落体
		for (int j = 0; j < board[0].size(); j++) {
			//自底向上找
			int lastBarIndex = -1;
			for (int i = board.size() - 1; i >= 0; i--) {
				if (board[i][j] == 'x') {
					lastBarIndex = i;
				}
				else if (board[i][j] == 'o') {
					if (lastBarIndex == -1) {
						board[i][j] = '.';
					} else {
						if (lastBarIndex > 0) {
							board[i][j] = '.';
							board[lastBarIndex-1][j] = 'o';
							lastBarIndex = lastBarIndex - 1;
						}
					}
				}
			}
		}
	}
};

void printV(vector<string> board) {
	for (string s : board) {
		cout << s << endl;
	}
	cout << endl;
}

void test(vector<string> board) {
	cout << "before\n";
	printV(board);

	Solution s;
	s.ballFallDown(board);

	cout << "after\n";
	printV(board);
}

int main(void)
{
	vector<string> board1;
	board1.push_back(".oxo");
	board1.push_back("o..o");
	board1.push_back(".xox");

	test(board1);

	vector<string> board2;
	board2.push_back(".oxo");
	board2.push_back("o..o");
	board2.push_back("....");
	board2.push_back("...o");
	board2.push_back("o...");
	board2.push_back(".xox");

	test(board2);

	vector<string> board3;
	board3.push_back(".oxo");
	board3.push_back("o..o");
	board3.push_back("o...");
	board3.push_back("x..o");
	board3.push_back("o...");
	board3.push_back(".xox");

	test(board3);


	return 0;
}