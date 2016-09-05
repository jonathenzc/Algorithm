#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main()
{
	int n;
	
	while (cin >> n) {
		int *height = new int[n];
		for (int i = 0; i < n; i++)
			cin >> height[i];

		int cnt = 0;
		cnt += n + (n - 3);

		for (int i = 0; i < n - 1; i++)
		{
			if (height[i] == height[i + 1])
				cnt++;
		}

		if (height[0] == height[n - 1])
			cnt++;

		cout << cnt << endl;
	}



	return 0;
}