#include <iostream>

using namespace std;

int numTrees(int n) 
{
	//trees[i] 表示i个节点可以构成的树的个数
	//那么trees[i]的个数可以认为左右子树个数的乘积，
	//比如有5个节点的时候，左右子树可能出现的情况有(0,4)+(1,3)+(2,2)+(3,1)+(4,0)
	int *trees = new int[n+1];
	trees[0] = 1;//空子树算1
	trees[1] = 1;
	trees[2] = 2;

	for (int i = 3; i <= n; i++)
	{
		trees[i] = 0;
		for (int j = 0; j < i; j++)
			trees[i] += trees[j]*trees[i-j-1];
	}

	return trees[n];
}

int main()
{
	cout << numTrees(4) << endl;
	cout<<numTrees(5);

	return 0;
}