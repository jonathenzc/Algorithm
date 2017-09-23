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
	vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
		//初始化图
		initGraph(numCourses, prerequisites);

		//将没有前置条件的课程塞入结果集合中
		vector<int> courseV;
		for (auto iter = vMap.begin(); iter != vMap.end(); iter++)
		{
			if (iter->second == 1)
				courseV.push_back(iter->first);
		}

		//取出入度为0的节点
		while (!zeroDegreeQ.empty())
		{
			int v = zeroDegreeQ.front();
			zeroDegreeQ.pop();

			courseV.push_back(v);

			//将v指向的节点的入度-1，同时更新入度为0的矩阵
			vector<int> vList = graph[v];
			for (int i = 0; i < vList.size(); i++)
			{
				int tmpDegree = inDegree[vList[i]];
				inDegree[vList[i]] = tmpDegree - 1;
				if (tmpDegree - 1 == 0)
					zeroDegreeQ.push(vList[i]);
			}
		}

		if (numCourses == courseV.size())
			return courseV;
		else
			return vector<int>();
	}
private:
	queue<int> zeroDegreeQ;
	unordered_map<int, int> vMap;
	unordered_map<int, int> inDegree;
	unordered_map<int, vector<int>> graph;
	int vCnt;

	//first <- second
	void initGraph(int numCourses, vector<pair<int,int>>& prerequisites) 
	{
		for (int i = 0; i < numCourses; i++)
			vMap[i] = 1;

		//构建邻接表的图
		for (int i = 0; i < prerequisites.size(); i++)
		{
			pair<int, int> edge = prerequisites[i];
			vMap[edge.first] = 0;
			vMap[edge.second] = 0;

			if (inDegree.find(edge.second) == inDegree.end())
				inDegree[edge.second] = 0;

			inDegree[edge.first]++;

			if (graph.find(edge.second) != graph.end())
				graph[edge.second].push_back(edge.first);
			else
			{
				vector<int> v;
				v.push_back(edge.first);
				graph[edge.second] = v;
			}
		}

		vCnt = 0;

		//寻找入度为0的节点
		unordered_map<int, int>::iterator inDegreeIter;
		for (inDegreeIter = inDegree.begin(); inDegreeIter != inDegree.end(); inDegreeIter++)
		{
			vCnt++;
			if (inDegreeIter->second == 0)
				zeroDegreeQ.push(inDegreeIter->first);
		}
	}
};

int main(void)
{
	Solution s;

	vector<pair<int, int>> prerequisites;
	pair<int, int> p1(1, 0);
	pair<int, int> p2(0, 2);

	prerequisites.push_back(p1);
	prerequisites.push_back(p2);

	//if (s.canFinish(2, prerequisites))
	//	cout << "Can finish\n";
	//else
	//	cout << "Can not finish\n";

	vector<int> ret = s.findOrder(4, prerequisites);
	for (int num : ret)
		cout << num << " ";


	return 0;
}