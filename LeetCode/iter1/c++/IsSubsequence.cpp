#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

bool isSubsequence(string s, string t) {
	int t_index = 0;
	for (int i = 0; i < s.size(); i++)
	{
		while (t_index < t.size())
		{
			if (s[i] == t[t_index++]) {
				if (t_index == t.size())
					return true;

				break;
			}
		}

		if (t_index >= t.size())
			return false;
	}

	return true;
}

void testPrint(string s, string t) {
	if (isSubsequence(s, t))
		cout << "Yes\n";
	else
		cout << "No\n";
	
}

int main()
{

	testPrint("abc","ahbgdc");
	testPrint("ahb","ahbgdc");
	testPrint("axc", "ahbgdc");
	return 0;
}