#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <sstream>

using namespace std;

void dfs(vector<vector<int>> distance, vector<bool> isVisited, int source,int nodeCnt, int cur, int &sum, int N)
{
	if (nodeCnt == N)
		sum = min(sum,cur);
	else
	{
		for (int i = 0; i < N; i++)
		{
			if (!isVisited[i])
			{
				isVisited[i] = true;
				dfs(distance,isVisited,i,nodeCnt+1,cur+distance[source][i],sum,N);
				isVisited[i] = false;
			}
		}
	}
}


int main()
{
	int num;
	cin >> num;

	vector<vector<int>> distance(num,vector<int>(num,0));

	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < num; j++)
		{
			cin >> distance[i][j];
		}
	}


	//vector<vector<int>> v;
	//vector<int> v1;
	//v1.push_back(0);
	//v1.push_back(1);
	//v1.push_back(2);
	//v1.push_back(3);

	//vector<int> v2;
	//v2.push_back(1);
	//v2.push_back(0);
	//v2.push_back(4);
	//v2.push_back(5);


	//vector<int> v3;
	//v3.push_back(2);
	//v3.push_back(4);
	//v3.push_back(0);
	//v3.push_back(2);

	//vector<int> v4;
	//v4.push_back(3);
	//v4.push_back(5);
	//v4.push_back(2);
	//v4.push_back(0);

	//v.push_back(v1);
	//v.push_back(v2);
	//v.push_back(v3);
	//v.push_back(v4);

	vector<bool>isVisited(num,false);
	int sum = INT_MAX;

	for (int i = 0; i < num; i++) {
	
		isVisited[i] = true;
		dfs(distance, isVisited, i, 1, 0, sum, num);
		isVisited[i] = false;
	
	}

	cout << sum << endl;

	return 0;
}