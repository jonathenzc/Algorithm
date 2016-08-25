#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>

using namespace std;

int main()
{
	int M;
	double rate[7] = {0.03, 0.1, 0.2, 0.25, 0.3, 0.35, 0.45};
	int bound[7] = { 0, 1500, 4500, 9000, 35000, 55000, 80000};
	double tax[7] = { 0 };
	for (int i = 1; i < 7; i++)
		tax[i] = tax[i-1]+(bound[i]-bound[i-1])*rate[i-1];

	while (cin >> M)
	{
		int salary = 3500;

		int i = 6;
		while (i >= 0 && tax[i] > M)
			i--;

		salary += (M - tax[i]) / rate[i] + bound[i];

		cout << salary << endl;
	}

	return 0;
}