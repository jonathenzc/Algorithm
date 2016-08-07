#include <iostream>
#include <vector>

using namespace std;

//方法1：O(n^2)
//int maxArea(vector<int>& height) {
//	if (height.size() < 2)
//		return 0;
//	
//	//每次记录范围内的最小值高度和其在数组中的下标，同时需要记录当前的最大值面积
//	int max_area = 0;
//	int minHeight = INT_MAX, minIndex = -1;
//
//	for (int i = 1; i < height.size(); i++)
//	{
//		for (int j = 0; j < i; j++)
//		{
//			int areaH = height[i];
//			if (height[j] < height[i])
//				areaH = height[j];
//
//			int area = areaH*(i-j);
//			if (area > max_area)
//				max_area = area;
//		}
//	}
//
//	return max_area;
//}

int min(int a, int b)
{
	if (a < b)
		return a;
	else
		return b;
}

int max(int a, int b)
{
	if (a > b)
		return a;
	else
		return b;
}

//方法2：O(n)
int maxArea(vector<int>& height) {
	int max_area = 0;
	int i = 0, j = height.size() - 1;
	int h = 0;
	//从两边开始往中间找高度高的下标
	while (i < j)
	{
		h = min(height[i],height[j]);
		max_area = max((j - i)*h,max_area);
		//找到比h要高的下标
		while (height[i] <= h && i < j)
			i++;

		while (height[j] <= h && i < j)
			j--;
	}

	return max_area;
}

void testPrint(vector<vector<char>>& board)
{
	for (auto row : board)
	{
		for (auto col : row)
			cout << col << " ";

		cout << endl;
	}

	cout << endl;
}

int main()
{
	vector<int> v1;

	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(2);
	v1.push_back(5);


	cout << maxArea(v1);



	return 0;
}