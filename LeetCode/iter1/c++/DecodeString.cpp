#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <sstream>
#include <unordered_map>

using namespace std;

string decodeString(string s) {
	vector<string> strV;
	vector<int> numV;

	string ret = "";
	string localStr = "";
	string numStr = "";

	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '[') {
			strV.push_back("[");

			int num;
			stringstream ss;
			ss << numStr;
			ss >> num;

			numV.push_back(num);

			numStr = "";
			localStr = "";
		}
		else if (s[i] == ']')
		{
			int cnt = numV.back();
			numV.pop_back();

			string oldStr = "";
			while (!strV.empty() && strV.back()[0] != '[') {
				oldStr = strV.back() + oldStr;
				strV.pop_back();
			}

			if (!strV.empty() && strV.back()[0] == '[')
				strV.pop_back();


			string tmpS = "";
			for (int i = 0; i < cnt; i++)
				tmpS += (oldStr+localStr);

			strV.push_back(tmpS);

			numStr = "";
			localStr = "";
		}
		else if(s[i] >= '0' && s[i] <= '9')
		{
			numStr += s[i];

			if (localStr.size() != 0) {
				strV.push_back(localStr);
				localStr = "";
			}
		}
		else
		{
			localStr += s[i];
		}
	}

	for (auto tmpS : strV)
		ret += tmpS;

	ret += localStr;

	return ret;
}

int main()
{
	cout << decodeString("3[a]2[bc]") << endl; //"aaabcbc"
	cout << decodeString("3[a2[c]]") << endl; // "accaccacc"
	cout << decodeString("3[2[c]bd]") << endl; //"ccbdccbdccbd"
	cout << decodeString("2[abc]3[cd]ef") << endl; //"abcabccdcdcdef"
	cout << decodeString("3[aa2[c]bd]") << endl; //"aaccbdaaccbdaaccbd"
	return 0;
}