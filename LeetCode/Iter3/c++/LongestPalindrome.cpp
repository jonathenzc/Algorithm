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
	int longestPalindrome(string s) {
		vector<int> letterMap(65,0);

		for (char c : s)
			letterMap[c-'A']++;

		int sum = 0;
		bool oddIsFound = false;
		for (int i = 0; i < 65; i++)
		{
			if (letterMap[i] & 1 == 1)
			{
				oddIsFound = true;
				sum += letterMap[i] - 1;
			}
			else
				sum += letterMap[i];
		}

		if (oddIsFound)
			sum++;

		return sum;
	}
};

void testPrint(vector<int> v)
{
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << " ";
}

int main(void)
{
	Solution s;

	cout << s.longestPalindrome("aaabbbbcccccd")<<endl;
	cout << s.longestPalindrome("aaaabbbbccccccdd") << endl;

	return 0;
}