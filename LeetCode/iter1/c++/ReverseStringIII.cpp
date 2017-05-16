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
	string reverseWords(string s) {
		int start = 0;

		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == ' ')
			{
				helper(s, start, i-1);
				start = i + 1;
			}
		}

		helper(s,start,s.size()-1);

		return s;
	}
private:
	void helper(string&s, int start, int end)
	{
		while (start < end)
		{
			char tmp = s[start];
			s[start] = s[end];
			s[end] = tmp;

			start++;
			end--;
		}
	}
};

int main(void)
{
	Solution s;
	cout << s.reverseWords("Let's take LeetCode contest") << endl;



	return 0;
}