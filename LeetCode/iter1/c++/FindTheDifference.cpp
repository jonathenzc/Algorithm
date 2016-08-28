#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>

using namespace std;

char findTheDifference(string s, string t) {
	unordered_map<char, int> map;
	for (int i = 0; i < s.size(); i++)
		map[s[i]]++;

	for (int i = 0; i < t.size(); i++)
		map[t[i]]--;

	char target;
	for (auto iter = map.begin(); iter != map.end(); iter++)
	{
		if (iter->second != 0)
			target = iter->first;
	}

	return target;
}

int lastRemaining(int n) {

}

int main()
{
	cout << findTheDifference("abcd","abcde") << endl;
}