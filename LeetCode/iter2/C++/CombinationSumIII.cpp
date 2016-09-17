#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <sstream>
#include <unordered_map>

using namespace std;

class Solution {
public:

	vector<vector<int>> combinationSum3(int k, int n) {

		vector<int> curV;

		helper(1,0,curV,k,n);

		return v;
	}

private:
	vector<vector<int>> v;

	void helper(int index,int sum, vector<int> curV, int k, int target) {
		if (curV.size() <= k) {
			if (sum == target && curV.size() == k)
				v.push_back(curV);
			else {
				for (int i = index; i <= 9; i++)
				{
					if (sum + i <= target) {
						curV.push_back(i);
						helper(i + 1, sum + i, curV, k, target);
						curV.pop_back();
					}
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

	vector<vector<int>> retV = s.combinationSum3(3,9);
	for (auto tmpV : retV) {
		for (int num : tmpV)
			cout << num << " ";

		cout << endl;
	}

	return 0;
}