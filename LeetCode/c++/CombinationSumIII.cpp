#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void helper(int index, int sum, int cnt,int target, vector<int>& candidates, vector<int> &curV, vector<vector<int>> &v)
{
	if (sum == target)
	{
		if(curV.size() == cnt)
			v.push_back(curV);
	}
	else
	{
		for (int i = index + 1; i < candidates.size(); i++)
		{
			if (sum + candidates[i] <= target)
			{
				curV.push_back(candidates[i]);
				helper(i, sum + candidates[i], cnt,target, candidates, curV, v);
				curV.pop_back();
			}
		}
	}
}

vector<vector<int>> combinationSum3(int k, int n) {
	vector<vector<int>> v;

	vector<int> candidates;
	for(int i=1;i<10;i++)
		candidates.push_back(i);

	vector<int> tmpV;

	helper(-1, 0, k,n, candidates, tmpV, v);

	return v;
}

void testPrint(int k, int n)
{
	cout << "k " << k << " n " << n << endl;
	vector<vector<int>> combinationV = combinationSum3(k, n);

	for (auto tmpV : combinationV)
	{
		for (auto num : tmpV)
			cout << num << " ";

		cout << endl;
	}

	cout << endl;
}

int main()
{
	testPrint(3, 7);
	testPrint(3, 9);

	return 0;
}