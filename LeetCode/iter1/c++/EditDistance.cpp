#include <iostream>
#include <string>

using namespace std;

int min(int a, int b, int c)
{
	if (a <= b && c >= a)//return a
		return a;
	else if (b <= a && c >= b)//return b
		return b;
	else if (c <= a && b >= c)//return c
		return c;
}

int minDistance(string word1,string word2)
{
	int **distance = new int*[word1.size()+1]; //distance[i][j]��ʾword1[0...i]��word2[0...j]�ı༭����
	for (int i = 0; i <= word1.size(); i++)
		distance[i] = new int[word2.size()+1];

	//��ʼ����̬����
	for (int i = 0; i <= word2.size(); i++)
		distance[0][i] = i;

	for (int i = 0; i <= word1.size(); i++)
		distance[i][0] = i;

	//�Ƚ������ַ���
	for (int i = 1; i <= word1.size(); i++)
	{
		for (int j = 1; j <= word2.size(); j++)
		{
			int temp = distance[i - 1][j - 1];
			if (word1[i-1] != word2[j-1])
				temp++;
			
			distance[i][j] = min(distance[i][j-1]+1,distance[i-1][j]+1,temp);
		}
	}

	//for (int i = 0; i <= word1.size(); i++)
	//{
	//	for (int j = 0; j <= word2.size(); j++)
	//		cout << distance[i][j] << " ";

	//	cout << endl;
	//}


	return distance[word1.size()][word2.size()];
}

int main()
{
	string a = "EXPONENTIAL";
	string b = "POLYNOMIAL";

	cout << minDistance(a,b);

	return 0;
}