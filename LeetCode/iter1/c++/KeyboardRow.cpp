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
	vector<string> findWords(vector<string>& words) {
		buildKeyboard();

		vector<string> ret;

		for (auto s : words)
		{
			bool isInOneLine = true;

			//find in which line
			int lineIndex = findInWhichLine(tolower(s[0]));
			auto targetSet = v[lineIndex];

			for (int i = 1; i < s.size(); i++)
			{
				if (targetSet.find(tolower(s[i])) == targetSet.end())
				{
					isInOneLine = false;
					break;
				}
			}

			if (isInOneLine)
				ret.push_back(s);
		}

		return ret;
	}
private:

	vector<unordered_set<char>> v;

	void buildKeyboard()
	{
		unordered_set<char> set1;
		set1.insert('`');
		set1.insert('~');
		for (int i = 0; i < 10; i++)
			set1.insert(i + '0');

		set1.insert('!');
		set1.insert('@');
		set1.insert('#');
		set1.insert('$');
		set1.insert('%');
		set1.insert('^');
		set1.insert('&');
		set1.insert('*');
		set1.insert('(');
		set1.insert(')');
		set1.insert('-');
		set1.insert('_');
		set1.insert('+');
		set1.insert('=');

		unordered_set<char> set2;
		set2.insert('q');
		set2.insert('w');
		set2.insert('e');
		set2.insert('r');
		set2.insert('t');
		set2.insert('y');
		set2.insert('u');
		set2.insert('i');
		set2.insert('o');
		set2.insert('p');
		set2.insert('[');
		set2.insert(']');
		set2.insert('{');
		set2.insert('}');
		set2.insert('\\');
		set2.insert('|');

		unordered_set<char> set3;
		set3.insert('a');
		set3.insert('s');
		set3.insert('d');
		set3.insert('f');
		set3.insert('g');
		set3.insert('h');
		set3.insert('j');
		set3.insert('k');
		set3.insert('l');
		set3.insert(';');
		set3.insert(':');
		set3.insert('\'');
		set3.insert('"');
		set3.insert('}');

		unordered_set<char> set4;
		set4.insert('z');
		set4.insert('x');
		set4.insert('c');
		set4.insert('v');
		set4.insert('b');
		set4.insert('n');
		set4.insert('m');
		set4.insert(',');
		set4.insert('<');
		set4.insert('.');
		set4.insert('>');
		set4.insert('?');
		set4.insert('/');

		v.push_back(set1);
		v.push_back(set2);
		v.push_back(set3);
		v.push_back(set4);
	}

	int findInWhichLine(char ch)
	{
		int index = 0;

		while (index < v.size())
		{
			if (v[index].find(ch) != v[index].end())
				break;
		
			index++;
		}

		return index;
	}
};

int main(void)
{
	Solution s;
	vector<string> v;
	v.push_back("Hello");
	v.push_back("Alaska");
	v.push_back("Dad");
	v.push_back("Peace");

	vector<string> ret = s.findWords(v);

	for(string str:ret)
		cout << str << endl;


	return 0;
}