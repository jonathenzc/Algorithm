#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <sstream>

using namespace std;

int binarySearch(vector<int> v, int target)
{
	int start = 0, end = v.size();
	int mid;
	bool isFound = false;

	while (start < end)
	{
		mid = (start+end) / 2;
		if (v[mid] == target)
		{
			isFound = true;
			break;
		}
		else if (v[mid] < target) 
		{
			start = mid+1;
		}
		else if (v[mid] > target)
		{
			end = mid;
		}
	}

	if (isFound)
		return mid;
	else
		return -1 - start;
}

int main()
{
	int target = 3, N = 5;
	cin >> target;
	cin >> N;

	vector<int> num(N,0);
	for (int i = 0; i < N; i++)
		cin >> num[i];

	cout << binarySearch(num,target)<<endl;

	//num[0] = 0;
	//num[1] = 1;
	//num[2] = 3;
	//num[3] = 5;
	//num[4] = 6;


	//cout << binarySearch(num,0)<<endl;
	//cout << binarySearch(num, 1) << endl;
	//cout << binarySearch(num, 3) << endl;
	//cout << binarySearch(num, 5) << endl;
	//cout << binarySearch(num, 6) << endl;

	//cout << binarySearch(num, -1) << endl;
	//cout << binarySearch(num, 2) << endl;
	//cout << binarySearch(num, 4) << endl;
	//cout << binarySearch(num, 7) << endl;
	//cout << binarySearch(num, 8) << endl;
	return 0;
}