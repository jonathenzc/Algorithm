#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(string s) 
{
	if (s.size() == 0 || s.size() == 1)
		return true;
	else
	{
		//�Ƚ�ԭ�ַ����Ŀո�����������ĸ�������ַ�ȥ����������д��ĸת��ΪСд��ĸ
		string newS = "";
		for (int i = 0; i < s.size(); i++)
		{
			if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9'))
				newS += s[i];
			else if (s[i] >= 'A' && s[i] <= 'Z')
				newS += s[i]+32;
		}
		
		//��Ԥ���������ַ������˷ֱ�����ָ�����Ƚ��Ƿ�Ϊ����
		//cout << newS << endl;

		int head = 0,tail = newS.size()-1;
		bool result = true;

		while (head <= tail)
		{
			if (newS[head] != newS[tail])
			{
				result = false;
				break;
			}

			head++;
			tail--;
		}

		return result;
	}
}

//第二种方法
bool isValidSudoku(vector<vector<char>>& board) {
	//先判断board的长度是否为9，不为9就返回false
	if (board.size() != 9)
		return false;

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

				//用3个大小为9的数组来表示行、列、9宫格是否符合数独的规律
				//用9位的二进制数来表示出现过的数，相遇如果不为0，表示之前出现过该数
				if ((rowmap[i] & binaryBit) != 0 || (colmap[j] & binaryBit) != 0 ||
					(blockmap[i / 3 * 3 + j / 3] & binaryBit) != 0)
					return false;

				rowmap[i] |= binaryBit;
				colmap[j] |= binaryBit;
				blockmap[i / 3 * 3 + j / 3] |= binaryBit;
			}
		}
	}

	return true;
}

int main()
{
	if (isPalindrome("1a2"))
		cout << "True";
	else
		cout << "False";

	return 0;
}