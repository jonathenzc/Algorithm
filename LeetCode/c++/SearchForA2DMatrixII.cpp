#include <iostream>
#include <vector>

using namespace std;

//方法1：用mlogn的方法，对每行进行二分搜索
bool binarySearch(vector<int> v, int target)
{
	//左闭右开
	int start = 0, end = v.size(), mid = 0;
	bool result = false;
	while (start < end)
	{
		mid = (start+end) / 2;
		if (v[mid] == target)
		{
			result = true;
			break;
		}
		else if (v[mid] > target)
			end = mid;
		else
			start = mid + 1;
	}

	return result;
}

//bool searchMatrix(vector<vector<int>>& matrix, int target) {
//	//复杂度m*log(n)
//	//对每一行进行二分查找
//	bool isFound = false;
//	for (int i = 0; i < matrix.size();i++)
//	{
//		isFound = binarySearch(matrix[i],target);
//
//		if (isFound)
//			break;
//	}
//
//	return isFound;
//}

//方法2：用m+n的方法，从左下角开始搜素，如果当前元素比target大，那么就向上查找；如果比target小，向右查找，直到找到右上角
bool searchMatrix(vector<vector<int>>& matrix, int target) {
	//复杂度m+n
	//对每一行进行二分查找
	if (matrix.size() == 0)
		return false;

	int mSize = matrix[0].size();
	int i = matrix.size() - 1, j=0; //左下角，第matrix.size()-1行,第0列开始

	bool isFound = false;
	while(i>=0 && j < mSize)
	{
		int num = matrix[i][j];

		if (target == num)
		{
			isFound = true;
			break;
		}
		else if (target > num)
			j++;
		else
			i--;
	}

	return isFound;
}

int main()
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(4);
	v1.push_back(7);
	v1.push_back(11);
	v1.push_back(15);

	vector<int> v2;
	v2.push_back(2);
	v2.push_back(5);
	v2.push_back(8);
	v2.push_back(12);
	v2.push_back(19);

	vector<int> v3;
	v3.push_back(3);
	v3.push_back(9);
	v3.push_back(9);
	v3.push_back(16);
	v3.push_back(22);

	vector<int> v4;
	v4.push_back(10);
	v4.push_back(13);
	v4.push_back(14);
	v4.push_back(17);
	v4.push_back(24);

	vector<int> v5;
	v5.push_back(18);
	v5.push_back(21);
	v5.push_back(23);
	v5.push_back(26);
	v5.push_back(30);

	vector<vector<int>> v;
	v.push_back(v1);
	v.push_back(v2);
	v.push_back(v3);
	v.push_back(v4);
	v.push_back(v5);

	if (searchMatrix(v, 20))
		cout << "Yes";
	else
		cout << "No";

	return 0;
}