#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int kthSmallest(vector<vector<int>>& matrix, int k) {
	int n = matrix[0].size();
	int left = matrix[0][0], right = matrix[n - 1][n - 1];
	int mid = 0;

	while (left < right)
	{
		mid = (left + right) >> 1;
		//统计小于等于mid的个数
		int num = 0;
		for (int i = 0; i < n; i++)
		{
			int cnt = upper_bound(matrix[i].begin(),matrix[i].end(),mid) - matrix[i].begin();
			num += cnt;
		}

		if (num < k)
			left = mid + 1;
		else
			right = mid;
	}

	return left;
}

int main()
{
	vector<vector<int>> v;

	vector<int> v1;
	v1.push_back(1);
	v1.push_back(5);
	v1.push_back(9);

	vector<int> v2;
	v2.push_back(10);
	v2.push_back(11);
	v2.push_back(13);

	vector<int> v3;
	v3.push_back(12);
	v3.push_back(13);
	v3.push_back(15);

	v.push_back(v1);
	v.push_back(v2);
	v.push_back(v3);

	for (int i = 1; i <= 9; i++)
		cout << kthSmallest(v,i)<<" ";

	return 0;
}