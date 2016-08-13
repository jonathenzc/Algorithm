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

vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
	vector<Interval> ret;
	int index = 0;
	//先将newInterval左边的变量选出来
	while (index < intervals.size() && intervals[index].end < newInterval.start)
		ret.push_back(intervals[index++]);

	//合并中间有交集的区间
	while (index < intervals.size() && intervals[index].start <= newInterval.end)
	{
		newInterval.start = min(newInterval.start,intervals[index].start);
		newInterval.end = max(newInterval.end,intervals[index].end);
		index++;
	}

	ret.push_back(newInterval);

	//将剩下的区间压入容器中
	while (index < intervals.size())
		ret.push_back(intervals[index++]);


	return ret;
}

void testPrint(vector<Interval> v, Interval newInterval)
{
	auto retV = insert(v,newInterval);

	for (auto item : retV)
		cout << "[" << item.start << "," << item.end << "]  ";

	cout << endl;
}

int main()
{
	vector<Interval> v;

	Interval i1;
	i1.start = 1;
	i1.end = 2;

	Interval i2;
	i2.start = 3;
	i2.end = 5;

	Interval i3;
	i3.start = 6;
	i3.end = 7;

	Interval i4;
	i4.start = 8;
	i4.end = 10;

	Interval i5;
	i5.start = 12;
	i5.end = 16;


	v.push_back(i1);
	v.push_back(i2);
	v.push_back(i3);
	v.push_back(i4);
	v.push_back(i5);

	Interval newInterval;
	newInterval.start = 4;
	newInterval.end = 9;

	testPrint(v,newInterval);

	return 0;
}