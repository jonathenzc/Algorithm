#include <iostream>
#include <vector>

using namespace std;

vector<int> countBits(int num)
{
	vector<int> v;

	if (num >= 0)
	{
		v.push_back(0);
		for (int i = 1; i <= num; i++)
			v.push_back(v[i>>1] + (i&1)); //原数的位1个数 等于 该数左移1位后的个数 + 该位是否是1即可。注意操作符的执行顺序
	}

	return v;
}

int main()
{
	vector<int> v = countBits(5);

	for (int i = 0; i<v.size(); i++)
		cout << v[i] << " ";

	return 0;
}