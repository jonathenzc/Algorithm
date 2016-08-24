#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	string s;
	string oldS;
	string fjxmlhx = "fjxmlhx";
	string marshtomp = "marshtomp";

	while (getline(cin,s))
	{
	//s = "marshTomp is beaten by fjxmlhx! marshtomp";
	//s = "AmarshtompB";
	//s = "The Marshtomp has seen it all before.";
		//s = "MarshtompMarshtomp";
		string outputS = s;

		oldS = s;

		transform(s.begin(), s.end(), s.begin(), ::tolower);

		int start = 0;
		while (start < s.size())
		{
			int index = s.find(marshtomp,start);
			if (index != string::npos)
			{
				outputS = outputS.substr(0, index) + fjxmlhx + outputS.substr(index + 9);
				s = outputS;
				transform(s.begin(), s.end(), s.begin(), ::tolower);
				start = index+4;
			}
			else
				break;
		}

		cout << outputS << endl;
	}

	return 0;
}