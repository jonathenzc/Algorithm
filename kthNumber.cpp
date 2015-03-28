#include <iostream>

using namespace std;

////快排中的切分助手
//int partition(int *a, int start, int end)
//{
//	int target = a[start];
//	int i = start;
//	int j = end;
//
//	while (i < j)
//	{
//		while (i < j && a[j] >= target)
//			j--;
//
//		a[i] = a[j];
//
//		while (i < j && a[i] <= target)
//			i++;
//
//		a[j] = a[i];
//	}
//
//	a[i] = target;
//
//	return i;
//}

//快排其他切分助手
int partition(int *a, int start, int end)
{
	int i = start;

	int target = a[start];

	for (int j = start + 1; j <= end; j++)
	{
		if (a[j] < target)
		{
			i++;

			//找到小于target的数后就与之前比target大的数交换位置
			int temp = a[i];
			a[i] = a[j];
			a[j] = temp;
		}
	}

	a[start] = a[i];
	a[i] = target;

	return i;
}

//返回第k小的数
int getKthNumber(int *a, int size, int kth)
{
	if (kth > 0 && kth <= size)
	{
		int kthNumber = -1;
		int pivot = -1;
		int start = 0;
		int end = size - 1;
		kth--;//因为下标从0开始，不是从1开始

		while (start <= end)
		{
			pivot = partition(a, start, end);

			if (pivot == kth)
				return a[kth];
			else if (pivot < kth) //将pivot前的数截掉
				start = pivot + 1;
			else//将pivot后的数截掉
				end = pivot - 1;
		}

		return kthNumber;
	}
}

int main()
{
	//int a[6] = {34,12,23,67,45,78};

	int a[6] = { 34, 12, 34, 12, 12, 34 };

	cout << "3rd: " << getKthNumber(a, 6, 3) << endl
		<< "4th; " << getKthNumber(a, 6, 4) << endl;

	for (int i = 0; i < 6; i++)
		cout << a[i] << " ";

	return 0;
}