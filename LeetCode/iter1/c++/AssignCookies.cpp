#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <queue>
#include <stack>

using namespace std;

class Solution {
public:
	int findContentChildren(vector<int>& g, vector<int>& s) {
		sort(g.begin(), g.end());
		sort(s.begin(), s.end());

		int gIndex = 0, sIndex = 0;
		int cnt = 0;
		
		while (gIndex < g.size() && sIndex < s.size())
		{
			if (g[gIndex] <= s[sIndex])
			{
				cnt++;
				gIndex++;
			}
				
			sIndex++;
		}

		return cnt;
	}
};

int main(void)
{
	Solution s;

	vector<int> g1;
	g1.push_back(1);
	g1.push_back(2);
	g1.push_back(3);

	vector<int> s1;
	s1.push_back(1);
	s1.push_back(1);

	cout << s.findContentChildren(g1, s1) << endl;

	vector<int> g2;
	g2.push_back(1);
	g2.push_back(2);

	vector<int> s2;
	s2.push_back(1);
	s2.push_back(2);
	s2.push_back(3);

	cout << s.findContentChildren(g2, s2) << endl;

	return 0;
}