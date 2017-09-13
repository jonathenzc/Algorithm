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
	bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
		//初始化图
		initGraph(prerequisites);

		//取出入度为0的节点
		int cnt = 0;
		while (!zeroDegreeQ.empty())
		{
			int v = zeroDegreeQ.front();
			zeroDegreeQ.pop();
			cnt++;

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
		
		return cnt == vCnt;
	}
private:
	queue<int> zeroDegreeQ;
	unordered_map<int, int> inDegree;
	unordered_map<int, vector<int>> graph;
	int vCnt;

	//first <- second
	void initGraph(vector<pair<int,int>>& prerequisites) 
	{
		//构建邻接表的图
		for (int i = 0; i < prerequisites.size(); i++)
		{
			pair<int, int> edge = prerequisites[i];

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

	if (s.canFinish(2, prerequisites))
		cout << "Can finish\n";
	else
		cout << "Can not finish\n";


	return 0;
}