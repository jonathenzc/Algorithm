#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <sstream>

using namespace std;

int str2int(string s)
{
	stringstream ss;
	ss << s;
	int result;
	ss >> result;

	return result;
}

vector<string> getReversedPoland(string s)
{
	vector<string> reverseV;
	stack<char> st;
	string num = "";

	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
			num += s[i];
		else
		{
			if(num.size() != 0)
			{
				reverseV.push_back(num);
				num = "";
			}

			if (s[i] == '(')
				st.push('(');
			else if (s[i] == '+' || s[i] == '-')
			{
				if (st.empty())
					st.push(s[i]);
				else
				{
					char ch;
					while (!st.empty())
					{
						ch = st.top();

						if (ch == '+')
							reverseV.push_back("+");
						else if (ch == '-')
							reverseV.push_back("-");
						else if (ch == '(')
						{
							break;
						}

						st.pop();
					}

					st.push(s[i]);
				}
			}
			else if (s[i] == ')') 
			{
				char ch;
				while (!st.empty())
				{
					ch = st.top();

					if (ch == '+')
						reverseV.push_back("+");
					else if (ch == '-')
						reverseV.push_back("-");
					else if (ch == '(')
					{
						st.pop();
						break;
					}

					st.pop();
				}
			}
		}

		if(i == s.size()-1 && num.size() != 0)
		{
			reverseV.push_back(num);

			char ch;
			while (!st.empty())
			{
				ch = st.top();

				if (ch == '+')
					reverseV.push_back("+");
				else if (ch == '-')
					reverseV.push_back("-");
				else if (ch == '(')
				{
					st.pop();
					break;
				}

				st.pop();
			}
		}
	}

	//将栈中剩余的符号输出到字符串中
	char ch;
	while (!st.empty())
	{
		ch = st.top();

		if (ch == '+')
			reverseV.push_back("+");
		else if (ch == '-')
			reverseV.push_back("-");
		else if (ch == '(')
		{
			st.pop();
			break;
		}

		st.pop();
	}

	return reverseV;
}

int calculate(string s) {
	//先获取逆波兰表达式
	vector<string> reversedPolandStr = getReversedPoland(s);

	//计算逆波兰表达式
	stack<int> st;

	for (int i = 0; i < reversedPolandStr.size(); i++)
	{
		string tmp = reversedPolandStr[i];

		if (tmp[0] == '+' || tmp[0] == '-') //符号
		{
			//获取左右操作数
			int right = st.top();
			st.pop();
			int left = st.top();
			st.pop();

			//根据当前符号位计算结果
			int sum;
			if (tmp[0] == '+')
				sum = left + right;
			else if (tmp[0] == '-')
				sum = left - right;

			//将计算结果压入栈中
			st.push(sum);
		}
		else
		{
			int tmpInt = str2int(tmp);
			st.push(tmpInt);
		}
	}

	int result = 0;
	if (!st.empty())
		result = st.top();

	return result;
}

//测试逆波兰表达式
void printV(string s)
{
	vector<string> v = getReversedPoland(s);

	for (int i = 0; i < v.size(); i++)
		cout << v[i] << " ";

	cout << endl;
}

int main()
{
	cout<<calculate("10")<<endl;
	cout<<calculate("(10)") << endl;
	cout<<calculate("(10+23)") << endl;
	cout<<calculate("(10-2)") << endl;
	cout<<calculate("(10-23)") << endl;
	cout<<calculate("(12-20+21)") << endl;
	cout<<calculate("(10-23)+(1-2-3)") << endl;
	cout<<calculate("(12-20+21)-(1+2-(13+41-31))") << endl;
	cout << calculate("1 + 1") << endl;
	cout << calculate(" 2-1 + 2 ") << endl;
	cout << calculate("(1+(4+5+2)-3)+(6+8)") << endl;


	return 0;
}
