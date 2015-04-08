//最长公共子串
//是指两个字符串的最长连续相同的子串
#include <iostream>
#include <string>

using namespace std;

//使用动态规划来求解，设lcs[i][j]表示a[1...i]与b[1...j]的最长公共子串
void LongestCommonSubstring(string a, string b)
{
	int **lcs = new int*[a.size()];
	for (int i = 0; i < a.size(); i++)
		lcs[i] = new int[b.size()];

	for (int i = 0; i < a.size(); i++)
		for (int j = 0; j < b.size(); j++)
			lcs[i][j] = 0;

	int iIndex = -1;
	int jIndex = -1;
	int maxLength = 0;

	for (int i = 0; i < a.size(); i++)
	{
		for (int j = 0; j < b.size(); j++)
		{
			if (a[i] == b[j])
			{
				if (i == 0 || j == 0)
					lcs[i][j] = 1;
				else
					lcs[i][j] = lcs[i - 1][j - 1] + 1;
			}

			if (lcs[i][j] > maxLength)
			{
				maxLength = lcs[i][j];
				iIndex = i;
				jIndex = j;
			}
		}
	}

	//输出这个二维矩阵
	for (int i = 0; i < a.size(); i++)
	{
		for (int j = 0; j < b.size(); j++)
			cout << lcs[i][j] << " ";

		cout << endl;
	}

	cout << "Longest length: "<<maxLength<<endl;

	cout << "Longest common substring is ";

	for (int i = maxLength-1; i >=0; i--)
		cout << a[iIndex - i];//b[jIndex+i]也行
	
}

int main()
{
	string a = "21232523311324";//bab
	string b = "312123223445";//caba

	LongestCommonSubstring(a,b);

	return 0;
}