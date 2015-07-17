#include <iostream>
#include <string>

using namespace std;

bool isMatch(string s, string p)
{
	//isStrMatch[i][j]��ʾp[0...i-1]��s[0...j-1]�Ƿ�ƥ��
	//����Ĵ�С��(p.size()+1)*(s.size()+1)
	bool **isStrMatch = new bool*[p.size() + 1];
	for (int i = 0; i <= p.size(); i++)
		isStrMatch[i] = new bool[s.size() + 1];

	for (int i = 0; i <= p.size(); i++)
		for (int j = 0; j <= s.size();j++)
		isStrMatch[i][j] = false;

	isStrMatch[0][0] = true;//���ַ����Ϳ��ַ����Ƚϣ�����ƥ��

	for (int i = 1; i <= p.size(); i++)
	{
		for (int j = 0; j <= s.size(); j++)
		{
			if (p[i - 1] != '*')
				isStrMatch[i][j] = j>0 && isStrMatch[i-1][j-1] && (p[i-1] == s[j-1] || p[i-1] == '.');
			else
			{
				//*ǰ�϶����һ��Ԫ�أ�����i-2����Խ�����
				isStrMatch[i][j] = isStrMatch[i - 2][j]; //*ǰ��Ԫ�ز����ӵ����
				isStrMatch[i][j] = isStrMatch[i][j] || (j>0 && isStrMatch[i][j-1] && (p[i - 2] == s[j - 1] || p[i - 2] == '.'));//*ǰԪ���������һ��
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