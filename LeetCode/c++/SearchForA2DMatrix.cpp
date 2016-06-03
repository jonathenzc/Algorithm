#include <iostream>
#include <vector>

using namespace std;

int binarySearch(vector<int> v, int target)
{
	int start = 0, end = v.size(), mid = 0;
	while (start < end)
	{
		mid = (start + end) / 2;
		int midNum = v[mid];
		if (midNum == target)
		{
			break;
		}
		else if (midNum > target)
			end = mid;
		else
			start = mid + 1;
	}

	return mid;
}

bool isFound(vector<int> v, int target)
{
	int start = 0, end = v.size(), mid = 0;
	while (start < end)
	{
		mid = (start + end) / 2;
		int midNum = v[mid];
		if (midNum == target)
		{
			return true;
		}
		else if (midNum > target)
			end = mid;
		else
			start = mid + 1;
	}

	return false;
}

bool searchMatrix(vector<vector<int>>& matrix, int target) {
	if (matrix.size() == 0)
		return false;

	//获取第一列
	vector<int> columnV;
	for (int i = 0; i < matrix.size(); i++)
		columnV.push_back(matrix[i][0]);

	//先根据列的二分确定所在的行
	int rowIndex = binarySearch(columnV, target);

	if (target < columnV[rowIndex])
		rowIndex--;

	if (rowIndex < 0)
		return false;

	//如果第一个是就直接返回
	if (columnV[rowIndex] == target)
		return true;

	//再对行进行二分确定是否存在
	bool findResult = isFound(matrix[rowIndex], target);

	if (findResult)
		return true;
	else
		return false;
}

void testBinary(int num)
{
	vector<int> v;
	for (int i = 0; i < num; i++)
		v.push_back(i * 2);

	for (int i = 0; i < num; i++)
		cout << v[i] << " ";

	cout << endl;

	for (int i = -3; i <= 2 * num + 5; i++)
	{
		int index = binarySearch(v, i);
		cout << "i: " << i << " index: " << index << endl;
	}
}

int main()
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(5);
	v1.push_back(7);

	vector<int> v2;
	v2.push_back(10);
	v2.push_back(11);
	v2.push_back(16);
	v2.push_back(20);

	vector<int> v3;
	v3.push_back(23);
	v3.push_back(30);
	v3.push_back(34);
	v3.push_back(50);

	vector<vector<int>> v;
	v.push_back(v1);
	v.push_back(v2);
	v.push_back(v3);

	if (searchMatrix(v, 9))
		cout << "Yes\n";
	else
		cout << "No\n";

	//testBinary(6);

	return 0;
}
