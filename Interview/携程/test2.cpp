#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <sstream>

using namespace std;

int str2int(string s)
{
	stringstream ss;
	ss << s;
	int num;
	ss >> num;

	return num;
}

vector<int> getInputNumV(string s)
{
	vector<int> v;

	int startIndex = 0, nextIndex = 0;

	while (nextIndex < s.size())
	{
		if (s[nextIndex] == ',')
		{
			string numStr = s.substr(startIndex,nextIndex-startIndex);
			int num = str2int(numStr);
			v.push_back(num);

			startIndex = nextIndex + 1;
		}

		nextIndex++;
	}

	string numStr = s.substr(startIndex, nextIndex - startIndex);
	int num = str2int(numStr);
	v.push_back(num);

	return v;
}

int main()
{
	string s;
	cin >> s;

	vector<int> stock = getInputNumV(s);

	int globalMin = 0;
	int preIndex = 0; 

	for (int i = 1; i < stock.size(); i++)
	{
		if (stock[i] < stock[preIndex])
			preIndex = i;

		globalMin = max(globalMin,stock[i]-stock[preIndex]);
	}

	cout << globalMin << endl;

	return 0;
}