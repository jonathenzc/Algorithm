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

		for (int i = 1; i < numRows; i++)//numRows行的内容
		{
			v.clear();
			for (int j = 0; j < i + 1; j++)//一行的内容
			{
				if (j == 0 || j == i)//矩阵的头尾皆为1
					v.push_back(1);
				else
					v.push_back(vSet[i-1][j-1]+vSet[i-1][j]);
			}
			vSet.push_back(v);
		}

		return vSet;
	}
}

vector<int> getRow(int rowIndex) 
{
	vector<int> now;
	vector<int> last;

	if (rowIndex+1 > 0)
	{
		now.push_back(1);

		for (int i = 1; i < rowIndex+1; i++)//numRows行的内容
		{
			last = now;
			now.clear();
			for (int j = 0; j < i + 1; j++)//一行的内容
			{
				if (j == 0 || j == i)//矩阵的头尾皆为1
					now.push_back(1);
				else
					now.push_back(last[j - 1] + last[j]);
			}
		}
	}

	return now;
}

int main()
{
	//vector<vector<int>> v = generate(5);

	//for (int i = 0; i < v.size(); i++)
	//{
	//	for (int j = 0; j < v[i].size(); j++)
	//		cout << v[i][j] << " ";

	//	cout << endl;
	//}

	vector<int> v = getRow(0);
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << " ";

	return 0;
}