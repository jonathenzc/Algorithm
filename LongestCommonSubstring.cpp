//������Ӵ�
//��ָ�����ַ������������ͬ���Ӵ�
#include <iostream>
#include <string>

using namespace std;

//ʹ�ö�̬�滮����⣬��lcs[i][j]��ʾa[1...i]��b[1...j]��������Ӵ�
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

	//��������ά����
	for (int i = 0; i < a.size(); i++)
	{
		for (int j = 0; j < b.size(); j++)
			cout << lcs[i][j] << " ";

		cout << endl;
	}

	cout << "Longest length: "<<maxLength<<endl;

	cout << "Longest common substring is ";

	for (int i = maxLength-1; i >=0; i--)
		cout << a[iIndex - i];//b[jIndex+i]Ҳ��
	
}

int main()
{
	string a = "21232523311324";//bab
	string b = "312123223445";//caba

	LongestCommonSubstring(a,b);

	return 0;
}