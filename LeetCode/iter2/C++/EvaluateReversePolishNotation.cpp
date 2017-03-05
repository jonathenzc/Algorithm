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
	int evalRPN(vector<string>& tokens) {
		int symbol = -1;

		for (auto str : tokens)
		{
			if (str[0] >= '0' && str[0] <= '9' || ((str[0] == '-' || str[0] == '+') && str.size()>1))
			{
				int num = str2int(str);
				numV.push_back(num);
			}
			else
			{
				int oper2 = numV.back();
				numV.pop_back();

				int oper1 = numV.back();
				numV.pop_back();

				int result;
				if (str[0] == '+')
					result = oper1 + oper2;
				else if (str[0] == '-')
					result = oper1 - oper2;
				else if (str[0] == '*')
					result = oper1 * oper2;
				else if (str[0] == '/')
					result = oper1 / oper2;

				numV.push_back(result);
			}
		}
		
		int evalResult = numV.back();
		numV.pop_back();

		return evalResult;
	}
private:
	vector<int> numV;

	int str2int(string str)
	{
		stringstream ss;
		ss << str;
		int num;
		ss >> num;

		return num;
	}
};

int main(void)
{
	Solution s;

	vector<string> v;
	v.push_back("2");
	v.push_back("1");
	v.push_back("+");
	v.push_back("3");
	v.push_back("*");

	vector<string> v1;
	v1.push_back("4");
	v1.push_back("13");
	v1.push_back("5");
	v1.push_back("/");
	v1.push_back("+");


	vector<string> v2;
	v2.push_back("3");
	v2.push_back("-4");
	v2.push_back("+");

	cout << s.evalRPN(v)  <<endl;
	cout << s.evalRPN(v1) << endl;
	cout << s.evalRPN(v2) << endl;

	return 0;
}