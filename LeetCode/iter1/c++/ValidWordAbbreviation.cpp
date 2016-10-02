#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <sstream>
#include <queue>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int str2int(string s)
{
	stringstream ss;
	ss << s;
	int num;
	ss >> num;

	return num;
}

bool validWordAbbreviation(string word, string abbr) {
	int word_index = 0;
	int abbr_index = 0;

	bool ret = true;

	string numStr = "";

	while (abbr_index < abbr.size())
	{
		if (abbr[abbr_index] >= '0' && abbr[abbr_index] <= '9')
			numStr += abbr[abbr_index++];
		else
		{
			//检查numStr和合法性
			if (numStr.size() > 1 && numStr[0] == '0')
			{
				ret = false;
				break;
			}

			int step = 0;
			if (numStr.size() != 0) {
				step = str2int(numStr);
				if (step == 0)
				{
					ret = false;
					break;
				}
			}
			
			word_index += step;

			if (word[word_index] == abbr[abbr_index])
			{
				word_index++;
				abbr_index++;
			}
			else
			{
				ret = false;
				break;
			}

			numStr = "";
		}
	}

	if (numStr.size() > 1 && numStr[0] == '0')
		return false;

	int step = 0;
	if (numStr.size() != 0)
		step = str2int(numStr);

	if (word_index +step > word.size() || word_index +step < word.size())
		ret = false;

	return ret;
}

void testPrint(string word, string abbr)
{
	if (validWordAbbreviation(word, abbr))
		cout << "Yes\n";
	else
		cout << "No\n";
}

int main()
{
	testPrint("internationalization","i12iz4n"); //yes
	testPrint("apple", "a2e"); //no
	testPrint("a", "2"); //no
	testPrint("a", "1"); //yes
	testPrint("a", "0"); //no 
	testPrint("apple", "appl1"); //yes
	testPrint("apple", "appl2"); //no
	testPrint("apple", "appl0"); //no
	testPrint("apple", "appl01"); //no
	testPrint("a", "01"); //no
	testPrint("a", "02"); //no
	testPrint("word", "w0ord"); //no

	return 0;

}