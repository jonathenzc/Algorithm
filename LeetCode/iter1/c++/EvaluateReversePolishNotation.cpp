#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int str2int(string s)
{
	stringstream ss;
	ss << s;
	int ret;
	ss >> ret;

	return ret;
}


int evalRPN(vector<string>& tokens) {
	vector<int> v;

	for (int i = 0; i < tokens.size(); i++)
	{
		if (tokens[i].size() == 1 && (tokens[i][0] == '+' || tokens[i][0] == '-' || tokens[i][0] == '*' || tokens[i][0] == '/'))
		{
			int operNum2 = v.back();
			v.pop_back();

			int operNum1 = v.back();
			v.pop_back();

			if (tokens[i][0] == '+')
				v.push_back(operNum1 + operNum2);
			else if (tokens[i][0] == '-')
				v.push_back(operNum1 - operNum2);
			else if (tokens[i][0] == '*')
				v.push_back(operNum1 * operNum2);
			else if (tokens[i][0] == '/')
				v.push_back(operNum1 / operNum2);
		}
		else
			v.push_back(str2int(tokens[i]));
	}

	return v.back();
}

int main()
{
	vector<string> v1;
	v1.push_back("2");
	v1.push_back("1");
	v1.push_back("+");
	v1.push_back("3");
	v1.push_back("*");

	cout << evalRPN(v1)<<endl; //9


	vector<string> v2;
	v2.push_back("4");
	v2.push_back("13");
	v2.push_back("5");
	v2.push_back("/");
	v2.push_back("+");

	cout << evalRPN(v2) << endl; //6

	vector<string> v3;
	v3.push_back("3");
	v3.push_back("-4");
	v3.push_back("+");


	cout << evalRPN(v3) << endl; //-1
	return 0;
}