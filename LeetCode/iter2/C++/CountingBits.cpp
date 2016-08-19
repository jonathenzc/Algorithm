#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

vector<int> countBits(int num) {
	vector<int> v(num+1,0);

	int twoPower = 1;
	for (int i = 1; i <= num; i++)
	{
		if ((i & (i - 1)) == 0) //2^n
			twoPower = i;

		v[i] = v[i-twoPower] + 1;
	}

	return v;
}

int main()
{
	vector<int> v = countBits(16);
	for (int i = 0; i < v.size();i++)
		cout << v[i] << " ";

	return 0;
}