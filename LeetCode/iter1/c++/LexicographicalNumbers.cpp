#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

void helper(int start, int end, vector<int> &v)
{
	if (start <= end)
	{
		v.push_back(start);
		helper(start*10, end, v);
		if (start+1 <= (start / 10) * 10 + 9)
			helper(start+1,end,v);
	}
}

vector<int> lexicalOrder(int n) {
	vector<int> v;

	helper(1, n, v);

	return v;
}

void testPrint(int n)
{
	auto v = lexicalOrder(n);
	cout << v.size() << endl;

	for (int i = 0; i < v.size(); i++)
		cout << v[i] << " ";
}

int main()
{
	testPrint(113);
		
	return 0;
}