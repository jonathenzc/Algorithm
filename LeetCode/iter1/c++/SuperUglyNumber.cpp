#include <iostream>
#include <vector>

using namespace std;

int min(int *uglyNumLst, vector<int> &pointerV, vector<int> primes)
{
	vector<int> tmpV;

	//求出集合中的最小值
	int min = INT_MAX;
	int minIndex = -1;//之后需要对公因数进1

	//得到结果集合扩大因数倍的集合
	for (int i = 0; i < pointerV.size(); i++)
	{
		int tmp = primes[i] * uglyNumLst[pointerV[i]];
		tmpV.push_back(tmp);

		if (min > tmp)
		{
			min = tmp;
			minIndex = i;
		}
	}

	pointerV[minIndex]++;

	//找出公因数并加指针进位
	for (int i = 0; i < pointerV.size(); i++)
	{
		if (i != minIndex)
		{
			if (min == tmpV[i])
				pointerV[i]++;
		}
	}
	
	return min;
}

int nthSuperUglyNumber(int n, vector<int>& primes) {
	int *result = new int[n];
	result[0] = 1;
	vector<int> pointerV; //primes个链表的初始指针
	for (int i = 0; i < primes.size(); i++)
		pointerV.push_back(0);

	for(int i=1;i<n;i++)
		result[i] = min(result, pointerV, primes);

	return result[n-1];
}

void printTest(vector<int> v)
{
	for (int i = 1; i <= 25; i++)
		cout << nthSuperUglyNumber(i, v) << " ";
}

int main()
{
	vector<int> primes;
	primes.push_back(2);
	primes.push_back(7);
	primes.push_back(13);
	primes.push_back(19);

	printTest(primes);

	return 0;
}
