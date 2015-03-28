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
	int *dimension; //用来记录各个矩阵维度，如果矩阵的维度是50*20,20*1,1*10,10*100，那么矩阵内的信息为50,20,1,10,100

	int matrixCnt;

	cout << "输入矩阵的个数";
	cin >> matrixCnt;

	dimension = new int[matrixCnt+1];

	cout << "输入各个矩阵的维度：\n";
	for (int i = 0; i < matrixCnt+1; i++)
		cin >> dimension[i];

	//multiplicationCnt是矩阵
	int **multiplicationCnt = new int*[matrixCnt];
	for (int i = 0; i < matrixCnt; i++)
		multiplicationCnt[i] = new int[matrixCnt];

	//multiplicationCnt初始化
	for (int i = 0; i < matrixCnt; i++)
	{
		for (int j = 0; j < matrixCnt; j++)
		{
			multiplicationCnt[i][j] = 0;
		}
	}

	//动态规划计算,斜对角动态规划
	for (int s = 0; s < matrixCnt;s++)//s表示multiplicationCnt[i][j]中j-i的大小，通过这个差值来实现斜对角访问
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
