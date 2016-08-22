#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxEnvelopes(vector<pair<int, int>>& envelopes) {
	sort(envelopes.begin(), envelopes.end(), [](pair<int, int> p1, pair<int, int> p2) {return p1.first < p2.first; });

	vector<int> dp(envelopes.size(),1);

	int maxCnt = 0;

	for (int i = 0; i < envelopes.size(); i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (envelopes[i].second > envelopes[j].second && envelopes[i].first > envelopes[j].first)
				dp[i] = max(dp[i], dp[j] + 1);
		}

		maxCnt = max(maxCnt,dp[i]);
	}

	return maxCnt;
}

int main()
{
	pair<int, int> p1(5,4);
	pair<int, int> p2(6, 4);
	pair<int, int> p3(6, 7);
	pair<int, int> p4(2, 3);

	vector<pair<int, int>> v;
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);

	cout << maxEnvelopes(v)<<endl;

	//[[4,5],[4,6],[6,7],[2,3],[1,1]]
	pair<int, int> p11(4, 5);
	pair<int, int> p12(4, 6);
	pair<int, int> p13(6, 7);
	pair<int, int> p14(2, 3);
	pair<int, int> p15(1, 1);

	vector<pair<int, int>> v1;
	v1.push_back(p11);
	v1.push_back(p12);
	v1.push_back(p13);
	v1.push_back(p14);
	v1.push_back(p15);

	cout << maxEnvelopes(v1) << endl;


	return 0;
}