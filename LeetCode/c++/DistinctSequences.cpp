#include <iostream>
#include <string>
#include <vector>

using namespace std;

int numDistinct(string s, string t) {
	if (t.size() == 0)
		return 1;

	if (s.size() == 0)
		return 0;

	//dpCnt[i][j]表示t[0...i-1]是s[0...j-1]的子串个数
	int **dpCnt = new int*[t.size()+1];
	for (int i = 0; i <= t.size(); i++)
		dpCnt[i] = new int[s.size() + 1];

	dpCnt[0][0] = 1;

	//第一行
	for (int i = 1; i <= s.size(); i++)
		dpCnt[0][i] = 1;

	//第一列
	for (int i = 1; i <= t.size(); i++)
		dpCnt[i][0] = 0;

	for (int i = 1; i <= t.size(); i++)
	{
		for (int j = 1; j <= s.size(); j++)
		{
			dpCnt[i][j] = dpCnt[i][j-1]; //t[0...i-2]是s[0...j-1]的子串个数
			if (t[i - 1] == s[j - 1])
				dpCnt[i][j] += dpCnt[i-1][j-1];
		}
	}

	return dpCnt[t.size()][s.size()];
}


int main()
{
	cout<< numDistinct("rabbbit","rabbit")<<endl;


	return 0;
}