#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maximalSquare(vector<vector<char>>& matrix) {
	if (matrix.size() == 0)
		return 0;

	int maxS = 0;

	vector<vector<int>> v(matrix.size(),vector<int>(matrix[0].size(),0));

	for (int i = 0; i < matrix.size(); i++)
	{
		if (matrix[i][0] == '1')
		{
			v[i][0] = 1;
			maxS = 1;
		}
	}

	for (int i = 0; i < matrix[0].size(); i++)
	{
		if (matrix[0][i] == '1')
		{
			v[0][i] = 1;
			maxS = 1;
		}
	}


	for (int i = 1; i < matrix.size(); i++)
	{
		for (int j = 1; j < matrix[0].size(); j++)
		{
			if (matrix[i][j] != '0')
				v[i][j] = min(min(v[i-1][j],v[i][j-1]),v[i-1][j-1])+1;

			maxS = max(maxS,v[i][j]);
		}
	}

	return maxS*maxS;
}

int main()
{
	vector<vector<char>> v;

	//vector<char> v1;
	//v1.push_back('1');
	//v1.push_back('0');
	//v1.push_back('1');
	//v1.push_back('0');
	//v1.push_back('0');

	//vector<char> v2;
	//v2.push_back('1');
	//v2.push_back('0');
	//v2.push_back('1');
	//v2.push_back('1');
	//v2.push_back('1');

	//vector<char> v3;
	//v3.push_back('1');
	//v3.push_back('1');
	//v3.push_back('1');
	//v3.push_back('1');
	//v3.push_back('1');

	//vector<char> v4;
	//v4.push_back('1');
	//v4.push_back('0');
	//v4.push_back('1');
	//v4.push_back('1');
	//v4.push_back('0');

	vector<char> v1;
	v1.push_back('0');
	v1.push_back('0');
	v1.push_back('0');
	v1.push_back('1');

	vector<char> v2;
	v2.push_back('1');
	v2.push_back('1');
	v2.push_back('0');
	v2.push_back('1');

	vector<char> v3;
	v3.push_back('1');
	v3.push_back('1');
	v3.push_back('1');
	v3.push_back('1');

	vector<char> v4;
	v4.push_back('0');
	v4.push_back('1');
	v4.push_back('1');
	v4.push_back('1');

	vector<char> v5;
	v5.push_back('0');
	v5.push_back('1');
	v5.push_back('1');
	v5.push_back('1');

	v.push_back(v1);
	v.push_back(v2);
	v.push_back(v3);
	v.push_back(v4);
	v.push_back(v5);

	cout << maximalSquare(v);




	return 0;
}