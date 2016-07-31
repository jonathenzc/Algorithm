#include <iostream>
#include <string>
#include <vector>

using namespace std;

string longestCommonPrefix(vector<string>& strs) 
{
	if (strs.size() == 0)
		return "";
	else if (strs.size() == 1)
		return strs[0];
	else
	{
		bool isFound = false;
		int index = 0;
		string commonPrefix = "";
		while (!isFound && index < strs[0].size())
		{
			char target = strs[0][index];
			for (int i = 1; i < strs.size(); i++)
			{
				if (index < strs[i].size())
				{
					if (target != strs[i][index])
					{
						isFound = true;
						break;
					}

					if (i == strs.size() - 1)
						commonPrefix += target;
				}
				else
				{
					isFound = true;
					break;
				}
			}

			index++;
		}

		return commonPrefix;
	}
}

int main()
{
	vector<string> v;
	v.push_back("abcdefg");
	v.push_back("abc");
	v.push_back("abcd");
	v.push_back("abcde");

	cout << longestCommonPrefix(v);

	return 0;
}