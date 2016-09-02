#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;



int main()
{
	int N, E;
	cin >> N >> E;
	//N = 5;
	vector<vector<int>> distance(N,vector<int>(N, 1000000));

	int cnt = 0;
	while (cnt < E)
	{
		int v1, v2, value;	
		cin >> v1 >> v2 >> value;

		distance[v1 - 1][v2 - 1] = min(distance[v1-1][v2-1],value);
		distance[v2 - 1][v1 - 1] = min(distance[v2 - 1][v1 - 1],value);

		cnt++;
	}

	for (int i = 0; i < N; i++)
		distance[i][i] = 0;

	//distance[0][1] = 967;
	//distance[1][2] = 900;
	//distance[2][3] = 771;
	//distance[3][4] = 196;

	////distance[1][3] = 788;
	//distance[2][0] = 637;
	////distance[0][3] = 883;
	//distance[1][3] = 82;

	//distance[4][1] = 647;
	//distance[0][3] = 198;
	////distance[1][3] = 181;
	////distance[4][1] = 665;

	//distance[0][0] = 0;
	//distance[1][1] = 0;
	//distance[2][2] = 0;
	//distance[3][3] = 0;
	//distance[4][4] = 0;

	//floyd-warshall算法
	for (int middle = 0; middle < N; middle++)
	{
		for (int start =0; start < N; start++)
		{
			for (int end = 0; end < N; end++)
			{
				distance[start][end] = min(distance[start][end],distance[start][middle] + distance[middle][end]);
			}
		}
	}

	for (auto v1: distance)
	{
		for (auto num : v1)
			cout << num << " ";

		cout << endl;
	}

	return 0;
}