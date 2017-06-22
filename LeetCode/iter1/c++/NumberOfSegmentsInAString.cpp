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
#include <map>

using namespace std;

class Solution {
public:
	int countSegments(string s) {
		int cnt = 0;
		if (s.size() > 0)
		{
			int start = 0, end = s.size() - 1;
			while (start < s.size() && s[start] == ' ')
				start++;

			while (end >= 0 && s[end] == ' ')
				end--;

			bool wordFound = false;

			for (int i = start; i <= end; i++) 
			{
				if (s[i] == ' ')
				{
					if (wordFound)
					{
						wordFound = false;
						cnt++;
					}
				}
				else
					wordFound = true;

				if (i == end)
					cnt++;
			}
		}

		return cnt;
	}
};

void testPrint(string s)
{
	Solution solution;
	cout << "["<< s << "] " << solution.countSegments(s) << endl;
}

int main(void)
{
	testPrint("");
	testPrint(" ");
	testPrint("   ");
	testPrint("Hello, my name is John");
	testPrint("   Hello, my name is John");
	testPrint("Hello, my name is John   ");
	testPrint("   Hello, my name is John     ");
	testPrint("Hello");
	testPrint(" Hello");
	testPrint("Hello ");
	testPrint(" Hello ");
	testPrint(", , , ,        a, eaefa");

	return 0;
} 