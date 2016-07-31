#include <iostream>
#include <vector>

using namespace std;

void helper(int index, int sum,int target, vector<int>& candidates, vector<int> &curV,vector<vector<int>> &v)
{
	if (sum == target)
	{
		v.push_back(curV);
	}
	else
	{
		for (int i = index; i < candidates.size(); i++)
		{
			if (sum + candidates[i] <= target)
			{
				curV.push_back(candidates[i]);

				helper(i,sum + candidates[i], target, candidates, curV, v);
				
				curV.pop_back();
			}
		}
	}
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
	vector<vector<int>> v;

	vector<int> tmpV;

	helper(0,0,target, candidates,tmpV,v);

	return v;
}

void testPrint(vector<int> &candidates,int target)
{
	vector<vector<int>> v = combinationSum(candidates,target);
	for (int i = 0; i < v.size(); i++)
	{
		for (int j = 0; j < v[i].size();j++)
			cout << v[i][j] << " ";


		cout << endl;
	}

	cout << endl;
}


int main()
{
	vector<int> v;
	v.push_back(2);
	v.push_back(3);
	v.push_back(6);
	v.push_back(7);

	testPrint(v,7);

	return 0;
}