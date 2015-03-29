//��Ʒ�����ظ��ı�������
#include <iostream>

using namespace std;

struct knapsack
{
	int weight;
	int value;
};

void KnapsackWithoutRepo(int itemWeight, int itemValue, int itemIndex, int **bag, int bagCapIndex)
{
	//�ȽϷ�����ƷitemIndex�Ա�����ֵ��Ӱ��
	if (itemWeight <= bagCapIndex)
	{
		int includeItem; //������ƷitemIndex������ֵ
		int excludeItem;//��������ƷitemIndex������ֵ

		includeItem = bag[itemIndex - 1][bagCapIndex - itemWeight] + itemValue;
		excludeItem = bag[itemIndex - 1][bagCapIndex];

		if (includeItem < excludeItem)
			bag[itemIndex][bagCapIndex] = excludeItem;
		else
			bag[itemIndex][bagCapIndex] = includeItem; 
	}
	else
		bag[itemIndex][bagCapIndex] = bag[itemIndex - 1][bagCapIndex];
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
	int **bag = new int*[itemCnt];//bag[i][j]��ʾ����iʱ�Ƿ�װ����Ʒj������ֵ
	for (int i = 0; i < itemCnt; i++)
		bag[i] = new int[bagCapacity+1];

	for (int i = 0; i < itemCnt; i++)
		for (int j = 0; j <= bagCapacity;j++)
			bag[i][j] = 0;

	for (int j = itemList[0].weight; j <= bagCapacity; j++)
		bag[0][j] = itemList[0].value;

	//��ʼ��̬�滮
	for (int i = 1; i < itemCnt; i++)
		for (int j = 0; j <= bagCapacity;j++)
			KnapsackWithoutRepo(itemList[i].weight,itemList[i].value, i, bag, j);

	for (int i = 0; i < itemCnt; i++)
	{
		for (int j = 0; j <= bagCapacity; j++)
			cout << bag[i][j] << " ";

		cout << endl;
	}


	cout << "\n�������Ϊ" << bag[itemCnt-1][bagCapacity];

	return 0;
}