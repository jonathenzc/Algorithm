#include <iostream>
#include <vector>

using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {
	int direction = 1;//1为从左向右，2为从下往上，3为从右向左，4为从上往下
	int n = matrix.size();
	int m = 0;
	if (n > 0)
		m = matrix[0].size();

	int end = m*n;
	int start = 1;
	int row = 0, col = 0;
	int diff = 1;

	vector<int> ret;

	while (start <= end)
	{
		ret.push_back(matrix[row][col]);

		if (col == m - diff && direction == 1)
			direction = 2;
		else if (row == n - diff && direction == 2)
			direction = 3;
		else if (col == diff-1 && direction == 3)
			direction = 4;
		else if (row == diff && direction == 4)
		{
			direction = 1;
			diff++;
		}

		if (direction == 1)
			col++;
		else if (direction == 2)
			row++;
		else if (direction == 3)
			col--;
		else if (direction == 4)
			row--;

		start++;
	}

	return ret;
}

void testPrint(vector<vector<int>>& matrix)
{
	vector<int> v = spiralOrder(matrix);
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}

	cout << endl;
}


int main()
{
	vector<vector<int>> vv1;
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);

	vector<int> v2;
	v2.push_back(5);
	v2.push_back(6);
	v2.push_back(7);
	v2.push_back(8);

	vector<int> v3;
	v3.push_back(9);
	v3.push_back(10);
	v3.push_back(11);
	v3.push_back(12);

	vv1.push_back(v1);
	vv1.push_back(v2);
	vv1.push_back(v3);


	//vector<vector<int>> vv1;
	//vector<int> v1;
	//v1.push_back(3);

	//vector<int> v2;
	//v2.push_back(2);

	//vv1.push_back(v1);
	//vv1.push_back(v2);

	testPrint(vv1);

	return 0;
}