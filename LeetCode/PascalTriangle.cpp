#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> generate(int numRows) 
{
	vector<int> v;
	vector<vector<int>> vSet;

	if (numRows <= 0)
	{
		vSet.push_back(v);

		return vSet;
	}
	else
	{
		v.push_back(1);
		vSet.push_back(v);

		for (int i = 1; i < numRows; i++)//numRows�е�����
		{
			v.clear();
			for (int j = 0; j < i + 1; j++)//һ�е�����
			{
				if (j == 0 || j == i)//�����ͷβ��Ϊ1
					v.push_back(1);
				else
					v.push_back(vSet[i-1][j-1]+vSet[i-1][j]);
			}
			vSet.push_back(v);
		}

		return vSet;
	}
}

int main()
{
	vector<vector<int>> v = generate(5);

	for (int i = 0; i < v.size(); i++)
	{
		for (int j = 0; j < v[i].size(); j++)
			cout << v[i][j] << " ";

		cout << endl;
	}

	return 0;
}