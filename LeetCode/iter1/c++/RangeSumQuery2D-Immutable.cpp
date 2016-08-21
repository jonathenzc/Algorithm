#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

class NumMatrix {
public:
	NumMatrix(vector<vector<int>> &matrix) {
		int n = matrix.size();
		int m = 0;
		if (n > 0)
		{
			m = matrix[0].size();
			dp = new int*[n];
			for (int i = 0; i < n; i++)
				dp[i] = new int[m];

			dp[0][0] = matrix[0][0];

			for (int i = 1; i < n; i++)
				dp[i][0] = dp[i-1][0]+matrix[i][0];

			for (int i = 1; i < m; i++)
				dp[0][i] = dp[0][i-1]+matrix[0][i];

			for (int i = 1; i < n; i++)
			{
				for (int j = 1; j < m; j++)
				{
					dp[i][j] = dp[i-1][j]+dp[i][j-1]+matrix[i][j]-dp[i-1][j-1];
				}
			}
		}
	}

	int sumRegion(int row1, int col1, int row2, int col2) {



		int ret = dp[row2][col2];
		if (col1 >= 1)
			ret -= dp[row2][col1-1];

		if (row1 >= 1)
			ret -= dp[row1-1][col2];

		if (row1 >= 1 && col1 >= 1)
			ret += dp[row1 - 1][col1-1];
		
		return ret;
	}
private:
	int **dp;
};


int main()
{
	vector<vector<int>> v;

	vector<int> v1;
	v1.push_back(3);
	v1.push_back(0);
	v1.push_back(1);
	v1.push_back(4);
	v1.push_back(2);


	vector<int> v2;
	v2.push_back(5);
	v2.push_back(6);
	v2.push_back(3);
	v2.push_back(2);
	v2.push_back(1);

	vector<int> v3;
	v3.push_back(1);
	v3.push_back(2);
	v3.push_back(0);
	v3.push_back(1);
	v3.push_back(5);

	vector<int> v4;
	v4.push_back(4);
	v4.push_back(1);
	v4.push_back(0);
	v4.push_back(1);
	v4.push_back(7);

	vector<int> v5;
	v5.push_back(1);
	v5.push_back(0);
	v5.push_back(3);
	v5.push_back(0);
	v5.push_back(5);

	v.push_back(v1);
	v.push_back(v2);
	v.push_back(v3);
	v.push_back(v4);
	v.push_back(v5);

	NumMatrix nm(v);

	cout << nm.sumRegion(2,1,4,3) << endl;
	cout << nm.sumRegion(1, 1, 2, 2) << endl;
	cout << nm.sumRegion(1, 2, 2, 4) << endl;
	cout << nm.sumRegion(2, 2, 2, 2) << endl;
	cout << nm.sumRegion(1, 1, 1, 1) << endl;
	cout << nm.sumRegion(4, 4, 4, 4) << endl;

	return 0;
}