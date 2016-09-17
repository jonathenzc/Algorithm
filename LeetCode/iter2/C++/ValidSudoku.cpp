//#include <iostream>
//#include <string>
//#include <algorithm>
//#include <vector>
//#include <sstream>
//#include <unordered_map>
//
//using namespace std;
//
//string int2Binary(int num)
//{
//	if (num <= 1)
//		return to_string(num);
//
//	string s = "";
//
//	while (num != 0) {
//		s = char(num%2+'0') + s;
//
//		num /= 2;
//	}
//
//	if (s.size() < 8) {
//		for (int i = 0; i < 8 - s.size(); i++)
//			s = "0" + s;
//	}
//
//	return s;
//}
//
//bool validUtf8(vector<int>& data) {
//	
//	string bitStr = int2Binary(data[0]);
//	int byteCnt = 0;
//
//	if (bitStr[0] == 0)
//	{
//		if (data.size() == 1)
//			return true;
//		else
//			return false;
//	}
//	else
//	{
//		for (int i = 0; i < bitStr.size(); i++)
//		{
//			if (bitStr[i] == '1')
//				byteCnt++;
//			else
//				break;
//		}
//
//		if (byteCnt == 1)
//			return false;
//	}
//
//	if (data.size() < byteCnt)
//		return false;
//
//	for (int i = 1; i < byteCnt; i++)
//	{
//		string newBitStr = int2Binary(data[i]);
//		int newByteCnt = 0;
//
//		if (!(newBitStr[0] == '1' && newBitStr[1] == '0'))
//			return false;
//	}
//
//	return true;
//}
//
//int main()
//{
//	//cout << longestSubstring("aaabb",3)<<endl;
//	//cout << longestSubstring("ababbc", 2) << endl;
//
//	vector<int> v;
//	v.push_back(197); 
//	v.push_back(130); 
//	v.push_back(1);
//
//	if (validUtf8(v))
//		cout << "Yes\n";
//	else
//		cout << "No\n";
//
//	vector<int> v1;
//	v1.push_back(235); 
//	v1.push_back(140); 
//	v1.push_back(4);
//
//	if (validUtf8(v1))
//		cout << "Yes\n";
//	else
//		cout << "No\n";
//
//	vector<int> v2;
//	v2.push_back(240);
//	v2.push_back(162);
//	v2.push_back(138);
//	v2.push_back(147);
//	v2.push_back(17);
//
//	if (validUtf8(v2))
//		cout << "Yes\n";
//	else
//		cout << "No\n";
//
//	return 0;
//}

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <sstream>
#include <unordered_map>

using namespace std;

class Solution {
public:
	bool isValidSudoku(vector<vector<char>>& board) {
		if (board.size() < 9)
			return false;

		rowUsed = new int[9];
		colUsed = new int[9];
		gridUsed = new int[9];

		for (int i = 0; i < 9; i++)
		{
			rowUsed[i] = 0;
			colUsed[i] = 0;
			gridUsed[i] = 0;
		}

		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				if (board[i][j] != '.') {
					int binaryDigit = 1 << (board[i][j] - '0');

					if ((rowUsed[i] & binaryDigit) != 0) //注意按位与的优先级
						return false;

					if ((colUsed[j] & binaryDigit) != 0)
						return false;

					if ((gridUsed[3 * (i / 3) + j / 3] & binaryDigit) != 0)
						return false;

					rowUsed[i] |= binaryDigit;
					colUsed[j] |= binaryDigit;
					gridUsed[3 * (i / 3) + j / 3] |= binaryDigit;
				}
			}
		}

		return true;
	}

private:
	int *rowUsed;
	int *colUsed;
	int *gridUsed;
};

int main()
{
	vector<vector<char>> board;

	vector<char> v1;
	v1.push_back('5');
	v1.push_back('5');
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
	v9.push_back('8');

	board.push_back(v9);

	Solution s;
	if (s.isValidSudoku(board))
		cout << "Yes\n";
	else
		cout << "No\n";

	return 0;
}