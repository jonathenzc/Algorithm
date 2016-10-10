#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <queue>

using namespace std;

int main(void)
{
	int N;
	cin >> N;
	vector<int> v(N,0);
	for (int i = 0; i < N; i++)
		cin >> v[i];

	//vector<int> v;
	//v.push_back(1);
	//v.push_back(1);
	//v.push_back(2);
	//v.push_back(3);
	//v.push_back(4);
	//v.push_back(4);
	//v.push_back(5);

	int preLen = -1;
	while (v.size() > 1 && preLen != v.size())
	{
		preLen = v.size();
		vector<int> tmpV;
		int i = 0;
		while(i<v.size()-1)
		{
			int sum = v[i] + v[i+1];
			if ((sum & 1) == 0) //even
			{
				tmpV.push_back(v[i]);
				if (i == v.size() - 2)
					tmpV.push_back(v[i+1]);

				i++;
			}
			else //delete this pair
			{
				i += 2;
				if (i == v.size() - 1)
					tmpV.push_back(v[i]);
			}
		}

		v = tmpV;
	}

	cout << v.size() << endl;


	return 0;
}