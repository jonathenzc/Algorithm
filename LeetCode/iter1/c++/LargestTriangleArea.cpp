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
	double largestTriangleArea(vector<vector<int>>& points) {
		if (points.size() < 3) return 0;

		maxArea = 0;
		for (int i = 0; i < points.size(); i++) {
			for (int j = 1; j < points.size(); j++) {
				double a = pointDis(points[i], points[j]);
				for (int k = 2; k < points.size(); k++) {
					double b = pointDis(points[i], points[k]);
					double c = pointDis(points[j], points[k]);
					maxArea = max(maxArea, helenTriangleArea(a, b, c));
				}
			}
		}

		return maxArea;
	}
private:
	double maxArea;

	//S = sqrt(p(p-a)(p-b)(p-c)),p=(a+b+c)/2
	double helenTriangleArea(double a, double b, double c) {
		double p = (a + b + c) / 2;
		return sqrt(p*(p - a)*(p - b)*(p - c));
	}

	double pointDis(vector<int> a, vector<int> b) {
		int squareSum = (a[0] - b[0]) * (a[0] - b[0]) + (a[1] - b[1]) * (a[1] - b[1]);
		return sqrt(squareSum);
	}
};

int main(void)
{
	vector<int> v1;
	v1.push_back(0);
	v1.push_back(0);

	vector<int> v2;
	v2.push_back(0);
	v2.push_back(1);

	vector<int> v3;
	v3.push_back(1);
	v3.push_back(0);

	vector<int> v4;
	v4.push_back(0);
	v4.push_back(2);

	vector<int> v5;
	v5.push_back(2);
	v5.push_back(0);

	vector<vector<int>> v;
	v.push_back(v1);
	v.push_back(v2);
	v.push_back(v3);
	v.push_back(v4);
	v.push_back(v5);

	Solution s;
	cout << s.largestTriangleArea(v) << endl;

	return 0;
}