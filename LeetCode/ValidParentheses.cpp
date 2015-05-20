#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool isValid(string s) 
{
	stack<char> st;

	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '(' || s[i] == '[' || s[i] == '{')
			st.push(s[i]);
		else if (s[i] == ')' || s[i] == ']' || s[i] == '}')
		{
			if (st.empty())
				return false;
			else
			{ 
				char bracket = st.top();
				st.pop();

				if (!(bracket == '(' && s[i] == ')' || bracket == '[' && s[i] == ']' || bracket == '{' && s[i] == '}'))
					return false;
			}
		}
	}

	if (!st.empty())
		return false;
	else
		return true;
}

int main()
{
	if (isValid("([)]"))
		cout << "Yes";
	else
		cout << "No";

	return 0;
}