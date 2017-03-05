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
	bool isAnagram(string s, string t) {
		if (s.size() != t.size())
			return false;

		vector<int> alphabat(26,0);

		for (char ch : s)
			alphabat[ch - 'a']++;

		bool ret = true;
		for (char ch : t)
		{
			if(alphabat[ch-'a']==0)
			{
				ret = false;
				break;
			}

			alphabat[ch - 'a']--;
		}

		return ret;
	}
};

void testPrint(string s, string t)
{
	Solution solution;
	if (solution.isAnagram(s, t))
		cout << s << " " << t << " is anagram\n";
	else
		cout << s << " " << t << " is not anagram\n";
}

int main(void)
{

	testPrint("rat","car");
	testPrint("anagram","nagaram");


	return 0;
}