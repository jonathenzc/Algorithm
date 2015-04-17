//�����������
//��ָ�����ַ��������ͬ���Ӵ���������ͬҲ���Բ�ͬ
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
		if (path[i][j] == 1)//б��
		{
			s += a[i - 1];//b[j-1]Ҳ��
			i--;
			j--;
		}
		else if (path[i][j] == 2)//���
			j--;
		else if (path[i][j] == 3)//�ϱ�
			i--;
	}

	//����ȡ�Ľ����תһ��
	string reversedS = "";
	for (int index = s.size() - 1; index >= 0; index--)
		reversedS += s[index];

	return reversedS;
}

//ʹ�ö�̬�滮����⣬��lcs[i][j]��ʾa[1...i]��b[1...j]��������Ӵ�
void LongestCommonSubsequence(string a, string b)
{
	//�����ӽṹ�Ķ�ά����
	int **lcs = new int*[a.size()+1];
	for (int i = 0; i <= a.size(); i++)
		lcs[i] = new int[b.size()+1];

	for (int i = 0; i <= a.size(); i++)
		for (int j = 0; j <= b.size(); j++)
			lcs[i][j] = 0;

	//��¼������еĸ������������ģ�0��ʾ��ʼ״̬��1��ʾб�ϣ�2��ʾ��ߣ�3��ʾ�ϱ�
	int **path = new int*[a.size()+1];
	for (int i = 0; i <= a.size(); i++)
		path[i] = new int[b.size() + 1];

	for (int i = 0; i <= a.size(); i++)
		for (int j = 0; j <= b.size(); j++)
			path[i][j] = 0;

	int iIndex = -1;
	int jIndex = -1;
	int maxLength = 0;

	//�����ӽṹ��
	//if a[i] != b[i], then lcs[i][j] = max(lcs[i-1][j],lcs[i][j-1]) ;
	//if a[i] == b[i], then lcs[i][j] = lcs[i-1][j-1]+1
	for (int i = 1; i <= a.size(); i++)
	{
		for (int j = 1; j <= b.size(); j++)
		{
			if (a[i - 1] == b[j - 1])
			{
				lcs[i][j] = lcs[i - 1][j - 1] + 1;
				//б��
				path[i][j] = 1;
			}
			else
			{
				int left = lcs[i][j-1];
				int upper = lcs[i - 1][j];
				//lcs[i][j] = diff(lcs[i - 1][j], lcs[i][j - 1]);

				if (left > upper)//�������
				{
					lcs[i][j] = left;
					path[i][j] = 2;
				}
				else//���ϱ���
				{
					lcs[i][j] = upper;
					path[i][j] = 3;
				}
			}
		}
	}

	//��������ά����
	for (int i = 0; i <= a.size(); i++)
	{
		for (int j = 0; j <= b.size(); j++)
			cout << lcs[i][j] << " ";

		cout << endl;
	}

	cout << "Path matrix is followed:\n";

	//���·������
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