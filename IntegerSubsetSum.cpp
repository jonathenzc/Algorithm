#include <iostream>

using namespace std;

//tΪ��͵�Ŀ��
void positiveSubsetSum(int a[],int size,int t)
{
	//���ö�̬�滮
	//isSubsetSum[i][j]��ʾԪ�ش�a0��ai����Ƿ����j
	//��ô����ֵȡ����[i-1][j]��[i-1][j-ai]�Ƿ����1��ֻҪ����һ��Ϊ1��ô����Ϊ1
	bool **isSubsetSum = new bool*[size];
	for (int i = 0; i < size; i++)
		isSubsetSum[i] = new bool[t+1];

	//��ʼ��
	//��Ϊ0ʱ��ô����Ϊtrue��Ϊ��ȡ������
	for (int i = 0; i < size; i++)
		isSubsetSum[i][0] = true;

	//����a0�Ƿ��ܹ�����
	for (int i = 1; i <= t; i++)
	{
		if (a[0] == i)
			isSubsetSum[0][i] = true;
		else
			isSubsetSum[0][i] = false;
	}

	for (int i = 1; i < size; i++)
	{
		for (int j = 1; j <= t; j++)
		{
			isSubsetSum[i][j] = isSubsetSum[i-1][j];

			if (j >= a[i])
				isSubsetSum[i][j] = isSubsetSum[i][j] || isSubsetSum[i-1][j-a[i]];
		}
	}

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j <= t; j++)
			cout << isSubsetSum[i][j] << " ";

		cout << endl;
	}

	if (isSubsetSum[size - 1][t])
	{
		cout << "There is subset sum equals " << t<<endl;

		//�����Ӽ���Ԫ��
		int i = size - 1;
		int j = t;

		while (j > 0 && i>=0)//�������ص�0ʱ���Ӽ��ҵ�
		{
			if (j >= a[i] && i >= 1 && isSubsetSum[i - 1][j - a[i]])
			{
				cout << a[i] << " ";
				j = j - a[i];
			}
			else if (i == 0)
				cout << a[i];

			i--;
		}
	}
	else
		cout << "There isn't subset sum equals "<<t;
}

int main()
{
	int a[7] = {1,1,1,2,7,3,1};
	
	positiveSubsetSum(a, 7, 10);

	return 0;
}