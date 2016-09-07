#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <sstream>
#include <unordered_map>

using namespace std;

class Solution {
public:

	vector<vector<int>> combine(int n, int k) {

		vector<int> curV;

		helper(1, curV, n, k);

		return v;
	}

private:
	vector<vector<int>> v;

	void helper(int index, vector<int> curV, int n, int k) {
		if (curV.size() == k)
			v.push_back(curV);
		else {
			for (int i = index; i <= n; i++)
			{
				if (curV.size()<=k) {
					curV.push_back(i);
					helper(i + 1, curV, n, k);
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

	vector<vector<int>> retV = s.combine(4, 2);
	for (auto tmpV : retV) {
		for (int num : tmpV)
			cout << num << " ";

		cout << endl;
	}

	return 0;
}