#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <sstream>
#include <iomanip>

using namespace std;

vector<string> retV;

int main()
{
	int testGroup;
	cin >> testGroup;

	int *fibo = new int[95];
	fibo[0] = 1;
	fibo[1] = 1;
	fibo[2] = 2;
	for (int i = 3; i < 95; i++)
		fibo[i] = fibo[i - 1] + fibo[i - 2];

	double *num = new double[95];
	num[0] = 1;
	num[1] = 2;
	num[2] = 3.5;
	for (int i = 3; i < 95; i++)
		num[i] = num[i-1]+fibo[i+1]/(double)fibo[i];

	int cnt = 0;
	while (cnt < testGroup)
	{
		int n;
		cin >> n;

		cout << setiosflags(ios::fixed) << setprecision(4)<<num[n]<<endl;
		cnt++;
	}

	return 0;
}