#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <sstream>
#include <unordered_map>

using namespace std;

class Solution {
public:

	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		sort(candidates.begin(),candidates.end());
		
		vector<int> curV;

		helper(0,0,curV,candidates,target);

		return v;
	}

private:
	vector<vector<int>> v;

	void helper(int index,int sum, vector<int> curV, vector<int> candidates,int target) {
		if (sum == target)
			v.push_back(curV);
		else{
			for (int i = index; i < candidates.size(); i++)
			{
				if (sum + candidates[i] <= target &&  (i == index || candidates[i] != candidates[i-1])) {
					curV.push_back(candidates[i]);
					helper(i+1, sum + candidates[i], curV, candidates, target);
					curV.pop_back();
				}
			}
		}
	}
};

int main()
{
	Solution s;

	vector<int> v;
	v.push_back(10);
	v.push_back(1);
	v.push_back(2);
	v.push_back(7);
	v.push_back(6);
	v.push_back(1);
	v.push_back(5);

	vector<vector<int>> retV = s.combinationSum2(v,8);
	for (auto tmpV : retV) {
		for (int num : tmpV)
			cout << num << " ";

		cout << endl;
	}

	return 0;
}