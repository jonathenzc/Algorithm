#include <iostream>

using namespace std;

////�����е��з�����
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

//���������з�����
int partition(int *a, int start, int end)
{
	int i = start;

	int target = a[start];

	for (int j = start + 1; j <= end; j++)
	{
		if (a[j] < target)
		{
			i++;

			//�ҵ�С��target���������֮ǰ��target���������λ��
			int temp = a[i];
			a[i] = a[j];
			a[j] = temp;
		}
	}

	a[start] = a[i];
	a[i] = target;

	return i;
}

//���ص�kС����
int getKthNumber(int *a, int size, int kth)
{
	if (kth > 0 && kth <= size)
	{
		int kthNumber = -1;
		int pivot = -1;
		int start = 0;
		int end = size - 1;
		kth--;//��Ϊ�±��0��ʼ�����Ǵ�1��ʼ

		while (start <= end)
		{
			pivot = partition(a, start, end);

			if (pivot == kth)
				return a[kth];
			else if (pivot < kth) //��pivotǰ�����ص�
				start = pivot + 1;
			else//��pivot������ص�
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