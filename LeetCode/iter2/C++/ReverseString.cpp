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
	string reverseString(string s) {
		int half_Len = s.size() >> 1;
		for (int i = 0; i < half_Len; i++)
		{
			char tmp = s[i];
			s[i] = s[s.size()-i-1];
			s[s.size() - i-1] = tmp;
		}

		return s;
	}
};


int main(void)
{
	Solution s;

	cout << s.reverseString("hello") << endl;


	return 0;
}