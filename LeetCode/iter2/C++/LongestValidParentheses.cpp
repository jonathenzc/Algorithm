#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

int longestValidParentheses(string s) {
	if (s.size() <= 1)
		return 0;

	vector<int> indexStack;
	indexStack.push_back(-1); //记录一开始第一个字符的位置

	int maxLength = 0;
	int curLen = 0;

	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == ')')
		{
			indexStack.pop_back();
			if (indexStack.size() == 0)
				indexStack.push_back(i);
			else {
				curLen = i - indexStack.back();
				maxLength = max(maxLength,curLen);
			}
		}
		else  //(
			indexStack.push_back(i);
	}

	return maxLength;
}

int main()
{
	cout << longestValidParentheses(")()())") << endl;
	cout << longestValidParentheses("(()") << endl;
	cout << longestValidParentheses("()())()()()") << endl;
	cout << longestValidParentheses("()())()(())") << endl;
	cout << longestValidParentheses("()(()") << endl;
	

	return 0;
}