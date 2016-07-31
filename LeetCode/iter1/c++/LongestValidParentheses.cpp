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
	stack<int> positionStack;//��¼�ַ����������ŵ�λ��
	positionStack.push(-1);

	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == ')')
		{
			if (positionStack.size()>1)
			{
				positionStack.pop();//�Ƚ���)��Ӧ��(��ջ

				int lastPos = positionStack.top();//��ȡƥ�俪ʼ��(�±�,���û�п�ʼ��λ��,��ô����-1������

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