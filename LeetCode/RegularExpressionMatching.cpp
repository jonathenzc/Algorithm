#include <iostream>
#include <string>

using namespace std;

bool isMatch(string s, string p)
{
	//isStrMatch[i][j]表示p[0...i-1]与s[0...j-1]是否匹配
	//矩阵的大小是(p.size()+1)*(s.size()+1)
	bool **isStrMatch = new bool*[p.size() + 1];
	for (int i = 0; i <= p.size(); i++)
		isStrMatch[i] = new bool[s.size() + 1];

	for (int i = 0; i <= p.size(); i++)
		for (int j = 0; j <= s.size();j++)
		isStrMatch[i][j] = false;

	isStrMatch[0][0] = true;//空字符串和空字符串比较，可以匹配

	for (int i = 1; i <= p.size(); i++)
	{
		for (int j = 0; j <= s.size(); j++)
		{
			if (p[i - 1] != '*')
				isStrMatch[i][j] = j>0 && isStrMatch[i-1][j-1] && (p[i-1] == s[j-1] || p[i-1] == '.');
			else
			{
				//*前肯定会带一个元素，所以i-2不会越界访问
				isStrMatch[i][j] = isStrMatch[i - 2][j]; //*前的元素不忽视的情况
				isStrMatch[i][j] = isStrMatch[i][j] || (j>0 && isStrMatch[i][j-1] && (p[i - 2] == s[j - 1] || p[i - 2] == '.'));//*前元素至少替代一个
			}
		}

		//cout << "b ";
		//for (int k = 0; k <= s.size(); k++)
		//{
		//	if (isStrMatch[i][k])
		//		cout << "1 ";
		//	else
		//		cout << "0 ";
		//}
		//cout << endl;
	}

	return isStrMatch[p.size()][s.size()];
}

int main()
{
	string a = "aab";
	string b = "c*a*b";

	if (isMatch(a, b))
		cout << "Yes";
	else
		cout << "No";

	return 0;
}