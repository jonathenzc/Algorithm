#include <iostream>
#include <vector>

using namespace std;

vector<int> grayCode(int n) 
{
	vector<int> v;
	v.push_back(0);

	if (n == 0)
		return v;

	v.push_back(1);

	for (int i = 1; i < n; i++)
	{
		//计算要加的2次幂数
		int addition = 1;
		int cnt = 0;
		while (cnt < i)
		{
			addition *= 2;
			cnt++;
		}

		//从容器开始计算格雷码
		int nextGrayCode;
		for (int j = addition - 1; j >= 0; j--) //从2次幂到0加上addition
		{
			nextGrayCode = v[j] + addition;
			v.push_back(nextGrayCode);
		}
	}

	return v;
}

int main()
{
	vector<int> v;
	v = grayCode(0);
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << " ";

	return 0;
}