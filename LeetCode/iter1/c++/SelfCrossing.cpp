#include <iostream>
#include <string>
#include <vector>

using namespace std;

//判断当前位移距离在由4个位移距离组成的方格中是否穿过
//cur表示当前向某个方向位移的距离，before1表示cur前1个方向的距离，before2表示cur前2个方向的距离，before3表示cur前3个方向的距离
bool isCrossHelper(int cur,int before1,int before2,int before3)
{
	//cur与它平行的位移距离比较，即before2
	if (cur < before2) 
		return false;
	else
	{
		if (before1 > before3)
			return false;
		else
			return true;
	}
}

bool isSelfCrossing(vector<int>& x) {
	int xSize = x.size();

	if (xSize < 4)
		return false;

	bool result = false;

	for (int i = 3; i < x.size(); i++)
	{
		if (isCrossHelper(x[i],x[i-1],x[i-2],x[i-3]))
		{
			result = true;
			break;
		}

		if (i > 3)
		{
			if (x[i] + x[i - 4] >= x[i - 2] && x[i-1] == x[i-3]) //平行且相交
			{
				result = true;
				break;
			}
		}

		if (i > 4)
		{
			if (x[i] <= x[i - 2] && x[i-4] <= x[i-2] && 
				x[i-5] <= x[i-3] && x[i - 1] <= x[i - 3]) //对接的情况
			{
				if ((x[i] + x[i-4]) >= x[i-2] && (x[i-1] +x[i-5]) >= x[i-3])
				{
					result = true;
					break;
				}
			}
		}
	}

	return result;
}

void testPrint(vector<int> v)
{
	if (isSelfCrossing(v))
		cout << "Yes\n";
	else
		cout << "No\n";
}

int main()
{
	vector<int> v;
	v.push_back(2);
	v.push_back(1);
	v.push_back(1);
	v.push_back(2);

	testPrint(v);


	vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);

	testPrint(v1);

	vector<int> v2;
	v2.push_back(1);
	v2.push_back(1);
	v2.push_back(1);
	v2.push_back(1);

	testPrint(v2);


	vector<int> v3;
	v3.push_back(0);
	v3.push_back(0);
	v3.push_back(0);
	v3.push_back(0);

	testPrint(v3);

	vector<int> v4;
	v4.push_back(1);
	v4.push_back(1);
	v4.push_back(3);
	v4.push_back(1);
	v4.push_back(1);

	testPrint(v4);


	vector<int> v5;
	v5.push_back(3);
	v5.push_back(3);
	v5.push_back(4);
	v5.push_back(2);
	v5.push_back(2);

	testPrint(v5);

	vector<int> v6;
	v6.push_back(1);
	v6.push_back(1);
	v6.push_back(2);
	v6.push_back(2);
	v6.push_back(1);
	v6.push_back(1);

	testPrint(v6);

	vector<int> v7;
	v7.push_back(3);
	v7.push_back(3);
	v7.push_back(3);
	v7.push_back(2);
	v7.push_back(1);
	v7.push_back(1);

	testPrint(v7);

	return 0;
}
