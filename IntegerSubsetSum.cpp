#include <iostream>

using namespace std;

//t为求和的目标
void positiveSubsetSum(int a[],int size,int t)
{
	//利用动态规划
	//isSubsetSum[i][j]表示元素从a0到ai求和是否等于j
	//那么它的值取决于[i-1][j]和[i-1][j-ai]是否等于1，只要其中一个为1那么它就为1
	bool **isSubsetSum = new bool*[size];
	for (int i = 0; i < size; i++)
		isSubsetSum[i] = new bool[t+1];

	//初始化
	//和为0时怎么样都为true因为不取就是了
	for (int i = 0; i < size; i++)
		isSubsetSum[i][0] = true;

	//放入a0是否能够放下
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

		//计算子集的元素
		int i = size - 1;
		int j = t;

		while (j > 0 && i>=0)//当容量回到0时，子集找到
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