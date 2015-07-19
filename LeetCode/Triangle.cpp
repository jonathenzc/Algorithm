#include <iostream>
#include <vector>

using namespace std;

int min(int a, int b)
{
	if (a < b)
		return a;
	else
		return b;
}

int minimumTotal(vector<vector<int>>& triangle) {
	//´ÓÏÂÍùÉÏÕÒ
	for (int i = triangle.size()-2; i >= 0; i--)
	{
		for (int j = 0; j < triangle[i].size(); j++)
		{
			int temp = triangle[i][j] + min(triangle[i+1][j],triangle[i+1][j+1]);
			triangle[i][j] = temp;
		}
	}

	return triangle[0][0];
}

int main()
{
	vector<vector<int>> v;
	vector<int> v1;
	v1.push_back(2);
	v.push_back(v1);

	vector<int> v2;
	v2.push_back(3);
	v2.push_back(4);
	v.push_back(v2);

	vector<int> v3;
	v3.push_back(6);
	v3.push_back(5);
	v3.push_back(7);
	v.push_back(v3);
	
	vector<int> v4;
	v4.push_back(4);
	v4.push_back(1);
	v4.push_back(8);
	v4.push_back(3);
	v.push_back(v4);

	cout << minimumTotal(v);

	return 0;
}
