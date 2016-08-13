#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}	
};

vector<Interval> merge(vector<Interval>& intervals) {
	sort(intervals.begin(), intervals.end(), [](Interval a, Interval b) { return a.start < b.start; });
	vector<Interval> ret;

	for (auto interval : intervals)
	{
		if (ret.empty() || interval.start > ret.back().end)
			ret.push_back(interval);
		else
			ret.back().end = max(interval.end,ret.back().end);
	}

	return ret;
}

void testPrint(vector<Interval> v)
{
	auto retV = merge(v);

	for (auto item : retV)
		cout << "[" << item.start << "," << item.end << "] ";

	cout << endl;
}

int main()
{
	vector<Interval> v;

	Interval i1;
	i1.start = 1;
	i1.end = 3;

	Interval i2;
	i2.start = 2;
	i2.end = 6;

	Interval i3;
	i3.start = 8;
	i3.end = 10;

	Interval i4;
	i4.start = 15;
	i4.end = 18;


	v.push_back(i1);
	v.push_back(i2);
	v.push_back(i3);
	v.push_back(i4);

	testPrint(v);

	return 0;
}