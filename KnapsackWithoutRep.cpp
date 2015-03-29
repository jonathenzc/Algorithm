//物品不可重复的背包问题
#include <iostream>

using namespace std;

struct knapsack
{
	int weight;
	int value;
};

void KnapsackWithoutRepo(int itemWeight, int itemValue, int itemIndex, int **bag, int bagCapIndex)
{
	//比较放入物品itemIndex对背包价值的影响
	if (itemWeight <= bagCapIndex)
	{
		int includeItem; //放入物品itemIndex的最大价值
		int excludeItem;//不放入物品itemIndex的最大价值

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

	//输入物品个数
	cout << "输入物品的个数: ";
	cin >> itemCnt;

	itemList = new knapsack[itemCnt];

	//输入物品重量和价值
	cout << "输入物品的重量和价值(w v): \n";
	for (int i = 0; i < itemCnt; i++)
		cin >> itemList[i].weight >> itemList[i].value;

	//输入背包容量
	int bagCapacity;//背包容量
	cout << "输入背包容量: ";
	cin >> bagCapacity;

	//动态规划的辅助变量
	int **bag = new int*[itemCnt];//bag[i][j]表示容量i时是否装入物品j的最大价值
	for (int i = 0; i < itemCnt; i++)
		bag[i] = new int[bagCapacity+1];

	for (int i = 0; i < itemCnt; i++)
		for (int j = 0; j <= bagCapacity;j++)
			bag[i][j] = 0;

	for (int j = itemList[0].weight; j <= bagCapacity; j++)
		bag[0][j] = itemList[0].value;

	//开始动态规划
	for (int i = 1; i < itemCnt; i++)
		for (int j = 0; j <= bagCapacity;j++)
			KnapsackWithoutRepo(itemList[i].weight,itemList[i].value, i, bag, j);

	for (int i = 0; i < itemCnt; i++)
	{
		for (int j = 0; j <= bagCapacity; j++)
			cout << bag[i][j] << " ";

		cout << endl;
	}


	cout << "\n最大容量为" << bag[itemCnt-1][bagCapacity];

	return 0;
}