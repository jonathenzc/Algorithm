//��Ʒ���ظ��ı�������
#include <iostream>

using namespace std;

struct knapsack
{
	int weight;
	int value;
};

void KnapsackWithRepo(knapsack *itemList, int *bag, int index, int itemCnt,int bagCapacity)
{
	//��ÿ��item�����ж�
	int maxValue = 0;

	for (int i = 0; i < itemCnt; i++)
	{
		if (itemList[i].weight <= index)
		{
			int valueCandidate = bag[index - itemList[i].weight] + itemList[i].value;
			if (maxValue < valueCandidate)
				maxValue = valueCandidate;
		}
	}

	bag[index] = maxValue;
}

int main()
{
	knapsack *itemList;
	int itemCnt;

	//������Ʒ����
	cout << "������Ʒ�ĸ���: ";
	cin >> itemCnt;

	itemList = new knapsack[itemCnt];

	//������Ʒ�����ͼ�ֵ
	cout << "������Ʒ�������ͼ�ֵ(w v): \n";
	for (int i = 0; i < itemCnt; i++)
		cin >> itemList[i].weight >> itemList[i].value;

	//���뱳������
	int bagCapacity;//��������
	cout << "���뱳������: ";
	cin >> bagCapacity;

	//��̬�滮�ĸ�������
	int *bag = new int[bagCapacity+1];//bag[i]��ʾ����iʱ��װ������ֵ

	for (int i = 0; i <= bagCapacity; i++)
		bag[i] = 0;

	//��ʼ��̬�滮
	for (int i = 0; i <= bagCapacity; i++)
	{
		KnapsackWithRepo(itemList, bag, i,itemCnt,bagCapacity);
	}

	for (int i = 0; i <= bagCapacity; i++)
		cout << bag[i] << " ";

	cout << "\n�������Ϊ" << bag[bagCapacity];

	return 0;
}