#include <iostream>
#include <string>

using namespace std;

//bool isMatch(string s, string p) 
//{
//	if (s.size()== p.size())
//	{
//		for (int i = 0; i < s.size(); i++)
//		{
//			if (s[i] != p[i])
//				break;
//
//			if (i == s.size() - 1)
//				return true;
//		}
//	}
//	
//	bool *isStrMatch = new bool[s.size()+1]; //isStrMatch[i]��ʾs[0...i]�ܷ���Pƥ��
//	for (int i = 0; i <= s.size(); i++)
//		isStrMatch[i] = false;
//
//	isStrMatch[0] = true;
//
//	for (int i = 0; i < p.size(); i++)
//	{
//		if (p[i] == '*')
//		{
//			for (int j = 1; j <= s.size(); j++)
//				isStrMatch[j] = isStrMatch[j] || isStrMatch[j - 1];
//
//			cout << "a ";
//			for (int k = 0; k <= s.size(); k++)
//			{
//				if (isStrMatch[k])
//					cout << "1 ";
//				else
//					cout << "0 ";
//			}
//			cout << endl;
//		}
//		else
//		{
//			for (int j = s.size(); j > 0; j--)
//				isStrMatch[j] = isStrMatch[j-1] && (p[i] == '?' || p[i] == s[j-1]);
//
//			cout << "b ";
//			for (int k = 0; k <= s.size(); k++)
//			{
//				if (isStrMatch[k])
//					cout << "1 ";
//				else
//					cout << "0 ";
//			}
//			cout << endl;
//		}
//
//		isStrMatch[0] = isStrMatch[0] && (p[i] == '*');
//	}
//
//	return isStrMatch[s.size()];
//}

bool isMatch(string s, string p)
{
	if (s.size()== p.size())
	{
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] != p[i])
				break;
	
			if (i == s.size() - 1)
				return true;
		}
	}

	//isStrMatch[i][j]��ʾp[0...i-1]��s[0...j-1]�Ƿ�ƥ��
	//����Ĵ�С��(p.size()+1)*(s.size()+1)�����᲻��Ҫ���ǿ��ַ�����Ϊ�϶��ǲ�ƥ���
	bool **isStrMatch = new bool*[p.size()+1]; 
	for (int i = 0; i <= p.size(); i++)
		isStrMatch[i] = new bool[s.size()+1];

	for (int i = 0; i <= s.size(); i++)
		isStrMatch[0][i] = false;

	isStrMatch[0][0] = true;

	for (int i = 1; i <= p.size(); i++)
	{
		isStrMatch[i][0] = isStrMatch[i - 1][0] && (p[i-1] == '*');

		if (p[i-1] == '*')
		{
			for (int j = 1; j <= s.size(); j++)
				isStrMatch[i][j] = isStrMatch[i-1][j] || isStrMatch[i][j - 1];
		}
		else
		{
			for (int j = 1; j <= s.size(); j++)
				isStrMatch[i][j] = isStrMatch[i-1][j - 1] && (p[i-1] == '?' || p[i-1] == s[j - 1]);
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
	string a = "aaaabbbb";
	string b = "a*b";

	if (isMatch(a, b))
		cout << "Yes";
	else
		cout << "No";

	return 0;
}