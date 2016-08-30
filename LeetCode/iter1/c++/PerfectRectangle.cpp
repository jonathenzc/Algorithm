#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<string, int> vertexMap;
unordered_map<string, int> edgeMap;
unordered_map<string, int> insideMap;

//返回小矩形各个顶点的位置,recV为大矩形的坐标
void getRecVertexPos(int x, int y, vector<int> recV)
{
	int cnt = 0;
	if (x == recV[0] || x == recV[2])
		cnt++;

	if (y == recV[1] || y == recV[3])
		cnt++;

	string s = to_string(x) + " " + to_string(y);
	if (cnt == 0) //INSIDE
		insideMap[s]++;
	else if (cnt == 1) //EDGE
		edgeMap[s]++;
	else if (cnt == 2) //VERTEX
		vertexMap[s]++;
}

//计算矩形面积
int area(vector<int> v)
{	
	return (v[2]-v[0])*(v[3]-v[1]);
}

//获取大矩形的坐标
vector<int> getRectBoarderPos(vector<vector<int>> rectangles, int &sumSquare)
{
	int minBoarder = INT_MAX, maxBoarder = INT_MIN;
	int minX, minY, maxX, maxY;
	vector<int> v;

	for (auto rec : rectangles)
	{
		if (rec[0] + rec[1] < minBoarder)
		{
			minBoarder = rec[0] + rec[1];
			minX = rec[0];
			minY = rec[1];
		}

		if (rec[2] + rec[3] > maxBoarder)
		{
			maxBoarder = rec[2] + rec[3];
			maxX = rec[2];
			maxY = rec[3];
		}

		sumSquare += area(rec);
	}

	v.push_back(minX);
	v.push_back(minY);
	v.push_back(maxX);
	v.push_back(maxY);

	return v;
}

bool isRectangleCover(vector<vector<int>>& rectangles) {
	if (rectangles.size() <= 1)
		return true;

	//先根据所有小矩形面积之和是否等于大矩形面积来筛选
	//获取大矩形的左下和右上坐标
	int sumSquare = 0;
	vector<int> outerRect = getRectBoarderPos(rectangles,sumSquare);

	if (area(outerRect) != sumSquare)
		return false;

	//再根据（1）在大矩形的顶角的点只属于1个小矩形，（2）在大矩形的边上的点属于2个矩形，（3）在大矩形的内部的点属于2个或者4个矩形

	
	for (auto rec : rectangles)
	{
		//左下
		getRecVertexPos(rec[0],rec[1],outerRect);

		//左上
		getRecVertexPos(rec[0], rec[3], outerRect);

		//右下
		getRecVertexPos(rec[2], rec[1], outerRect);

		//右上
		getRecVertexPos(rec[2], rec[3], outerRect);
	}

	//遍历3个记录顶点位置的map
	//vertex
	for (auto iter = vertexMap.begin(); iter != vertexMap.end(); iter++)
	{
		if (iter->second != 1)
			return false;
	}

	//edge
	for (auto iter = edgeMap.begin(); iter != edgeMap.end(); iter++)
	{
		if (iter->second != 2)
			return false;
	}

	//inside
	for (auto iter = insideMap.begin(); iter != insideMap.end(); iter++)
	{
		if (iter->second != 2 && iter->second != 4)
			return false;
	}

	return true;
}

int main()
{
	vector<vector<int>> v;
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(3);

	vector<int> v2;
	v2.push_back(3);
	v2.push_back(1);
	v2.push_back(4);
	v2.push_back(2);

	vector<int> v3;
	v3.push_back(3);
	v3.push_back(2);
	v3.push_back(4);
	v3.push_back(4);

	vector<int> v4;
	v4.push_back(1);
	v4.push_back(3);
	v4.push_back(2);
	v4.push_back(4);

	vector<int> v5;
	v5.push_back(2);
	v5.push_back(3);
	v5.push_back(3);
	v5.push_back(4);

	v.push_back(v1);
	v.push_back(v2);
	v.push_back(v3);
	v.push_back(v4);
	//v.push_back(v5);

	if (isRectangleCover(v))
		cout << "Yes\n";
	else
		cout << "No\n";
}