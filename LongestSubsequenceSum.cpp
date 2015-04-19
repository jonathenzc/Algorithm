//最长子序列和，求出一组连续的数字序列，使得它们的和最大

#include <iostream>

using namespace std;

//算法思路：从头开始加起，如果加上sequence[i]之后仍大于0则继续加下去。复杂度是线性的
void longestSubsequenceSum(int sequence[], int length)
{
	if (length > 0)
	{
		int maxStartIndex = 0;
		int maxEndIndex = 0;
		int maxSum = 0;//sequence[0];

		int subSum = 0;//sequence[0];
		int subStartIndex = 0;
		int subEndIndex = 0;

		for (int i = 0; i < length; i++)
		{
			subSum += sequence[i];
			if (subSum >= maxSum)
			{
				maxSum = subSum;
				maxStartIndex = subStartIndex;
				maxEndIndex = i;
			}
			else if (subSum < 0)
			{
				subSum = 0;
				subStartIndex = i + 1;
			}
		}

		//输出结果
		if (maxSum == 0)//全是负数或者全是非正数
		{
			//那么找个最大的数
			int max = -9999;
			int maxIndex = 0;
			for (int i = 0; i < length; i++)
			{
				if (sequence[i] > max)
				{
					max = sequence[i];
					maxIndex = i;
				}
			}

			cout << "Longest subsequence sum is " << max << endl
				<< sequence[maxIndex]<<endl;
		}
		else
		{ 
			cout << "Longest subsequence sum is " << maxSum << endl;
			
			for (int i = maxStartIndex; i <= maxEndIndex; i++)
				cout << sequence[i] << " ";

			cout << endl;
		}
	}
	else
	{
		cout << "There is no longest subsequence sum.\n";
	}
}

int main()
{
	int a[6] = {-2,11,-4,13,-5,-2}; //20
	int b[12] = {-6,2,4,-7,5,3,2,-1,6,-9,10,-2 }; // 16
	int c[4] = {5,-3,4,2}; //8
	int d[4] = {5,-6,4,2}; //6
	int e[4] = {5,-6,1,2}; //5
	int f[4] = {-5,-6,-1,-2}; //-1
	int g[4] = {0,0,0,0 }; // 0

	longestSubsequenceSum(a, 6);
	longestSubsequenceSum(b, 12);
	longestSubsequenceSum(c, 4);
	longestSubsequenceSum(d, 4);
	longestSubsequenceSum(e, 4);
	longestSubsequenceSum(f, 4);
	longestSubsequenceSum(g, 4);

	return 0;
}