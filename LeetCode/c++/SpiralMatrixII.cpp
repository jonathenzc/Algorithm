#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> generateMatrix(int n) {
	vector<vector<int>> v(n,vector<int>(n)); //用push_back会花费额外的时间

	if (n > 0)
	{
		int cnt = 1;
		int end = n*n;
		int row = 0, col = 0;
		int direction = 1; //1为从左向右，2为从右向左,3为从上往下，4为从下往上
		int diff = 1;

		while (cnt <= end)
		{
			v[row][col] = cnt;

			if (direction == 1)
				col++;
			else if (direction == 2)
				col--;
			else if (direction == 3)
				row++;
			else if (direction == 4)
				row--;

			//更新位置
			if (col == n - diff && direction == 1)
				direction = 3;
			else if (row == n - diff && direction == 3)
				direction = 2;
			else if (col == diff-1 && direction == 2)
				direction = 4;
			else if (row == diff && direction == 4)
			{
				direction = 1;
				diff++;
			}

			cnt++;
		}
	}

	return v;
}

void testPrint(int n)
{
	cout << "test " << n << endl;

	vector<vector<int>> v = generateMatrix(n);
	for (int i = 0; i < v.size(); i++)
	{
		vector<int> tmpV = v[i];
		for (int j = 0; j < tmpV.size(); j++)
			cout << tmpV[j] << " ";

		cout << endl;
	}

	cout << endl;
}


int main()
{
	testPrint(3);
	testPrint(4);
	testPrint(2);
	testPrint(1);
	testPrint(5);
	testPrint(6);
	return 0;
}