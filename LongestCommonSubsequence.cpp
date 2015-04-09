//最长公共子序列
//是指两个字符串的最长相同的子串，可以相同也可以不同
#include <iostream>
#include <string>

using namespace std;

int diff(int a, int b)
{
	if (a > b)
		return a;
	else
		return b;
}

//使用动态规划来求解，设lcs[i][j]表示a[1...i]与b[1...j]的最长公共子串
void LongestCommonSubsequence(string a, string b)
{
	int **lcs = new int*[a.size()+1];
	for (int i = 0; i <= a.size(); i++)
		lcs[i] = new int[b.size()+1];

	for (int i = 0; i <= a.size(); i++)
		for (int j = 0; j <= b.size(); j++)
			lcs[i][j] = 0;

	int iIndex = -1;
	int jIndex = -1;
	int maxLength = 0;

	//最优子结构：
	//if a[i] != b[i], then lcs[i][j] = max(lcs[i-1][j],lcs[i][j-1]) ;
	//if a[i] == b[i], then lcs[i][j] = lcs[i-1][j-1]+1
	for (int i = 1; i <= a.size(); i++)
	{
		for (int j = 1; j <= b.size(); j++)
		{
			if (a[i-1] == b[j-1])
				lcs[i][j] = lcs[i - 1][j - 1] + 1;
			else
				lcs[i][j] = diff(lcs[i - 1][j],lcs[i][j - 1]);
		}
	}

	//输出这个二维矩阵
	for (int i = 0; i <= a.size(); i++)
	{
		for (int j = 0; j <= b.size(); j++)
			cout << lcs[i][j] << " ";

		cout << endl;
	}
}

int main()
{
	string a = "ABCBDAB";//bab  
	string b = "BDCABA";//caba

	LongestCommonSubsequence(a, b);

	return 0;
}