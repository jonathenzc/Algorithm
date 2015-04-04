#include <iostream>

using namespace std;

const int VertexSize = 6;//�ڵ����
const int k = 3;//����k����
const int AWAY = 9999;

int main()
{
	//���ڽӾ��󴢴�ͼ
	int **adjancyMatrix = new int*[VertexSize];
	for (int i = 0; i < VertexSize; i++)
		adjancyMatrix[i] = new int[VertexSize];

	//����ͼ
	for (int i = 0; i < VertexSize; i++)
	{
		for (int j = 0; j < VertexSize; j++)
		{
			if (i == j)
				adjancyMatrix[i][j] = 0;
			else
				adjancyMatrix[i][j] = AWAY;
		}
	}

	adjancyMatrix[0][1] = 1;//edge 1
	adjancyMatrix[1][0] = 1;//edge 1
	adjancyMatrix[1][2] = 2;//edge 2
	adjancyMatrix[2][1] = 2;//edge 2
	adjancyMatrix[2][5] = 4;//edge 3
	adjancyMatrix[5][2] = 4;//edge 3
	adjancyMatrix[0][3] = 2;//edge 4
	adjancyMatrix[3][0] = 2;//edge 4
	adjancyMatrix[4][0] = 5;//edge 5
	adjancyMatrix[0][4] = 5;//edge 5
	adjancyMatrix[1][4] = 5;//edge 6
	adjancyMatrix[4][1] = 5;//edge 6
	adjancyMatrix[3][4] = 3;//edge 7
	adjancyMatrix[4][3] = 3;//edge 7
	adjancyMatrix[2][4] = 1;//edge 8
	adjancyMatrix[4][2] = 1;//edge 8
	adjancyMatrix[4][5] = 1;//edge 9
	adjancyMatrix[5][4] = 1;//edge 9

	//distance[i][j]��ʾ��Դ��0���ڵ�j����i���ߵ����·��
	int **distance = new int*[k+1];
	for (int i = 0; i <= k; i++)
		distance[i] = new int[VertexSize];

	////��i=1ʱ
	//for (int j = 0; j < VertexSize; j++)
	//	distance[1][j] = adjancyMatrix[0][j];

	//��i=0ʱ
	distance[0][0] = 0;
	for (int j = 1; j < VertexSize; j++)
		distance[0][j] = AWAY;

	for (int i = 1; i <= k; i++)
	{
		for (int j = 0; j < VertexSize; j++)
		{
			int min = AWAY;
			for (int vertex = 0; vertex < VertexSize; vertex++)
			{
				if (vertex != j && adjancyMatrix[vertex][j] != AWAY)
				{
					if (distance[i - 1][vertex] + adjancyMatrix[vertex][j] < min)
						min = distance[i - 1][vertex] + adjancyMatrix[vertex][j];
				}
			}
			distance[i][j] = min;
		}
	}

	
	//���distance
	for (int i = 0; i <= k; i++)
	{
		for (int j = 0; j < VertexSize; j++)
			cout << distance[i][j] << " ";
		cout << endl;
	}

	return 0;
}