#include <iostream>
#include <vector>

using namespace std;

void rotate(vector<vector<int>>& matrix) 
{
	int temp;
	int n = matrix.size();

	//先按水平线交换对折交换，接着通过对角线交换
	for (int i = 0; i < n; i++) //第i列
	{
		for (int j = 0; j < n/2; j++)
		{
			temp = matrix[j][i];
			matrix[j][i] = matrix[n-1-j][i];
			matrix[n - 1 - j][i] = temp;
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			temp = matrix[i][j];
			matrix[i][j] = matrix[j][i];
			matrix[j][i] = temp;
		}
	}
}

vector<int> getImageRow(int n,int cnt)
{
	vector<int> v;

	for (int i = n; i < n + cnt; i++)
		v.push_back(i);

	return v;
}

void printV(vector<vector<int>> v)
{
	for (int i = 0; i < v.size(); i++)
	{
		for (int j = 0; j < v.size(); j++)
			cout << v[i][j] << " ";

		cout << endl;
	}
}

int main()
{
	vector<int> v1 = getImageRow(11, 5);
	vector<int> v2 = getImageRow(21, 5);
	vector<int> v3 = getImageRow(31, 5);
	vector<int> v4 = getImageRow(41, 5);
	vector<int> v5 = getImageRow(51, 5);

	vector<vector<int>> v;
	v.push_back(v1);
	v.push_back(v2);
	v.push_back(v3);
	v.push_back(v4);
	v.push_back(v5);

	printV(v);

	cout << endl;

	rotate(v);

	printV(v);

	return 0;
}