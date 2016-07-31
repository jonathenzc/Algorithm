#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

bool isValid(string s)
{
	stack<char> st;
	bool result = true;

	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '(')
			st.push(s[i]);
		else
		{
			if (st.empty())
			{
				result = false;
				break;
			}
			else
				st.pop();
		}
	}

	return result;
}

void parenthesisHelper(string s,vector<string> &v,int leftCnt,int rightCnt,int n)
{
	if (leftCnt >= rightCnt)
	{
		if (leftCnt == n && rightCnt == n)
		{
			//不判断也可以
			// if (isValid(s))
			// {
				v.push_back(s);
			// }
		}
		else
		{
			if (leftCnt < n)
			{
				//先加'('
				string leftS = s + "(";
				parenthesisHelper(leftS, v, leftCnt + 1, rightCnt, n);
			}
			
			if (rightCnt < n)
			{
				//再加')'
				string rightS = s + ")";
				parenthesisHelper(rightS, v, leftCnt, rightCnt + 1, n);
			}
		}
	}
}

vector<string> generateParenthesis(int n) {
	vector<string> v;

	if (n > 0)
	{
		int leftCnt = 1, rightCnt = 0;
		string s = "(";

		parenthesisHelper(s,v,leftCnt,rightCnt,n);
	}

	return v; 
}

int main()
{
	vector<string> v = generateParenthesis(3);

	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << endl;
	}

	return 0;
}
