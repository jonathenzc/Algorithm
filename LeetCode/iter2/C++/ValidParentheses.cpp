#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <queue>

using namespace std;

class Solution {
public:
	bool isValid(string s) {
		if (s.size() == 0)
			return true;

		vector<char> st;
		st.push_back(s[0]);

		for (int i = 1; i < s.size(); i++)
		{
			if (s[i] == '(' || s[i] == '[' || s[i] == '{') //left bracket
				st.push_back(s[i]);
			else
			{
				if (st.empty())
					return false;

				char topEle = st.back();
				st.pop_back();

				if (!((s[i] == ')' && topEle == '(') || (s[i] == ']' && topEle == '[') || (s[i] == '}' && topEle == '{')))
					return false;
			}
		}

		if (!st.empty())
			return false;

		return true;
	}
};

void testPrint(string s)
{
	Solution solution;
	if (solution.isValid(s))
		cout << "Yes\n";
	else
		cout << "No\n";
}

int main(void)
{
	testPrint("(())");
	testPrint("(())][");

	return 0;
}