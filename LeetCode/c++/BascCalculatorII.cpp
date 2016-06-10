#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <stack>

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
			if (num.size() != 0)
			{
				reverseV.push_back(num);
				num = "";
			}

			if (s[i] == '(')
				st.push('(');
			else if (s[i] == '+' || s[i] == '-' ||
				s[i] == '*' || s[i] == '/')
			{
				if (st.empty())
					st.push(s[i]);
				else
				{
					char ch;
					while (!st.empty())
					{
						ch = st.top();

						if (ch == '+' || ch == '-')
						{
							//当前符号是乘除，优先级高,栈顶元素的优先级低就不弹栈
							if (s[i] == '*' || s[i] == '/')
							{
								break;
							}
							else//+和-
							{
								string tmpStr = "a";
								tmpStr[0] = ch;
								reverseV.push_back(tmpStr);
							}
						}
						else if (ch == '*' || ch == '/') //将栈中元素优先级高，弹栈
						{
							string tmpStr = "a";
							tmpStr[0] = ch;
							reverseV.push_back(tmpStr);
						}
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

					if (ch == '+' || ch == '-' ||
						ch == '*' || ch == '/')
					{
						string tmpStr = "a";
						tmpStr[0] = ch;
						reverseV.push_back(tmpStr);
					}
					else if (ch == '(')
					{
						st.pop();
						break;
					}

					st.pop();
				}
			}
		}

		if (i == s.size() - 1 && num.size() != 0)
		{
			reverseV.push_back(num);

			char ch;
			while (!st.empty())
			{
				ch = st.top();

				if (ch == '+' || ch == '-' ||
					ch == '*' || ch == '/')
				{
					string tmpStr = "a";
					tmpStr[0] = ch;
					reverseV.push_back(tmpStr);
				}
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

		if (ch == '+' || ch == '-' ||
			ch == '*' || ch == '/')
		{
			string tmpStr = "a";
			tmpStr[0] = ch;
			reverseV.push_back(tmpStr);
		}
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

		if (tmp[0] == '+' || tmp[0] == '-' ||
			tmp[0] == '*' || tmp[0] == '/') //符号
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
			else if (tmp[0] == '*')
				sum = left * right;
			else if (tmp[0] == '/')
				sum = left / right;

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

int main()
{
	cout << calculate("10") << endl;
	cout << calculate("(10)") << endl;
	cout << calculate("(10+23)") << endl;
	cout << calculate("(10-2)") << endl;
	cout << calculate("(10-23)") << endl;
	cout << calculate("(12-20+21)") << endl;
	cout << calculate("(10-23)+(1-2-3)") << endl;
	cout << calculate("(12-20+21)-(1+2-(13+41-31))") << endl;
	cout << calculate("1 + 1") << endl;
	cout << calculate(" 2-1 + 2 ") << endl;
	cout << calculate("(1+(4+5+2)-3)+(6+8)") << endl;
	cout << "******** multiply ******\n";
	cout << calculate(" 2-1 * 2 ") << endl;
	cout << calculate("40-12*10") << endl;
	cout << calculate(" 2-1 / 2 ") << endl;
	cout << calculate("(40-12*10)+(5*2*10)") << endl;
	return 0;
}
