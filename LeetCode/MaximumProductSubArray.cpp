#include <iostream>
#include <vector>

using namespace std;

//int max(int a, int b,int c)
//{
//	if (a >= b && c<=a) //max a
//		return a;
//	else if (b >= c && a <= b) //max b
//		return b;
//	else if (c >= a && b <= c)//max c
//		return c;
//}
//
//int min(int a, int b,int c)
//{
//	if (a <= b && c >= a) //min a
//		return a;
//	else if (b <= c && a >= b) //min b
//		return b;
//	else if (c <= a && b >= c)//min c
//		return c;
//}

//int maxProduct(vector<int>& nums) {
//	if (nums.size() == 0)
//		return 0;
//
//	int curmax = nums[0];
//	int curmin = nums[0];
//	int maxPro = nums[0];
//	for (int i = 1; i < nums.size(); i++)
//	{
//		int temp = curmax;
//		curmax = max(curmax*nums[i],nums[i],curmin*nums[i]);
//		curmin = min(temp*nums[i], nums[i], curmin*nums[i]);
//
//		if (curmax > maxPro)
//			maxPro = curmax;
//	}
//	
//	return maxPro;
//}

const int MIN = -99999999;

int maxFive(int a, int b, int c, int d, int e)
{
	if (a >= b && c <= a && d <= a && e <= a) //max a
		return a;
	else if (b >= a && c <= b && d <= b && e <= b) // max b
		return b;
	else if (c >= a && b <= c && d <= c && e <= c) // max c
		return c;
	else if (d >= a && b <= d && c <= d && e <= d) // max d
		return d;
	else if (e >= a && b <= e && c <= e && d <= e) // max e
		return e;
}

int product(vector<int> v, int start, int end)
{
	if (start > end || end > v.size() || start >= v.size())
		return MIN;

	int result = v[start];
	for (int i = start+1; i < end; i++)
		result *= v[i];

	return result;
}

int maxProduct(vector<int>& nums) {
	//存储0的下标数组
	int *zeroArray = new int[nums.size()];
	int zeroArraySize = 0;
	zeroArray[zeroArraySize++] = -1;
	//存储负数的下标数组
	int *negativeArray = new int[nums.size()];
	int negativeArraySize = 0;

	//记录数组中的非正数下标
	int max;

	for (int i = 0; i < nums.size(); i++)
	{
		if (nums[i] == 0)
			zeroArray[zeroArraySize++] = i;

		if (nums[i] < 0)
			negativeArray[negativeArraySize++] = i;

		if (i == 0)
			max = nums[0];
		else
			max *= nums[i];
	}

	zeroArray[zeroArraySize++] = nums.size();

	if (max > 0)
		return max;

	max = MIN;

	int j = 0;
	int negativeCnt = 0;
	int negativeFirstIndex = -1;
	int negativeLastIndex = -1;
	for (int i = 1; i < zeroArraySize;i++)
	{
		while (j<negativeArraySize && negativeArray[j] < zeroArray[i])
		{
			if (negativeFirstIndex == -1)
				negativeFirstIndex = negativeArray[j];

			negativeCnt++;
			negativeLastIndex = negativeArray[j];
			j++;
		}

		//zeroArray[i]前的负数个数为偶数
		if (negativeCnt % 2 == 0)
		{
			int tempProduct = MIN;

			if (zeroArray[i-1]+1 < nums.size())
				tempProduct = product(nums, zeroArray[i - 1] + 1, zeroArray[i]);

			if (tempProduct > max)
				max = tempProduct;
		}
		else
		{
			//以最后一个负数的索引来计算最大乘积，比如1,2,-3,4,5,-6,7,-8,9,10,11
			int formerPartWithLast = product(nums, zeroArray[i - 1] + 1, negativeLastIndex);//1到7
			int latterPartWithLast = product(nums,negativeLastIndex+1,zeroArray[i]);//9到11
			//以第一个负数的索引来计算最大乘机，比如1,2,-3,4,5,-6,7,-8,9,10,11
			int formerPartWithFirst = product(nums,zeroArray[i-1]+1,negativeFirstIndex); //1到2
			int latterPartWithFirst = product(nums, negativeFirstIndex + 1, zeroArray[i]); //4到11

			max = maxFive(max,formerPartWithLast,latterPartWithLast,formerPartWithFirst,latterPartWithFirst);
		}
		
		negativeCnt = 0;
		negativeFirstIndex = -1;
		negativeLastIndex = -1;
	}

	return max;
}


int main()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(1);
	v.push_back(2);
	v.push_back(-3);
	v.push_back(4);
	v.push_back(5); 
	v.push_back(-6);
	//v.push_back(7);
	//v.push_back(-8);
	//v.push_back(9);
	//v.push_back(10);
	//v.push_back(11);

	//v.push_back(-3);
	//v.push_back(0);
	//v.push_back(1);
	//v.push_back(-2);

	cout << maxProduct(v);

	return 0;
}