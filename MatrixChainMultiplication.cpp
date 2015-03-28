#include <iostream>

using namespace std;

void matrixChain(int **multi,int *dimension,int i,int j)
{
	int min = 999999999;
	for (int k = i; k < j; k++)
	{
		int multiCnt = multi[i][k] + multi[k + 1][j] + dimension[i]*dimension[k+1]*dimension[j+1];
		if (min > multiCnt)
			min = multiCnt;

		if (k==j-1)
			multi[i][j] = min;
	}
}

int main()
{
	int *dimension; //������¼��������ά�ȣ���������ά����50*20,20*1,1*10,10*100����ô�����ڵ���ϢΪ50,20,1,10,100

	int matrixCnt;

	cout << "�������ĸ���";
	cin >> matrixCnt;

	dimension = new int[matrixCnt+1];

	cout << "������������ά�ȣ�\n";
	for (int i = 0; i < matrixCnt+1; i++)
		cin >> dimension[i];

	//multiplicationCnt�Ǿ���
	int **multiplicationCnt = new int*[matrixCnt];
	for (int i = 0; i < matrixCnt; i++)
		multiplicationCnt[i] = new int[matrixCnt];

	//multiplicationCnt��ʼ��
	for (int i = 0; i < matrixCnt; i++)
	{
		for (int j = 0; j < matrixCnt; j++)
		{
			multiplicationCnt[i][j] = 0;
		}
	}

	//��̬�滮����,б�ԽǶ�̬�滮
	for (int s = 0; s < matrixCnt;s++)//s��ʾmultiplicationCnt[i][j]��j-i�Ĵ�С��ͨ�������ֵ��ʵ��б�ԽǷ���
	{
		for (int i = 0; i < matrixCnt-s; i++)
		{
			int j = i + s;

			matrixChain(multiplicationCnt,dimension,i, j);
		}
	}

	for (int i = 0; i < matrixCnt; i++)
	{
		for (int j = 0; j < matrixCnt; j++)
		{
			cout<<multiplicationCnt[i][j]<<" ";
		}
		cout << endl;
	}

	cout << "Matrix Chain Multiplication minimal count is " << multiplicationCnt[0][matrixCnt - 1] << endl;

	return 0;
}
