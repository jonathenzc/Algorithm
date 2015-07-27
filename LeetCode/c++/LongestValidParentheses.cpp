#include <iostream>
#include <string>
#include <stack>

using namespace std;

int max(int a, int b)
{
	if (a > b)
		return a;
	else
		return b;
}

int longestValidParentheses(string s) 
{
	if (s.size() == 0)
		return 0;

	int maxLength = 0;
	stack<int> positionStack;//记录字符串中左括号的位置
	positionStack.push(-1);

	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == ')')
		{
			if (positionStack.size()>1)
			{
				positionStack.pop();//先将与)对应的(弹栈

				int lastPos = positionStack.top();//获取匹配开始的(下标,如果没有开始的位置,那么将以-1来计算

				int currentLength = i - lastPos;

				maxLength = max(maxLength, currentLength);
			}
			else
			{
				positionStack.pop();
				positionStack.push(i);
			}
		}
		else
			positionStack.push(i);
	}

	return maxLength;
}


int main()
{
	cout << longestValidParentheses("((())") << endl
		<< longestValidParentheses("((()))") << endl
		<< longestValidParentheses("())") << endl
		<< longestValidParentheses("(()()(") << endl
		<< longestValidParentheses("((())((()())((") << endl;

	cout<< longestValidParentheses("((())((()())))") << endl;
	cout << longestValidParentheses(")()())(()()(()))(") << endl;

	return 0;
}