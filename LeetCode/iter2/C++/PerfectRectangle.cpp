#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

//顶点map 1
unordered_map<string, int> vertexMap;

//边map 2
unordered_map<string, int> edgeMap;

//中间map 2或4
unordered_map<string, int> insideMap;

int area(vector<int> v)
{
	return (v[2]-v[0])*(v[3]-v[1]);
}

vector<int> getPerfectRect(vector<vector<int>> rectangles, int &sum)
{
	vector<int> retV(4,0);

	int maxSum = INT_MIN, minSum = INT_MAX;

	for (auto v:rectangles)
	{
		sum += area(v);

		if (v[0] + v[1] < minSum) {
			retV[0] = v[0];
			retV[1] = v[1];
			minSum = v[0] + v[1];
		}

		if (v[2] + v[3] > maxSum) {
			retV[2] = v[2];
			retV[3] = v[3];
			maxSum = v[2] + v[3];
		}
	}

	return retV;
}

void getRecPointPos(int x, int y,vector<int> perfectRec)
{
	int intersecCnt = 0;
	if (x == perfectRec[0] || x == perfectRec[2])
		intersecCnt++;

	if (y == perfectRec[1] || y == perfectRec[3])
		intersecCnt++;

	string s = to_string(x) + " " + to_string(y);

	if (intersecCnt == 2)
		vertexMap[s]++;
	else if (intersecCnt == 1)
		edgeMap[s]++;
	else
		insideMap[s]++;
}

bool isRectangleCover(vector<vector<int>>& rectangles) {
	if (rectangles.size() <= 1)
		return true;

	int sumArea = 0;
	vector<int> perfectRect = getPerfectRect(rectangles,sumArea);

	if (area(perfectRect) != sumArea)
		return false;


	for (auto v : rectangles)
	{
		//统计顶点、边、中间
		getRecPointPos(v[0], v[1],perfectRect);
		getRecPointPos(v[0], v[3], perfectRect);
		getRecPointPos(v[2], v[1], perfectRect);
		getRecPointPos(v[2], v[3], perfectRect);
	}

	for (auto iter = vertexMap.begin(); iter != vertexMap.end(); iter++)
	{
		if (iter->second != 1)
			return false;
	}

	for (auto iter = edgeMap.begin(); iter != edgeMap.end(); iter++)
	{
		if (iter->second != 2)
			return false;
	}

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