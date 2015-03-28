#include <iostream>

using namespace std;

int main()
{
	int *LIS; //LIS[i]��ʾ��������0��i�������������

	int sequenceLength;
	cout << "�����������еĳ���: ";
	cin >> sequenceLength;

	LIS = new int[sequenceLength];

	//��ʼ��LIS
	for (int i = 0; i < sequenceLength; i++)
		LIS[i] = 1;

	int *sequence = new int[sequenceLength];//��������

	cout << "������������ \n";
	for (int i = 0; i < sequenceLength; i++)
		cin >> sequence[i];

	//��ʼ�滮
	for (int i = 0; i < sequenceLength; i++)
	{
		int max = -1;
		for (int j = 0; j < i;j++)
		{
			if (sequence[j] < sequence[i])//�ϸ����,����֮���б�
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