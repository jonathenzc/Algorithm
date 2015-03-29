//物品可重复的背包问题
#include <iostream>

using namespace std;

struct knapsack
{
	int weight;
	int value;
};

void KnapsackWithRepo(knapsack *itemList, int *bag, int index, int itemCnt,int bagCapacity)
{
	//对每个item进行判断
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
	int *bag = new int[bagCapacity+1];//bag[i]表示容量i时可装的最大价值

	for (int i = 0; i <= bagCapacity; i++)
		bag[i] = 0;

	//开始动态规划
	for (int i = 0; i <= bagCapacity; i++)
	{
		KnapsackWithRepo(itemList, bag, i,itemCnt,bagCapacity);
	}

	for (int i = 0; i <= bagCapacity; i++)
		cout << bag[i] << " ";

	cout << "\n最大容量为" << bag[bagCapacity];

	return 0;
}