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
		
		//使用map来记录每个点与其他点的距离
		for (auto point : points)
		{
			unordered_map<int, int> distanceMap;
			for (auto anotherPoint : points)
			{
				int pointDis = distance(point,anotherPoint);
				distanceMap[pointDis]++;
			}

			for (auto iter : distanceMap)
			{
				if(iter.second > 1)
					cnt += iter.second*(iter.second - 1);
			}
		}

		return cnt;
	}
private:
	int distance(pair<int, int>p1, pair<int, int>p2)
	{
		return (p1.first - p2.first)*(p1.first - p2.first) + (p1.second - p2.second)*(p1.second - p2.second);
	}
};

int main(void)
{
	vector<pair<int, int>> v;
	v.push_back(pair<int,int>(0,0));
	v.push_back(pair<int, int>(1, 0));
	v.push_back(pair<int, int>(2, 0));
	v.push_back(pair<int, int>(1, -1));

	Solution s;
	cout << s.numberOfBoomerangs(v) << endl;

	 
	return 0;
}