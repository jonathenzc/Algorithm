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
	int numberOfBoomerangs(vector<pair<int, int>>& points) {
		int cnt = 0;
		for (int i = 0; i < points.size();i++)
		{
			unordered_map<int, int> distance_map;
			for (int j = 0; j < points.size(); j++)
			{
				int pair_distance = distance(points[i], points[j]);
				distance_map[pair_distance]++;
			}

			for (auto iter : distance_map)
			{
				int distanceCnt = iter.second;
				cnt += distanceCnt*(distanceCnt-1);
			}
		}

		return cnt;
	}
private:
	int distance(pair<int, int> v1, pair<int, int> v2) {
		int firstDiff = v1.first - v2.first;
		int secondDiff = v1.second - v2.second;

		return firstDiff * firstDiff + secondDiff * secondDiff;
	}
};

int main(void)
{
	Solution s;

	pair<int, int> p1(0, 0);
	pair<int, int> p2(1, 0);
	pair<int, int> p3(-1, 0);
	pair<int, int> p4(0, 1);
	pair<int, int> p5(0, -1);

	vector<pair<int, int>> v;
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	v.push_back(p5);

	cout << s.numberOfBoomerangs(v) << endl;

	return 0;
}