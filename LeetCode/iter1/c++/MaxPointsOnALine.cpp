#include <iostream>
#include <map>
#include <vector>

using namespace std;

struct Point {
	int x;
	int y;
	Point() : x(0), y(0) {}
	Point(int a, int b) : x(a), y(b) {}
};

double slopeRatio(Point a, Point b)
{
	if (a.y == b.y)
		return 0;

	if (a.x == b.x)
		return INT_MAX;

	return double(a.y - b.y) / double(a.x - b.x);
}

int maxPoints(vector<Point>& points) {
	if (points.size() == 0)
		return 0;

	if (points.size() == 1)
		return 1;

	int max = 0;

	map<double, int> m;

	for (int i = 0; i < points.size(); i++)
	{
		m.clear(); //关键
		int duplicate = 0;
		m[0] = 1;//相同两点的斜率
		for (int j = 0; j < points.size(); j++)
		{
			if (i != j)
			{
				if (points[i].x == points[j].x && points[i].y == points[j].y)
					duplicate++;
				else
				{
					double slope = slopeRatio(points[i], points[j]);

					if (m.find(slope) == m.end())
					{
						m.insert(map<double, int>::value_type(slope, 2));
					}
					else
					{
						m[slope]++;
					}
				}
			}
		}

		map<double, int>::iterator iter;
		for (iter = m.begin(); iter != m.end(); iter++)
		{
			if (max < iter->second + duplicate)
				max = iter->second + duplicate;
		}
	}

	return max;
}

int main()
{
	//Point p1 = Point(0,-12);
	//Point p2 = Point(5, 2);
	//Point p3 = Point(2, 5);
	//Point p4 = Point(0, -5);
	//Point p5 = Point(1, 5);
	//Point p6 = Point(2, -2);
	//Point p7 = Point(5, -4);
	//Point p8 = Point(3, 4);
	//Point p9 = Point(-2, 4);
	//Point p10 = Point(-1, 4);
	//Point p11 = Point(0, -5);
	//Point p12 = Point(0, -8);
	//Point p13 = Point(-2, -1);
	//Point p14 = Point(0, -11);
	//Point p15 = Point(0, -9);

	//vector<Point> v;
	//v.push_back(p1);
	//v.push_back(p2);
	//v.push_back(p3);
	//v.push_back(p4);
	//v.push_back(p5);
	//v.push_back(p6);
	//v.push_back(p7);
	//v.push_back(p8);
	//v.push_back(p9);
	//v.push_back(p10);
	//v.push_back(p11);
	//v.push_back(p12);
	//v.push_back(p13);
	//v.push_back(p14);
	//v.push_back(p15);

	Point p1 = Point(1,1);
	Point p2 = Point(2, 2);
	Point p3 = Point(3, 3);
	Point p4 = Point(4, 4);
	Point p5 = Point(8, 8);

	vector<Point> v;

	v.push_back(p4);
	v.push_back(p5);
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);

	//Point p1 = Point(1, 1);
	//Point p2 = Point(1, 1);
	//Point p3 = Point(2, 2);
	//Point p4 = Point(2, 2);
	//Point p5 = Point(1, 1);
	//Point p6 = Point(1, 1);
	//
	//vector<Point> v;

	//v.push_back(p1);
	//v.push_back(p2);
	//v.push_back(p3);
	//v.push_back(p4);
	//v.push_back(p5);
	//v.push_back(p6);

	cout << maxPoints(v);

	return 0;
}