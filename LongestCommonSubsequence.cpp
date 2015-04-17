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

string commonString(int **path,string a,string b)
{
	string s = "";

	int i = a.size();
	int j = b.size();

	while (i >=0 && j >=0 && path[i][j] != 0 )
	{
		if (path[i][j] == 1)//斜上
		{
			s += a[i - 1];//b[j-1]也行
			i--;
			j--;
		}
		else if (path[i][j] == 2)//左边
			j--;
		else if (path[i][j] == 3)//上边
			i--;
	}

	//将获取的结果反转一下
	string reversedS = "";
	for (int index = s.size() - 1; index >= 0; index--)
		reversedS += s[index];

	return reversedS;
}

//使用动态规划来求解，设lcs[i][j]表示a[1...i]与b[1...j]的最长公共子串
void LongestCommonSubsequence(string a, string b)
{
	//最优子结构的二维数组
	int **lcs = new int*[a.size()+1];
	for (int i = 0; i <= a.size(); i++)
		lcs[i] = new int[b.size()+1];

	for (int i = 0; i <= a.size(); i++)
		for (int j = 0; j <= b.size(); j++)
			lcs[i][j] = 0;

	//记录最长子序列的更新是哪里来的：0表示初始状态，1表示斜上，2表示左边，3表示上边
	int **path = new int*[a.size()+1];
	for (int i = 0; i <= a.size(); i++)
		path[i] = new int[b.size() + 1];

	for (int i = 0; i <= a.size(); i++)
		for (int j = 0; j <= b.size(); j++)
			path[i][j] = 0;

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
			if (a[i - 1] == b[j - 1])
			{
				lcs[i][j] = lcs[i - 1][j - 1] + 1;
				//斜上
				path[i][j] = 1;
			}
			else
			{
				int left = lcs[i][j-1];
				int upper = lcs[i - 1][j];
				//lcs[i][j] = diff(lcs[i - 1][j], lcs[i][j - 1]);

				if (left > upper)//从左边来
				{
					lcs[i][j] = left;
					path[i][j] = 2;
				}
				else//从上边来
				{
					lcs[i][j] = upper;
					path[i][j] = 3;
				}
			}
		}
	}

	//输出这个二维矩阵
	for (int i = 0; i <= a.size(); i++)
	{
		for (int j = 0; j <= b.size(); j++)
			cout << lcs[i][j] << " ";

		cout << endl;
	}

	cout << "Path matrix is followed:\n";

	//输出路径矩阵
	for (int i = 0; i <= a.size(); i++)
	{
		for (int j = 0; j <= b.size(); j++)
			cout << path[i][j] << " ";

		cout << endl;
	}

	cout << "Largest Common String is " << commonString(path,a,b)<<endl;
}

int main()
{
	string a = "ABCBDAB";//bab  
	string b = "BDCABA";//caba

	LongestCommonSubsequence(a, b);

	return 0;
}