#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <sstream>
#include <iomanip>
#include <queue>
#include <utility>

using namespace std;

string getColumnStr(vector<string>& words, int index)
{
	string s = "";

	for (int i = 0; i < words.size(); i++)
	{
		if(index < words[i].size())
			s += words[i][index];
	}

	return s;
}

bool validWordSquare(vector<string>& words) {

	bool ret = true;

	int kth = 0;

	for (int i = 0; i < words.size(); i++)
	{
		string rowStr = words[i];
		string columnStr = getColumnStr(words,i);

		if (rowStr != columnStr)
		{
			ret = false;
			break;
		}
	}

	return ret;
}

int main()
{
	vector<string> v;
	string s1 = "ball";
	string s2 = "bnrt";
	string s3 = "crm";
	string s4 = "dt";

	v.push_back(s1);
	v.push_back(s2);
	v.push_back(s3);
	v.push_back(s4);

	if (validWordSquare(v))
		cout << "Yes\n";
	else
		cout << "No\n";

	return 0;
}