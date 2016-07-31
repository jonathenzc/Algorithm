#include <iostream>
#include <vector>

using namespace std;

//方法1：
int hIndex(vector<int>& citations) {
	int *map = new int[citations.size() + 1];

	for (int i = 0; i <= citations.size(); i++)
		map[i] = 0;

	for (int i = 0; i < citations.size(); i++)
	{
		int j = 0;
		while (j <= citations.size() && j <= citations[i])
		{
			map[j]++;
			j++;
		}
	}


	int hIndex = 0;

	for (int i = citations.size(); i >= 0; i--)
	{
		if (i <= map[i])
		{
			hIndex = i;
			break;
		}
	}

	return hIndex;
}

//方法2：
int hIndex(vector<int>& citations) {
	
	//求出最大值
	int max = 0;
	for (int i = 0; i < citations.size(); i++)
	{
		if (max < citations[i])
			max = citations[i];
	}

	//构建引用量与个数的映射
	int *map = new int[max+1];
	for (int i = 0; i <= max; i++)
		map[i] = 0;

	for (int i = 0; i < citations.size(); i++)
		map[citations[i]]++;

	int hIndex = 0;

	for (int i = max; i >= 0; i--)
	{
		hIndex += map[i];
		if (hIndex >= i)
		{
			hIndex = i;
			break;
		}
	}

	return hIndex;
}

int main()
{
	vector<int> v;
	v.push_back(4);
	v.push_back(5);
	v.push_back(6);
	v.push_back(1);
	v.push_back(5);

	cout << hIndex(v)<<endl;

	vector<int> v1;
	v1.push_back(4);
	v1.push_back(4);
	v1.push_back(0);
	v1.push_back(0);
	cout << hIndex(v1)<<endl;

	return 0;
}