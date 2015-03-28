#include <iostream>

using namespace std;

int main()
{
	int *LIS; //LIS[i]表示数字序列0到i的最长递增子序列

	int sequenceLength;
	cout << "输入数字序列的长度: ";
	cin >> sequenceLength;

	LIS = new int[sequenceLength];

	//初始化LIS
	for (int i = 0; i < sequenceLength; i++)
		LIS[i] = 1;

	int *sequence = new int[sequenceLength];//数字序列

	cout << "输入数字序列 \n";
	for (int i = 0; i < sequenceLength; i++)
		cin >> sequence[i];

	//开始规划
	for (int i = 0; i < sequenceLength; i++)
	{
		int max = -1;
		for (int j = 0; j < i;j++)
		{
			if (sequence[j] < sequence[i])//严格递增,他们之间有边
			{
				if (max < LIS[j])
					max = LIS[j];
			}
		}

		if (max!=-1)
			LIS[i] = max+1;
	}

	for (int i = 0; i < sequenceLength; i++)
		cout << LIS[i] << " ";

	cout << endl;
	cout << LIS[sequenceLength-1];

	return 0;
}