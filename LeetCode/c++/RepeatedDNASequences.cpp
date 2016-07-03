#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>

using namespace std;

vector<string> findRepeatedDnaSequences(string s) {
	vector<string> v;

	if (s.size() > 10)
	{
		unordered_map<string, int> map;

		for (int i = 0; i <= s.size() - 10; i++)
		{
			string target = s.substr(i,10);
			map[target]++;
		}

		for (auto iter = map.begin(); iter != map.end(); iter++)
		{
			if (iter->second > 1)
				v.push_back(iter->first);
		}
	}

	return v;
}

void testPrint(vector<string> v)
{
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << endl;

	cout << "#############################\n";
}


int main()
{
	testPrint(findRepeatedDnaSequences("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"));
	testPrint(findRepeatedDnaSequences("AAAAACCCCCAAAAACCCCCAAAAAGGGTTT"));
	testPrint(findRepeatedDnaSequences("AAAAAAAAAAA"));

	return 0;
}