#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <queue>
#include <stack>

using namespace std;

class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {

		int prime[26] = { 2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101 };

		for (int i = 0; i < strs.size(); i++)
		{
			int anagramIndex = generateAnagramIndex(prime, strs[i]);

			if (index_map.find(anagramIndex) == index_map.end())
			{
				index_map[anagramIndex] = v.size();

				vector<string> tmpV;
				tmpV.push_back(strs[i]);
				v.push_back(tmpV);
			}
			else
				v[index_map[anagramIndex]].push_back(strs[i]);
		}

		return v;
	}

	void testPrint()
	{
		for (auto tmpV : v)
		{
			for (auto s : tmpV)
				cout << s << " ";

			cout << endl;
		}
	}

private:
	vector<vector<string>> v;

	unordered_map<int, int> index_map;

	int generateAnagramIndex(int anagramIndex[], string s)
	{
		int sum = 1;

		for (char ch : s)
			sum *= anagramIndex[ch - 'a'];

		return sum;
	}

	bool isInMap(string s, vector<int> alphabat)
	{
		for (char ch : s)
			alphabat[ch - 'a']--;

		for (int i = 0; i < alphabat.size(); i++)
		{
			if (alphabat[i] != 0)
				return false;
		}

		return true;
	}
};

int main(void)
{
	Solution s;

	vector<string> v;
	v.push_back("eat");
	v.push_back("tea");
	v.push_back("tan");
	v.push_back("ate");
	v.push_back("nat");
	v.push_back("bat");

	s.groupAnagrams(v);
	s.testPrint();

	return 0;
}