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

		//取出
	}
private:
	queue<int> zeroDegreeQ;
	unordered_map<int, int> inDegree;
	unordered_map<int, vector<int>> graph;

	void initGraph(vector<pair<int,int>>& prerequisites) 
	{
		//构建邻接表的图
		for (int i = 0; i < prerequisites.size(); i++)
		{
			pair<int, int> edge = prerequisites[i];
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

		//寻找入度为0的节点
		unordered_map<int, int>::iterator inDegreeIter;
		for (; inDegreeIter != inDegree.end(); inDegreeIter++)
		{
			if (inDegreeIter->second == 0)
				zeroDegreeQ.push(inDegreeIter->first);
		}
	}
};

int main(void)
{
	Solution s;

	//vector<int> numbers;
	//numbers.push_back(2);
	//numbers.push_back(7);
	//numbers.push_back(11);
	//numbers.push_back(15);

	//vector<int> ret = s.twoSum(numbers, 17);
	//for (int index : ret)
	//{
	//	cout << index << " ";
	//}
	//cout << endl;

	vector<int> numbers2;
	numbers2.push_back(3);
	numbers2.push_back(24);
	numbers2.push_back(50);
	numbers2.push_back(79);
	numbers2.push_back(88);
	numbers2.push_back(150);
	numbers2.push_back(345);

	vector<int> ret2 = s.twoSum(numbers2, 200);
	for (int index : ret2) 
	{
		cout << index << " ";
	}
	cout << endl;


	return 0;
}