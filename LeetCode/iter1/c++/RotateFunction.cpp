#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <sstream>
#include <unordered_map>

using namespace std;

//方法1： O(N^2)
//int F(vector<int> A, int pos) {
//	int sum = 0, size = A.size();
//
//	for (int i = 1; i < pos; i++)
//		sum += i*(A[size - pos + i]);
//
//	for (int i = 0; i < size - pos; i++)
//		sum += (i + pos)*(A[i]);
//
//	return sum;
//}
//
//int maxRotateFunction(vector<int>& A) {
//	if (A.size() == 0)
//		return 0;
//
//	int maxF = INT_MIN;
//
//	for (int i = 0; i < A.size(); i++)
//		maxF = max(maxF, F(A, i));
//
//	return maxF;
//}

//方法2： O(N)
int maxRotateFunction(vector<int>& A) {
	if (A.size() == 0)
		return 0;

	int sum = 0;
	int noweightSum = 0;

	for (int i = 0; i < A.size(); i++) {
		sum += i*A[i];
		noweightSum += A[i];
	}

	//nextSum = preSum + noweightSum - size*A[size-i]
	int maxSum = sum, size = A.size();
	for (int i = 1; i < size; i++) {
		sum = sum + noweightSum - size*A[size - i];

		maxSum = max(maxSum,sum);
	}
	
	return maxSum;
}

int main()
{
	vector<int> v;
	v.push_back(4);
	v.push_back(3);
	v.push_back(2);
	v.push_back(6);

	cout<< maxRotateFunction(v) <<endl;

	return 0;
}