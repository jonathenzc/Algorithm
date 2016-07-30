#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void helper(int index,int sum,int target, vector<int>& candidates, vector<int> &curV,vector<vector<int>> &v)
{
	if (sum == target)
		v.push_back(curV);
	else
	{
		for (int i = index + 1; i < candidates.size(); i++)
		{
			if (i == index + 1 || i > 0 && candidates[i - 1] != candidates[i])
			{

				if (sum + candidates[i] <= target)
				{
					curV.push_back(candidates[i]);
					helper(i, sum + candidates[i], target, candidates, curV, v);
					curV.pop_back();
				}
			}
		}
	}  
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
	vector<vector<int>> v;
	vector<int> tmpV;

	sort(candidates.begin(),candidates.end());

	helper(-1,0,target, candidates,tmpV, v);

	return v;
}

void testPrint(vector<int> v,int target)
{
	vector<vector<int>> combinationV = combinationSum2(v,target);

	for (auto tmpV : combinationV)
	{
		for (auto num:tmpV)
			cout << num << " ";

		cout << endl;
	}

	cout << endl;
}

int main()
{
	//vector<int> v;
	//v.push_back(10);
	//v.push_back(1);
	//v.push_back(2);
	//v.push_back(7);
	//v.push_back(6);
	//v.push_back(1);
	//v.push_back(5);

	//testPrint(v,8);

	vector<int> v;
	v.push_back(1);
	v.push_back(1);
	v.push_back(1);
	v.push_back(2);

	testPrint(v,3);

	return 0;
}