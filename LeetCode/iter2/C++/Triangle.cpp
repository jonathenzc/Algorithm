#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int minimumTotal(vector<vector<int>>& triangle) {
	if (triangle.size() == 0)
		return 0;
	else if (triangle.size() == 1)
		return triangle[0][0];

	int height = triangle.size();
	for (int i = 1; i < height; i++)
	{
		for (int j = 0; j < triangle[i].size(); j++)
		{
			int left = INT_MAX, right = INT_MAX;
			if (j - 1 >= 0)
				left = triangle[i - 1][j - 1];
			if (j <= triangle[i - 1].size() - 1)
				right = triangle[i - 1][j];

			triangle[i][j] = min(left, right) + triangle[i][j];

		}
	}

	int minSum = INT_MAX;
	
	int n = triangle[height - 1].size();
	for (int i = 0; i < n; i++)
	{
		if (triangle[height-1][i] < minSum)
			minSum = triangle[height-1][i];
	}

	return minSum;
}

int main()
{
	vector<vector<int>> v;

	vector<int> v1;
	v1.push_back(2);

	vector<int> v2;
	v2.push_back(3);
	v2.push_back(4);

	vector<int> v3;
	v3.push_back(6);
	v3.push_back(5);
	v3.push_back(7);

	vector<int> v4;
	v4.push_back(4);
	v4.push_back(1);
	v4.push_back(8);
	v4.push_back(3);

	v.push_back(v1);
	v.push_back(v2);
	v.push_back(v3);
	v.push_back(v4);

	cout << minimumTotal(v)<<endl;

	return 0;
}